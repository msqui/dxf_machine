#ifndef __PROCESSOR__STREAMPROCESSOR_H__
#define __PROCESSOR__STREAMPROCESSOR_H__

#include "Processor.h"

#include <iostream>

namespace dxf_machine { namespace processor {

/**
 * Takes ostream and dumps all tuples from dispatcher to that stream
**/
class StreamProcessor : public Processor
{
public:
  explicit StreamProcessor(std::ostream& str);
  
  void process_tuple(type::DxfTuplePtrT tuple_ptr);
  
private:
  std::ostream& _str;
};

}}

#endif // __PROCESSOR__STREAMPROCESSOR_H__
