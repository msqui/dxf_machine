#include "CircleState.h"

namespace state {
namespace entities {

CircleState::PtrT CircleState::_instance = CircleState::PtrT();

CircleState* CircleState::Instance()
{
  if (!_instance.get()) {
    _instance = CircleState::PtrT(new CircleState);
  }
  return _instance.get();
}

void CircleState::process(type::DxfTuplePtrT tuple_ptr, processor::StatefulProcessor* p)
{
  switch (tuple_ptr->code()) {
    case 10:
      std::cout << "Circle 10: " << tuple_ptr->value() << std::endl;
      break;
    case 20:
      std::cout << "Circle 20: " << tuple_ptr->value() << std::endl;
      break;
    case 30:
      std::cout << "Circle 30: " << tuple_ptr->value() << std::endl;
      break;
    case 40:
      std::cout << "Circle 40: " << tuple_ptr->value() << std::endl;
      break;
    default:
      EntityState::process(tuple_ptr, p);
      break;
  }
}

} /* entities */
} /* state */