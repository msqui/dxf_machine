#include "Dispatcher.h"

#include <stdexcept>

namespace dispatcher {

Dispatcher::Dispatcher(std::auto_ptr<type::DxfQueueT> q_ptr) :
  _q_ptr(q_ptr)
{}

Dispatcher::~Dispatcher()
{}

type::DxfTuplePtrT
Dispatcher::get() const
{
  if (_q_ptr->empty()) {
    throw std::out_of_range("tuple queue is empty");
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
    throw std::out_of_range("tuple queue is empty");
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

} /* dispatcher */
