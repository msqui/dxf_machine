#ifndef __UTIL__UNINSTANTIABLE_HPP__
#define __UTIL__UNINSTANTIABLE_HPP__

namespace dxf_machine { namespace util {

class uninstantiable
{
private:
    uninstantiable();
    uninstantiable(const uninstantiable&);
    void operator= (const uninstantiable&);
};

}}

#endif // __UTIL__UNINSTANTIABLE_HPP__
