#include "BinaryDxfFile.h"

namespace file {

std::auto_ptr<type::DxfQueueT>
BinaryDxfFile::read_file()
{
  // TODO implement this
  
  // read bin file
  return std::auto_ptr<type::DxfQueueT>(new type::DxfQueueT);
}

} /* file */
