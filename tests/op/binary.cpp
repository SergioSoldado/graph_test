//
// Created by serj on 20/10/18.
//

#include <iostream>

#include <gtest/gtest.h>

#include <arm/op/binary.hpp>

// BEGIN: ignore the warnings listed below when compiled with clang from here
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wexit-time-destructors"
#pragma clang diagnostic ignored "-Wglobal-constructors"
#endif

using namespace arm;

////////////////////////////////////////////////////////////////////////////////
// Tests
TEST(binary_operations, addition) {
  {
    op::BinaryOp<double> oper(op::add<float>);
    ASSERT_DOUBLE_EQ(oper(1.5, 4.0), 5.5);
  }
  {
    op::BinaryOp<int> oper(op::add<int>);
    ASSERT_EQ(oper(1, 4), 5);
  }
}

TEST(binary_operations, subtraction) {
  {
    op::BinaryOp<double> oper(op::subtract<float>);
    ASSERT_DOUBLE_EQ(1.0, oper(5.5, 4.5));
  }
  {
    op::BinaryOp<int> oper(op::subtract<int>);
    ASSERT_EQ(oper(4, 3), 1);
  }
}

TEST(binary_operations, multiplication) {
  {
    op::BinaryOp<double> oper(op::multiply<float>);
    ASSERT_DOUBLE_EQ(oper(3.5, 2.0), 7.0);
  }
  {
    op::BinaryOp<int> oper(op::multiply<int>);
    ASSERT_EQ(oper(4, 3), 12);
  }
}
