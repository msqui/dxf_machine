#ifndef __STATE__ENTITIES__CIRCLESTATE_H__
#define __STATE__ENTITIES__CIRCLESTATE_H__

#include "dxf_machine/state/entities/EntityState.h"

namespace dxf_machine { namespace state {

namespace entities {

class CircleState : public EntityState
{
public:
    void process(State::ProcPtrT proc, type::DxfTuplePtrT tuple_ptr);
};

}

}}

#endif // __STATE__ENTITIES__CIRCLESTATE_H__
