#ifndef __STATE__ENTITIES__CIRCLESTATE_H__
#define __STATE__ENTITIES__CIRCLESTATE_H__

#include "dxf_machine/state/entities/EntityState.h"

#include <memory>

namespace dxf_machine { namespace state {

namespace entities {

class CircleState : public EntityState
{
public:
  static CircleState* Instance();
  
  void process(type::DxfTuplePtrT tuple_ptr, processor::StatefulProcessor* p);
  
private:
  typedef std::auto_ptr<CircleState> PtrT;
  
  static PtrT _instance;
};

}

}}

#endif // __STATE__ENTITIES__CIRCLESTATE_H__
