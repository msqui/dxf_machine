#ifndef __MODEL__ENTITIES__CIRCLE_H__
#define __MODEL__ENTITIES__CIRCLE_H__

#include "dxf_machine/model/entities/Entity.h"

#include "dxf_machine/type/types.hpp"

namespace dxf_machine { namespace model {

namespace entities {

class Circle : public Entity
{
public:
    Circle();
    
    type::Point3d center;
    double radius;
    
protected:
    std::ostream& put(std::ostream& str) const;
};

}

}}

#endif // __MODEL__ENTITIES__CIRCLE_H__
