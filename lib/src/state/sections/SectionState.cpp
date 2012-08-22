#include "SectionState.h"

#include "state/ReadyState.h"

#include "HeaderSectionState.h"
#include "EntitiesSectionState.h"

#include <boost/assign.hpp>

namespace dxf_machine { namespace state {

namespace sections {

SectionState::PtrT SectionState::_instance = SectionState::PtrT();

State::JumpMapT
SectionState::_jump_map = boost::assign::map_list_of<type::DxfTupleT, state::State*>
  (type::DxfTupleT(2, "HEADER"), HeaderSectionState::Instance())
  (type::DxfTupleT(2, "ENTITIES"), EntitiesSectionState::Instance())
  (type::DxfTupleT(0, "ENDSEC"), ReadyState::Instance())
  ;

SectionState::~SectionState()
{}

SectionState* SectionState::Instance()
{
  if (!_instance.get()) {
    _instance = SectionState::PtrT(new SectionState);
  }
  return _instance.get();
}

void SectionState::process(type::DxfTuplePtrT tuple_ptr, processor::StatefulProcessor* p)
{
  // Select section to which send tuple
  State::JumpIterT map_it = _jump_map.find(*tuple_ptr);
  if (map_it != _jump_map.end()) {
    change_state(p, map_it->second);
  } else {
    State::process(tuple_ptr, p);
  }
}

}

}}
