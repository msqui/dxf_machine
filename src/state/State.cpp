#include "State.h"

#include <processor/StatefulProcessor.h>

namespace state {

void State::change_state(processor::StatefulProcessor* p, State* new_state)
{
  p->change_state(new_state);
}

} /* state */