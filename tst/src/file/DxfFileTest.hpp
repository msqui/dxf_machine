#ifndef __FILE__DXFFILE_HPP__
#define __FILE__DXFFILE_HPP__

#include <gtest/gtest.h>

#include "file/DxfFile.h"
#include "type/types.hpp"
#include "exception/file/file_not_found.h"
#include "exception/dxf/bad_dxf_file.h"

#include "Paths.hpp"

using namespace dxf_machine;

namespace {

class DxfFileTest : public ::testing::Test
{
protected:
    DxfFileTest() {}
};

TEST_F(DxfFileTest, open_file)
{
    file::DxfFile::DxfFilePtrT file_ptr;
    ASSERT_NO_THROW(file_ptr = file::DxfFile::open_file(Paths::GOOD_FILENAME));
    ASSERT_THROW(file_ptr = file::DxfFile::open_file(Paths::BAD_FILENAME),
            exception::file::file_not_found);
}

TEST_F(DxfFileTest, to_queue)
{
    file::DxfFile::DxfFilePtrT file_ptr = file::DxfFile::open_file(Paths::GOOD_FILENAME);
    type::DxfQueuePtrT qp = file_ptr->read_file();
    ASSERT_FALSE(qp->empty());
    type::DxfTupleT tuple_1(0, "SECTION");
    ASSERT_EQ(tuple_1, *qp->front());
    
    file_ptr = file::DxfFile::open_file(Paths::BAD_FILE_FILENAME);
    ASSERT_THROW((void)file_ptr->read_file(),
            exception::dxf::bad_dxf_file);
}

}

#endif /* end of include guard: __FILE__DXFFILE_HPP__ */
