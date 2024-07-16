#include "test_main.h"

TEST(map, ConstructorDefaultMap) {
  s21::map<int, char> my_empty_map;
  std::map<int, char> orig_empty_map;
  EXPECT_EQ(my_empty_map.empty(), orig_empty_map.empty());
}

TEST(map, ConstructorInitializerMap) {
  s21::map<int, char> my_map = {{1, 'x'}, {2, 'b'}, {3, 'z'}, {4, 'y'}};
  std::map<int, char> orig_map = {{1, 'x'}, {2, 'b'}, {3, 'z'}, {4, 'y'}};
  EXPECT_EQ(my_map.size(), orig_map.size());
  auto my_it = my_map.begin();
  auto orig_it = orig_map.begin();
  for (; my_it != my_map.end(); ++my_it, ++orig_it) {
    EXPECT_TRUE((*my_it).first == (*orig_it).first);
    EXPECT_TRUE((*my_it).second == (*orig_it).second);
  }
}

TEST(map, ConstructorInitializer2Map) {
  s21::map<int, char> my_map;
  std::map<int, char> orig_map;
  EXPECT_EQ(my_map.size(), orig_map.size());
  auto my_it = my_map.begin();
  auto orig_it = orig_map.begin();
  for (; my_it != my_map.end(); ++my_it, ++orig_it) {
    EXPECT_TRUE((*my_it).first == (*orig_it).first);
    EXPECT_TRUE((*my_it).second == (*orig_it).second);
  }
}

TEST(map, ConstructorCopyMap) {
  s21::map<int, int> my_map = {{1, 2}, {3, 4}, {5, 6}};
  std::map<int, int> orig_map = {{1, 2}, {3, 4}, {5, 6}};
  s21::map<int, int> my_map_copy = my_map;
  std::map<int, int> orig_map_copy = orig_map;
  EXPECT_EQ(my_map_copy.size(), orig_map_copy.size());
  auto my_it = my_map_copy.begin();
  auto orig_it = orig_map_copy.begin();
  for (; my_it != my_map_copy.end(); ++my_it, ++orig_it) {
    EXPECT_TRUE((*my_it).first == (*orig_it).first);
    EXPECT_TRUE((*my_it).second == (*orig_it).second);
  }
}

TEST(map, ConstructorMoveMap) {
  s21::map<int, int> my_map = {{1, 2}, {3, 4}, {5, 6}};
  std::map<int, int> orig_map = {{1, 2}, {3, 4}, {5, 6}};
  s21::map<int, int> my_map_copy = std::move(my_map);
  std::map<int, int> orig_map_copy = std::move(orig_map);
  EXPECT_EQ(my_map.size(), orig_map.size());
  EXPECT_EQ(my_map_copy.size(), orig_map_copy.size());
  auto my_it = my_map_copy.begin();
  auto orig_it = orig_map_copy.begin();
  for (; my_it != my_map_copy.end(); ++my_it, ++orig_it) {
    EXPECT_TRUE((*my_it).first == (*orig_it).first);
    EXPECT_TRUE((*my_it).second == (*orig_it).second);
  }
}

TEST(map, MapOperator) {
  s21::map<char, std::string> my_map = {
      {'a', "Alina"}, {'b', "Boris"}, {'c', "Chuck"}};
  std::map<char, std::string> orig_map = {
      {'a', "Alina"}, {'b', "Boris"}, {'c', "Chuck"}};
  my_map['a'] = "Alisa";
  orig_map['a'] = "Alisa";
  orig_map['b'] = "Ben";
  EXPECT_TRUE(my_map['a'] == orig_map['a']);
  EXPECT_FALSE(my_map['b'] == orig_map['b']);
  EXPECT_TRUE(my_map['c'] == orig_map['c']);
}

TEST(map, MapAtOperatorException) {
  s21::map<char, std::string> my_map = {
      {'a', "Alina"}, {'b', "Boris"}, {'c', "Chuck"}};
  EXPECT_THROW(my_map.at('g') = "Alisa", std::out_of_range);
}

TEST(map, MapAtOperator) {
  s21::map<char, std::string> my_map = {
      {'a', "Alina"}, {'b', "Boris"}, {'c', "Chuck"}};
  std::map<char, std::string> orig_map = {
      {'a', "Alina"}, {'b', "Boris"}, {'c', "Chuck"}};
  my_map.at('a') = "Alisa";
  orig_map.at('a') = "Alisa";
  orig_map.at('b') = "Ben";
  EXPECT_TRUE(my_map['a'] == orig_map['a']);
  EXPECT_FALSE(my_map['b'] == orig_map['b']);
  EXPECT_TRUE(my_map['c'] == orig_map['c']);
}

TEST(map, MapCapacity) {
  s21::map<char, std::string> my_map;
  std::map<char, std::string> orig_map;
  EXPECT_TRUE(my_map.empty() == orig_map.empty());
  my_map.insert('z', "wow");
  EXPECT_FALSE(my_map.empty() == orig_map.empty());
  EXPECT_EQ(my_map.size(), 1);
}

TEST(map, MapClear) {
  s21::map<int, int> my_map;
  std::map<int, int> orig_map;
  my_map.clear();
  orig_map.clear();
  EXPECT_EQ(my_map.empty(), orig_map.empty());
  my_map.insert(std::make_pair(1, 1));
  orig_map.insert(std::make_pair(1, 1));
  EXPECT_EQ(my_map.empty(), orig_map.empty());
  my_map.clear();
  orig_map.clear();
  EXPECT_EQ(my_map.empty(), orig_map.empty());
}

TEST(map, MapInsert1) {
  s21::map<int, char> my_map;
  std::map<int, char> orig_map;
  my_map.insert(std::make_pair(1, 'a'));
  my_map.insert(std::make_pair(2, 'a'));
  my_map.insert(std::make_pair(3, 'a'));
  orig_map.insert(std::make_pair(1, 'a'));
  orig_map.insert(std::make_pair(2, 'a'));
  orig_map.insert(std::make_pair(3, 'a'));

  auto my_it = my_map.begin();
  auto orig_it = orig_map.begin();
  for (; my_it != my_map.end(); ++my_it, ++orig_it) {
    EXPECT_TRUE((*my_it).first == (*orig_it).first);
    EXPECT_TRUE((*my_it).second == (*orig_it).second);
  }

  auto pr1 = my_map.insert(std::make_pair(1, 'a'));
  auto pr2 = orig_map.insert(std::make_pair(1, 'a'));
  EXPECT_TRUE(pr1.second == pr2.second);
}

TEST(map, MapInsert2) {
  s21::map<int, char> my_map;
  std::map<int, char> orig_map;
  my_map.insert(1, 'a');
  my_map.insert(2, 'a');
  my_map.insert(3, 'a');
  orig_map.insert(std::make_pair(1, 'a'));
  orig_map.insert(std::make_pair(2, 'a'));
  orig_map.insert(std::make_pair(3, 'a'));

  auto my_it = my_map.begin();
  auto orig_it = orig_map.begin();
  for (; my_it != my_map.end(); ++my_it, ++orig_it) {
    EXPECT_TRUE((*my_it).first == (*orig_it).first);
    EXPECT_TRUE((*my_it).second == (*orig_it).second);
  }

  auto pr1 = my_map.insert(1, 'a');
  auto pr2 = orig_map.insert(std::make_pair(1, 'a'));
  EXPECT_TRUE(pr1.second == pr2.second);
}

TEST(map, MapInsert3) {
  s21::map<int, char> my_map;
  std::map<int, char> orig_map;
  my_map.insert(1, 'a');
  my_map.insert(2, 'a');
  my_map.insert(3, 'a');
  orig_map.insert(std::make_pair(1, 'a'));
  orig_map.insert(std::make_pair(2, 'a'));
  orig_map.insert(std::make_pair(3, 'a'));

  auto my_it = my_map.begin();
  auto orig_it = orig_map.begin();
  for (; my_it != my_map.end(); ++my_it, ++orig_it) {
    EXPECT_TRUE((*my_it).first == (*orig_it).first);
    EXPECT_TRUE((*my_it).second == (*orig_it).second);
  }

  auto pr1 = my_map.insert_or_assign(1, 'b');
  auto i = orig_map.begin();
  EXPECT_TRUE((*pr1.first).first == (*i).first);
  EXPECT_FALSE((*pr1.first).second == (*i).second);
}

TEST(map, MapErase) {
  s21::map<int, char> my_map = {{1, 'x'}, {2, 'b'}, {3, 'z'}, {4, 'y'}};
  std::map<int, char> orig_map = {{1, 'x'}, {2, 'b'}, {3, 'z'}, {4, 'y'}};
  EXPECT_EQ(my_map.size(), orig_map.size());
  my_map.erase(my_map.begin());
  orig_map.erase(orig_map.begin());
  EXPECT_EQ(my_map.size(), orig_map.size());
  auto my_it = my_map.begin();
  auto orig_it = orig_map.begin();
  for (; my_it != my_map.end(); ++my_it, ++orig_it) {
    EXPECT_TRUE((*my_it).first == (*orig_it).first);
    EXPECT_TRUE((*my_it).second == (*orig_it).second);
  }
}

TEST(map, SwapMap) {
  s21::map<int, int> my_map = {{1, 1}};
  s21::map<int, int> my_swap_map = {{3, 3}, {4, 4}};

  my_map.swap(my_swap_map);
  EXPECT_EQ(my_map.size(), 2);
  EXPECT_EQ(my_swap_map.size(), 1);
  auto x = (*(my_map.begin())).first;
  auto y = (*(my_swap_map.begin())).first;
  EXPECT_EQ(x, 3);
  EXPECT_EQ(y, 1);
}

TEST(map, MergeMap) {
  s21::map<int, int> my_map = {{1, 1}, {4, 4}, {2, 2}};
  s21::map<int, int> my_map_merge = {{3, 3}, {4, 4}};

  std::map<int, int> orig_map = {{1, 1}, {4, 4}, {2, 2}};
  std::map<int, int> orig_map_merge = {{3, 3}, {4, 4}};

  my_map.merge(my_map_merge);

  orig_map.merge(orig_map_merge);

  auto my_it = my_map.begin();
  auto orig_it = orig_map.begin();
  for (; my_it != my_map.end(); ++my_it, ++orig_it) {
    EXPECT_TRUE((*my_it).first == (*orig_it).first);
    EXPECT_TRUE((*my_it).second == (*orig_it).second);
  }
}

TEST(mapConstructorTest, DefaultConstructor) {
  s21::map<int, std::string> m;
  EXPECT_EQ(m.size(), 0);
  EXPECT_TRUE(m.empty());
}

TEST(mapConstructorTest, InitializerListConstructor) {
  s21::map<int, std::string> m{{1, "one"}, {2, "two"}, {3, "three"}};
  EXPECT_EQ(m.size(), 3);
  EXPECT_FALSE(m.empty());
  EXPECT_EQ(m.at(1), "one");
  EXPECT_EQ(m.at(2), "two");
  EXPECT_EQ(m.at(3), "three");
}

TEST(mapConstructorTest, CopyConstructor) {
  s21::map<int, std::string> m{{1, "one"}, {2, "two"}, {3, "three"}};
  s21::map<int, std::string> copy_m(m);
  EXPECT_EQ(copy_m.size(), 3);
  EXPECT_FALSE(copy_m.empty());
  EXPECT_EQ(copy_m.at(1), "one");
}
// Test the insert(key, value) function
TEST(mapTest, insertKeyValue) {
  s21::map<int, std::string> map;
  // insert a single key-value pair
  map.insert(1, "one");
  // Check that the size is correct
  EXPECT_EQ(map.size(), 1);
  // Check that the inserted key-value pair is in the map
  EXPECT_EQ(map.contains(1), true);
  EXPECT_EQ(map[1], "one");
  // insert another key-value pair
  map.insert(2, "two");
  // Check that the size is correct
  EXPECT_EQ(map.size(), 2);
  // Check that both inserted key-value pairs are in the map
  EXPECT_EQ(map.contains(1), true);
  EXPECT_EQ(map[1], "one");
  EXPECT_EQ(map.contains(2), true);
  EXPECT_EQ(map[2], "two");
}
// Test the insert(pair) function
TEST(mapTest, insertPair) {
  s21::map<int, std::string> map;
  // insert a single key-value pair using a pair object
  map.insert(std::make_pair(1, "one"));
  // Check that the size is correct
  EXPECT_EQ(map.size(), 1);
  // Check that the inserted key-value pair is in the map
  EXPECT_EQ(map.contains(1), true);
  EXPECT_EQ(map[1], "one");
  // insert another key-value pair using a pair object
  map.insert(std::make_pair(2, "two"));
  // Check that the size is correct
  EXPECT_EQ(map.size(), 2);
  // Check that both inserted key-value pairs are in the map
  EXPECT_EQ(map.contains(1), true);
  EXPECT_EQ(map[1], "one");
  EXPECT_EQ(map.contains(2), true);
  EXPECT_EQ(map[2], "two");
}
TEST(mapTest, insertOrAssign) {
  s21::map<int, std::string> map;
  // insert a new element with a key that does not exist.
  auto [it1, inserted1] = map.insert_or_assign(1, "one");
  EXPECT_TRUE(inserted1);
  EXPECT_EQ(it1->first, 1);
  EXPECT_EQ(it1->second, "one");
  // insert a new element with a key that already exists.
  auto [it2, inserted2] = map.insert_or_assign(1, "ONE");
  // EXPECT_FALSE(inserted2);
  // //=====================================================
  EXPECT_EQ(it2->first, 1);
  EXPECT_EQ(it2->second, "ONE");
  // insert multiple elements.
  map.insert_or_assign(2, "two");
  map.insert_or_assign(3, "three");
  map.insert_or_assign(4, "four");
  map.insert_or_assign(5, "five");
  EXPECT_EQ(map.size(), 5);
  EXPECT_EQ(map[1], "ONE");
  EXPECT_EQ(map[2], "two");
  EXPECT_EQ(map[3], "three");
  EXPECT_EQ(map[4], "four");
  EXPECT_EQ(map[5], "five");
}
TEST(mapTest, AtAndOperatorBrackets) {
  s21::map<int, std::string> map = {{1, "one"}, {2, "two"}, {3, "three"}};

  EXPECT_EQ(map.at(1), "one");
  EXPECT_EQ(map[2], "two");

  EXPECT_THROW(map.at(4), std::out_of_range);
  map[4] = "four";
  EXPECT_EQ(map[4], "four");
  map[2] = "TWO";
  EXPECT_EQ(map[2], "TWO");
}

TEST(mapTest, EmptyAndSize) {
  s21::map<int, std::string> empty_map;
  s21::map<int, std::string> map = {{1, "one"}, {2, "two"}, {3, "three"}};

  EXPECT_TRUE(empty_map.empty());
  EXPECT_EQ(empty_map.size(), 0);

  EXPECT_FALSE(map.empty());
  EXPECT_EQ(map.size(), 3);
}

TEST(mapTest, MaxSize) {
  s21::map<int, std::string> map;
  std::map<int, std::string> map1;

  // Max size is implementation-dependent, but it should be greater than 0
  EXPECT_EQ(map.max_size(), map1.max_size());
}
TEST(mapTest, Erase) {
  s21::map<int, std::string> map;

  map.insert({1, "one"});
  map.insert({2, "two"});
  map.insert({3, "three"});
  map.insert({5, "five"});

  // Erase an existing element.
  auto it1 = ++map.begin();

  map.erase(it1);
  EXPECT_EQ(map.size(), 3);

  EXPECT_FALSE(map.contains(2));
}

TEST(mapTest, Swap) {
  s21::map<int, std::string> map1;
  map1.insert({1, "one"});
  map1.insert({2, "two"});

  s21::map<int, std::string> map2;
  map2.insert({3, "three"});
  map2.insert({4, "four"});

  map1.swap(map2);

  EXPECT_EQ(map1.size(), 2);
  EXPECT_TRUE(map1.contains(3));
  EXPECT_TRUE(map1.contains(4));

  EXPECT_EQ(map2.size(), 2);
  EXPECT_TRUE(map2.contains(1));
  EXPECT_TRUE(map2.contains(2));
}

TEST(mapTest, Merge) {
  s21::map<int, std::string> map1;
  map1.insert({1, "one"});
  map1.insert({2, "two"});

  s21::map<int, std::string> map2;
  map2.insert({3, "three"});
  map2.insert({4, "four"});

  map1.merge(map2);

  EXPECT_EQ(map1.size(), 4);
  EXPECT_TRUE(map1.contains(1));
  EXPECT_TRUE(map1.contains(2));
  EXPECT_TRUE(map1.contains(3));
  EXPECT_TRUE(map1.contains(4));
}

TEST(mapTest, Contains) {
  s21::map<int, std::string> map;

  map.insert({1, "one"});
  map.insert({2, "two"});
  EXPECT_TRUE(map.contains(2));
  EXPECT_FALSE(map.contains(3));
}

TEST(Map, Constructor_Default) {
  s21::map<int, std::string> s21_map;
  std::map<int, std::string> std_map;
  EXPECT_EQ(s21_map.size(), std_map.size());
  EXPECT_EQ(s21_map.empty(), std_map.empty());
}

TEST(Map, Constructor_Initializer_list) {
  s21::map<int, std::string> s21_map = {
      {1, "aboba"}, {2, "shleppa"}, {3, "amogus"}, {4, "abobus"}};
  std::map<int, std::string> std_map = {
      {1, "aboba"}, {2, "shleppa"}, {3, "amogus"}, {4, "abobus"}};
  EXPECT_EQ(s21_map.size(), std_map.size());
  EXPECT_EQ(s21_map.empty(), std_map.empty());
}

TEST(Map, Constructor_Copy) {
  s21::map<int, std::string> s21_map_1 = {
      {1, "aboba"}, {2, "shleppa"}, {3, "amogus"}, {4, "abobus"}};
  std::map<int, std::string> std_map_1 = {
      {1, "aboba"}, {2, "shleppa"}, {3, "amogus"}, {4, "abobus"}};
  s21::map<int, std::string> s21_map_2 = s21_map_1;
  std::map<int, std::string> std_map_2 = std_map_1;

  EXPECT_EQ(s21_map_1.size(), s21_map_2.size());
  EXPECT_EQ(std_map_1.size(), std_map_2.size());
  auto it1 = s21_map_1.begin();
  auto it2 = s21_map_2.begin();
  while (it1 != s21_map_1.end()) {
    EXPECT_EQ(it1->first, it2->first);
    EXPECT_EQ(it1->second, it2->second);
    ++it1, ++it2;
  }
}

TEST(Map, Constructor_Move) {
  s21::map<int, std::string> s21_map_1 = {
      {1, "aboba"}, {2, "shleppa"}, {3, "amogus"}, {4, "abobus"}};
  std::map<int, std::string> std_map_1 = {
      {1, "aboba"}, {2, "shleppa"}, {3, "amogus"}, {4, "abobus"}};
  s21::map<int, std::string> s21_map_2 = std::move(s21_map_1);
  std::map<int, std::string> std_map_2 = std::move(std_map_1);

  EXPECT_EQ(s21_map_2.size(), std_map_2.size());
  EXPECT_EQ(s21_map_1.size(), std_map_1.size());
  EXPECT_EQ(s21_map_1.empty(), std_map_1.empty());
  auto it1 = s21_map_2.begin();
  auto it2 = std_map_2.begin();
  while (it1 != s21_map_2.end()) {
    EXPECT_EQ(it1->first, it2->first);
    EXPECT_EQ(it1->second, it2->second);
    ++it1, ++it2;
  }
}

TEST(Map, Modifier_Insert) {
  s21::map<char, int> s21_map_1 = {{'b', 228}, {'c', 1337}};
  s21::map<char, int> s21_map_2 = {
      {'b', 228},
      {'c', 1337},
      {'d', 322},
      {'a', 5},
  };

  EXPECT_EQ(s21_map_1.insert('d', 322).second, true);
  EXPECT_EQ(s21_map_1.insert('d', 14).second, false);

  std::pair<char, int> pair1('a', 5);
  std::pair<char, int> pair2('a', 28);

  EXPECT_EQ(s21_map_1.insert(pair1).second, true);
  EXPECT_EQ(s21_map_1.insert(pair2).second, false);

  auto it1 = s21_map_1.begin();
  auto it2 = s21_map_2.begin();

  while (it1 != s21_map_1.end()) {
    EXPECT_EQ(it1->first, it2->first);
    EXPECT_EQ(it1->second, it2->second);

    ++it1, ++it2;
  }
  EXPECT_EQ(s21_map_1.size(), s21_map_2.size());
}

TEST(Map, Rehash_And_Insert_In_Collision) {
  s21::map<std::string, int> s21_map;
  s21_map.insert("asd", 0);
  s21_map.insert("asa", 1);
  s21_map.insert("asf", 2);
  s21_map.insert("asg", 3);
  s21_map.insert("ash", 4);
  s21_map.insert("aqw", 5);
  s21_map.insert("fgh", 6);
  s21_map.insert("ghf", 7);
  s21_map.insert("dghfg", 8);
  s21_map.insert("dghfdsg", 9);
  s21_map.insert("dghfgfsadfsd", 10);
  s21_map.insert("dghfgfsadfsdasd", 11);
  s21_map.insert("dghfgfsadfsasdasdd", 12);
  s21_map.insert("dghfgfsadfsdasdasd", 13);
  s21_map.insert("dghfgfdsasadfdsasasdsadsad", 14);
  s21_map.insert("dghdsafgfsadfdsasasdsadsad", 15);
  s21_map.insert("ådsdghfgfsadfdsasasdsadsad", 16);
  s21_map.insert("dghfgfsadfdsasasdsaddsasad", 17);
  s21_map.insert("dghfgfsadfdsasassadadsadsad", 18);
  s21_map.insert("dghfgfsadfdsasdasasdsadsad", 19);
  s21_map.insert("dghasdaasdfgfsadfsasdsadsad", 20);
  s21_map.insert("asddghfgfsadfsasaß∂asdsadsad", 21);
  s21_map.insert("dghfgfsadfasdsasdsadsad", 22);
  s21_map.insert("dghfgfsadfsasdsadsad", 23);
  s21_map.insert("dghfgfsasdadfsasdsadsad", 24);
  s21_map.insert("asdsadadghfgfsadfsasdsadsad", 25);
  std::unordered_map<std::string, int> std_map;
  std_map.insert(std::pair<std::string, int>("asd", 0));
  std_map.insert(std::pair<std::string, int>("asa", 1));
  std_map.insert(std::pair<std::string, int>("asf", 2));
  std_map.insert(std::pair<std::string, int>("asg", 3));
  std_map.insert(std::pair<std::string, int>("ash", 4));
  std_map.insert(std::pair<std::string, int>("aqw", 5));
  std_map.insert(std::pair<std::string, int>("fgh", 6));
  std_map.insert(std::pair<std::string, int>("ghf", 7));
  std_map.insert(std::pair<std::string, int>("dghfg", 8));
  std_map.insert(std::pair<std::string, int>("dghfdsg", 9));
  std_map.insert(std::pair<std::string, int>("dghfgfsadfsd", 10));
  std_map.insert(std::pair<std::string, int>("dghfgfsadfsdasd", 11));
  std_map.insert(std::pair<std::string, int>("dghfgfsadfsasdasdd", 12));
  std_map.insert(std::pair<std::string, int>("dghfgfsadfsdasdasd", 13));
  std_map.insert(std::pair<std::string, int>("dghfgfdsasadfdsasasdsadsad", 14));
  std_map.insert(std::pair<std::string, int>("dghdsafgfsadfdsasasdsadsad", 15));
  std_map.insert(std::pair<std::string, int>("ådsdghfgfsadfdsasasdsadsad", 16));
  std_map.insert(std::pair<std::string, int>("dghfgfsadfdsasasdsaddsasad", 17));
  std_map.insert(
      std::pair<std::string, int>("dghfgfsadfdsasassadadsadsad", 18));
  std_map.insert(std::pair<std::string, int>("dghfgfsadfdsasdasasdsadsad", 19));
  std_map.insert(
      std::pair<std::string, int>("dghasdaasdfgfsadfsasdsadsad", 20));
  std_map.insert(
      std::pair<std::string, int>("asddghfgfsadfsasaß∂asdsadsad", 21));
  std_map.insert(std::pair<std::string, int>("dghfgfsadfasdsasdsadsad", 22));
  std_map.insert(std::pair<std::string, int>("dghfgfsadfsasdsadsad", 23));
  std_map.insert(std::pair<std::string, int>("dghfgfsasdadfsasdsadsad", 24));
  std_map.insert(
      std::pair<std::string, int>("asdsadadghfgfsadfsasdsadsad", 25));
  for (auto i : std_map) {
    EXPECT_EQ(i.second, s21_map[i.first]);
  }
  EXPECT_EQ(s21_map.size(), std_map.size());
}

TEST(Map, Modifier_Get_Value) {
  s21::map<std::string, int> m;
  m["123"] = 5;
  EXPECT_EQ(5, m["123"]);
}

TEST(Map, Modifier_Insert_or_assign) {
  s21::map<char, int> s21_map_1 = {{'b', 228}, {'c', 1337}};
  s21::map<char, int> s21_map_2 = {
      {'b', 228},
      {'c', 1337},
      {'d', 14},
      {'a', 28},
  };

  EXPECT_EQ(s21_map_1.insert_or_assign('d', 322).second, true);
  EXPECT_EQ(s21_map_1.insert_or_assign('d', 14).second, false);

  EXPECT_EQ(s21_map_1.insert_or_assign('a', 5).second, true);
  EXPECT_EQ(s21_map_1.insert_or_assign('a', 28).second, false);

  auto it1 = s21_map_1.begin();
  auto it2 = s21_map_2.begin();
  while (it1 != s21_map_1.end()) {
    EXPECT_EQ(it1->first, it2->first);
    EXPECT_EQ(it1->second, it2->second);
    ++it1, ++it2;
  }
  EXPECT_EQ(s21_map_1.size(), s21_map_2.size());
}

TEST(Map, Modifier_Erase_1) {
  s21::map<int, std::string> s21_map_1 = {
      {1, "aboba"}, {2, "shleppa"}, {3, "amogus"}, {4, "abobus"}};
  s21::map<int, std::string> s21_map_2 = {
      {1, "aboba"}, {3, "amogus"}, {4, "abobus"}};
  auto it = s21_map_1.begin();
  ++it;
  s21_map_1.erase(it);
  auto it1 = s21_map_1.begin();
  auto it2 = s21_map_2.begin();
  while (it1 != s21_map_1.end()) {
    EXPECT_EQ(it1->first, it2->first);
    EXPECT_EQ(it1->second, it2->second);
    ++it1, ++it2;
  }
  EXPECT_EQ(s21_map_1.size(), s21_map_2.size());
}

TEST(Map, Modifier_Swap) {
  s21::map<int, std::string> s21_map_1 = {
      {1, "aboba"}, {2, "shleppa"}, {3, "amogus"}, {4, "abobus"}};
  s21::map<int, std::string> s21_map_2 = {
      {10, "shtirlits"}, {12, "vovochka"}, {13, "poruchik"}, {14, "chepaev"}};
  s21::map<int, std::string> s21_map_3 = {
      {1, "aboba"}, {2, "shleppa"}, {3, "amogus"}, {4, "abobus"}};
  s21::map<int, std::string> s21_map_4 = {
      {10, "shtirlits"}, {12, "vovochka"}, {13, "poruchik"}, {14, "chepaev"}};

  s21_map_1.swap(s21_map_2);
  auto it1 = s21_map_1.begin();
  auto it2 = s21_map_2.begin();
  auto it3 = s21_map_3.begin();
  auto it4 = s21_map_4.begin();
  while (it1 != s21_map_1.end()) {
    EXPECT_EQ(*it1, *it4);
    ++it1, ++it4;
  }
  while (it2 != s21_map_2.end()) {
    EXPECT_EQ(*it2, *it3);
    ++it2, ++it3;
  }
  EXPECT_EQ(s21_map_1.size(), s21_map_4.size());
  EXPECT_EQ(s21_map_2.size(), s21_map_3.size());
}

TEST(Map, Lookup_Contains) {
  s21::map<int, std::string> s21_map;
  s21_map.insert(1, "salamandry");
  s21_map.insert(2, "medoedy");
  s21_map.insert(3, "kapibary");
  s21_map.insert(4, "alpaki");
  EXPECT_EQ(s21_map.contains(1), true);
  EXPECT_EQ(s21_map.contains(2), true);
  EXPECT_EQ(s21_map.contains(3), true);
  EXPECT_EQ(s21_map.contains(4), true);
  EXPECT_EQ(s21_map.contains(7), false);
  EXPECT_EQ(s21_map.contains(-2), false);
  EXPECT_EQ(s21_map.contains(0), false);
}

class MapTest : public ::testing::Test {
 public:
  void SetUp(void) override {
    std::srand(42);

    int map_size = 1000;
    for (int i = 0; i < map_size; ++i) {
      int key = rand();
      std::string value = std::to_string(key + i);
      ms21.insert(std::make_pair(key, value));
      mstd.insert(std::make_pair(key, value));
    }

    mms21.insert(std::make_pair(500, std::to_string(500)));
    mmstd.insert(std::make_pair(500, std::to_string(500)));
    mms21.insert(std::make_pair(300, std::to_string(300)));
    mmstd.insert(std::make_pair(300, std::to_string(300)));
    mms21.insert(std::make_pair(800, std::to_string(800)));
    mmstd.insert(std::make_pair(800, std::to_string(800)));
    mms21.insert(std::make_pair(200, std::to_string(200)));
    mmstd.insert(std::make_pair(200, std::to_string(200)));
    mms21.insert(std::make_pair(400, std::to_string(400)));
    mmstd.insert(std::make_pair(400, std::to_string(400)));
    mms21.insert(std::make_pair(600, std::to_string(600)));
    mmstd.insert(std::make_pair(600, std::to_string(600)));
    mms21.insert(std::make_pair(1200, std::to_string(1200)));
    mmstd.insert(std::make_pair(1200, std::to_string(1200)));
    mms21.insert(std::make_pair(100, std::to_string(100)));
    mmstd.insert(std::make_pair(100, std::to_string(100)));
    mms21.insert(std::make_pair(700, std::to_string(700)));
    mmstd.insert(std::make_pair(700, std::to_string(700)));
    mms21.insert(std::make_pair(1000, std::to_string(1000)));
    mmstd.insert(std::make_pair(1000, std::to_string(1000)));
    mms21.insert(std::make_pair(1300, std::to_string(1300)));
    mmstd.insert(std::make_pair(1300, std::to_string(1300)));
    mms21.insert(std::make_pair(900, std::to_string(900)));
    mmstd.insert(std::make_pair(900, std::to_string(900)));
    mms21.insert(std::make_pair(1100, std::to_string(1100)));
    mmstd.insert(std::make_pair(1100, std::to_string(1100)));
  }

  template <typename Key, typename Value>
  bool MapEqual(const s21::map<Key, Value> &lhs,
                const s21::map<Key, Value> &rhs) {
    bool t = true;
    for (auto it = lhs.begin(), it2 = rhs.begin(); it != lhs.end();
         ++it, ++it2) {
      if (it->first != it2->first || it->second != it2->second) t = false;
    }
    return lhs.empty() == rhs.empty() && lhs.size() == rhs.size() && t;
  }
  template <typename Key, typename Value>
  bool MapEqual(const s21::map<Key, Value> &lhs,
                const std::map<Key, Value> &rhs) {
    bool t = true;
    for (auto it = lhs.begin(), it2 = rhs.begin(); it != lhs.end();
         ++it, ++it2) {
      if (it->first != it2->first || it->second != it2->second) t = false;
    }
    return lhs.empty() == rhs.empty() && lhs.size() == rhs.size() && t;
  }
  template <typename Key, typename Value>
  bool MapEqual(const std::map<Key, Value> &lhs,
                const s21::map<Key, Value> &rhs) {
    bool t = true;
    for (auto it = lhs.begin(), it2 = rhs.begin(); it != lhs.end();
         ++it, ++it2) {
      if (it->first != it2->first || it->second != it2->second) t = false;
    }
    return lhs.empty() == rhs.empty() && lhs.size() == rhs.size() && t;
  }

  s21::map<int, std::string> ms21;
  std::map<int, std::string> mstd;

  s21::map<int, std::string> mms21;
  std::map<int, std::string> mmstd;
};

TEST_F(MapTest, DefaultCtor) {
  {
    s21::map<int, int> m;
    EXPECT_TRUE(m.empty());
    EXPECT_EQ(m.size(), 0);
  }
  {
    const s21::map<int, int> m;
    EXPECT_TRUE(m.empty());
    EXPECT_EQ(m.size(), 0);
  }
  {
    s21::map<std::string, std::vector<int>> m;
    EXPECT_TRUE(m.empty());
    EXPECT_EQ(m.size(), 0);
  }
  {
    const s21::map<std::string, std::vector<int>> m;
    EXPECT_TRUE(m.empty());
    EXPECT_EQ(m.size(), 0);
  }
}

TEST_F(MapTest, InitializeCtor) {
  s21::map<int, double> s21_map = {
      std::make_pair(15, 78.1),      std::make_pair(-100, 0.1),
      std::make_pair(158, 278.1),    std::make_pair(254, 30.1),
      std::make_pair(1158, 178.1),   std::make_pair(1254, 40.1),
      std::make_pair(-1158, -178.1), std::make_pair(-1254, -40.1),
      std::make_pair(1, -9178.1),    std::make_pair(0, -40.1),
      std::make_pair(158, 21.3),     std::make_pair(254, 31.1)};
  std::map<int, double> std_map = {
      std::make_pair(15, 78.1),      std::make_pair(-100, 0.1),
      std::make_pair(158, 278.1),    std::make_pair(254, 30.1),
      std::make_pair(1158, 178.1),   std::make_pair(1254, 40.1),
      std::make_pair(-1158, -178.1), std::make_pair(-1254, -40.1),
      std::make_pair(1, -9178.1),    std::make_pair(0, -40.1),
      std::make_pair(158, 21.3),     std::make_pair(254, 31.1)};

  EXPECT_TRUE(MapEqual(s21_map, std_map));

  const s21::map<int, double> s21_cmap = {
      std::make_pair(15, 78.1),
      std::make_pair(-100, 0.1),
      std::make_pair(158, 278.1),
      std::make_pair(254, 30.1),
  };
  const std::map<int, double> std_cmap = {
      std::make_pair(15, 78.1),
      std::make_pair(-100, 0.1),
      std::make_pair(158, 278.1),
      std::make_pair(254, 30.1),
  };

  EXPECT_TRUE(MapEqual(s21_cmap, std_cmap));
}

TEST_F(MapTest, CopyCtor) {
  {
    s21::map<int, std::string> s21_empty_map;
    std::map<int, std::string> std_empty_map;
    s21::map<int, std::string> s21_map(s21_empty_map);
    std::map<int, std::string> std_map(std_empty_map);

    EXPECT_TRUE(MapEqual(s21_empty_map, std_empty_map));
    EXPECT_TRUE(MapEqual(s21_map, std_map));
  }
  {
    const s21::map<int, std::string> s21_const_empty_map;
    const std::map<int, std::string> std_const_empty_map;
    const s21::map<int, std::string> s21_map(s21_const_empty_map);
    const std::map<int, std::string> std_map(std_const_empty_map);

    EXPECT_TRUE(MapEqual(s21_const_empty_map, std_const_empty_map));
    EXPECT_TRUE(MapEqual(s21_map, std_map));
  }
  {
    s21::map<int, int> s21_tmp = {std::make_pair(10, 1)};
    std::map<int, int> std_tmp = {std::make_pair(10, 1)};
    s21::map<int, int> s21_map(s21_tmp);
    std::map<int, int> std_map(std_tmp);

    EXPECT_TRUE(MapEqual(s21_tmp, std_tmp));
    EXPECT_TRUE(MapEqual(s21_map, std_map));
  }
  {
    s21::map<int, int> s21_tmp = {std::make_pair(10, 1), std::make_pair(5, 3),
                                  std::make_pair(15, 5)};
    std::map<int, int> std_tmp = {std::make_pair(10, 1), std::make_pair(5, 3),
                                  std::make_pair(15, 5)};
    s21::map<int, int> s21_map(s21_tmp);
    std::map<int, int> std_map(std_tmp);

    EXPECT_TRUE(MapEqual(s21_tmp, std_tmp));
    EXPECT_TRUE(MapEqual(s21_map, std_map));
  }
  {
    s21::map<int, std::string> s21_map(ms21);
    std::map<int, std::string> std_map(mstd);

    EXPECT_TRUE(MapEqual(ms21, mstd));
    EXPECT_TRUE(MapEqual(s21_map, std_map));
  }
  {
    const s21::map<int, std::string> s21_map(ms21);
    const std::map<int, std::string> std_map(mstd);

    EXPECT_TRUE(MapEqual(ms21, mstd));
    EXPECT_TRUE(MapEqual(s21_map, std_map));
  }
}

TEST_F(MapTest, MoveCtor) {
  {
    s21::map<int, std::string> s21_empty_map;
    std::map<int, std::string> std_empty_map;
    s21::map<int, std::string> s21_map(std::move(s21_empty_map));
    std::map<int, std::string> std_map(std::move(std_empty_map));

    EXPECT_TRUE(MapEqual(s21_empty_map, std_empty_map));
    EXPECT_TRUE(MapEqual(s21_map, std_map));
  }
  {
    const s21::map<int, std::string> s21_const_empty_map;
    const std::map<int, std::string> std_const_empty_map;
    const s21::map<int, std::string> s21_map(std::move(s21_const_empty_map));
    const std::map<int, std::string> std_map(std::move(std_const_empty_map));

    EXPECT_TRUE(MapEqual(s21_const_empty_map, std_const_empty_map));
    EXPECT_TRUE(MapEqual(s21_map, std_map));
  }
  {
    s21::map<int, int> s21_tmp = {std::make_pair(10, 1)};
    std::map<int, int> std_tmp = {std::make_pair(10, 1)};
    s21::map<int, int> s21_map(std::move(s21_tmp));
    std::map<int, int> std_map(std::move(std_tmp));

    EXPECT_TRUE(MapEqual(s21_tmp, std_tmp));
    EXPECT_TRUE(MapEqual(s21_map, std_map));
  }
  {
    s21::map<int, int> s21_tmp = {std::make_pair(10, 1), std::make_pair(5, 3),
                                  std::make_pair(15, 5)};
    std::map<int, int> std_tmp = {std::make_pair(10, 1), std::make_pair(5, 3),
                                  std::make_pair(15, 5)};
    s21::map<int, int> s21_map(std::move(s21_tmp));
    std::map<int, int> std_map(std::move(std_tmp));

    EXPECT_TRUE(MapEqual(s21_tmp, std_tmp));
    EXPECT_TRUE(MapEqual(s21_map, std_map));
  }
  {
    s21::map<int, std::string> s21_map(std::move(ms21));
    std::map<int, std::string> std_map(std::move(mstd));

    EXPECT_TRUE(MapEqual(ms21, mstd));
    EXPECT_TRUE(MapEqual(s21_map, std_map));
  }
  {
    const s21::map<int, std::string> s21_map(std::move(ms21));
    const std::map<int, std::string> std_map(std::move(mstd));

    EXPECT_TRUE(MapEqual(ms21, mstd));
    EXPECT_TRUE(MapEqual(s21_map, std_map));
  }
}

TEST_F(MapTest, CopyOpearotAssign) {
  {
    s21::map<int, std::string> s21_empty_map;
    std::map<int, std::string> std_empty_map;
    s21::map<int, std::string> s21_map;
    std::map<int, std::string> std_map;

    s21_map = s21_empty_map;
    std_map = std_empty_map;

    EXPECT_TRUE(MapEqual(s21_empty_map, std_empty_map));
    EXPECT_TRUE(MapEqual(s21_map, std_map));
  }
  {
    s21::map<int, int> s21_tmp = {std::make_pair(10, 1)};
    std::map<int, int> std_tmp = {std::make_pair(10, 1)};
    s21::map<int, int> s21_map;
    std::map<int, int> std_map;

    s21_map = s21_tmp;
    std_map = std_tmp;

    EXPECT_TRUE(MapEqual(s21_tmp, std_tmp));
    EXPECT_TRUE(MapEqual(s21_map, std_map));
  }
  {
    s21::map<int, int> s21_tmp = {std::make_pair(10, 1), std::make_pair(5, 3),
                                  std::make_pair(15, 5)};
    std::map<int, int> std_tmp = {std::make_pair(10, 1), std::make_pair(5, 3),
                                  std::make_pair(15, 5)};
    s21::map<int, int> s21_map = {std::make_pair(10, 1)};
    std::map<int, int> std_map = {std::make_pair(10, 1)};

    s21_map = s21_tmp;
    std_map = std_tmp;

    EXPECT_TRUE(MapEqual(s21_tmp, std_tmp));
    EXPECT_TRUE(MapEqual(s21_map, std_map));
  }
  {
    s21::map<int, std::string> s21_map = {
        std::make_pair(10, std::to_string(1))};
    std::map<int, std::string> std_map = {
        std::make_pair(10, std::to_string(1))};

    s21_map = ms21;
    std_map = mstd;

    EXPECT_TRUE(MapEqual(ms21, mstd));
    EXPECT_TRUE(MapEqual(s21_map, std_map));
  }
}

TEST_F(MapTest, MoveOpearotAssign) {  ////// 9 leaks
  {
    s21::map<int, std::string> s21_empty_map;
    std::map<int, std::string> std_empty_map;
    s21::map<int, std::string> s21_map;
    std::map<int, std::string> std_map;

    s21_map = std::move(s21_empty_map);
    std_map = std::move(std_empty_map);

    EXPECT_TRUE(MapEqual(s21_empty_map, std_empty_map));
    EXPECT_TRUE(MapEqual(s21_map, std_map));
  }
  {
    s21::map<int, int> s21_tmp = {std::make_pair(10, 1)};
    std::map<int, int> std_tmp = {std::make_pair(10, 1)};
    s21::map<int, int> s21_map(s21_tmp);
    std::map<int, int> std_map(std_tmp);

    s21_map = std::move(s21_tmp);
    std_map = std::move(std_tmp);

    EXPECT_TRUE(MapEqual(s21_tmp, std_tmp));
    EXPECT_TRUE(MapEqual(s21_map, std_map));
  }
  {
    s21::map<int, int> s21_tmp = {std::make_pair(10, 1), std::make_pair(5, 3),
                                  std::make_pair(15, 5)};
    std::map<int, int> std_tmp = {std::make_pair(10, 1), std::make_pair(5, 3),
                                  std::make_pair(15, 5)};
    s21::map<int, int> s21_map = {std::make_pair(10, 1)};
    std::map<int, int> std_map = {std::make_pair(10, 1)};

    s21_map = std::move(s21_tmp);
    std_map = std::move(std_tmp);

    EXPECT_TRUE(MapEqual(s21_tmp, std_tmp));
    EXPECT_TRUE(MapEqual(s21_map, std_map));
  }
  {
    s21::map<int, std::string> s21_map = {
        std::make_pair(10, std::to_string(1))};
    std::map<int, std::string> std_map = {
        std::make_pair(10, std::to_string(1))};

    s21_map = std::move(ms21);
    std_map = std::move(mstd);

    EXPECT_TRUE(MapEqual(ms21, mstd));
    EXPECT_TRUE(MapEqual(s21_map, std_map));
  }
}

TEST_F(MapTest, ConstAt) {
  const s21::map<int, std::string> cms21 = mms21;
  const std::map<int, std::string> cmstd = mmstd;

  for (int i = 0; i < 1500; i += 10) {
    try {
      std::string val_s21 = cms21.at(i);
      std::string val_std = cmstd.at(i);
      EXPECT_EQ(val_s21, val_std);
    } catch (std::out_of_range &e_s21) {
      try {
        std::string val_std = cmstd.at(i);
        EXPECT_TRUE(false);
      } catch (std::out_of_range &e_std) {
        EXPECT_TRUE(true);
      }
    }
  }
  EXPECT_TRUE(MapEqual(cms21, cmstd));
}

TEST_F(MapTest, At) {
  for (int i = 0; i < 1500; i += 10) {
    try {
      std::string val_s21 = mms21.at(i);
      std::string val_std = mmstd.at(i);
      EXPECT_EQ(val_s21, val_std);
      val_s21 = "ABCDEF";
      val_std = "ABCDEF";
      val_s21 = mms21.at(i);
      val_std = mmstd.at(i);
      EXPECT_EQ(val_s21, val_std);
    } catch (std::out_of_range &e_s21) {
      try {
        std::string val_std = mmstd.at(i);
        EXPECT_EQ(21, 42);
      } catch (std::out_of_range &e_std) {
        EXPECT_EQ(42, 42);
      }
    }
  }
  EXPECT_TRUE(MapEqual(mms21, mmstd));
}

TEST_F(MapTest, OperatorSquareBrackets) {
  for (int i = 0; i < 1500; i += 10) {
    std::string val_s21 = mms21[i];
    std::string val_std = mmstd[i];
    EXPECT_EQ(val_s21, val_std);
    val_s21 = "ABCDEF";
    val_std = "ABCDEF";
    val_s21 = mms21[i];
    val_std = mmstd[i];
  }
  EXPECT_TRUE(MapEqual(mms21, mmstd));
}

TEST_F(MapTest, Iterator) {
  {
    s21::map<int, std::string>::iterator s21_it = ms21.begin();
    std::map<int, std::string>::iterator std_it = mstd.begin();

    ++s21_it;
    ++s21_it;
    ++std_it;
    ++std_it;
    EXPECT_EQ(s21_it->first, std_it->first);
    EXPECT_EQ((++s21_it)->first, (++std_it)->first);
    EXPECT_EQ((++s21_it)->first, (++std_it)->first);
    EXPECT_EQ(s21_it->first, std_it->first);
    EXPECT_EQ((--s21_it)->first, (--std_it)->first);
    EXPECT_EQ(s21_it->first, std_it->first);
    EXPECT_EQ((--s21_it)->first, (--std_it)->first);
    EXPECT_EQ(s21_it->first, std_it->first);
    --s21_it;
    --std_it;
    EXPECT_EQ(s21_it->second, std_it->second);

    auto s21_tmp = ++s21_it;
    auto std_tmp = ++std_it;
    EXPECT_TRUE(s21_tmp == s21_it);
    EXPECT_TRUE(std_tmp == std_it);
    EXPECT_FALSE(s21_tmp != s21_it);
    EXPECT_FALSE(std_tmp != std_it);
    ++s21_tmp;
    ++std_tmp;
    EXPECT_FALSE(s21_tmp == s21_it);
    EXPECT_FALSE(std_tmp == std_it);
    EXPECT_TRUE(s21_tmp != s21_it);
    EXPECT_TRUE(std_tmp != std_it);
  }
  {
    s21::map<int, std::string>::iterator s21_it = ms21.end();
    std::map<int, std::string>::iterator std_it = mstd.end();
    --s21_it;
    --s21_it;
    --std_it;
    --std_it;
    EXPECT_EQ(s21_it->first, std_it->first);
    EXPECT_EQ((--s21_it)->first, (--std_it)->first);
    EXPECT_EQ((--s21_it)->first, (--std_it)->first);
    EXPECT_EQ(s21_it->first, std_it->first);
    EXPECT_EQ((++s21_it)->first, (++std_it)->first);
    EXPECT_EQ(s21_it->first, std_it->first);
    EXPECT_EQ((++s21_it)->first, (++std_it)->first);
    EXPECT_EQ(s21_it->first, std_it->first);
    --s21_it;
    --std_it;
    EXPECT_EQ(s21_it->second, std_it->second);
  }
}

TEST_F(MapTest, ConstIterator) {
  const s21::map<int, std::string> cms21 = ms21;
  const std::map<int, std::string> cmstd = mstd;
  {
    s21::map<int, std::string>::const_iterator s21_it = cms21.begin();
    std::map<int, std::string>::const_iterator std_it = cmstd.begin();

    ++s21_it;
    ++s21_it;
    ++std_it;
    ++std_it;
    EXPECT_EQ(s21_it->first, std_it->first);
    EXPECT_EQ((++s21_it)->first, (++std_it)->first);
    EXPECT_EQ((++s21_it)->first, (++std_it)->first);
    EXPECT_EQ(s21_it->first, std_it->first);
    EXPECT_EQ((--s21_it)->first, (--std_it)->first);
    EXPECT_EQ(s21_it->first, std_it->first);
    EXPECT_EQ((--s21_it)->first, (--std_it)->first);
    EXPECT_EQ(s21_it->first, std_it->first);
    --s21_it;
    --std_it;
    EXPECT_EQ(s21_it->second, std_it->second);
  }
  {
    s21::map<int, std::string>::const_iterator s21_it = cms21.end();
    std::map<int, std::string>::const_iterator std_it = cmstd.end();
    --s21_it;
    --s21_it;
    --std_it;
    --std_it;
    EXPECT_EQ(s21_it->first, std_it->first);
    EXPECT_EQ((--s21_it)->first, (--std_it)->first);
    EXPECT_EQ((--s21_it)->first, (--std_it)->first);
    EXPECT_EQ(s21_it->first, std_it->first);
    EXPECT_EQ((++s21_it)->first, (++std_it)->first);
    EXPECT_EQ(s21_it->first, std_it->first);
    EXPECT_EQ((++s21_it)->first, (++std_it)->first);
    EXPECT_EQ(s21_it->first, std_it->first);
    --s21_it;
    --std_it;
    EXPECT_EQ(s21_it->second, std_it->second);
  }
}

TEST_F(MapTest, Capacity) {
  {
    s21::map<int, std::vector<double>> s21_m;
    std::map<int, std::vector<double>> std_m;

    EXPECT_EQ(s21_m.empty(), std_m.empty());
    EXPECT_EQ(s21_m.size(), std_m.size());
  }
  {
    s21::map<int, std::vector<double>> s21_m{
        std::make_pair(10, std::vector<double>{1.0, 2.0})};
    std::map<int, std::vector<double>> std_m{
        std::make_pair(10, std::vector<double>{1.0, 2.0})};

    EXPECT_EQ(s21_m.empty(), std_m.empty());
    EXPECT_EQ(s21_m.size(), std_m.size());
  }
  {
    s21::map<int, std::vector<double>> s21_m{
        std::make_pair(10, std::vector<double>{1.0, 2.0}),
        std::make_pair(19, std::vector<double>{10.0, 20.0}),
        std::make_pair(-19, std::vector<double>{100.0, 200.0})};
    std::map<int, std::vector<double>> std_m{
        std::make_pair(10, std::vector<double>{1.0, 2.0}),
        std::make_pair(19, std::vector<double>{10.0, 20.0}),
        std::make_pair(-19, std::vector<double>{100.0, 200.0})};

    EXPECT_EQ(s21_m.empty(), std_m.empty());
    EXPECT_EQ(s21_m.size(), std_m.size());
  }
  {
    EXPECT_EQ(ms21.empty(), mstd.empty());
    EXPECT_EQ(ms21.size(), mstd.size());
  }
  {
    const s21::map<int, std::string> cms21 = ms21;
    const std::map<int, std::string> cmstd = mstd;

    EXPECT_EQ(cms21.empty(), cmstd.empty());
    EXPECT_EQ(cms21.size(), cmstd.size());
  }
}

TEST_F(MapTest, Clear) {
  s21::map<int, std::string> m = ms21;
  std::map<int, std::string> s = mstd;

  m.clear();
  s.clear();

  EXPECT_EQ(m.empty(), s.empty());
  EXPECT_TRUE(MapEqual(m, s));
}

TEST_F(MapTest, Insert0) {
  s21::map<int, std::string> m;
  std::map<int, std::string> s;

  for (int i = 0; i < 100; ++i) {
    int key = rand() % 1000000;
    auto ps21 = m.insert(std::make_pair(key, std::to_string(key)));
    auto pstd = s.insert(std::make_pair(key, std::to_string(key)));
    EXPECT_EQ(ps21.first->first, pstd.first->first);
    EXPECT_EQ(ps21.first->second, pstd.first->second);
    EXPECT_EQ(ps21.second, pstd.second);
  }
  EXPECT_TRUE(MapEqual(m, s));
}

TEST_F(MapTest, Insert1) {
  s21::map<int, std::string> m;
  s21::map<int, std::string> s;

  for (int i = 0; i < 100; ++i) {
    int key = rand() % 1000000;
    auto ps21 = m.insert(std::make_pair(key, std::to_string(key)));
    auto pstd = s.insert(std::make_pair(key, std::to_string(key)));
    EXPECT_EQ(ps21.first->first, pstd.first->first);
    EXPECT_EQ(ps21.first->second, pstd.first->second);
    EXPECT_EQ(ps21.second, pstd.second);
  }
  EXPECT_TRUE(MapEqual(m, s));
}

TEST_F(MapTest, Insert2) {
  s21::map<int, std::string> m;
  std::map<int, std::string> s;

  for (int i = 0; i < 100; ++i) {
    int key = rand() / 10000;
    auto ps21 = m.insert(key, std::to_string(key));
    auto pstd = s.insert(std::make_pair(key, std::to_string(key)));
    EXPECT_EQ(ps21.first->first, pstd.first->first);
    EXPECT_EQ(ps21.first->second, pstd.first->second);
    EXPECT_EQ(ps21.second, pstd.second);
  }
  EXPECT_TRUE(MapEqual(m, s));
}

TEST_F(MapTest, InsertOrAssign) {
  s21::map<int, std::string> m;
  std::map<int, std::string> s;

  for (int i = 0; i < 100; ++i) {
    int key = rand() % 1000;
    auto ps21 = m.insert_or_assign(key, std::to_string(key + i));
    auto pstd = s.insert_or_assign(key, std::to_string(key + i));
    EXPECT_EQ(ps21.first->first, pstd.first->first);
    EXPECT_EQ(ps21.first->second, pstd.first->second);
    EXPECT_EQ(ps21.second, pstd.second);
  }
  EXPECT_TRUE(MapEqual(m, s));
}

TEST_F(MapTest, Erase1) {
  s21::map<int, std::string> m = ms21;
  std::map<int, std::string> s = mstd;

  auto mit = m.begin();
  m.erase(mit);
  auto sit = s.begin();
  s.erase(sit);
  EXPECT_TRUE(MapEqual(m, s));

  mit = --m.end();
  m.erase(mit);
  sit = --s.end();
  s.erase(sit);
  EXPECT_TRUE(MapEqual(m, s));

  mit = m.end();
  sit = s.end();
  for (int i = 0; i < 100; ++i) {
    --mit;
    --sit;
  }
  m.erase(mit);
  s.erase(sit);
  EXPECT_TRUE(MapEqual(m, s));

  mit = m.begin();
  sit = s.begin();
  for (int i = 0; i < 100; ++i) {
    ++mit;
    ++sit;
  }
  m.erase(mit);
  s.erase(sit);
  EXPECT_TRUE(MapEqual(m, s));
}

TEST_F(MapTest, Erase2) {
  s21::map<int, std::string> m;
  std::map<int, std::string> s;

  m.insert(std::make_pair(10, "10"));
  s.insert(std::make_pair(10, "10"));

  m.erase(m.begin());
  s.erase(s.begin());
  EXPECT_TRUE(MapEqual(m, s));
}

TEST_F(MapTest, Erase3) {
  s21::map<int, std::string> mm;
  std::map<int, std::string> ss;

  mm.insert(std::make_pair(10, "10"));
  mm.insert(std::make_pair(8, "8"));
  mm.insert(std::make_pair(11, "11"));

  ss.insert(std::make_pair(10, "10"));
  ss.insert(std::make_pair(8, "8"));
  ss.insert(std::make_pair(11, "11"));

  {
    s21::map<int, std::string> m = mm;
    std::map<int, std::string> s = ss;

    m.erase(m.begin());
    s.erase(s.begin());
    EXPECT_TRUE(MapEqual(m, s));
  }
  {
    s21::map<int, std::string> m = mm;
    std::map<int, std::string> s = ss;

    m.erase(++m.begin());
    s.erase(++s.begin());
    EXPECT_TRUE(MapEqual(m, s));
  }
  {
    s21::map<int, std::string> m = mm;
    std::map<int, std::string> s = ss;

    m.erase(--m.end());
    s.erase(--s.end());
    EXPECT_TRUE(MapEqual(m, s));
  }
  {
    s21::map<int, std::string> m = mm;
    std::map<int, std::string> s = ss;

    m.erase(--m.end());
    s.erase(--s.end());
    m.erase(++m.begin());
    s.erase(++s.begin());
    EXPECT_TRUE(MapEqual(m, s));
  }
  {
    s21::map<int, std::string> m = mm;
    std::map<int, std::string> s = ss;

    m.erase(--m.end());
    s.erase(--s.end());
    m.erase(++m.begin());
    s.erase(++s.begin());
    m.erase(m.begin());
    s.erase(s.begin());
    EXPECT_TRUE(MapEqual(m, s));
  }
}

TEST_F(MapTest, Erase4) {
  {
    s21::map<int, std::string> m = mms21;
    std::map<int, std::string> s = mmstd;

    auto mit = m.find(600);
    auto sit = s.find(600);
    m.erase(mit);
    s.erase(sit);
    // ASSERT_EQ(m.verify(), 0);
    EXPECT_TRUE(MapEqual(m, s));
  }
  {
    s21::map<int, std::string> m = mms21;
    std::map<int, std::string> s = mmstd;

    auto mit = m.find(200);
    auto sit = s.find(200);
    m.erase(mit);
    s.erase(sit);
    // ASSERT_EQ(m.verify(), 0);
    EXPECT_TRUE(MapEqual(m, s));
  }
  {
    s21::map<int, std::string> m = mms21;
    std::map<int, std::string> s = mmstd;

    m.insert(std::make_pair(350, "a"));
    s.insert(std::make_pair(350, "a"));

    auto mit = m.find(300);
    auto sit = s.find(300);
    m.erase(mit);
    s.erase(sit);
    // ASSERT_EQ(m.verify(), 0);
    EXPECT_TRUE(MapEqual(m, s));
  }
  {
    s21::map<int, std::string> m = mms21;
    std::map<int, std::string> s = mmstd;

    m.insert(std::make_pair(450, "a"));
    s.insert(std::make_pair(450, "a"));
    m.insert(std::make_pair(430, "b"));
    s.insert(std::make_pair(430, "b"));
    m.insert(std::make_pair(460, "c"));
    s.insert(std::make_pair(460, "c"));

    auto mit = m.find(300);
    auto sit = s.find(300);
    m.erase(mit);
    s.erase(sit);
    // ASSERT_EQ(m.verify(), 0);
    EXPECT_TRUE(MapEqual(m, s));
  }

  {
    s21::map<int, std::string> m = mms21;
    std::map<int, std::string> s = mmstd;

    auto mit = m.find(800);
    auto sit = s.find(800);
    m.erase(mit);
    s.erase(sit);
    // ASSERT_EQ(m.verify(), 0);
    EXPECT_TRUE(MapEqual(m, s));
  }
  {
    s21::map<int, std::string> m = mms21;
    std::map<int, std::string> s = mmstd;

    auto mit = m.find(500);
    auto sit = s.find(500);
    m.erase(mit);
    s.erase(sit);
    // ASSERT_EQ(m.verify(), 0);
    EXPECT_TRUE(MapEqual(m, s));
  }
  {
    s21::map<int, std::string> m = mms21;
    std::map<int, std::string> s = mmstd;

    auto mit = m.find(900);
    auto sit = s.find(900);
    m.erase(mit);
    s.erase(sit);
    EXPECT_TRUE(MapEqual(m, s));

    mit = m.find(800);
    sit = s.find(800);
    m.erase(mit);
    s.erase(sit);
    // ASSERT_EQ(m.verify(), 0);
    EXPECT_TRUE(MapEqual(m, s));
  }
  {
    s21::map<int, std::string> m = mms21;
    std::map<int, std::string> s = mmstd;

    auto mit = m.find(900);
    auto sit = s.find(900);
    m.erase(mit);
    s.erase(sit);
    EXPECT_TRUE(MapEqual(m, s));

    mit = m.find(800);
    sit = s.find(800);
    m.erase(mit);
    s.erase(sit);
    // ASSERT_EQ(m.verify(), 0);
    EXPECT_TRUE(MapEqual(m, s));

    mit = m.find(300);
    sit = s.find(300);
    m.erase(mit);
    s.erase(sit);
    // ASSERT_EQ(m.verify(), 0);
    EXPECT_TRUE(MapEqual(m, s));

    mit = m.find(1000);
    sit = s.find(1000);
    m.erase(mit);
    s.erase(sit);
    // ASSERT_EQ(m.verify(), 0);
    EXPECT_TRUE(MapEqual(m, s));
  }
}

TEST_F(MapTest, Erase5) {
  s21::map<int, std::string> m;
  std::map<int, std::string> s;

  for (int i = 0; i < 100; ++i) {
    int key = rand() / 100000;
    m.insert(std::make_pair(key, std::to_string(key)));
    s.insert(std::make_pair(key, std::to_string(key)));
  }
  EXPECT_TRUE(MapEqual(m, s));

  for (int i = 0; i < 100; ++i) {
    int key = rand() / 100000;
    auto it1 = m.find(key);
    auto it2 = s.find(key);
    if (it1 != m.end()) {
      EXPECT_EQ(it1->first, it2->first);
      EXPECT_EQ(it1->second, it2->second);
    }
  }
  for (int i = 0; i < 100; ++i) {
    int key = rand() / 100000;
    auto it1 = m.find(key);
    auto it2 = s.find(key);

    if (it2 != s.end()) {
      m.erase(it1);
      s.erase(it2);
    }
  }
  // ASSERT_EQ(m.verify(), 0);
  EXPECT_TRUE(MapEqual(m, s));
}

TEST_F(MapTest, Swap) {
  s21::map<int, std::string> m = {{1, "1"}};
  std::map<int, std::string> s = {{1, "1"}};

  m.swap(ms21);
  s.swap(mstd);

  EXPECT_TRUE(MapEqual(m, s));
  EXPECT_TRUE(MapEqual(ms21, mstd));
}

TEST_F(MapTest, Merge1) {
  {
    s21::map<int, std::string> m_s21;
    s21::map<int, std::string> source_s21;
    std::map<int, std::string> m_std;
    std::map<int, std::string> source_std;

    m_s21.merge(source_s21);
    m_std.merge(source_std);

    EXPECT_TRUE(MapEqual(m_s21, m_std));
    EXPECT_TRUE(MapEqual(source_s21, source_std));
  }
  {
    s21::map<int, std::string> m_s21 = {{1, "1"}};
    s21::map<int, std::string> source_s21;
    std::map<int, std::string> m_std = {{1, "1"}};
    std::map<int, std::string> source_std;

    m_s21.merge(source_s21);
    m_std.merge(source_std);

    EXPECT_TRUE(MapEqual(m_s21, m_std));
    EXPECT_TRUE(MapEqual(source_s21, source_std));
  }
  {
    s21::map<int, std::string> m_s21;
    s21::map<int, std::string> source_s21 = {{1, "1"}};
    std::map<int, std::string> m_std;
    std::map<int, std::string> source_std = {{1, "1"}};

    m_s21.merge(source_s21);
    m_std.merge(source_std);

    EXPECT_TRUE(MapEqual(m_s21, m_std));
    EXPECT_TRUE(MapEqual(source_s21, source_std));
  }
  {
    s21::map<int, std::string> m_s21 = {{2, "2"}};
    s21::map<int, std::string> source_s21 = {{1, "1"}};
    std::map<int, std::string> m_std = {{2, "2"}};
    std::map<int, std::string> source_std = {{1, "1"}};

    m_s21.merge(source_s21);
    m_std.merge(source_std);

    EXPECT_TRUE(MapEqual(m_s21, m_std));
    EXPECT_TRUE(MapEqual(source_s21, source_std));
  }
  {
    s21::map<int, std::string> m_s21 = {{1, "1"}, {2, "2"}};
    s21::map<int, std::string> source_s21 = {{1, "1"}};
    std::map<int, std::string> m_std = {{1, "1"}, {2, "2"}};
    std::map<int, std::string> source_std = {{1, "1"}};

    m_s21.merge(source_s21);
    m_std.merge(source_std);

    EXPECT_TRUE(MapEqual(m_s21, m_std));
    EXPECT_TRUE(MapEqual(source_s21, source_std));
  }
  {
    s21::map<int, std::string> m_s21 = {{1, "1"}, {2, "2"}};
    s21::map<int, std::string> source_s21 = {{1, "1"}, {3, "3"}};
    std::map<int, std::string> m_std = {{1, "1"}, {2, "2"}};
    std::map<int, std::string> source_std = {{1, "1"}, {3, "3"}};

    m_s21.merge(source_s21);
    m_std.merge(source_std);

    EXPECT_TRUE(MapEqual(m_s21, m_std));
    EXPECT_TRUE(MapEqual(source_s21, source_std));
  }
  {
    s21::map<int, std::string> m_s21 = {
        {1, "1"}, {2, "2"}, {0, "0"}, {-1, "-1"}, {2, "2"}};
    s21::map<int, std::string> source_s21 = {
        {1, "1"}, {3, "3"}, {2, "2"}, {4, "4"}, {5, "5"}};
    std::map<int, std::string> m_std = {
        {1, "1"}, {2, "2"}, {0, "0"}, {-1, "-1"}, {2, "2"}};
    std::map<int, std::string> source_std = {
        {1, "1"}, {3, "3"}, {2, "2"}, {4, "4"}, {5, "5"}};

    m_s21.merge(source_s21);
    m_std.merge(source_std);

    EXPECT_TRUE(MapEqual(m_s21, m_std));
    EXPECT_TRUE(MapEqual(source_s21, source_std));
  }
}

TEST_F(MapTest, Merge2) {
  s21::map<int, std::string> m_s21;
  s21::map<int, std::string> source_s21;
  std::map<int, std::string> m_std;
  std::map<int, std::string> source_std;

  for (int i = 0; i < 100; ++i) {
    int key = rand() % 1000000;
    m_s21.insert(std::make_pair(key, std::to_string(key)));
    m_std.insert(std::make_pair(key, std::to_string(key)));
  }
  for (int i = 0; i < 100; ++i) {
    int key = rand() % 100000;
    source_s21.insert(std::make_pair(key, std::to_string(key + i)));
    source_std.insert(std::make_pair(key, std::to_string(key + i)));
  }

  EXPECT_FALSE(MapEqual(m_s21, source_s21));

  m_s21.merge(source_s21);
  m_std.merge(source_std);

  EXPECT_TRUE(MapEqual(m_s21, m_std));
  EXPECT_TRUE(MapEqual(source_s21, source_std));
}

TEST_F(MapTest, Find) {
  s21::map<int, std::string> m;
  std::map<int, std::string> s;

  for (int i = 0; i < 100; ++i) {
    int key = rand() / 100000;
    m.insert(std::make_pair(key, std::to_string(key)));
    s.insert(std::make_pair(key, std::to_string(key)));
  }
  EXPECT_TRUE(MapEqual(m, s));

  for (int i = 0; i < 100; ++i) {
    int key = rand() / 100000;
    auto it1 = m.find(key);
    auto it2 = s.find(key);
    if (it2 != s.end()) {
      EXPECT_EQ(it1->first, it2->first);
      EXPECT_EQ(it1->second, it2->second);
    } else {
      EXPECT_EQ(it1, m.end());
    }
  }
}

TEST_F(MapTest, ConstFind) {
  s21::map<int, std::string> m;
  std::map<int, std::string> s;

  for (int i = 0; i < 100; ++i) {
    int key = rand() / 100000;
    m.insert(std::make_pair(key, std::to_string(key)));
    s.insert(std::make_pair(key, std::to_string(key)));
  }
  EXPECT_TRUE(MapEqual(m, s));

  const s21::map<int, std::string> cm = m;
  const std::map<int, std::string> cs = s;

  for (int i = 0; i < 100; ++i) {
    int key = rand() / 100000;
    auto it1 = cm.find(key);
    auto it2 = cs.find(key);
    if (it1 != cm.end()) {
      EXPECT_EQ(it1->first, it2->first);
      EXPECT_EQ(it1->second, it2->second);
    } else {
      EXPECT_EQ(it1, cm.end());
    }
  }
}

TEST_F(MapTest, Contains) {
  s21::map<int, std::string> m;
  std::map<int, std::string> s;

  for (int i = 0; i < 100; ++i) {
    int key = rand() / 100000;
    m.insert(std::make_pair(key, std::to_string(key)));
    s.insert(std::make_pair(key, std::to_string(key)));
  }
  EXPECT_TRUE(MapEqual(m, s));

  const s21::map<int, std::string> cm = m;
  const std::map<int, std::string> cs = s;

  for (int i = 0; i < 100; ++i) {
    int key = rand() / 100000;

    {
      bool res_s21 = m.contains(key);
      auto it = cs.find(key);
      bool res_std = (it != cs.end());
      EXPECT_EQ(res_s21, res_std);
    }
    {
      bool res_s21 = cm.contains(key);
      auto it = cs.find(key);
      bool res_std = (it != cs.end());
      EXPECT_EQ(res_s21, res_std);
    }
  }
}

TEST_F(MapTest, InsertMany) {
  {
    s21::map<int, std::string> m = {{1, "1"}, {2, "2"}};

    m.insert_many(std::make_pair(5, std::string("5")),
                  std::make_pair(3, std::string("3")),
                  std::make_pair(3, std::string("3")),
                  std::make_pair(4, std::string("4")));

    std::map<int, std::string> std_m = {
        {1, "1"}, {2, "2"}, {3, "3"}, {4, "4"}, {5, "5"}};

    EXPECT_TRUE(MapEqual(m, std_m));
  }
  {
    s21::map<int, std::string> m = {{1, "1"}, {2, "2"}};

    m.insert_many(std::make_pair(5, std::string("5")));

    std::map<int, std::string> std_m = {{1, "1"}, {2, "2"}, {5, "5"}};

    EXPECT_TRUE(MapEqual(m, std_m));
  }
  {
    s21::map<int, std::string> m = {{1, "1"}, {2, "2"}};

    m.insert_many();

    std::map<int, std::string> std_m = {{1, "1"}, {2, "2"}};

    EXPECT_TRUE(MapEqual(m, std_m));
  }
}