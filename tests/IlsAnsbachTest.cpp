#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "../include/PropertyLocation.h"
#include "../include/IlsAnsbach.h"
#include "../include/IOperation.h"

using namespace boost::unit_test;

BOOST_AUTO_TEST_CASE( ParseFile )
{
   IlsAnsbach* parser = new IlsAnsbach();
   bool result = parser->Parse("");

   BOOST_CHECK(true == result);

   delete parser;
}
