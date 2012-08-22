#include "dxf_machine/dispatcher/Dispatcher.h"

#include <stdexcept>

#include "dxf_machine/util/Messages.h"

namespace dxf_machine { namespace dispatcher {

Dispatcher::Dispatcher(type::DxfQueuePtrT q_ptr) :
    _q_ptr(q_ptr)
{}

Dispatcher::~Dispatcher()
{}

type::DxfTuplePtrT
Dispatcher::get() const
{
    if (_q_ptr->empty()) {
        throw std::out_of_range(util::Messages::TUPLE_QUEUE_EMPTY);
    }
    
    return _q_ptr->front();
}

bool Dispatcher::empty() const
{
    return _q_ptr->empty();
}

void Dispatcher::operator++ ()
{
    if (_q_ptr->empty()) {
        throw std::out_of_range(util::Messages::TUPLE_QUEUE_EMPTY);
    }
    _q_ptr->pop();
}

type::DxfTuplePtrT 
Dispatcher::operator++ (int)
{
    type::DxfTuplePtrT tuple = get();
    ++(*this);
    return tuple;
}

}}
