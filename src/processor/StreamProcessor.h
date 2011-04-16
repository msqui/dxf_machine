#ifndef __PROCESSOR__STREAMPROCESSOR_H__
#define __PROCESSOR__STREAMPROCESSOR_H__

#include "Processor.h"

#include <iostream>

namespace processor {
/**
 * Takes ostream and dumps all tuples from dispatcher to that stream
**/
class StreamProcessor : public Processor
{
public:
  explicit StreamProcessor(std::ostream& str);
  
  void process(dispatcher::Dispatcher& dispatcher);
  
private:
  std::ostream& _str;
};

} /* processor */

#endif /* end of include guard: __PROCESSOR__STREAMPROCESSOR_H__ */