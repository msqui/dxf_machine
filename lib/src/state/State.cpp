#include "dxf_machine/state/State.h"

#include "dxf_machine/processor/StatefulProcessor.h"

namespace dxf_machine { namespace state {

State::~State()
{}

/**
 * Default process tuple realisation
**/
void State::process(type::DxfTuplePtrT, processor::StatefulProcessor*)
{}

void State::change_state(processor::StatefulProcessor* p, State* new_state)
{
  p->change_state(new_state);
}

}}
