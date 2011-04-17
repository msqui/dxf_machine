#ifndef __STATE__STATE_H__
#define __STATE__STATE_H__

#include <type/types.hpp>

// ====================
// = Fwd declarations =
// ====================
namespace processor {
  
  class StatefulProcessor;
  
} /* processor */

namespace state {

class State
{
public:
  virtual ~State();
  
  virtual void process(type::DxfTuplePtrT tuple_ptr) = 0;
  
protected:
  void change_state(processor::StatefulProcessor* p, State* new_state);
};

} /* state */

#endif /* end of include guard: __STATE__STATE_H__ */
