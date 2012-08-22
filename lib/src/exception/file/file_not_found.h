#ifndef __EXCEPTION_FILE__FILE_NOT_FOUND_H__
#define __EXCEPTION_FILE__FILE_NOT_FOUND_H__

#include <stdexcept>

namespace dxf_machine { namespace exception {

namespace file {

struct file_not_found : public std::runtime_error
{
    explicit file_not_found(const std::string& what) :
        std::runtime_error(what)
    {}
};

}

}}

#endif // __EXCEPTION_FILE__FILE_NOT_FOUND_H__
