#ifndef __TYPE__POINT3D_HPP__
#define __TYPE__POINT3D_HPP__

#include <iostream>

namespace dxf_machine { namespace type {

template <typename T>
struct _Point3d
{
  T x;
  T y;
  T z;
  
  _Point3d(T x = T(), T y = T(), T z = T()) :
    x(x),
    y(y),
    z(z)
  {}
  
  friend std::ostream& operator<< (std::ostream& str, const _Point3d& p3d)
  {
    str << "( " << p3d.x << " ; "
                << p3d.y << " ; "
                << p3d.z
        << " )";
    
    return str;
  }
};

}}

#endif // __TYPE__POINT3D_HPP__
