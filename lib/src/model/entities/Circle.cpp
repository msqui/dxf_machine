#include "Circle.h"

namespace dxf_machine { namespace model {

namespace entities {

Circle::Circle()
{
    #ifdef DEBUG
        std::cout << "Circle created" << std::endl;
    #endif
}

std::ostream& Circle::put(std::ostream& str) const
{
    str << "Circle" << "\n"
        << "\tcenter: " << center << "\n"
        << "\tradius: " << radius << "\n";
    return str;
}

}

}}
