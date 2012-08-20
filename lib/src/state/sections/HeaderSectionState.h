#ifndef __SECTIONS__HEADERSECTIONSTATE_H__
#define __SECTIONS__HEADERSECTIONSTATE_H__

#include "SectionState.h"

#include <memory>

namespace state {
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

} /* sections */
} /* state */

#endif /* end of include guard: __SECTIONS__HEADERSECTIONSTATE_H__ */
