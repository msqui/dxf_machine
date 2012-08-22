#include "dxf_machine/state/ReadyState.h"
#include "dxf_machine/state/EndState.h"
#include "dxf_machine/state/sections/SectionState.h"

#include <boost/assign.hpp>

namespace dxf_machine { namespace state {

ReadyState::PtrT ReadyState::_instance = ReadyState::PtrT();

State::JumpMapT
ReadyState::_jump_map = boost::assign::map_list_of<type::DxfTupleT, state::State*>
  (type::DxfTupleT(0, "SECTION"), sections::SectionState::Instance())
  (type::DxfTupleT(0, "EOF"), EndState::Instance())
  ;

ReadyState* ReadyState::Instance()
{
  if (!_instance.get()) {
    _instance = ReadyState::PtrT(new ReadyState);
  }
  return _instance.get();
}

void ReadyState::process(type::DxfTuplePtrT tuple_ptr, processor::StatefulProcessor* p)
{
  State::JumpIterT map_it = _jump_map.find(*tuple_ptr);
  if (map_it != _jump_map.end()) {
    change_state(p, map_it->second);
  } else {
    #ifdef DEBUG
      std::cout << "Don't know how to process " << *tuple_ptr << std::endl;
    #endif
  }
}

}}
