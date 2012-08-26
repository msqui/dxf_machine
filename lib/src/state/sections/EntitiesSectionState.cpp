#include "dxf_machine/state/sections/EntitiesSectionState.h"

#include "dxf_machine/state/entities/CircleState.h"
#include "dxf_machine/state/entities/LineState.h"
#include "dxf_machine/state/entities/LwPolylineState.h"

#include "dxf_machine/model/entities/Circle.h"
#include "dxf_machine/model/entities/Line.h"
#include "dxf_machine/model/entities/LwPolyline.h"

namespace dxf_machine { namespace state {

namespace sections {

  namespace me = model::entities;
  namespace se = state::entities;

EntitiesSectionState::EntJumpMapT
EntitiesSectionState::_jump_map = {
    { type::DxfTupleT(0, "CIRCLE"),
        std::make_pair<State::PtrT, me::EntityFactoryBase*>(
                State::Instance<se::CircleState>(),
                new me::EntityFactory<me::Circle>)
    },
    { type::DxfTupleT(0, "LINE"),
        std::make_pair<State::PtrT, me::EntityFactoryBase*>(
                State::Instance<se::LineState>(),
                new me::EntityFactory<me::Line>)
    },
    { type::DxfTupleT(0, "LWPOLYLINE"),
        std::make_pair<State::PtrT, me::EntityFactoryBase*>(
                State::Instance<se::LwPolylineState>(),
                new me::EntityFactory<me::LwPolyline>)
    }
};

EntitiesSectionState::~EntitiesSectionState()
{}

void EntitiesSectionState::process(State::ProcPtrT proc, type::DxfTuplePtrT tuple_ptr)
{
    EntitiesSectionState::EntJumpIterT map_it = _jump_map.find(*tuple_ptr);
    if (map_it != _jump_map.end()) {
        change_state(proc, map_it->second.first);
        add_entity(proc, map_it->second.second->create());
    } else {
        SectionState::process(proc, tuple_ptr);
    }
}

}

}}
