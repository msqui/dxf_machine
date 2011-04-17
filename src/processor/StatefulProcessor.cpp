#include "StatefulProcessor.h"

#include "state/State.h"

namespace processor {

StatefulProcessor::StatefulProcessor(state::State* state) :
  _current_state(state)
{}

void StatefulProcessor::process_tuple(type::DxfTuplePtrT tuple_ptr)
{
  _current_state->process(tuple_ptr);
}

void StatefulProcessor::change_state(state::State* new_state)
{
  _current_state = new_state;
}

} /* processor */