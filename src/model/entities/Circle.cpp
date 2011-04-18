#include "Circle.h"

namespace model {
namespace entities {

Circle::Circle()
{
  std::cout << "Circle created" << std::endl;
}

std::ostream& Circle::put(std::ostream& str) const
{
  str << "Circle";
  return str;
}

} /* entities */
} /* model */
