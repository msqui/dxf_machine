#include "EntityState.h"

namespace state {
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
      // Layer name
      std::cout << "Layer name: " << tuple_ptr->value() << std::endl;
      break;
    default:
      sections::EntitiesSectionState::process(tuple_ptr, p);
      break;
  }
}

} /* entities */
} /* state */
