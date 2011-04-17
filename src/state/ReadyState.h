#ifndef __STATE__READYSTATE_H__
#define __STATE__READYSTATE_H__

#include "State.h"

#include <memory>

namespace state {

class ReadyState : public State
{
public:
  static ReadyState* Instance();
  
  virtual void process(type::DxfTuplePtrT tuple_ptr, processor::StatefulProcessor* p);
  
private:
  static std::auto_ptr<ReadyState> _instance;
  
  static State::JumpMapT _jump_map;
};

} /* state */

#endif /* end of include guard: __STATE__READYSTATE_H__ */
