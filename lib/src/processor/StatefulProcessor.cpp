#include "dxf_machine/processor/StatefulProcessor.h"

// #include "dxf_machine/state/State.h"
#include "dxf_machine/state/ReadyState.h"
#include "dxf_machine/exception/state/bad_state.h"
#include "dxf_machine/util/Messages.h"

namespace dxf_machine { namespace processor {

StatefulProcessor::PtrT
StatefulProcessor::Instance(StatefulProcessor::StatePtrT state)
{
    return StatefulProcessor::PtrT(new StatefulProcessor(state));
}

StatefulProcessor::StatefulProcessor(StatePtrT state)
{
    if (state) {
        _current_state = state;
    } else {
        _current_state = state::State::Instance<state::ReadyState>();
    }
}

void StatefulProcessor::process_tuple(type::DxfTuplePtrT tuple_ptr)
{
    _current_state->process(shared_from_this(), tuple_ptr);
}

void StatefulProcessor::add_entity(model::entities::Entity::PtrT ent)
{
    _model_ptr->entities->push_back(ent);
}

model::entities::Entity::PtrT
StatefulProcessor::current_entity()
{
    return _model_ptr->entities->back();
}

void StatefulProcessor::change_state(state::State::PtrT new_state)
{
    if (!new_state) {
        throw exception::state::bad_state(util::Messages::PROCESSOR_NULL_STATE);
    }
    _current_state = new_state;
}

}}
