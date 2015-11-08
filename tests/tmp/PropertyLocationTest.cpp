#include <UnitTest++.h>
//#include "../src/PropertyLocation.cpp"
#include "../include/PropertyLocation.h"


TEST(SettedCityResultsInMeaningfulTrue)
{
    PropertyLocation* location = new PropertyLocation();
    location->SetCity("Ipsheim");

    CHECK_EQUAL(true, location->IsMeaningful());

    delete location;
}

TEST(SettedZipCodeResultsInMeaningfulTrue)
{
    PropertyLocation* location = new PropertyLocation();
    location->SetZipCode("91472");

    CHECK_EQUAL(true, location->IsMeaningful());

    delete location;
}

TEST(SettedStreetResultsInMeaningfulTrue)
{
    PropertyLocation* location = new PropertyLocation();
    location->SetStreet("Waldstr.");

    CHECK_EQUAL(true, location->IsMeaningful());

    delete location;
}

TEST(SettedNothingResultsInMeaningfulFalse)
{
    PropertyLocation* location = new PropertyLocation();

    CHECK_EQUAL(false, location->IsMeaningful());

    delete location;
}

TEST(SettedEmptyCityResultsInMeaningfulFalse)
{
    PropertyLocation* location = new PropertyLocation();
    location->SetCity("   ");

    CHECK_EQUAL(false, location->IsMeaningful());

    delete location;
}

TEST(SetCityWithTrailingWhitespaceResultsIpsheim)
{
    PropertyLocation* location = new PropertyLocation();
    location->SetCity("  Ipsheim    ");

    CHECK_EQUAL("Ipsheim", location->GetCity());

    delete location;
}

TEST(SettedNothingResultsInHasGeoCoordinatesFalse)
{
    PropertyLocation* location = new PropertyLocation();

    CHECK_EQUAL(false, location->HasGeoCoordinates());

    delete location;
}

TEST(SettedLatitudeResultsInHasGeoCoordinatesTrue)
{
    PropertyLocation* location = new PropertyLocation();
    location->SetGeoLatitude("1,0");

    CHECK_EQUAL(true, location->HasGeoCoordinates());

    delete location;
}

TEST(SettedLongitudeResultsInHasGeoCoordinatesTrue)
{
    PropertyLocation* location = new PropertyLocation();
    location->SetGeoLongitude("1,0");

    CHECK_EQUAL(true, location->HasGeoCoordinates());

    delete location;
}

TEST(SettedStreetAndLocationResultsCorrectString)
{
    PropertyLocation* location = new PropertyLocation();
    location->SetStreet("Waldstr.");
    location->SetStreetNumber("46");
    location->SetZipCode("91472");
    location->SetCity("Ipsheim");

    std::string expected = "Waldstr. 46, 91472 Ipsheim";
    CHECK_EQUAL(expected, location->ToString());

    delete location;
}

TEST(SettedStreetResultsCorrectString)
{
    PropertyLocation* location = new PropertyLocation();
    location->SetStreet("Waldstr.");
    location->SetStreetNumber("46");

    std::string expected = "Waldstr. 46";
    CHECK_EQUAL(expected, location->ToString());

    delete location;
}

TEST(SettedCityResultsCorrectString)
{
    PropertyLocation* location = new PropertyLocation();
    location->SetZipCode("91472");
    location->SetCity("Ipsheim");

    std::string expected = "91472 Ipsheim";
    CHECK_EQUAL(expected, location->ToString());

    delete location;
}

TEST(SettedOnlyStreetAndCityWithoutNumberResultsCorrectString)
{
    PropertyLocation* location = new PropertyLocation();
    location->SetStreet("Waldstr.");
    location->SetCity("Ipsheim");

    std::string expected = "Waldstr., Ipsheim";
    CHECK_EQUAL(expected, location->ToString());

    delete location;
}

TEST(SettedOnlyStreetAndZipCodeResultsCorrectString)
{
    PropertyLocation* location = new PropertyLocation();
    location->SetStreet("Waldstr.");
    location->SetZipCode("91472");

    std::string expected = "Waldstr., 91472";
    CHECK_EQUAL(expected, location->ToString());

    delete location;
}

TEST(CopyConstructerCreatesIdenticalObject)
{
    PropertyLocation* location = new PropertyLocation();
    location->SetCity("Ipsheim");
    location->SetGeoLatitude("1,0");
    location->SetGeoLongitude("2,0");
    location->SetIntersection("intersection");
    location->SetLocation("Ipsheim");
    location->SetProperty("Wohnhaus");
    location->SetStreet("Waldstr.");
    location->SetStreetNumber("46");
    location->SetZipCode("91472");

    PropertyLocation* copiedObject = new PropertyLocation(*location);

    CHECK_EQUAL(location->GetCity(), copiedObject->GetCity());
    CHECK_EQUAL(location->GetGeoLatitude(), copiedObject->GetGeoLatitude());
    CHECK_EQUAL(location->GetGeoLongitude(), copiedObject->GetGeoLongitude());
    CHECK_EQUAL(location->GetIntersection(), copiedObject->GetIntersection());
    CHECK_EQUAL(location->GetLocation(), copiedObject->GetLocation());
    CHECK_EQUAL(location->GetProperty(), copiedObject->GetProperty());
    CHECK_EQUAL(location->GetStreet(), copiedObject->GetStreet());
    CHECK_EQUAL(location->GetStreetNumber(), copiedObject->GetStreetNumber());
    CHECK_EQUAL(location->GetZipCode(), copiedObject->GetZipCode());

    delete location;
    delete copiedObject;
}
