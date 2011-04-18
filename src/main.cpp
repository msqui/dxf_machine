#include <iostream>
#include <cstdlib>
#include <string>
#include <memory>
#include <stdexcept>
#include <functional>
#include <algorithm>

#include <boost/program_options.hpp>
namespace po = boost::program_options;

#include "util/Messages.hpp"
#include "type/types.hpp"
#include "file/DxfFile.h"
#include "dispatcher/Dispatcher.h"
#include "processor/StreamProcessor.h"
#include "processor/StatefulProcessor.h"

#include "model/Model.h"
#include "model/entities/Entity.h"

// ======================
// = Usage help message =
// ======================
void usage(const std::string& message, const po::options_description& desc)
{
  std::cout << std::endl
            << message
            << std::endl;
  
  std::cout << desc << std::endl;
}

// ========================
// = Entity print functor =
// ========================
struct print_entity : public std::unary_function<model::entities::Entity, void>
{
  void operator() (const model::entities::Entity& ent)
  {
    std::cout << ent << std::endl;
  }
};

// ================
// = Main program =
// ================
int main(int argc, char **argv)
{
  // ==================
  // = Config options =
  // ==================
  std::string input_file;
  
  // ===========================
  // = Command line processing =
  // ===========================
  try {
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
    
    if(vm.count("help"))
    {
      usage(util::Messages::usage, desc);
      return EXIT_SUCCESS;
    }
    if(vm.count("version"))
    {
      std::cout << "dxf_machine version " << util::Messages::version << std::endl;
      return EXIT_SUCCESS;
    }
    
    if(!vm.count("input-file"))
    {
      std::cerr << util::Messages::no_files_to_process << std::endl;
      return EXIT_FAILURE;
    }
  }
  catch (const std::exception& exc) {
    std::cerr << "Error: " << exc.what() << std::endl;
    return EXIT_FAILURE;
  }
  catch (...) {
    std::cerr << "Unknown exception!" << std::endl;
    return EXIT_FAILURE;
  }
  
  // ===================
  // = File processing =
  // ===================
  
  // Welcome message
  std::cout << "Dxf Machine started." << std::endl;
  
  // Get tuples from file
  std::auto_ptr<type::DxfQueueT> tuples;
  try {
    std::auto_ptr<file::DxfFile> file_ptr = file::DxfFile::open_file(input_file);
    tuples = file_ptr->read_file();
  }
  catch (const std::exception& e) {
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
  std::for_each(model->entities()->begin(), model->entities()->end(), print_entity());
  
  return EXIT_SUCCESS;
}
