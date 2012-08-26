#include "dxf_machine/processor/Processor.h"

#include "dxf_machine/dispatcher/Dispatcher.h"

namespace dxf_machine { namespace processor {

Processor::Processor() :
    _model_ptr()
{}

Processor::~Processor() {}

Processor::ModelPtrT
Processor::process(dispatcher::Dispatcher& dispatcher)
{
    _model_ptr.reset(new model::Model());

    while (!dispatcher.empty()) {
        process_tuple(dispatcher++);
    }

    return std::move(_model_ptr);
}

}}
