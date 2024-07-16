#include "test_main.h"

TEST(S21Array, ConstructAnyTypes) {
  s21::array<int, 5> s21_arr_int{1, 4, 8, 9, 1};
  s21::array<double, 5> s21_arr_double{1.4, 4.8, 8.9, 9.1, 1.1};
  s21::array<std::string, 5> s21_arr_string{"Hello", ",", "world", "!", "!!"};

  EXPECT_EQ(s21_arr_int.size(), 5);
  EXPECT_EQ(s21_arr_int[0], 1);

  EXPECT_EQ(s21_arr_double.size(), 5);
  EXPECT_EQ(s21_arr_double[0], 1.4);

  EXPECT_EQ(s21_arr_string.size(), 5);
  EXPECT_EQ(s21_arr_string[0], "Hello");
}

TEST(S21Array, ConstructAnyTypesEmpty) {
  s21::array<int, 4> s21_arr_int;
  s21::array<double, 4> s21_arr_double;
  s21::array<std::string, 4> s21_arr_string;

  EXPECT_EQ(s21_arr_int.size(), 4);
  EXPECT_EQ(s21_arr_double.size(), 4);
  EXPECT_EQ(s21_arr_string.size(), 4);
}

TEST(S21Array, CopyConstructor) {
  s21::array<int, 4> s21_arr_ref_int{1, 4, 8, 9};
  s21::array<int, 4> s21_arr_res_int(s21_arr_ref_int);

  s21::array<double, 4> s21_arr_ref_double{1.4, 4.8, 8.9, 9.1};
  s21::array<double, 4> s21_arr_res_double(s21_arr_ref_double);

  s21::array<std::string, 4> s21_arr_ref_string{"Hello", ",", "world", "!"};
  s21::array<std::string, 4> s21_arr_res_string(s21_arr_ref_string);

  EXPECT_EQ(s21_arr_ref_int.size(), s21_arr_res_int.size());
  EXPECT_EQ(s21_arr_ref_int[0], s21_arr_res_int[0]);
  EXPECT_EQ(s21_arr_ref_int[1], s21_arr_res_int[1]);
  EXPECT_EQ(s21_arr_ref_int[2], s21_arr_res_int[2]);
  EXPECT_EQ(s21_arr_ref_int[3], s21_arr_res_int[3]);

  EXPECT_EQ(s21_arr_ref_double.size(), s21_arr_res_double.size());
  EXPECT_EQ(s21_arr_ref_double[0], s21_arr_res_double[0]);
  EXPECT_EQ(s21_arr_ref_double[1], s21_arr_res_double[1]);
  EXPECT_EQ(s21_arr_ref_double[2], s21_arr_res_double[2]);
  EXPECT_EQ(s21_arr_ref_double[3], s21_arr_res_double[3]);

  EXPECT_EQ(s21_arr_ref_string.size(), s21_arr_res_string.size());
  EXPECT_EQ(s21_arr_ref_string[0], s21_arr_res_string[0]);
  EXPECT_EQ(s21_arr_ref_string[1], s21_arr_res_string[1]);
  EXPECT_EQ(s21_arr_ref_string[2], s21_arr_res_string[2]);
  EXPECT_EQ(s21_arr_ref_string[3], s21_arr_res_string[3]);
}

TEST(S21Array, MoveConstructor) {
  s21::array<int, 4> s21_arr_ref_int{1, 4, 8, 9};
  s21::array<int, 4> s21_arr_res_int = std::move(s21_arr_ref_int);

  s21::array<double, 4> s21_arr_ref_double{1.4, 4.8, 8.9, 9.1};
  s21::array<double, 4> s21_arr_res_double = std::move(s21_arr_ref_double);

  s21::array<std::string, 4> s21_arr_ref_string{"Hello", ",", "world", "!"};
  s21::array<std::string, 4> s21_arr_res_string = std::move(s21_arr_ref_string);

  EXPECT_EQ(s21_arr_res_int.size(), 4);
  EXPECT_EQ(s21_arr_res_int[0], 1);
  EXPECT_EQ(s21_arr_res_int[1], 4);
  EXPECT_EQ(s21_arr_res_int[2], 8);
  EXPECT_EQ(s21_arr_res_int[3], 9);

  EXPECT_EQ(s21_arr_res_double.size(), 4);
  EXPECT_EQ(s21_arr_res_double[0], 1.4);
  EXPECT_EQ(s21_arr_res_double[1], 4.8);
  EXPECT_EQ(s21_arr_res_double[2], 8.9);
  EXPECT_EQ(s21_arr_res_double[3], 9.1);

  EXPECT_EQ(s21_arr_res_string.size(), 4);
  EXPECT_EQ(s21_arr_res_string[0], "Hello");
  EXPECT_EQ(s21_arr_res_string[1], ",");
  EXPECT_EQ(s21_arr_res_string[2], "world");
  EXPECT_EQ(s21_arr_res_string[3], "!");
}

TEST(S21Array, OperatorMove) {
  s21::array<int, 4> s21_arr_ref_int{1, 4, 8, 9};
  s21::array<int, 4> s21_arr_res_int;
  s21_arr_res_int = std::move(s21_arr_ref_int);

  s21::array<double, 4> s21_arr_ref_double{1.4, 4.8, 8.9, 9.1};
  s21::array<double, 4> s21_arr_res_double;
  s21_arr_res_double = std::move(s21_arr_ref_double);

  s21::array<std::string, 4> s21_arr_ref_string{"Hello", ",", "world", "!"};
  s21::array<std::string, 4> s21_arr_res_string;
  s21_arr_res_string = std::move(s21_arr_ref_string);

  EXPECT_EQ(s21_arr_res_int.size(), 4);
  EXPECT_EQ(s21_arr_res_int[0], 1);
  EXPECT_EQ(s21_arr_res_int[1], 4);
  EXPECT_EQ(s21_arr_res_int[2], 8);
  EXPECT_EQ(s21_arr_res_int[3], 9);

  EXPECT_EQ(s21_arr_res_double.size(), 4);
  EXPECT_EQ(s21_arr_res_double[0], 1.4);
  EXPECT_EQ(s21_arr_res_double[1], 4.8);
  EXPECT_EQ(s21_arr_res_double[2], 8.9);
  EXPECT_EQ(s21_arr_res_double[3], 9.1);

  EXPECT_EQ(s21_arr_res_string.size(), 4);
  EXPECT_EQ(s21_arr_res_string[0], "Hello");
  EXPECT_EQ(s21_arr_res_string[1], ",");
  EXPECT_EQ(s21_arr_res_string[2], "world");
  EXPECT_EQ(s21_arr_res_string[3], "!");
}
TEST(S21Array, OperatorCopy) {
  s21::array<int, 4> s21_arr_ref_int{1, 4, 8, 9};
  s21::array<int, 4> s21_arr_res_int;
  s21_arr_res_int = s21_arr_ref_int;

  s21::array<double, 4> s21_arr_ref_double{1.4, 4.8, 8.9, 9.1};
  s21::array<double, 4> s21_arr_res_double;
  s21_arr_res_double = s21_arr_ref_double;

  s21::array<std::string, 4> s21_arr_ref_string{"Hello", ",", "world", "!"};
  s21::array<std::string, 4> s21_arr_res_string;
  s21_arr_res_string = s21_arr_ref_string;

  EXPECT_EQ(s21_arr_res_int.size(), 4);
  EXPECT_EQ(s21_arr_res_int[0], 1);
  EXPECT_EQ(s21_arr_res_int[1], 4);
  EXPECT_EQ(s21_arr_res_int[2], 8);
  EXPECT_EQ(s21_arr_res_int[3], 9);

  EXPECT_EQ(s21_arr_res_double.size(), 4);
  EXPECT_EQ(s21_arr_res_double[0], 1.4);
  EXPECT_EQ(s21_arr_res_double[1], 4.8);
  EXPECT_EQ(s21_arr_res_double[2], 8.9);
  EXPECT_EQ(s21_arr_res_double[3], 9.1);

  EXPECT_EQ(s21_arr_res_string.size(), 4);
  EXPECT_EQ(s21_arr_res_string[0], "Hello");
  EXPECT_EQ(s21_arr_res_string[1], ",");
  EXPECT_EQ(s21_arr_res_string[2], "world");
  EXPECT_EQ(s21_arr_res_string[3], "!");
}

TEST(S21Array, At) {
  s21::array<int, 4> s21_arr_int{1, 4, 8, 9};
  s21::array<double, 4> s21_arr_double{1.4, 4.8, 8.9, 9.1};
  s21::array<std::string, 4> s21_arr_string{"Hello", ",", "world", "!"};

  EXPECT_EQ(s21_arr_int.at(0), 1);
  EXPECT_EQ(s21_arr_double.at(0), 1.4);
  EXPECT_EQ(s21_arr_string.at(0), "Hello");

  const s21::array<int, 4> s21_arr_int_const{1, 4, 8, 9};
  EXPECT_EQ(s21_arr_int_const.at(0), 1);
}

TEST(S21Array, SquareBraces) {
  s21::array<int, 4> s21_arr_int{1, 4, 8, 9};
  s21::array<double, 4> s21_arr_double{1.4, 4.8, 8.9, 9.1};
  s21::array<std::string, 4> s21_arr_string{"Hello", ",", "world", "!"};

  EXPECT_EQ(s21_arr_int[1], 4);
  EXPECT_EQ(s21_arr_double[1], 4.8);
  EXPECT_EQ(s21_arr_string[0], "Hello");

  const s21::array<int, 4> s21_arr_int_const{1, 4, 8, 9};
  EXPECT_EQ(s21_arr_int_const[1], 4);
}

TEST(S21Array, Front) {
  s21::array<int, 4> s21_arr_int{1, 4, 8, 9};
  s21::array<double, 4> s21_arr_double{1.4, 4.8, 8.9, 9.1};
  s21::array<std::string, 4> s21_arr_string{"Hello", ",", "world", "!"};

  EXPECT_EQ(s21_arr_int.front(), 1);
  EXPECT_EQ(s21_arr_double.front(), 1.4);
  EXPECT_EQ(s21_arr_string.front(), "Hello");
}

TEST(S21Array, Back) {
  s21::array<int, 4> s21_arr_int{1, 4, 8, 9};
  s21::array<double, 4> s21_arr_double{1.4, 4.8, 8.9, 9.1};
  s21::array<std::string, 4> s21_arr_string{"Hello", ",", "world", "!"};

  EXPECT_EQ(s21_arr_int.back(), 9);
  EXPECT_EQ(s21_arr_double.back(), 9.1);
  EXPECT_EQ(s21_arr_string.back(), "!");
}

TEST(S21Array, Data) {
  s21::array<int, 4> s21_arr_int{1, 4, 8, 9};
  s21::array<double, 4> s21_arr_double{1.4, 4.8, 8.9, 9.1};
  s21::array<std::string, 4> s21_arr_string{"Hello", ",", "world", "!"};

  EXPECT_EQ(s21_arr_int.data(), &s21_arr_int[0]);
  EXPECT_EQ(s21_arr_double.data(), &s21_arr_double[0]);
  EXPECT_EQ(s21_arr_string.data(), &s21_arr_string[0]);
}

TEST(S21Array, Begin) {
  s21::array<int, 4> s21_arr_int{1, 4, 8, 9};
  s21::array<double, 4> s21_arr_double{1.4, 4.8, 8.9, 9.1};
  s21::array<std::string, 4> s21_arr_string{"Hello", ",", "world", "!"};

  EXPECT_EQ(s21_arr_int.begin(), &s21_arr_int[0]);
  EXPECT_EQ(s21_arr_double.begin(), &s21_arr_double[0]);
  EXPECT_EQ(s21_arr_string.begin(), &s21_arr_string[0]);
}

TEST(S21Array, End) {
  s21::array<int, 4> s21_arr_int{1, 4, 8, 9};
  s21::array<double, 4> s21_arr_double{1.4, 4.8, 8.9, 9.1};
  s21::array<std::string, 4> s21_arr_string{"Hello", ",", "world", "!"};

  EXPECT_EQ(s21_arr_int.end(), &s21_arr_int[0] + 4);
  EXPECT_EQ(s21_arr_double.end(), &s21_arr_double[0] + 4);
  EXPECT_EQ(s21_arr_string.end(), &s21_arr_string[0] + 4);
}

TEST(S21Array, CBegin) {
  const s21::array<int, 5> s21_arr_int{1, 4, 8, 9};
  auto it = s21_arr_int.cbegin();
  EXPECT_EQ(*it, 1);
}

TEST(S21Array, CEnd) {
  const s21::array<int, 4> s21_arr_int{1, 4, 8, 9};
  auto it = s21_arr_int.cend();
  auto beginIt = s21_arr_int.cbegin();
  EXPECT_EQ(it, beginIt + 4);
}

TEST(S21Array, EmptyFalse) {
  s21::array<int, 4> s21_arr_int{1, 4, 8, 9};
  s21::array<double, 4> s21_arr_double{1.4, 4.8, 8.9, 9.1};
  s21::array<std::string, 4> s21_arr_string{"Hello", ",", "world", "!"};

  EXPECT_EQ(s21_arr_int.empty(), 0);
  EXPECT_EQ(s21_arr_double.empty(), 0);
  EXPECT_EQ(s21_arr_string.empty(), 0);
}

TEST(S21Array, EmptyTrue) {
  s21::array<int, 0> s21_arr_int;
  s21::array<double, 0> s21_arr_double;
  s21::array<std::string, 0> s21_arr_string;

  EXPECT_EQ(s21_arr_int.empty(), 1);
  EXPECT_EQ(s21_arr_double.empty(), 1);
  EXPECT_EQ(s21_arr_string.empty(), 1);
}

TEST(S21Array, Size) {
  s21::array<int, 4> s21_arr_int{1, 4, 8, 9};
  s21::array<double, 4> s21_arr_double{1.4, 4.8, 8.9, 9.1};
  s21::array<std::string, 4> s21_arr_string{"Hello", ",", "world", "!"};

  EXPECT_EQ(s21_arr_int.size(), 4);
  EXPECT_EQ(s21_arr_double.size(), 4);
  EXPECT_EQ(s21_arr_string.size(), 4);
}

TEST(S21Array, SizeWithZero) {
  s21::array<int, 0> s21_arr_int;
  s21::array<double, 0> s21_arr_double;
  s21::array<std::string, 0> s21_arr_string;

  EXPECT_EQ(s21_arr_int.size(), 0);
  EXPECT_EQ(s21_arr_double.size(), 0);
  EXPECT_EQ(s21_arr_string.size(), 0);
}

TEST(S21Array, MaxSize) {
  s21::array<int, 4> s21_arr_int{1, 4, 8, 9};
  std::array<int, 4> std_arr_int{1, 4, 8, 9};

  s21::array<double, 4> s21_arr_double{1.4, 4.8, 8.9, 9.1};
  std::array<double, 4> std_arr_double{1.4, 4.8, 8.9, 9.1};

  s21::array<std::string, 4> s21_arr_string{"Hello", ",", "world", "!"};
  std::array<std::string, 4> std_arr_string{"Hello", ",", "world", "!"};

  EXPECT_EQ(s21_arr_int.max_size(), std_arr_int.max_size());
  EXPECT_EQ(s21_arr_double.max_size(), std_arr_double.max_size());
  EXPECT_EQ(s21_arr_string.max_size(), std_arr_string.max_size());
}

TEST(S21Array, Swap) {
  s21::array<int, 4> s21_arr_ref_int{1, 4, 8, 9};
  s21::array<int, 4> s21_arr_res_int{21, 21, 21, 21};

  s21::array<double, 4> s21_arr_ref_double{1.4, 4.8, 8.9, 9.1};
  s21::array<double, 4> s21_arr_res_double{21.0, 21.0, 21.0, 21.0};

  s21::array<std::string, 4> s21_arr_ref_string{"Hello", ",", "world", "!"};
  s21::array<std::string, 4> s21_arr_res_string{"21", "21", "21", "21"};

  s21_arr_ref_int.swap(s21_arr_res_int);
  s21_arr_ref_double.swap(s21_arr_res_double);
  s21_arr_ref_string.swap(s21_arr_res_string);

  EXPECT_EQ(s21_arr_ref_int[3], 21);
  EXPECT_EQ(s21_arr_res_int[0], 1);
  EXPECT_EQ(s21_arr_res_int[1], 4);
  EXPECT_EQ(s21_arr_res_int[2], 8);
  EXPECT_EQ(s21_arr_res_int[3], 9);

  EXPECT_EQ(s21_arr_ref_double[3], 21.0);
  EXPECT_EQ(s21_arr_res_double[0], 1.4);
  EXPECT_EQ(s21_arr_res_double[1], 4.8);
  EXPECT_EQ(s21_arr_res_double[2], 8.9);
  EXPECT_EQ(s21_arr_res_double[3], 9.1);

  EXPECT_EQ(s21_arr_ref_string[3], "21");
  EXPECT_EQ(s21_arr_res_string[0], "Hello");
  EXPECT_EQ(s21_arr_res_string[1], ",");
  EXPECT_EQ(s21_arr_res_string[2], "world");
  EXPECT_EQ(s21_arr_res_string[3], "!");
}

TEST(S21Array, Fill) {
  s21::array<int, 4> s21_arr_int{1, 4, 8, 9};
  s21::array<double, 4> s21_arr_double{1.4, 4.8, 8.9, 9.1};
  s21::array<std::string, 4> s21_arr_string{"Hello", ",", "world", "!"};

  s21_arr_int.fill(21);
  s21_arr_double.fill(21.0);
  s21_arr_string.fill("21");

  EXPECT_EQ(s21_arr_int[0], 21);
  EXPECT_EQ(s21_arr_int[1], 21);
  EXPECT_EQ(s21_arr_int[2], 21);
  EXPECT_EQ(s21_arr_int[3], 21);

  EXPECT_EQ(s21_arr_double[0], 21.0);
  EXPECT_EQ(s21_arr_double[1], 21.0);
  EXPECT_EQ(s21_arr_double[2], 21.0);
  EXPECT_EQ(s21_arr_double[3], 21.0);

  EXPECT_EQ(s21_arr_string[0], "21");
  EXPECT_EQ(s21_arr_string[1], "21");
  EXPECT_EQ(s21_arr_string[2], "21");
  EXPECT_EQ(s21_arr_string[3], "21");
}

TEST(S21Array, iter1) {
  s21::array<int, 10> arr1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::array<int, 10> arr2 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  auto it1 = arr1.begin();
  auto it2 = arr2.begin();
  for (int i = 0; i < 4; i++) ++it1, ++it2;
  EXPECT_EQ(*it1, *it2);
}

TEST(S21Array, iter2) {
  s21::array<int, 10> arr1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::array<int, 10> arr2 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  auto it1 = arr1.end();
  auto it2 = arr2.end();
  for (int i = 0; i < 3; i++) --it1, --it2;
  EXPECT_EQ(*it1, *it2);
}

TEST(S21Array, iter3) {
  s21::array<int, 10> arr1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  auto it1 = arr1.end();
  auto it2 = arr1.end();
  EXPECT_EQ(it1 == it2, true);
}

TEST(S21Array, iter4) {
  s21::array<int, 10> arr1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  auto it1 = arr1.end();
  auto it2 = arr1.end();
  EXPECT_EQ(it1 != it2, false);
}

TEST(S21Array, iter5) {
  s21::array<int, 10> arr1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  auto it1 = arr1.end();
  auto it2 = arr1.end();
  ++it2;
  EXPECT_EQ(it1 == it2, false);
}

//////////////////////////////////////////////////////////// EXPECT_THROW
//////////////////////////////////////////////////////////////////

TEST(s21_array, throw_list) {
  s21::array<int, 5> arr1{1, 2, 3, 4, 5};
  EXPECT_EQ(arr1[0], 1);
  EXPECT_EQ(arr1[1], 2);
  EXPECT_EQ(arr1[2], 3);
  EXPECT_EQ(arr1[3], 4);
  EXPECT_EQ(arr1[4], 5);
  try {
    s21::array<int, 5> arr = {1, 2, 3, 4, 5, 6};
  } catch (const std::out_of_range &ex) {
  }
}

TEST(array_at, AtOutOfRange) {
  s21::array<int, 4> s21_arr_int{1, 4, 8, 9};
  s21::array<double, 4> s21_arr_double{1.4, 4.8, 8.9, 9.1};
  s21::array<std::string, 4> s21_arr_string{"Hello", ",", "world", "!"};

  EXPECT_THROW(s21_arr_int.at(5), std::out_of_range);
  EXPECT_THROW(s21_arr_double.at(5), std::out_of_range);
  EXPECT_THROW(s21_arr_string.at(5), std::out_of_range);

  const s21::array<int, 4> s21_arr_int_const = {1, 4, 8, 9};
  const s21::array<double, 4> s21_arr_double_const = {1.4, 4.8, 8.9, 9.1};
  const s21::array<std::string, 4> s21_arr_string_const = {"Hello", ",",
                                                           "world", "!"};

  EXPECT_THROW(s21_arr_int_const.at(5), std::out_of_range);
  EXPECT_THROW(s21_arr_double_const.at(5), std::out_of_range);
  EXPECT_THROW(s21_arr_string_const.at(5), std::out_of_range);
}
