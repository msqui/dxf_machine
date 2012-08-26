#ifndef __STATE__SECTIONS__HEADERSECTIONSTATE_H__
#define __STATE__SECTIONS__HEADERSECTIONSTATE_H__

#include "dxf_machine/state/sections/SectionState.h"

namespace dxf_machine { namespace state {
namespace sections {

class HeaderSectionState : public SectionState
{
public:
    void process(State::ProcPtrT proc, type::DxfTuplePtrT tuple_ptr);
};

}

}}

#endif // __STATE__SECTIONS__HEADERSECTIONSTATE_H__
