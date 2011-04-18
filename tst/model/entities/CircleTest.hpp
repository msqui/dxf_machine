#ifndef __ENTITIES__CIRCLETEST_HPP__
#define __ENTITIES__CIRCLETEST_HPP__

#include <gtest/gtest.h>

#include <sstream>

#include "model/entities/Circle.h"

namespace {

class CircleTest : public ::testing::Test
{
protected:
  void SetUp()
  {
    
  }
  
  std::stringstream sstr;
  model::entities::Circle circle;
};

TEST_F(CircleTest, ostr)
{
  sstr << circle;
  ASSERT_EQ("Circle", sstr.str());
}

}

#endif /* end of include guard: __ENTITIES__CIRCLETEST_HPP__ */
