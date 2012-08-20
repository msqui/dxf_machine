#ifndef __TST__PATHS_HPP__
#define __TST__PATHS_HPP__

#include <string>

struct Paths
{
    static const std::string GOOD_FILENAME;
    static const std::string BAD_FILENAME;
    static const std::string BAD_FILE_FILENAME;
};

const std::string Paths::GOOD_FILENAME("../dxf_machine/data/Drawing1.dxf");
const std::string Paths::BAD_FILENAME("../dxf_machine/data/Bakldjfkodf.dxf");
const std::string Paths::BAD_FILE_FILENAME("../dxf_machine/data/BadDxfFile.dxf");

#endif /* end of include guard: __TST__PATHS_HPP__ */
