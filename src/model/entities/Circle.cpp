#include "Circle.h"

namespace model {
namespace entities {

std::ostream& Circle::put(std::ostream& str) const
{
  str << "Circle";
  return str;
}

} /* entities */
} /* model */
