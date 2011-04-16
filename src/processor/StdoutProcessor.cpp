#include "StdoutProcessor.h"

#include <iostream>

namespace processor {

void StdoutProcessor::process(dispatcher::Dispatcher& dispatcher)
{
  while (!dispatcher.empty()) {
    std::cout << *(dispatcher++) << std::endl;
  }
}

} /* processor */