#ifndef __FILE__BINARYDXFFILE_H__
#define __FILE__BINARYDXFFILE_H__

#include "DxfFile.h"

namespace file {
/**
 * Represents binary dxf file
**/
class BinaryDxfFile : public DxfFile
{
public:
  friend class DxfFile;
  
  std::auto_ptr<type::DxfQueueT> read_file();
  
private:
  explicit BinaryDxfFile(const std::string& filename) :
    DxfFile(filename)
  {}
};

} /* file */

#endif /* end of include guard: __FILE__BINARYDXFFILE_H__ */
