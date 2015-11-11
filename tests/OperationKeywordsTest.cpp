#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/date_time/posix_time/posix_time_types.hpp>
#include "../include/OperationKeywords.h"

BOOST_AUTO_TEST_CASE(NotEmptyKeywordsResultsInCorrectOutput)
{
    OperationKeywords* op = new OperationKeywords();
    op->SetKeyword("eins");

    std::string expected = "Stichwort: eins";
    BOOST_CHECK(expected == op->ToString());

    delete op;
}

BOOST_AUTO_TEST_CASE(NotEmptyEmergencyKeywordsResultsInCorrectOutput)
{
    OperationKeywords* op = new OperationKeywords();
    op->SetEmergencyKeyword("eins");

    std::string expected = "Stichwort: eins";
    BOOST_CHECK(expected == op->ToString());

    delete op;
}

BOOST_AUTO_TEST_CASE(SettedAllResultsInCorrectOutput)
{
    OperationKeywords* op = new OperationKeywords();
    op->SetKeyword("eins");
    op->SetEmergencyKeyword("zwei");
    op->SetB("b1");
    op->SetR("r1");
    op->SetS("s1");
    op->SetT("t1");

    std::string expected = "Stichwort: eins, Stichwort: zwei, B: b1, R: r1, S: s1, T: t1";
    BOOST_CHECK(expected == op->ToString());

    delete op;
}

BOOST_AUTO_TEST_CASE(SettedAllWithoutRKeywordsResultsInCorrectOutput)
{
    OperationKeywords* op = new OperationKeywords();
    op->SetKeyword("eins");
    op->SetEmergencyKeyword("zwei");
    op->SetB("b1");
    op->SetS("s1");
    op->SetT("t1");

    std::string expected = "Stichwort: eins, Stichwort: zwei, B: b1, S: s1, T: t1";
    BOOST_CHECK(expected == op->ToString());

    delete op;
}
