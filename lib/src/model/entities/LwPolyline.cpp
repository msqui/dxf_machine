#include "LwPolyline.h"

#include <algorithm>

namespace dxf_machine { namespace model {

namespace entities {

LwPolyline::LwPolyline()
{
    #ifdef DEBUG
        std::cout << "LwPolyline created" << std::endl;
    #endif
}

std::ostream& LwPolyline::put(std::ostream& str) const
{
    str << "LwPolyline" << "\n";
    std::for_each(points.begin(), points.end(), print_points(str));
    return str;
}

}

}}
