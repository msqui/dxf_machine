#include "StatefulProcessor.h"

// #include "state/State.h"
#include "state/ReadyState.h"
#include "exception/state/bad_state.h"

namespace processor {

StatefulProcessor::StatefulProcessor(state::State* state)
{
  if (state) {
    _current_state = state;
  } else {
    _current_state = state::ReadyState::Instance();
  }
}

void StatefulProcessor::process_tuple(type::DxfTuplePtrT tuple_ptr)
{
  _current_state->process(tuple_ptr, this);
}

void StatefulProcessor::change_state(state::State* new_state)
{
  if (!new_state) {
    throw exception::state::bad_state("state is null");
  }
  _current_state = new_state;
}

} /* processor */