#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "../include/PropertyLocation.h"
#include "../include/IlsAnsbach.h"
#include "../include/IOperation.h"

using namespace boost::unit_test;

BOOST_AUTO_TEST_CASE( ParseFileWithEmptyFilename )
{
   IlsAnsbach* parser = new IlsAnsbach();
   IOperation* result = parser->Parse("");

   BOOST_CHECK(result == nullptr);

   delete parser;
}

BOOST_AUTO_TEST_CASE( ParseFileWithNotExistingFile )
{
   IlsAnsbach* parser = new IlsAnsbach();
   IOperation* result = parser->Parse("/tmp/sowieso");

   BOOST_CHECK(result == nullptr);

   delete parser;
}

BOOST_AUTO_TEST_CASE( Fail )
{
   BOOST_CHECK(true == false);
}