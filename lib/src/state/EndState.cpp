#include "EndState.h"

namespace dxf_machine { namespace state {

EndState::PtrT EndState::_instance = EndState::PtrT();

EndState* EndState::Instance()
{
  if (!_instance.get()) {
    _instance = EndState::PtrT(new EndState);
  }
  return _instance.get();
}

void EndState::process(type::DxfTuplePtrT tuple_ptr, processor::StatefulProcessor*)
{
  #ifdef DEBUG
    std::cout << "END state processes " << *tuple_ptr << std::endl;
  #endif
}

}}
