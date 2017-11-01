#include <boost/test/unit_test.hpp>
#include <boost/test/data/test_case.hpp>
#include <boost/test/data/monomorphic.hpp>

#include "sierpinski.hpp"

// ========================================

BOOST_AUTO_TEST_SUITE( Basic )

BOOST_AUTO_TEST_CASE( IntegerPowers )
{
  BOOST_CHECK_EQUAL( static_cast<size_t>(1), Sierpinski::IntegerPower(2,0) );
  BOOST_CHECK_EQUAL( static_cast<size_t>(1), Sierpinski::IntegerPower(3,0) );
  BOOST_CHECK_EQUAL( static_cast<size_t>(1), Sierpinski::IntegerPower(5,0) );
  
  BOOST_CHECK_EQUAL( static_cast<size_t>(2), Sierpinski::IntegerPower(2,1) );
  BOOST_CHECK_EQUAL( static_cast<size_t>(3), Sierpinski::IntegerPower(3,1) );

  BOOST_CHECK_EQUAL( static_cast<size_t>(4), Sierpinski::IntegerPower(2,2) );
  BOOST_CHECK_EQUAL( static_cast<size_t>(9), Sierpinski::IntegerPower(3,2) );

  BOOST_CHECK_EQUAL( static_cast<size_t>(8), Sierpinski::IntegerPower(2,3) );
  BOOST_CHECK_EQUAL( static_cast<size_t>(27), Sierpinski::IntegerPower(3,3) );

  BOOST_CHECK_EQUAL( static_cast<size_t>(16), Sierpinski::IntegerPower(2,4) );
  BOOST_CHECK_EQUAL( static_cast<size_t>(81), Sierpinski::IntegerPower(3,4) );

  BOOST_CHECK_EQUAL( static_cast<size_t>(128), Sierpinski::IntegerPower(2,7) );
}

BOOST_AUTO_TEST_SUITE_END()
