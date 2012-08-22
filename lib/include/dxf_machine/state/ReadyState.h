#ifndef __STATE__READYSTATE_H__
#define __STATE__READYSTATE_H__

#include "dxf_machine/state/State.h"

#include <memory>

namespace dxf_machine { namespace state {

class ReadyState : public State
{
public:
  static ReadyState* Instance();
  
  virtual void process(type::DxfTuplePtrT tuple_ptr, processor::StatefulProcessor* p);
  
private:
  typedef std::auto_ptr<ReadyState> PtrT;
  
  static PtrT _instance;
  
  static State::JumpMapT _jump_map;
};

}}

#endif // __STATE__READYSTATE_H__
