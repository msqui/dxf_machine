#include "dxf_machine/state/entities/CircleState.h"

#include <boost/lexical_cast.hpp>

#include "dxf_machine/model/entities/Circle.h"

namespace dxf_machine { namespace state {

namespace entities {
  
    namespace me = model::entities;

// TODO add exception handling
void CircleState::process(State::ProcPtrT proc, type::DxfTuplePtrT tuple_ptr)
{
    double value;
    switch (tuple_ptr->code()) {
        case 10:
            #ifdef DEBUG
                std::cout << "Circle 10: " << tuple_ptr->value() << std::endl;
            #endif
            value = boost::lexical_cast<double>(tuple_ptr->value());
            if (me::Circle* ptr = dynamic_cast<me::Circle*>(current_entity(proc).get())) {
                ptr->center.x = value;
            } else { /* throw */ }
            break;
        case 20:
            #ifdef DEBUG
                std::cout << "Circle 20: " << tuple_ptr->value() << std::endl;
            #endif
            value = boost::lexical_cast<double>(tuple_ptr->value());
            if (me::Circle* ptr = dynamic_cast<me::Circle*>(current_entity(proc).get())) {
                ptr->center.y = value;
            } else { /* throw */ }
            break;
        case 30:
            #ifdef DEBUG
                std::cout << "Circle 30: " << tuple_ptr->value() << std::endl;
            #endif
            value = boost::lexical_cast<double>(tuple_ptr->value());
            if (me::Circle* ptr = dynamic_cast<me::Circle*>(current_entity(proc).get())) {
                ptr->center.z = value;
            } else { /* throw */ }
            break;
        case 40:
            #ifdef DEBUG
                std::cout << "Circle 40: " << tuple_ptr->value() << std::endl;
            #endif
            value = boost::lexical_cast<double>(tuple_ptr->value());
            if (me::Circle* ptr = dynamic_cast<me::Circle*>(current_entity(proc).get())) {
                ptr->radius = value;
            } else { /* throw */ }
            break;
        default:
            EntityState::process(proc, tuple_ptr);
            break;
    }
}

}

}}
