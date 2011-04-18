#include "CircleState.h"

#include <boost/lexical_cast.hpp>

#include "processor/StatefulProcessor.h"

#include "model/entities/Circle.h"

namespace state {
namespace entities {
  
  namespace me = model::entities;

CircleState::PtrT CircleState::_instance = CircleState::PtrT();

CircleState* CircleState::Instance()
{
  if (!_instance.get()) {
    _instance = CircleState::PtrT(new CircleState);
  }
  return _instance.get();
}

// TODO add exception handling
void CircleState::process(type::DxfTuplePtrT tuple_ptr, processor::StatefulProcessor* p)
{
  double value;
  switch (tuple_ptr->code()) {
    case 10:
      #ifdef DEBUG
        std::cout << "Circle 10: " << tuple_ptr->value() << std::endl;
      #endif
      value = boost::lexical_cast<double>(tuple_ptr->value());
      dynamic_cast<me::Circle&>(p->current_entity()).center.x = value;
      break;
    case 20:
      #ifdef DEBUG
        std::cout << "Circle 20: " << tuple_ptr->value() << std::endl;
      #endif
      value = boost::lexical_cast<double>(tuple_ptr->value());
      dynamic_cast<me::Circle&>(p->current_entity()).center.y = value;
      break;
    case 30:
      #ifdef DEBUG
        std::cout << "Circle 30: " << tuple_ptr->value() << std::endl;
      #endif
      value = boost::lexical_cast<double>(tuple_ptr->value());
      dynamic_cast<me::Circle&>(p->current_entity()).center.z = value;
      break;
    case 40:
      #ifdef DEBUG
        std::cout << "Circle 40: " << tuple_ptr->value() << std::endl;
      #endif
      value = boost::lexical_cast<double>(tuple_ptr->value());
      dynamic_cast<me::Circle&>(p->current_entity()).radius = value;
      break;
    default:
      EntityState::process(tuple_ptr, p);
      break;
  }
}

} /* entities */
} /* state */
