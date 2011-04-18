#include "Line.h"

namespace model {
namespace entities {

std::ostream& Line::put(std::ostream& str) const
{
  str << "Line";
  return str;
}

} /* entities */
} /* model */
