#include <array>
#include <ctime>
#include <string>

#include "all_tests_s21.h"

TEST(ArrayConstructor, Test1) {
  s21::array<int, 1> s21_container{};
  std::array<int, 1> container{};
  EXPECT_EQ(s21_container.size(), container.size());
  EXPECT_EQ(s21_container.empty(), false);
}

TEST(ArrayConstructor, Test2) {
  s21::array<char, 0> s21_container;
  std::array<char, 0> container;
  EXPECT_EQ(s21_container.size(), container.size());
  EXPECT_EQ(s21_container.empty(), true);
}

TEST(ArrayConstructor, Test3) {
  s21::array s21_container{1, 2, 3, 4, 5};
  std::array container{1, 2, 3, 4, 5};
  EXPECT_EQ(s21_container.size(), container.size());
  auto s21_data{s21_container.data()};
  for (const auto &i : container) {
    EXPECT_EQ(*s21_data, i);
    ++s21_data;
  }
}

TEST(ArrayConstructor, Test4) {
  s21::array s21_container_1{1, 2, 3, 4, 5};
  std::array container_1{1, 2, 3, 4, 5};

  s21::array s21_container_2{s21_container_1};
  std::array container_2{container_1};

  s21_container_1[0] = 6;
  container_1[0] = 6;

  auto s21_data{s21_container_1.data()};
  for (const auto &i : container_1) {
    EXPECT_EQ(*s21_data, i);
    ++s21_data;
  }

  s21_data = s21_container_2.data();
  for (const auto &i : container_2) {
    EXPECT_EQ(*s21_data, i);
    ++s21_data;
  }
}

TEST(ArrayConstructor, Test5) {
  const char *word{"School 21"};
  s21::array<std::string, 9UL> s21_container_1{
      "The", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog"};
  std::array<std::string, 9UL> container{
      "The", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog"};

  for (size_t i{0}, count{s21_container_1.size()}; i != count; ++i) {
    EXPECT_EQ(s21_container_1[i], container[i]);
  }
  EXPECT_EQ(s21_container_1.size(), 9UL);

  s21::array s21_container_2{std::move(s21_container_1)};

  s21_container_1.fill(word);

  for (size_t i{0}, count{s21_container_1.size()}; i != count; ++i) {
    EXPECT_EQ(s21_container_1[i], word);
  }

  for (size_t i{0}, count{s21_container_2.size()}; i != count; ++i) {
    EXPECT_EQ(s21_container_2[i], container[i]);
  }
  EXPECT_EQ(s21_container_1.size(), s21_container_2.size());
}

TEST(ArrayConstructor, Test6) {
  const char *word{"School 21"};
  s21::array<std::string, 9UL> s21_container_1{
      "The", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog"};
  std::array<std::string, 9UL> container{
      "The", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog"};
  s21::array<std::string, 9UL> s21_container_2;
  s21_container_2 = s21_container_1;

  s21_container_1.fill(word);

  auto last{s21_container_2.end()};
  auto first{s21_container_2.begin()};
  auto it{container.end()};

  do {
    EXPECT_EQ(*--last, *--it);
  } while (first != last);

  for (size_t i{0}, count{s21_container_1.size()}; i != count; ++i) {
    EXPECT_EQ(s21_container_1[i], word);
  }
}

TEST(ArrayConstructor, Test7) {
  const char *word{"School 21"};
  s21::array<std::string, 9UL> s21_container_1{
      "The", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog"};
  std::array<std::string, 9UL> container{
      "The", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog"};
  EXPECT_EQ(s21_container_1.front(), container.front());
  EXPECT_EQ(s21_container_1.back(), container.back());

  s21::array<std::string, 9UL> s21_container_2;
  s21_container_2 = std::move(s21_container_1);

  s21_container_1.fill(word);

  const s21::array<std::string, 9UL> &ref{s21_container_2};
  auto first{ref.begin()};
  auto last{ref.end()};

  for (auto it{container.begin()}; first != last; ++first, ++it) {
    EXPECT_EQ(*first, *it);
  }

  for (size_t i{0}, count{s21_container_1.size()}; i != count; ++i) {
    EXPECT_EQ(s21_container_1[i], word);
  }
}

TEST(ArrayConstructor, Test8) {
  s21::array<int, 21> s21_container{5, 4, 3, 2, 1};
  std::array<int, 21> container{5, 4, 3, 2, 1};

  for (size_t i{0}, count{s21_container.size()}; i != count; ++i) {
    EXPECT_EQ(s21_container[i], container[i]);
  }
}

TEST(ArrayConstructor, Test9) {
  s21::array s21_container_nested{5, 4, 3, 2, 1};
  std::array container_nested{5, 4, 3, 2, 1};

  s21::array s21_container{s21_container_nested, s21_container_nested};
  std::array container{container_nested, container_nested};

  for (size_t i{0}, count{s21_container.size()}; i != count; ++i) {
    EXPECT_EQ(s21_container[i].size(), container[i].size());
    for (size_t j{0}, size{container[i].size()}; j != size; ++j) {
      EXPECT_EQ(s21_container[i][j], container[i][j]);
    }
  }
}

TEST(ArrayConstructor, Test10) {
  s21::array<int, 21> s21_container_1{5, 4, 3, 2, 1};
  std::array<int, 21> container_1{5, 4, 3, 2, 1};

  s21::array<int, 21> s21_container_2;
  std::array<int, 21> container_2;

  s21_container_1 = s21_container_1;

  for (size_t i{0}, count{s21_container_1.size()}; i != count; ++i) {
    EXPECT_EQ(s21_container_1[i], container_1[i]);
  }

  s21_container_2 = s21_container_1;
  container_2 = container_1;

  container_2[6] = s21_container_2[6] = 6;

  for (size_t i{0}, count{s21_container_2.size()}; i != count; ++i) {
    EXPECT_EQ(s21_container_2[i], container_2[i]);
    EXPECT_EQ(s21_container_1[i], container_1[i]);
  }
}

TEST(Arrayswap, Test1) {
  std::srand(std::time(nullptr));
  const size_t n{21};
  s21::array<int, n> s21_container_1;
  s21::array<int, n> s21_container_2;
  std::array<int, n> container_1;
  std::array<int, n> container_2;
  for (int i{0}; i != n; ++i) {
    const int random_value{std::rand()};
    container_1[i] = random_value;
    s21_container_1[i] = random_value;
  }

  s21_container_1.swap(s21_container_2);
  container_1.swap(container_2);

  container_1.fill(0);
  s21_container_1.fill(0);

  for (size_t i{0}; i != n; ++i) {
    EXPECT_EQ(s21_container_2[i], container_2[i]);
  }

  for (size_t i{0}; i != n; ++i) {
    EXPECT_EQ(s21_container_1[i], container_1[i]);
  }
}

TEST(Arrayswap, Test2) {
  std::srand(std::time(nullptr));
  const size_t n{21};
  s21::array<int, n> s21_container;
  std::array<int, n> container;
  for (int i{0}; i != n; ++i) {
    const int random_value{std::rand()};
    container[i] = random_value;
    s21_container[i] = random_value;
  }

  s21_container.swap(s21_container);

  for (size_t i{0}; i != n; ++i) {
    EXPECT_EQ(s21_container[i], container[i]);
  }
}

TEST(Arrayat, Test1) {
  s21::array<int, 0> s21_container;
  std::array<int, 0> container;
  EXPECT_THROW(s21_container.at(0), std::out_of_range);
  EXPECT_THROW(container.at(0), std::out_of_range);
}

TEST(Arrayat, Test2) {
  s21::array<int, 0> s21_container;
  std::array<int, 0> container;
  EXPECT_THROW(s21_container.at(1), std::out_of_range);
  EXPECT_THROW(container.at(1), std::out_of_range);
}

TEST(Arrayat, Test3) {
  s21::array<int, 1> s21_container;
  std::array<int, 1> container;
  EXPECT_THROW(s21_container.at(2), std::out_of_range);
  EXPECT_THROW(container.at(2), std::out_of_range);
}

TEST(Arrayat, Test4) {
  s21::array<int, 1> s21_container;
  std::array<int, 1> container;
  EXPECT_THROW(s21_container.at(-1), std::out_of_range);
  EXPECT_THROW(container.at(-1), std::out_of_range);
}

TEST(Arrayat, Test5) {
  s21::array<int, 10> s21_container;
  std::array<int, 10> container;
  size_t i{0};
  for (; i != s21_container.size(); ++i) {
    EXPECT_NO_THROW(s21_container.at(i));
    EXPECT_NO_THROW(container.at(i));
  }
  EXPECT_THROW(s21_container.at(i), std::out_of_range);
  EXPECT_THROW(container.at(i), std::out_of_range);
}

TEST(ArrayMaxsize, Test1) {
  s21::array<int, 1> s21_container{};
  std::array<int, 1> container{};
  EXPECT_EQ(s21_container.max_size(), container.max_size());
}

TEST(ArrayMaxsize, Test2) {
  s21::array<uint8_t, 1> s21_container{};
  std::array<uint8_t, 1> container{};
  EXPECT_EQ(s21_container.max_size(), container.max_size());
}

TEST(ArrayMaxsize, Test3) {
  s21::array<Dummy, 1> s21_container{};
  std::array<Dummy, 1> container{};
  EXPECT_EQ(s21_container.max_size(), container.max_size());
}

TEST(ArrayMaxsize, Test4) {
  s21::array<int *, 1> s21_container{};
  std::array<int *, 1> container{};
  EXPECT_EQ(s21_container.max_size(), container.max_size());
}

TEST(ArrayMaxsize, Test5) {
  s21::array<int *, 0> s21_container;
  std::array<int *, 0> container;
  EXPECT_EQ(s21_container.max_size(), container.max_size());
}

TEST(ArrayMaxsize, Test6) {
  s21::array s21_container{"back", "bait", "cat", "cow", "crow"};
  std::array container{"back", "bait", "cat", "cow", "crow"};
  EXPECT_EQ(s21_container.max_size(), container.max_size());
}

TEST(ArrayMaxsize, Test7) {
  s21::array<const char *, 10UL> s21_container{"back", "bait", "cat", "cow"};
  std::array<const char *, 10UL> container{"back", "bait", "cat", "cow"};
  EXPECT_EQ(s21_container.max_size(), container.max_size());
  EXPECT_EQ(s21_container.size(), container.size());
}

TEST(ArrayMaxsize, Test8) {
  s21::array s21_container{
      Dummy{0, 22, 10, 2024}, Dummy{1, 22, 10, 2024},  Dummy{3, 23, 10, 2024},
      Dummy{4, 1, 12, 2024},  Dummy{5, 23, 10, 2023},  Dummy{6, 1, 1, 2023},
      Dummy{7, 24, 2, 2022},  Dummy{8, 1, 1, 2000},    Dummy{9, 8, 1, 1992},
      Dummy{10, 1, 1, 2000},  Dummy{11, 23, 10, 2024}, Dummy{12, 1, 1, 2000}};
  std::array container{
      Dummy{0, 22, 10, 2024}, Dummy{1, 22, 10, 2024},  Dummy{3, 23, 10, 2024},
      Dummy{4, 1, 12, 2024},  Dummy{5, 23, 10, 2023},  Dummy{6, 1, 1, 2023},
      Dummy{7, 24, 2, 2022},  Dummy{8, 1, 1, 2000},    Dummy{9, 8, 1, 1992},
      Dummy{10, 1, 1, 2000},  Dummy{11, 23, 10, 2024}, Dummy{12, 1, 1, 2000}};

  EXPECT_EQ(s21_container.max_size(), container.max_size());
  EXPECT_EQ(s21_container.size(), 12UL);

  auto first{s21_container.begin()};
  auto last{s21_container.end()};
  for (auto it{container.begin()}; first != last; ++first, ++it) {
    EXPECT_EQ(*first, *it);
  }
}
