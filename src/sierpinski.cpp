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
  
  bool CheckStencil( const size_t y, const size_t x ) {
    unsigned int counts[factor] = {0,0,0};

    counts[x]++;
    counts[y]++;

    return( (counts[1]==0) || (counts[1]==2) );
  }

  bool CheckStencil( const size_t z, const size_t y, const size_t x ) {
    unsigned int counts[factor] = {0,0,0};

    counts[x]++;
    counts[y]++;
    counts[z]++;

    return( (counts[1]==0) || (counts[1]==3) );
  }

  size_t ReduceCoord( const size_t scale, const size_t val ) {
    return (val / scale) % factor;
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
	currValue = currValue && CheckStencil( ReduceCoord(currScale,i) );
	currScale /= factor;
      }
      
      result[i] = currValue;
    }
    
    return result;
  }

  boost::multi_array<bool,2> Create2D( const size_t depth ) {
    if( depth > floor(log(std::numeric_limits<size_t>::max()) / log(factor)) ) {
      throw std::invalid_argument("Depth too great");
    }

    const size_t nVals = IntegerPower(factor,depth);
    boost::multi_array<bool,2> result(boost::extents[nVals][nVals]);

    for( size_t iy=0; iy<nVals; iy++ ) {
      for( size_t ix=0; ix<nVals; ix++ ) {
	bool currValue = true;

	size_t currScale = nVals / factor;
	while( (currScale>0) && currValue ) {
	  const size_t redy = ReduceCoord(currScale,iy);
	  const size_t redx = ReduceCoord(currScale,ix);
	  currValue = currValue && CheckStencil( redy, redx );
	  currScale /= factor;
	}

	result[iy][ix] = currValue;
      }
    }
    
    return result;
  }

  boost::multi_array<bool,3> Create3D( const size_t depth ) {
    if( depth > floor(log(std::numeric_limits<size_t>::max()) / log(factor)) ) {
      throw std::invalid_argument("Depth too great");
    }

    const size_t nVals = IntegerPower(factor,depth);
    boost::multi_array<bool,3> result(boost::extents[nVals][nVals][nVals]);

    for( size_t iz=0; iz<nVals; iz++ ) {
      for( size_t iy=0; iy<nVals; iy++ ) {
	for( size_t ix=0; ix<nVals; ix++ ) {
	  bool currValue = true;

	  size_t currScale = nVals / factor;
	  while( (currScale>0) && currValue ) {
	    const size_t redz = ReduceCoord(currScale,iz);
	    const size_t redy = ReduceCoord(currScale,iy);
	    const size_t redx = ReduceCoord(currScale,ix);
	    currValue = currValue && CheckStencil( redz, redy, redx );
	    currScale /= factor;
	  }
	  
	  result[iz][iy][ix] = currValue;
	}
      }
    }
    
    return result;
  }
}
