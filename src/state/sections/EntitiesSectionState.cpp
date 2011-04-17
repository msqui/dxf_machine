#include "EntitiesSectionState.h"

#include "state/entities/CircleState.h"
#include "state/entities/LineState.h"
#include "state/entities/LwPolylineState.h"

#include <boost/assign.hpp>

namespace state {
namespace sections {

EntitiesSectionState::PtrT EntitiesSectionState::_instance = EntitiesSectionState::PtrT();

State::JumpMapT
EntitiesSectionState::_jump_map = boost::assign::map_list_of<type::DxfTupleT, state::State*>
  (type::DxfTupleT(0, "CIRCLE"),      state::entities::CircleState::Instance())
  (type::DxfTupleT(0, "LINE"),        state::entities::LineState::Instance())
  (type::DxfTupleT(0, "LWPOLYLINE"),  state::entities::LwPolylineState::Instance())
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
  State::JumpIterT map_it = _jump_map.find(*tuple_ptr);
  if (map_it != _jump_map.end()) {
    change_state(p, map_it->second);
  } else {
    SectionState::process(tuple_ptr, p);
  }
}

} /* sections */
} /* state */