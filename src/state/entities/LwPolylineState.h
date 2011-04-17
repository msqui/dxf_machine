#ifndef __ENTITIES__LWPOLYLINESTATE_H__
#define __ENTITIES__LWPOLYLINESTATE_H__

#include "EntityState.h"

namespace state {
namespace entities {

class LwPolylineState : public EntityState
{
public:
  static LwPolylineState* Instance();
  
  void process(type::DxfTuplePtrT tuple_ptr, processor::StatefulProcessor* p);
  
private:
  static LwPolylineState* _instance;
};

} /* entities */
} /* state */

#endif /* end of include guard: __ENTITIES__LWPOLYLINESTATE_H__ */
