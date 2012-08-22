#include "dxf_machine/processor/StatefulProcessor.h"

// #include "dxf_machine/state/State.h"
#include "dxf_machine/state/ReadyState.h"
#include "dxf_machine/exception/state/bad_state.h"
#include "dxf_machine/util/Messages.h"

namespace dxf_machine { namespace processor {

StatefulProcessor::StatefulProcessor(state::State* state) :
    _model_ptr(std::auto_ptr<model::Model>(new model::Model))
{
    if (state) {
        _current_state = state;
    } else {
        _current_state = state::ReadyState::Instance();
    }
}

void StatefulProcessor::process_tuple(type::DxfTuplePtrT tuple_ptr)
{
    assert(_model_ptr.get() != NULL);
    _current_state->process(tuple_ptr, this);
}

void StatefulProcessor::add_entity(model::entities::Entity* ent)
{
    _model_ptr->entities()->push_back(ent);
}

model::entities::Entity& StatefulProcessor::current_entity()
{
    return _model_ptr->entities()->back();
}

model::Model* StatefulProcessor::get_model()
{
    assert(_model_ptr.get() != NULL);
    return _model_ptr.release();
}

void StatefulProcessor::change_state(state::State* new_state)
{
    if (!new_state) {
        throw exception::state::bad_state(util::Messages::PROCESSOR_NULL_STATE);
    }
    _current_state = new_state;
}

}}
