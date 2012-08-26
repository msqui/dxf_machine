#include "dxf_machine/state/sections/EntitiesSectionState.h"

#include "dxf_machine/state/entities/CircleState.h"
#include "dxf_machine/state/entities/LineState.h"
#include "dxf_machine/state/entities/LwPolylineState.h"

#include "dxf_machine/model/entities/Circle.h"
#include "dxf_machine/model/entities/Line.h"
#include "dxf_machine/model/entities/LwPolyline.h"

namespace dxf_machine { namespace state {

namespace sections {

  namespace se = state::entities;

EntitiesSectionState::EntJumpMapT
EntitiesSectionState::_jump_map = {
    { type::DxfTupleT(0, "CIRCLE"),
        std::make_pair<State::PtrT, me::FactoryPtrT >(
                State::Instance<se::CircleState>(),
                me::EntityFactory<me::Circle>::Instance() )
    },
    { type::DxfTupleT(0, "LINE"),
        std::make_pair<State::PtrT, me::FactoryPtrT >(
                State::Instance<se::LineState>(),
                me::EntityFactory<me::Line>::Instance() )
    },
    { type::DxfTupleT(0, "LWPOLYLINE"),
        std::make_pair<State::PtrT, me::FactoryPtrT >(
                State::Instance<se::LwPolylineState>(),
                me::EntityFactory<me::LwPolyline>::Instance() )
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
