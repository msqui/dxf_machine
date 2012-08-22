#ifndef __PROCESSOR__STREAMPROCESSORTEST_HPP__
#define __PROCESSOR__STREAMPROCESSORTEST_HPP__

#include <gtest/gtest.h>

#include <iostream>
#include <memory>
#include <sstream>
#include <string>

#include "processor/StreamProcessor.h"

#include "type/types.hpp"
#include "file/DxfFile.h"
#include "dispatcher/Dispatcher.h"

#include "Paths.hpp"

using namespace dxf_machine;

namespace {

class StreamProcessorTest : public ::testing::Test
{
    typedef std::unique_ptr<dispatcher::Dispatcher> DispPtrT;
    typedef std::unique_ptr<processor::StreamProcessor> ProcPtrT;
  
protected:
    void SetUp()
    {
        type::DxfQueuePtrT tuples;
        file::DxfFile::DxfFilePtrT file_ptr = file::DxfFile::open_file(Paths::GOOD_FILENAME);
        tuples = file_ptr->read_file();
        d_ptr = DispPtrT(new dispatcher::Dispatcher(tuples));
        p_ptr = ProcPtrT(new processor::StreamProcessor(sstr));
    }
    
    std::stringstream sstr;
    DispPtrT d_ptr;
    ProcPtrT p_ptr;
};

TEST_F(StreamProcessorTest, process)
{
    p_ptr->start(*d_ptr);
    
    std::string str;
    std::getline(sstr, str);
    
    ASSERT_EQ("(0 ; SECTION)", str);
}

}

#endif /* end of include guard: __PROCESSOR__STREAMPROCESSORTEST_HPP__ */
