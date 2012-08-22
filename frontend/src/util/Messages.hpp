#ifndef __UTIL__MESSAGES_HPP__
#define __UTIL__MESSAGES_HPP__

#include <string>

namespace dxf_machine { namespace frontend {

namespace util {

class Messages
{
public:
    static const std::string usage;
    static const std::string version;
    static const std::string long_version;
    static const std::string no_files_to_process;

private:
    Messages ();
    Messages (const Messages&);
    void operator= (const Messages&);
};

const std::string Messages::usage = "Usage: \n\tentities_parser [OPTIONS] <input file>";
const std::string Messages::version = "0.1";
const std::string Messages::long_version = "dxf_machine version: " + Messages::version;
const std::string Messages::no_files_to_process = "No input files to process!\n Now exiting";

}

}}

#endif // __UTIL__MESSAGES_HPP__
