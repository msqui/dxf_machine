#include <gtest/gtest.h>

#include "type/CVTupleTest.hpp"
#include "file/DxfFileTest.hpp"
#include "dispatcher/DispatcherTest.hpp"
#include "processor/StreamProcessorTest.hpp"

#include "model/entities/CircleTest.hpp"
#include "model/entities/LwPolylineTest.hpp"
#include "model/entities/LineTest.hpp"

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    
    return RUN_ALL_TESTS();
}
