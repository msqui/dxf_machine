#ifndef __MODEL__ENTITIES__LINE_H__
#define __MODEL__ENTITIES__LINE_H__

#include "Entity.h"

#include "type/types.hpp"

namespace dxf_machine { namespace model {

namespace entities {

class Line : public Entity
{
public:
    Line();
    
    type::Point3d start;
    type::Point3d end;
    
protected:
    std::ostream& put(std::ostream& str) const;
};

}

}}

#endif // __MODEL__ENTITIES__LINE_H__
