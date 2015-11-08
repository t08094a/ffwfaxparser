#include <UnitTest++.h>
#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/date_time/posix_time/posix_time_types.hpp>
#include "../src/ParserUtility.cpp"


TEST(ReadFaxTimestampResultsInCorrectOne)
{
    std::string line = "ILS Ansbac   +49 (981) 65050-410   0(9846)979725  1/1   24.07.2015   12:38";
    boost::posix_time::ptime expected(boost::gregorian::date(2015, 7, 24), boost::posix_time::time_duration(12, 38, 0));
    boost::posix_time::ptime fallback(boost::gregorian::date(2002, 1, 10), boost::posix_time::time_duration(1, 2, 3));

    boost::posix_time::ptime result = ParserUtility::ReadFaxTimestamp(line, fallback);

    CHECK_EQUAL(expected, result);
}

/*
TEST(ReadFaxTimestampResultsInFallback)
{
    std::string line = "ILS Ansbac   +49 (981) 65050-410   0(9846)979725  1/1";
    boost::posix_time::ptime fallback(boost::gregorian::date(2002, 1, 10), boost::posix_time::time_duration(1, 2, 3));

    boost::posix_time::ptime result = ParserUtility::ReadFaxTimestamp(line, fallback);

    CHECK_EQUAL(fallback, result);
}

TEST(AppendLineToString)
{
    std::string value = "abc";
    
    ParserUtility::AppendLine(value, "def");

    std::string expected = "abc\ndef";
    CHECK_EQUAL(expected, value);
}

TEST(AppendEmptyStringShouldResultInNotModifiedString)
{
    std::string value = "abc";
    
    ParserUtility::AppendLine(value, "");

    std::string expected = "abc";
    CHECK_EQUAL(expected, value);
}

TEST(LineStartsWithKeywordResultsInTrue)
{
    std::string line = "VU 1";
    std::vector<std::string> keywords { "THL", "VU" };
    std::string foundKeyword;

    bool result = ParserUtility::StartsWithKeyword(line, keywords, foundKeyword);

    CHECK_EQUAL(true, result);
    CHECK_EQUAL("VU", foundKeyword);
}

TEST(LineStartsNotWithKeywordResultsInFalse)
{
    std::string line = "Technische Hilfe klein";
    std::vector<std::string> keywords { "THL", "VU" };
    std::string foundKeyword;

    bool result = ParserUtility::StartsWithKeyword(line, keywords, foundKeyword);

    CHECK_EQUAL(false, result);
    CHECK_EQUAL("", foundKeyword);
}

TEST(GetMessageTextResultsInVuMitPkw)
{
    std::string line = "Schlagw. : VU mit PKW";
    std::string keyword = "Schlagw.";
    std::string expected = "VU mit PKW";

    std::string result = ParserUtility::GetMessageText(line, keyword);

    CHECK_EQUAL(expected, result);
}

TEST(GetMessageTextWithoutKeywordResultsInVuMitPkw)
{
    std::string line = "VU mit PKW";
    std::string expected = "VU mit PKW";

    std::string result = ParserUtility::GetMessageText(line);
    
    CHECK_EQUAL(expected, result);
}

TEST(GetMessageTextWithMissingKeywordResultsInVuMitPkw)
{
    std::string line = "VU mit PKW";
    std::string keyword = "Schlagw.";
    std::string expected = "VU mit PKW";

    std::string result = ParserUtility::GetMessageText(line, keyword);

    CHECK_EQUAL(expected, result);
}

TEST(GetMessageTextWithKeywordAndTimestampResultsInTimestamp)
{
    std::string line = "Alarmiert                       : 13.09.2015 11:36";
    std::string keyword = "Alarmiert";
    std::string expected = "13.09.2015 11:36";

    std::string result = ParserUtility::GetMessageText(line, keyword);

    CHECK_EQUAL(expected, result);
}

TEST(ReadZipCodeFromCityResultsIn91472)
{
    std::string city = "91472 Ipsheim";

    std::string result = ParserUtility::ReadZipCodeFromCity(city);

    CHECK_EQUAL("91472", result);
}

TEST(ReadZipCodeFromCityWithLeadingWhitespaceResultsIn91472)
{
    std::string city = "   91472 Ipsheim";

    std::string result = ParserUtility::ReadZipCodeFromCity(city);

    CHECK_EQUAL("91472", result);
}

TEST(ReadZipCodeFromCityWithWrongContentResultsInEmptyResult)
{
    std::string city = "Ipsheim";

    std::string result = ParserUtility::ReadZipCodeFromCity(city);

    CHECK_EQUAL("", result);
}

TEST(GetTimestampFromMessage)
{
    std::string timestamp = "13.09.2015 11:36";
    boost::posix_time::ptime fallback(boost::gregorian::date(2002, 1, 10), boost::posix_time::time_duration(1, 2, 3));
    boost::posix_time::ptime expected(boost::gregorian::date(2015, 9, 13), boost::posix_time::time_duration(11, 36, 0));

    boost::posix_time::ptime result = ParserUtility::TryGetTimestampFromMessage(timestamp, fallback);

    CHECK_EQUAL(expected, result);
}

TEST(GetTimestampFromMessageOnlyWithDateResultsInCorrectDate)
{
    std::string timestamp = "13.09.2015";
    boost::posix_time::ptime fallback(boost::gregorian::date(2002, 1, 10), boost::posix_time::time_duration(1, 2, 3));
    boost::posix_time::ptime expected(boost::gregorian::date(2015, 9, 13));

    boost::posix_time::ptime result = ParserUtility::TryGetTimestampFromMessage(timestamp, fallback);

    CHECK_EQUAL(expected, result);
}

TEST(GetTimestampFromMessageWithAbcResultsInFallback)
{
    std::string timestamp = "abc";
    boost::posix_time::ptime fallback(boost::gregorian::date(2002, 1, 10), boost::posix_time::time_duration(1, 2, 3));

    boost::posix_time::ptime result = ParserUtility::TryGetTimestampFromMessage(timestamp, fallback);

    CHECK_EQUAL(fallback, result);
}

TEST(GetTimestampFromMessageWithEmptyStringResultsInFallback)
{
    std::string timestamp = "";
    boost::posix_time::ptime fallback(boost::gregorian::date(2002, 1, 10), boost::posix_time::time_duration(1, 2, 3));

    boost::posix_time::ptime result = ParserUtility::TryGetTimestampFromMessage(timestamp, fallback);

    CHECK_EQUAL(fallback, result);
}

TEST(RemoveTrailingNewlineWithLineFeedResultsInDeletedLineFeed)
{
    std::string line = "VU mit PKW\n";
    std::string expected = "VU mit PKW";
    
    ParserUtility::RemoveTrailingNewline(line);

    CHECK_EQUAL(expected, line);
}

TEST(RemoveTrailingNewlineWithoutLineFeedResultsInSameValue)
{
    std::string line = "VU mit PKW";
    std::string expected = "VU mit PKW";

    ParserUtility::RemoveTrailingNewline(line);

    CHECK_EQUAL(expected, line);
}

TEST(RemoveTrailingNewlineWithInnerLineFeedResultsInSameValue)
{
    std::string line = "VU mit\n PKW";
    std::string expected = "VU mit\n PKW";

    ParserUtility::RemoveTrailingNewline(line);

    CHECK_EQUAL(expected, line);
}

TEST(AnalyzeStreetLineResultsInCorrectStreet)
{
    std::string message = "Straße       : Oberndorfer Straße           Haus-Nr.: 12a";
    std::string street;
    std::string streetNumber;
    std::string appendix;

    ParserUtility::AnalyzeStreetLine(message, street, streetNumber, appendix);

    CHECK_EQUAL("Oberndorfer Straße", street);
    CHECK_EQUAL("12a", streetNumber);
    CHECK_EQUAL("", appendix);
}

TEST(AnalyzeStreetLineWithFreewayResultsInCorrectStreet)
{
    std::string message = "Straße       : B470           Haus-Nr./Km: 3";
    std::string street;
    std::string streetNumber;
    std::string appendix;

    ParserUtility::AnalyzeStreetLine(message, street, streetNumber, appendix);

    CHECK_EQUAL("B470", street);
    CHECK_EQUAL("3", streetNumber);
    CHECK_EQUAL("", appendix);
}

TEST(AnalyzeStreetLineWithFreewayWithoutHausNrResultsInCorrectStreet)
{
    std::string message = "Straße       : B470  ";
    std::string street;
    std::string streetNumber;
    std::string appendix;

    ParserUtility::AnalyzeStreetLine(message, street, streetNumber, appendix);

    CHECK_EQUAL("B470", street);
    CHECK_EQUAL("", streetNumber);
    CHECK_EQUAL("", appendix);
}

TEST(AnalyzeStreetLineWithoutHausNrResultsInCorrectStreet)
{
    std::string message = "Straße       : Oberndorfer Straße       ";
    std::string street;
    std::string streetNumber;
    std::string appendix;

    ParserUtility::AnalyzeStreetLine(message, street, streetNumber, appendix);

    CHECK_EQUAL("Oberndorfer Straße", street);
    CHECK_EQUAL("1", streetNumber);
    CHECK_EQUAL("", appendix);
}

TEST(A7ResultsInHighwayIsTrue)
{
    std::string line = "Straße       : A7";

    bool result = ParserUtility::IsHighway(line);

    CHECK_EQUAL(true, result);
}

TEST(B470ResultsInHighwayIsTrue)
{
    std::string line = "Straße       : B470";

    bool result = ParserUtility::IsHighway(line);

    CHECK_EQUAL(true, result);
}

TEST(St2252ResultsInHighwayIsTrue)
{
    std::string line = "Straße       : St2252";

    bool result = ParserUtility::IsHighway(line);

    CHECK_EQUAL(true, result);
}

TEST(ST2252ResultsInHighwayIsTrue)
{
    std::string line = "Straße       : ST2252";

    bool result = ParserUtility::IsHighway(line);

    CHECK_EQUAL(true, result);
}

TEST(NormalStreetResultsInHighwayIsFalse)
{
    std::string line = "Straße       : Oberndorfer Straße           Haus-Nr.: 12a";

    bool result = ParserUtility::IsHighway(line);

    CHECK_EQUAL(false, result);
}

TEST(TrimStringVectorResultsInTrimmedLines)
{
    std::vector<std::string> lines;
    lines.push_back(" abc   ");
    lines.push_back("    def  ");
    lines.push_back("hij");

    ParserUtility::Trim(lines);

    CHECK_EQUAL("abc", lines.at(0));
    CHECK_EQUAL("def", lines.at(1));
    CHECK_EQUAL("hij", lines.at(2));
}
*/
