#ifndef __PROCESSOR__PROCESSOR_H__
#define __PROCESSOR__PROCESSOR_H__

#include "dispatcher/Dispatcher.h"

namespace processor {

class Processor
{
public:
  Processor() {}
  virtual ~Processor() {}
  
  virtual void process(dispatcher::Dispatcher& dispatcher) = 0;
};

} /* processor */

#endif /* end of include guard: __PROCESSOR__PROCESSOR_H__ */
