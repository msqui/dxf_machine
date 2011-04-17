#include "State.h"

#include "processor/StatefulProcessor.h"

namespace state {

State::~State()
{
  std::cout << "State destructed" << std::endl;
}

/**
 * Default process tuple realisation
**/
void State::process(type::DxfTuplePtrT tuple_ptr, processor::StatefulProcessor*)
{
  #ifdef DEBUG
    // std::cout << *tuple_ptr << " is not processed" << std::endl;
  #endif
}

void State::change_state(processor::StatefulProcessor* p, State* new_state)
{
  p->change_state(new_state);
}

} /* state */