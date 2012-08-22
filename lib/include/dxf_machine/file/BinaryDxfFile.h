#ifndef __FILE__BINARYDXFFILE_H__
#define __FILE__BINARYDXFFILE_H__

#include "dxf_machine/file/DxfFile.h"

namespace dxf_machine { namespace file {

/**
 * Represents binary dxf file
**/
class BinaryDxfFile : public DxfFile
{
public:
    friend class DxfFile;
    
    type::DxfQueuePtrT read_file();
  
private:
    explicit BinaryDxfFile(const std::string& filename) :
        DxfFile(filename)
    {}
};

}}

#endif // __FILE__BINARYDXFFILE_H__
