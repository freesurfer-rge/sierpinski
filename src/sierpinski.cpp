#include <sstream>

#include "sierpinski.hpp"

void Sierpinski::SetLength( const size_t l ) {
  if( !this->CheckPowerFactor(l) ) {
    std::stringstream msg;
    msg << "Not a power of " << factor;
    throw std::invalid_argument(msg.str().c_str());
  }

  this->length = l;
}

size_t Sierpinski::GetLength() const {
  return this->length;
}
