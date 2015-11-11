#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/date_time/posix_time/posix_time_types.hpp>
#include "../include/PropertyLocation.h"

using namespace boost::unit_test;


BOOST_AUTO_TEST_CASE(SettedCityResultsInMeaningfulTrue)
{
    PropertyLocation* location = new PropertyLocation();
    location->SetCity("Ipsheim");

    BOOST_CHECK(true == location->IsMeaningful());

    delete location;
}

BOOST_AUTO_TEST_CASE(SettedZipCodeResultsInMeaningfulTrue)
{
    PropertyLocation* location = new PropertyLocation();
    location->SetZipCode("91472");

    BOOST_CHECK(true == location->IsMeaningful());

    delete location;
}

BOOST_AUTO_TEST_CASE(SettedStreetResultsInMeaningfulTrue)
{
    PropertyLocation* location = new PropertyLocation();
    location->SetStreet("Waldstr.");

    BOOST_CHECK(true == location->IsMeaningful());

    delete location;
}

BOOST_AUTO_TEST_CASE(SettedNothingResultsInMeaningfulFalse)
{
    PropertyLocation* location = new PropertyLocation();

    BOOST_CHECK(false == location->IsMeaningful());

    delete location;
}

BOOST_AUTO_TEST_CASE(SettedEmptyCityResultsInMeaningfulFalse)
{
    PropertyLocation* location = new PropertyLocation();
    location->SetCity("   ");

    BOOST_CHECK(false == location->IsMeaningful());

    delete location;
}

BOOST_AUTO_TEST_CASE(SetCityWithTrailingWhitespaceResultsIpsheim)
{
    PropertyLocation* location = new PropertyLocation();
    location->SetCity("  Ipsheim    ");

    BOOST_CHECK("Ipsheim" == location->GetCity());

    delete location;
}

BOOST_AUTO_TEST_CASE(SettedNothingResultsInHasGeoCoordinatesFalse)
{
    PropertyLocation* location = new PropertyLocation();

    BOOST_CHECK(false == location->HasGeoCoordinates());

    delete location;
}

BOOST_AUTO_TEST_CASE(SettedLatitudeResultsInHasGeoCoordinatesTrue)
{
    PropertyLocation* location = new PropertyLocation();
    location->SetGeoLatitude("1,0");

    BOOST_CHECK(true == location->HasGeoCoordinates());

    delete location;
}

BOOST_AUTO_TEST_CASE(SettedLongitudeResultsInHasGeoCoordinatesTrue)
{
    PropertyLocation* location = new PropertyLocation();
    location->SetGeoLongitude("1,0");

    BOOST_CHECK(true == location->HasGeoCoordinates());

    delete location;
}

BOOST_AUTO_TEST_CASE(SettedStreetAndLocationResultsCorrectString)
{
    PropertyLocation* location = new PropertyLocation();
    location->SetStreet("Waldstr.");
    location->SetStreetNumber("46");
    location->SetZipCode("91472");
    location->SetCity("Ipsheim");

    std::string expected = "Waldstr. 46, 91472 Ipsheim";
    BOOST_CHECK(expected == location->ToString());

    delete location;
}

BOOST_AUTO_TEST_CASE(SettedStreetResultsCorrectString)
{
    PropertyLocation* location = new PropertyLocation();
    location->SetStreet("Waldstr.");
    location->SetStreetNumber("46");

    std::string expected = "Waldstr. 46";
    BOOST_CHECK(expected == location->ToString());

    delete location;
}

BOOST_AUTO_TEST_CASE(SettedCityResultsCorrectString)
{
    PropertyLocation* location = new PropertyLocation();
    location->SetZipCode("91472");
    location->SetCity("Ipsheim");

    std::string expected = "91472 Ipsheim";
    BOOST_CHECK(expected == location->ToString());

    delete location;
}

BOOST_AUTO_TEST_CASE(SettedOnlyStreetAndCityWithoutNumberResultsCorrectString)
{
    PropertyLocation* location = new PropertyLocation();
    location->SetStreet("Waldstr.");
    location->SetCity("Ipsheim");

    std::string expected = "Waldstr., Ipsheim";
    BOOST_CHECK(expected == location->ToString());

    delete location;
}

BOOST_AUTO_TEST_CASE(SettedOnlyStreetAndZipCodeResultsCorrectString)
{
    PropertyLocation* location = new PropertyLocation();
    location->SetStreet("Waldstr.");
    location->SetZipCode("91472");

    std::string expected = "Waldstr., 91472";
    BOOST_CHECK(expected == location->ToString());

    delete location;
}

BOOST_AUTO_TEST_CASE(CopyConstructerCreatesIdenticalObject)
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

    BOOST_CHECK(location->GetCity() == copiedObject->GetCity());
    BOOST_CHECK(location->GetGeoLatitude() == copiedObject->GetGeoLatitude());
    BOOST_CHECK(location->GetGeoLongitude() == copiedObject->GetGeoLongitude());
    BOOST_CHECK(location->GetIntersection() == copiedObject->GetIntersection());
    BOOST_CHECK(location->GetLocation() == copiedObject->GetLocation());
    BOOST_CHECK(location->GetProperty() == copiedObject->GetProperty());
    BOOST_CHECK(location->GetStreet() == copiedObject->GetStreet());
    BOOST_CHECK(location->GetStreetNumber() == copiedObject->GetStreetNumber());
    BOOST_CHECK(location->GetZipCode() == copiedObject->GetZipCode());

    delete location;
    delete copiedObject;
}
