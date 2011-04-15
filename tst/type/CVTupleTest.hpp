#ifndef __FILE__CVTUPLETEST_HPP__
#define __FILE__CVTUPLETEST_HPP__

#include <gtest/gtest.h>

#include <string>
#include <sstream>

#include "type/CVTuple.hpp"
#include "type/types.hpp"

namespace {

class CVTupleTest : public ::testing::Test
{
protected:
  CVTupleTest() {}
};

TEST_F(CVTupleTest, getters)
{
  type::DxfTupleT tuple(0, "ONE");
  ASSERT_EQ(0, tuple.code());
  ASSERT_EQ("ONE", tuple.value());
}

TEST_F(CVTupleTest, eq_op)
{
  type::DxfTupleT tuple_1(0, "ONE");
  type::DxfTupleT tuple_2(0, "ONE");
  type::DxfTupleT tuple_3(1, "ONE");
  type::DxfTupleT tuple_4(0, "TWO");
  type::DxfTupleT tuple_5(10, "TEN");
  
  ASSERT_TRUE(tuple_1 == tuple_2);
  ASSERT_FALSE(tuple_1 == tuple_3);
  ASSERT_FALSE(tuple_1 == tuple_4);
  ASSERT_FALSE(tuple_1 == tuple_5);
}

TEST_F(CVTupleTest, less_op)
{
  type::DxfTupleT tuple_1(0, "ONE");
  type::DxfTupleT tuple_2(0, "ONE");
  type::DxfTupleT tuple_3(1, "ONE");
  type::DxfTupleT tuple_4(0, "TWO");
  type::DxfTupleT tuple_5(10, "TEN");
  
  ASSERT_FALSE(tuple_1 < tuple_2);
  ASSERT_TRUE(tuple_1 < tuple_3);
  ASSERT_TRUE(tuple_1 < tuple_4);
  ASSERT_FALSE(tuple_5 < tuple_1);
}

TEST_F(CVTupleTest, string_cast)
{
  type::DxfTupleT tuple_1(0, "ONE");
  ASSERT_EQ("(0 ; ONE)", static_cast<std::string>(tuple_1));
}

TEST_F(CVTupleTest, to_stream)
{
  type::DxfTupleT tuple_1(0, "ONE");
  
  std::stringstream sstr;
  sstr << tuple_1;
  ASSERT_EQ("(0 ; ONE)", sstr.str());
}

}

#endif /* end of include guard: __FILE__CVTUPLETEST_HPP__ */
