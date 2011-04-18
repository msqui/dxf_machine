#include "LwPolyline.h"

namespace model {
namespace entities {

LwPolyline::LwPolyline()
{
  #ifdef DEBUG
    std::cout << "LwPolyline created" << std::endl;
  #endif
}

std::ostream& LwPolyline::put(std::ostream& str) const
{
  str << "LwPolyline";
  return str;
}

} /* entities */
} /* model */
