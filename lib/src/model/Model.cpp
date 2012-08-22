#include "Model.h"

namespace dxf_machine { namespace model {

Model::Model() :
    _entities(Model::EntVecPtrT(new Model::EntVecT))
{}

Model::EntVecT*
Model::entities()
{
    // TODO Danger!!!
    return _entities.get();
}

}}
