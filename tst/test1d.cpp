#include <boost/test/unit_test.hpp>

#include <sstream>

#include "sierpinski.hpp"

// ===========================

std::string ConvertToString( const boost::multi_array<bool,1>& arr ) {
  std::stringstream result;

  for( auto it=arr.begin(); it!=arr.end(); ++it ) {
    if( *it ) {
      result << '@';
    } else {
      result << '.';
    }
  }
  
  return result.str();
}

// ===========================

BOOST_AUTO_TEST_SUITE( Test1d )

BOOST_AUTO_TEST_CASE( Depth0 )
{
  std::string expected = "@";

  auto result = Sierpinski::Create1D(0);

  BOOST_CHECK_EQUAL( static_cast<size_t>(1), result.shape()[0] );
  BOOST_CHECK_EQUAL( expected, ConvertToString(result) );
}

BOOST_AUTO_TEST_CASE( Depth1 )
{
  std::string expected = "@.@";

  auto result = Sierpinski::Create1D(1);

  BOOST_CHECK_EQUAL( static_cast<size_t>(3), result.shape()[0] );
  BOOST_CHECK_EQUAL( expected, ConvertToString(result) );
}

BOOST_AUTO_TEST_CASE( Depth2 )
{
  std::string expected = "@.@...@.@";

  auto result = Sierpinski::Create1D(2);

  BOOST_CHECK_EQUAL( static_cast<size_t>(9), result.shape()[0] );
  BOOST_CHECK_EQUAL( expected, ConvertToString(result) );
}

BOOST_AUTO_TEST_CASE( Depth3 )
{
  std::string expected = "@.@...@.@.........@.@...@.@";

  auto result = Sierpinski::Create1D(3);

  BOOST_CHECK_EQUAL( static_cast<size_t>(27), result.shape()[0] );
  BOOST_CHECK_EQUAL( expected, ConvertToString(result) );
}

BOOST_AUTO_TEST_CASE( Depth4 )
{
  std::string expected = std::string("") +
    std::string("@.@...@.@.........@.@...@.@") +
    std::string("...........................") +
    std::string("@.@...@.@.........@.@...@.@");
    

  auto result = Sierpinski::Create1D(4);

  BOOST_CHECK_EQUAL( static_cast<size_t>(81), result.shape()[0] );
  BOOST_CHECK_EQUAL( expected, ConvertToString(result) );
}

BOOST_AUTO_TEST_CASE( TooLarge )
{
  auto checkMsg = []( std::invalid_argument const& e ) {
    std::string expected = "Depth too great";
    BOOST_TEST_INFO("Check for message: " << expected);
    return expected == e.what();
  };

  BOOST_CHECK_EXCEPTION( Sierpinski::Create1D(256), std::invalid_argument, checkMsg );
}

BOOST_AUTO_TEST_SUITE_END()
