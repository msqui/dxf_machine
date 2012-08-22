#ifndef __FILE__DXFFILE_H__
#define __FILE__DXFFILE_H__

#include <memory>
#include <string>
#include <fstream>

#include <boost/utility.hpp>

#include "dxf_machine/type/types.hpp"

namespace dxf_machine { namespace file {

/**
 * Represents Dxf file
**/
class DxfFile : private boost::noncopyable
{
public:
    typedef std::unique_ptr<DxfFile> DxfFilePtrT;

    /**
     * Factory to open ASCII or binary dxfs
    **/
    static DxfFilePtrT open_file(const std::string& filename);
    
    virtual ~DxfFile();
    
    virtual type::DxfQueuePtrT read_file() = 0;
  
protected:
    explicit DxfFile(const std::string& filename);
    
    // ==========
    // = Fields =
    // ==========
    std::string _filename;
    std::fstream _fstr;
};

}}

#endif // __FILE__DXFFILE_H__
