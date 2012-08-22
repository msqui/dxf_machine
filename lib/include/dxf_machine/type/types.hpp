#ifndef __TYPE__TYPES_HPP__
#define __TYPE__TYPES_HPP__

#include <queue>
#include <memory>

#include "dxf_machine/type/CVTuple.hpp"
#include "dxf_machine/type/Point3d.hpp"

namespace dxf_machine { namespace type {

typedef CVTuple<std::string> DxfTupleT;
typedef std::shared_ptr<DxfTupleT> DxfTuplePtrT;

typedef std::queue<DxfTuplePtrT> DxfQueueT;
typedef std::shared_ptr<DxfQueueT> DxfQueuePtrT;

typedef _Point3d<double> Point3d;

}}

#endif // __TYPE__TYPES_HPP__
