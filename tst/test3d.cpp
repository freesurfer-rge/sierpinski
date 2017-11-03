#include <boost/test/unit_test.hpp>

#include <sstream>

#include "sierpinski.hpp"

// ===========================

std::string ConvertToString( const boost::multi_array<bool,3>& arr ) {
  std::stringstream result;

  auto shape = arr.shape();

  for( size_t iz=0; iz<shape[0]; iz++ ) {
    for( size_t iy=0; iy<shape[1]; iy++ ) {
      for( size_t ix=0; ix<shape[2]; ix++ ) {
	if( arr[iz][iy][ix] ) {
	  result << '@';
	} else {
	  result << '.';
	}
      }
      result << "?";
    }
    result << std::endl;
  }
  
  return result.str();
}

// ===========================

BOOST_AUTO_TEST_SUITE( Test3d )
BOOST_AUTO_TEST_CASE( Depth0 )
{
  std::stringstream expected;
  expected << "@" << "?" << std::endl;

  auto result = Sierpinski::Create3D(0);

  BOOST_CHECK_EQUAL( static_cast<size_t>(1), result.shape()[0] );
  BOOST_CHECK_EQUAL( static_cast<size_t>(1), result.shape()[1] );
  BOOST_CHECK_EQUAL( static_cast<size_t>(1), result.shape()[2] );
  BOOST_CHECK_EQUAL( expected.str(), ConvertToString(result) );
}

BOOST_AUTO_TEST_CASE( Depth1 )
{
  std::stringstream expected;
  expected << "@.@" << "?";
  expected << "..." << "?";
  expected << "@.@" << "?";
  expected << std::endl;
  expected << "..." << "?";
  expected << ".@." << "?";
  expected << "..." << "?";
  expected << std::endl;
  expected << "@.@" << "?";
  expected << "..." << "?";
  expected << "@.@" << "?";
  expected << std::endl;
  

  auto result = Sierpinski::Create3D(1);

  BOOST_CHECK_EQUAL( static_cast<size_t>(3), result.shape()[0] );
  BOOST_CHECK_EQUAL( static_cast<size_t>(3), result.shape()[1] );
  BOOST_CHECK_EQUAL( static_cast<size_t>(3), result.shape()[2] );
  BOOST_CHECK_EQUAL( expected.str(), ConvertToString(result) );
}

BOOST_AUTO_TEST_CASE( Depth2 )
{
  std::stringstream expected;
  expected << "@.@...@.@" << "?";
  expected << "........." << "?";
  expected << "@.@...@.@" << "?";
  expected << "........." << "?";
  expected << "........." << "?";
  expected << "........." << "?";
  expected << "@.@...@.@" << "?";
  expected << "........." << "?";
  expected << "@.@...@.@" << "?";
  expected << std::endl;
  expected << "........." << "?";
  expected << ".@.....@." << "?";
  expected << "........." << "?";
  expected << "........." << "?";
  expected << "........." << "?";
  expected << "........." << "?";
  expected << "........." << "?";
  expected << ".@.....@." << "?";
  expected << "........." << "?";
  expected << std::endl;
  expected << "@.@...@.@" << "?";
  expected << "........." << "?";
  expected << "@.@...@.@" << "?";
  expected << "........." << "?";
  expected << "........." << "?";
  expected << "........." << "?";
  expected << "@.@...@.@" << "?";
  expected << "........." << "?";
  expected << "@.@...@.@" << "?";
  expected << std::endl;

  expected << "........." << "?";
  expected << "........." << "?";
  expected << "........." << "?";
  expected << "...@.@..." << "?";
  expected << "........." << "?";
  expected << "...@.@..." << "?";
  expected << "........." << "?";
  expected << "........." << "?";
  expected << "........." << "?";
  expected << std::endl;
  expected << "........." << "?";
  expected << "........." << "?";
  expected << "........." << "?";
  expected << "........." << "?";
  expected << "....@...." << "?";
  expected << "........." << "?";
  expected << "........." << "?";
  expected << "........." << "?";
  expected << "........." << "?";
  expected << std::endl;
  expected << "........." << "?";
  expected << "........." << "?";
  expected << "........." << "?";
  expected << "...@.@..." << "?";
  expected << "........." << "?";
  expected << "...@.@..." << "?";
  expected << "........." << "?";
  expected << "........." << "?";
  expected << "........." << "?";
  expected << std::endl;

  expected << "@.@...@.@" << "?";
  expected << "........." << "?";
  expected << "@.@...@.@" << "?";
  expected << "........." << "?";
  expected << "........." << "?";
  expected << "........." << "?";
  expected << "@.@...@.@" << "?";
  expected << "........." << "?";
  expected << "@.@...@.@" << "?";
  expected << std::endl;
  expected << "........." << "?";
  expected << ".@.....@." << "?";
  expected << "........." << "?";
  expected << "........." << "?";
  expected << "........." << "?";
  expected << "........." << "?";
  expected << "........." << "?";
  expected << ".@.....@." << "?";
  expected << "........." << "?";
  expected << std::endl;
  expected << "@.@...@.@" << "?";
  expected << "........." << "?";
  expected << "@.@...@.@" << "?";
  expected << "........." << "?";
  expected << "........." << "?";
  expected << "........." << "?";
  expected << "@.@...@.@" << "?";
  expected << "........." << "?";
  expected << "@.@...@.@" << "?";
  expected << std::endl;
  
  auto result = Sierpinski::Create3D(2);

  BOOST_CHECK_EQUAL( static_cast<size_t>(9), result.shape()[0] );
  BOOST_CHECK_EQUAL( static_cast<size_t>(9), result.shape()[1] );
  BOOST_CHECK_EQUAL( static_cast<size_t>(9), result.shape()[2] );
  BOOST_CHECK_EQUAL( expected.str(), ConvertToString(result) );
}

BOOST_AUTO_TEST_CASE( TooLarge )
{
  auto checkMsg = []( std::invalid_argument const& e ) {
    std::string expected = "Depth too great";
    BOOST_TEST_INFO("Check for message: " << expected);
    return expected == e.what();
  };

  BOOST_CHECK_EXCEPTION( Sierpinski::Create3D(256), std::invalid_argument, checkMsg );
}

BOOST_AUTO_TEST_SUITE_END()
