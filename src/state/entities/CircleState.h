#ifndef __ENTITIES__CIRCLESTATE_H__
#define __ENTITIES__CIRCLESTATE_H__

#include "EntityState.h"

#include <memory>

namespace state {
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

} /* entities */
} /* state */

#endif /* end of include guard: __ENTITIES__CIRCLESTATE_H__ */
