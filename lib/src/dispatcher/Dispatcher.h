#ifndef __DISPATCHER__DISPATCHER_H__
#define __DISPATCHER__DISPATCHER_H__

#include <boost/utility.hpp>

#include "type/types.hpp"

namespace dispatcher {
/**
 * Iterates through queue of tuples
**/
class Dispatcher : private boost::noncopyable
{
public:
  explicit Dispatcher(std::auto_ptr<type::DxfQueueT> q_ptr);
  virtual ~Dispatcher();
  
  type::DxfTuplePtrT get() const;
  bool empty() const;
  
  void operator++ ();
  type::DxfTuplePtrT operator++ (int);
  
protected:
  std::auto_ptr<type::DxfQueueT> _q_ptr;
};

} /* dispatcher */

#endif /* end of include guard: __DISPATCHER__DISPATCHER_H__ */
