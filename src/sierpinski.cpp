#include <sstream>
#include <iostream>
#include <cmath>

#include "sierpinski.hpp"

namespace Sierpinski {
  const size_t factor = 3;
  
  size_t IntegerPower( const size_t x, const size_t n ) {
    if( n == 0 ) {
      return 1;
    } else if( n == 1 ) {
      return x;
    }
    
    if( (n%2) == 0 ) {
      size_t tmp = IntegerPower(x,n/2);
      return tmp*tmp;
    } else {
      return x * IntegerPower(x,n-1);
    }
  }
  
  bool CheckStencil( const size_t x ) {
    return( (x==0) || (x==2) );
  }
  
  boost::multi_array<bool,1> Create1D( const size_t depth ) {
    if( depth > floor(log(std::numeric_limits<size_t>::max()) / log(factor)) ) {
      throw std::invalid_argument("Depth too great");
    }
    
    const size_t nVals = IntegerPower(factor,depth);
    boost::multi_array<bool,1> result(boost::extents[nVals]);
    
    for( size_t i=0; i<nVals; i++ ) {
      bool currValue = true;
      
      size_t currScale = nVals / factor;
      while( (currScale > 0) && currValue ) {
	currValue = currValue && CheckStencil( (i / currScale) % factor );
	currScale /= factor;
      }
      
      result[i] = currValue;
    }
    
    return result;
  }
}
