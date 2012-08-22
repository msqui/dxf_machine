#ifndef __PROCESSOR__STATEFULPROCESSOR_H__
#define __PROCESSOR__STATEFULPROCESSOR_H__

#include "Processor.h"

#include <memory>

#include "model/Model.h"
#include "model/entities/Entity.h"

namespace dxf_machine {

    // ====================
    // = Fwd declarations =
    // ====================
    namespace state {
    
        class State;
    
    }

namespace processor {

class StatefulProcessor : public Processor
{
public:
    explicit StatefulProcessor(state::State* state = NULL);
    
    void process_tuple(type::DxfTuplePtrT tuple_ptr);
    
    void add_entity(model::entities::Entity* ent);
    model::entities::Entity& current_entity();
    
    model::Model* get_model();
    
private:
    state::State* _current_state;
    
    friend class state::State;
    void change_state(state::State* new_state);
    
    std::auto_ptr<model::Model> _model_ptr;
};

}

}

#endif // __PROCESSOR__STATEFULPROCESSOR_H__
