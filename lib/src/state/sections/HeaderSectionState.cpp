#include "HeaderSectionState.h"

namespace state {
namespace sections {

HeaderSectionState::PtrT HeaderSectionState::_instance = HeaderSectionState::PtrT();

HeaderSectionState* HeaderSectionState::Instance()
{
  if (!_instance.get()) {
    _instance = HeaderSectionState::PtrT(new HeaderSectionState);
  }
  return _instance.get();
}

void HeaderSectionState::process(type::DxfTuplePtrT tuple_ptr, processor::StatefulProcessor* p)
{
  SectionState::process(tuple_ptr, p);
}

} /* sections */
} /* state */