#include "EntitiesSectionState.h"

#include "processor/StatefulProcessor.h"

#include "state/entities/CircleState.h"
#include "state/entities/LineState.h"
#include "state/entities/LwPolylineState.h"

#include "model/entities/Circle.h"
#include "model/entities/Line.h"
#include "model/entities/LwPolyline.h"

#include <boost/assign.hpp>

namespace state {
namespace sections {

  namespace me = model::entities;
  namespace se = state::entities;

EntitiesSectionState::PtrT EntitiesSectionState::_instance = EntitiesSectionState::PtrT();

EntitiesSectionState::EntJumpMapT
EntitiesSectionState::_jump_map = boost::assign::map_list_of<type::DxfTupleT, std::pair<State*, me::EntityFactoryBase*> >
  (type::DxfTupleT(0, "CIRCLE"),
      std::make_pair<State*, me::EntityFactoryBase*>(
        se::CircleState::Instance(),
        new me::EntityFactory<me::Circle>)
  )
  (type::DxfTupleT(0, "LINE"),
      std::make_pair<State*, me::EntityFactoryBase*>(
        se::LineState::Instance(),
        new me::EntityFactory<me::Line>)
  )
  (type::DxfTupleT(0, "LWPOLYLINE"),
      std::make_pair<State*, me::EntityFactoryBase*>(
        se::LwPolylineState::Instance(),
        new me::EntityFactory<me::LwPolyline>)
  )
  ;

EntitiesSectionState::~EntitiesSectionState()
{}

EntitiesSectionState* EntitiesSectionState::Instance()
{
  if (!_instance.get()) {
    _instance = EntitiesSectionState::PtrT(new EntitiesSectionState);
  }
  return _instance.get();
}

void EntitiesSectionState::process(type::DxfTuplePtrT tuple_ptr, processor::StatefulProcessor* p)
{
  EntitiesSectionState::EntJumpIterT map_it = _jump_map.find(*tuple_ptr);
  if (map_it != _jump_map.end()) {
    change_state(p, map_it->second.first);
    p->add_entity(map_it->second.second->create());
  } else {
    SectionState::process(tuple_ptr, p);
  }
}

} /* sections */
} /* state */