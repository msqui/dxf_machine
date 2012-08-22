#include "dxf_machine/processor/Processor.h"

#include "dxf_machine/dispatcher/Dispatcher.h"

namespace dxf_machine { namespace processor {

void Processor::start(dispatcher::Dispatcher& dispatcher)
{
    while (!dispatcher.empty()) {
        process_tuple(dispatcher++);
    }
}

}}
