#ifndef __TYPE__TYPES_HPP__
#define __TYPE__TYPES_HPP__

#include <queue>
#include <boost/shared_ptr.hpp>

#include "CVTuple.hpp"
#include "Point3d.hpp"

namespace type {

typedef CVTuple<std::string> DxfTupleT;
typedef boost::shared_ptr<DxfTupleT> DxfTuplePtrT;

typedef std::queue<DxfTuplePtrT> DxfQueueT;

typedef _Point3d<double> Point3d;

} /* type */

#endif /* end of include guard: __TYPE__TYPES_HPP__ */
