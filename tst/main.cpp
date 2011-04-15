#include <gtest/gtest.h>

#include "type/CVTupleTest.hpp"
#include "file/DxfFileTest.hpp"
#include "dispatcher/DispatcherTest.hpp"

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  
  return RUN_ALL_TESTS();
}
