#ifndef __STATE__SECTIONS__ENTITIESSECTIONSTATE_H__
#define __STATE__SECTIONS__ENTITIESSECTIONSTATE_H__

#include "dxf_machine/state/sections/SectionState.h"

#include "dxf_machine/model/entities/Entity.h"
#include "dxf_machine/model/entities/EntityFactory.hpp"

namespace dxf_machine { namespace state {

namespace sections {

class EntitiesSectionState : public SectionState
{
public:
    virtual ~EntitiesSectionState();
    
    void process(State::ProcPtrT proc, type::DxfTuplePtrT tuple_ptr);
  
private:
    // static State::JumpMapT _jump_map;
    typedef std::map<type::DxfTupleT,
                    std::pair<State::PtrT, model::entities::EntityFactoryBase*> > EntJumpMapT;
    typedef EntJumpMapT::const_iterator EntJumpIterT;
    
    static EntJumpMapT _jump_map;
};

}

}}

#endif // __STATE__SECTIONS__ENTITIESSECTIONSTATE_H__
