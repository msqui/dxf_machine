#include "LwPolylineState.h"

#include <boost/lexical_cast.hpp>

#include "processor/StatefulProcessor.h"

#include "model/entities/LwPolyline.h"

namespace state {
namespace entities {
  
  namespace me = model::entities;

LwPolylineState::PtrT LwPolylineState::_instance = LwPolylineState::PtrT();

LwPolylineState* LwPolylineState::Instance()
{
  if (!_instance.get()) {
    _instance = LwPolylineState::PtrT(new LwPolylineState);
  }
  return _instance.get();
}

// TODO add exception handling
// TODO Beware of indirect order of coordinates (i.e. 20, 10 instead of 10, 20)
void LwPolylineState::process(type::DxfTuplePtrT tuple_ptr, processor::StatefulProcessor* p)
{
  double value;
  switch (tuple_ptr->code()) {
    case 10:
      std::cout << "LwPolyline 10: " << tuple_ptr->value() << std::endl;
      value = boost::lexical_cast<double>(tuple_ptr->value());
      dynamic_cast<me::LwPolyline&>(p->current_entity()).points.push_back(type::Point3d(value));
      break;
    case 20:
      std::cout << "LwPolyline 20: " << tuple_ptr->value() << std::endl;
      value = boost::lexical_cast<double>(tuple_ptr->value());
      dynamic_cast<me::LwPolyline&>(p->current_entity()).points.back().y = value;
      break;
    default:
      EntityState::process(tuple_ptr, p);
      break;
  }
}

} /* entities */
} /* state */
