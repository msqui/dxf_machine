#ifndef __ENTITIES__LINE_H__
#define __ENTITIES__LINE_H__

#include "Entity.h"

#include "type/types.hpp"

namespace model {
namespace entities {

class Line : public Entity
{
public:
  Line();
  
  type::Point3d start;
  type::Point3d end;
  
protected:
  std::ostream& put(std::ostream& str) const;
};

} /* entities */
} /* model */

#endif /* end of include guard: __ENTITIES__LINE_H__ */
