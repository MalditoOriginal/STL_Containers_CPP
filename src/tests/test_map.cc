#include "test_main.h"

TEST(map, move_assignment) {
  s21::map<int, int> test = {{4, 2}, {1, 3}, {2, 4}, {3, 1}, {1, 3}};
  s21::map<int, int> test2 = {{4, 2}, {1, 3}, {2, 4}, {3, 1}, {1, 3}};
  test2 = std::move(test);
  std::map<int, int> map = {{4, 2}, {1, 3}, {2, 4}, {3, 1}, {1, 3}};
  std::map<int, int> map2 = {{4, 2}, {1, 3}, {2, 4}, {3, 1}, {1, 3}};
  map2 = std::move(map);
  std::map<int, int>::iterator it;
  s21::map<int, int>::iterator it2 = test2.begin();
  for (it = map2.begin(); it != map2.end(); it++) {
    ASSERT_EQ(*it, *it2);
    it2++;
  }
  ASSERT_EQ(test.size(), map.size());
}

TEST(map, move_constructor) {
  s21::map<int, int> test = {{4, 2}, {1, 3}, {2, 4}, {3, 1}, {1, 3}};
  s21::map<int, int> test2(std::move(test));
  std::map<int, int> map = {{4, 2}, {1, 3}, {2, 4}, {3, 1}, {1, 3}};
  std::map<int, int> map2(std::move(map));
  std::map<int, int>::iterator it;
  s21::map<int, int>::iterator it2 = test2.begin();
  for (it = map2.begin(); it != map2.end(); it++) {
    ASSERT_EQ(*it, *it2);
    it2++;
  }
  ASSERT_EQ(test.size(), map.size());
}

TEST(map, init_constructor) {
  s21::map<int, int> test = {{4, 2}, {1, 3}, {2, 4}, {3, 1}, {1, 3}};
  s21::map<int, int>::iterator it = test.begin();
  std::map<int, int> test2 = {{4, 2}, {1, 3}, {2, 4}, {3, 1}, {1, 3}};
  std::map<int, int>::iterator it2;
  for (it2 = test2.begin(); it2 != test2.end(); it2++) {
    EXPECT_EQ(*it, *it2);
    it++;
  }
}

TEST(map, init_constructor2) {
  s21::map<std::string, int> test = {
      {"one", 2}, {"two", 3}, {"three", 4}, {"four", 1}, {"check", 3}};
  s21::map<std::string, int>::iterator it = test.begin();
  std::map<std::string, int> test2 = {
      {"one", 2}, {"two", 3}, {"three", 4}, {"four", 1}, {"check", 3}};
  std::map<std::string, int>::iterator it2;
  for (it2 = test2.begin(); it2 != test2.end(); it2++) {
    EXPECT_EQ(*it, *it2);
    it++;
  }
}

TEST(map, insert_bool) {
  s21::map<std::string, int> test = {
      {"one", 2}, {"two", 3}, {"three", 4}, {"four", 1}, {"check", 3}};
  std::pair<s21::map<std::string, int>::iterator, bool> check =
      test.insert({"shit", 5});
  std::map<std::string, int> test2 = {
      {"one", 2}, {"two", 3}, {"three", 4}, {"four", 1}, {"check", 3}};
  std::pair<std::map<std::string, int>::iterator, bool> check2 =
      test2.insert({"shit", 5});
  EXPECT_EQ(*check.first, *check2.first);
  EXPECT_EQ(check.second, check2.second);
}

TEST(map, insert_0r_assign) {
  s21::map<std::string, int> test = {
      {"one", 2}, {"two", 3}, {"three", 4}, {"four", 1}, {"check", 3}};
  std::pair<s21::map<std::string, int>::iterator, bool> check =
      test.insert_or_assign("king", 5);
  std::map<std::string, int> test2 = {
      {"one", 2}, {"two", 3}, {"three", 4}, {"four", 1}, {"check", 3}};
  std::pair<std::map<std::string, int>::iterator, bool> check2 =
      test2.insert_or_assign("king", 5);
  EXPECT_EQ(*check.first, *check2.first);
  EXPECT_EQ(check.second, check2.second);
}

TEST(map, swap) {
  s21::map<std::string, int> test = {
      {"one", 2}, {"two", 3}, {"three", 4}, {"four", 1}, {"check", 3}};
  s21::map<std::string, int> test2 = {
      {"mob", 2}, {"1", 3}, {"2", 4}, {"3", 1}, {"1", 3}};
  std::map<std::string, int> map = {
      {"one", 2}, {"two", 3}, {"three", 4}, {"four", 1}, {"check", 3}};
  std::map<std::string, int> map2 = {
      {"mob", 2}, {"1", 3}, {"2", 4}, {"3", 1}, {"1", 3}};

  test2.swap(test);
  map2.swap(map);
  std::map<std::string, int>::iterator it;
  s21::map<std::string, int>::iterator it2 = test2.begin();
  for (it = map2.begin(); it != map2.end(); it++) {
    ASSERT_EQ(*it, *it2);
    it2++;
  }
  it2 = test.begin();
  for (it = map.begin(); it != map.end(); it++) {
    ASSERT_EQ(*it, *it2);
    it2++;
  }
}

TEST(map, merge) {
  s21::map<std::string, int> test = {
      {"one", 2}, {"two", 3}, {"three", 4}, {"four", 1}, {"check", 3}};
  s21::map<std::string, int> test2 = {
      {"mob", 2}, {"1", 3}, {"2", 4}, {"3", 1}, {"1", 3}};
  std::map<std::string, int> map = {
      {"one", 2}, {"two", 3}, {"three", 4}, {"four", 1}, {"check", 3}};
  std::map<std::string, int> map2 = {
      {"mob", 2}, {"1", 3}, {"2", 4}, {"3", 1}, {"1", 3}};
  test2.merge(test);
  map2.merge(map);
  std::map<std::string, int>::iterator it;
  s21::map<std::string, int>::iterator it2 = test2.begin();
  for (it = map2.begin(); it != map2.end(); it++) {
    ASSERT_EQ(*it, *it2);
    it2++;
  }
}

TEST(map, insert_many) {
  s21::map<int, std::string> m = {{1, "1"}, {2, "2"}};

  m.insert_many(
      std::make_pair(5, std::string("5")), std::make_pair(3, std::string("3")),
      std::make_pair(3, std::string("3")), std::make_pair(4, std::string("4")));

  std::map<int, std::string> std_m = {
      {1, "1"}, {2, "2"}, {3, "3"}, {4, "4"}, {5, "5"}};
  s21::map<int, std::string>::iterator it = m.begin();
  std::map<int, std::string>::iterator it2;
  for (it2 = std_m.begin(); it2 != std_m.end(); it2++) {
    EXPECT_EQ(*it, *it2);
    it++;
  }
}

TEST(map, max) {
  s21::map<int, int> test = {{4, 2}, {1, 3}, {2, 4}, {3, 1}, {1, 3}};
  std::map<int, int> test2 = {{4, 2}, {1, 3}, {2, 4}, {3, 1}, {1, 3}};
  EXPECT_EQ(test.max_size(), test2.max_size());
}

TEST(map, brackets) {
  s21::map<std::string, int> test = {
      {"one", 2}, {"two", 3}, {"three", 4}, {"four", 1}, {"check", 3}};
  std::map<std::string, int> test2 = {
      {"one", 2}, {"two", 3}, {"three", 4}, {"four", 1}, {"check", 3}};
  EXPECT_EQ(test["one"], test2["one"]);
}

TEST(map, at) {
  s21::map<int, int> test = {{4, 2}, {1, 3}, {2, 4}, {3, 1}, {1, 3}};
  std::map<int, int> test2 = {{4, 2}, {1, 3}, {2, 4}, {3, 1}, {1, 3}};
  EXPECT_EQ(test.at(4), test2.at(4));
}

TEST(map, default_constructor) {
  s21::map<int, int> test;
  std::map<int, int> test2;
  EXPECT_EQ(test.size(), test2.size());
  EXPECT_TRUE(test.empty());
}

TEST(map, size) {
  s21::map<std::string, int> test = {
      {"one", 2}, {"two", 3}, {"three", 4}, {"four", 1}, {"check", 3}};
  std::map<std::string, int> test2 = {
      {"one", 2}, {"two", 3}, {"three", 4}, {"four", 1}, {"check", 3}};
  EXPECT_EQ(test.size(), test2.size());
}

TEST(map, empty) {
  s21::map<std::string, int> test0;
  EXPECT_TRUE(test0.empty());
  s21::map<std::string, int> test = {
      {"one", 2}, {"two", 3}, {"three", 4}, {"four", 1}, {"check", 3}};
  EXPECT_FALSE(test.empty());
}

TEST(map, clear) {
  s21::map<std::string, int> test = {
      {"one", 2}, {"two", 3}, {"three", 4}, {"four", 1}, {"check", 3}};
  std::map<std::string, int> test2 = {
      {"one", 2}, {"two", 3}, {"three", 4}, {"four", 1}, {"check", 3}};
  test.clear();
}

TEST(map, move_constructor_with_initializer_list) {
  s21::map<int, int> test = {{5, 2}, {6, 3}, {7, 4}, {8, 1}, {9, 3}};
  std::map<int, int> map = {{5, 2}, {6, 3}, {7, 4}, {8, 1}, {9, 3}};
  s21::map<int, int>::iterator it = test.begin();
  for (auto it2 = map.begin(); it2 != map.end(); it2++) {
    EXPECT_EQ(*it, *it2);
    it++;
  }
}

TEST(map, move_constructor_empty) {
  s21::map<int, int> test;
  s21::map<int, int> test2(std::move(test));
  EXPECT_TRUE(test.empty());
}

TEST(map, move_assignment_empty) {
  s21::map<int, int> test;
  s21::map<int, int> test2;
  test2 = std::move(test);
  EXPECT_TRUE(test.empty());
}

TEST(map, initializer_list_constructor) {
  s21::map<int, int> test = {{4, 2}, {1, 3}, {2, 4}, {3, 1}, {1, 3}};
  s21::map<int, int> test2 = {{5, 2}, {6, 3}, {7, 4}, {8, 1}, {9, 3}};
  std::map<int, int> map = {{4, 2}, {1, 3}, {2, 4}, {3, 1}, {1, 3}};
  std::map<int, int> map2 = {{5, 2}, {6, 3}, {7, 4}, {8, 1}, {9, 3}};
  s21::map<int, int>::iterator it = test.begin();
  for (auto it2 = map.begin(); it2 != map.end(); it2++) {
    EXPECT_EQ(*it, *it2);
    it++;
  }
  it = test2.begin();
  for (auto it2 = map2.begin(); it2 != map2.end(); it2++) {
    EXPECT_EQ(*it, *it2);
    it++;
  }
}

TEST(map, move_constructor_with_initializer_lis2t) {
  s21::map<int, int> test = {{5, 2}, {6, 3}, {7, 4}, {8, 1}, {9, 3}};
  std::map<int, int> map = {{5, 2}, {6, 3}, {7, 4}, {8, 1}, {9, 3}};
  s21::map<int, int>::iterator it = test.begin();
  for (auto it2 = map.begin(); it2 != map.end(); it2++) {
    EXPECT_EQ(*it, *it2);
    it++;
  }
}