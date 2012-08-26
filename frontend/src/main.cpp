#include <iostream>
#include <cstdlib>
#include <string>
#include <exception>
#include <algorithm>

#include "util/Util.h"
#include "exception/silent_exit.h"

#include "dxf_machine/Machine.hpp"

using namespace dxf_machine;
namespace f = frontend;

// ================
// = Main program =
// ================
int main(int argc, char **argv)
{
    // ==================
    // = Config options =
    // ==================
    std::string input_file;

    try {
        f::util::Util::parse_options(argc, argv, input_file);
    } catch (const f::exception::silent_exit& exc) {
        std::cout << exc.what() << std::endl;
        return EXIT_SUCCESS;
    } catch (const std::exception& exc) {
        std::cerr << "Error: " << exc.what() << std::endl;
        return EXIT_FAILURE;
    } catch (...) {
        std::cerr << "Unknown exception!" << std::endl;
        return EXIT_FAILURE;
    }
    
    // ===================
    // = File processing =
    // ===================
    
    // Welcome message
    #ifdef DEBUG
        std::cout << "Dxf Machine started." << std::endl;
    #endif
    
    typedef Machine<> MachineT;

    
    MachineT m;
    MachineT::ModelPtrT model = m.process(input_file);

    std::cout << "Result:" << std::endl;
    std::for_each(model->entities->begin(), model->entities->end(),
            [](const MachineT::ModelT::EntityT::PtrT ent) {
                std::cout << *ent << std::endl;
            });

    return EXIT_SUCCESS;
}
