#ifndef __STATE__STATE_H__
#define __STATE__STATE_H__

#include <map>
#include <memory>

#include "dxf_machine/type/types.hpp"
#include "dxf_machine/model/entities/Entity.h"

namespace dxf_machine {

    // ====================
    // = Fwd declarations =
    // ====================
    namespace processor {
        class StatefulProcessor;
    }


namespace state {

class State
{
public:
    typedef std::shared_ptr<processor::StatefulProcessor> ProcPtrT;
    typedef std::shared_ptr<State> PtrT;

    virtual ~State();

    template <typename StateT>
    static PtrT Instance()
    {
        return PtrT(new StateT);
    }
    
    virtual void process(ProcPtrT proc, type::DxfTuplePtrT tuple_ptr) = 0;

protected:
    typedef std::map<type::DxfTupleT, State::PtrT> JumpMapT;
    typedef JumpMapT::const_iterator JumpIterT;
    
    void change_state(ProcPtrT proc, State::PtrT new_state);
    model::entities::Entity::PtrT current_entity(ProcPtrT proc);
    void add_entity(ProcPtrT proc, model::entities::Entity::PtrT ent);
    
    State();
};

}

}

#endif // __STATE__STATE_H__
