#ifndef __STATE__STATE_H__
#define __STATE__STATE_H__

#include <map>

#include "type/types.hpp"

namespace dxf_machine {

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
  
  virtual void process(type::DxfTuplePtrT tuple_ptr, processor::StatefulProcessor* p) = 0;
  
protected:
  typedef std::map<type::DxfTupleT, State*> JumpMapT;
  typedef JumpMapT::const_iterator JumpIterT;
  
  void change_state(processor::StatefulProcessor* p, State* new_state);
  
  State() {}
};

}

}

#endif // __STATE__STATE_H__
