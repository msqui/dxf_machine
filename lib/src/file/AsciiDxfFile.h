#ifndef __FILE__ASCIIDXFFILE_H__
#define __FILE__ASCIIDXFFILE_H__

#include "DxfFile.h"

namespace dxf_machine { namespace file {

/**
 * Represents ASCII dxf file
**/
class AsciiDxfFile : public DxfFile
{
public:
    friend class DxfFile;
    
    type::DxfQueuePtrT read_file();
  
private:
    explicit AsciiDxfFile(const std::string& filename) :
        DxfFile(filename)
    {}
};

}}

#endif // __FILE__ASCIIDXFFILE_H__
