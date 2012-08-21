#include "Util.h"

#include <sstream>
#include <stdexcept>

#include "Messages.hpp"
#include "exception/silent_exit.h"

namespace dm { namespace frontend {
namespace util {

void Util::parse_options(int argc, char** argv, std::string& input_file)
{
    po::options_description main_desc("Mandatory params");
    main_desc.add_options()
        ("input-file,i", po::value<std::string>(&input_file), "input dxf file")
        ;
    
    po::options_description help_desc("Help");
    help_desc.add_options()
        ("help,h", "produce help message")
        ("version,v", "display program version")
        ;
    
    po::options_description desc("");
    desc.add(main_desc).add(help_desc);
    
    po::positional_options_description p;
    p.add("input-file", -1);
    
    po::variables_map vm;
    po::store(po::command_line_parser(argc, argv).
                options(desc).positional(p).run(), vm);
    po::notify(vm);
    
    if(vm.count("help")) {
        throw exception::silent_exit( Util::usage(Messages::usage, desc) );
    }
    if(vm.count("version")) {
        throw exception::silent_exit( Messages::long_version );
    }
    
    if(!vm.count("input-file")) {
        throw std::invalid_argument(Messages::no_files_to_process);
    }
}

std::string Util::usage(const std::string& message, const po::options_description& desc)
{
    std::stringstream sstr;
    sstr << "\n" << message << "\n"
        << desc << "\n";
    return sstr.str();
}

}
}}
