#ifndef __SECTIONS__HEADERSECTIONSTATE_H__
#define __SECTIONS__HEADERSECTIONSTATE_H__

#include "SectionState.h"

namespace state {
namespace sections {

class HeaderSectionState : public SectionState
{
public:
  static HeaderSectionState* Instance();
  
  void process(type::DxfTuplePtrT tuple_ptr, processor::StatefulProcessor* p);
  
private:
  static HeaderSectionState* _instance;
};

} /* sections */
} /* state */

#endif /* end of include guard: __SECTIONS__HEADERSECTIONSTATE_H__ */
