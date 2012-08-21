#ifndef __UTIL__UTIL_H__
#define __UTIL__UTIL_H__

#include <string>

#include <boost/program_options.hpp>
namespace po = boost::program_options;

namespace util {

class Util
{
public:
    static void parse_options(int argc, char** argv, std::string& input_file);
    static std::string usage(const std::string& message, const po::options_description& desc);

private:
    Util();
    Util(const Util&);
    void operator= (const Util&);
};

}

#endif // __UTIL__UTIL_H__
