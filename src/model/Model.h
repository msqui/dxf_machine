#ifndef __MODEL__MODEL_H__
#define __MODEL__MODEL_H__

#include <vector>
#include <memory>

#include <boost/utility.hpp>
#include <boost/ptr_container/ptr_vector.hpp>

#include "entities/Entity.h"

namespace model {
/**
 * struct of object collections
**/
class Model : private boost::noncopyable
{
public:
  typedef boost::ptr_vector<entities::Entity> EntVecT;
  typedef std::auto_ptr<EntVecT> EntVecPtrT;
  
  Model();
  
  EntVecT* entities();
  
private:
  EntVecPtrT _entities;
};

} /* model */

#endif /* end of include guard: __MODEL__MODEL_H__ */
