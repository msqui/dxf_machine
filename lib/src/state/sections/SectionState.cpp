#include "dxf_machine/state/sections/SectionState.h"

#include "dxf_machine/state/ReadyState.h"

#include "dxf_machine/state/sections/HeaderSectionState.h"
#include "dxf_machine/state/sections/EntitiesSectionState.h"

namespace dxf_machine { namespace state {

namespace sections {

State::JumpMapT
SectionState::_jump_map = {
    { type::DxfTupleT(2, "HEADER"),   State::Instance<HeaderSectionState>() },
    { type::DxfTupleT(2, "ENTITIES"), State::Instance<EntitiesSectionState>() },
    { type::DxfTupleT(0, "ENDSEC"),   State::Instance<ReadyState>() }
};

SectionState::~SectionState()
{}

void SectionState::process(State::ProcPtrT proc, type::DxfTuplePtrT tuple_ptr)
{
    // Select section to which send tuple
    State::JumpIterT map_it = _jump_map.find(*tuple_ptr);
    if (map_it != _jump_map.end()) {
        change_state(proc, map_it->second);
    } else {
        State::process(proc, tuple_ptr);
    }
}

}

}}
