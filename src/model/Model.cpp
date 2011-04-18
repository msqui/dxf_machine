#include "Model.h"

namespace model {

Model::Model() :
  _entities(Model::EntVecPtrT(new Model::EntVecT))
{}

Model::EntVecT*
Model::entities()
{
  return _entities.get();
}

} /* model */
