#ifndef __ENTITIES__ENTITY_H__
#define __ENTITIES__ENTITY_H__

#include <iostream>

namespace model {
namespace entities {
/**
 * ABC for entities
**/
class Entity
{
public:
  virtual ~Entity();
  
  friend std::ostream& operator<< (std::ostream& str, const Entity& ent)
  {
    return ent.put(str);
  }
  
protected:
  virtual std::ostream& put(std::ostream& str) const = 0;
  
};

} /* entities */
} /* model */

#endif /* end of include guard: __ENTITIES__ENTITY_H__ */
