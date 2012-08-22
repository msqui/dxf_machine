#ifndef __MODEL__ENTITIES__LWPOLYLINE_H__
#define __MODEL__ENTITIES__LWPOLYLINE_H__

#include "dxf_machine/model/entities/Entity.h"

#include <vector>
#include <iostream>
#include <functional>

#include "dxf_machine/type/types.hpp"

namespace dxf_machine { namespace model {

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

}

}}

#endif // __MODEL__ENTITIES__LWPOLYLINE_H__
