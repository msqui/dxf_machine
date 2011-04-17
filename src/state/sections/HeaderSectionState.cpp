#include "HeaderSectionState.h"

namespace state {
namespace sections {

HeaderSectionState* HeaderSectionState::_instance = NULL;

HeaderSectionState* HeaderSectionState::Instance()
{
  if (!_instance) {
    _instance = new HeaderSectionState;
  }
  return _instance;
}

void HeaderSectionState::process(type::DxfTuplePtrT tuple_ptr, processor::StatefulProcessor* p)
{
  SectionState::process(tuple_ptr, p);
}

} /* sections */
} /* state */
