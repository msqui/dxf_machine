#ifndef __STATE__ENDSTATE_H__
#define __STATE__ENDSTATE_H__

#include "State.h"

#include <memory>

namespace state {

class EndState : public State
{
public:
  static EndState* Instance();
  
  virtual void process(type::DxfTuplePtrT tuple_ptr, processor::StatefulProcessor*);
  
private:
  typedef std::auto_ptr<EndState> PtrT;
  
  static PtrT _instance;
};

} /* state */

#endif /* end of include guard: __STATE__ENDSTATE_H__ */