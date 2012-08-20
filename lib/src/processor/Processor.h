#ifndef __PROCESSOR__PROCESSOR_H__
#define __PROCESSOR__PROCESSOR_H__

#include <type/types.hpp>

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
  
  void start(dispatcher::Dispatcher& dispatcher);
  
  virtual void process_tuple(type::DxfTuplePtrT tuple_ptr) = 0;
};

} /* processor */

#endif /* end of include guard: __PROCESSOR__PROCESSOR_H__ */
