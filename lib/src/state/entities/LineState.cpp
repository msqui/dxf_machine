#include "dxf_machine/state/entities/LineState.h"

#include <boost/lexical_cast.hpp>

#include "dxf_machine/model/entities/Line.h"

namespace dxf_machine { namespace state {
    
namespace entities {
  
  namespace me = model::entities;

// TODO add exception handling
void LineState::process(State::ProcPtrT proc, type::DxfTuplePtrT tuple_ptr)
{
  double value;
  switch (tuple_ptr->code()) {
    case 10:
      #ifdef DEBUG
        std::cout << "Line 10: " << tuple_ptr->value() << std::endl;
      #endif
      value = boost::lexical_cast<double>(tuple_ptr->value());
      if (me::Line* ptr = dynamic_cast<me::Line*>(current_entity(proc).get())) {
          ptr->start.x = value;
      } else { /* throw */ }
      break;
    case 20:
      #ifdef DEBUG
        std::cout << "Line 20: " << tuple_ptr->value() << std::endl;
      #endif
      value = boost::lexical_cast<double>(tuple_ptr->value());
      if (me::Line* ptr = dynamic_cast<me::Line*>(current_entity(proc).get())) {
          ptr->start.y = value;
      } else { /* throw */ }
      break;
    case 30:
      #ifdef DEBUG
        std::cout << "Line 30: " << tuple_ptr->value() << std::endl;
      #endif
      value = boost::lexical_cast<double>(tuple_ptr->value());
      if (me::Line* ptr = dynamic_cast<me::Line*>(current_entity(proc).get())) {
          ptr->start.z = value;
      } else { /* throw */ }
      break;
    case 11:
      #ifdef DEBUG
        std::cout << "Line 11: " << tuple_ptr->value() << std::endl;
      #endif
      value = boost::lexical_cast<double>(tuple_ptr->value());
      if (me::Line* ptr = dynamic_cast<me::Line*>(current_entity(proc).get())) {
          ptr->end.x = value;
      } else { /* throw */ }
      break;
    case 21:
      #ifdef DEBUG
        std::cout << "Line 21: " << tuple_ptr->value() << std::endl;
      #endif
      value = boost::lexical_cast<double>(tuple_ptr->value());
      if (me::Line* ptr = dynamic_cast<me::Line*>(current_entity(proc).get())) {
          ptr->end.y = value;
      } else { /* throw */ }
      break;
    case 31:
      #ifdef DEBUG
        std::cout << "Line 31: " << tuple_ptr->value() << std::endl;
      #endif
      value = boost::lexical_cast<double>(tuple_ptr->value());
      if (me::Line* ptr = dynamic_cast<me::Line*>(current_entity(proc).get())) {
          ptr->end.z = value;
      } else { /* throw */ }
      break;
    default:
      EntityState::process(proc, tuple_ptr);
      break;
  }
}

}

}}
