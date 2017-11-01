#include <boost/test/unit_test.hpp>
#include <boost/test/data/test_case.hpp>
#include <boost/test/data/monomorphic.hpp>

#include "sierpinski.hpp"

// ========================================

const size_t validSizes[] = { 1, 3, 9, 27, 81 };

// ========================================

BOOST_AUTO_TEST_SUITE( Basic )

BOOST_DATA_TEST_CASE( SetAndGetLength, boost::unit_test::data::make( validSizes ), l )
{
  Sierpinski s;

  s.SetLength(l);
  BOOST_CHECK_EQUAL(l, s.GetLength() );
}

BOOST_AUTO_TEST_CASE( SetZeroLength )
{
  Sierpinski s;

  auto checkMsg = []( std::invalid_argument const& e ) {
    return std::string("Must have value > 0") == e.what();
  };

  BOOST_CHECK_EXCEPTION( s.SetLength(0), std::invalid_argument, checkMsg );
}

BOOST_AUTO_TEST_CASE( SetNonPower3 )
{
  Sierpinski s;

  auto checkMsg = []( std::invalid_argument const& e ) {
    return std::string("Not a power of 3") == e.what();
  };

  BOOST_CHECK_EXCEPTION( s.SetLength(2), std::invalid_argument, checkMsg );
  BOOST_CHECK_EXCEPTION( s.SetLength(4), std::invalid_argument, checkMsg );
  BOOST_CHECK_EXCEPTION( s.SetLength(6), std::invalid_argument, checkMsg );
  BOOST_CHECK_EXCEPTION( s.SetLength(7), std::invalid_argument, checkMsg );
  BOOST_CHECK_EXCEPTION( s.SetLength(8), std::invalid_argument, checkMsg );
  BOOST_CHECK_EXCEPTION( s.SetLength(10), std::invalid_argument, checkMsg );
  BOOST_CHECK_EXCEPTION( s.SetLength(18), std::invalid_argument, checkMsg );
  BOOST_CHECK_EXCEPTION( s.SetLength(26), std::invalid_argument, checkMsg );
  BOOST_CHECK_EXCEPTION( s.SetLength(28), std::invalid_argument, checkMsg );
}

BOOST_AUTO_TEST_SUITE_END()
