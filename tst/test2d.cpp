#include <boost/test/unit_test.hpp>

#include <sstream>

#include "sierpinski.hpp"

// ===========================

std::string ConvertToString( const boost::multi_array<bool,2>& arr ) {
  std::stringstream result;

  auto shape = arr.shape();

  for( size_t iy=0; iy<shape[0]; iy++ ) {
    for( size_t ix=0; ix<shape[1]; ix++ ) {
      if( arr[iy][ix] ) {
	result << '@';
      } else {
	result << '.';
      }
    }
    result << std::endl;
  }
  
  return result.str();
}

// ===========================

BOOST_AUTO_TEST_SUITE( Test2d )
BOOST_AUTO_TEST_CASE( Depth0 )
{
  std::stringstream expected;
  expected << "@" << std::endl;

  auto result = Sierpinski::Create2D(0);

  BOOST_CHECK_EQUAL( static_cast<size_t>(1), result.shape()[0] );
  BOOST_CHECK_EQUAL( static_cast<size_t>(1), result.shape()[1] );
  BOOST_CHECK_EQUAL( expected.str(), ConvertToString(result) );
}

BOOST_AUTO_TEST_CASE( Depth1 )
{
  std::stringstream expected;
  expected << "@.@" << std::endl;
  expected << ".@." << std::endl;
  expected << "@.@" << std::endl;

  auto result = Sierpinski::Create2D(1);

  BOOST_CHECK_EQUAL( static_cast<size_t>(3), result.shape()[0] );
  BOOST_CHECK_EQUAL( static_cast<size_t>(3), result.shape()[1] );
  BOOST_CHECK_EQUAL( expected.str(), ConvertToString(result) );
}

BOOST_AUTO_TEST_CASE( Depth2 )
{
  std::stringstream expected;
  expected << "@.@...@.@" << std::endl;
  expected << ".@.....@." << std::endl;
  expected << "@.@...@.@" << std::endl;
  expected << "...@.@..." << std::endl;
  expected << "....@...." << std::endl;
  expected << "...@.@..." << std::endl;
  expected << "@.@...@.@" << std::endl;
  expected << ".@.....@." << std::endl;
  expected << "@.@...@.@" << std::endl;

  auto result = Sierpinski::Create2D(2);

  BOOST_CHECK_EQUAL( static_cast<size_t>(9), result.shape()[0] );
  BOOST_CHECK_EQUAL( static_cast<size_t>(9), result.shape()[1] );
  BOOST_CHECK_EQUAL( expected.str(), ConvertToString(result) );
}

BOOST_AUTO_TEST_CASE( Depth3 )
{
  std::stringstream expected;
  expected << "@.@...@.@.........@.@...@.@" << std::endl;
  expected << ".@.....@...........@.....@." << std::endl;
  expected << "@.@...@.@.........@.@...@.@" << std::endl;
  expected << "...@.@...............@.@..." << std::endl;
  expected << "....@.................@...." << std::endl;
  expected << "...@.@...............@.@..." << std::endl;
  expected << "@.@...@.@.........@.@...@.@" << std::endl;
  expected << ".@.....@...........@.....@." << std::endl;
  expected << "@.@...@.@.........@.@...@.@" << std::endl;
  expected << ".........@.@...@.@........." << std::endl;
  expected << "..........@.....@.........." << std::endl;
  expected << ".........@.@...@.@........." << std::endl;
  expected << "............@.@............" << std::endl;
  expected << ".............@............." << std::endl;
  expected << "............@.@............" << std::endl;
  expected << ".........@.@...@.@........." << std::endl;
  expected << "..........@.....@.........." << std::endl;
  expected << ".........@.@...@.@........." << std::endl;
  expected << "@.@...@.@.........@.@...@.@" << std::endl;
  expected << ".@.....@...........@.....@." << std::endl;
  expected << "@.@...@.@.........@.@...@.@" << std::endl;
  expected << "...@.@...............@.@..." << std::endl;
  expected << "....@.................@...." << std::endl;
  expected << "...@.@...............@.@..." << std::endl;
  expected << "@.@...@.@.........@.@...@.@" << std::endl;
  expected << ".@.....@...........@.....@." << std::endl;
  expected << "@.@...@.@.........@.@...@.@" << std::endl;

  auto result = Sierpinski::Create2D(3);

  BOOST_CHECK_EQUAL( static_cast<size_t>(27), result.shape()[0] );
  BOOST_CHECK_EQUAL( static_cast<size_t>(27), result.shape()[1] );
  BOOST_CHECK_EQUAL( expected.str(), ConvertToString(result) );
}

BOOST_AUTO_TEST_CASE( TooLarge )
{
  auto checkMsg = []( std::invalid_argument const& e ) {
    std::string expected = "Depth too great";
    BOOST_TEST_INFO("Check for message: " << expected);
    return expected == e.what();
  };

  BOOST_CHECK_EXCEPTION( Sierpinski::Create2D(256), std::invalid_argument, checkMsg );
}

BOOST_AUTO_TEST_SUITE_END()
