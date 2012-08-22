#ifndef __STATE__SECTIONS__HEADERSECTIONSTATE_H__
#define __STATE__SECTIONS__HEADERSECTIONSTATE_H__

#include "dxf_machine/state/sections/SectionState.h"

#include <memory>

namespace dxf_machine { namespace state {
namespace sections {

class HeaderSectionState : public SectionState
{
public:
  static HeaderSectionState* Instance();
  
  void process(type::DxfTuplePtrT tuple_ptr, processor::StatefulProcessor* p);
  
private:
  typedef std::auto_ptr<HeaderSectionState> PtrT;
  static PtrT _instance;
};

}

}}

#endif // __STATE__SECTIONS__HEADERSECTIONSTATE_H__
