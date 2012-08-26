#include "dxf_machine/state/State.h"

#include "dxf_machine/processor/StatefulProcessor.h"

namespace dxf_machine { namespace state {

State::State()
{}

State::~State()
{}

/**
 * Default process tuple realisation
**/
void State::process(State::ProcPtrT, type::DxfTuplePtrT)
{}

void State::change_state(State::ProcPtrT proc, State::PtrT new_state)
{
    proc->change_state(new_state);
}

model::entities::Entity::PtrT
State::current_entity(State::ProcPtrT proc)
{
    return proc->current_entity();
}

void State::add_entity(ProcPtrT proc, model::entities::Entity::PtrT ent)
{
    proc->add_entity(ent);
}

}}
