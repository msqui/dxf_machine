#ifndef __ENTITIES__ENTITYSTATE_H__
#define __ENTITIES__ENTITYSTATE_H__

#include "state/sections/EntitiesSectionState.h"

namespace state {
namespace entities {
/**
 * ABC of Entities
**/
class EntityState : public sections::EntitiesSectionState
{
public:
  virtual ~EntityState();
  
  virtual void process(type::DxfTuplePtrT tuple_ptr, processor::StatefulProcessor* p) = 0;
};

} /* entities */
} /* state */

#endif /* end of include guard: __ENTITIES__ENTITYSTATE_H__ */
