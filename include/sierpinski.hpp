#pragma once

#include <stdexcept>

#include "boost/multi_array.hpp"

namespace Sierpinski {
  size_t IntegerPower( const size_t x, const size_t n );
  
  boost::multi_array<bool,1> Create1D( const size_t depth );

  boost::multi_array<bool,2> Create2D( const size_t depth );
}

