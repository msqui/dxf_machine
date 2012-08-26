#ifndef __STATE__READYSTATE_H__
#define __STATE__READYSTATE_H__

#include "dxf_machine/state/State.h"

namespace dxf_machine { namespace state {

class ReadyState : public State
{
public:
    virtual void process(ProcPtrT proc, type::DxfTuplePtrT tuple_ptr);
  
private:
    static State::JumpMapT _jump_map;
};

}}

#endif // __STATE__READYSTATE_H__
