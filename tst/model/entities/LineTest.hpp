#ifndef __ENTITIES__LINETEST_HPP__
#define __ENTITIES__LINETEST_HPP__

#include <gtest/gtest.h>

#include <sstream>

#include "model/entities/Line.h"

namespace {

class LineTest : public ::testing::Test
{
protected:
  void SetUp()
  {
    
  }
  
  std::stringstream sstr;
  model::entities::Line line;
};

TEST_F(LineTest, ostr)
{
  sstr << line;
  ASSERT_EQ("Line", sstr.str());
}

}

#endif /* end of include guard: __ENTITIES__LINETEST_HPP__ */