#ifndef __ENTITIES__CIRCLE_H__
#define __ENTITIES__CIRCLE_H__

#include "Entity.h"

#include "type/types.hpp"

namespace model {
namespace entities {

class Circle : public Entity
{
public:
  Circle();
  
  type::Point3d center;
  double radius;
  
protected:
  std::ostream& put(std::ostream& str) const;
};

} /* entities */
} /* model */

#endif /* end of include guard: __ENTITIES__CIRCLE_H__ */
