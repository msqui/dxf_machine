#include "dxf_machine/state/ReadyState.h"
#include "dxf_machine/state/EndState.h"
#include "dxf_machine/state/sections/SectionState.h"

namespace dxf_machine { namespace state {

State::JumpMapT
ReadyState::_jump_map = {
    { type::DxfTupleT(0, "SECTION"),    State::Instance<sections::SectionState>() },
    { type::DxfTupleT(0, "EOF"),        State::Instance<EndState>() }
};

void ReadyState::process(State::ProcPtrT proc, type::DxfTuplePtrT tuple_ptr)
{
    State::JumpIterT map_it = _jump_map.find(*tuple_ptr);
    if (map_it != _jump_map.end()) {
        change_state(proc, map_it->second);
    } else {
        #ifdef DEBUG
            std::cout << "Don't know how to process " << *tuple_ptr << std::endl;
        #endif
    }
}

}}
