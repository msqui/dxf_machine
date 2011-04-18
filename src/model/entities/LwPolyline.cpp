#include "LwPolyline.h"

namespace model {
namespace entities {

std::ostream& LwPolyline::put(std::ostream& str) const
{
  str << "LwPolyline";
  return str;
}

} /* entities */
} /* model */
