#include "LineState.h"

#include <boost/lexical_cast.hpp>

#include "processor/StatefulProcessor.h"

#include "model/entities/Line.h"

namespace state {
namespace entities {
  
  namespace me = model::entities;

LineState::PtrT LineState::_instance = LineState::PtrT();

LineState* LineState::Instance()
{
  if (!_instance.get()) {
    _instance = LineState::PtrT(new LineState);
  }
  return _instance.get();
}

// TODO add exception handling
void LineState::process(type::DxfTuplePtrT tuple_ptr, processor::StatefulProcessor* p)
{
  double value;
  switch (tuple_ptr->code()) {
    case 10:
      #ifdef DEBUG
        std::cout << "Line 10: " << tuple_ptr->value() << std::endl;
      #endif
      value = boost::lexical_cast<double>(tuple_ptr->value());
      dynamic_cast<me::Line&>(p->current_entity()).start.x = value;
      break;
    case 20:
      #ifdef DEBUG
        std::cout << "Line 20: " << tuple_ptr->value() << std::endl;
      #endif
      value = boost::lexical_cast<double>(tuple_ptr->value());
      dynamic_cast<me::Line&>(p->current_entity()).start.y = value;
      break;
    case 30:
      #ifdef DEBUG
        std::cout << "Line 30: " << tuple_ptr->value() << std::endl;
      #endif
      value = boost::lexical_cast<double>(tuple_ptr->value());
      dynamic_cast<me::Line&>(p->current_entity()).start.z = value;
      break;
    case 11:
      #ifdef DEBUG
        std::cout << "Line 11: " << tuple_ptr->value() << std::endl;
      #endif
      value = boost::lexical_cast<double>(tuple_ptr->value());
      dynamic_cast<me::Line&>(p->current_entity()).end.x = value;
      break;
    case 21:
      #ifdef DEBUG
        std::cout << "Line 21: " << tuple_ptr->value() << std::endl;
      #endif
      value = boost::lexical_cast<double>(tuple_ptr->value());
      dynamic_cast<me::Line&>(p->current_entity()).end.y = value;
      break;
    case 31:
      #ifdef DEBUG
        std::cout << "Line 31: " << tuple_ptr->value() << std::endl;
      #endif
      value = boost::lexical_cast<double>(tuple_ptr->value());
      dynamic_cast<me::Line&>(p->current_entity()).end.z = value;
      break;
    default:
      EntityState::process(tuple_ptr, p);
      break;
  }
}

} /* entities */
} /* state */
