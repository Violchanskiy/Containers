#include "test_main.h"

TEST(S21Stack, ConstructAnyTypes) {
  s21::stack<int> S21Stack_int{1, 4, 8, 9, 1};
  s21::stack<double> S21Stack_double{1.4, 4.8, 8.9, 9.1, 1.1};
  s21::stack<std::string> S21Stack_string{"Hello", ",", "world", "!", "!!"};

  EXPECT_EQ(S21Stack_int.size(), 5);
  EXPECT_EQ(S21Stack_int.top(), 1);

  EXPECT_EQ(S21Stack_double.size(), 5);
  EXPECT_EQ(S21Stack_double.top(), 1.1);

  EXPECT_EQ(S21Stack_string.size(), 5);
  EXPECT_EQ(S21Stack_string.top(), "!!");
}

TEST(StackTest, ConstructorList) {
  s21::stack<int> S21Stack_int = {1, 2, 3};
  std::stack<int> std_stack_int;
  std_stack_int.push(1);
  std_stack_int.push(2);
  std_stack_int.push(3);
  EXPECT_EQ(S21Stack_int.top(), std_stack_int.top());
}

TEST(StackTest, ConstructorList2) {
  std::initializer_list<int> b;
  s21::stack<int> stack{b};
  std::stack<int> std_stack{b};
  EXPECT_EQ(stack.size(), std_stack.size());
}

TEST(S21Stack, CopyConstrucor) {
  s21::stack<int> S21Stack_ref_int{1, 4, 8, 9, 1};
  s21::stack<int> S21Stack_res_int(S21Stack_ref_int);

  s21::stack<double> S21Stack_ref_double{1.4, 4.8, 8.9, 9.1, 1.1};
  s21::stack<double> S21Stack_res_double(S21Stack_ref_double);

  s21::stack<std::string> S21Stack_ref_string{"Hello", ",", "world", "!", "!!"};
  s21::stack<std::string> S21Stack_res_string(S21Stack_ref_string);

  EXPECT_EQ(S21Stack_res_int.size(), 5);
  EXPECT_EQ(S21Stack_res_int.top(), 1);

  EXPECT_EQ(S21Stack_res_double.size(), 5);
  EXPECT_EQ(S21Stack_res_double.top(), 1.1);

  EXPECT_EQ(S21Stack_res_string.size(), 5);
  EXPECT_EQ(S21Stack_res_string.top(), "!!");
}

TEST(S21Stack, CopyOperator) {
  s21::stack<int> S21Stack_ref_int{1, 4, 8, 9, 1};
  s21::stack<int> S21Stack_res_int = S21Stack_ref_int;

  s21::stack<double> S21Stack_ref_double{1.4, 4.8, 8.9, 9.1, 1.1};
  s21::stack<double> S21Stack_res_double = S21Stack_ref_double;

  s21::stack<std::string> S21Stack_ref_string{"Hello", ",", "world", "!", "!!"};
  s21::stack<std::string> S21Stack_res_string = S21Stack_ref_string;

  EXPECT_EQ(S21Stack_res_int.size(), 5);
  EXPECT_EQ(S21Stack_res_int.top(), 1);

  EXPECT_EQ(S21Stack_res_double.size(), 5);
  EXPECT_EQ(S21Stack_res_double.top(), 1.1);

  EXPECT_EQ(S21Stack_res_string.size(), 5);
  EXPECT_EQ(S21Stack_res_string.top(), "!!");
}

TEST(S21Stack, MoveConstructor) {
  s21::stack<int> S21Stack_ref_int{1, 4, 8, 9, 1};
  s21::stack<int> S21Stack_res_int = std::move(S21Stack_ref_int);

  s21::stack<double> S21Stack_ref_double{1.4, 4.8, 8.9, 9.1, 1.1};
  s21::stack<double> S21Stack_res_double = std::move(S21Stack_ref_double);

  s21::stack<std::string> S21Stack_ref_string{"Hello", ",", "world", "!", "!!"};
  s21::stack<std::string> S21Stack_res_string = std::move(S21Stack_ref_string);

  EXPECT_EQ(S21Stack_ref_int.size(), 0);
  EXPECT_EQ(S21Stack_res_int.size(), 5);
  EXPECT_EQ(S21Stack_res_int.top(), 1);

  EXPECT_EQ(S21Stack_ref_double.size(), 0);
  EXPECT_EQ(S21Stack_res_double.size(), 5);
  EXPECT_EQ(S21Stack_res_double.top(), 1.1);

  EXPECT_EQ(S21Stack_ref_string.size(), 0);
  EXPECT_EQ(S21Stack_res_string.size(), 5);
  EXPECT_EQ(S21Stack_res_string.top(), "!!");
}

TEST(S21Stack, MoveOperator) {
  s21::stack<int> S21Stack_ref_int{1, 4, 8, 9, 1};
  s21::stack<int> S21Stack_res_int;
  S21Stack_res_int = std::move(S21Stack_ref_int);

  s21::stack<double> S21Stack_ref_double{1.4, 4.8, 8.9, 9.1, 1.1};
  s21::stack<double> S21Stack_res_double;
  S21Stack_res_double = std::move(S21Stack_ref_double);

  s21::stack<std::string> S21Stack_ref_string{"Hello", ",", "world", "!", "!!"};
  s21::stack<std::string> S21Stack_res_string;
  S21Stack_res_string = std::move(S21Stack_ref_string);

  EXPECT_EQ(S21Stack_ref_int.size(), 0);
  EXPECT_EQ(S21Stack_res_int.size(), 5);
  EXPECT_EQ(S21Stack_res_int.top(), 1);

  EXPECT_EQ(S21Stack_ref_double.size(), 0);
  EXPECT_EQ(S21Stack_res_double.size(), 5);
  EXPECT_EQ(S21Stack_res_double.top(), 1.1);

  EXPECT_EQ(S21Stack_ref_string.size(), 0);
  EXPECT_EQ(S21Stack_res_string.size(), 5);
  EXPECT_EQ(S21Stack_res_string.top(), "!!");
}

TEST(S21Stack, emptyFalse) {
  s21::stack<int> S21Stack_int{1, 4, 8, 9, 1};
  s21::stack<double> S21Stack_double{1.4, 4.8, 8.9, 9.1, 1.1};
  s21::stack<std::string> S21Stack_string{"Hello", ",", "world", "!", "!!"};

  EXPECT_EQ(S21Stack_int.empty(), 0);
  EXPECT_EQ(S21Stack_double.empty(), 0);
  EXPECT_EQ(S21Stack_string.empty(), 0);
}

TEST(S21Stack, emptyTrue) {
  s21::stack<int> S21Stack_int;
  s21::stack<double> S21Stack_double;
  s21::stack<std::string> S21Stack_string;

  EXPECT_EQ(S21Stack_int.empty(), 1);
  EXPECT_EQ(S21Stack_double.empty(), 1);
  EXPECT_EQ(S21Stack_string.empty(), 1);
}

TEST(S21Stack, size) {
  s21::stack<int> S21Stack_int{1, 4, 8, 9, 1};
  s21::stack<double> S21Stack_double{1.4, 4.8, 8.9, 9.1, 1.1};
  s21::stack<std::string> S21Stack_string{"Hello", ",", "world", "!", "!!"};

  EXPECT_EQ(S21Stack_int.size(), 5);
  EXPECT_EQ(S21Stack_double.size(), 5);
  EXPECT_EQ(S21Stack_string.size(), 5);
}

TEST(S21Stack, sizeZero) {
  s21::stack<int> S21Stack_int;
  s21::stack<double> S21Stack_double;
  s21::stack<std::string> S21Stack_string;

  EXPECT_EQ(S21Stack_int.size(), 0);
  EXPECT_EQ(S21Stack_double.size(), 0);
  EXPECT_EQ(S21Stack_string.size(), 0);
}

TEST(S21Stack, top) {
  s21::stack<int> S21Stack_int{1, 4, 8, 9, 1};
  s21::stack<double> S21Stack_double{1.4, 4.8, 8.9, 9.1, 1.1};
  s21::stack<std::string> S21Stack_string{"Hello", ",", "world", "!", "!!"};

  EXPECT_EQ(S21Stack_int.top(), 1);
  EXPECT_EQ(S21Stack_double.top(), 1.1);
  EXPECT_EQ(S21Stack_string.top(), "!!");
}

TEST(S21Stack, push) {
  s21::stack<int> S21Stack_int{1, 4, 8, 9, 1};
  s21::stack<double> S21Stack_double{1.4, 4.8, 8.9, 9.1, 1.1};
  s21::stack<std::string> S21Stack_string{"Hello", ",", "world", "!", "!!"};

  S21Stack_int.push(255);
  S21Stack_double.push(255.0);
  S21Stack_string.push("255");

  EXPECT_EQ(S21Stack_int.top(), 255);
  EXPECT_EQ(S21Stack_double.top(), 255.0);
  EXPECT_EQ(S21Stack_string.top(), "255");
}

TEST(S21Stack, pushemptyStack) {
  s21::stack<int> S21Stack_int;
  s21::stack<double> S21Stack_double;
  s21::stack<std::string> S21Stack_string;

  S21Stack_int.push(255);
  S21Stack_double.push(255.0);
  S21Stack_string.push("255");

  EXPECT_EQ(S21Stack_int.top(), 255);
  EXPECT_EQ(S21Stack_double.top(), 255.0);
  EXPECT_EQ(S21Stack_string.top(), "255");
}

TEST(S21Stack, pop) {
  s21::stack<int> S21Stack_int{1, 4, 8, 9, 1};
  s21::stack<double> S21Stack_double{1.4, 4.8, 8.9, 9.1, 1.1};
  s21::stack<std::string> S21Stack_string{"Hello", ",", "world", "!", "!!"};

  S21Stack_int.pop();
  S21Stack_double.pop();
  S21Stack_string.pop();

  EXPECT_EQ(S21Stack_int.top(), 9);
  EXPECT_EQ(S21Stack_double.top(), 9.1);
  EXPECT_EQ(S21Stack_string.top(), "!");
}

TEST(S21Stack, swapWithempty) {
  s21::stack<int> S21Stack_ref_int{1, 4, 8, 9, 1};
  s21::stack<int> S21Stack_res_int;

  s21::stack<double> S21Stack_ref_double{1.4, 4.8, 8.9, 9.1, 1.1};
  s21::stack<double> S21Stack_res_double;

  s21::stack<std::string> S21Stack_ref_string{"Hello", ",", "world", "!", "!!"};
  s21::stack<std::string> S21Stack_res_string;

  S21Stack_ref_int.swap(S21Stack_res_int);
  S21Stack_ref_double.swap(S21Stack_res_double);
  S21Stack_ref_string.swap(S21Stack_res_string);

  EXPECT_EQ(S21Stack_ref_int.size(), 0);
  EXPECT_EQ(S21Stack_res_int.size(), 5);
  EXPECT_EQ(S21Stack_res_int.top(), 1);

  EXPECT_EQ(S21Stack_ref_double.size(), 0);
  EXPECT_EQ(S21Stack_res_double.size(), 5);
  EXPECT_EQ(S21Stack_res_double.top(), 1.1);

  EXPECT_EQ(S21Stack_ref_string.size(), 0);
  EXPECT_EQ(S21Stack_res_string.size(), 5);
  EXPECT_EQ(S21Stack_res_string.top(), "!!");
}

TEST(S21Stack, swap) {
  s21::stack<int> S21Stack_ref_int{1, 4, 8, 9, 1};
  s21::stack<int> S21Stack_res_int{12, 13, 14};

  s21::stack<double> S21Stack_ref_double{1.4, 4.8, 8.9, 9.1, 1.1};
  s21::stack<double> S21Stack_res_double{13.0};

  s21::stack<std::string> S21Stack_ref_string{"Hello", ",", "world", "!", "!!"};
  s21::stack<std::string> S21Stack_res_string{"14", "15"};

  S21Stack_ref_int.swap(S21Stack_res_int);
  S21Stack_ref_double.swap(S21Stack_res_double);
  S21Stack_ref_string.swap(S21Stack_res_string);

  EXPECT_EQ(S21Stack_ref_int.size(), 3);
  EXPECT_EQ(S21Stack_ref_int.top(), 14);
  EXPECT_EQ(S21Stack_res_int.size(), 5);
  EXPECT_EQ(S21Stack_res_int.top(), 1);

  EXPECT_EQ(S21Stack_ref_double.size(), 1);
  EXPECT_EQ(S21Stack_ref_double.top(), 13.0);
  EXPECT_EQ(S21Stack_res_double.size(), 5);
  EXPECT_EQ(S21Stack_res_double.top(), 1.1);

  EXPECT_EQ(S21Stack_ref_string.size(), 2);
  EXPECT_EQ(S21Stack_ref_string.top(), "15");
  EXPECT_EQ(S21Stack_res_string.size(), 5);
  EXPECT_EQ(S21Stack_res_string.top(), "!!");
}

TEST(S21Stack, InsertManyfront) {
  s21::stack<int> S21Stack_int;
  S21Stack_int.insert_many_front(1, 2, 3);
  EXPECT_EQ(S21Stack_int.top(), 3);
}

TEST(StackTest, Constructor_default) {
  s21::stack<int> s21_stack;
  std::stack<int> std_stack;
  EXPECT_EQ(s21_stack.size(), std_stack.size());
}

TEST(StackTest, Constructor_initializer_list_1) {
  s21::stack<int> s21_stack{1, 2, 4};
  EXPECT_EQ(s21_stack.size(), 3);
  EXPECT_EQ(s21_stack.top(), 4);
}

TEST(StackTest, Constructor_initializer_list_2) {
  std::initializer_list<int> b;
  s21::stack<int> s21_stack{b};
  std::stack<int> std_stack{b};

  EXPECT_EQ(s21_stack.size(), std_stack.size());
}

TEST(StackTest, Constructor_copy_1) {
  std::initializer_list<int> il1 = {1, 2, 3};
  s21::stack<int> s21_stack{il1};
  s21::stack<int> s21_stack_copy{s21_stack};
  std::stack<int> std_stack{il1};
  std::stack<int> std_stack_copy{std_stack};
  EXPECT_EQ(s21_stack_copy.size(), std_stack_copy.size());
  EXPECT_EQ(s21_stack_copy.top(), std_stack_copy.top());
}

TEST(StackTest, Constructor_move_1) {
  std::initializer_list<int> il1 = {1, 2, 3};

  s21::stack<int> s21_stack{il1};
  s21::stack<int> s21_stack_move{s21_stack};
  std::stack<int> std_stack{il1};
  std::stack<int> std_stack_move{std_stack};
  EXPECT_EQ(s21_stack_move.size(), std_stack_move.size());
  EXPECT_EQ(s21_stack_move.top(), std_stack_move.top());
}

TEST(StackTest, Opertator_move_1) {
  std::initializer_list<int> il1 = {1, 2, 3};
  std::initializer_list<int> il2 = {4, 5, 6, 7};

  s21::stack<int> s21_stack{il1};
  s21::stack<int> s21_stack_move{il2};
  s21_stack = std::move(s21_stack_move);

  std::stack<int> std_stack{il1};
  std::stack<int> std_stack_move{il2};
  std_stack = std::move(std_stack_move);

  EXPECT_EQ(s21_stack.size(), std_stack.size());
  EXPECT_EQ(s21_stack.top(), std_stack.top());
}

TEST(StackTest, Opertator_move_2) {
  std::initializer_list<int> il1 = {4, 5, 6, 7};
  std::initializer_list<int> il2 = {1, 2, 3};

  s21::stack<int> s21_stack{il1};
  s21::stack<int> s21_stack_move{il2};
  s21_stack = std::move(s21_stack_move);

  std::stack<int> std_stack{il1};
  std::stack<int> std_stack_move{il2};
  std_stack = std::move(std_stack_move);

  EXPECT_EQ(s21_stack.size(), std_stack.size());
  EXPECT_EQ(s21_stack.top(), std_stack.top());
}

TEST(StackTest, Opertator_move_3) {
  std::initializer_list<int> il1;
  std::initializer_list<int> il2 = {4, 5, 6, 7};

  s21::stack<int> s21_stack{il1};
  s21::stack<int> s21_stack_move{il2};
  s21_stack = std::move(s21_stack_move);

  std::stack<int> std_stack{il1};
  std::stack<int> std_stack_move{il2};
  std_stack = std::move(std_stack_move);

  EXPECT_EQ(s21_stack.size(), std_stack.size());
  EXPECT_EQ(s21_stack.top(), std_stack.top());
}

TEST(StackTest, top_1) {
  std::initializer_list<int> il1 = {4, 5, 6, 7};

  s21::stack<int> s21_stack{il1};

  std::stack<int> std_stack{il1};

  EXPECT_EQ(s21_stack.top(), std_stack.top());
}

TEST(StackTest, empty_1) {
  std::initializer_list<int> il1 = {4, 5, 6, 7};

  s21::stack<int> s21_stack{il1};
  std::stack<int> std_stack{il1};

  EXPECT_EQ(s21_stack.empty(), std_stack.empty());
}

TEST(StackTest, empty_2) {
  std::initializer_list<int> il1;

  s21::stack<int> s21_stack{il1};
  std::stack<int> std_stack{il1};

  EXPECT_EQ(s21_stack.empty(), std_stack.empty());
}

TEST(StackTest, size_1) {
  std::initializer_list<int> il1 = {4, 5, 6, 7};

  s21::stack<int> s21_stack{il1};
  std::stack<int> std_stack{il1};

  EXPECT_EQ(s21_stack.size(), std_stack.size());
}

TEST(StackTest, size_2) {
  std::initializer_list<int> il1 = {4, 5, 6, 7};

  s21::stack<int> s21_stack{il1};
  std::stack<int> std_stack{il1};

  EXPECT_EQ(s21_stack.size(), std_stack.size());
}

TEST(StackTest, push_1) {
  std::initializer_list<int> il1 = {4, 5, 6, 7};

  s21::stack<int> s21_stack{il1};
  std::stack<int> std_stack{il1};
  s21_stack.push(1);
  std_stack.push(1);
  EXPECT_EQ(s21_stack.size(), std_stack.size());
  EXPECT_EQ(s21_stack.top(), std_stack.top());
}

TEST(StackTest, push_2) {
  std::initializer_list<int> il1;

  s21::stack<int> s21_stack{il1};
  std::stack<int> std_stack{il1};
  s21_stack.push(1);
  std_stack.push(1);
  EXPECT_EQ(s21_stack.size(), std_stack.size());
  EXPECT_EQ(s21_stack.top(), std_stack.top());
}

TEST(StackTest, pop_1) {
  std::initializer_list<int> il1 = {4, 5, 6, 7};

  s21::stack<int> s21_stack{il1};
  std::stack<int> std_stack{il1};
  s21_stack.pop();
  std_stack.pop();
  EXPECT_EQ(s21_stack.size(), std_stack.size());
  EXPECT_EQ(s21_stack.top(), std_stack.top());
}

TEST(StackTest, pop_2) {
  std::initializer_list<int> il1;

  s21::stack<int> s21_stack{il1};
  std::stack<int> std_stack{il1};
  EXPECT_EQ(s21_stack.size(), 0);
}

TEST(StackTest, swap_1) {
  std::initializer_list<int> il1 = {4, 5, 6, 7};
  std::initializer_list<int> il2 = {1, 2, 3};

  s21::stack<int> s21_stack{il1};
  s21::stack<int> s21_stack_swap{il2};
  std::stack<int> std_stack{il1};
  std::stack<int> std_stack_swap{il2};
  s21_stack.swap(s21_stack_swap);
  std_stack.swap(std_stack_swap);

  EXPECT_EQ(s21_stack.size(), std_stack.size());
  EXPECT_EQ(s21_stack.top(), std_stack.top());

  EXPECT_EQ(s21_stack_swap.size(), std_stack_swap.size());
  EXPECT_EQ(s21_stack_swap.top(), std_stack_swap.top());
}

TEST(StackTest, swap_2) {
  std::initializer_list<int> il1 = {1, 2, 3};
  std::initializer_list<int> il2 = {4, 5, 6, 7};

  s21::stack<int> s21_stack{il1};
  s21::stack<int> s21_stack_swap{il2};
  std::stack<int> std_stack{il1};
  std::stack<int> std_stack_swap{il2};
  s21_stack.swap(s21_stack_swap);
  std_stack.swap(std_stack_swap);

  EXPECT_EQ(s21_stack.size(), std_stack.size());
  EXPECT_EQ(s21_stack.top(), std_stack.top());

  EXPECT_EQ(s21_stack_swap.size(), std_stack_swap.size());
  EXPECT_EQ(s21_stack_swap.top(), std_stack_swap.top());
}

TEST(StackTest, swap_3) {
  std::initializer_list<int> il1 = {4, 5, 6, 7};
  std::initializer_list<int> il2;

  s21::stack<int> s21_stack{il1};
  s21::stack<int> s21_stack_swap{il2};
  std::stack<int> std_stack{il1};
  std::stack<int> std_stack_swap{il2};
  s21_stack.swap(s21_stack_swap);
  std_stack.swap(std_stack_swap);

  EXPECT_EQ(s21_stack.size(), std_stack.size());

  EXPECT_EQ(s21_stack_swap.size(), std_stack_swap.size());
}

TEST(StackTest, swap_4) {
  std::initializer_list<int> il1;
  std::initializer_list<int> il2 = {4, 5, 6, 7};

  s21::stack<int> s21_stack{il1};
  s21::stack<int> s21_stack_swap{il2};
  std::stack<int> std_stack{il1};
  std::stack<int> std_stack_swap{il2};
  s21_stack.swap(s21_stack_swap);
  std_stack.swap(std_stack_swap);

  EXPECT_EQ(s21_stack.size(), std_stack.size());

  EXPECT_EQ(s21_stack_swap.size(), std_stack_swap.size());
}

TEST(StackTest, swap_5) {
  std::initializer_list<int> il1;
  std::initializer_list<int> il2;

  s21::stack<int> s21_stack{il1};
  s21::stack<int> s21_stack_swap{il2};
  std::stack<int> std_stack{il1};
  std::stack<int> std_stack_swap{il2};
  s21_stack.swap(s21_stack_swap);
  std_stack.swap(std_stack_swap);

  EXPECT_EQ(s21_stack.size(), std_stack.size());

  EXPECT_EQ(s21_stack_swap.size(), std_stack_swap.size());
}

TEST(StackTest, swap_6) {
  std::initializer_list<int> il1 = {4, 5, 6, 7};
  std::initializer_list<int> il2 = {4, 5, 6, 7};

  s21::stack<int> s21_stack{il1};
  s21::stack<int> s21_stack_swap{il2};
  std::stack<int> std_stack{il1};
  std::stack<int> std_stack_swap{il2};
  s21_stack.swap(s21_stack_swap);
  std_stack.swap(std_stack_swap);

  EXPECT_EQ(s21_stack.size(), std_stack.size());
  EXPECT_EQ(s21_stack.top(), std_stack.top());

  EXPECT_EQ(s21_stack_swap.size(), std_stack_swap.size());
  EXPECT_EQ(s21_stack_swap.top(), std_stack_swap.top());
}

TEST(StackTest, Move) {
  s21::stack<int> s1{1, 2, 3, 4, 5, 6};
  s21::stack<int> s2{6, 5, 4, 3, 2, 1};
  s2 = (std::move(s1));

  EXPECT_EQ(s2.top(), 6);
  s2.pop();
  EXPECT_EQ(s2.top(), 5);
  s2.pop();
  EXPECT_EQ(s2.top(), 4);
  s2.pop();
  EXPECT_EQ(s1.size(), 0);

  s21::stack<int> s3{1, 2, 3, 4, 5, 6};
  s21::stack<int> s4(std::move(s3));
  EXPECT_EQ(s4.top(), 6);
  s4.pop();
  EXPECT_EQ(s4.top(), 5);
  s4.pop();
  EXPECT_EQ(s4.top(), 4);
  s4.pop();

  EXPECT_EQ(s3.size(), 0);
}

//////////////////////////////////////////////////////////// EXPECT_THROW
///////////////////////////////////////////////////////////////
TEST(S21Stack, popemptyStack) {
  s21::stack<int> S21Stack_int;
  s21::stack<double> S21Stack_double;
  s21::stack<std::string> S21Stack_string;

  EXPECT_THROW(S21Stack_int.pop(), std::out_of_range);
  EXPECT_THROW(S21Stack_double.pop(), std::out_of_range);
  EXPECT_THROW(S21Stack_string.pop(), std::out_of_range);
}
TEST(S21Stack, topemptyStack) {
  s21::stack<int> S21Stack_int;
  s21::stack<double> S21Stack_double;
  s21::stack<std::string> S21Stack_string;

  EXPECT_THROW(S21Stack_int.top(), std::out_of_range);
  EXPECT_THROW(S21Stack_double.top(), std::out_of_range);
  EXPECT_THROW(S21Stack_string.top(), std::out_of_range);
}

TEST(StackTest, top_2_throw) {
  std::initializer_list<int> il1;
  s21::stack<int> s21_stack{il1};
  EXPECT_THROW(s21_stack.top(), std::out_of_range);
}
