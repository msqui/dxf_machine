#ifndef __ENTITIES__LWPOLYLINE_H__
#define __ENTITIES__LWPOLYLINE_H__

#include "Entity.h"

#include <vector>
#include <iostream>
#include <functional>

#include "type/types.hpp"

namespace model {
namespace entities {

class LwPolyline : public Entity
{
public:
  LwPolyline();
  
  std::vector<type::Point3d> points;
  
protected:
  std::ostream& put(std::ostream& str) const;
  
  struct print_points : public std::unary_function<type::Point3d, void>
  {
    std::ostream& _ostr;
    
    print_points(std::ostream& ostr) : _ostr(ostr) {}
    
    void operator() (const type::Point3d& p3d)
    {
      _ostr << "\t" << p3d << "\n";
    }
    
  };
};

} /* entities */
} /* model */

#endif /* end of include guard: __ENTITIES__LWPOLYLINE_H__ */
