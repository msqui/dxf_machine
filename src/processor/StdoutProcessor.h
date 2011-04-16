#ifndef __PROCESSOR__STDOUTPROCESSOR_H__
#define __PROCESSOR__STDOUTPROCESSOR_H__

#include "Processor.h"

namespace processor {

class StdoutProcessor : public Processor
{
public:
  void process(dispatcher::Dispatcher& dispatcher);
};

} /* processor */

#endif /* end of include guard: __PROCESSOR__STDOUTPROCESSOR_H__ */
