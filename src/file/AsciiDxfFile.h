#ifndef __FILE__ASCIIDXFFILE_H__
#define __FILE__ASCIIDXFFILE_H__

#include "DxfFile.h"

namespace file {
/**
 * Represents ASCII dxf file
**/
class AsciiDxfFile : public DxfFile
{
public:
  friend class DxfFile;
  
  std::auto_ptr<type::DxfQueueT> read_file();
  
private:
  explicit AsciiDxfFile(const std::string& filename) :
    DxfFile(filename)
  {}
};

} /* file */

#endif /* end of include guard: __FILE__ASCIIDXFFILE_H__ */
