#include "dxf_machine/state/entities/LwPolylineState.h"

#include <boost/lexical_cast.hpp>

#include "dxf_machine/model/entities/LwPolyline.h"

namespace dxf_machine { namespace state {

namespace entities {
  
  namespace me = model::entities;

// TODO add exception handling
// TODO Beware of indirect order of coordinates (i.e. 20, 10 instead of 10, 20)
void LwPolylineState::process(State::ProcPtrT proc, type::DxfTuplePtrT tuple_ptr)
{
    double value;
    switch (tuple_ptr->code()) {
        case 10:
            #ifdef DEBUG
                std::cout << "LwPolyline 10: " << tuple_ptr->value() << std::endl;
            #endif
            value = boost::lexical_cast<double>(tuple_ptr->value());
            if (me::LwPolyline* ptr = dynamic_cast<me::LwPolyline*>(current_entity(proc).get())) {
                ptr->points.push_back(type::Point3d(value));
            } else { /* throw */ }
            break;
        case 20:
            #ifdef DEBUG
                std::cout << "LwPolyline 20: " << tuple_ptr->value() << std::endl;
            #endif
            value = boost::lexical_cast<double>(tuple_ptr->value());
            if (me::LwPolyline* ptr = dynamic_cast<me::LwPolyline*>(current_entity(proc).get())) {
                ptr->points.back().y = value;
            } else { /* throw */ }
            break;
        default:
            EntityState::process(proc, tuple_ptr);
            break;
    }
}

}

}}
