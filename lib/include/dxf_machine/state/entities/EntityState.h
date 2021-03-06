#ifndef __STATE_ENTITIES__ENTITYSTATE_H__
#define __STATE_ENTITIES__ENTITYSTATE_H__

#include "dxf_machine/state/sections/EntitiesSectionState.h"

namespace dxf_machine { namespace state {
    
namespace entities {

/**
 * ABC of Entities
**/
class EntityState : public sections::EntitiesSectionState
{
public:
  virtual ~EntityState();
  
  virtual void process(State::ProcPtrT proc, type::DxfTuplePtrT tuple_ptr) = 0;
};

}

}}

#endif // __STATE_ENTITIES__ENTITYSTATE_H__
