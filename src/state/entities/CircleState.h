#ifndef __ENTITIES__CIRCLESTATE_H__
#define __ENTITIES__CIRCLESTATE_H__

#include "EntityState.h"

namespace state {
namespace entities {

class CircleState : public EntityState
{
public:
  static CircleState* Instance();
  
  void process(type::DxfTuplePtrT tuple_ptr, processor::StatefulProcessor* p);
  
private:
  static CircleState* _instance;
};

} /* entities */
} /* state */

#endif /* end of include guard: __ENTITIES__CIRCLESTATE_H__ */
