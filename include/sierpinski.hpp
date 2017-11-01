#pragma once

#include <stdexcept>

class Sierpinski {
public:
  void SetLength( const size_t l );
  size_t GetLength() const;
  
private:
  size_t length;

  const size_t factor = 3;

  bool CheckPowerFactor( const size_t value ) const {
    if( value == 0 ) {
      throw std::invalid_argument("Must have value > 0");
    }
    
    size_t current = value;

    while( current > 1 ) {
      if( (current % Sierpinski::factor) != 0 ) {
	return false;
      }

      current /= factor;
    }

    return true;
  }
};
