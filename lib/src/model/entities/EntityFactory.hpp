#ifndef __MODEL__ENTITIES__ENTITYFACTORY_HPP__
#define __MODEL__ENTITIES__ENTITYFACTORY_HPP__

#include "Entity.h"

namespace dxf_machine { namespace model {

namespace entities {

struct EntityFactoryBase
{
    virtual Entity* create() = 0;
};

template <typename T>
struct EntityFactory : public EntityFactoryBase
{
    T* create()
    {
        return new T;
    }
};

}

}}

#endif // __MODEL__ENTITIES__ENTITYFACTORY_HPP__
