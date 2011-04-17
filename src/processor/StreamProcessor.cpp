#include "StreamProcessor.h"

#include "dispatcher/Dispatcher.h"

namespace processor {

StreamProcessor::StreamProcessor(std::ostream& str) :
  _str(str)
{}

void StreamProcessor::process(dispatcher::Dispatcher& dispatcher)
{
  while (!dispatcher.empty()) {
    _str << *(dispatcher++) << std::endl;
  }
}

} /* processor */