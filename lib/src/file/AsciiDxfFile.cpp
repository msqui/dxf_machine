#include "AsciiDxfFile.h"

#include <string>

#include <boost/make_shared.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>

#include "exception/dxf/bad_dxf_file.h"

namespace file {

std::auto_ptr<type::DxfQueueT>
AsciiDxfFile::read_file()
{
  // read Ascii file
  std::string s_code, s_value;
  int i_code;
  
  std::auto_ptr<type::DxfQueueT> queue(new type::DxfQueueT);
  
  while (!_fstr.eof()) {
    getline(_fstr, s_code);
    boost::trim(s_code);
    try {
      i_code = boost::lexical_cast<int>(s_code);
    }
    catch (boost::bad_lexical_cast) {
      throw exception::dxf::bad_dxf_file("DXF file structure corrupted");
    }
    
    if (_fstr.eof()) throw exception::dxf::bad_dxf_file("DXF file structure corrupted");
    getline(_fstr, s_value);
    boost::trim(s_value);
    
    queue->push(boost::make_shared<type::DxfTupleT>(i_code, s_value));
    
    if (s_value == "EOF") break;
  }
  
  if (s_value != "EOF") {
    throw exception::dxf::bad_dxf_file("DXF file structure corrupted");
  }
  
  return queue;
}

} /* file */
