#include "Line.h"

namespace model {
namespace entities {

Line::Line()
{
  #ifdef DEBUG
    std::cout << "Line created" << std::endl;
  #endif
}

std::ostream& Line::put(std::ostream& str) const
{
  str << "Line";
  return str;
}

} /* entities */
} /* model */
