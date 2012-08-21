#ifndef __EXCEPTION__SILENT_EXIT_H__
#define __EXCEPTION__SILENT_EXIT_H__

#include <stdexcept>

namespace exception {

struct silent_exit : public std::runtime_error
{
    explicit silent_exit(const std::string& what) :
        std::runtime_error(what)
    {}
};

}

#endif // __EXCEPTION__SILENT_EXIT_H__
