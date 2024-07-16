
#include "test_main.h"

TEST(ListTest, constructor1) { s21::List<int> List(6); }

TEST(ListTest, constructor3) {
  s21::List<int> List1(19);

  EXPECT_EQ(List1.size(), 19);
  List1.clear();
  EXPECT_EQ(List1.size(), 0);
}

TEST(ListTest, constructor4) {
  ASSERT_THROW(s21::List<int> myList(0), std::out_of_range);
}

TEST(ListTest, constructor5) {
  ASSERT_THROW(s21::List<int> myList(-2), std::out_of_range);
}

TEST(ListTest, constructor6) {
  s21::List<int> myList = {1, 2, 3, 4, 5, 6};
  EXPECT_EQ(myList.size(), 6);
  ASSERT_EQ(myList.front(), 1);
  ASSERT_EQ(myList.back(), 6);
  int expectedValue = 1;
  for (const auto& item : myList) {
    ASSERT_EQ(item, expectedValue);
    expectedValue++;
  }
}

TEST(ListTest, constructor7) {
  s21::List<int> List = {};
  EXPECT_EQ(List.size(), 0);
  ASSERT_THROW(List.front(), std::out_of_range);
  ASSERT_THROW(List.back(), std::out_of_range);
}

TEST(ListTest, constructor8) {
  s21::List<int> List1 = {1, 2, 3, 4, 5, 6};
  s21::List<int> List2(List1);
  ASSERT_EQ(List2.front(), 1);
  ASSERT_EQ(List2.back(), 6);
  int expectedValue = 1;
  for (const auto& item : List2) {
    ASSERT_EQ(item, expectedValue);
    expectedValue++;
  }
}

TEST(ListTest, constructor9) {
  s21::List<int> List1 = {};
  EXPECT_EQ(List1.size(), 0);
  ASSERT_THROW(List1.front(), std::out_of_range);
  ASSERT_THROW(List1.back(), std::out_of_range);
  s21::List<int> List2(List1);
  EXPECT_EQ(List2.size(), 0);
  ASSERT_THROW(List2.front(), std::out_of_range);
  ASSERT_THROW(List2.back(), std::out_of_range);
}

TEST(ListTest, constructor10) {
  s21::List<int> List1 = {};
  s21::List<int> List2(std::move(List1));
  EXPECT_EQ(List1.size(), 0);
  ASSERT_THROW(List1.front(), std::out_of_range);
  ASSERT_THROW(List1.back(), std::out_of_range);
  EXPECT_EQ(List2.size(), 0);
  ASSERT_THROW(List2.front(), std::out_of_range);
  ASSERT_THROW(List2.back(), std::out_of_range);
}

TEST(ListTest, constructor11) {
  s21::List<int> List1 = {1, 2, 3, 4, 5, 6};
  s21::List<int> List2(std::move(List1));
  EXPECT_EQ(List1.size(), 0);
  ASSERT_THROW(List1.front(), std::out_of_range);
  ASSERT_THROW(List1.back(), std::out_of_range);
  ASSERT_EQ(List2.front(), 1);
  ASSERT_EQ(List2.back(), 6);
  int expectedValue = 1;
  for (const auto& item : List2) {
    ASSERT_EQ(item, expectedValue);
    expectedValue++;
  };
}

TEST(ListTest, frontback) {
  s21::List<int> List1 = {};
  s21::List<int> List2 = {914, 21, 36, 4, 55, 74};
  EXPECT_EQ(List1.size(), 0);
  ASSERT_THROW(List1.front(), std::out_of_range);
  ASSERT_THROW(List1.back(), std::out_of_range);
  ASSERT_EQ(List2.front(), 914);
  ASSERT_EQ(List2.back(), 74);
}

TEST(ListTest, beginend) {
  s21::List<int> List1 = {};
  EXPECT_EQ(List1.size(), 0);
  ASSERT_EQ(List1.begin(), nullptr);
  ASSERT_EQ(List1.end(), nullptr);

  s21::List<int> List2 = {914, 21, 36, 4, 55, 74};
  ASSERT_EQ(*(List2.begin()), 914);
  ASSERT_EQ(List2.end(), nullptr);
}

TEST(ListTest, empty) {
  s21::List<int> List1 = {};
  ASSERT_EQ(List1.empty(), true);

  s21::List<int> List2 = {914, 21, 36, 4, 55, 74};
  ASSERT_EQ(List2.empty(), false);
}

TEST(ListTest, operator1) {
  s21::List<int> List2 = {914, 21, 36, 4, 55, 74};
  s21::List<int> List1 = std::move(List2);
  EXPECT_EQ(List2.size(), 0);
  ASSERT_THROW(List2.front(), std::out_of_range);
  ASSERT_THROW(List2.back(), std::out_of_range);
  ASSERT_EQ(List1.front(), 914);
  ASSERT_EQ(List1.back(), 74);
  EXPECT_EQ(List1.size(), 6);
}

TEST(max_size_test, TEST_1) {
  s21::List<char> B;
  size_t mine = B.max_size();
  std::list<char> C;
  size_t their = C.max_size();
  EXPECT_EQ(mine, their);
}

TEST(ListTest, push_back1) {
  s21::List<int> List;
  List.push_back(914);
  List.push_back(21);
  List.push_back(36);
  List.push_back(4);
  List.push_back(55);
  List.push_back(74);

  EXPECT_EQ(List.size(), 6);
  EXPECT_EQ(List.front(), 914);
  EXPECT_EQ(List.back(), 74);
}

TEST(ListTest, push_back2) {
  s21::List<int> List = {3, 6, 1};
  List.push_back(914);
  List.push_back(21);
  List.push_back(36);
  List.push_back(4);
  List.push_back(55);
  List.push_back(74);
  EXPECT_EQ(List.size(), 9);
  EXPECT_EQ(List.front(), 3);
  EXPECT_EQ(List.back(), 74);
}

TEST(ListTest, push_front1) {
  s21::List<int> List;
  List.push_front(74);
  List.push_front(55);
  List.push_front(4);
  List.push_front(36);
  List.push_front(21);
  List.push_front(914);

  EXPECT_EQ(List.size(), 6);
  EXPECT_EQ(List.front(), 914);
  EXPECT_EQ(List.back(), 74);
}

TEST(ListTest, push_front2) {
  s21::List<int> List = {3, 6, 1};
  List.push_front(74);
  List.push_front(55);
  List.push_front(4);
  List.push_front(36);
  List.push_front(21);
  List.push_front(914);

  EXPECT_EQ(List.size(), 9);
  EXPECT_EQ(List.front(), 914);
  EXPECT_EQ(List.back(), 1);
}

TEST(ListTest, pop_back1) {
  s21::List<int> List = {3, 6, 1};
  List.pop_back();

  EXPECT_EQ(List.size(), 2);
  EXPECT_EQ(List.front(), 3);
  EXPECT_EQ(List.back(), 6);
}

TEST(ListTest, pop_back2) {
  s21::List<int> List = {3};
  List.pop_back();

  EXPECT_EQ(List.size(), 0);
  ASSERT_THROW(List.front(), std::out_of_range);
  ASSERT_THROW(List.back(), std::out_of_range);
}

TEST(ListTest, pop_back3) {
  s21::List<int> List = {};
  ASSERT_THROW(List.pop_back(), std::out_of_range);
}

TEST(ListTest, pop_front1) {
  s21::List<int> List = {3, 6, 1};
  List.pop_front();

  EXPECT_EQ(List.size(), 2);
  EXPECT_EQ(List.front(), 6);
  EXPECT_EQ(List.back(), 1);
}

TEST(ListTest, pop_front2) {
  s21::List<int> List = {3};
  List.pop_front();

  EXPECT_EQ(List.size(), 0);
  ASSERT_THROW(List.front(), std::out_of_range);
  ASSERT_THROW(List.back(), std::out_of_range);
}

TEST(ListTest, pop_front3) {
  s21::List<int> List = {};
  ASSERT_THROW(List.pop_front(), std::out_of_range);
}

TEST(ListTest, erase1) {
  s21::List<int> List = {3, 6, 1};
  List.erase(List.begin());
  EXPECT_EQ(List.size(), 2);
  EXPECT_EQ(List.front(), 6);
  EXPECT_EQ(List.back(), 1);
}

TEST(ListTest, erase2) {
  s21::List<int> List = {};
  List.erase(List.begin());
  EXPECT_EQ(List.size(), 0);
  ASSERT_THROW(List.front(), std::out_of_range);
  ASSERT_THROW(List.back(), std::out_of_range);
}

TEST(ListTest, erase3) {
  s21::List<int> List = {4};
  List.erase(List.begin());
  EXPECT_EQ(List.size(), 0);
  ASSERT_THROW(List.front(), std::out_of_range);
  ASSERT_THROW(List.back(), std::out_of_range);
}

TEST(ListTest, erase4) {
  s21::List<int> List = {4, 5, 8, 2, 44, 1, 2, 6};
  List.erase(List.begin());
  EXPECT_EQ(List.size(), 7);
  EXPECT_EQ(List.front(), 5);
  EXPECT_EQ(List.back(), 6);
}

TEST(ListTest, erase5) {
  s21::List<int> List = {4, 5, 8, 2, 44, 1, 2, 6};
  List.erase(List.end());
  EXPECT_EQ(List.size(), 8);
  EXPECT_EQ(List.front(), 4);
  EXPECT_EQ(List.back(), 6);
}

TEST(ListTest, erase6) {
  s21::List<int> List = {4, 5, 8, 2, 44, 1, 2, 6};
  s21::List<int>::iterator it = List.begin();
  ++it;
  ++it;
  List.erase(it);
  s21::List<int>::iterator newit = List.begin();
  ++newit;
  ++newit;
  EXPECT_EQ(List.size(), 7);
  EXPECT_EQ(*newit, 2);
  EXPECT_EQ(List.front(), 4);
  EXPECT_EQ(List.back(), 6);
}

TEST(ListTest, swap1) {
  s21::List<int> List1 = {4, 5, 8, 2, 44, 1, 2, 6};
  s21::List<int> List2 = {88, 4444};
  List1.swap(List2);
  EXPECT_EQ(List1.size(), 2);
  EXPECT_EQ(List2.size(), 8);
  EXPECT_EQ(List1.front(), 88);
  EXPECT_EQ(List1.back(), 4444);
  EXPECT_EQ(List2.front(), 4);
  EXPECT_EQ(List2.back(), 6);
}

TEST(ListTest, swap2) {
  s21::List<int> List1 = {4, 5, 8, 2, 44, 1, 2, 6};
  s21::List<int> List2 = {};
  List1.swap(List2);
  EXPECT_EQ(List1.size(), 0);
  EXPECT_EQ(List2.size(), 8);
  ASSERT_THROW(List1.front(), std::out_of_range);
  ASSERT_THROW(List1.back(), std::out_of_range);
  EXPECT_EQ(List2.front(), 4);
  EXPECT_EQ(List2.back(), 6);
}

TEST(ListTest, swap3) {
  s21::List<int> List1 = {5};
  s21::List<int> List2 = {8};
  List1.swap(List2);
  EXPECT_EQ(List1.size(), 1);
  EXPECT_EQ(List2.size(), 1);
  EXPECT_EQ(List1.front(), 8);
  EXPECT_EQ(List1.back(), 8);
  EXPECT_EQ(List2.front(), 5);
  EXPECT_EQ(List2.back(), 5);
}

TEST(ListTest, swap4) {
  s21::List<int> List1 = {};
  s21::List<int> List2 = {};
  List1.swap(List2);
  EXPECT_EQ(List1.size(), 0);
  EXPECT_EQ(List2.size(), 0);
  ASSERT_THROW(List1.front(), std::out_of_range);
  ASSERT_THROW(List1.back(), std::out_of_range);
  ASSERT_THROW(List2.front(), std::out_of_range);
  ASSERT_THROW(List2.back(), std::out_of_range);
}

TEST(ListTest, merge1) {
  s21::List<int> List1 = {};
  s21::List<int> List2 = {};
  List1.merge(List2);
  EXPECT_EQ(List1.size(), 0);
  EXPECT_EQ(List2.size(), 0);
  ASSERT_THROW(List1.front(), std::out_of_range);
  ASSERT_THROW(List1.back(), std::out_of_range);
  ASSERT_THROW(List2.front(), std::out_of_range);
  ASSERT_THROW(List2.back(), std::out_of_range);
}

TEST(ListTest, merge2) {
  s21::List<int> List1 = {1, 2, 3, 4, 5};
  s21::List<int> List2 = {6, 7, 8, 9, 10, 11, 12, 13, 14};
  List1.merge(List2);
  EXPECT_EQ(List1.size(), 14);
  EXPECT_EQ(List2.size(), 9);
  EXPECT_EQ(List1.front(), 1);
  EXPECT_EQ(List1.back(), 14);
  EXPECT_EQ(List2.front(), 6);
  EXPECT_EQ(List2.back(), 14);
}

TEST(ListTest, merge3) {
  s21::List<int> List1 = {};
  s21::List<int> List2 = {1, 2, 3, 4, 5};
  List1.merge(List2);
  EXPECT_EQ(List1.size(), 5);
  EXPECT_EQ(List2.size(), 5);
  EXPECT_EQ(List1.front(), 1);
  EXPECT_EQ(List1.back(), 5);
  EXPECT_EQ(List2.front(), 1);
  EXPECT_EQ(List2.back(), 5);
}

TEST(ListTest, merge4) {
  s21::List<int> List1 = {1, 2, 3, 4, 5};
  s21::List<int> List2 = {};
  List1.merge(List2);
  EXPECT_EQ(List1.size(), 5);
  EXPECT_EQ(List2.size(), 0);
  EXPECT_EQ(List1.front(), 1);
  EXPECT_EQ(List1.back(), 5);
  ASSERT_THROW(List2.front(), std::out_of_range);
  ASSERT_THROW(List2.back(), std::out_of_range);
}

TEST(ListTest, merge6) {
  s21::List<int> List1 = {1, 2, 3, 4, 5};
  s21::List<int> List2 = {4};
  List1.merge(List2);
  EXPECT_EQ(List1.size(), 6);
  EXPECT_EQ(List2.size(), 1);
  EXPECT_EQ(List1.front(), 1);
  EXPECT_EQ(List1.back(), 5);
  EXPECT_EQ(List2.front(), 4);
  EXPECT_EQ(List2.back(), 4);
}

TEST(ListTest, splice1) {
  s21::List<int> List1 = {1, 2, 3, 4, 5};
  s21::List<int> List2 = {57};
  s21::List<int>::const_iterator run = List1.cbegin();
  List1.splice(run, List2);
  EXPECT_EQ(List1.size(), 6);
  EXPECT_EQ(List2.size(), 0);
  ASSERT_THROW(List2.front(), std::out_of_range);
  ASSERT_THROW(List2.back(), std::out_of_range);
  EXPECT_EQ(List1.front(), 57);
  EXPECT_EQ(List1.back(), 5);
}

TEST(ListTest, splice2) {
  s21::List<int> List1 = {1, 2, 3, 4, 5};
  s21::List<int> List2 = {57};
  s21::List<int>::const_iterator run = List1.cend();
  List1.splice(run, List2);
  EXPECT_EQ(List1.size(), 6);
  EXPECT_EQ(List2.size(), 0);
  ASSERT_THROW(List2.front(), std::out_of_range);
  ASSERT_THROW(List2.back(), std::out_of_range);
  EXPECT_EQ(List1.front(), 1);
  EXPECT_EQ(List1.back(), 57);
}

TEST(ListTest, splice3) {
  s21::List<int> List1 = {1, 2, 3, 4, 5};
  s21::List<int> List2 = {57, 5, 222};
  s21::List<int>::const_iterator run = List1.cend();
  List1.splice(run, List2);
  EXPECT_EQ(List1.size(), 8);
  EXPECT_EQ(List2.size(), 0);
  ASSERT_THROW(List2.front(), std::out_of_range);
  ASSERT_THROW(List2.back(), std::out_of_range);
  EXPECT_EQ(List1.front(), 1);
  EXPECT_EQ(List1.back(), 222);
}

TEST(ListTest, splice4) {
  s21::List<int> List1 = {1, 2, 3, 4, 5};
  s21::List<int> List2 = {57, 5, 222};
  s21::List<int>::const_iterator run = List1.cbegin();
  List1.splice(run, List2);
  EXPECT_EQ(List1.size(), 8);
  EXPECT_EQ(List2.size(), 0);
  ASSERT_THROW(List2.front(), std::out_of_range);
  ASSERT_THROW(List2.back(), std::out_of_range);
  EXPECT_EQ(List1.front(), 57);
  EXPECT_EQ(List1.back(), 5);
}

TEST(ListTest, splice5) {
  s21::List<int> List1 = {};
  s21::List<int> List2 = {57, 5, 222};
  s21::List<int>::const_iterator run = List1.cbegin();
  ASSERT_THROW(List1.splice(run, List2), std::out_of_range);
}

TEST(ListTest, splice6) {
  s21::List<int> List2 = {57, 5, 222};
  s21::List<int>::const_iterator run = List2.cbegin();
  ASSERT_THROW(List2.splice(run, List2), std::out_of_range);
}

TEST(ListTest, splice7) {
  s21::List<int> List2 = {};
  s21::List<int>::const_iterator run = List2.cbegin();
  ASSERT_THROW(List2.splice(run, List2), std::out_of_range);
}

TEST(ListTest, insert1) {
  s21::List<int> List1 = {1, 2, 3, 4, 5};
  auto it = List1.begin();
  it = List1.insert(it, 10);
  EXPECT_EQ(List1.size(), 6);
  EXPECT_EQ(List1.front(), 10);
  EXPECT_EQ(List1.back(), 5);
}

TEST(ListTest, insert2) {
  s21::List<int> List1 = {1, 2, 3, 4, 5};
  auto it = List1.end();
  it = List1.insert(it, 10);
  EXPECT_EQ(List1.size(), 6);
  EXPECT_EQ(List1.front(), 1);
  EXPECT_EQ(List1.back(), 10);
}

TEST(ListTest, insert3) {
  s21::List<int> List1 = {};
  auto it = List1.end();
  it = List1.insert(it, 10);
  EXPECT_EQ(List1.size(), 1);
  EXPECT_EQ(List1.front(), 10);
  EXPECT_EQ(List1.back(), 10);
}

TEST(ListTest, insert4) {
  s21::List<int> List1 = {};
  auto it = List1.begin();
  it = List1.insert(it, 10);
  EXPECT_EQ(List1.size(), 1);
  EXPECT_EQ(List1.front(), 10);
  EXPECT_EQ(List1.back(), 10);
}

TEST(ListTest, insert5) {
  s21::List<int> List1 = {3};
  auto it = List1.end();
  it = List1.insert(it, 10);
  EXPECT_EQ(List1.size(), 2);
  EXPECT_EQ(List1.front(), 3);
  EXPECT_EQ(List1.back(), 10);
}

TEST(ListTest, insert6) {
  s21::List<int> List1 = {3};
  auto it = List1.begin();
  it = List1.insert(it, 10);
  EXPECT_EQ(List1.size(), 2);
  EXPECT_EQ(List1.front(), 10);
  EXPECT_EQ(List1.back(), 3);
}

TEST(ListTest, reverse1) {
  s21::List<int> List = {1, 2, 3, 4, 5};
  List.reverse();
  EXPECT_EQ(List.size(), 5);
  EXPECT_EQ(List.front(), 5);
  EXPECT_EQ(List.back(), 1);

  auto it = List.begin();
  EXPECT_EQ(*it, 5);
  ++it;
  EXPECT_EQ(*it, 4);
  ++it;
  EXPECT_EQ(*it, 3);
  ++it;
  EXPECT_EQ(*it, 2);
  ++it;
  EXPECT_EQ(*it, 1);
}

TEST(ListTest, reverse2) {
  s21::List<int> List = {};
  List.reverse();
  EXPECT_EQ(List.size(), 0);
  ASSERT_THROW(List.front(), std::out_of_range);
  ASSERT_THROW(List.back(), std::out_of_range);
}

TEST(ListTest, unique1) {
  s21::List<int> List = {1, 2, 2, 3, 4, 4, 5, 5};
  List.unique();
  EXPECT_EQ(List.size(), 5);
  auto it = List.begin();
  EXPECT_EQ(*it, 1);
  ++it;
  EXPECT_EQ(*it, 2);
  ++it;
  EXPECT_EQ(*it, 3);
  ++it;
  EXPECT_EQ(*it, 4);
  ++it;
  EXPECT_EQ(*it, 5);
}

TEST(ListTest, unique2) {
  s21::List<int> List = {};
  List.unique();
  EXPECT_EQ(List.size(), 0);
  ASSERT_THROW(List.front(), std::out_of_range);
  ASSERT_THROW(List.back(), std::out_of_range);
}

TEST(ListTest, unique3) {
  s21::List<int> List = {1, 1};
  List.unique();
  EXPECT_EQ(List.size(), 1);
  EXPECT_EQ((List.front()), 1);
  EXPECT_EQ((List.back()), 1);
}

TEST(ListTest, unique4) {
  s21::List<int> List = {1, 1, 2, 1, 4, 1, 1, 1};
  List.unique();
  EXPECT_EQ(List.size(), 5);
  auto it = List.begin();
  EXPECT_EQ(*it, 1);
  ++it;
  EXPECT_EQ(*it, 2);
  ++it;
  EXPECT_EQ(*it, 1);
  ++it;
  EXPECT_EQ(*it, 4);
  ++it;
  EXPECT_EQ(*it, 1);
}

#include <gtest/gtest.h>

TEST(ListTest, sort1) {
  s21::List<int> List = {1, 5, 3, 2, 4};
  List.sort();
  EXPECT_EQ(List.size(), 5);
  EXPECT_EQ((List.front()), 1);
  EXPECT_EQ((List.back()), 5);
  auto it = List.begin();
  EXPECT_EQ(*it, 1);
  ++it;
  EXPECT_EQ(*it, 2);
  ++it;
  EXPECT_EQ(*it, 3);
  ++it;
  EXPECT_EQ(*it, 4);
  ++it;
  EXPECT_EQ(*it, 5);
}

TEST(ListTest, sort2) {
  s21::List<int> List = {};
  List.sort();
  EXPECT_EQ(List.size(), 0);
  ASSERT_THROW(List.front(), std::out_of_range);
  ASSERT_THROW(List.back(), std::out_of_range);
}

TEST(ListTest, sort3) {
  s21::List<int> List = {8, 33, 1, 1, 4, 3, 0};
  List.sort();
  EXPECT_EQ(List.size(), 7);
  EXPECT_EQ((List.front()), 0);
  EXPECT_EQ((List.back()), 33);
  auto it = List.begin();
  EXPECT_EQ(*it, 0);
  ++it;
  EXPECT_EQ(*it, 1);
  ++it;
  EXPECT_EQ(*it, 1);
  ++it;
  EXPECT_EQ(*it, 3);
  ++it;
  EXPECT_EQ(*it, 4);
  ++it;
  EXPECT_EQ(*it, 8);
  ++it;
  EXPECT_EQ(*it, 33);
}

TEST(ListTest, sort4) {
  s21::List<int> List = {8, 33, 1, 1, 4, 3, 0};
  List.sort();
  EXPECT_EQ(List.size(), 7);
  EXPECT_EQ((List.front()), 0);
  EXPECT_EQ((List.back()), 33);
  auto it = List.begin();
  EXPECT_EQ(*it, 0);
  ++it;
  EXPECT_EQ(*it, 1);
  ++it;
  EXPECT_EQ(*it, 1);
  ++it;
  EXPECT_EQ(*it, 3);
  ++it;
  EXPECT_EQ(*it, 4);
  ++it;
  EXPECT_EQ(*it, 8);
  ++it;
  EXPECT_EQ(*it, 33);
}

TEST(ListTest, sort5) {
  s21::List<int> List = {1};
  List.sort();
  EXPECT_EQ(List.size(), 1);
  EXPECT_EQ((List.front()), 1);
  EXPECT_EQ((List.back()), 1);
}

TEST(ListTest, sort6) {
  s21::List<int> List = {1, 2, 3, 98, 4};
  List.sort();
  EXPECT_EQ(List.size(), 5);
  EXPECT_EQ((List.front()), 1);
  EXPECT_EQ((List.back()), 98);
  auto it = List.begin();
  EXPECT_EQ(*it, 1);
  ++it;
  EXPECT_EQ(*it, 2);
  ++it;
  EXPECT_EQ(*it, 3);
  ++it;
  EXPECT_EQ(*it, 4);
  ++it;
  EXPECT_EQ(*it, 98);
}

TEST(ListTest, insert_many1) {
  s21::List<int> List = {1, 2, 3, 4, 5};
  auto it = List.insert_many(List.cbegin(), 6, 7);
  EXPECT_EQ(List.size(), 7);
  EXPECT_EQ((List.front()), 7);
  EXPECT_EQ((List.back()), 5);
  EXPECT_EQ(*it, 7);
  ++it;
  EXPECT_EQ(*it, 6);
  ++it;
  EXPECT_EQ(*it, 1);
  ++it;
  EXPECT_EQ(*it, 2);
  ++it;
  EXPECT_EQ(*it, 3);
  ++it;
  EXPECT_EQ(*it, 4);
  ++it;
  EXPECT_EQ(*it, 5);
}

TEST(ListTest, insert_many2) {
  s21::List<int> List = {1, 2, 3, 4, 5};
  auto it = List.insert_many(List.cend(), 6, 7);
  EXPECT_EQ(List.size(), 7);
  EXPECT_EQ((List.front()), 1);
  EXPECT_EQ((List.back()), 7);
  EXPECT_EQ(*it, 7);
  --it;
  EXPECT_EQ(*it, 6);
  --it;
  EXPECT_EQ(*it, 5);
  --it;
  EXPECT_EQ(*it, 4);
  --it;
  EXPECT_EQ(*it, 3);
  --it;
  EXPECT_EQ(*it, 2);
  --it;
  EXPECT_EQ(*it, 1);
}

// ---------------------------------------------------
TEST(ListTest, insert_many3) {
  s21::List<int> List = {};
  List.insert_many(List.cend(), 6, 7);
  EXPECT_EQ(List.size(), 2);
  EXPECT_EQ((List.front()), 7);
  EXPECT_EQ((List.back()), 6);
  s21::List<int> List2 = {};
  List2.insert_many(List2.cbegin(), 6, 7);
  EXPECT_EQ(List2.size(), 2);
  EXPECT_EQ((List2.front()), 7);
  EXPECT_EQ((List2.back()), 6);
}
// ---------------------------------------------------

TEST(ListTest, insert_many4) {
  s21::List<int> List = {5, 6, 7, 8, 9, 10};
  auto it = List.insert_many(List.cbegin(), 4, 3, 2, 1);
  EXPECT_EQ(List.size(), 10);
  EXPECT_EQ((List.front()), 1);
  EXPECT_EQ((List.back()), 10);
  EXPECT_EQ(*it, 1);
}

TEST(ListTest, insert_many5) {
  s21::List<int> List = {5, 6, 7, 8, 9, 10};
  List.insert_many(List.cend(), 4, 3, 2, 1);
  EXPECT_EQ(List.size(), 10);
  EXPECT_EQ((List.front()), 5);
  EXPECT_EQ((List.back()), 1);
}

TEST(ListTest, insert_many6) {
  s21::List<int> List = {5, 6, 7, 8, 9, 10};
  List.insert_many(List.cend(), 4, 3, 2, 1);
  EXPECT_EQ(List.size(), 10);
  EXPECT_EQ((List.front()), 5);
  EXPECT_EQ((List.back()), 1);
}

TEST(ListTest, insert_many7) {
  s21::List<int> List = {5, 6, 7, 8, 9, 10};
  auto n = List.cbegin();
  ++n;
  auto it = List.insert_many(n, 4, 3, 2, 1);
  EXPECT_EQ(List.size(), 10);
  EXPECT_EQ((List.front()), 5);
  EXPECT_EQ((List.back()), 10);
  EXPECT_EQ(*it, 1);
  it++;
  EXPECT_EQ(*it, 2);
  it++;
  EXPECT_EQ(*it, 3);
  it++;
  EXPECT_EQ(*it, 4);
  it++;
  EXPECT_EQ(*it, 6);
}

TEST(ListTest, insert_many8) {
  s21::List<int> List = {5, 6, 7, 8, 9, 10};
  auto n = List.cbegin();
  ++n;
  ++n;
  ++n;
  auto it = List.insert_many(n, 4, 3, 2, 1);
  EXPECT_EQ(List.size(), 10);
  EXPECT_EQ((List.front()), 5);
  EXPECT_EQ((List.back()), 10);
  EXPECT_EQ(*it, 1);
}

TEST(ListTest, insert_many_back1) {
  s21::List<int> List = {5, 6, 7, 8, 9, 10};
  List.insert_many_back(4, 3, 2, 1);
  EXPECT_EQ(List.size(), 10);
  EXPECT_EQ((List.front()), 5);
  EXPECT_EQ((List.back()), 1);
}

TEST(ListTest, insert_many_back2) {
  s21::List<int> List = {};
  List.insert_many_back(1, 2, 3, 4);
  EXPECT_EQ(List.size(), 4);
  EXPECT_EQ((List.front()), 1);
  EXPECT_EQ((List.back()), 4);
}

TEST(ListTest, insert_many_back3) {
  s21::List<int> List = {};
  List.insert_many_back(1);
  EXPECT_EQ(List.size(), 1);
  EXPECT_EQ((List.front()), 1);
  EXPECT_EQ((List.back()), 1);
}

TEST(ListTest, insert_many_front1) {
  s21::List<int> List = {5, 6, 7, 8, 9, 10};
  List.insert_many_front(4, 3, 2, 1);
  EXPECT_EQ(List.size(), 10);
  EXPECT_EQ((List.front()), 1);
  EXPECT_EQ((List.back()), 10);
}

TEST(ListTest, insert_many_front2) {
  s21::List<int> List = {};
  List.insert_many_front(1, 2, 3, 4);
  EXPECT_EQ(List.size(), 4);
  EXPECT_EQ((List.front()), 4);
  EXPECT_EQ((List.back()), 1);
}

TEST(ListTest, insert_many_front3) {
  s21::List<int> List = {};
  List.insert_many_front(1);
  EXPECT_EQ(List.size(), 1);
  EXPECT_EQ((List.front()), 1);
  EXPECT_EQ((List.back()), 1);
}

TEST(ListIteratorTest, IncrementNotemptyIterator) {
  s21::List<int> myList;
  myList.push_back(1);
  myList.push_back(2);

  s21::List<int>::ListIterator it = myList.begin();
  EXPECT_NO_THROW(++it);
  EXPECT_EQ(*it, 2);
}

TEST(ListIteratorTest, IncrementemptyIterator) {
  s21::List<int> myList;
  s21::List<int>::ListIterator emptyIterator;
  ++emptyIterator;
  ++emptyIterator;
  ++emptyIterator;
  ++emptyIterator;
}

TEST(ListIteratorTest, IncrementemptyIterator2) {
  s21::List<int> myList;
  s21::List<int>::ListIterator emptyIterator;
  --emptyIterator;
  --emptyIterator;
  --emptyIterator;
  --emptyIterator;
}

TEST(ListIteratorTest, IncrementemptyIterator3) {
  s21::List<int> myList;
  s21::List<int>::ListIterator emptyIterator = myList.end();
  --emptyIterator;
  --emptyIterator;
  --emptyIterator;
  --emptyIterator;
}

TEST(ListIteratorTest, IncrementemptyIterator4) {
  s21::List<int> myList;
  s21::List<int>::ListIterator emptyIterator = myList.end();
  ++emptyIterator;
  ++emptyIterator;
  ++emptyIterator;
  ++emptyIterator;
}

TEST(ListIteratorTest, IncrementemptyIterator5) {
  s21::List<int> myList = {1, 2, 3, 4, 5};
  s21::List<int>::ListIterator emptyIterator = myList.end();
  ++emptyIterator;
  ++emptyIterator;
  ++emptyIterator;
  ++emptyIterator;
}

TEST(ListIteratorTest, IncrementemptyIterator6) {
  s21::List<int> myList = {1, 2, 3, 4, 5};
  s21::List<int>::ListIterator emptyIterator = myList.end();
  --emptyIterator;
  EXPECT_EQ((*emptyIterator), 5);
  --emptyIterator;
  EXPECT_EQ((*emptyIterator), 4);
  --emptyIterator;
  EXPECT_EQ((*emptyIterator), 3);
  --emptyIterator;
  EXPECT_EQ((*emptyIterator), 2);
  --emptyIterator;
  EXPECT_EQ((*emptyIterator), 1);
  --emptyIterator;
  ASSERT_THROW(*emptyIterator, std::out_of_range);
}

TEST(ListIteratorTest, IncrementemptyIterator7) {
  s21::List<int> myList = {1};
  s21::List<int>::ListIterator emptyIterator = myList.begin();
  EXPECT_EQ((*emptyIterator), 1);
  ++emptyIterator;
  ASSERT_THROW(*emptyIterator, std::out_of_range);
}

TEST(ListIteratorTest, IncrementemptyIterator8) {
  s21::List<int> myList = {1};
  s21::List<int>::ListIterator emptyIterator = myList.begin();
  ++emptyIterator;
  ASSERT_THROW(*emptyIterator, std::out_of_range);
}

// ---------------------------------------------------------------------------------------------------------------------------------------

class TestList {
 public:
  s21::List<int> s21_list_empty;
  s21::List<int> s21_list_three{1, 2, 3};
  s21::List<int> s21_lesser{534789,   2479056, 987654, 110101024,
                            62348710, 1,       35674};
  s21::List<char> s21_char_list{'L', 'I', 'S', 'T'};
  s21::List<int> s21_list_ten{1, 2, 3, 5, 9, 10};
  s21::List<int> s21_list_unique{111, 111, 111, 3, 4, 5, 6, 666, 666};

  std::list<int> std_list_empty;
  std::list<int> std_list_three{1, 2, 3};
  std::list<int> std_lesser{534789,   2479056, 987654, 110101024,
                            62348710, 1,       35674};
  std::list<char> std_char_list{'L', 'I', 'S', 'T'};
  std::list<int> std_list_ten{1, 2, 3, 5, 9, 10};
  std::list<int> std_list_unique{111, 111, 111, 3, 4, 5, 6, 666, 666};
};

TEST(List, default_constructor) {
  TestList tester;
  EXPECT_EQ(tester.s21_list_empty.size(), tester.std_list_empty.size());
  EXPECT_EQ(tester.s21_list_empty.empty(), tester.std_list_empty.empty());
  // s21::List<int> qwe;
  // qwe.
}

TEST(List, init_constructor) {
  TestList tester;
  s21::List<int> a(3);
  std::list<int> b(3);
  s21::List<int>::iterator s21_it = a.begin();
  std::list<int>::iterator std_it = b.begin();
  while (s21_it != a.end()) {
    ASSERT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
}

TEST(List, initializer_constructor) {
  TestList tester;
  s21::List<int>::iterator s21_iter = tester.s21_list_three.begin();
  std::list<int>::iterator std_iter = tester.std_list_three.begin();
  while (s21_iter != tester.s21_list_three.end()) {
    EXPECT_EQ(*s21_iter, *std_iter);
    ++s21_iter;
    ++std_iter;
  }
  EXPECT_EQ(tester.s21_list_three.size(), tester.std_list_three.size());
  EXPECT_EQ(tester.s21_list_three.empty(), tester.std_list_three.empty());
}

TEST(List, copy_constructor) {
  TestList tester;
  s21::List<int> s21_list_copy(tester.s21_list_three);
  std::list<int> std_list_copy(tester.std_list_three);
  s21::List<int>::iterator s21_iter = s21_list_copy.begin();
  std::list<int>::iterator std_iter = std_list_copy.begin();
  while (s21_iter != s21_list_copy.end()) {
    EXPECT_EQ(*s21_iter, *std_iter);
    ++s21_iter;
    ++std_iter;
  }
  EXPECT_EQ(s21_list_copy.size(), std_list_copy.size());
  EXPECT_EQ(s21_list_copy.empty(), std_list_copy.empty());
}

TEST(List, move_constructor) {
  TestList tester;
  s21::List<int> s21_list_move(std::move(tester.s21_list_three));
  std::list<int> std_list_move(std::move(tester.std_list_three));
  s21::List<int>::iterator s21_iter = s21_list_move.begin();
  std::list<int>::iterator std_iter = std_list_move.begin();
  while (s21_iter != s21_list_move.end()) {
    EXPECT_EQ(*s21_iter, *std_iter);
    ++s21_iter;
    ++std_iter;
  }
  EXPECT_EQ(s21_list_move.size(), std_list_move.size());
  EXPECT_EQ(s21_list_move.empty(), std_list_move.empty());
  s21::List<int> s21_list_three{1, 2, 3};
  std::list<int> s21_list_three_{1, 2, 3};
  s21_iter = s21_list_three.begin();
  std_iter = s21_list_three_.begin();
  while (s21_iter != s21_list_three.end()) {
    EXPECT_EQ(*s21_iter, *std_iter);
    ++s21_iter;
    ++std_iter;
  }
  EXPECT_EQ(tester.s21_list_three.size(), tester.std_list_three.size());
  EXPECT_EQ(tester.s21_list_three.empty(), tester.std_list_three.empty());
}

TEST(List, copy_assigment_lesser) {
  TestList tester;
  s21::List<int> s21_list_copy{1, 2};
  std::list<int> std_list_copy{1, 2};
  s21_list_copy = tester.s21_lesser;
  std_list_copy = tester.std_lesser;
  s21::List<int>::iterator s21_iter = s21_list_copy.begin();
  std::list<int>::iterator std_iter = std_list_copy.begin();
  while (s21_iter != s21_list_copy.end()) {
    EXPECT_EQ(*s21_iter, *std_iter);
    ++s21_iter;
    ++std_iter;
  }
  EXPECT_EQ(s21_list_copy.size(), std_list_copy.size());
  EXPECT_EQ(s21_list_copy.empty(), std_list_copy.empty());
}

TEST(List, move_assigment) {
  TestList tester;
  s21::List<int> s21_list_move{1, 2};
  std::list<int> std_list_move{1, 2};
  s21_list_move = std::move(tester.s21_lesser);
  std_list_move = std::move(tester.std_lesser);
  s21::List<int>::iterator s21_iter = s21_list_move.begin();
  std::list<int>::iterator std_iter = std_list_move.begin();
  while (s21_iter != s21_list_move.end()) {
    EXPECT_EQ(*s21_iter, *std_iter);
    ++s21_iter;
    ++std_iter;
  }
  EXPECT_EQ(s21_list_move.size(), std_list_move.size());
  EXPECT_EQ(s21_list_move.empty(), std_list_move.empty());
}

TEST(List, function_front) {
  TestList tester;
  EXPECT_EQ(tester.s21_char_list.front(), tester.std_char_list.front());
}

TEST(List, iterator_access3) {
  TestList tester;
  s21::List<char>::const_iterator con_it = tester.s21_char_list.cbegin();
  s21::List<char>::iterator s21_iter(con_it);
  std::list<char>::iterator std_iter = tester.std_char_list.begin();
  while (s21_iter != tester.s21_char_list.end()) {
    EXPECT_EQ(*s21_iter, *std_iter);
    ++s21_iter;
    ++std_iter;
  }
}

TEST(List, const_iterator_access) {
  TestList tester;
  s21::List<char>::const_iterator s21_const_iter =
      tester.s21_char_list.cbegin();
  std::list<char>::const_iterator std_const_iter = tester.std_char_list.begin();
  while (s21_const_iter != tester.s21_char_list.cend()) {
    EXPECT_EQ(*s21_const_iter, *std_const_iter);
    ++s21_const_iter;
    ++std_const_iter;
  }
}

TEST(List, function_empty) {
  TestList tester;
  EXPECT_EQ(tester.s21_list_empty.empty(), tester.std_list_empty.empty());
  EXPECT_EQ(tester.s21_list_three.empty(), tester.std_list_three.empty());
}

TEST(List, function_size) {
  TestList tester;
  EXPECT_EQ(tester.s21_list_three.size(), tester.std_list_three.size());
  EXPECT_EQ(tester.s21_list_empty.size(), tester.std_list_empty.size());
}

TEST(List, function_clear) {
  TestList tester;
  tester.s21_list_three.clear();
  tester.std_list_three.clear();
  EXPECT_EQ(tester.s21_list_three.size(), tester.std_list_three.size());
}

TEST(List, function_insert_begin) {
  TestList tester;
  s21::List<int>::iterator s21_it = tester.s21_list_empty.begin();
  std::list<int>::iterator std_it = tester.std_list_empty.begin();
  s21_it = tester.s21_list_empty.insert(s21_it, 666);
  std_it = tester.std_list_empty.insert(std_it, 666);
  ASSERT_EQ(*s21_it, *std_it);
  s21_it = tester.s21_list_empty.begin();
  std_it = tester.std_list_empty.begin();
  while (s21_it != tester.s21_list_empty.end()) {
    EXPECT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
  EXPECT_EQ(tester.s21_list_empty.size(), tester.std_list_empty.size());
  EXPECT_EQ(tester.s21_list_empty.empty(), tester.std_list_empty.empty());
}

TEST(List, function_insert_mid) {
  TestList tester;
  s21::List<int>::iterator s21_it = tester.s21_list_ten.begin();
  std::list<int>::iterator std_it = tester.std_list_ten.begin();
  ++s21_it;
  ++std_it;
  ++s21_it;
  ++std_it;
  ++s21_it;
  ++std_it;
  s21_it = tester.s21_list_ten.insert(s21_it, 666);
  std_it = tester.std_list_ten.insert(std_it, 666);
  ASSERT_EQ(*s21_it, *std_it);
  s21_it = tester.s21_list_ten.begin();
  std_it = tester.std_list_ten.begin();
  while (s21_it != tester.s21_list_ten.end()) {
    ASSERT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
  EXPECT_EQ(tester.s21_list_ten.size(), tester.std_list_ten.size());
  EXPECT_EQ(tester.s21_list_ten.empty(), tester.std_list_ten.empty());
}

TEST(List, function_erase_multi) {
  TestList tester;
  s21::List<int>::iterator s21_it = tester.s21_list_ten.begin();
  std::list<int>::iterator std_it = tester.std_list_ten.begin();
  ++s21_it;
  ++std_it;
  ++s21_it;
  ++std_it;
  ++s21_it;
  ++std_it;
  tester.s21_list_ten.erase(s21_it);
  tester.std_list_ten.erase(std_it);
  s21_it = tester.s21_list_ten.begin();
  std_it = tester.std_list_ten.begin();
  tester.s21_list_ten.erase(s21_it);
  tester.std_list_ten.erase(std_it);
  s21_it = tester.s21_list_ten.begin();
  std_it = tester.std_list_ten.begin();
  while (s21_it != tester.s21_list_ten.end()) {
    EXPECT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
  EXPECT_EQ(tester.s21_list_ten.size(), tester.std_list_ten.size());
  EXPECT_EQ(tester.s21_list_ten.empty(), tester.std_list_ten.empty());
}
TEST(List, function_push_back) {
  TestList tester;
  tester.s21_list_three.push_back(666);
  tester.std_list_three.push_back(666);
  tester.s21_list_three.push_back(123);
  tester.std_list_three.push_back(123);
  s21::List<int>::iterator s21_it = tester.s21_list_three.begin();
  std::list<int>::iterator std_it = tester.std_list_three.begin();
  while (s21_it != tester.s21_list_three.end()) {
    EXPECT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
  EXPECT_EQ(tester.s21_list_three.size(), tester.std_list_three.size());
  EXPECT_EQ(tester.s21_list_three.empty(), tester.std_list_three.empty());
}

TEST(List, function_pop_back) {
  TestList tester;
  tester.s21_list_ten.pop_back();
  tester.std_list_ten.pop_back();
  tester.s21_list_ten.pop_back();
  tester.std_list_ten.pop_back();
  s21::List<int>::iterator s21_it = tester.s21_list_ten.begin();
  std::list<int>::iterator std_it = tester.std_list_ten.begin();
  while (s21_it != tester.s21_list_ten.end()) {
    EXPECT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
  EXPECT_EQ(tester.s21_list_ten.size(), tester.std_list_ten.size());
  EXPECT_EQ(tester.s21_list_ten.empty(), tester.std_list_ten.empty());
}

TEST(List, function_push_front) {
  TestList tester;
  tester.s21_list_ten.push_front(666);
  tester.std_list_ten.push_front(666);
  tester.s21_list_ten.push_front(123);
  tester.std_list_ten.push_front(123);
  s21::List<int>::iterator s21_it = tester.s21_list_ten.begin();
  std::list<int>::iterator std_it = tester.std_list_ten.begin();
  while (s21_it != tester.s21_list_ten.end()) {
    EXPECT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
  EXPECT_EQ(tester.s21_list_ten.size(), tester.std_list_ten.size());
  EXPECT_EQ(tester.s21_list_ten.empty(), tester.std_list_ten.empty());
}

TEST(List, function_pop_front) {
  TestList tester;
  tester.s21_list_ten.pop_front();
  tester.std_list_ten.pop_front();
  tester.s21_list_ten.pop_front();
  tester.std_list_ten.pop_front();
  s21::List<int>::iterator s21_it = tester.s21_list_ten.begin();
  std::list<int>::iterator std_it = tester.std_list_ten.begin();
  while (s21_it != tester.s21_list_ten.end()) {
    EXPECT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
  EXPECT_EQ(tester.s21_list_ten.size(), tester.std_list_ten.size());
  EXPECT_EQ(tester.s21_list_ten.empty(), tester.std_list_ten.empty());
}

TEST(List, function_swap) {
  TestList tester;
  s21::List<int> s21_list_swap{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::list<int> std_list_swap{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  tester.s21_lesser.swap(s21_list_swap);
  tester.std_lesser.swap(std_list_swap);
  s21::List<int>::iterator s21_it = s21_list_swap.begin();
  std::list<int>::iterator std_it = std_list_swap.begin();
  while (s21_it != s21_list_swap.end()) {
    EXPECT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
  EXPECT_EQ(s21_list_swap.size(), std_list_swap.size());
  EXPECT_EQ(s21_list_swap.empty(), std_list_swap.empty());
  s21_it = tester.s21_lesser.begin();
  std_it = tester.std_lesser.begin();
  while (s21_it != tester.s21_lesser.end()) {
    ASSERT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
  EXPECT_EQ(tester.s21_lesser.size(), tester.std_lesser.size());
  EXPECT_EQ(tester.s21_lesser.empty(), tester.std_lesser.empty());
}

TEST(List, function_splice) {
  TestList tester;
  s21::List<int> s21_list_splice{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::list<int> std_list_splice{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  s21::List<int>::iterator s21_it = tester.s21_lesser.begin();
  std::list<int>::iterator std_it = tester.std_lesser.begin();
  ++s21_it;
  ++std_it;
  tester.s21_lesser.splice(s21_it, s21_list_splice);
  tester.std_lesser.splice(std_it, std_list_splice);
  s21_it = s21_list_splice.begin();
  std_it = std_list_splice.begin();
  while (s21_it != s21_list_splice.end()) {
    EXPECT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
  EXPECT_EQ(s21_list_splice.size(), std_list_splice.size());
  EXPECT_EQ(s21_list_splice.empty(), std_list_splice.empty());
  s21_it = tester.s21_lesser.begin();
  std_it = tester.std_lesser.begin();
  EXPECT_EQ(tester.s21_lesser.size(), tester.std_lesser.size());
  EXPECT_EQ(tester.s21_lesser.empty(), tester.std_lesser.empty());
}

TEST(List, function_reverse) {
  TestList tester;
  tester.s21_list_ten.reverse();
  tester.std_list_ten.reverse();
  s21::List<int>::iterator s21_it = tester.s21_list_ten.begin();
  std::list<int>::iterator std_it = tester.std_list_ten.begin();
  while (s21_it != tester.s21_list_ten.end()) {
    EXPECT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
  EXPECT_EQ(tester.s21_list_ten.size(), tester.std_list_ten.size());
  EXPECT_EQ(tester.s21_list_ten.empty(), tester.std_list_ten.empty());
}

TEST(List, function_unique) {
  TestList tester;
  tester.s21_list_unique.unique();
  tester.std_list_unique.unique();
  s21::List<int>::iterator s21_it = tester.s21_list_unique.begin();
  std::list<int>::iterator std_it = tester.std_list_unique.begin();
  while (s21_it != tester.s21_list_unique.end()) {
    ASSERT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
  EXPECT_EQ(tester.s21_list_unique.size(), tester.std_list_unique.size());
  EXPECT_EQ(tester.s21_list_unique.empty(), tester.std_list_unique.empty());
}

TEST(List, function_sort) {
  TestList tester;
  tester.s21_lesser.sort();
  tester.std_lesser.sort();
  s21::List<int>::iterator s21_it = tester.s21_lesser.begin();
  std::list<int>::iterator std_it = tester.std_lesser.begin();
  while (s21_it != tester.s21_lesser.end()) {
    EXPECT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
  EXPECT_EQ(tester.s21_lesser.size(), tester.std_lesser.size());
  EXPECT_EQ(tester.s21_lesser.empty(), tester.std_lesser.empty());
}

TEST(List, function_emplace_begin) {
  TestList tester;
  s21::List<int>::iterator s21_it = tester.s21_list_ten.begin();
  std::list<int>::iterator std_it = tester.std_list_ten.begin();
  s21_it = tester.s21_list_ten.insert_many(s21_it, 666);
  std_it = tester.std_list_ten.emplace(std_it, 666);
  ASSERT_EQ(*s21_it, *std_it);
  s21_it = tester.s21_list_ten.begin();
  std_it = tester.std_list_ten.begin();
  while (s21_it != tester.s21_list_ten.end()) {
    EXPECT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
  EXPECT_EQ(tester.s21_list_ten.size(), tester.std_list_ten.size());
  EXPECT_EQ(tester.s21_list_ten.empty(), tester.std_list_ten.empty());
}

TEST(List, function_emplace_mid) {
  TestList tester;
  s21::List<int>::iterator s21_it = tester.s21_list_ten.begin();
  std::list<int>::iterator std_it = tester.std_list_ten.begin();
  ++s21_it;
  ++std_it;
  ++s21_it;
  ++std_it;
  ++s21_it;
  ++std_it;
  s21_it = tester.s21_list_ten.insert_many(s21_it, 666);
  std_it = tester.std_list_ten.emplace(std_it, 666);
  ASSERT_EQ(*s21_it, *std_it);
  s21_it = tester.s21_list_ten.begin();
  std_it = tester.std_list_ten.begin();
  while (s21_it != tester.s21_list_ten.end()) {
    EXPECT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
  EXPECT_EQ(tester.s21_list_ten.size(), tester.std_list_ten.size());
  EXPECT_EQ(tester.s21_list_ten.empty(), tester.std_list_ten.empty());
}

TEST(List, function_emplace_end) {
  TestList tester;
  s21::List<int>::iterator s21_it = tester.s21_list_ten.end();
  std::list<int>::iterator std_it = tester.std_list_ten.end();
  --s21_it;
  --std_it;
  s21_it = tester.s21_list_ten.insert_many(s21_it, 666);
  std_it = tester.std_list_ten.emplace(std_it, 666);
  EXPECT_EQ(*s21_it, *std_it);
  while (s21_it != tester.s21_list_ten.end()) {
    EXPECT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
  EXPECT_EQ(tester.s21_list_ten.size(), tester.std_list_ten.size());
  EXPECT_EQ(tester.s21_list_ten.empty(), tester.std_list_ten.empty());
}

TEST(List, function_emplace_multi) {
  TestList tester;
  s21::List<int>::iterator s21_it = tester.s21_list_ten.begin();
  std::list<int>::iterator std_it = tester.std_list_ten.begin();
  s21_it = tester.s21_list_ten.insert_many(s21_it, 666);
  std_it = tester.std_list_ten.emplace(std_it, 666);
  ++s21_it;
  ++std_it;
  ++s21_it;
  ++std_it;
  ++s21_it;
  ++std_it;
  s21_it = tester.s21_list_ten.insert_many(s21_it, 666);
  std_it = tester.std_list_ten.emplace(std_it, 666);
  ASSERT_EQ(*s21_it, *std_it);
  s21_it = tester.s21_list_ten.begin();
  std_it = tester.std_list_ten.begin();
  while (s21_it != tester.s21_list_ten.end()) {
    EXPECT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
  EXPECT_EQ(tester.s21_list_ten.size(), tester.std_list_ten.size());
  EXPECT_EQ(tester.s21_list_ten.empty(), tester.std_list_ten.empty());
}

TEST(List, function_emplace_back) {
  TestList tester;
  tester.s21_list_three.insert_many_back(666);
  tester.std_list_three.emplace_back(666);
  tester.s21_list_three.insert_many_back(123);
  tester.std_list_three.emplace_back(123);
  s21::List<int>::iterator s21_it = tester.s21_list_three.begin();
  std::list<int>::iterator std_it = tester.std_list_three.begin();
  while (s21_it != tester.s21_list_three.end()) {
    EXPECT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
  EXPECT_EQ(tester.s21_list_three.size(), tester.std_list_three.size());
  EXPECT_EQ(tester.s21_list_three.empty(), tester.std_list_three.empty());
}

TEST(List, function_emplace_front) {
  TestList tester;
  tester.s21_list_three.insert_many_front(666);
  tester.std_list_three.emplace_front(666);
  tester.s21_list_three.insert_many_front(123);
  tester.std_list_three.emplace_front(123);
  s21::List<int>::iterator s21_it = tester.s21_list_three.begin();
  std::list<int>::iterator std_it = tester.std_list_three.begin();
  while (s21_it != tester.s21_list_three.end()) {
    EXPECT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
  EXPECT_EQ(tester.s21_list_three.size(), tester.std_list_three.size());
  EXPECT_EQ(tester.s21_list_three.empty(), tester.std_list_three.empty());
}

TEST(initializer_lists, TEST_1) {
  s21::List<int> A = {};
  std::list<int> B = {};

  size_t a = A.size();
  size_t b = B.size();
  ASSERT_EQ(a, b);
}

TEST(initializer_lists, TEST_2) {
  s21::List<int> A = {1, 2,  3,      4,   5,    6,    7,   8,
                      9, 10, 456545, 987, 5423, 3454, 3673};
  std::list<int> B = {1, 2,  3,      4,   5,    6,    7,   8,
                      9, 10, 456545, 987, 5423, 3454, 3673};

  size_t a = A.size();
  size_t b = B.size();
  ASSERT_EQ(a, b);

  s21::List<int>::ListIterator iterA = A.begin();
  std::list<int>::iterator iterB = B.begin();
  ASSERT_EQ(*iterA, *iterB);

  iterA = A.end();
  iterB = B.end();
  --iterA;
  --iterB;

  ASSERT_EQ(*iterA, *iterB);
}

TEST(initializer_lists, TEST_3) {
  s21::List<double> A{77.987654};
  std::list<double> B{77.987654};

  size_t a = A.size();
  size_t b = B.size();
  ASSERT_EQ(a, b);
  s21::List<double>::ListIterator iterA = A.begin();
  std::list<double>::iterator iterB = B.begin();
  ASSERT_EQ(*iterA, *iterB);
}

TEST(parameterized_constructor, TEST_4) {
  s21::List<double> A(50);
  std::list<double> B(50);

  size_t a = A.size();
  size_t b = B.size();
  ASSERT_EQ(a, b);
  s21::List<double>::ListIterator iterA = A.begin();
  std::list<double>::iterator iterB = B.begin();

  ASSERT_EQ(*iterA, *iterB);
  iterA = A.end();
  iterB = B.end();
  --iterA;
  --iterB;
  ASSERT_EQ(*iterA, *iterB);
}

TEST(parameterized_constructor, TEST_5) {
  s21::List<double> A(50);
  s21::List<double>::ListIterator iterA;
  double y = 0.5;
  for (iterA = A.begin(); iterA != A.end(); ++iterA) {
    *iterA = 1648.090 + y;
  }
  std::list<double> B(50);
  std::list<double>::iterator iterB;
  for (iterB = B.begin(); iterB != B.end(); ++iterB) {
    *iterB = 1648.090 + y;
  }
  size_t a = A.size();
  size_t b = B.size();
  EXPECT_EQ(a, b);

  iterA = A.begin();
  iterB = B.begin();
  EXPECT_DOUBLE_EQ(*iterA, *iterB);

  iterA = A.end();
  iterB = B.end();
  --iterA;
  --iterB;
  EXPECT_DOUBLE_EQ(*iterA, *iterB);
}

TEST(copy_constructor, TEST_1) {
  s21::List<double> A = {1.0006, 21, 3, 4,  51, 6, 7,  8, 9,  10, 765765467.646,
                         6,      7,  7, 53, 2,  2, 45, 6, 32, 1};
  s21::List<double> B(A);
  s21::List<double>::ListIterator iterA = A.begin();
  s21::List<double>::ListIterator iterB = B.begin();
  EXPECT_DOUBLE_EQ(*iterA, *iterB);

  iterA = A.end();
  iterB = B.end();

  size_t a = A.size();
  size_t b = B.size();
  EXPECT_EQ(a, b);
}

TEST(move_constructor, TEST_1) {
  s21::List<int> A = {1, 4, 6, 4, 8};
  s21::List<int> B(std::move(A));

  EXPECT_EQ(A.size(), 0);

  EXPECT_EQ(B.size(), 5);

  s21::List<int>::ListIterator iterA = B.begin();
  EXPECT_EQ(*iterA, 1);
  iterA = B.end();
  --iterA;
  EXPECT_EQ(*iterA, 8);
}

TEST(move_operator, TEST_1) {
  s21::List<int> A = {1, 4, 6, 4, 8};
  s21::List<int> B(std::move(A));

  EXPECT_EQ(A.size(), 0);

  EXPECT_EQ(B.size(), 5);

  s21::List<int>::ListIterator iterB = B.begin();
  EXPECT_EQ(*iterB, 1);
  iterB = B.end();
  --iterB;
  EXPECT_EQ(*iterB, 8);
}

TEST(insert_test, TEST_1) {
  s21::List<int> A{0, 0, 0, 0, 0, 0, 0};
  s21::List<int>::ListIterator it = A.begin();
  A.insert(it, -999);
  it = A.begin();

  std::list<int> orig{0, 0, 0, 0, 0, 0, 0};
  std::list<int>::iterator it_orig = orig.begin();
  orig.insert(it_orig, -999);
  orig.begin();
  for (it_orig = orig.begin(); it_orig != orig.end(); ++it_orig) {
    EXPECT_EQ(*it, *it_orig);
    ++it;
  }
}

TEST(insert_test, TEST_2) {
  s21::List<int> B{1, 2, 3};
  s21::List<int>::ListIterator iter = B.end();
  std::list<int> OG{1, 2, 3};
  std::list<int>::iterator OG_it = OG.end();
  iter = B.insert(iter, 0);
  OG_it = OG.insert(OG_it, 0);
  OG_it = OG.begin();
  for (s21::List<int>::ListIterator iterat = B.begin(); iterat != B.end();
       ++iterat) {
    EXPECT_EQ(*iterat, *OG_it);
    ++OG_it;
  }
}

TEST(insert_test, TEST_3) {
  s21::List<int> A{0, 0, 0, 0, 0, 0, 0};
  s21::List<int>::ListIterator it = A.begin();
  A.insert(it, -999);
  A.insert(it, -999);
  A.insert(it, -999);
  A.insert(it, -999);

  ++it;
  ++it;
  A.insert(it, -999);
  it = A.begin();

  std::list<int> orig{0, 0, 0, 0, 0, 0, 0};
  std::list<int>::iterator it_orig = orig.begin();
  orig.insert(it_orig, -999);
  orig.insert(it_orig, -999);
  orig.insert(it_orig, -999);
  orig.insert(it_orig, -999);
  ++it_orig;
  ++it_orig;
  orig.insert(it_orig, -999);

  for (it_orig = orig.begin(); it_orig != orig.end(); ++it_orig) {
    EXPECT_EQ(*it, *it_orig);
    ++it;
  }
}

TEST(empty, TEST_1) {
  s21::List<int> A;
  std::list<int> orig;
  bool A_ = A.empty();
  bool B = orig.empty();
  EXPECT_EQ(B, A_);
}

TEST(empty, TEST_2) {
  s21::List<int> A(30);
  std::list<int> orig(30);
  bool A_ = A.empty();
  bool B = orig.empty();
  EXPECT_EQ(B, A_);
}

TEST(empty, TEST_3) {
  s21::List<int> A{1, 1, 1, 1};
  std::list<int> orig{1, 1, 1, 1};
  bool A_ = A.empty();
  bool B = orig.empty();
  EXPECT_EQ(B, A_);
}

TEST(empty, TEST_4) {
  s21::List<int> A{1, 1, 1, 1};
  A.clear();
  std::list<int> orig{1, 1, 1, 1};
  orig.clear();
  bool A_ = A.empty();
  bool B = orig.empty();
  EXPECT_EQ(B, A_);
}

TEST(const_reference_front_back, TEST_2) {
  std::list<int> A{1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 10};
  int ans = A.front();
  s21::List<int> B{1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 10};
  int ans_mine = B.front();
  EXPECT_EQ(ans, ans_mine);

  ans = A.back();
  ans_mine = B.back();
  EXPECT_EQ(ans, ans_mine);
}

TEST(const_reference_front_back, TEST_3) {
  std::list<int> A(20);
  int ans = A.front();
  s21::List<int> B(20);
  int ans_mine = B.front();
  EXPECT_EQ(ans, ans_mine);

  ans = A.back();
  ans_mine = B.back();
  EXPECT_EQ(ans, ans_mine);
}

TEST(const_reference_front_back, TEST_4) {
  s21::List<int> B(20);
  B.clear();
  EXPECT_THROW(B.front(), std::out_of_range);
}

TEST(size_test, TEST_1) {
  std::list<int> A(20);
  s21::List<int> B(20);
  size_t mine = B.size();
  size_t orig = A.size();
  EXPECT_EQ(mine, orig);
}

TEST(size_test, TEST_2) {
  std::list<int> A(20);
  s21::List<int> B(20);
  B.clear();
  A.clear();
  size_t mine = B.size();
  size_t orig = A.size();
  EXPECT_EQ(mine, orig);
}

TEST(size_test, TEST_3) {
  std::list<int> A{1, 2, 3, 4, 5, 5, 32, 2, 4, 1, 1, 1, 3};
  s21::List<int> B{1, 2, 3, 4, 5, 5, 32, 2, 4, 1, 1, 1, 3};
  size_t mine = B.size();
  size_t orig = A.size();
  EXPECT_EQ(mine, orig);
}

TEST(push_back_front_test, TEST_4) {
  std::list<char> A;
  A.push_back('I');
  A.push_front('G');
  A.push_back('\'');
  A.push_front('G');
  A.push_back('m');
  A.push_back(' ');
  A.push_front('s');
  A.push_back('D');
  A.push_front('!');
  A.push_front('!');
  s21::List<char> B;
  B.push_back('I');
  B.push_front('G');
  B.push_back('\'');
  B.push_front('G');
  B.push_back('m');
  B.push_back(' ');
  B.push_front('s');
  B.push_back('D');
  B.push_front('!');
  B.push_front('!');

  size_t mine = B.size();
  size_t orig = A.size();
  EXPECT_EQ(mine, orig);
  std::list<char>::iterator it = A.begin();
  s21::List<char>::ListIterator it_mine = B.begin();
  for (; it != A.end(); ++it) {
    EXPECT_EQ(*it, *it_mine);
    ++it_mine;
  }
}

TEST(erase, TEST_1) {
  std::list<int> A{1, 2, 3, 4, 5, 5, 32, 2, 4, 1, 1, 1, 3};
  s21::List<int> B{1, 2, 3, 4, 5, 5, 32, 2, 4, 1, 1, 1, 3};
  std::list<int>::iterator it = A.begin();
  s21::List<int>::ListIterator it_mine = B.begin();
  A.erase(it);
  B.erase(it_mine);
  it = A.begin();
  it_mine = B.begin();
  for (; it != A.end(); ++it) {
    EXPECT_EQ(*it, *it_mine);
    ++it_mine;
  }
  size_t mine = B.size();
  size_t orig = A.size();
  EXPECT_EQ(mine, orig);
}

// TEST(max_size_test, TEST_1){
//   s21::List<char>B;
//   size_t mine = B.max_size();
//   std::list<char>C;
//   size_t their = C.max_size();
//   EXPECT_EQ(mine,their);
// }
