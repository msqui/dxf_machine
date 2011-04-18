#ifndef __ENTITIES__LWPOLYLINE_H__
#define __ENTITIES__LWPOLYLINE_H__

#include "Entity.h"

#include <vector>

#include "type/types.hpp"

namespace model {
namespace entities {

class LwPolyline : public Entity
{
public:
  LwPolyline();
  
  std::vector<type::Point3d> points;
  
protected:
  std::ostream& put(std::ostream& str) const;
};

} /* entities */
} /* model */

#endif /* end of include guard: __ENTITIES__LWPOLYLINE_H__ */
