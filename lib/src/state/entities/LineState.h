#ifndef __STATE_ENTITIES__LINESTATE_H__
#define __STATE_ENTITIES__LINESTATE_H__

#include "EntityState.h"

#include <memory>

namespace dxf_machine { namespace state {

namespace entities {

class LineState : public EntityState
{
public:
  static LineState* Instance();
  
  void process(type::DxfTuplePtrT tuple_ptr, processor::StatefulProcessor* p);
  
private:
  typedef std::auto_ptr<LineState> PtrT;
  
  static PtrT _instance;
};

}

}}

#endif // __STATE_ENTITIES__LINESTATE_H__
