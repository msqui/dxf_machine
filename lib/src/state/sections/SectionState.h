#ifndef __SECTIONS__SECTIONSTATE_H__
#define __SECTIONS__SECTIONSTATE_H__

#include "state/State.h"

#include <memory>

namespace state {
namespace sections {

class SectionState : public state::State
{
public:
  virtual ~SectionState();
  
  static SectionState* Instance();
  
  virtual void process(type::DxfTuplePtrT tuple_ptr, processor::StatefulProcessor* p);
  
private:
  typedef std::auto_ptr<SectionState> PtrT;
  static PtrT _instance;
  static State::JumpMapT _jump_map;
};

} /* sections */
} /* state */

#endif /* end of include guard: __SECTIONS__SECTIONSTATE_H__ */
