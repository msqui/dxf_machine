#ifndef __DXF__BAD_DXF_FILE_H__
#define __DXF__BAD_DXF_FILE_H__

#include <stdexcept>

namespace exception {
namespace dxf {

struct bad_dxf_file : public std::logic_error
{
  explicit bad_dxf_file(const std::string& what) :
    std::logic_error(what)
  {}
};

} /* dxf */
} /* exception */

#endif /* end of include guard: __DXF__BAD_DXF_FILE_H__ */
