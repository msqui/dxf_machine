#ifndef __UTIL__MESSAGES_HPP__
#define __UTIL__MESSAGES_HPP__

#include <string>

#include "dxf_machine/util/uninstantiable.hpp"

namespace dxf_machine { namespace util {

struct Messages : private uninstantiable
{
    static const std::string TUPLE_QUEUE_EMPTY;

    static const std::string FILE_NOT_FOUND;
    static const std::string DXF_BAD_STRUCTURE;

    static const std::string PROCESSOR_NULL_STATE;
};

}}

#endif // __UTIL__MESSAGES_HPP__
