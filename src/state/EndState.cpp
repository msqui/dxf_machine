#include "EndState.h"

namespace state {

EndState* EndState::_instance = NULL;

EndState* EndState::Instance()
{
  if (!_instance) {
    _instance = new EndState;
  }
  return _instance;
}

void EndState::process(type::DxfTuplePtrT tuple_ptr, processor::StatefulProcessor*)
{
  #ifdef DEBUG
    std::cout << "END state processes " << *tuple_ptr << std::endl;
  #endif
}

} /* state */