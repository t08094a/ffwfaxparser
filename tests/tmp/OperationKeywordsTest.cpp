#include <UnitTest++.h>
//#include "../src/OperationKeywords.cpp"
#include "../include/OperationKeywords.h"

TEST(NotEmptyKeywordsResultsInCorrectOutput)
{
    OperationKeywords* op = new OperationKeywords();
    op->SetKeyword("eins");

    std::string expected = "Stichwort: eins";
    CHECK_EQUAL(expected, op->ToString());

    delete op;
}

TEST(NotEmptyEmergencyKeywordsResultsInCorrectOutput)
{
    OperationKeywords* op = new OperationKeywords();
    op->SetEmergencyKeyword("eins");

    std::string expected = "Stichwort: eins";
    CHECK_EQUAL(expected, op->ToString());

    delete op;
}

TEST(SettedAllResultsInCorrectOutput)
{
    OperationKeywords* op = new OperationKeywords();
    op->SetKeyword("eins");
    op->SetEmergencyKeyword("zwei");
    op->SetB("b1");
    op->SetR("r1");
    op->SetS("s1");
    op->SetT("t1");

    std::string expected = "Stichwort: eins, Stichwort: zwei, B: b1, R: r1, S: s1, T: t1";
    CHECK_EQUAL(expected, op->ToString());

    delete op;
}

TEST(SettedAllWithoutRKeywordsResultsInCorrectOutput)
{
    OperationKeywords* op = new OperationKeywords();
    op->SetKeyword("eins");
    op->SetEmergencyKeyword("zwei");
    op->SetB("b1");
    op->SetS("s1");
    op->SetT("t1");

    std::string expected = "Stichwort: eins, Stichwort: zwei, B: b1, S: s1, T: t1";
    CHECK_EQUAL(expected, op->ToString());

    delete op;
}
