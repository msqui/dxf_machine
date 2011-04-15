#ifndef __FILE__DXFFILE_H__
#define __FILE__DXFFILE_H__

#include <memory>
#include <fstream>

#include <boost/utility.hpp>

#include "type/types.hpp"

namespace file {
/**
 * Represents Dxf file
**/
class DxfFile : private boost::noncopyable
{
public:
  /**
   * Factory to open ASCII or binary dxfs
  **/
  static std::auto_ptr<DxfFile> open_file(const std::string& filename);
  
  virtual ~DxfFile();
  
  virtual std::auto_ptr<type::DxfQueueT> read_file() = 0;
  
protected:
  explicit DxfFile(const std::string& filename);
  
  // ==========
  // = Fields =
  // ==========
  std::string _filename;
  std::fstream _fstr;
  
};

} /* file */

#endif /* end of include guard: __FILE__DXFFILE_H__ */
