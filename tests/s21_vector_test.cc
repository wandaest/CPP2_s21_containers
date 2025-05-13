#include <ctime>

#include "all_tests_s21.h"

namespace s21 {

class S21VectorTest : public ::testing::Test {
 protected:
  void SetUp() override {}
  void TearDown() override {}
};

TEST_F(S21VectorTest, DefaultConstructor) {
  vector<int> v;
  EXPECT_EQ(v.size(), 0);
  EXPECT_EQ(v.capacity(), 0);
  EXPECT_TRUE(v.empty());
}

TEST_F(S21VectorTest, ParameterizedConstructor) {
  vector<int> v(5);
  EXPECT_EQ(v.size(), 5);
  EXPECT_GE(v.capacity(), 5);
  for (size_t i = 0; i < v.size(); ++i) {
    EXPECT_EQ(v[i], int());  // Default value for int is 0
  }
}

TEST_F(S21VectorTest, InitializerListConstructor) {
  vector<int> v = {1, 2, 3, 4, 5};
  EXPECT_EQ(v.size(), 5);
  EXPECT_EQ(v[0], 1);
  EXPECT_EQ(v[4], 5);
}

TEST_F(S21VectorTest, CopyConstructor) {
  vector<int> v1 = {1, 2, 3};
  vector<int> v2 = v1;
  EXPECT_EQ(v2.size(), v1.size());
  for (size_t i = 0; i < v2.size(); ++i) {
    EXPECT_EQ(v2[i], v1[i]);
  }
}

TEST_F(S21VectorTest, MoveConstructor) {
  vector<int> v1 = {1, 2, 3};
  vector<int> v2 = std::move(v1);
  EXPECT_EQ(v2.size(), 3);
  EXPECT_EQ(v1.size(), 0);
  EXPECT_EQ(v2[0], 1);
}

TEST_F(S21VectorTest, AssignmentOperatorMove) {
  vector<int> v1 = {1, 2, 3};
  vector<int> v2;
  v2 = std::move(v1);
  EXPECT_EQ(v2.size(), 3);
  EXPECT_EQ(v1.size(), 0);
  EXPECT_EQ(v2[1], 2);
}

TEST_F(S21VectorTest, AtFunction) {
  vector<int> v = {1, 2, 3};
  EXPECT_EQ(v.at(1), 2);
  EXPECT_THROW(v.at(3), std::out_of_range);
}

TEST_F(S21VectorTest, FrontAndBackFunctions) {
  vector<int> v = {10, 20, 30};
  EXPECT_EQ(v.front(), 10);
  EXPECT_EQ(v.back(), 30);
}

TEST_F(S21VectorTest, DataFunction) {
  vector<int> v = {1, 2, 3};
  EXPECT_EQ(v.data()[0], 1);
  EXPECT_EQ(v.data()[2], 3);
}

TEST_F(S21VectorTest, BeginAndEndFunctions) {
  vector<int> v = {1, 2, 3};
  auto it = v.begin();
  EXPECT_EQ(*it, 1);
  ++it;
  EXPECT_EQ(*it, 2);
  EXPECT_EQ(*(v.end() - 1), 3);
}

TEST_F(S21VectorTest, ReserveFunction) {
  vector<int> v;
  v.reserve(10);
  EXPECT_GE(v.capacity(), 10);
  EXPECT_EQ(v.size(), 0);
}

TEST_F(S21VectorTest, ShrinkToFitFunction) {
  vector<int> v(5);
  v.reserve(20);
  v.shrink_to_fit();
  EXPECT_EQ(v.capacity(), v.size());
}

TEST_F(S21VectorTest, ClearFunction) {
  vector<int> v = {1, 2, 3};
  v.clear();
  EXPECT_EQ(v.size(), 0);
  EXPECT_TRUE(v.empty());
}

TEST_F(S21VectorTest, InsertFunction) {
  vector<int> v = {1, 2, 3};
  auto it = v.insert(v.begin() + 1, 10);
  EXPECT_EQ(*it, 10);
  EXPECT_EQ(v[1], 10);
  EXPECT_EQ(v.size(), 4);
}

TEST_F(S21VectorTest, EraseFunction) {
  vector<int> v = {1, 2, 3};
  v.erase(v.begin() + 1);
  EXPECT_EQ(v.size(), 2);
  EXPECT_EQ(v[1], 3);
}

TEST_F(S21VectorTest, PushBackFunction) {
  vector<int> v;
  v.push_back(1);
  EXPECT_EQ(v.size(), 1);
  EXPECT_EQ(v.back(), 1);
  v.push_back(2);
  EXPECT_EQ(v.size(), 2);
  EXPECT_EQ(v.back(), 2);
}

TEST_F(S21VectorTest, PopBackFunction) {
  vector<int> v = {1, 2, 3};
  v.pop_back();
  EXPECT_EQ(v.size(), 2);
  EXPECT_EQ(v.back(), 2);
}

TEST_F(S21VectorTest, SwapFunction) {
  vector<int> v1 = {1, 2, 3};
  vector<int> v2 = {4, 5, 6};
  v1.swap(v2);
  EXPECT_EQ(v1[0], 4);
  EXPECT_EQ(v2[0], 1);
}

}  // namespace s21

TEST(VectorConstructor, Test1) {
  const s21::array<std::string, 9> a{"Non-zero",  "value",      "character",
                                     "The",       "behavior",   "is",
                                     "undefined", "whitespace", "otherwise"};
  std::vector<std::string> container;
  s21::vector<std::string> s21_container;
  container.reserve(a.size());
  s21_container.reserve(a.size());

  for (const auto& i : a) {
    container.push_back(i);
    s21_container.push_back(i);
  }

  auto s21_it = s21_container.begin();
  for (auto it{container.begin()}; s21_it != s21_container.end();
       ++s21_it, ++it) {
    EXPECT_EQ(*s21_it, *it);
  }

  EXPECT_EQ(container.size(), s21_container.size());
  EXPECT_EQ(container.capacity(), s21_container.capacity());
}

TEST(VectorConstructor, Test2) {
  const s21::array<std::string, 9> a{"Non-zero",  "value",      "character",
                                     "The",       "behavior",   "is",
                                     "undefined", "whitespace", "otherwise"};
  std::vector<std::string> container;
  s21::vector<std::string> s21_container;

  for (const auto& i : a) {
    container.push_back(i);
    s21_container.push_back(i);
  }

  auto s21_it = s21_container.begin();
  for (auto it{container.begin()}; s21_it != s21_container.end();
       ++s21_it, ++it) {
    EXPECT_EQ(*s21_it, *it);
  }

  EXPECT_EQ(container.size(), s21_container.size());
  EXPECT_EQ(container.capacity(), s21_container.capacity());
}

TEST(VectorConstructor, Test3) {
  const s21::array<std::string, 14> a{
      "but",    "there", "is",   "still", "no", "way",     "to",
      "adjust", "the",   "size", "based", "on", "runtime", "information"};
  std::vector<std::string> container{
      "they",    "must",  "all",          "be",         "available", "at",
      "compile", "time",  "and",          "can",        "only",      "depend",
      "on",      "other", "compile-time", "information"};
  s21::vector<std::string> s21_container{
      "they",    "must",  "all",          "be",         "available", "at",
      "compile", "time",  "and",          "can",        "only",      "depend",
      "on",      "other", "compile-time", "information"};

  for (const auto& i : a) {
    container.push_back(i);
    s21_container.push_back(i);
  }

  auto s21_it = s21_container.begin();
  for (auto it{container.begin()}; s21_it != s21_container.end();
       ++s21_it, ++it) {
    EXPECT_EQ(*s21_it, *it);
  }

  EXPECT_EQ(container.size(), s21_container.size());
  EXPECT_EQ(container.capacity(), s21_container.capacity());
}

TEST(VectorCapacity, Test1) {
  std::vector<std::vector<char>> container;
  s21::vector<s21::vector<char>> s21_container;
  EXPECT_EQ(s21_container.size(), container.size());
  EXPECT_EQ(s21_container.capacity(), container.capacity());
}

TEST(VectorCapacity, Test2) {
  std::vector<std::vector<char>> container(1);
  s21::vector<s21::vector<char>> s21_container(1);
  EXPECT_EQ(s21_container.size(), container.size());
  EXPECT_EQ(s21_container.capacity(), container.capacity());
}

TEST(VectorCapacity, Test3) {
  std::vector<std::vector<char>> container(5);
  s21::vector<s21::vector<char>> s21_container(5);
  EXPECT_EQ(s21_container.size(), container.size());
  EXPECT_EQ(s21_container.capacity(), container.capacity());
}

TEST(VectorCapacity, Test4) {
  std::vector<std::vector<char>> container(100'000);
  s21::vector<s21::vector<char>> s21_container(100'000);
  EXPECT_EQ(s21_container.size(), container.size());
  EXPECT_EQ(s21_container.capacity(), container.capacity());
}

TEST(VectorInsertMany, Test1) {
  std::vector container{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  s21::vector<int> s21_container;
  s21_container.insert_many(s21_container.begin(), 1, 2, 3, 4, 5, 6, 7, 8, 9,
                            10);
  auto s21_it{s21_container.begin()};
  for (auto it{container.begin()}; s21_it != s21_container.end();
       ++s21_it, ++it) {
    EXPECT_EQ(*s21_it, *it);
  }

  EXPECT_EQ(container.size(), s21_container.size());
}

TEST(VectorInsertMany, Test2) {
  std::vector<int> container;
  s21::vector<int> s21_container;
  s21_container.insert_many(s21_container.end());
  auto s21_it{s21_container.begin()};
  for (auto it{container.begin()}; s21_it != s21_container.end();
       ++s21_it, ++it) {
    EXPECT_EQ(*s21_it, *it);
  }

  EXPECT_EQ(container.size(), s21_container.size());
}

TEST(VectorInsertMany, Test3) {
  std::vector container{1};
  s21::vector<int> s21_container;
  s21_container.insert_many(s21_container.end(), 1);
  auto s21_it{s21_container.begin()};
  for (auto it{container.begin()}; s21_it != s21_container.end();
       ++s21_it, ++it) {
    EXPECT_EQ(*s21_it, *it);
  }

  EXPECT_EQ(container.size(), s21_container.size());
}

TEST(VectorInsertMany, Test4) {
  std::vector container{1, 2, 3};
  s21::vector<int> s21_container;
  s21_container.insert_many(s21_container.end(), 1, 2, 3);
  auto s21_it{s21_container.begin()};
  for (auto it{container.begin()}; s21_it != s21_container.end();
       ++s21_it, ++it) {
    EXPECT_EQ(*s21_it, *it);
  }

  EXPECT_EQ(container.size(), s21_container.size());
}

TEST(VectorInsertMany, Test5) {
  std::vector container{1, 2, 3};
  s21::vector s21_container{1, 2, 3};
  s21_container.insert_many(s21_container.begin());
  auto s21_it{s21_container.begin()};
  for (auto it{container.begin()}; s21_it != s21_container.end();
       ++s21_it, ++it) {
    EXPECT_EQ(*s21_it, *it);
  }

  EXPECT_EQ(container.size(), s21_container.size());
}

TEST(VectorInsertMany, Test6) {
  std::vector container{1, 2, 4, 5, 6, 3};
  s21::vector s21_container{1, 2, 3};
  auto s21_it{s21_container.begin()};
  std::advance(s21_it, 2);
  auto s21_it_new{s21_container.insert_many(s21_it, 4, 5, 6)};

  EXPECT_EQ(*s21_it_new, 4);

  s21_it = s21_container.begin();
  for (auto it{container.begin()}; s21_it != s21_container.end();
       ++s21_it, ++it) {
    EXPECT_EQ(*s21_it, *it);
  }

  EXPECT_EQ(container.size(), s21_container.size());
}

TEST(VectorInsertMany, Test7) {
  std::vector container{1, 5, 2, 3};
  s21::vector s21_container{1, 2, 3};
  auto s21_it{s21_container.begin()};
  std::advance(s21_it, 1);
  auto s21_it_new{s21_container.insert_many(s21_it, 5)};

  EXPECT_EQ(*s21_it_new, 5);

  s21_it = s21_container.begin();
  for (auto it{container.begin()}; s21_it != s21_container.end();
       ++s21_it, ++it) {
    EXPECT_EQ(*s21_it, *it);
  }

  EXPECT_EQ(container.size(), s21_container.size());
}

TEST(VectorInsertMany, Test8) {
  std::vector container{'a',  'b',  'c', '\t', '\v', '\r',
                        '\b', '\f', ' ', 'x',  'y',  'z'};
  s21::vector s21_container{'a', 'b', 'c', 'x', 'y', 'z'};
  auto s21_it{s21_container.begin()};
  std::advance(s21_it, 3);
  auto s21_it_new{
      s21_container.insert_many(s21_it, '\t', '\v', '\r', '\b', '\f', ' ')};

  EXPECT_EQ(*s21_it_new, '\t');

  s21_it = s21_container.begin();
  for (auto it{container.begin()}; s21_it != s21_container.end();
       ++s21_it, ++it) {
    EXPECT_EQ(*s21_it, *it);
  }

  EXPECT_EQ(container.size(), s21_container.size());
}

TEST(VectorInsertMany, Test9) {
  std::vector container{'a',  'b',  'c',  'x', '\t', '\v',
                        '\r', '\b', '\f', ' ', 'y',  'z'};
  s21::vector s21_container{'a', 'b', 'c', 'x', 'y', 'z'};
  auto s21_it{s21_container.end()};
  std::advance(s21_it, -2);
  auto s21_it_new{
      s21_container.insert_many(s21_it, '\t', '\v', '\r', '\b', '\f', ' ')};

  EXPECT_EQ(*s21_it_new, '\t');

  s21_it = s21_container.begin();
  for (auto it{container.begin()}; s21_it != s21_container.end();
       ++s21_it, ++it) {
    EXPECT_EQ(*s21_it, *it);
  }

  EXPECT_EQ(container.size(), s21_container.size());
}

TEST(VectorInsertMany, Test10) {
  std::vector container{"Non-zero",  "value",      "character",
                        "The",       "behavior",   "is",
                        "undefined", "whitespace", "otherwise"};
  s21::vector s21_container{"Non-zero", "value", "character", "whitespace",
                            "otherwise"};
  auto s21_it{s21_container.end()};
  std::advance(s21_it, -2);
  auto s21_it_new{
      s21_container.insert_many(s21_it, "The", "behavior", "is", "undefined")};

  EXPECT_EQ(*s21_it_new, "The");

  s21_it = s21_container.begin();
  for (auto it{container.begin()}; s21_it != s21_container.end();
       ++s21_it, ++it) {
    EXPECT_EQ(*s21_it, *it);
  }

  EXPECT_EQ(container.size(), s21_container.size());
}

TEST(VectorInsertMany, Test11) {
  const Dummy kArr[]{{0, 22, 10, 2024}, {1, 22, 10, 2024},  {3, 23, 10, 2024},
                     {4, 1, 12, 2024},  {5, 23, 10, 2023},  {6, 1, 1, 2023},
                     {7, 24, 2, 2022},  {8, 1, 1, 2000},    {9, 8, 1, 1992},
                     {10, 1, 1, 2000},  {11, 23, 10, 2024}, {12, 1, 1, 2000}};
  std::vector container{Dummy{11, 8, 1, 1992}, Dummy{12, 1, 1, 2000},
                        Dummy{13, 1, 1, 2000}};
  s21::vector<Dummy> s21_container;
  for (const auto& i : kArr) {
    container.push_back(i);
    s21_container.push_back(i);
  }
  s21_container.insert_many(s21_container.begin(), Dummy{11, 8, 1, 1992},
                            Dummy{12, 1, 1, 2000}, Dummy{13, 1, 1, 2000});

  auto s21_it{s21_container.begin()};
  for (auto it{container.begin()}; s21_it != s21_container.end();
       ++s21_it, ++it) {
    EXPECT_EQ(*s21_it, *it);
  }

  EXPECT_EQ(container.size(), s21_container.size());
}

TEST(VectorInsertMany, Test12) {
  std::vector<std::string> container{"Non-zero",  "value",      "character",
                                     "The",       "behavior",   "is",
                                     "undefined", "whitespace", "otherwise"};
  s21::vector<std::string> s21_container{"Non-zero", "value", "character",
                                         "whitespace", "otherwise"};
  auto s21_it{s21_container.end()};
  std::advance(s21_it, -2);
  auto s21_it_new{
      s21_container.insert_many(s21_it, "The", "behavior", "is", "undefined")};

  EXPECT_EQ(*s21_it_new, "The");

  s21_it = s21_container.begin();
  for (auto it{container.begin()}; s21_it != s21_container.end();
       ++s21_it, ++it) {
    EXPECT_EQ(*s21_it, *it);
  }

  EXPECT_EQ(container.size(), s21_container.size());
}

TEST(VectorInsertMany, Test13) {
  std::vector<std::string> container{
      "The",        "following", "behavior-changing",
      "runtime",    "applied",   "as",
      "a",          "defect",    "report",
      "information"};
  s21::vector<std::string> s21_container{
      "The", "following", "behavior-changing", "runtime", "information"};
  auto s21_it{s21_container.end()};
  std::advance(s21_it, -1);
  auto s21_it_new{s21_container.insert_many(s21_it, "applied", "as", "a",
                                            "defect", "report")};

  EXPECT_EQ(*s21_it_new, "applied");

  s21_it = s21_container.begin();
  for (auto it{container.begin()}; s21_it != s21_container.end();
       ++s21_it, ++it) {
    EXPECT_EQ(*s21_it, *it);
  }

  EXPECT_EQ(container.size(), s21_container.size());
}

TEST(VectorInsertMany, Test14) {
  std::vector<std::string> container{"assigns", "the", "contents", "elements",
                                     "that"};
  s21::vector<std::string> s21_container{"elements", "that"};
  auto s21_it{s21_container.end()};
  std::advance(s21_it, -s21_container.size());
  auto s21_it_new{
      s21_container.insert_many(s21_it, "assigns", "the", "contents")};

  EXPECT_EQ(*s21_it_new, "assigns");

  s21_it = s21_container.begin();
  for (auto it{container.begin()}; s21_it != s21_container.end();
       ++s21_it, ++it) {
    EXPECT_EQ(*s21_it, *it);
  }

  EXPECT_EQ(container.size(), s21_container.size());
}

TEST(VectorInsertMany, Test15) {
  std::vector<std::string> container{"assigns", "the", "contents"};
  s21::vector<std::string> s21_container;
  auto s21_it{s21_container.begin()};
  auto s21_it_new{
      s21_container.insert_many(s21_it, "assigns", "the", "contents")};

  EXPECT_EQ(*s21_it_new, "assigns");

  s21_it = s21_container.begin();
  for (auto it{container.begin()}; s21_it != s21_container.end();
       ++s21_it, ++it) {
    EXPECT_EQ(*s21_it, *it);
  }

  EXPECT_EQ(container.size(), s21_container.size());
}

TEST(VectorInsertManyBack, Test1) {
  std::vector container{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  s21::vector<int> s21_container;
  s21_container.insert_many_back(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
  auto s21_it{s21_container.begin()};
  for (auto it{container.begin()}; s21_it != s21_container.end();
       ++s21_it, ++it) {
    EXPECT_EQ(*s21_it, *it);
  }

  EXPECT_EQ(container.size(), s21_container.size());
}

TEST(VectorInsertManyBack, Test2) {
  std::vector<int> container;
  s21::vector<int> s21_container;
  s21_container.insert_many_back();
  auto s21_it{s21_container.begin()};
  for (auto it{container.begin()}; s21_it != s21_container.end();
       ++s21_it, ++it) {
    EXPECT_EQ(*s21_it, *it);
  }

  EXPECT_EQ(container.size(), s21_container.size());
}

TEST(VectorInsertManyBack, Test3) {
  std::vector container{1};
  s21::vector<int> s21_container;
  s21_container.insert_many_back(1);
  auto s21_it{s21_container.begin()};
  for (auto it{container.begin()}; s21_it != s21_container.end();
       ++s21_it, ++it) {
    EXPECT_EQ(*s21_it, *it);
  }

  EXPECT_EQ(container.size(), s21_container.size());
}

TEST(VectorInsertManyBack, Test4) {
  std::vector container{1, 2, 3};
  s21::vector<int> s21_container;
  s21_container.insert_many_back(1, 2, 3);
  auto s21_it{s21_container.begin()};
  for (auto it{container.begin()}; s21_it != s21_container.end();
       ++s21_it, ++it) {
    EXPECT_EQ(*s21_it, *it);
  }

  EXPECT_EQ(container.size(), s21_container.size());
}

TEST(VectorInsertManyBack, Test5) {
  std::vector container{1, 2, 3};
  s21::vector s21_container{1, 2, 3};
  s21_container.insert_many_back();
  auto s21_it{s21_container.begin()};
  for (auto it{container.begin()}; s21_it != s21_container.end();
       ++s21_it, ++it) {
    EXPECT_EQ(*s21_it, *it);
  }

  EXPECT_EQ(container.size(), s21_container.size());
}

TEST(VectorInsertManyBack, Test6) {
  std::vector container{1, 2, 3, 4, 5, 6};
  s21::vector s21_container{1, 2, 3};
  s21_container.insert_many_back(4, 5, 6);
  auto s21_it{s21_container.begin()};
  for (auto it{container.begin()}; s21_it != s21_container.end();
       ++s21_it, ++it) {
    EXPECT_EQ(*s21_it, *it);
  }

  EXPECT_EQ(container.size(), s21_container.size());
}

TEST(VectorInsertManyBack, Test7) {
  std::vector container{1, 2, 3, 5};
  s21::vector s21_container{1, 2, 3};
  s21_container.insert_many_back(5);
  auto s21_it{s21_container.begin()};
  for (auto it{container.begin()}; s21_it != s21_container.end();
       ++s21_it, ++it) {
    EXPECT_EQ(*s21_it, *it);
  }

  EXPECT_EQ(container.size(), s21_container.size());
}

TEST(VectorInsertManyBack, Test8) {
  std::vector container{'a',  'b',  'c',  'x',  'y',  'z',
                        '\t', '\v', '\r', '\b', '\f', ' '};
  s21::vector s21_container{'a', 'b', 'c', 'x', 'y', 'z'};
  s21_container.insert_many_back('\t', '\v', '\r', '\b', '\f', ' ');
  auto s21_it{s21_container.begin()};
  for (auto it{container.begin()}; s21_it != s21_container.end();
       ++s21_it, ++it) {
    EXPECT_EQ(*s21_it, *it);
  }

  EXPECT_EQ(container.size(), s21_container.size());
}

TEST(VectorInsertManyBack, Test9) {
  std::vector<std::string> container{"Non-zero",   "value",     "character",
                                     "whitespace", "otherwise", "The",
                                     "behavior",   "is",        "undefined"};
  s21::vector<std::string> s21_container{"Non-zero", "value", "character",
                                         "whitespace", "otherwise"};
  s21_container.insert_many_back("The", "behavior", "is", "undefined");
  auto s21_it{s21_container.begin()};
  for (auto it{container.begin()}; s21_it != s21_container.end();
       ++s21_it, ++it) {
    EXPECT_EQ(*s21_it, *it);
  }

  EXPECT_EQ(container.size(), s21_container.size());
}

TEST(VectorInsertManyBack, Test10) {
  std::vector container{
      Dummy{0, 22, 10, 2024}, Dummy{1, 22, 10, 2024},  Dummy{3, 23, 10, 2024},
      Dummy{4, 1, 12, 2024},  Dummy{5, 23, 10, 2023},  Dummy{6, 1, 1, 2023},
      Dummy{7, 24, 2, 2022},  Dummy{8, 1, 1, 2000},    Dummy{9, 8, 1, 1992},
      Dummy{10, 1, 1, 2000},  Dummy{11, 23, 10, 2024}, Dummy{12, 1, 1, 2000},
      Dummy{11, 8, 1, 1992},  Dummy{12, 1, 1, 2000},   Dummy{13, 1, 1, 2000}};
  s21::vector s21_container{
      Dummy{0, 22, 10, 2024}, Dummy{1, 22, 10, 2024},  Dummy{3, 23, 10, 2024},
      Dummy{4, 1, 12, 2024},  Dummy{5, 23, 10, 2023},  Dummy{6, 1, 1, 2023},
      Dummy{7, 24, 2, 2022},  Dummy{8, 1, 1, 2000},    Dummy{9, 8, 1, 1992},
      Dummy{10, 1, 1, 2000},  Dummy{11, 23, 10, 2024}, Dummy{12, 1, 1, 2000}};

  s21_container.insert_many_back(Dummy{11, 8, 1, 1992}, Dummy{12, 1, 1, 2000},
                                 Dummy{13, 1, 1, 2000});
  auto s21_it{s21_container.begin()};
  for (auto it{container.begin()}; s21_it != s21_container.end();
       ++s21_it, ++it) {
    EXPECT_EQ(*s21_it, *it);
  }

  EXPECT_EQ(container.size(), s21_container.size());
}

TEST(VectorErase, Test1) {
  std::srand(std::time(nullptr));
  const int n{1'000};
  std::vector<int> container;
  s21::vector<int> s21_container;

  for (int i{}; i != n; ++i) {
    const int random_value{std::rand()};
    container.push_back(random_value);
    s21_container.push_back(random_value);
  }

  container.erase(container.begin());
  s21_container.erase(s21_container.begin());

  auto s21_it{s21_container.begin()};
  for (auto it{container.begin()}; s21_it != s21_container.end();
       ++s21_it, ++it) {
    EXPECT_EQ(*s21_it, *it);
  }

  EXPECT_EQ(container.size(), s21_container.size());
}

TEST(VectorErase, Test2) {
  std::srand(std::time(nullptr));
  const int n{1'000};
  std::vector<int> container;
  s21::vector<int> s21_container;

  for (int i{}; i != n; ++i) {
    const int random_value{std::rand()};
    container.push_back(random_value);
    s21_container.push_back(random_value);
  }

  container.erase(container.end() - 1);
  s21_container.erase(s21_container.end() - 1);

  auto s21_it{s21_container.end()};
  auto it{container.end()};
  do {
    EXPECT_EQ(*--s21_it, *--it);
  } while (s21_it != s21_container.begin());

  EXPECT_EQ(container.size(), s21_container.size());
}

TEST(VectorErase, Test3) {
  std::srand(std::time(nullptr));
  const int n{1'000};
  std::vector<int> container;
  s21::vector<int> s21_container;

  for (int i{}; i != n; ++i) {
    const int random_value{std::rand()};
    container.push_back(random_value);
    s21_container.push_back(random_value);
  }

  const int position{std::rand() % n};
  container.erase(container.begin() + position);
  s21_container.erase(s21_container.begin() + position);

  auto s21_it{s21_container.end()};
  auto it{container.end()};
  do {
    EXPECT_EQ(*--s21_it, *--it);
  } while (s21_it != s21_container.begin());

  EXPECT_EQ(container.size(), s21_container.size());
}

TEST(VectorErase, Test4) {
  std::vector<std::string> container{"another", "range", "beginning"};
  s21::vector<std::string> s21_container{"another", "range", "beginning"};

  container.erase(container.begin());
  s21_container.erase(s21_container.begin());

  auto s21_it{s21_container.end()};
  auto it{container.end()};
  do {
    EXPECT_EQ(*--s21_it, *--it);
  } while (s21_it != s21_container.begin());

  EXPECT_EQ(container.size(), s21_container.size());
}

TEST(VectorErase, Test5) {
  std::srand(std::time(nullptr));
  std::vector<std::string> container{"Copies",       "the",       "elements",
                                     "in",           "the",       "range",
                                     "concurrently", "accessing", "guaranteed"};
  s21::vector<std::string> s21_container{
      "Copies", "the",          "elements",  "in",        "the",
      "range",  "concurrently", "accessing", "guaranteed"};

  while (!s21_container.empty()) {
    const auto position{std::rand() % s21_container.size()};
    container.erase(container.begin() + position);
    s21_container.erase(s21_container.begin() + position);

    auto s21_it{s21_container.begin()};
    for (auto it{container.begin()}; s21_it != s21_container.end();
         ++s21_it, ++it) {
      EXPECT_EQ(*s21_it, *it);
    }
  }

  EXPECT_EQ(container.size(), s21_container.size());
}
