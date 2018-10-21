//
// Created by serj on 20/10/18.
//

#include <gtest/gtest.h>

#include <arm/digraph.hpp>

// BEGIN: ignore the warnings listed below when compiled with clang from here
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wexit-time-destructors"
#pragma clang diagnostic ignored "-Wglobal-constructors"
#endif

using namespace arm;

////////////////////////////////////////////////////////////////////////////////
// Tests
TEST(graph, basic) {
  DiGraph<int, int> g;
}

TEST(graph, add) {
  DiGraph<int, int> g;
  ASSERT_EQ(g.getNodes().size(), 0);
  g.add(0);
  ASSERT_EQ(g.getNodes().size(), 1);
  g.add(1);
  ASSERT_EQ(g.getNodes().size(), 2);
}

TEST(graph, add_duplicate_fail) {
  DiGraph<int, int> g;
  ASSERT_TRUE(g.add(0));
  ASSERT_FALSE(g.add(0));
  ASSERT_TRUE(g.add(1));
  ASSERT_FALSE(g.add(1));
}

TEST(graph, connect) {
  DiGraph<int, int> g;
  g.add(0, 1, 1);
  g.add(0, 2, 2);
  g.add(0, 3, 3);
  g.add(1, 3, 4);
  ASSERT_EQ(g.getNodes().size(), 3);
  ASSERT_EQ(g.getEdges(0).size(), 3);
  ASSERT_EQ(g.getEdges(0).at(1), 1);
  ASSERT_EQ(g.getEdges(0).at(2), 2);
  ASSERT_EQ(g.getEdges(0).at(3), 3);
  ASSERT_EQ(g.getEdges(1).at(3), 4);
}

TEST(graph, get_invalid_edge) {
  DiGraph<int, int> g;
  g.add(0, 1, 2);
  ASSERT_THROW(g.getEdges(10), std::out_of_range);
}

TEST(graph, is_connected) {
  DiGraph<int, int> g;
  g.add(0);
  g.add(1, 2, 2);
  ASSERT_TRUE(g.isConnected(1, 2));
  ASSERT_FALSE(g.isConnected(0, 1));
}

TEST(graph, get_edge) {
  DiGraph<int, int> g;
  g.add(1, 2, 2);
  g.add(1, 3, 7);
  ASSERT_EQ(g.getEdge(1, 2), 2);
  ASSERT_EQ(g.getEdge(1, 3), 7);
}
