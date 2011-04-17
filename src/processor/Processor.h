#ifndef __PROCESSOR__PROCESSOR_H__
#define __PROCESSOR__PROCESSOR_H__


// ====================
// = Fwd declarations =
// ====================
namespace dispatcher {

  class Dispatcher;

} /* dispatcher */

namespace processor {
/**
 * Defines how to process dispatcher's tuples
**/
class Processor
{
public:
  Processor() {}
  virtual ~Processor() {}
  
  virtual void process(dispatcher::Dispatcher& dispatcher) = 0;
};

} /* processor */

#endif /* end of include guard: __PROCESSOR__PROCESSOR_H__ */
