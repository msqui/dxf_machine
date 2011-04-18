#ifndef __ENTITIES__ENTITYFACTORY_HPP__
#define __ENTITIES__ENTITYFACTORY_HPP__

#include "Entity.h"

namespace model {
namespace entities {

struct EntityFactoryBase
{
  virtual Entity* create() = 0;
};

template <typename T>
struct EntityFactory : public EntityFactoryBase
{
  T* create()
  {
    return new T;
  }
};

} /* entities */
} /* model */

#endif /* end of include guard: __ENTITIES__ENTITYFACTORY_HPP__ */
