#include "LwPolylineState.h"

namespace state {
namespace entities {

LwPolylineState* LwPolylineState::_instance = NULL;

LwPolylineState* LwPolylineState::Instance()
{
  if (!_instance) {
    _instance = new LwPolylineState;
  }
  return _instance;
}

void LwPolylineState::process(type::DxfTuplePtrT tuple_ptr, processor::StatefulProcessor* p)
{
  switch (tuple_ptr->code()) {
    case 10:
      std::cout << "LwPolyline 10: " << tuple_ptr->value() << std::endl;
      break;
    case 20:
      std::cout << "LwPolyline 20: " << tuple_ptr->value() << std::endl;
      break;
    default:
      EntityState::process(tuple_ptr, p);
      break;
  }
}

} /* entities */
} /* state */