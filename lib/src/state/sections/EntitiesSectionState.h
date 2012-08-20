#ifndef __SECTIONS__ENTITIESSECTIONSTATE_H__
#define __SECTIONS__ENTITIESSECTIONSTATE_H__

#include "SectionState.h"

#include <memory>

#include "model/entities/Entity.h"
#include "model/entities/EntityFactory.hpp"

namespace state {
namespace sections {

class EntitiesSectionState : public SectionState
{
public:
  virtual ~EntitiesSectionState();
  
  static EntitiesSectionState* Instance();
  
  void process(type::DxfTuplePtrT tuple_ptr, processor::StatefulProcessor* p);
  
private:
  typedef std::auto_ptr<EntitiesSectionState> PtrT;
  static PtrT _instance;
  
  // static State::JumpMapT _jump_map;
  typedef std::map<type::DxfTupleT, std::pair<State*, model::entities::EntityFactoryBase*> > EntJumpMapT;
  typedef EntJumpMapT::const_iterator EntJumpIterT;
  
  static EntJumpMapT _jump_map;
};

} /* sections */
} /* state */

#endif /* end of include guard: __SECTIONS__ENTITIESSECTIONSTATE_H__ */
