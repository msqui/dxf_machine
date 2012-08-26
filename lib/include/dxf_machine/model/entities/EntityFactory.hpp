#ifndef __MODEL__ENTITIES__ENTITYFACTORY_HPP__
#define __MODEL__ENTITIES__ENTITYFACTORY_HPP__

#include "dxf_machine/model/entities/Entity.h"

namespace dxf_machine { namespace model {

namespace entities {

struct EntityFactoryBase
{
    virtual Entity::PtrT create() = 0;
};

template <typename T>
struct EntityFactory : public EntityFactoryBase
{
    Entity::PtrT create()
    {
        return Entity::PtrT(new T);
    }
};

}

}}

#endif // __MODEL__ENTITIES__ENTITYFACTORY_HPP__
