#ifndef __PROCESSOR__PROCESSOR_H__
#define __PROCESSOR__PROCESSOR_H__

#include "dxf_machine/type/types.hpp"

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
public:
    Processor() {}
    virtual ~Processor() {}
    
    void start(dispatcher::Dispatcher& dispatcher);
    
    virtual void process_tuple(type::DxfTuplePtrT tuple_ptr) = 0;
};

}

}

#endif // __PROCESSOR__PROCESSOR_H__
