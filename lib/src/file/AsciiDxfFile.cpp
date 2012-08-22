#include "dxf_machine/file/AsciiDxfFile.h"

#include <string>

#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>

#include "dxf_machine/exception/dxf/bad_dxf_file.h"

namespace dxf_machine { namespace file {

type::DxfQueuePtrT
AsciiDxfFile::read_file()
{
    // read Ascii file
    std::string s_code, s_value;
    int i_code;
    
    type::DxfQueuePtrT queue(new type::DxfQueueT);
    
    while (!_fstr.eof()) {
        getline(_fstr, s_code);
        boost::trim(s_code);
        try {
            i_code = boost::lexical_cast<int>(s_code);
        } catch (boost::bad_lexical_cast) {
            throw exception::dxf::bad_dxf_file("DXF file structure corrupted");
        }
        
        if (_fstr.eof()) throw exception::dxf::bad_dxf_file("DXF file structure corrupted");
        getline(_fstr, s_value);
        boost::trim(s_value);
        
        queue->push( type::DxfTuplePtrT(new type::DxfTupleT(i_code, s_value)) );
        
        if (s_value == "EOF") break;
    }
    
    if (s_value != "EOF") {
        throw exception::dxf::bad_dxf_file("DXF file structure corrupted");
    }
    
    return queue;
}

}}
