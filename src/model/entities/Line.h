#ifndef __ENTITIES__LINE_H__
#define __ENTITIES__LINE_H__

#include "Entity.h"

namespace model {
namespace entities {

class Line : public Entity
{
protected:
  std::ostream& put(std::ostream& str) const;
};

} /* entities */
} /* model */

#endif /* end of include guard: __ENTITIES__LINE_H__ */
