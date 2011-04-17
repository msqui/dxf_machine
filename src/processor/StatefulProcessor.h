#ifndef __PROCESSOR__STATEFULPROCESSOR_H__
#define __PROCESSOR__STATEFULPROCESSOR_H__

#include "Processor.h"

// ====================
// = Fwd declarations =
// ====================
namespace state {

  class State;

} /* state */

namespace processor {

class StatefulProcessor : public Processor
{
public:
  explicit StatefulProcessor(state::State* state = NULL);
  
  void process_tuple(type::DxfTuplePtrT tuple_ptr);
  
private:
  state::State* _current_state;
  
  friend class state::State;
  void change_state(state::State* new_state);
};

} /* processor */

#endif /* end of include guard: __PROCESSOR__STATEFULPROCESSOR_H__ */
