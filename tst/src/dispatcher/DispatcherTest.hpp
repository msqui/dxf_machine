#ifndef __DISPATCHER__DISPATCHERTEST_HPP__
#define __DISPATCHER__DISPATCHERTEST_HPP__

#include <gtest/gtest.h>

#include <memory>
#include <stdexcept>

#include "file/DxfFile.h"
#include "dispatcher/Dispatcher.h"

using namespace dxf_machine;

namespace {

class DispatcherTest : public ::testing::Test
{
    typedef std::unique_ptr<dispatcher::Dispatcher> DispPtrT;

protected:
    virtual void SetUp()
    {
        file::DxfFile::DxfFilePtrT file_ptr =
            file::DxfFile::open_file(Paths::GOOD_FILENAME);
        d_ptr = DispPtrT(new dispatcher::Dispatcher(file_ptr->read_file()));
    }

    DispPtrT d_ptr;
  
private:
    file::DxfFile::DxfFilePtrT file_ptr;
};

TEST_F(DispatcherTest, get)
{
    type::DxfTupleT tuple(0, "SECTION");
    type::DxfTuplePtrT tuple_ptr = d_ptr->get();
    ASSERT_EQ(tuple, *tuple_ptr);
    
    while (!d_ptr->empty()) {
        ++(*d_ptr);
    }
    ASSERT_THROW(d_ptr->get(), std::out_of_range);
}

TEST_F(DispatcherTest, empty)
{
    dispatcher::Dispatcher d(type::DxfQueuePtrT(new type::DxfQueueT));
    ASSERT_TRUE(d.empty());
    ASSERT_FALSE(d_ptr->empty());
}

TEST_F(DispatcherTest, pre_inc)
{
    type::DxfTupleT tuple(2, "HEADER");
    ++(*d_ptr);
    ASSERT_EQ(tuple, *(d_ptr->get()));
    
    while (!d_ptr->empty()) {
        ++(*d_ptr);
    }
    ASSERT_THROW( ++(*d_ptr), std::out_of_range);
}

TEST_F(DispatcherTest, inc_post)
{
    type::DxfTupleT tuple_1(0, "SECTION");
    type::DxfTupleT tuple_2(2, "HEADER");
    ASSERT_EQ(tuple_1, *(*d_ptr)++);
    ASSERT_EQ(tuple_2, *(d_ptr->get()));
    
    while (!d_ptr->empty()) {
        (*d_ptr)++;
    }
    ASSERT_THROW( (*d_ptr)++, std::out_of_range );
}

}

#endif /* end of include guard: __DISPATCHER__DISPATCHERTEST_HPP__ */
