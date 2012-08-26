#ifndef __STATE_ENTITIES__LINESTATE_H__
#define __STATE_ENTITIES__LINESTATE_H__

#include "dxf_machine/state/entities/EntityState.h"

namespace dxf_machine { namespace state {

namespace entities {

class LineState : public EntityState
{
public:
    void process(State::ProcPtrT proc, type::DxfTuplePtrT tuple_ptr);
};

}

}}

#endif // __STATE_ENTITIES__LINESTATE_H__
