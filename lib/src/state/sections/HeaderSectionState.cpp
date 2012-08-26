#include "dxf_machine/state/sections/HeaderSectionState.h"

namespace dxf_machine { namespace state {

namespace sections {

void HeaderSectionState::process(State::ProcPtrT proc, type::DxfTuplePtrT tuple_ptr)
{
    SectionState::process(proc, tuple_ptr);
}

}

}}
