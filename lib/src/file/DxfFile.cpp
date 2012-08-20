#include "DxfFile.h"
#include "AsciiDxfFile.h"
#include "BinaryDxfFile.h"

#include <boost/filesystem.hpp>

#include "exception/file/file_not_found.h"


namespace file {

std::auto_ptr<DxfFile>
DxfFile::open_file(const std::string& filename)
{
  // checks if file exists
  if (!boost::filesystem::exists(filename) ||
      boost::filesystem::is_directory(filename))
  {
    throw exception::file::file_not_found("file doesn't exist");
  }
  
  // TODO check ASCII or Binary
  
  // for ascii:
  return std::auto_ptr<DxfFile>(new AsciiDxfFile(filename));
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

} /* file */
