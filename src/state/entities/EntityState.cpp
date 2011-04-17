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
  sections::EntitiesSectionState::process(tuple_ptr, p);
}

} /* entities */
} /* state */
