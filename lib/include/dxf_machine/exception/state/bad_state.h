#ifndef __EXCEPTION__STATE__BAD_STATE_H__
#define __EXCEPTION__STATE__BAD_STATE_H__

#include <stdexcept>

namespace dxf_machine { namespace exception {

namespace state {

struct bad_state : public std::runtime_error
{
    explicit bad_state(const std::string& what) :
        std::runtime_error(what)
    {}
};

}

}}

#endif // __EXCEPTION__STATE__BAD_STATE_H__
