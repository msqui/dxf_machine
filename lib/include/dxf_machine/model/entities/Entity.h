#ifndef __MODEL__ENTITIES__ENTITY_H__
#define __MODEL__ENTITIES__ENTITY_H__

#include <memory>
#include <iostream>

namespace dxf_machine { namespace model {

namespace entities {
/**
 * ABC for entities
**/
class Entity
{
public:
    typedef std::shared_ptr<Entity> PtrT;

    virtual ~Entity();
    
    friend std::ostream& operator<< (std::ostream& str, const Entity& ent)
    {
        return ent.put(str);
    }
  
protected:
    virtual std::ostream& put(std::ostream& str) const = 0;
};

}

}}

#endif // __MODEL__ENTITIES__ENTITY_H__
