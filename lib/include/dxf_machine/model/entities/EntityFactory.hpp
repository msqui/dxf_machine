#ifndef __MODEL__ENTITIES__ENTITYFACTORY_HPP__
#define __MODEL__ENTITIES__ENTITYFACTORY_HPP__

#include <memory>

#include <boost/noncopyable.hpp>

#include "dxf_machine/model/entities/Entity.h"

namespace dxf_machine { namespace model {

namespace entities {

struct EntityFactoryBase;
typedef std::shared_ptr<EntityFactoryBase> FactoryPtrT;

struct EntityFactoryBase
{
    virtual ~EntityFactoryBase() {}
    virtual Entity::PtrT create() = 0;
};

template <typename T>
class EntityFactory : public EntityFactoryBase, private boost::noncopyable
{
public:
    static FactoryPtrT Instance()
    {
        return FactoryPtrT(new EntityFactory<T>());
    }

    Entity::PtrT create()
    {
        return Entity::PtrT(new T);
    }

private:
    EntityFactory() {}
};

}

}}

#endif // __MODEL__ENTITIES__ENTITYFACTORY_HPP__
