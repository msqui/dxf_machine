#ifndef __DISPATCHER__DISPATCHER_H__
#define __DISPATCHER__DISPATCHER_H__

#include <boost/utility.hpp>

#include "dxf_machine/type/types.hpp"

namespace dxf_machine { namespace dispatcher {
/**
 * Iterates through queue of tuples
**/
class Dispatcher : private boost::noncopyable
{
public:
    explicit Dispatcher(type::DxfQueuePtrT q_ptr);
    virtual ~Dispatcher();
    
    type::DxfTuplePtrT get() const;
    bool empty() const;

    void operator++ ();
    type::DxfTuplePtrT operator++ (int);
  
protected:
    type::DxfQueuePtrT _q_ptr;
};

}}

#endif // __DISPATCHER__DISPATCHER_H__
