#include "dxf_machine/file/DxfFile.h"

#include "dxf_machine/file/AsciiDxfFile.h"
#include "dxf_machine/file/BinaryDxfFile.h"

#if defined DEBUG
    #include <iostream>
#endif

#include <boost/filesystem.hpp>

#include "dxf_machine/exception/file/file_not_found.h"
#include "dxf_machine/util/Messages.h"

namespace dxf_machine { namespace file {

DxfFile::DxfFilePtrT
DxfFile::open_file(const std::string& filename)
{
    // checks if file exists
    if (!boost::filesystem::exists(filename) ||
        boost::filesystem::is_directory(filename))
    {
        throw exception::file::file_not_found(util::Messages::FILE_NOT_FOUND);
    }
    
    // TODO check ASCII or Binary
    
    // for ascii:
    return DxfFile::DxfFilePtrT(new AsciiDxfFile(filename));
}

DxfFile::DxfFile(const std::string& filename) :
    _fstr(filename.c_str(), std::ios::in)
{}

DxfFile::~DxfFile()
{
    #if defined DEBUG
      std::cout << "file is closed" << std::endl;
    #endif
    if (_fstr.is_open()) {
      _fstr.close();
    }
}

}}
