#include "test_main.h"

TEST(S21Queue, ConstructorDefault) {
  s21::queue<int> s21_queue;
  std::queue<int> std_queue;
  EXPECT_EQ(s21_queue.size(), std_queue.size());
  EXPECT_EQ(s21_queue.empty(), std_queue.empty());
}

TEST(S21Queue, ConstructorListCompare) {
  s21::queue<int> s21_queue = {1, 2, 3};
  std::queue<int> std_queue;
  std_queue.push(1);
  std_queue.push(2);
  std_queue.push(3);
  EXPECT_EQ(s21_queue.front(), std_queue.front());
  EXPECT_EQ(s21_queue.back(), std_queue.back());
}
TEST(S21Queue, ConstructorList) {
  s21::queue<int> s21_queue = {1, 2, 3, 4};
  EXPECT_EQ(s21_queue.front(), 1);
  EXPECT_EQ(s21_queue.back(), 4);
  EXPECT_EQ(s21_queue.size(), size_t(4));
  EXPECT_EQ(s21_queue.empty(), false);
}

TEST(S21Queue, ConstructorCopyCompare) {
  s21::queue<int> s21_queue = {1, 2, 3};
  s21::queue<int> s21_copy(s21_queue);
  std::queue<int> std_queue;
  std_queue.push(1);
  std_queue.push(2);
  std_queue.push(3);
  std::queue<int> std_copy(std_queue);
  EXPECT_EQ(s21_copy.front(), std_copy.front());
  EXPECT_EQ(s21_copy.back(), std_copy.back());
}

TEST(S21Queue, OperatorCopyCompare) {
  s21::queue<int> s21_queue_int = {1, 2, 3};
  std::queue<int> std_queue_int;
  std_queue_int.push(1);
  std_queue_int.push(2);
  std_queue_int.push(3);
  s21::queue<int> s21_queue_empty;
  std::queue<int> std_queue_empty;
  s21_queue_empty = s21_queue_int;
  std_queue_empty = std_queue_int;
  EXPECT_EQ(s21_queue_empty.front(), std_queue_empty.front());
  EXPECT_EQ(s21_queue_empty.back(), std_queue_empty.back());
  EXPECT_EQ(s21_queue_int.empty(), std_queue_int.empty());
}

TEST(S21Queue, OperatorCopy) {
  s21::queue<char> s21_queue_1 = {'a', 'b', 'c', 'd'};
  s21::queue<char> s21_queue_2 = s21_queue_1;

  EXPECT_EQ(s21_queue_1.size(), s21_queue_2.size());

  for (auto i = 0; i < 4; i++) {
    EXPECT_EQ(s21_queue_1.front(), s21_queue_2.front());
    EXPECT_EQ(s21_queue_1.size(), s21_queue_2.size());
    s21_queue_1.pop(), s21_queue_2.pop();
  }
}

TEST(S21Queue, ConstructorMove) {
  s21::queue<int> s21_queue = {1, 2, 3};
  s21::queue<int> s21_move(std::move(s21_queue));
  std::queue<int> std_queue;
  std_queue.push(1);
  std_queue.push(2);
  std_queue.push(3);
  std::queue<int> std_move(std::move(std_queue));
  EXPECT_EQ(s21_move.front(), std_move.front());
  EXPECT_EQ(s21_move.back(), std_move.back());
  EXPECT_EQ(s21_queue.empty(), std_queue.empty());
}

TEST(S21Queue, OperatorMoveCompare) {
  s21::queue<int> s21_queue_int = {1, 2, 3};
  std::queue<int> std_queue_int;
  std_queue_int.push(1);
  std_queue_int.push(2);
  std_queue_int.push(3);
  s21::queue<int> s21_queue_empty;
  std::queue<int> std_queue_empty;
  s21_queue_empty = std::move(s21_queue_int);
  std_queue_empty = std::move(std_queue_int);
  EXPECT_EQ(s21_queue_empty.front(), std_queue_empty.front());
  EXPECT_EQ(s21_queue_empty.back(), std_queue_empty.back());
  EXPECT_EQ(s21_queue_int.empty(), std_queue_int.empty());
}

TEST(S21Queue, OperatorMove) {
  s21::queue<char> s21_queue_1 = {'a', 'b', 'c', 'd'};
  s21::queue<char> s21_queue_2 = std::move(s21_queue_1);
  s21::queue<char> s21_queue_3 = {'a', 'b', 'c', 'd'};

  EXPECT_EQ(s21_queue_2.size(), s21_queue_3.size());
  EXPECT_EQ(s21_queue_1.size(), size_t(0));
  EXPECT_EQ(s21_queue_1.empty(), true);
  for (auto i = 0; i < 4; i++) {
    EXPECT_EQ(s21_queue_3.front(), s21_queue_2.front());
    EXPECT_EQ(s21_queue_3.size(), s21_queue_2.size());
    s21_queue_3.pop(), s21_queue_2.pop();
  }
}

TEST(S21Queue, FrontAndBack) {
  s21::queue<int> s21_queue_int = {1, 2, 3};
  std::queue<int> std_queue_int;
  std_queue_int.push(1);
  std_queue_int.push(2);
  std_queue_int.push(3);
  s21::queue<double> s21_queue_double = {1.1f, 2.1f, 3.1f};
  std::queue<double> std_queue_double;
  std_queue_double.push(1.1f);
  std_queue_double.push(2.1f);
  std_queue_double.push(3.1f);
  s21::queue<std::string> s21_queue_string = {"abc", "def", "ghf"};
  std::queue<std::string> std_queue_string;
  std_queue_string.push("abc");
  std_queue_string.push("def");
  std_queue_string.push("ghf");
  EXPECT_EQ(s21_queue_int.front(), std_queue_int.front());
  EXPECT_EQ(s21_queue_double.front(), std_queue_double.front());
  EXPECT_EQ(s21_queue_string.front(), std_queue_string.front());
  EXPECT_EQ(s21_queue_int.back(), std_queue_int.back());
  EXPECT_EQ(s21_queue_double.back(), std_queue_double.back());
  EXPECT_EQ(s21_queue_string.back(), std_queue_string.back());
}

TEST(S21Queue, Empty) {
  s21::queue<int> s21_queue_int = {1, 2, 3};
  std::queue<int> std_queue_int;
  std_queue_int.push(1);
  std_queue_int.push(2);
  std_queue_int.push(3);
  EXPECT_EQ(s21_queue_int.empty(), std_queue_int.empty());
  s21::queue<int> s21_queue_empty;
  std::queue<int> std_queue_empty;
  EXPECT_EQ(s21_queue_empty.empty(), std_queue_empty.empty());
}

TEST(S21Queue, Size) {
  s21::queue<int> s21_queue_int = {1, 2, 3};
  std::queue<int> std_queue_int;
  std_queue_int.push(1);
  std_queue_int.push(2);
  std_queue_int.push(3);
  EXPECT_EQ(s21_queue_int.size(), std_queue_int.size());
  s21::queue<int> s21_queue_empty;
  std::queue<int> std_queue_empty;
  EXPECT_EQ(s21_queue_empty.size(), std_queue_empty.size());
}

TEST(S21Queue, Push) {
  s21::queue<int> s21_queue_int;
  s21_queue_int.push(1);
  s21_queue_int.push(2);
  s21_queue_int.push(3);
  std::queue<int> std_queue_int;
  std_queue_int.push(1);
  std_queue_int.push(2);
  std_queue_int.push(3);
  EXPECT_EQ(s21_queue_int.front(), std_queue_int.front());
  EXPECT_EQ(s21_queue_int.back(), std_queue_int.back());
  EXPECT_EQ(s21_queue_int.size(), std_queue_int.size());
  EXPECT_EQ(s21_queue_int.empty(), std_queue_int.empty());
}

TEST(S21Queue, Pop) {
  s21::queue<int> s21_queue_int;
  s21_queue_int.push(1);
  s21_queue_int.push(2);
  s21_queue_int.push(3);
  s21_queue_int.pop();
  std::queue<int> std_queue_int;
  std_queue_int.push(1);
  std_queue_int.push(2);
  std_queue_int.push(3);
  std_queue_int.pop();
  EXPECT_EQ(s21_queue_int.front(), std_queue_int.front());
  EXPECT_EQ(s21_queue_int.back(), std_queue_int.back());
  s21_queue_int.pop();
  s21_queue_int.pop();
  std_queue_int.pop();
  std_queue_int.pop();
  EXPECT_EQ(s21_queue_int.empty(), std_queue_int.empty());
}

TEST(S21Queue, Swap) {
  s21::queue<int> s21_queue_int = {1, 2, 3};
  std::queue<int> std_queue_int;
  std_queue_int.push(1);
  std_queue_int.push(2);
  std_queue_int.push(3);
  s21::queue<int> s21_queue_empty;
  std::queue<int> std_queue_empty;
  s21_queue_empty.swap(s21_queue_int);
  std_queue_empty.swap(std_queue_int);
  EXPECT_EQ(s21_queue_empty.front(), std_queue_empty.front());
  EXPECT_EQ(s21_queue_empty.back(), std_queue_empty.back());
  EXPECT_EQ(s21_queue_int.empty(), std_queue_int.empty());
}

TEST(S21Queue, SwapString) {
  s21::queue<std::string> s21_queue_1 = {"aboba", "shleppa", "amogus",
                                         "abobus"};
  s21::queue<std::string> s21_queue_2 = {"shtirlits", "vovochka", "poruchik"};
  s21::queue<std::string> s21_queue_3 = {"aboba", "shleppa", "amogus",
                                         "abobus"};
  s21::queue<std::string> s21_queue_4 = {"shtirlits", "vovochka", "poruchik"};

  s21_queue_1.swap(s21_queue_2);

  EXPECT_EQ(s21_queue_1.size(), s21_queue_4.size());
  EXPECT_EQ(s21_queue_2.size(), s21_queue_3.size());
  for (auto i = 0; i < 4; i++) {
    EXPECT_EQ(s21_queue_3.front(), s21_queue_2.front());
    EXPECT_EQ(s21_queue_3.size(), s21_queue_2.size());
    s21_queue_3.pop(), s21_queue_2.pop();
  }
  for (auto i = 0; i < 3; i++) {
    EXPECT_EQ(s21_queue_1.front(), s21_queue_4.front());
    EXPECT_EQ(s21_queue_1.size(), s21_queue_4.size());
    s21_queue_1.pop(), s21_queue_4.pop();
  }
}
TEST(S21Queue, InsertManyBack) {
  s21::queue<int> s21_queue_int;
  s21_queue_int.insert_many_back(1, 2, 3);
  EXPECT_EQ(s21_queue_int.front(), 1);
  EXPECT_EQ(s21_queue_int.back(), 3);
}

template <typename T>
bool compare_queues(s21::queue<T> my_queue, std::queue<T> std_queue) {
  bool result = true;
  if (my_queue.size() == std_queue.size()) {
    while (!my_queue.empty() && !std_queue.empty()) {
      if (my_queue.front() != std_queue.front()) {
        result = false;
        break;
      }
      my_queue.pop();
      std_queue.pop();
    }
  } else {
    result = false;
  }
  return result;
}

TEST(QueueTest, CompareQueues) {
  s21::queue<int> my_queue{1, 3, 10, -5, 20};
  std::queue<int> std_queue;
  std_queue.push(1);
  std_queue.push(3);
  std_queue.push(10);
  std_queue.push(-5);
  std_queue.push(20);
  EXPECT_TRUE(compare_queues(my_queue, std_queue));
  std_queue.push(20);
  EXPECT_FALSE(compare_queues(my_queue, std_queue));
}

TEST(QueueTest, DefaultConstructor) {
  s21::queue<int> my_queue;
  std::queue<int> std_queue;
  EXPECT_EQ(my_queue.size(), 0);
  EXPECT_TRUE(my_queue.empty());
  EXPECT_TRUE(compare_queues(my_queue, std_queue));
}

TEST(QueueTest, InitializerqueueConstructor) {
  s21::queue<int> my_queue{1, 2, 3, 7, 9};
  std::initializer_list<int> il = {1, 2, 3, 7, 9};
  std::queue<int> std_queue{il};
  EXPECT_TRUE(compare_queues(my_queue, std_queue));
}

TEST(QueueTest, InitializerqueueConstructor_2) {
  std::initializer_list<int> b;
  s21::queue<int> my_queue{b};
  std::queue<int> std_queue{b};
  EXPECT_TRUE(compare_queues(my_queue, std_queue));
}

TEST(QueueTest, CopyConstructor) {
  s21::queue<int> my_queue{1, 2, 3, 7, 9};
  s21::queue<int> my_queue_copy(my_queue);
  std::initializer_list<int> il = {1, 2, 3, 7, 9};
  std::queue<int> std_queue{il};
  std::queue<int> std_queue_copy(std_queue);
  EXPECT_TRUE(compare_queues(my_queue_copy, std_queue_copy));
}

TEST(QueueTest, CopyConstructorempty) {
  s21::queue<int> my_queue;
  s21::queue<int> my_queue_copy(my_queue);
  std::queue<int> std_queue;
  std::queue<int> std_queue_copy(std_queue);
  EXPECT_TRUE(compare_queues(my_queue_copy, std_queue_copy));
}

TEST(QueueTest, MoveConstructor) {
  s21::queue<int> my_queue{1, 2, 3, 7, 20};
  s21::queue<int> my_queue_copy(my_queue);
  s21::queue<int> my_queue_move(std::move(my_queue));
  std::initializer_list<int> il = {1, 2, 3, 7, 20};
  std::queue<int> std_queue{il};
  std::queue<int> std_queue_copy(std_queue);
  std::queue<int> std_queue_move(std::move(std_queue));
  EXPECT_TRUE(compare_queues(my_queue_copy, std_queue_copy));
}

TEST(QueueTest, MoveConstructorempty) {
  s21::queue<int> my_queue;
  s21::queue<int> my_queue_copy(my_queue);
  s21::queue<int> my_queue_move(std::move(my_queue));
  std::queue<int> std_queue;
  std::queue<int> std_queue_copy(std_queue);
  std::queue<int> std_queue_move(std::move(std_queue));
  EXPECT_TRUE(compare_queues(my_queue_copy, std_queue_copy));
}

TEST(QueueTest, MoveAssignmentoperator) {
  s21::queue<int> my_queue{1, 2, 3, 7, 20};
  s21::queue<int> my_queue_copy(my_queue);
  s21::queue<int> my_queue_move = std::move(my_queue);
  std::initializer_list<int> il = {1, 2, 3, 7, 20};
  std::queue<int> std_queue{il};
  std::queue<int> std_queue_copy(std_queue);
  std::queue<int> std_queue_move = std::move(std_queue);
  EXPECT_TRUE(compare_queues(my_queue_move, std_queue_move));
}

TEST(QueueTest, MoveAssignmentoperatorempty) {
  s21::queue<int> my_queue;
  s21::queue<int> my_queue_copy(my_queue);
  s21::queue<int> my_queue_move = std::move(my_queue);
  std::queue<int> std_queue;
  std::queue<int> std_queue_copy(std_queue);
  std::queue<int> std_queue_move = std::move(std_queue);
  EXPECT_TRUE(compare_queues(my_queue_move, std_queue_move));
}

TEST(QueueTest, front) {
  s21::queue<int> my_queue{99, 2, 3, 4, 5};
  std::initializer_list<int> il = {99, 1, 3, 7, 20};
  std::queue<int> std_queue{il};
  EXPECT_EQ(my_queue.front(), std_queue.front());
}

TEST(QueueTest, back) {
  s21::queue<int> my_queue{1, 2, 3, 3, 4, 99};
  std::initializer_list<int> il = {99, 1, 3, 5, 4, 7, 99};
  std::queue<int> std_queue{il};
  EXPECT_EQ(my_queue.back(), std_queue.back());
}

TEST(QueueTest, empty) {
  s21::queue<int> my_queue;
  std::queue<int> std_queue;
  EXPECT_EQ(my_queue.empty(), std_queue.empty());
  my_queue.push(2354);
  std_queue.push(2354);
  EXPECT_EQ(my_queue.empty(), std_queue.empty());
}

TEST(QueueTest, size) {
  s21::queue<int> my_queue{1, 2, 3, 4, 5, 6, 7, 8};
  std::initializer_list<int> il = {1, 2, 3, 4, 5, 6, 7, 8};
  std::queue<int> std_queue{il};
  EXPECT_EQ(my_queue.size(), std_queue.size());
}

TEST(QueueTest, push) {
  s21::queue<int> my_queue;
  std::queue<int> std_queue;
  my_queue.push(627);
  std_queue.push(627);
  my_queue.push(2354);
  std_queue.push(2354);
  EXPECT_TRUE(compare_queues(my_queue, std_queue));
}

TEST(QueueTest, pop) {
  s21::queue<int> my_queue{1, 2, 3, 4, 5, 6, 7, 8};
  std::initializer_list<int> il = {1, 2, 3, 4, 5, 6, 7, 8};
  std::queue<int> std_queue{il};
  my_queue.pop();
  my_queue.pop();
  std_queue.pop();
  std_queue.pop();
  EXPECT_TRUE(compare_queues(my_queue, std_queue));
  EXPECT_EQ(my_queue.front(), 3);
}

TEST(QueueTest, swap) {
  s21::queue<int> my_queue1{1, 2, 3, 4, 5};
  s21::queue<int> my_queue2{6, 7, 8, 9, 10, 11};
  my_queue1.swap(my_queue2);

  std::initializer_list<int> il1 = {1, 2, 3, 4, 5};
  std::initializer_list<int> il2 = {6, 7, 8, 9, 10, 11};
  std::queue<int> std_queue1{il1};
  std::queue<int> std_queue2{il2};
  std_queue1.swap(std_queue2);

  EXPECT_TRUE(compare_queues(my_queue1, std_queue1));
  EXPECT_TRUE(compare_queues(my_queue2, std_queue2));
}

TEST(QueueTest, swap_2) {
  s21::queue<int> my_queue1{1, 2, 99, 4, 242};
  s21::queue<int> my_queue2;
  my_queue1.swap(my_queue2);

  std::initializer_list<int> il = {1, 2, 99, 4, 242};
  std::queue<int> std_queue1{il};
  std::queue<int> std_queue2;
  std_queue1.swap(std_queue2);

  EXPECT_TRUE(compare_queues(my_queue1, std_queue1));
  EXPECT_TRUE(compare_queues(my_queue2, std_queue2));
}

//////////////////////////////////////////////////////////// EXPECT_THROW
///////////////////////////////////////////////////////////////

TEST(S21Queue, PopEmptytack) {
  s21::queue<int> s21_queue_int;
  s21::queue<double> s21_queue_double;
  s21::queue<std::string> s21_queue_string;

  EXPECT_THROW(s21_queue_int.pop(), std::out_of_range);
  EXPECT_THROW(s21_queue_double.pop(), std::out_of_range);
  EXPECT_THROW(s21_queue_string.pop(), std::out_of_range);
}

TEST(S21Queue, FrontEmptyStack) {
  s21::queue<int> s21_queue_int;
  s21::queue<double> s21_queue_double;
  s21::queue<std::string> s21_queue_string;

  EXPECT_THROW(s21_queue_int.front(), std::out_of_range);
  EXPECT_THROW(s21_queue_double.front(), std::out_of_range);
  EXPECT_THROW(s21_queue_string.front(), std::out_of_range);
}
TEST(S21Queue, BackEmptyStack) {
  s21::queue<int> s21_queue_int;
  s21::queue<double> s21_queue_double;
  s21::queue<std::string> s21_queue_string;

  EXPECT_THROW(s21_queue_int.back(), std::out_of_range);
  EXPECT_THROW(s21_queue_double.back(), std::out_of_range);
  EXPECT_THROW(s21_queue_string.back(), std::out_of_range);
}
