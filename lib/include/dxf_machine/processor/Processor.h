#ifndef __PROCESSOR__PROCESSOR_H__
#define __PROCESSOR__PROCESSOR_H__

#include <memory>

#include "dxf_machine/type/types.hpp"
#include "dxf_machine/model/Model.h"

namespace dxf_machine {

    // ====================
    // = Fwd declarations =
    // ====================
    namespace dispatcher {
        class Dispatcher;
    }

namespace processor {
/**
 * Defines how to process dispatcher's tuples
**/
class Processor
{
    typedef std::unique_ptr<model::Model> ModelPtrT;

public:
    Processor();
    virtual ~Processor();
    
    ModelPtrT process(dispatcher::Dispatcher& dispatcher);
    
protected:
    ModelPtrT _model_ptr;

    virtual void process_tuple(type::DxfTuplePtrT tuple_ptr) = 0;
};

}

}

#endif // __PROCESSOR__PROCESSOR_H__
