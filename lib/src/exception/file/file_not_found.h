#ifndef __EXCEPTION_FILE__FILE_NOT_FOUND_H__
#define __EXCEPTION_FILE__FILE_NOT_FOUND_H__

#include <stdexcept>

namespace exception {
namespace file {

struct file_not_found : public std::runtime_error
{
  explicit file_not_found(const std::string& what) :
    std::runtime_error(what)
  {}
};

} /* file */
} /* exception */

#endif /* end of include guard: __EXCEPTION_FILE__FILE_NOT_FOUND_H__ */
