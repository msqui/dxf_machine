#include "dxf_machine/state/entities/EntityState.h"

namespace dxf_machine { namespace state {

namespace entities {

EntityState::~EntityState()
{}

/**
 * Default process tuple realisation
**/
void EntityState::process(type::DxfTuplePtrT tuple_ptr, processor::StatefulProcessor* p)
{
  switch (tuple_ptr->code()) {
    case 8:
      #ifdef DEBUG
        std::cout << "Layer name: " << tuple_ptr->value() << std::endl;
      #endif
      break;
    default:
      sections::EntitiesSectionState::process(tuple_ptr, p);
      break;
  }
}

}

}}
