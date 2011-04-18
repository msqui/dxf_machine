#ifndef __ENTITIES__LWPOLYLINETEST_HPP__
#define __ENTITIES__LWPOLYLINETEST_HPP__

#include <gtest/gtest.h>

#include <sstream>

#include "model/entities/LwPolyline.h"

namespace {

class LwPolylineTest : public ::testing::Test
{
protected:
  void SetUp()
  {
    
  }
  
  std::stringstream sstr;
  model::entities::LwPolyline lw_polyline;
};

TEST_F(LwPolylineTest, ostr)
{
  sstr << lw_polyline;
  ASSERT_EQ("LwPolyline", sstr.str());
}

}

#endif /* end of include guard: __ENTITIES__LWPOLYLINETEST_HPP__ */
