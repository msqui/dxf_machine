/*
 * DxfFileUtils.hpp
 *
 *  Created on: Dec 29, 2009
 *      Author: msqui
 */

#ifndef DXFFILEUTILS_HPP_
#define DXFFILEUTILS_HPP_

#include <iostream>
#include <fstream>
#include <string>
#include <functional>

#include <boost/filesystem.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>
#include <boost/bind.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>

#include "Types/DxfTypes.h"

namespace ep{
namespace util{
namespace file{

typedef boost::shared_ptr<std::fstream> FilePtr; // RAII pattern

/**
 * custom delete functor for RAII shared_ptr
**/
struct close_file : std::unary_function<std::fstream*, void>
{
  void operator() (std::fstream* file)
  {
    if (file->is_open()) {
      file->close();
    }
    
    delete file;
  }
};

/**
 * reads given file and divides it in Code-Value tuples
**/
type::DxfPQueuePtr readFile(const char* filename) throw(std::logic_error)
{
  if (!boost::filesystem::exists(filename) ||
        boost::filesystem::is_directory(filename))
  {
    throw std::logic_error("file doesn't exist");
  }
  
  FilePtr file = FilePtr(new std::fstream(filename, std::ios::in), close_file());

  std::string s_code, s_value;
  int i_code;

  type::DxfPQueuePtr result = boost::make_shared<type::DxfPQueue>();

  while (!file->eof()) {
    getline(*file.get(), s_code);
    boost::trim(s_code);
    try {
      i_code = boost::lexical_cast<int>(s_code);
    }
    catch (boost::bad_lexical_cast) {
      i_code = 0;
    }
    
    if (file->eof()) throw std::logic_error("DXF file corrupted");
    
    getline(*file.get(), s_value);
    boost::trim(s_value);
    
    // There can be empty vars
    // if(boost::empty(s_value)) continue;
    
    result->push(boost::make_shared<type::DxfTuple>(i_code, s_value));
    
    if (s_value == "EOF") break;


  } // end while

  return result;
}

}}}

#endif /* DXFFILEUTILS_HPP_ */
