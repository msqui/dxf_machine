#ifndef __TYPE__TYPES_HPP__
#define __TYPE__TYPES_HPP__

#include <queue>
#include <boost/shared_ptr.hpp>

#include "CVTuple.hpp"

namespace type {

typedef CVTuple<std::string> DxfTupleT;
typedef boost::shared_ptr<DxfTupleT> DxfTuplePtrT;

typedef std::queue<DxfTuplePtrT> DxfQueueT;

} /* type */

#endif /* end of include guard: __TYPE__TYPES_HPP__ */
