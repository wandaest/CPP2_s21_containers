#include <deque>
#include <queue>

#include "all_tests_s21.h"

TEST(QueueConstructor, Test1) {
  s21::queue<int> s21_container;
  std::queue<int> container;
  EXPECT_EQ(s21_container.empty(), container.empty());
}

TEST(QueueConstructor, Test2) {
  s21::queue<int> s21_container;
  std::queue<int> container;
  EXPECT_EQ(s21_container.size(), container.size());
}

TEST(QueueConstructor, Test3) {
  s21::queue s21_container{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::deque deq{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::queue container{deq};
  EXPECT_EQ(s21_container.size(), container.size());
  while (!s21_container.empty()) {
    EXPECT_EQ(s21_container.front(), container.front());
    s21_container.pop();
    container.pop();
  }
  EXPECT_EQ(s21_container.empty(), container.empty());
}

TEST(QueueConstructor, Test4) {
  s21::queue s21_container{"the", "frogurt", "is", "also", "cursed"};
  std::deque deq{"the", "frogurt", "is", "also", "cursed"};
  std::queue container{deq};

  s21::queue<const char*> s21_copy;
  s21_copy = s21_container;

  const size_t s21_container_size{s21_container.size()};

  while (!s21_container.empty()) {
    EXPECT_EQ(s21_container.front(), container.front());
    s21_container.pop();
    container.pop();
  }

  EXPECT_EQ(s21_copy.size(), s21_container_size);
  EXPECT_EQ(s21_container.empty(), true);
}

TEST(QueueConstructor, Test5) {
  s21::queue<std::string> s21_container{"the", "frogurt", "is", "also",
                                        "cursed"};
  std::deque<std::string> deq{"the", "frogurt", "is", "also", "cursed"};
  std::queue<std::string> container{deq};

  s21::queue<std::string> s21_copy;
  s21_copy = std::move(s21_container);

  const size_t s21_container_size{s21_container.size()};

  while (!s21_container.empty()) {
    EXPECT_EQ(s21_container.front(), container.front());
    s21_container.pop();
    container.pop();
  }

  EXPECT_EQ(s21_copy.size(), s21_container_size);
  EXPECT_EQ(s21_container.empty(), true);
}

TEST(QueueConstructor, Test6) {
  s21::queue<std::string> s21_container{"cat", "cow", "crow"};
  std::deque<std::string> deq{"cat", "cow", "crow"};
  std::queue container{deq};

  s21::queue s21_copy{std::move(s21_container)};

  const size_t s21_container_size{s21_container.size()};

  while (!s21_container.empty()) {
    EXPECT_EQ(s21_container.front(), container.front());
    s21_container.pop();
    container.pop();
  }

  EXPECT_EQ(s21_copy.size(), s21_container_size);
  EXPECT_EQ(s21_container.empty(), true);
}

TEST(QueuePush, Test1) {
  const char a{'a'};
  s21::queue<char> s21_container;
  std::queue<char> container;
  for (int i{0}, count{'z' - 'a'}; i <= count; ++i) {
    s21_container.push(a + i);
    container.push(a + i);
    EXPECT_EQ(s21_container.back(), container.back());
  }
  EXPECT_EQ(s21_container.size(), container.size());
}

TEST(QueuePush, Test2) {
  const Dummy kArr[]{{1, 8, 1, 1992},    {2, 1, 1, 2000},    {3, 1, 1, 2000},
                     {4, 24, 2, 2022},   {5, 1, 1, 2023},    {6, 23, 10, 2023},
                     {7, 22, 10, 2024},  {8, 22, 10, 2024},  {9, 23, 10, 2024},
                     {10, 1, 12, 2024},  {11, 8, 1, 1992},   {12, 1, 1, 2000},
                     {13, 1, 1, 2000},   {14, 24, 2, 2022},  {15, 1, 1, 2023},
                     {16, 23, 10, 2023}, {17, 22, 10, 2024}, {18, 22, 10, 2024},
                     {19, 23, 10, 2024}, {20, 1, 12, 2024}};
  s21::queue<Dummy> s21_container;
  std::queue<Dummy> container;
  for (size_t i{0}; i != std::size(kArr); ++i) {
    s21_container.push(kArr[i]);
    container.push(kArr[i]);
    EXPECT_EQ(s21_container.back(), container.back());
  }

  EXPECT_EQ(s21_container.size(), container.size());

  while (!s21_container.empty()) {
    EXPECT_EQ(s21_container.front(), container.front());
    s21_container.pop();
    container.pop();
  }

  EXPECT_EQ(s21_container.size(), container.size());
  EXPECT_EQ(s21_container.empty(), true);
}

TEST(QueueSwap, Test1) {
  std::srand(std::time(nullptr));
  const int n{21};
  s21::queue<int> s21_container_1;
  s21::queue<int> s21_container_2;
  std::queue<int> container;
  for (int i{0}; i != n; ++i) {
    const int random_value{std::rand()};
    container.push(random_value);
    s21_container_1.push(random_value);
  }

  const size_t s21_container_size{s21_container_1.size()};

  s21_container_1.swap(s21_container_2);

  EXPECT_EQ(s21_container_1.empty(), true);
  EXPECT_EQ(s21_container_2.size(), s21_container_size);

  while (!s21_container_2.empty()) {
    EXPECT_EQ(s21_container_2.front(), container.front());
    s21_container_2.pop();
    container.pop();
  }

  EXPECT_EQ(s21_container_2.empty(), true);
}

TEST(QueueSwap, Test2) {
  std::srand(std::time(nullptr));
  const int n{21};
  s21::queue<int> s21_container;
  std::queue<int> container;
  for (int i{0}; i != n; ++i) {
    const int random_value{std::rand()};
    container.push(random_value);
    s21_container.push(random_value);
  }

  s21_container.swap(s21_container);

  while (!s21_container.empty()) {
    EXPECT_EQ(s21_container.front(), container.front());
    s21_container.pop();
    container.pop();
  }

  EXPECT_EQ(s21_container.size(), container.size());
  EXPECT_EQ(s21_container.empty(), true);
}

TEST(QueueInsertManyBack, Test1) {
  std::deque deq{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::queue container{deq};
  s21::queue<int> s21_container;
  s21_container.insert_many_back(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
  EXPECT_EQ(s21_container.size(), container.size());
  while (!s21_container.empty()) {
    EXPECT_EQ(s21_container.front(), container.front());
    s21_container.pop();
    container.pop();
  }
  EXPECT_EQ(s21_container.empty(), container.empty());
}

TEST(QueueInsertManyBack, Test2) {
  std::queue<int> container;
  s21::queue<int> s21_container;
  s21_container.insert_many_back();
  EXPECT_EQ(s21_container.size(), container.size());
  while (!s21_container.empty()) {
    EXPECT_EQ(s21_container.front(), container.front());
    s21_container.pop();
    container.pop();
  }
  EXPECT_EQ(s21_container.empty(), container.empty());
}

TEST(QueueInsertManyBack, Test3) {
  std::deque deq{1};
  std::queue container{deq};
  s21::queue<int> s21_container;
  s21_container.insert_many_back(1);
  EXPECT_EQ(s21_container.size(), container.size());
  while (!s21_container.empty()) {
    EXPECT_EQ(s21_container.front(), container.front());
    s21_container.pop();
    container.pop();
  }
  EXPECT_EQ(s21_container.empty(), container.empty());
}

TEST(QueueInsertManyBack, Test4) {
  std::deque deq{1, 2, 3};
  std::queue container{deq};
  s21::queue<int> s21_container;
  s21_container.insert_many_back(1, 2, 3);
  EXPECT_EQ(s21_container.size(), container.size());
  while (!s21_container.empty()) {
    EXPECT_EQ(s21_container.front(), container.front());
    s21_container.pop();
    container.pop();
  }
  EXPECT_EQ(s21_container.empty(), container.empty());
}

TEST(QueueInsertManyBack, Test5) {
  std::deque deq{1, 2, 3};
  std::queue container{deq};
  s21::queue s21_container{1, 2, 3};
  s21_container.insert_many_back();
  EXPECT_EQ(s21_container.size(), container.size());
  while (!s21_container.empty()) {
    EXPECT_EQ(s21_container.front(), container.front());
    s21_container.pop();
    container.pop();
  }
  EXPECT_EQ(s21_container.empty(), container.empty());
}

TEST(QueueInsertManyBack, Test6) {
  std::deque deq{1, 2, 3, 4, 5, 6};
  std::queue container{deq};
  s21::queue s21_container{1, 2, 3};
  s21_container.insert_many_back(4, 5, 6);
  EXPECT_EQ(s21_container.size(), container.size());
  while (!s21_container.empty()) {
    EXPECT_EQ(s21_container.front(), container.front());
    s21_container.pop();
    container.pop();
  }
  EXPECT_EQ(s21_container.empty(), container.empty());
}

TEST(QueueInsertManyBack, Test7) {
  std::deque deq{1, 2, 3, 5};
  std::queue container{deq};
  s21::queue s21_container{1, 2, 3};
  s21_container.insert_many_back(5);
  EXPECT_EQ(s21_container.size(), container.size());
  while (!s21_container.empty()) {
    EXPECT_EQ(s21_container.front(), container.front());
    s21_container.pop();
    container.pop();
  }
  EXPECT_EQ(s21_container.empty(), container.empty());
}

TEST(QueueInsertManyBack, Test8) {
  std::deque deq{'a',  'b',  'c',  'x',  'y',  'z',
                 '\t', '\v', '\r', '\b', '\f', ' '};
  std::queue container{deq};
  s21::queue s21_container{'a', 'b', 'c', 'x', 'y', 'z'};
  s21_container.insert_many_back('\t', '\v', '\r', '\b', '\f', ' ');
  EXPECT_EQ(s21_container.size(), container.size());
  while (!s21_container.empty()) {
    EXPECT_EQ(s21_container.front(), container.front());
    s21_container.pop();
    container.pop();
  }
  EXPECT_EQ(s21_container.empty(), container.empty());
}

TEST(QueueInsertManyBack, Test9) {
  std::deque<std::string> deq{"Non-zero",   "value",     "character",
                              "whitespace", "otherwise", "The",
                              "behavior",   "is",        "undefined"};
  std::queue<std::string> container{deq};
  s21::queue<std::string> s21_container{"Non-zero", "value", "character",
                                        "whitespace", "otherwise"};
  s21_container.insert_many_back("The", "behavior", "is", "undefined");
  EXPECT_EQ(s21_container.size(), container.size());
  while (!s21_container.empty()) {
    EXPECT_EQ(s21_container.front(), container.front());
    s21_container.pop();
    container.pop();
  }
  EXPECT_EQ(s21_container.empty(), container.empty());
}

TEST(QueueInsertManyBack, Test10) {
  std::deque deq{
      Dummy{0, 22, 10, 2024}, Dummy{1, 22, 10, 2024},  Dummy{3, 23, 10, 2024},
      Dummy{4, 1, 12, 2024},  Dummy{5, 23, 10, 2023},  Dummy{6, 1, 1, 2023},
      Dummy{7, 24, 2, 2022},  Dummy{8, 1, 1, 2000},    Dummy{9, 8, 1, 1992},
      Dummy{10, 1, 1, 2000},  Dummy{11, 23, 10, 2024}, Dummy{12, 1, 1, 2000},
      Dummy{11, 8, 1, 1992},  Dummy{12, 1, 1, 2000},   Dummy{13, 1, 1, 2000}};
  std::queue container{deq};
  s21::queue s21_container{
      Dummy{0, 22, 10, 2024}, Dummy{1, 22, 10, 2024},  Dummy{3, 23, 10, 2024},
      Dummy{4, 1, 12, 2024},  Dummy{5, 23, 10, 2023},  Dummy{6, 1, 1, 2023},
      Dummy{7, 24, 2, 2022},  Dummy{8, 1, 1, 2000},    Dummy{9, 8, 1, 1992},
      Dummy{10, 1, 1, 2000},  Dummy{11, 23, 10, 2024}, Dummy{12, 1, 1, 2000}};

  s21_container.insert_many_back(Dummy{11, 8, 1, 1992}, Dummy{12, 1, 1, 2000},
                                 Dummy{13, 1, 1, 2000});
  EXPECT_EQ(s21_container.size(), container.size());
  while (!s21_container.empty()) {
    EXPECT_EQ(s21_container.front(), container.front());
    s21_container.pop();
    container.pop();
  }
  EXPECT_EQ(s21_container.empty(), container.empty());
}
