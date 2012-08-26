#ifndef __STATE__ENDSTATE_H__
#define __STATE__ENDSTATE_H__

#include "dxf_machine/state/State.h"

namespace dxf_machine { namespace state {

class EndState : public State
{
private:
    virtual void process(ProcPtrT proc, type::DxfTuplePtrT tuple_ptr);
};

}}

#endif // __STATE__ENDSTATE_H__
