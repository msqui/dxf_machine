#include "dxf_machine/processor/StreamProcessor.h"

namespace dxf_machine { namespace processor {

StreamProcessor::StreamProcessor(std::ostream& str) :
  _str(str)
{}

void StreamProcessor::process_tuple(type::DxfTuplePtrT tuple_ptr)
{
  _str << *tuple_ptr << std::endl;
}

}}
