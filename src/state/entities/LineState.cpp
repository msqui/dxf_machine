#include "LineState.h"

namespace state {
namespace entities {

LineState* LineState::_instance = NULL;

LineState* LineState::Instance()
{
  if (!_instance) {
    _instance = new LineState;
  }
  return _instance;
}

void LineState::process(type::DxfTuplePtrT tuple_ptr, processor::StatefulProcessor* p)
{
  switch (tuple_ptr->code()) {
    case 10:
      std::cout << "Line 10: " << tuple_ptr->value() << std::endl;
      break;
    case 20:
      std::cout << "Line 20: " << tuple_ptr->value() << std::endl;
      break;
    case 30:
      std::cout << "Line 30: " << tuple_ptr->value() << std::endl;
      break;
    case 11:
      std::cout << "Line 11: " << tuple_ptr->value() << std::endl;
      break;
    case 21:
      std::cout << "Line 21: " << tuple_ptr->value() << std::endl;
      break;
    case 31:
      std::cout << "Line 31: " << tuple_ptr->value() << std::endl;
      break;
    default:
      EntityState::process(tuple_ptr, p);
      break;
  }
}

} /* entities */
} /* state */