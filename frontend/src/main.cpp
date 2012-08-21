#include <iostream>
#include <cstdlib>
#include <string>
#include <memory>
#include <exception>
#include <algorithm>

#include "util/Util.h"
#include "exception/silent_exit.h"
namespace f = dm::frontend;

#include "type/types.hpp"
#include "file/DxfFile.h"
#include "dispatcher/Dispatcher.h"
#include "processor/StreamProcessor.h"
#include "processor/StatefulProcessor.h"

#include "model/Model.h"
#include "model/entities/Entity.h"

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
    
    // Get tuples from file
    std::auto_ptr<type::DxfQueueT> tuples;
    try {
        std::auto_ptr<file::DxfFile> file_ptr = file::DxfFile::open_file(input_file);
        tuples = file_ptr->read_file();
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    
    // Process tuples
    dispatcher::Dispatcher d(tuples);
    // processor::StreamProcessor p(std::cout);
    processor::StatefulProcessor p;
    p.start(d);
    
    // Show model
    model::Model* model = p.get_model();
    std::cout << "Result:" << std::endl;
    std::for_each(model->entities()->begin(), model->entities()->end(),
            [](const model::entities::Entity& ent) {
                std::cout << ent << std::endl;
            });
    
    return EXIT_SUCCESS;
}
