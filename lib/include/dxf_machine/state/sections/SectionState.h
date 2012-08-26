#ifndef __STATE__SECTIONS__SECTIONSTATE_H__
#define __STATE__SECTIONS__SECTIONSTATE_H__

#include "dxf_machine/state/State.h"

namespace dxf_machine { namespace state {

namespace sections {

class SectionState : public state::State
{
public:
    virtual ~SectionState();
    
    virtual void process(State::ProcPtrT proc, type::DxfTuplePtrT tuple_ptr);
    
private:
    static State::JumpMapT _jump_map;
};

}

}}

#endif // __STATE__SECTIONS__SECTIONSTATE_H__
