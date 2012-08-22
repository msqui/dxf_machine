#ifndef __STATE__ENTITIES__LWPOLYLINESTATE_H__
#define __STATE__ENTITIES__LWPOLYLINESTATE_H__

#include "dxf_machine/state/entities/EntityState.h"

#include <memory>

namespace dxf_machine { namespace state {

namespace entities {

class LwPolylineState : public EntityState
{
public:
  static LwPolylineState* Instance();
  
  void process(type::DxfTuplePtrT tuple_ptr, processor::StatefulProcessor* p);
  
private:
  typedef std::auto_ptr<LwPolylineState> PtrT;
  
  static PtrT _instance;
};

}

}}

#endif // __STATE__ENTITIES__LWPOLYLINESTATE_H__
