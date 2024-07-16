#include "test_main.h"

TEST(VectorTest, constructor1) { s21::Vector<int> intVector; }

TEST(VectorTest, constructor2) {
  const size_t size = 100;
  s21::Vector<int> myVector(size);
  EXPECT_EQ(myVector.size(), size);
  for (size_t i = 0; i < size; ++i) {
    EXPECT_EQ(myVector[i], 0);
  }
}

TEST(VectorTest, constructordop1) {
  const size_t size = s21::Vector<int>().max_size() + 1;
  EXPECT_THROW(s21::Vector<int> myVector(size), std::out_of_range);
}

TEST(VectorTest, constructordop2) {
  const size_t size = s21::Vector<int>().max_size();
  EXPECT_THROW(s21::Vector<int> myVector(size), std::out_of_range);
}

TEST(VectorTest, constructor3) {
  const size_t size = 0;
  s21::Vector<int> myVector(size);
  EXPECT_EQ(myVector.size(), size);
  for (size_t i = 0; i < size; ++i) {
    EXPECT_EQ(myVector[i], 0);
  }
}

TEST(VectorTest, constructor4) {
  const size_t size = 1;
  s21::Vector<int> myVector(size);
  EXPECT_EQ(myVector.size(), size);
  for (size_t i = 0; i < size; ++i) {
    EXPECT_EQ(myVector[i], 0);
  }
}

TEST(VectorTest, constructor5) {
  s21::Vector<int> myVector = {1, 2, 3, 4, 5};
  EXPECT_EQ(myVector.size(), 5);
  for (size_t i = 0; i < 5; ++i) {
    EXPECT_EQ(myVector[i], i + 1);
  }
}

TEST(VectorTest, constructor6) {
  s21::Vector<int> myVector = {};
  EXPECT_EQ(myVector.size(), 0);
}

TEST(VectorTest, constructor7) {
  s21::Vector<int> sourceVector = {1, 2, 3, 4};
  s21::Vector<int> copiedVector(sourceVector);
  EXPECT_EQ(sourceVector.size(), copiedVector.size());
  EXPECT_EQ(sourceVector.front(), copiedVector.front());
  EXPECT_EQ(sourceVector.back(), copiedVector.back());
  for (size_t i = 0; i < sourceVector.size(); i++) {
    EXPECT_EQ(sourceVector[i], copiedVector[i]);
  }
}

TEST(VectorTest, constructor8) {
  s21::Vector<int> sourceVector = {};
  s21::Vector<int> copiedVector(sourceVector);
  EXPECT_EQ(sourceVector.size(), copiedVector.size());
  EXPECT_THROW(sourceVector.at(0), std::out_of_range);
  EXPECT_THROW(sourceVector.at(0), std::out_of_range);
  EXPECT_THROW(sourceVector.front(), std::out_of_range);
  EXPECT_THROW(copiedVector.front(), std::out_of_range);
  EXPECT_THROW(sourceVector.back(), std::out_of_range);
  EXPECT_THROW(copiedVector.back(), std::out_of_range);
  for (size_t i = 0; i < sourceVector.size(); i++) {
    EXPECT_EQ(sourceVector[i], copiedVector[i]);
  }
}

TEST(VectorTest, constructor9) {
  s21::Vector<int> sourceVector = {9};
  s21::Vector<int> copiedVector(sourceVector);
  EXPECT_EQ(sourceVector.size(), copiedVector.size());
  EXPECT_EQ(sourceVector.front(), copiedVector.front());
  EXPECT_EQ(sourceVector.back(), copiedVector.back());
  for (size_t i = 0; i < sourceVector.size(); i++) {
    EXPECT_EQ(sourceVector[i], copiedVector[i]);
  }
}

TEST(VectorTest, constructor10) {
  s21::Vector<int> sourceVector = {9};
  s21::Vector<int> copiedVector(std::move(sourceVector));
  EXPECT_EQ(sourceVector.size(), 0);
  EXPECT_EQ(copiedVector.size(), 1);
  EXPECT_EQ(copiedVector[0], 9);
}

TEST(VectorTest, constructor11) {
  s21::Vector<int> sourceVector = {1, 2,  3,  4,  5,  6,  7, 8,
                                   9, 10, 11, 12, 13, 14, 15};
  s21::Vector<int> copiedVector(std::move(sourceVector));
  EXPECT_EQ(sourceVector.size(), 0);
  EXPECT_EQ(copiedVector.size(), 15);
  for (size_t i = 0; i < sourceVector.size(); i++) {
    EXPECT_EQ(copiedVector[i], i);
  }
}

TEST(VectorTest, constructor12) {
  s21::Vector<int> sourceVector = {};
  s21::Vector<int> copiedVector(std::move(sourceVector));
  EXPECT_EQ(sourceVector.size(), 0);
  EXPECT_EQ(copiedVector.size(), 0);
}

TEST(VectorTest, operator1) {
  s21::Vector<int> sourceVector = {};
  s21::Vector<int> copiedVector = (sourceVector);
  EXPECT_EQ(sourceVector.size(), 0);
  EXPECT_EQ(copiedVector.size(), 0);
  EXPECT_THROW(sourceVector.front(), std::out_of_range);
  EXPECT_THROW(copiedVector.front(), std::out_of_range);
  EXPECT_THROW(sourceVector.back(), std::out_of_range);
  EXPECT_THROW(copiedVector.back(), std::out_of_range);
}

TEST(VectorTest, operator2) {
  s21::Vector<int> sourceVector = {7};
  s21::Vector<int> copiedVector = (sourceVector);
  EXPECT_EQ(sourceVector.size(), 1);
  EXPECT_EQ(copiedVector.size(), 1);
  EXPECT_EQ(sourceVector.front(), copiedVector.front());
  EXPECT_EQ(sourceVector.back(), copiedVector.back());
  for (size_t i = 0; i < sourceVector.size(); i++) {
    EXPECT_EQ(sourceVector[i], copiedVector[i]);
  }
}

TEST(VectorTest, operator3) {
  s21::Vector<int> sourceVector = {7, 7, 8, 1, 2,   2, 3, 4,
                                   1, 7, 6, 5, 342, 1, 4};
  s21::Vector<int> copiedVector = (sourceVector);
  EXPECT_EQ(sourceVector.size(), copiedVector.size());
  EXPECT_EQ(sourceVector.front(), copiedVector.front());
  EXPECT_EQ(sourceVector.back(), copiedVector.back());
  for (size_t i = 0; i < sourceVector.size(); i++) {
    EXPECT_EQ(sourceVector[i], copiedVector[i]);
  }
}

TEST(VectorTest, data1) {
  s21::Vector<int> myVector = {1, 2, 3, 4, 5};
  int* dataPtr = myVector.data();
  EXPECT_NE(dataPtr, nullptr);
  for (size_t i = 0; i < myVector.size(); ++i) {
    EXPECT_EQ(dataPtr[i], myVector[i]);
  }
}

TEST(VectorTest, data2) {
  s21::Vector<int> myVector = {};
  int* dataPtr = myVector.data();
  EXPECT_TRUE(myVector.empty());
  if (!myVector.empty()) {
    for (size_t i = 0; i < myVector.size(); ++i) {
      EXPECT_EQ(dataPtr[i], myVector[i]);
    }
  }
}

TEST(VectorTest, max_size7) {
  s21::Vector<std::string> s21_vec;
  std::vector<std::string> std_vec;

  EXPECT_EQ(s21_vec.max_size(), std_vec.max_size());
}

TEST(VectorTest, beginend1) {
  s21::Vector<int> myVector = {};
  auto y = myVector.begin();
  auto x = myVector.end();
  EXPECT_EQ(y, nullptr);
  EXPECT_EQ(x, nullptr);
}

TEST(VectorTest, constbeginend1) {
  s21::Vector<int> myVector = {6, 1, 99, 23};
  auto y = myVector.cbegin();
  auto x = myVector.cend();
  x--;
  EXPECT_EQ(*y, 6);
  EXPECT_EQ(*x, 23);
}

TEST(VectorTest, frontback1) {
  s21::Vector<int> myVector = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  EXPECT_EQ(myVector.front(), 1);
  EXPECT_EQ(myVector.back(), 9);
}

TEST(VectorTest, frontback2) {
  s21::Vector<int> myVector = {};
  EXPECT_THROW(myVector.front(), std::out_of_range);
  EXPECT_THROW(myVector.back(), std::out_of_range);
}

TEST(VectorTest, at1) {
  s21::Vector<int> myVector = {};
  EXPECT_THROW(myVector.at(2), std::out_of_range);
}

TEST(VectorTest, at2) {
  s21::Vector<int> myVector = {4, 2, 1};
  EXPECT_EQ(myVector.at(2), 1);
}

TEST(VectorTest, at3) {
  s21::Vector<int> myVector = {3};
  EXPECT_THROW(myVector.at(2), std::out_of_range);
}

TEST(VectorTest, empty2) {
  s21::Vector<int> emptyVector;
  s21::Vector<int> nonEmptyVector = {1, 2, 3, 4, 5};

  EXPECT_TRUE(emptyVector.empty());
  EXPECT_FALSE(nonEmptyVector.empty());
}

TEST(VectorTest, reserve1) {
  s21::Vector<int> myVector = {1, 2, 3, 4, 5};
  size_t initialCapacity = myVector.capacity();
  size_t newCapacity = initialCapacity + 10;

  myVector.reserve(newCapacity);
  EXPECT_EQ(myVector.capacity(), newCapacity + myVector.size());
  EXPECT_EQ(myVector.size(), 5);
  for (size_t i = 0; i < myVector.size(); ++i) {
    EXPECT_EQ(myVector[i], i + 1);
  }
}

TEST(VectorTest, reserve2) {
  s21::Vector<int> myVector = {1, 2, 3, 4, 5};
  myVector.capacity();
  size_t newCapacity = 2;

  myVector.reserve(newCapacity);
  EXPECT_EQ(myVector.capacity(), 7);
  EXPECT_EQ(myVector.size(), 5);
  for (size_t i = 0; i < myVector.size(); ++i) {
    EXPECT_EQ(myVector[i], i + 1);
  }
}

TEST(VectorTest, reservedop1) {
  const size_t size = s21::Vector<int>().max_size() + 1;
  s21::Vector<int> myVector = {1, 2, 3, 4, 5};
  EXPECT_THROW(myVector.reserve(size), std::out_of_range);
}

TEST(VectorTest, reservedop2) {
  const size_t size = s21::Vector<int>().max_size();
  s21::Vector<int> myVector = {1, 2, 3, 4, 5};
  EXPECT_THROW(myVector.reserve(size), std::out_of_range);
}

TEST(VectorTest, shrinkToFit1) {
  s21::Vector<int> myVector = {1, 2, 3, 4, 5};
  myVector.capacity();
  myVector.shrink_to_fit();
  EXPECT_EQ(myVector.capacity(), myVector.size());
  for (size_t i = 0; i < myVector.size(); ++i) {
    EXPECT_EQ(myVector[i], i + 1);
  }
}
TEST(VectorTest, shrinkToFit2) {
  s21::Vector<int> myVector;
  size_t initialCapacity = myVector.capacity();
  myVector.shrink_to_fit();
  EXPECT_EQ(myVector.capacity(), initialCapacity);
}

TEST(VectorTest, shrinkToFit3) {
  s21::Vector<int> myVector = {1, 2, 3, 4, 5};
  myVector.capacity();
  myVector.reserve(10);
  myVector.shrink_to_fit();
  EXPECT_EQ(myVector.capacity(), myVector.size());
}

TEST(VectorTest, inser1) {
  s21::Vector<int> myVector = {1, 2, 4, 5};
  s21::Vector<int>::VectorIterator it = myVector.begin() + 2;
  it = myVector.insert(it, 3);
  EXPECT_EQ(*it, 3);
  EXPECT_EQ(myVector.size(), 5);
  for (size_t i = 0; i < myVector.size(); ++i) {
    EXPECT_EQ(myVector[i], i + 1);
  }
}

TEST(VectorTest, insert2) {
  s21::Vector<int> myVector = {2, 3, 4, 5};
  s21::Vector<int>::VectorIterator it =
      myVector.begin();  // Вставляем элемент в начало
  it = myVector.insert(it, 1);
  EXPECT_EQ(*it, 1);
  EXPECT_EQ(myVector.size(), 5);
  for (size_t i = 0; i < myVector.size(); ++i) {
    EXPECT_EQ(myVector[i], i + 1);
  }
}

TEST(VectorTest, insert3) {
  s21::Vector<int> myVector = {1, 2, 3, 4};
  s21::Vector<int>::VectorIterator it =
      myVector.end();  // Вставляем элемент в конец
  it = myVector.insert(it, 5);
  EXPECT_EQ(*it, 5);
  EXPECT_EQ(myVector.size(), 5);
  for (size_t i = 0; i < myVector.size(); ++i) {
    EXPECT_EQ(myVector[i], i + 1);
  }
}

TEST(VectorTest, insert4) {
  s21::Vector<int> myVector;
  s21::Vector<int>::VectorIterator it = myVector.begin();
  it = myVector.insert(it, 1);
  EXPECT_EQ(*it, 1);
  EXPECT_EQ(myVector.size(), 1);
  EXPECT_EQ(myVector[0], 1);
}

TEST(VectorTest, insert5) {
  s21::Vector<int> myVector = {1, 2, 3, 4, 5};
  s21::Vector<int>::VectorIterator it = myVector.end() + 1;
  EXPECT_THROW(myVector.insert(it, 6), std::out_of_range);
}

TEST(VectorTest, erase1) {
  s21::Vector<int> myVector = {1, 2, 3, 4, 5};
  s21::Vector<int>::VectorIterator it = myVector.begin() + 2;
  myVector.erase(it);

  EXPECT_EQ(myVector.size(), 4);
  EXPECT_EQ(myVector[0], 1);
  EXPECT_EQ(myVector[1], 2);
  EXPECT_EQ(myVector[2], 4);
  EXPECT_EQ(myVector[3], 5);
}

TEST(VectorTest, erase2) {
  s21::Vector<int> myVector = {1, 2, 3, 4, 5};
  s21::Vector<int>::VectorIterator it = myVector.begin();
  myVector.erase(it);

  EXPECT_EQ(myVector.size(), 4);
  EXPECT_EQ(myVector[0], 2);
  EXPECT_EQ(myVector[1], 3);
  EXPECT_EQ(myVector[2], 4);
  EXPECT_EQ(myVector[3], 5);
}

TEST(VectorTest, erase3) {
  s21::Vector<int> myVector = {1, 2, 3, 4, 5};
  s21::Vector<int>::VectorIterator it = myVector.end() - 1;
  myVector.erase(it);

  EXPECT_EQ(myVector.size(), 4);
  EXPECT_EQ(myVector[0], 1);
  EXPECT_EQ(myVector[1], 2);
  EXPECT_EQ(myVector[2], 3);
  EXPECT_EQ(myVector[3], 4);
}

TEST(VectorTest, erase4) {
  s21::Vector<int> myVector = {1, 2, 3, 4, 5};
  for (s21::Vector<int>::VectorIterator it = myVector.begin();
       it != myVector.end();) {
    myVector.erase(it);
  }

  EXPECT_EQ(myVector.size(), 0);
  EXPECT_TRUE(myVector.empty());
}

TEST(VectorTest, erase5) {
  s21::Vector<int> myVector = {1, 2, 3, 4, 5};
  s21::Vector<int>::VectorIterator it = myVector.end() + 1;
  EXPECT_THROW(myVector.erase(it), std::out_of_range);
}

TEST(VectorTest, front1) {
  s21::Vector<int> myVector = {1, 2, 3, 4, 5};
  EXPECT_EQ(myVector.front(), 1);
}

TEST(VectorTest, front2) {
  s21::Vector<int> myVector;
  EXPECT_THROW(myVector.front(), std::out_of_range);
}

TEST(VectorTest, back1) {
  s21::Vector<int> myVector = {1, 2, 3, 4, 5};
  EXPECT_EQ(myVector.back(), 5);
}

TEST(VectorTest, back2) {
  s21::Vector<int> myVector;
  EXPECT_THROW(myVector.back(), std::out_of_range);
}

TEST(VectorTest, backfront1) {
  s21::Vector<int> myVector = {1};
  EXPECT_EQ(myVector.front(), 1);
  EXPECT_EQ(myVector.back(), 1);
}

TEST(VectorTest, PushBack1) {
  s21::Vector<int> myVector = {1, 2, 3};
  myVector.push_back(4);
  EXPECT_EQ(myVector.size(), 4);
  EXPECT_EQ(myVector[3], 4);
}

TEST(VectorTest, PushBack2) {
  s21::Vector<int> myVector;
  myVector.push_back(1);
  EXPECT_EQ(myVector.size(), 1);
  EXPECT_EQ(myVector[0], 1);
}

TEST(VectorTest, PushBack3) {
  s21::Vector<int> myVector;
  myVector.reserve(3);
  myVector.push_back(1);
  myVector.push_back(2);
  myVector.push_back(3);
  myVector.push_back(4);
  EXPECT_EQ(myVector.size(), 4);
  EXPECT_EQ(myVector[3], 4);
}

TEST(VectorTest, PopBack1) {
  s21::Vector<int> myVector = {1, 2, 3, 4};
  myVector.pop_back();
  EXPECT_EQ(myVector.size(), 3);
  EXPECT_EQ(myVector.back(), 3);
}

TEST(VectorTest, PopBack2) {
  s21::Vector<int> myVector = {1};
  myVector.pop_back();
  EXPECT_EQ(myVector.size(), 0);
}

TEST(VectorTest, PopBack3) {
  s21::Vector<int> myVector;
  myVector.pop_back();
  EXPECT_EQ(myVector.size(), 0);
}

TEST(VectorTest, Swap1) {
  s21::Vector<int> myVector1 = {1, 2, 3};
  s21::Vector<int> myVector2 = {4, 5, 6};
  myVector1.swap(myVector2);
  EXPECT_EQ(myVector1.size(), 3);
  EXPECT_EQ(myVector2.size(), 3);
  for (int i = 0; i < 3; ++i) {
    EXPECT_EQ(myVector1[i], 4 + i);
    EXPECT_EQ(myVector2[i], 1 + i);
  }
}

TEST(VectorTest, Swap2) {
  s21::Vector<int> myVector1;
  s21::Vector<int> myVector2;
  myVector1.swap(myVector2);
  EXPECT_EQ(myVector1.size(), 0);
  EXPECT_EQ(myVector2.size(), 0);
}

TEST(VectorTest, Swap3) {
  s21::Vector<int> myVector1 = {1, 2, 3};
  s21::Vector<int> myVector2;
  myVector1.swap(myVector2);
  EXPECT_EQ(myVector1.size(), 0);
  EXPECT_EQ(myVector2.size(), 3);
  for (int i = 0; i < 3; ++i) {
    EXPECT_EQ(myVector2[i], 1 + i);
  }
}

TEST(VectorTest, shrinkToFit7) {
  s21::Vector<int> myVector = {1, 2, 3, 4, 5};
  myVector.capacity();
  myVector.shrink_to_fit();
  EXPECT_EQ(myVector.capacity(), 5);
  EXPECT_EQ(myVector.size(), 5);
}

TEST(VectorTest, shrinkToFit8) {
  s21::Vector<int> myVector = {1, 2, 3};
  size_t initialCapacity = myVector.capacity();
  myVector.shrink_to_fit();
  EXPECT_EQ(myVector.capacity(), initialCapacity);
}

TEST(VectorTest, shrinkToFit9) {
  s21::Vector<int> myVector;
  myVector.shrink_to_fit();
  EXPECT_EQ(myVector.capacity(), 0);
}

TEST(VectorTest, insert_many1) {
  s21::Vector<int> vec = {3, 4, 5};
  s21::Vector<int>::VectorIterator it = vec.insert_many(vec.cbegin(), 2, 1);
  assert(vec.size() == 5);
  assert(vec[0] == 1);
  assert(vec[1] == 2);
  assert(vec[2] == 3);
  assert(vec[3] == 4);
  assert(vec[4] == 5);
  assert(*it == 1);
}

TEST(VectorTest, insert_many2) {
  s21::Vector<int> vec(4);
  s21::Vector<int>::VectorIterator it = vec.insert_many(vec.cbegin(), 1, 2);
  assert(vec.size() == 6);
  assert(vec[0] == 2);
  assert(vec[1] == 1);
  assert(*it == 2);
}

TEST(VectorTest, insert_many3) {
  s21::Vector<int> vec(2);
  s21::Vector<int>::VectorIterator it = vec.insert_many(vec.cbegin(), 1);
  assert(vec.size() == 3);
  assert(vec[0] == 1);
  assert(*it == 1);
}

TEST(VectorTest, insert_many4) {
  s21::Vector<int> vec = {3, 4, 5};
  s21::Vector<int>::VectorIterator it = vec.insert_many(vec.cbegin());
  assert(vec.size() == 3);
  assert(vec[0] == 3);
  assert(vec[1] == 4);
  assert(vec[2] == 5);
  assert(*it == 3);
}

TEST(VectorTest, insert_many5) {
  s21::Vector<int> vec = {};
  vec.insert_many(vec.cbegin());
  assert(vec.size() == 0);
}

TEST(VectorTest, insert_many6) {
  s21::Vector<int> vec = {1, 2, 3};
  s21::Vector<int>::VectorIterator it = vec.insert_many(vec.cend(), 5, 4);
  assert(vec.size() == 5);
  assert(vec[0] == 1);
  assert(vec[1] == 2);
  assert(vec[2] == 3);
  assert(vec[3] == 4);
  assert(vec[4] == 5);
  assert(*it == 4);
}

TEST(VectorTest, insert_many7) {
  s21::Vector<int> vec = {1, 2, 3};
  s21::Vector<int>::VectorIterator it = vec.insert_many(vec.cend());
  assert(vec.size() == 3);
  assert(*it == 1);
}

TEST(VectorTest, insert_many_back1) {
  s21::Vector<int> vec = {1, 2, 3};
  vec.insert_many_back(4, 5, 6);
  assert(vec.size() == 6);
  assert(vec[0] == 1);
  assert(vec[1] == 2);
  assert(vec[2] == 3);
  assert(vec[3] == 4);
  assert(vec[4] == 5);
  assert(vec[5] == 6);
}

TEST(VectorTest, insert_many_back3) {
  s21::Vector<int> vec = {1, 2, 3};
  vec.insert_many_back();
  assert(vec.size() == 3);
  assert(vec[0] == 1);
  assert(vec[1] == 2);
  assert(vec[2] == 3);
}

TEST(VectorTest, insert_many_back9) {
  s21::Vector<int> vec = {1, 2, 3};
  vec.insert_many_back(6, 7);
  assert(vec.size() == 5);
  assert(vec[0] == 1);
  assert(vec[1] == 2);
  assert(vec[2] == 3);
  assert(vec[3] == 6);
  assert(vec[4] == 7);
}

TEST(VectorTest, insert_many_back4) {
  s21::Vector<int> vec;
  vec.insert_many_back();
  assert(vec.size() == 0);
}

TEST(VectorInsertManyTest, InsertManyWorks) {
  s21::Vector<int> vec;
  for (int i = 1; i <= 5; ++i) {
    vec.push_back(i);
  }
  s21::Vector<int> toInsert{10, 20, 30};
  auto it =
      vec.insert_many(vec.cbegin() + 1, toInsert[0], toInsert[1], toInsert[2]);
  ASSERT_EQ(vec.size(), 8);
  ASSERT_EQ(vec[0], 1);
  ASSERT_EQ(vec[1], 30);
  ASSERT_EQ(vec[2], 20);
  ASSERT_EQ(vec[3], 10);
  ASSERT_EQ(vec[4], 2);
  ASSERT_EQ(vec[5], 3);
  ASSERT_EQ(vec[6], 4);
  ASSERT_EQ(vec[7], 5);
  ASSERT_EQ(*it, 30);
}

// TEST(VectorInsertManyTest, InsertManyOutOfRange) {
//     s21::Vector<int> vec;
//     for (int i = 1; i <= 5; ++i) {
//         vec.push_back(i);
//     }
//     s21::Vector<int> toInsert{10, 20, 30};
//     ASSERT_THROW(vec.insert_many(vec.cend() + 1, toInsert.cbegin(),
//     toInsert.cend()), std::out_of_range);
// }
