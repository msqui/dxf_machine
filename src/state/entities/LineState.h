#ifndef __ENTITIES__LINESTATE_H__
#define __ENTITIES__LINESTATE_H__

#include "EntityState.h"

namespace state {
namespace entities {

class LineState : public EntityState
{
public:
  static LineState* Instance();
  
  void process(type::DxfTuplePtrT tuple_ptr, processor::StatefulProcessor* p);
  
private:
  static LineState* _instance;
};

} /* entities */
} /* state */

#endif /* end of include guard: __ENTITIES__LINESTATE_H__ */
