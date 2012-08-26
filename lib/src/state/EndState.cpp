#include "dxf_machine/state/EndState.h"

namespace dxf_machine { namespace state {

void EndState::process(State::ProcPtrT proc, type::DxfTuplePtrT tuple_ptr)
{
    #ifdef DEBUG
        std::cout << "END state processes " << *tuple_ptr << std::endl;
    #endif
}

}}
