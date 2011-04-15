#ifndef __TYPE__CVTUPLE_HPP__
#define __TYPE__CVTUPLE_HPP__

#include <iostream>
#include <string>
#include <sstream>

#include <boost/utility.hpp>

namespace type {
/**
 * Code-Value tuple template
**/
template <typename ValT>
class CVTuple : private boost::noncopyable
{
public:
  CVTuple(int code, const ValT& value) :
    _code(code),
    _value(value)
  {}
  
  int code() const
  {
    return _code;
  }
  
  ValT value() const
  {
    return _value;
  }
  
  bool operator== (const CVTuple& rhs) const
  {
    return ( (_code == rhs.code()) && (_value == rhs.value()) );
  }
  
  bool operator< (const CVTuple& rhs) const
  {
    if (_code == rhs.code()) {
      return (_value < rhs.value());
    }
    
    return (_code < rhs.code());
  }
  
  operator std::string () const
  {
    std::stringstream sstr;
    sstr << "(" << _code << " ; " << _value << ")";
    return sstr.str();
  }
  
  friend std::ostream& operator<< (std::ostream& ostr, const CVTuple& tuple)
  {
    ostr << static_cast<std::string>(tuple);
    return ostr;
  }
  
private:
  // ==========
  // = Fields =
  // ==========
  int _code;
  ValT _value;
};

} /* type */

#endif /* end of include guard: __TYPE__CVTUPLE_HPP__ */
