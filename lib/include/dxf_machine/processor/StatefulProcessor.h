#ifndef __PROCESSOR__STATEFULPROCESSOR_H__
#define __PROCESSOR__STATEFULPROCESSOR_H__

#include "dxf_machine/processor/Processor.h"

#include <memory>

#include "dxf_machine/model/Model.h"
#include "dxf_machine/model/entities/Entity.h"

namespace dxf_machine {

    // ====================
    // = Fwd declarations =
    // ====================
    namespace state {
        class State;
    }

namespace processor {

class StatefulProcessor : public Processor,
                        public std::enable_shared_from_this<StatefulProcessor>
{
    typedef std::shared_ptr<state::State> StatePtrT;

public:
    typedef std::shared_ptr<StatefulProcessor> PtrT;
    
    static PtrT Instance(StatePtrT state = nullptr);
    
private:
    StatefulProcessor(StatePtrT state = nullptr);

    StatePtrT _current_state;
    
    friend class state::State;
    void change_state(StatePtrT new_state);
    
    void process_tuple(type::DxfTuplePtrT tuple_ptr);

    void add_entity(model::entities::Entity::PtrT ent);
    model::entities::Entity::PtrT current_entity();
    
};

}

}

#endif // __PROCESSOR__STATEFULPROCESSOR_H__
