#ifndef __STATE__ENDSTATE_H__
#define __STATE__ENDSTATE_H__

#include "State.h"

namespace state {

class EndState : public State
{
public:
  static EndState* Instance();
  
  virtual void process(type::DxfTuplePtrT tuple_ptr, processor::StatefulProcessor*);
  
private:
  static EndState* _instance;
};

} /* state */

#endif /* end of include guard: __STATE__ENDSTATE_H__ */
