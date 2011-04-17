#ifndef __SECTIONS__ENTITIESSECTIONSTATE_H__
#define __SECTIONS__ENTITIESSECTIONSTATE_H__

#include "SectionState.h"

namespace state {
namespace sections {

class EntitiesSectionState : public SectionState
{
public:
  static EntitiesSectionState* Instance();
  
  void process(type::DxfTuplePtrT tuple_ptr, processor::StatefulProcessor* p);
  
private:
  static EntitiesSectionState* _instance;
  static State::JumpMapT _jump_map;
};

} /* sections */
} /* state */

#endif /* end of include guard: __SECTIONS__ENTITIESSECTIONSTATE_H__ */
