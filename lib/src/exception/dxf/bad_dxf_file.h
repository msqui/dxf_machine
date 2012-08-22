#ifndef __EXCEPTION__DXF__BAD_DXF_FILE_H__
#define __EXCEPTION__DXF__BAD_DXF_FILE_H__

#include <stdexcept>

namespace dxf_machine { namespace exception {

namespace dxf {

struct bad_dxf_file : public std::logic_error
{
    explicit bad_dxf_file(const std::string& what) :
        std::logic_error(what)
    {}
};

}

}}

#endif // __EXCEPTION__DXF__BAD_DXF_FILE_H__
