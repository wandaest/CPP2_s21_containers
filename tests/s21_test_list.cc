#include <ctime>
#include <list>
#include <string>

#include "all_tests_s21.h"

TEST(ListConstructor, Test1) {
  s21::list<int> s21_container;
  EXPECT_EQ(s21_container.size(), 0);
  EXPECT_EQ(s21_container.empty(), true);
}

TEST(ListConstructor, Test2) {
  const size_t n{0};
  std::list<std::string> container(n);
  s21::list<std::string> s21_container(n);
  EXPECT_EQ(container.size(), s21_container.size());
  EXPECT_EQ(s21_container.empty(), true);
}

TEST(ListConstructor, Test3) {
  const size_t n{21};
  std::list<std::string> container(n);
  s21::list<std::string> s21_container(n);
  EXPECT_EQ(container.size(), s21_container.size());

  auto it{container.begin()};
  auto s21_it{s21_container.begin()};
  for (; s21_it != s21_container.end(); ++s21_it, ++it) {
    EXPECT_EQ(*it, *s21_it);
  }
}

TEST(ListConstructor, Test4) {
  s21::list<std::string> s21_container{"the", "frogurt", "is", "also",
                                       "cursed"};
  std::list<std::string> container{"the", "frogurt", "is", "also", "cursed"};

  s21::list<std::string> s21_copy(21);
  s21_copy = s21_container;

  auto s21_it{s21_container.begin()};
  for (auto it{s21_copy.begin()}; s21_it != s21_container.end();
       ++s21_it, ++it) {
    EXPECT_EQ(*it, *s21_it);
  }

  s21_copy.clear();

  s21_it = s21_container.begin();
  for (auto it{container.begin()}; s21_it != s21_container.end();
       ++s21_it, ++it) {
    EXPECT_EQ(*it, *s21_it);
  }
}

TEST(ListConstructor, Test5) {
  s21::list<std::string> s21_container;
  std::list<std::string> container;

  EXPECT_EQ(container.size(), s21_container.size());
  EXPECT_EQ(s21_container.empty(), true);

  s21::list<std::string> s21_copy(21);
  s21_copy = s21_container;

  EXPECT_EQ(container.size(), s21_copy.size());
  EXPECT_EQ(s21_copy.empty(), true);
}

TEST(ListConstructor, Test6) {
  s21::list<std::string> s21_container{"cat", "cow", "crow"};
  std::list<std::string> container{"cat", "cow", "crow"};

  s21::list<std::string> s21_copy(21);
  s21_copy = std::move(s21_container);

  auto s21_it{s21_container.begin()};
  for (auto it{s21_copy.begin()}; s21_it != s21_container.end();
       ++s21_it, ++it) {
    EXPECT_EQ(*it, *s21_it);
  }

  s21_copy.clear();

  s21_it = s21_container.begin();
  for (auto it{container.begin()}; s21_it != s21_container.end();
       ++s21_it, ++it) {
    EXPECT_EQ(*it, *s21_it);
  }
}

TEST(ListConstructor, Test7) {
  s21::list<std::string> s21_container{"cat", "cow", "crow"};
  std::list<std::string> container{"cat", "cow", "crow"};

  s21::list s21_copy{s21::list<std::string>{"cat", "cow", "crow"}};

  auto s21_it{s21_container.begin()};
  for (auto it{s21_copy.begin()}; s21_it != s21_container.end();
       ++s21_it, ++it) {
    EXPECT_EQ(*it, *s21_it);
  }

  s21_copy.clear();

  s21_it = s21_container.begin();
  for (auto it{container.begin()}; s21_it != s21_container.end();
       ++s21_it, ++it) {
    EXPECT_EQ(*it, *s21_it);
  }
}

TEST(ListConstructor, Test8) {
  s21::list s21_container{"The",  "quick", "brown", "fox", "jumps",
                          "over", "the",   "lazy",  "dog"};
  std::list container{"The",  "quick", "brown", "fox", "jumps",
                      "over", "the",   "lazy",  "dog"};

  auto s21_it{s21_container.begin()};
  for (auto it{container.begin()}; s21_it != s21_container.end();
       ++s21_it, ++it) {
    EXPECT_EQ(*it, *s21_it);
  }
}

TEST(ListPush, Test1) {
  s21::list<int> s21_container;

  for (int i{0}; i != 21; ++i) {
    s21_container.push_back(i + 1);
  }
  EXPECT_EQ(s21_container.size(), 21);

  for (size_t i{s21_container.size()}; i != 0; --i) {
    s21_container.pop_back();
  }
  EXPECT_EQ(s21_container.empty(), true);
}

TEST(ListPush, Test2) {
  s21::list<std::string> s21_container;

  for (int i{0}; i != 21; ++i) {
    s21_container.push_back("School " + std::to_string(i + 1));
  }
  EXPECT_EQ(s21_container.size(), 21);

  for (size_t i{s21_container.size()}; i != 0; --i) {
    s21_container.pop_back();
  }
  EXPECT_EQ(s21_container.empty(), true);
}

TEST(ListBack, Test1) {
  const char a{'a'};
  s21::list<char> s21_container;
  std::list<char> container;
  for (int i{0}, count{'z' - 'a'}; i <= count; ++i) {
    s21_container.push_back(a + i);
    container.push_back(a + i);
    EXPECT_EQ(s21_container.back(), container.back());
  }
  auto container_i{container.begin()};
  auto s21_container_i{s21_container.begin()};
  for (; container_i != container.end(); ++container_i, s21_container_i++) {
    EXPECT_EQ(*s21_container_i, *container_i);
  }
  EXPECT_EQ(s21_container_i, s21_container.end());
}

TEST(ListFront, Test5) {
  const char a{'A'};
  s21::list<char> s21_container;
  std::list<char> container;
  for (int i{0}, count{'Z' - 'A'}; i <= count; ++i) {
    s21_container.push_front(a + i);
    container.push_front(a + i);
    EXPECT_EQ(s21_container.front(), container.front());
  }
  auto container_i{container.begin()};
  auto s21_container_i{s21_container.begin()};
  for (; container_i != container.end(); ++container_i, s21_container_i++) {
    EXPECT_EQ(*s21_container_i, *container_i);
  }
  EXPECT_EQ(s21_container_i, s21_container.end());
}

TEST(ListPop, Test1) {
  const int n{13};
  const char small_a{'a'};
  const char big_a{'A'};
  s21::list<char> s21_container;
  std::list<char> container;
  for (int i{0}, count{'z' - 'a'}; i <= count; ++i) {
    s21_container.push_front(small_a + i);
    container.push_front(small_a + i);
  }
  for (int i{0}, count{'Z' - 'A'}; i <= count; ++i) {
    s21_container.push_back(big_a + i);
    container.push_back(big_a + i);
  }
  for (int i{0}; i != n; ++i) {
    s21_container.pop_front();
    container.pop_front();
  }
  for (int i{0}; i != n; ++i) {
    s21_container.pop_back();
    container.pop_back();
  }
  auto container_i{container.begin()};
  auto s21_container_i{s21_container.begin()};
  for (; container_i != container.end(); ++container_i, ++s21_container_i) {
    EXPECT_EQ(*s21_container_i, *container_i);
  }
  EXPECT_EQ(s21_container_i, s21_container.end());

  EXPECT_EQ(s21_container.front(), container.front());
  EXPECT_EQ(s21_container.back(), container.back());
}

TEST(ListPop, Test2) {
  const int n{11};
  const char small_a{'a'};
  const char big_a{'A'};
  s21::list<int> s21_container;
  std::list<int> container;
  for (int i{0}, count{'z' - 'a'}; i <= count; ++i) {
    s21_container.push_front(small_a + i);
    container.push_front(small_a + i);
  }
  for (int i{0}, count{'Z' - 'A'}; i <= count; ++i) {
    s21_container.push_back(big_a + i);
    container.push_back(big_a + i);
  }
  for (int i{0}; i != n; ++i) {
    s21_container.pop_front();
    container.pop_front();
  }
  for (int i{0}; i != n; ++i) {
    s21_container.pop_back();
    container.pop_back();
  }
  auto container_i{container.end()};
  auto s21_container_i{s21_container.end()};
  do {
    EXPECT_EQ(*--s21_container_i, *--container_i);
  } while (container_i != container.begin());
  EXPECT_EQ(s21_container_i, s21_container.begin());

  EXPECT_EQ(s21_container.front(), container.front());
  EXPECT_EQ(s21_container.back(), container.back());
}

TEST(ListIterator, Test1) {
  const uint64_t n{21};
  std::list<uint64_t> container;
  s21::list<uint64_t> s21_container;
  auto container_i{container.begin()};
  auto s21_container_i{s21_container.begin()};
  for (uint64_t i{0}; i != n; ++i) {
    container_i = container.insert(container_i, i);
    s21_container_i = s21_container.insert(s21_container_i, i);
  }
  container_i = container.begin();
  s21_container_i = s21_container.begin();
  size_t counter{0};
  for (; s21_container_i != s21_container.end();
       s21_container_i++, container_i++, ++counter) {
    EXPECT_EQ(*s21_container_i, *container_i);
  }
  EXPECT_EQ(s21_container.size(), counter);
  EXPECT_EQ(s21_container.size(), container.size());
}

TEST(ListIterator, Test2) {
  const uint64_t n{21};
  std::list<uint64_t> container;
  s21::list<uint64_t> s21_container;
  auto container_i{container.end()};
  auto s21_container_i{s21_container.end()};
  for (uint64_t i{0}; i != n; ++i) {
    container_i = container.insert(container_i, i);
    s21_container_i = s21_container.insert(s21_container_i, i);
  }
  container_i = container.begin();
  s21_container_i = s21_container.begin();
  size_t counter{0};
  for (; s21_container_i != s21_container.end();
       s21_container_i++, container_i++, ++counter) {
    EXPECT_EQ(*s21_container_i, *container_i);
  }
  EXPECT_EQ(s21_container.size(), counter);
  EXPECT_EQ(s21_container.size(), container.size());
}

TEST(ListIterator, Test3) {
  const uint64_t n{21};
  std::list<uint64_t> container;
  s21::list<uint64_t> s21_container;
  auto container_i{container.end()};
  auto s21_container_i{s21_container.end()};
  for (uint64_t i{0}; i != n; ++i) {
    container_i = container.insert(container_i, i);
    s21_container_i = s21_container.insert(s21_container_i, i);
  }
  container_i = container.begin();
  s21_container_i = s21_container.begin();
  for (uint64_t i{0}; i != n; ++i) {
    container_i = container.insert(container_i, i);
    s21_container_i = s21_container.insert(s21_container_i, i);
  }
  EXPECT_EQ(s21_container_i, s21_container.begin());
  container_i = container.begin();
  s21_container_i = s21_container.begin();
  for (uint64_t i{0}; i != n; ++i) {
    ++container_i;
    ++s21_container_i;
  }
  for (uint64_t i{0}; i != n; ++i) {
    container_i = container.insert(container_i, i);
    s21_container_i = s21_container.insert(s21_container_i, i);
  }
  container_i = container.begin();
  s21_container_i = s21_container.begin();
  size_t counter{0};
  for (; s21_container_i != s21_container.end();
       s21_container_i++, container_i++, ++counter) {
    EXPECT_EQ(*s21_container_i, *container_i);
  }
  EXPECT_EQ(s21_container.size(), counter);
  EXPECT_EQ(s21_container.size(), container.size());
}

TEST(ListIterator, Test4) {
  std::list<int> container;
  s21::list<int> s21_container;

  container.push_front(1);
  s21_container.push_front(1);

  container.push_back(2);
  s21_container.push_back(2);

  container.push_front(3);
  s21_container.push_front(3);

  container.insert(container.begin(), 4);
  s21_container.insert(s21_container.begin(), 4);

  container.insert(container.end(), 5);
  s21_container.insert(s21_container.end(), 5);

  auto it{container.begin()};
  it++;
  ++it;

  auto s21_it{s21_container.begin()};
  s21_it++;
  ++s21_it;

  container.insert(it, 6);
  s21_container.insert(s21_it, 6);

  container.push_back(7);
  s21_container.push_back(7);

  it = container.end();
  it--;
  --it;

  s21_it = s21_container.end();
  s21_it--;
  --s21_it;

  container.insert(it, 8);
  s21_container.insert(s21_it, 8);

  container.pop_front();
  s21_container.pop_front();

  container.pop_back();
  s21_container.pop_back();

  it = container.begin();
  s21_it = s21_container.begin();

  for (; s21_it != s21_container.end(); ++s21_it, ++it) {
    EXPECT_EQ(*it, *s21_it);
  }
  EXPECT_EQ(container.size(), s21_container.size());

  s21_it = s21_container.end();

  s21_container.clear();
  EXPECT_EQ(s21_container.empty(), true);
  EXPECT_EQ(s21_it, s21_container.end());
}

TEST(ListErase, Test1) {
  const uint8_t n{210};
  std::list<uint8_t> container;
  s21::list<uint8_t> s21_container;
  for (uint8_t i{10}; i != n; i += 10) {
    container.push_back(i);
    s21_container.push_back(i);
  }
  auto it{container.begin()};
  auto s21_it{s21_container.begin()};

  container.erase(it);
  s21_container.erase(s21_it);

  it = container.begin();
  s21_it = s21_container.begin();

  it++;
  it++;

  s21_it++;
  s21_it++;

  container.erase(it);
  s21_container.erase(s21_it);

  it = container.end();
  s21_it = s21_container.end();

  --it;
  --s21_it;

  container.erase(it);
  s21_container.erase(s21_it);

  it = container.begin();
  s21_it = s21_container.begin();

  for (; s21_it != s21_container.end(); ++s21_it, ++it) {
    EXPECT_EQ(*it, *s21_it);
  }

  EXPECT_EQ(container.size(), s21_container.size());

  while (!s21_container.empty()) {
    s21_container.erase(--s21_container.end());
    container.erase(--container.end());
  }

  EXPECT_EQ(s21_container.empty(), true);
}

TEST(ListErase, Test2) {
  const int n{101};
  std::list<int> container;
  s21::list<int> s21_container;
  for (int i{0}; i != n; ++i) {
    container.push_back(i);
    s21_container.push_back(i);
  }

  auto it{container.begin()};

  for (auto s21_it{s21_container.begin()}; s21_it != s21_container.end();) {
    if (*s21_it % 2 == 0) {
      s21_container.erase(s21_it++);
    } else {
      ++s21_it;
    }
    if (*it % 2 == 0) {
      container.erase(it++);
    } else {
      ++it;
    }
  }

  it = container.begin();
  for (auto s21_it{s21_container.begin()}; s21_it != s21_container.end();
       ++s21_it, ++it) {
    EXPECT_EQ(*s21_it, *it);
  }
  EXPECT_EQ(container.size(), s21_container.size());
}

TEST(ListReverse, Test1) {
  std::list<int> container;
  s21::list<int> s21_container;

  container.reverse();
  s21_container.reverse();

  auto it{container.begin()};
  auto s21_it{s21_container.begin()};
  for (; s21_it != s21_container.end(); ++s21_it, ++it) {
    EXPECT_EQ(*it, *s21_it);
  }
  EXPECT_EQ(container.size(), s21_container.size());
}

TEST(ListReverse, Test2) {
  const uint16_t n{1};
  std::list<uint16_t> container;
  s21::list<uint16_t> s21_container;
  for (uint16_t i{0}; i != n; ++i) {
    container.push_back(i);
    s21_container.push_back(i);
  }

  container.reverse();
  s21_container.reverse();

  auto it{container.begin()};
  auto s21_it{s21_container.begin()};
  for (; s21_it != s21_container.end(); ++s21_it, ++it) {
    EXPECT_EQ(*it, *s21_it);
  }
  EXPECT_EQ(container.size(), s21_container.size());
}

TEST(ListReverse, Test3) {
  const uint16_t n{10};
  std::list<uint16_t> container;
  s21::list<uint16_t> s21_container;
  for (uint16_t i{0}; i != n; ++i) {
    container.push_back(i);
    s21_container.push_back(i);
  }

  auto it_first{container.begin()};
  auto it_last{container.end().operator--()};
  auto s21_it_first{s21_container.begin()};
  auto s21_it_last{s21_container.end().operator--()};

  container.reverse();
  s21_container.reverse();

  auto it{container.begin()};
  auto s21_it{s21_container.begin()};
  for (; s21_it != s21_container.end(); ++s21_it, ++it) {
    EXPECT_EQ(*it, *s21_it);
  }
  it = container.end();
  s21_it = s21_container.end();
  do {
    EXPECT_EQ(*--it, *--s21_it);
  } while (s21_it != s21_container.begin());
  EXPECT_EQ(container.size(), s21_container.size());

  EXPECT_EQ(*s21_it_first, *it_first);
  EXPECT_EQ(*s21_it_last, *it_last);
  EXPECT_EQ(*s21_it_first, *s21_container.end().operator--());
  EXPECT_EQ(*s21_it_last, *s21_container.begin());
}

TEST(ListReverse, Test4) {
  const uint16_t n{21};
  std::list<uint16_t> container;
  s21::list<uint16_t> s21_container;
  for (uint16_t i{0}; i != n; ++i) {
    container.push_back(i);
    s21_container.push_back(i);
  }

  auto it_first{container.begin()};
  auto it_last{container.end().operator--()};
  auto s21_it_first{s21_container.begin()};
  auto s21_it_last{s21_container.end().operator--()};

  container.reverse();
  s21_container.reverse();

  auto it{container.begin()};
  auto s21_it{s21_container.begin()};
  for (; s21_it != s21_container.end(); ++s21_it, ++it) {
    EXPECT_EQ(*it, *s21_it);
  }
  it = container.end();
  s21_it = s21_container.end();
  do {
    EXPECT_EQ(*--it, *--s21_it);
  } while (s21_it != s21_container.begin());
  EXPECT_EQ(container.size(), s21_container.size());

  EXPECT_EQ(*s21_it_first, *it_first);
  EXPECT_EQ(*s21_it_last, *it_last);
  EXPECT_EQ(*s21_it_first, *s21_container.end().operator--());
  EXPECT_EQ(*s21_it_last, *s21_container.begin());
}

TEST(ListReverse, Test5) {
  std::srand(std::time(nullptr));
  std::list container{2611, 2511};
  s21::list s21_container{2611, 2511};

  auto it_first{container.begin()};
  auto it_last{container.end().operator--()};
  auto s21_it_first{s21_container.begin()};
  auto s21_it_last{s21_container.end().operator--()};

  container.reverse();
  s21_container.reverse();

  auto it{container.begin()};
  auto s21_it{s21_container.begin()};
  for (; s21_it != s21_container.end(); ++s21_it, ++it) {
    EXPECT_EQ(*it, *s21_it);
  }
  it = container.end();
  s21_it = s21_container.end();
  do {
    EXPECT_EQ(*--it, *--s21_it);
  } while (s21_it != s21_container.begin());
  EXPECT_EQ(container.size(), s21_container.size());

  EXPECT_EQ(*s21_it_first, *it_first);
  EXPECT_EQ(*s21_it_last, *it_last);
  EXPECT_EQ(*s21_it_first, *s21_container.end().operator--());
  EXPECT_EQ(*s21_it_last, *s21_container.begin());
}

TEST(ListReverse, Test6) {
  std::srand(std::time(nullptr));
  const int n{10'000'000};
  std::list container{13, 15, 11, 17, 19};
  s21::list s21_container{13, 15, 11, 17, 19};
  for (int i{}; i != n; ++i) {
    const int random_value{std::rand()};
    container.push_back(random_value);
    s21_container.push_back(random_value);
  }

  auto it_first{container.begin()};
  auto it_last{container.end().operator--()};
  auto s21_it_first{s21_container.begin()};
  auto s21_it_last{s21_container.end().operator--()};

  container.reverse();
  s21_container.reverse();

  auto it{container.begin()};
  auto s21_it{s21_container.begin()};
  for (; s21_it != s21_container.end(); ++s21_it, ++it) {
    EXPECT_EQ(*it, *s21_it);
  }
  it = container.end();
  s21_it = s21_container.end();
  do {
    EXPECT_EQ(*--it, *--s21_it);
  } while (s21_it != s21_container.begin());
  EXPECT_EQ(container.size(), s21_container.size());

  EXPECT_EQ(*s21_it_first, *it_first);
  EXPECT_EQ(*s21_it_last, *it_last);
  EXPECT_EQ(*s21_it_first, *s21_container.end().operator--());
  EXPECT_EQ(*s21_it_last, *s21_container.begin());
}

TEST(ListReverse, Test7) {
  std::list container{'a',  'b',  'c', 'd', '\t', '\v', '\r',
                      '\b', '\f', ' ', 'x', 'y',  'z'};
  s21::list s21_container{'a',  'b',  'c', 'd', '\t', '\v', '\r',
                          '\b', '\f', ' ', 'x', 'y',  'z'};

  auto it_first{container.begin()};
  auto it_last{container.end().operator--()};
  auto s21_it_first{s21_container.begin()};
  auto s21_it_last{s21_container.end().operator--()};

  container.reverse();
  s21_container.reverse();

  auto it{container.begin()};
  auto s21_it{s21_container.begin()};
  for (; s21_it != s21_container.end(); ++s21_it, ++it) {
    EXPECT_EQ(*it, *s21_it);
  }
  it = container.end();
  s21_it = s21_container.end();
  do {
    EXPECT_EQ(*--it, *--s21_it);
  } while (s21_it != s21_container.begin());
  EXPECT_EQ(container.size(), s21_container.size());

  EXPECT_EQ(*s21_it_first, *it_first);
  EXPECT_EQ(*s21_it_last, *it_last);
  EXPECT_EQ(*s21_it_first, *s21_container.end().operator--());
  EXPECT_EQ(*s21_it_last, *s21_container.begin());
}

TEST(ListSwap, Test1) {
  std::srand(std::time(nullptr));
  const int n{21};
  s21::list<int> s21_container_1;
  s21::list<int> s21_container_2;
  std::list<int> container;
  for (int i{0}; i != n; ++i) {
    const int random_value{std::rand()};
    container.push_back(random_value);
    s21_container_1.push_back(random_value);
  }

  auto it{container.begin()};
  auto s21_it{s21_container_1.begin()};
  auto s21_it_begin{s21_it};
  auto s21_it_end{s21_container_1.end()};

  s21_container_1.swap(s21_container_2);

  for (; s21_it != s21_container_2.end(); ++s21_it, ++it) {
    EXPECT_EQ(*it, *s21_it);
  }

  EXPECT_EQ(s21_it_begin, s21_container_2.begin());
  EXPECT_EQ(s21_it_end, s21_container_2.end());

  EXPECT_EQ(s21_container_1.empty(), true);
}

TEST(ListSwap, Test2) {
  std::srand(std::time(nullptr));
  const int n{21};
  s21::list<int> s21_container;
  std::list<int> container;
  for (int i{0}; i != n; ++i) {
    const int random_value{std::rand()};
    container.push_back(random_value);
    s21_container.push_back(random_value);
  }

  s21_container.swap(s21_container);

  auto it{container.begin()};
  auto s21_it{s21_container.begin()};
  for (; s21_it != s21_container.end(); ++s21_it, ++it) {
    EXPECT_EQ(*it, *s21_it);
  }

  EXPECT_EQ(s21_container.size(), container.size());
}

TEST(ListSplice, Test1) {
  std::srand(std::time(nullptr));
  const int n{1};
  s21::list<int> s21_container_1;
  s21::list<int> s21_container_2;
  std::list<int> container_1;
  std::list<int> container_2;
  for (int i{0}; i != n; ++i) {
    const int random_value{std::rand()};
    container_1.push_back(random_value);
    s21_container_1.push_back(random_value);
  }
  s21_container_2.splice(s21_container_2.begin(), s21_container_1);
  container_2.splice(container_2.begin(), container_1);

  EXPECT_EQ(s21_container_1.empty(), true);
  EXPECT_EQ(s21_container_2.size(), n);

  auto it{container_2.begin()};
  auto s21_it{s21_container_2.begin()};
  for (; s21_it != s21_container_2.end(); ++s21_it, ++it) {
    EXPECT_EQ(*it, *s21_it);
  }
}

TEST(ListSplice, Test2) {
  std::srand(std::time(nullptr));
  const int n{21};
  s21::list<int> s21_container_1;
  s21::list<int> s21_container_2;
  std::list<int> container_1;
  std::list<int> container_2;
  for (int i{0}; i != n; ++i) {
    const int random_value{std::rand()};
    container_1.push_back(random_value);
    s21_container_1.push_back(random_value);
  }
  s21_container_2.splice(s21_container_2.begin(), s21_container_1);
  container_2.splice(container_2.begin(), container_1);

  EXPECT_EQ(s21_container_1.empty(), true);
  EXPECT_EQ(s21_container_2.size(), n);

  auto it{container_2.begin()};
  auto s21_it{s21_container_2.begin()};
  for (; s21_it != s21_container_2.end(); ++s21_it, ++it) {
    EXPECT_EQ(*it, *s21_it);
  }
}

TEST(ListSplice, Test3) {
  std::srand(std::time(nullptr));
  const int n{21};
  s21::list<int> s21_container_1;
  s21::list<int> s21_container_2;
  std::list<int> container_1;
  std::list<int> container_2;
  for (int i{0}; i != n; ++i) {
    const int random_value{std::rand()};
    container_1.push_back(random_value);
    s21_container_1.push_back(random_value);
  }
  s21_container_2.splice(s21_container_2.end(), s21_container_1);
  container_2.splice(container_2.end(), container_1);

  EXPECT_EQ(s21_container_1.empty(), true);
  EXPECT_EQ(s21_container_2.size(), n);

  auto it{container_2.begin()};
  auto s21_it{s21_container_2.begin()};
  for (; s21_it != s21_container_2.end(); ++s21_it, ++it) {
    EXPECT_EQ(*it, *s21_it);
  }
}

TEST(ListSplice, Test4) {
  std::srand(std::time(nullptr));
  const int n{21};
  s21::list<int> s21_container_1;
  std::list<int> container_1;

  for (int i{0}; i != n; ++i) {
    const int random_value{std::rand()};
    container_1.push_back(random_value);
    s21_container_1.push_back(random_value);
  }

  s21::list<int> s21_container_2;
  std::list<int> container_2;
  for (int i{0}; i != n; ++i) {
    const int random_value{std::rand()};
    container_2.push_back(random_value);
    s21_container_2.push_back(random_value);
  }
  s21_container_2.splice(s21_container_2.end(), s21_container_1);
  container_2.splice(container_2.end(), container_1);

  EXPECT_EQ(s21_container_1.empty(), true);
  EXPECT_EQ(s21_container_2.size(), n * 2);

  auto it{container_2.begin()};
  auto s21_it{s21_container_2.begin()};
  for (; s21_it != s21_container_2.end(); ++s21_it, ++it) {
    EXPECT_EQ(*it, *s21_it);
  }
}

TEST(ListSplice, Test5) {
  std::srand(std::time(nullptr));
  const int n{21};
  s21::list<int> s21_container_1;
  std::list<int> container_1;

  for (int i{0}; i != n; ++i) {
    const int random_value{std::rand()};
    container_1.push_front(random_value);
    s21_container_1.push_front(random_value);
  }

  s21::list<int> s21_container_2;
  std::list<int> container_2;
  for (int i{0}; i != n; ++i) {
    const int random_value{std::rand()};
    container_2.push_back(random_value);
    s21_container_2.push_back(random_value);
  }
  s21_container_2.splice(s21_container_2.begin(), s21_container_1);
  container_2.splice(container_2.begin(), container_1);

  EXPECT_EQ(s21_container_1.empty(), true);
  EXPECT_EQ(s21_container_2.size(), n * 2);

  auto it{container_2.begin()};
  auto s21_it{s21_container_2.begin()};
  for (; s21_it != s21_container_2.end(); ++s21_it, ++it) {
    EXPECT_EQ(*it, *s21_it);
  }
}

TEST(ListSplice, Test6) {
  std::srand(std::time(nullptr));
  const int n{21};
  s21::list<int> s21_container_1;
  std::list<int> container_1;

  for (int i{0}; i != n; ++i) {
    const int random_value{std::rand()};
    container_1.push_front(random_value);
    s21_container_1.push_front(random_value);
  }

  s21::list<int> s21_container_2;
  std::list<int> container_2;
  for (int i{0}; i != n; ++i) {
    const int random_value{std::rand()};
    container_2.push_back(random_value);
    s21_container_2.push_back(random_value);
  }

  auto it{container_2.begin()};
  auto s21_it{s21_container_2.begin()};

  ++it;
  ++it;

  ++s21_it;
  ++s21_it;

  s21_container_2.splice(s21_it, s21_container_1);
  container_2.splice(it, container_1);

  EXPECT_EQ(s21_container_1.empty(), true);
  EXPECT_EQ(s21_container_2.size(), n * 2);

  it = container_2.begin();
  s21_it = s21_container_2.begin();
  for (; s21_it != s21_container_2.end(); ++s21_it, ++it) {
    EXPECT_EQ(*it, *s21_it);
  }
}

TEST(ListSplice, Test7) {
  std::srand(std::time(nullptr));
  const int n{1};
  s21::list<int> s21_container_1;
  std::list<int> container_1;

  for (int i{0}; i != n; ++i) {
    const int random_value{std::rand()};
    container_1.push_front(random_value);
    s21_container_1.push_front(random_value);
  }

  s21::list<int> s21_container_2;
  std::list<int> container_2;

  for (int i{0}; i != n; ++i) {
    const int random_value{std::rand()};
    container_2.push_front(random_value);
    s21_container_2.push_front(random_value);
  }

  const auto const_s21_it{s21_container_1.begin()};
  const auto const_it{container_1.begin()};

  s21_container_2.splice(s21_container_2.end(), s21_container_1);
  container_2.splice(container_2.end(), container_1);

  EXPECT_EQ(s21_container_1.empty(), true);
  EXPECT_EQ(s21_container_2.size(), n * 2);

  EXPECT_EQ(const_s21_it, s21_container_2.begin().operator++());
  EXPECT_EQ(const_it, container_2.begin().operator++());

  auto it{container_2.begin()};
  auto s21_it{s21_container_2.begin()};
  for (; s21_it != s21_container_2.end(); ++s21_it, ++it) {
    EXPECT_EQ(*it, *s21_it);
  }
}

TEST(ListSplice, Test8) {
  std::srand(std::time(nullptr));
  const int n{5};
  s21::list<int> s21_container_1;
  std::list<int> container_1;

  for (int i{0}; i != n; ++i) {
    const int random_value{std::rand()};
    container_1.push_front(random_value);
    s21_container_1.push_front(random_value);
  }

  s21::list<int> s21_container_2;
  std::list<int> container_2;

  s21_container_2.splice(s21_container_2.begin(), s21_container_1);
  container_2.splice(container_2.begin(), container_1);

  EXPECT_EQ(s21_container_1.empty(), true);
  EXPECT_EQ(s21_container_2.size(), n);

  auto it{container_2.begin()};
  auto s21_it{s21_container_2.begin()};
  for (; s21_it != s21_container_2.end(); ++s21_it, ++it) {
    EXPECT_EQ(*it, *s21_it);
  }
}

TEST(ListSplice, Test9) {
  std::srand(std::time(nullptr));
  const int n{5};
  s21::list<int> s21_container_1;
  std::list<int> container_1;

  for (int i{0}; i != n; ++i) {
    const int random_value{std::rand()};
    container_1.push_front(random_value);
    s21_container_1.push_front(random_value);
  }

  s21::list<int> s21_container_2;
  std::list<int> container_2;

  EXPECT_EQ(s21_container_2.empty(), true);

  s21_container_1.splice(s21_container_1.end(), s21_container_2);
  container_1.splice(container_1.end(), container_2);

  EXPECT_EQ(s21_container_1.size(), n);

  auto it{container_1.begin()};
  auto s21_it{s21_container_1.begin()};
  for (; s21_it != s21_container_1.end(); ++s21_it, ++it) {
    EXPECT_EQ(*it, *s21_it);
  }
}

TEST(ListSplice, Test10) {
  std::srand(std::time(nullptr));
  const int n{21};
  s21::list<int> s21_container_1;
  std::list<int> container_1;

  for (int i{0}; i != n; ++i) {
    const int random_value{std::rand()};
    container_1.push_front(random_value);
    s21_container_1.push_front(random_value);
  }

  s21::list<int> s21_container_2;
  std::list<int> container_2;
  for (int i{0}; i != n; ++i) {
    const int random_value{std::rand()};
    container_2.push_back(random_value);
    s21_container_2.push_back(random_value);
  }

  const s21::list<int>& ref_s21_container_2{s21_container_2};
  const std::list<int>& ref_container_2{container_2};

  auto s21_it{ref_s21_container_2.begin()};
  auto it{ref_container_2.begin()};

  std::advance(it, 2);
  std::advance(s21_it, 2);

  s21_it++;
  s21_it--;

  s21_container_2.splice(s21_it, s21_container_1);
  container_2.splice(it, container_1);

  EXPECT_EQ(s21_container_1.empty(), true);
  EXPECT_EQ(s21_container_2.size(), n * 2);

  s21_it = ref_s21_container_2.end();
  it = ref_container_2.end();
  do {
    EXPECT_EQ(*--it, *--s21_it);
  } while (s21_it != ref_s21_container_2.begin());
}

TEST(ListSplice, Test11) {
  std::list container_out{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  auto it{container_out.begin()};
  std::advance(it, 3);
  std::list<int> container_in;
  container_in.splice(container_in.begin(), container_out, it,
                      container_out.end());

  s21::list s21_container_out{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  auto s21_it{s21_container_out.begin()};
  std::advance(s21_it, 3);
  s21::list<int> s21_container_in;
  s21_container_in.splice(s21_container_in.begin(), s21_container_out, s21_it,
                          s21_container_out.end());

  s21_it = s21_container_in.begin();
  it = container_in.begin();
  for (; s21_it != s21_container_in.end(); ++s21_it, ++it) {
    EXPECT_EQ(*it, *s21_it);
  }

  s21_it = s21_container_out.begin();
  it = container_out.begin();
  for (; s21_it != s21_container_out.end(); ++s21_it, ++it) {
    EXPECT_EQ(*it, *s21_it);
  }
}

TEST(ListSplice, Test12) {
  std::list container_out{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  auto it_begin{container_out.begin()};
  auto it_end{container_out.end()};
  std::advance(it_begin, 3);
  std::advance(it_end, -3);
  std::list<int> container_in;
  container_in.splice(container_in.begin(), container_out, it_begin, it_end);

  s21::list s21_container_out{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  auto s21_it_begin{s21_container_out.begin()};
  auto s21_it_end{s21_container_out.end()};
  std::advance(s21_it_begin, 3);
  std::advance(s21_it_end, -3);
  s21::list<int> s21_container_in;
  s21_container_in.splice(s21_container_in.begin(), s21_container_out,
                          s21_it_begin, s21_it_end);

  s21_it_begin = s21_container_in.begin();
  it_begin = container_in.begin();
  for (; s21_it_begin != s21_container_in.end(); ++s21_it_begin, ++it_begin) {
    EXPECT_EQ(*it_begin, *s21_it_begin);
  }

  s21_it_begin = s21_container_out.begin();
  it_begin = container_out.begin();
  for (; s21_it_begin != s21_container_out.end(); ++s21_it_begin, ++it_begin) {
    EXPECT_EQ(*it_begin, *s21_it_begin);
  }
}

TEST(ListSplice, Test13) {
  std::list container_out{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  auto it_begin{container_out.begin()};
  std::advance(it_begin, 3);
  std::list<int> container_in;
  container_in.splice(container_in.begin(), container_out, it_begin, it_begin);

  s21::list s21_container_out{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  auto s21_it_begin{s21_container_out.begin()};
  std::advance(s21_it_begin, 3);
  s21::list<int> s21_container_in;
  s21_container_in.splice(s21_container_in.begin(), s21_container_out,
                          s21_it_begin, s21_it_begin);

  EXPECT_EQ(s21_container_in.empty(), true);

  s21_it_begin = s21_container_out.begin();
  it_begin = container_out.begin();
  for (; s21_it_begin != s21_container_out.end(); ++s21_it_begin, ++it_begin) {
    EXPECT_EQ(*it_begin, *s21_it_begin);
  }
}

TEST(ListSplice, Test14) {
  std::list container_out{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  auto it_begin{container_out.begin()};
  std::list<int> container_in;
  container_in.splice(container_in.begin(), container_out, it_begin,
                      container_out.end());

  s21::list s21_container_out{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  auto s21_it_begin{s21_container_out.begin()};
  s21::list<int> s21_container_in;
  s21_container_in.splice(s21_container_in.begin(), s21_container_out,
                          s21_it_begin, s21_container_out.end());

  s21_it_begin = s21_container_in.begin();
  it_begin = container_in.begin();
  for (; s21_it_begin != s21_container_in.end(); ++s21_it_begin, ++it_begin) {
    EXPECT_EQ(*it_begin, *s21_it_begin);
  }

  EXPECT_EQ(s21_container_out.empty(), true);
  EXPECT_EQ(s21_container_out.size(), container_out.size());
}

TEST(ListSplice, Test15) {
  std::list<int> container_out;
  auto it_begin{container_out.begin()};
  std::list<int> container_in;
  container_in.splice(container_in.begin(), container_out, it_begin,
                      container_out.end());

  s21::list<int> s21_container_out;
  auto s21_it_begin{s21_container_out.begin()};
  s21::list<int> s21_container_in;
  s21_container_in.splice(s21_container_in.begin(), s21_container_out,
                          s21_it_begin, s21_container_out.end());

  EXPECT_EQ(s21_container_in.empty(), true);
  EXPECT_EQ(s21_container_in.size(), container_in.size());
  EXPECT_EQ(s21_container_out.empty(), true);
  EXPECT_EQ(s21_container_out.size(), container_out.size());
}

TEST(ListSplice, Test16) {
  std::list container_out{1, 2, 3, 5, 8, 4, 4, 9, 4, 4, 7, 2, 0, 3};
  auto it_begin{container_out.begin()};
  auto it_end{container_out.end()};
  std::advance(it_end, -5);
  std::list container_in{1, 4, 6, 7, 7, 8, 3, 3, 3, 6, 7,
                         2, 2, 5, 6, 5, 3, 2, 1, 2, 5, 3};
  auto it_in_begin{container_in.begin()};
  std::advance(it_in_begin, 4);
  container_in.splice(it_in_begin, container_out, it_begin, it_end);

  s21::list s21_container_out{1, 2, 3, 5, 8, 4, 4, 9, 4, 4, 7, 2, 0, 3};
  auto s21_it_begin{s21_container_out.begin()};
  auto s21_it_end{s21_container_out.end()};
  std::advance(s21_it_end, -5);
  s21::list s21_container_in{1, 4, 6, 7, 7, 8, 3, 3, 3, 6, 7,
                             2, 2, 5, 6, 5, 3, 2, 1, 2, 5, 3};
  auto s21_it_in_begin{s21_container_in.begin()};
  std::advance(s21_it_in_begin, 4);
  s21_container_in.splice(s21_it_in_begin, s21_container_out, s21_it_begin,
                          s21_it_end);

  s21_it_begin = s21_container_in.begin();
  it_begin = container_in.begin();
  for (; s21_it_begin != s21_container_in.end(); ++s21_it_begin, ++it_begin) {
    EXPECT_EQ(*it_begin, *s21_it_begin);
  }

  s21_it_begin = s21_container_out.begin();
  it_begin = container_out.begin();
  for (; s21_it_begin != s21_container_out.end(); ++s21_it_begin, ++it_begin) {
    EXPECT_EQ(*it_begin, *s21_it_begin);
  }
}

TEST(ListSplice, Test17) {
  std::srand(std::time(nullptr));
  const size_t n{100'000};
  std::list<int> container;
  s21::list<int> s21_container;
  for (size_t i{0}; i != n; ++i) {
    const int random_value{std::rand()};
    container.push_back(random_value);
    s21_container.push_back(random_value);
  }

  std::list<int> container_out;
  s21::list<int> s21_container_out;

  container_out.splice(container_out.begin(), container);
  s21_container_out.splice(s21_container_out.begin(), s21_container);

  EXPECT_EQ(s21_container.empty(), true);

  auto it{container_out.begin()};
  auto s21_it{s21_container_out.begin()};
  for (; s21_it != s21_container_out.end(); ++s21_it, ++it) {
    EXPECT_EQ(*s21_it, *it);
  }
  EXPECT_EQ(s21_container_out.size(), container_out.size());
  EXPECT_EQ(container_out.size(), n);
}

TEST(ListUnique, Test1) {
  std::srand(std::time(nullptr));
  const int n{21};
  s21::list<int> s21_container;
  std::list<int> container;

  for (int i{0}; i != n; ++i) {
    const int random_value{std::rand() % 2};
    container.push_front(random_value);
    s21_container.push_front(random_value);
  }

  container.unique();
  s21_container.unique();

  EXPECT_EQ(s21_container.size(), container.size());

  auto it{container.begin()};
  auto s21_it{s21_container.begin()};
  for (; s21_it != s21_container.end(); ++s21_it, ++it) {
    EXPECT_EQ(*it, *s21_it);
  }
}

TEST(ListUnique, Test2) {
  const int n{21};
  s21::list<std::string> s21_container(n);
  std::list<std::string> container(n);

  container.unique();
  s21_container.unique();

  EXPECT_EQ(s21_container.size(), container.size());

  auto it{container.begin()};
  auto s21_it{s21_container.begin()};
  for (; s21_it != s21_container.end(); ++s21_it, ++it) {
    EXPECT_EQ(*it, *s21_it);
  }
}

TEST(ListUnique, Test3) {
  s21::list<std::string> s21_container;
  std::list<std::string> container;

  container.unique();
  s21_container.unique();

  EXPECT_EQ(s21_container.size(), container.size());
  EXPECT_EQ(s21_container.empty(), true);
}

TEST(ListUnique, Test4) {
  s21::list<const char*> s21_container;
  std::list<const char*> container;

  container.unique();
  s21_container.unique();

  EXPECT_EQ(s21_container.size(), container.size());
  EXPECT_EQ(s21_container.empty(), true);
}

TEST(ListUnique, Test5) {
  std::srand(std::time(nullptr));
  const char* array[]{"aaa", "aa", "a", "bbb", "bb", "b"};
  const int n{100};
  s21::list<const char*> s21_container;
  std::list<const char*> container;

  for (int i{0}; i != n; ++i) {
    const char* ptr{array[std::rand() % std::size(array)]};
    container.push_front(ptr);
    s21_container.push_front(ptr);
  }

  container.unique();
  s21_container.unique();

  EXPECT_EQ(s21_container.size(), container.size());

  auto it{container.begin()};
  auto s21_it{s21_container.begin()};
  for (; s21_it != s21_container.end(); ++s21_it, ++it) {
    EXPECT_EQ(*it, *s21_it);
  }
}

TEST(ListUnique, Test6) {
  const time_t current_time{std::time(nullptr)};
  const tm* date{std::localtime(&current_time)};
  const int n{21};
  s21::list<const tm*> s21_container;
  std::list<const tm*> container;

  for (int i{0}; i != n; ++i) {
    container.push_front(date);
    s21_container.push_front(date);
  }

  container.unique();
  s21_container.unique();

  EXPECT_EQ(s21_container.size(), 1);

  auto it{container.begin()};
  auto s21_it{s21_container.begin()};
  for (; s21_it != s21_container.end(); ++s21_it, ++it) {
    EXPECT_EQ(*it, *s21_it);
  }
}

TEST(ListClear, Test1) {
  s21::list<int> s21_container;
  s21_container.clear();
  EXPECT_EQ(s21_container.empty(), true);
  EXPECT_EQ(s21_container.begin(), s21_container.end());
}

TEST(ListMerge, Test1) {
  std::list container_1{1, 22, 5, 6, 3, 5, 8, 2, 5, 8, 2, 2, 35};
  s21::list s21_container_1{1, 22, 5, 6, 3, 5, 8, 2, 5, 8, 2, 2, 35};

  std::list container_2{41, 2, 4, 7, 21, 2, 3, 5, 8, 3, 4, 7};
  s21::list s21_container_2{41, 2, 4, 7, 21, 2, 3, 5, 8, 3, 4, 7};

  container_1.merge(container_2);
  s21_container_1.merge(s21_container_2);

  EXPECT_EQ(s21_container_2.empty(), true);
  EXPECT_EQ(s21_container_1.size(), container_1.size());

  auto s21_it{s21_container_1.begin()};
  for (auto it{container_1.begin()}; s21_it != s21_container_1.end();
       ++s21_it, ++it) {
    EXPECT_EQ(*it, *s21_it);
  }
}

TEST(ListMerge, Test2) {
  std::list container_1{41, 2, 4, 7, 21, 2, 3, 5, 8, 3, 4, 7};
  s21::list s21_container_1{41, 2, 4, 7, 21, 2, 3, 5, 8, 3, 4, 7};

  std::list container_2{1, 22, 5, 6, 3, 5, 8, 2, 5, 8, 2, 2, 35};
  s21::list s21_container_2{1, 22, 5, 6, 3, 5, 8, 2, 5, 8, 2, 2, 35};

  container_1.merge(container_2);
  s21_container_1.merge(s21_container_2);

  EXPECT_EQ(s21_container_2.empty(), true);
  EXPECT_EQ(s21_container_1.size(), container_1.size());

  auto s21_it{s21_container_1.begin()};
  for (auto it{container_1.begin()}; s21_it != s21_container_1.end();
       ++s21_it, ++it) {
    EXPECT_EQ(*it, *s21_it);
  }
}

TEST(ListMerge, Test3) {
  std::list container_1{1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21};
  s21::list s21_container_1{1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21};

  std::list container_2{0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22};
  s21::list s21_container_2{0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22};

  container_1.merge(container_2);
  s21_container_1.merge(s21_container_2);

  EXPECT_EQ(s21_container_2.empty(), true);
  EXPECT_EQ(s21_container_1.size(), container_1.size());

  auto s21_it{s21_container_1.begin()};
  for (auto it{container_1.begin()}; s21_it != s21_container_1.end();
       ++s21_it, ++it) {
    EXPECT_EQ(*it, *s21_it);
  }
}

TEST(ListMerge, Test4) {
  std::list container_1{1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21};
  s21::list s21_container_1{1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21};

  std::list<int> container_2;
  s21::list<int> s21_container_2;

  container_1.merge(container_2);
  s21_container_1.merge(s21_container_2);

  EXPECT_EQ(s21_container_2.empty(), true);
  EXPECT_EQ(s21_container_1.size(), container_1.size());

  auto s21_it{s21_container_1.begin()};
  for (auto it{container_1.begin()}; s21_it != s21_container_1.end();
       ++s21_it, ++it) {
    EXPECT_EQ(*it, *s21_it);
  }
}

TEST(ListMerge, Test5) {
  std::list container_1{1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21};
  s21::list s21_container_1{1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21};

  container_1.merge(container_1);
  s21_container_1.merge(s21_container_1);

  EXPECT_EQ(s21_container_1.size(), container_1.size());

  auto s21_it{s21_container_1.begin()};
  for (auto it{container_1.begin()}; s21_it != s21_container_1.end();
       ++s21_it, ++it) {
    EXPECT_EQ(*it, *s21_it);
  }
}

TEST(ListMerge, Test6) {
  std::list container_1{1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21};
  s21::list s21_container_1{1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21};

  container_1.merge(container_1);
  s21_container_1.merge(s21_container_1);

  EXPECT_EQ(s21_container_1.size(), container_1.size());

  auto s21_it{s21_container_1.begin()};
  for (auto it{container_1.begin()}; s21_it != s21_container_1.end();
       ++s21_it, ++it) {
    EXPECT_EQ(*it, *s21_it);
  }
}

TEST(ListMerge, Test7) {
  std::list<int> container_1;
  s21::list<int> s21_container_1;

  std::list container_2{1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21};
  s21::list s21_container_2{1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21};

  container_1.merge(container_2);
  s21_container_1.merge(s21_container_2);

  EXPECT_EQ(s21_container_2.empty(), true);
  EXPECT_EQ(s21_container_1.size(), container_1.size());

  auto s21_it{s21_container_1.begin()};
  for (auto it{container_1.begin()}; s21_it != s21_container_1.end();
       ++s21_it, ++it) {
    EXPECT_EQ(*it, *s21_it);
  }
}

TEST(ListMerge, Test8) {
  std::list<int> container_1;
  s21::list<int> s21_container_1;

  std::list<int> container_2;
  s21::list<int> s21_container_2;

  container_1.merge(container_2);
  s21_container_1.merge(s21_container_2);

  EXPECT_EQ(s21_container_1.empty(), true);
  EXPECT_EQ(s21_container_1.size(), container_1.size());
  EXPECT_EQ(s21_container_2.empty(), true);
  EXPECT_EQ(s21_container_2.size(), container_2.size());
}

TEST(ListMerge, Test9) {
  std::list container_1{"back", "bait", "cat", "cow", "crow"};
  s21::list s21_container_1{"back", "bait", "cat", "cow", "crow"};

  std::list container_2{"ball", "cake", "car", "carrot", "cat", "clock"};
  s21::list s21_container_2{"ball", "cake", "car", "carrot", "cat", "clock"};

  container_1.merge(container_2);
  s21_container_1.merge(s21_container_2);

  EXPECT_EQ(s21_container_2.empty(), true);
  EXPECT_EQ(s21_container_1.size(), container_1.size());

  auto s21_it{s21_container_1.begin()};
  for (auto it{container_1.begin()}; s21_it != s21_container_1.end();
       ++s21_it, ++it) {
    EXPECT_EQ(*it, *s21_it);
  }
}

TEST(ListMerge, Test10) {
  std::list container_1{"cat", "bait", "back", "cow", "crow"};
  s21::list s21_container_1{"cat", "bait", "back", "cow", "crow"};

  std::list container_2{"ball", "cat", "carrot", "car", "clock", "cake"};
  s21::list s21_container_2{"ball", "cat", "carrot", "car", "clock", "cake"};

  container_1.merge(container_2);
  s21_container_1.merge(s21_container_2);

  EXPECT_EQ(s21_container_2.empty(), true);
  EXPECT_EQ(s21_container_1.size(), container_1.size());

  auto s21_it{s21_container_1.begin()};
  for (auto it{container_1.begin()}; s21_it != s21_container_1.end();
       ++s21_it, ++it) {
    EXPECT_EQ(*it, *s21_it);
  }
}

TEST(ListMerge, Test11) {
  std::list container_1{1, 2, 3, 4, 5, 6, 7};
  s21::list s21_container_1{1, 2, 3, 4, 5, 6, 7};

  std::list container_2{11, 12, 13, 14, 15, 16, 17};
  s21::list s21_container_2{11, 12, 13, 14, 15, 16, 17};

  container_1.merge(container_2);
  s21_container_1.merge(s21_container_2);

  EXPECT_EQ(s21_container_2.empty(), true);
  EXPECT_EQ(s21_container_1.size(), container_1.size());

  auto s21_it{s21_container_1.begin()};
  for (auto it{container_1.begin()}; s21_it != s21_container_1.end();
       ++s21_it, ++it) {
    EXPECT_EQ(*it, *s21_it);
  }
}

TEST(ListMerge, Test12) {
  std::list container_1{11, 12, 13, 14, 15, 16, 17};
  s21::list s21_container_1{11, 12, 13, 14, 15, 16, 17};

  std::list container_2{1, 2, 3, 4, 5, 6, 7};
  s21::list s21_container_2{1, 2, 3, 4, 5, 6, 7};

  container_1.merge(container_2);
  s21_container_1.merge(s21_container_2);

  EXPECT_EQ(s21_container_2.empty(), true);
  EXPECT_EQ(s21_container_1.size(), container_1.size());

  auto s21_it{s21_container_1.begin()};
  for (auto it{container_1.begin()}; s21_it != s21_container_1.end();
       ++s21_it, ++it) {
    EXPECT_EQ(*it, *s21_it);
  }
}

TEST(ListMerge, Test13) {
  std::list container_1{1, 21};
  s21::list s21_container_1{1, 21};

  std::list container_2{1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11,
                        12, 13, 14, 15, 16, 17, 18, 19, 20, 21};
  s21::list s21_container_2{1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11,
                            12, 13, 14, 15, 16, 17, 18, 19, 20, 21};

  container_1.merge(container_2);
  s21_container_1.merge(s21_container_2);

  EXPECT_EQ(s21_container_2.empty(), true);
  EXPECT_EQ(s21_container_1.size(), container_1.size());

  auto s21_it{s21_container_1.begin()};
  for (auto it{container_1.begin()}; s21_it != s21_container_1.end();
       ++s21_it, ++it) {
    EXPECT_EQ(*it, *s21_it);
  }
}

TEST(ListMerge, Test14) {
  std::list container_1{1, 2, 3, 4, 5, 6, 7};
  s21::list s21_container_1{1, 2, 3, 4, 5, 6, 7};

  std::list container_2{-1};
  s21::list s21_container_2{-1};

  container_1.merge(container_2);
  s21_container_1.merge(s21_container_2);

  EXPECT_EQ(s21_container_2.empty(), true);
  EXPECT_EQ(s21_container_1.size(), container_1.size());

  auto s21_it{s21_container_1.begin()};
  for (auto it{container_1.begin()}; s21_it != s21_container_1.end();
       ++s21_it, ++it) {
    EXPECT_EQ(*it, *s21_it);
  }
}

TEST(ListMerge, Test15) {
  std::list container_1{1, 2, 3, 4, 5, 6, 7};
  s21::list s21_container_1{1, 2, 3, 4, 5, 6, 7};

  std::list container_2{10};
  s21::list s21_container_2{10};

  container_1.merge(container_2);
  s21_container_1.merge(s21_container_2);

  EXPECT_EQ(s21_container_2.empty(), true);
  EXPECT_EQ(s21_container_1.size(), container_1.size());

  auto s21_it{s21_container_1.begin()};
  for (auto it{container_1.begin()}; s21_it != s21_container_1.end();
       ++s21_it, ++it) {
    EXPECT_EQ(*it, *s21_it);
  }
}

TEST(ListMerge, Test16) {
  std::srand(std::time(nullptr));
  const int n{1'000'000};
  std::list<int> container_1;
  s21::list<int> s21_container_1;
  for (int i{0}; i != n; ++i) {
    const int random_value{std::rand()};
    container_1.push_back(random_value);
    s21_container_1.push_back(random_value);
  }

  std::list<int> container_2;
  s21::list<int> s21_container_2;
  for (int i{0}; i != n; ++i) {
    const int random_value{std::rand()};
    container_1.push_back(random_value);
    s21_container_1.push_back(random_value);
  }

  container_1.merge(container_2);
  s21_container_1.merge(s21_container_2);

  EXPECT_EQ(s21_container_2.empty(), true);
  EXPECT_EQ(s21_container_1.size(), container_1.size());

  auto s21_it{s21_container_1.begin()};
  for (auto it{container_1.begin()}; s21_it != s21_container_1.end();
       ++s21_it, ++it) {
    EXPECT_EQ(*it, *s21_it);
  }
}

TEST(ListMerge, Test17) {
  std::srand(std::time(nullptr));
  const int n{500'000};
  std::list<int> container_1;
  std::list<int> container_2;
  s21::list<int> s21_container_1;
  s21::list<int> s21_container_2;
  for (int i{0}; i != n; ++i) {
    container_1.push_back(i);
    s21_container_1.push_back(i);
    container_2.push_back(i);
    s21_container_2.push_back(i);
  }

  container_1.merge(container_2);
  s21_container_1.merge(s21_container_2);

  EXPECT_EQ(s21_container_2.empty(), true);
  EXPECT_EQ(s21_container_1.size(), container_1.size());

  auto s21_it{s21_container_1.begin()};
  for (auto it{container_1.begin()}; s21_it != s21_container_1.end();
       ++s21_it, ++it) {
    EXPECT_EQ(*it, *s21_it);
  }
}

TEST(ListMerge, Test18) {
  const Dummy kArr_1[]{{1, 8, 1, 1992},   {2, 1, 1, 2000},   {3, 1, 1, 2000},
                       {4, 24, 2, 2022},  {5, 1, 1, 2023},   {6, 23, 10, 2023},
                       {7, 22, 10, 2024}, {8, 22, 10, 2024}, {9, 23, 10, 2024},
                       {10, 1, 12, 2024}};
  const Dummy kArr_2[]{{11, 8, 1, 1992},   {12, 1, 1, 2000},
                       {13, 1, 1, 2000},   {14, 24, 2, 2022},
                       {15, 1, 1, 2023},   {16, 23, 10, 2023},
                       {17, 22, 10, 2024}, {18, 22, 10, 2024},
                       {19, 23, 10, 2024}, {20, 1, 12, 2024}};
  std::list<Dummy> container_1;
  std::list<Dummy> container_2;
  s21::list<Dummy> s21_container_1;
  s21::list<Dummy> s21_container_2;
  for (size_t i{0}; i != std::size(kArr_1); ++i) {
    container_1.push_back(kArr_1[i]);
    s21_container_1.push_back(kArr_1[i]);
    container_2.push_back(kArr_2[i]);
    s21_container_2.push_back(kArr_2[i]);
  }

  container_1.merge(container_2);
  s21_container_1.merge(s21_container_2);

  EXPECT_EQ(s21_container_2.empty(), true);
  EXPECT_EQ(s21_container_1.size(), container_1.size());

  auto s21_it{s21_container_1.begin()};
  for (auto it{container_1.begin()}; s21_it != s21_container_1.end();
       ++s21_it, ++it) {
    EXPECT_EQ(*it, *s21_it);
  }
}

TEST(ListSort, Test1) {
  std::srand(std::time(nullptr));
  const int n{1};
  std::list<int> container;
  s21::list<int> s21_container;
  for (int i{0}; i != n; ++i) {
    const int random_value{std::rand()};
    container.push_back(random_value);
    s21_container.push_back(random_value);
  }

  container.sort();
  s21_container.sort();

  auto it{container.begin()};
  auto s21_it{s21_container.begin()};
  for (; s21_it != s21_container.end(); ++s21_it, ++it) {
    EXPECT_EQ(*s21_it, *it);
  }
  EXPECT_EQ(s21_container.size(), container.size());
}

TEST(ListSort, Test2) {
  std::srand(std::time(nullptr));
  const int n{2};
  std::list<int> container;
  s21::list<int> s21_container;
  for (int i{0}; i != n; ++i) {
    const int random_value{std::rand()};
    container.push_back(random_value);
    s21_container.push_back(random_value);
  }

  container.sort();
  s21_container.sort();

  auto it{container.begin()};
  auto s21_it{s21_container.begin()};
  for (; s21_it != s21_container.end(); ++s21_it, ++it) {
    EXPECT_EQ(*s21_it, *it);
  }
  EXPECT_EQ(s21_container.size(), container.size());
}

TEST(ListSort, Test3) {
  std::list container{5, 4, 2, 3, 1, 6};
  s21::list s21_container{5, 4, 2, 3, 1, 6};

  const s21::list<int>& s21_ref{s21_container};
  auto s21_num_pos_1{s21_ref.begin()};
  auto s21_num_pos_3{s21_num_pos_1};
  auto s21_num_pos_5{s21_num_pos_1};
  std::advance(s21_num_pos_1, 4);
  std::advance(s21_num_pos_3, 3);

  const std::list<int>& ref{container};
  auto num_pos_1{ref.begin()};
  auto num_pos_3{num_pos_1};
  auto num_pos_5{num_pos_1};
  std::advance(num_pos_1, 4);
  std::advance(num_pos_3, 3);

  container.sort();
  s21_container.sort();

  auto it{container.begin()};
  auto s21_it{s21_container.begin()};
  for (; s21_it != s21_container.end(); ++s21_it, ++it) {
    EXPECT_EQ(*s21_it, *it);
  }
  EXPECT_EQ(s21_container.size(), container.size());

  EXPECT_EQ(*++s21_num_pos_1, *++num_pos_1);
  EXPECT_EQ(*s21_num_pos_1, 2);
  EXPECT_EQ(*++s21_num_pos_3, *++num_pos_3);
  EXPECT_EQ(*s21_num_pos_3, 4);
  EXPECT_EQ(*++s21_num_pos_5, *++num_pos_5);
  EXPECT_EQ(*s21_num_pos_5, 6);
}

TEST(ListSort, Test4) {
  std::srand(std::time(nullptr));
  std::list<int> container;
  s21::list<int> s21_container;
  const int n{100};
  for (int i{1}; i <= n; ++i) {
    for (int j{0}; j != i; ++j) {
      const int random_value{std::rand()};
      container.push_back(random_value);
      s21_container.push_back(random_value);
    }

    container.sort();
    s21_container.sort();

    auto it{container.begin()};
    auto s21_it{s21_container.begin()};
    for (; s21_it != s21_container.end(); ++s21_it, ++it) {
      EXPECT_EQ(*s21_it, *it);
    }

    it = container.end();
    s21_it = s21_container.end();
    do {
      EXPECT_EQ(*--s21_it, *--it);
    } while (s21_it != s21_container.begin());

    EXPECT_EQ(s21_container.size(), container.size());
    container.clear();
    s21_container.clear();
    EXPECT_EQ(s21_container.empty(), container.empty());
  }
}

TEST(ListSort, Test5) {
  std::srand(std::time(nullptr));
  const int n{1'000};
  std::list<int> container;
  s21::list<int> s21_container;
  for (int i{0}; i != n; ++i) {
    const int random_value{std::rand()};
    container.push_back(random_value);
    s21_container.push_back(random_value);
  }

  container.sort();
  s21_container.sort();

  auto it{container.begin()};
  auto s21_it{s21_container.begin()};
  for (; s21_it != s21_container.end(); ++s21_it, ++it) {
    EXPECT_EQ(*s21_it, *it);
  }
  EXPECT_EQ(s21_container.size(), container.size());
}

TEST(ListSort, Test6) {
  std::srand(std::time(nullptr));
  const int n{10'000};
  std::list<int> container;
  s21::list<int> s21_container;
  for (int i{0}; i != n; ++i) {
    const int random_value{std::rand()};
    container.push_back(random_value);
    s21_container.push_back(random_value);
  }

  container.sort();
  s21_container.sort();

  auto it{container.begin()};
  auto s21_it{s21_container.begin()};
  for (; s21_it != s21_container.end(); ++s21_it, ++it) {
    EXPECT_EQ(*s21_it, *it);
  }
  EXPECT_EQ(s21_container.size(), container.size());
}

TEST(ListSort, Test7) {
  std::srand(std::time(nullptr));
  const int n{1'000'000};
  std::list<int> container;
  s21::list<int> s21_container;
  for (int i{0}; i != n; ++i) {
    const int random_value{std::rand()};
    container.push_back(random_value);
    s21_container.push_back(random_value);
  }

  container.sort();
  s21_container.sort();

  auto it{container.begin()};
  auto s21_it{s21_container.begin()};
  for (; s21_it != s21_container.end(); ++s21_it, ++it) {
    EXPECT_EQ(*s21_it, *it);
  }
  EXPECT_EQ(s21_container.size(), container.size());
}

TEST(ListSort, Test8) {
  std::srand(std::time(nullptr));
  const int n{1'000};
  std::list<int> container;
  s21::list<int> s21_container;
  for (int i{0}; i != n; ++i) {
    const int random_value{std::rand() % 100};
    container.push_back(random_value);
    s21_container.push_back(random_value);
  }

  container.sort();
  container.unique();
  s21_container.sort();
  s21_container.unique();

  auto it{container.begin()};
  auto s21_it{s21_container.begin()};
  for (; s21_it != s21_container.end(); ++s21_it, ++it) {
    EXPECT_EQ(*s21_it, *it);
  }
  EXPECT_EQ(s21_container.size(), container.size());
}

TEST(ListSort, Test9) {
  const Dummy kArr[]{{0, 22, 10, 2024}, {1, 22, 10, 2024},  {3, 23, 10, 2024},
                     {4, 1, 12, 2024},  {5, 23, 10, 2023},  {6, 1, 1, 2023},
                     {7, 24, 2, 2022},  {8, 1, 1, 2000},    {9, 8, 1, 1992},
                     {10, 1, 1, 2000},  {11, 23, 10, 2024}, {12, 1, 1, 2000}};
  std::list<Dummy> container;
  s21::list<Dummy> s21_container;

  for (const auto& i : kArr) {
    container.push_back(i);
    s21_container.push_back(i);
  }

  container.sort();
  s21_container.sort();

  auto it{container.begin()};
  auto s21_it{s21_container.begin()};
  for (; s21_it != s21_container.end(); ++s21_it, ++it) {
    EXPECT_EQ(*s21_it, *it);
  }
  EXPECT_EQ(s21_container.size(), container.size());
}

TEST(ListMaxSize, Test1) {
  s21::list<int> s21_container;
  EXPECT_EQ(s21_container.max_size(), 0);
}

TEST(ListMaxSize, Test2) {
  s21::list<uint8_t> s21_container;
  EXPECT_EQ(s21_container.max_size(), 0);
}

TEST(ListMaxSize, Test3) {
  s21::list<Dummy> s21_container;
  EXPECT_EQ(s21_container.max_size(), 0);
}

TEST(ListMaxSize, Test4) {
  s21::list<int*> s21_container;
  EXPECT_EQ(s21_container.max_size(), 0);
}

TEST(ListInsertManyFront, Test1) {
  std::list container{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  s21::list<int> s21_container;
  s21_container.insert_many_front(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
  auto s21_it{s21_container.begin()};
  for (auto it{container.begin()}; s21_it != s21_container.end();
       ++s21_it, ++it) {
    EXPECT_EQ(*s21_it, *it);
  }
}

TEST(ListInsertManyFront, Test2) {
  std::list<int> container;
  s21::list<int> s21_container;
  s21_container.insert_many_front();
  auto s21_it{s21_container.begin()};
  for (auto it{container.begin()}; s21_it != s21_container.end();
       ++s21_it, ++it) {
    EXPECT_EQ(*s21_it, *it);
  }
}

TEST(ListInsertManyFront, Test3) {
  std::list container{1};
  s21::list<int> s21_container;
  s21_container.insert_many_front(1);
  auto s21_it{s21_container.begin()};
  for (auto it{container.begin()}; s21_it != s21_container.end();
       ++s21_it, ++it) {
    EXPECT_EQ(*s21_it, *it);
  }
}

TEST(ListInsertManyFront, Test4) {
  std::list container{1, 2, 3};
  s21::list<int> s21_container;
  s21_container.insert_many_front(1, 2, 3);
  auto s21_it{s21_container.begin()};
  for (auto it{container.begin()}; s21_it != s21_container.end();
       ++s21_it, ++it) {
    EXPECT_EQ(*s21_it, *it);
  }
}

TEST(ListInsertManyFront, Test5) {
  std::list container{1, 2, 3};
  s21::list s21_container{1, 2, 3};
  s21_container.insert_many_front();
  auto s21_it{s21_container.begin()};
  for (auto it{container.begin()}; s21_it != s21_container.end();
       ++s21_it, ++it) {
    EXPECT_EQ(*s21_it, *it);
  }
}

TEST(ListInsertManyFront, Test6) {
  std::list container{4, 5, 6, 1, 2, 3};
  s21::list s21_container{1, 2, 3};
  s21_container.insert_many_front(4, 5, 6);
  auto s21_it{s21_container.begin()};
  for (auto it{container.begin()}; s21_it != s21_container.end();
       ++s21_it, ++it) {
    EXPECT_EQ(*s21_it, *it);
  }
}

TEST(ListInsertManyFront, Test7) {
  std::list container{5, 1, 2, 3};
  s21::list s21_container{1, 2, 3};
  s21_container.insert_many_front(5);
  auto s21_it{s21_container.begin()};
  for (auto it{container.begin()}; s21_it != s21_container.end();
       ++s21_it, ++it) {
    EXPECT_EQ(*s21_it, *it);
  }
}

TEST(ListInsertManyFront, Test8) {
  std::list container{'\t', '\v', '\r', '\b', '\f', ' ',
                      'a',  'b',  'c',  'x',  'y',  'z'};
  s21::list s21_container{'a', 'b', 'c', 'x', 'y', 'z'};
  s21_container.insert_many_front('\t', '\v', '\r', '\b', '\f', ' ');
  auto s21_it{s21_container.begin()};
  for (auto it{container.begin()}; s21_it != s21_container.end();
       ++s21_it, ++it) {
    EXPECT_EQ(*s21_it, *it);
  }
}

TEST(ListInsertManyFront, Test9) {
  std::list<std::string> container{"The",       "behavior",   "is",
                                   "undefined", "Non-zero",   "value",
                                   "character", "whitespace", "otherwise"};
  s21::list<std::string> s21_container{"Non-zero", "value", "character",
                                       "whitespace", "otherwise"};
  s21_container.insert_many_front("The", "behavior", "is", "undefined");
  auto s21_it{s21_container.begin()};
  for (auto it{container.begin()}; s21_it != s21_container.end();
       ++s21_it, ++it) {
    EXPECT_EQ(*s21_it, *it);
  }
}

TEST(ListInsertManyFront, Test10) {
  const Dummy kArr[]{{0, 22, 10, 2024}, {1, 22, 10, 2024},  {3, 23, 10, 2024},
                     {4, 1, 12, 2024},  {5, 23, 10, 2023},  {6, 1, 1, 2023},
                     {7, 24, 2, 2022},  {8, 1, 1, 2000},    {9, 8, 1, 1992},
                     {10, 1, 1, 2000},  {11, 23, 10, 2024}, {12, 1, 1, 2000}};
  std::list container{Dummy{11, 8, 1, 1992}, Dummy{12, 1, 1, 2000},
                      Dummy{13, 1, 1, 2000}};
  s21::list<Dummy> s21_container;
  for (const auto& i : kArr) {
    container.push_back(i);
    s21_container.push_back(i);
  }
  s21_container.insert_many_front(Dummy{11, 8, 1, 1992}, Dummy{12, 1, 1, 2000},
                                  Dummy{13, 1, 1, 2000});
  auto s21_it{s21_container.begin()};
  for (auto it{container.begin()}; s21_it != s21_container.end();
       ++s21_it, ++it) {
    EXPECT_EQ(*s21_it, *it);
  }
}

TEST(ListInsertManyBack, Test1) {
  std::list container{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  s21::list<int> s21_container;
  s21_container.insert_many_back(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
  auto s21_it{s21_container.begin()};
  for (auto it{container.begin()}; s21_it != s21_container.end();
       ++s21_it, ++it) {
    EXPECT_EQ(*s21_it, *it);
  }
}

TEST(ListInsertManyBack, Test2) {
  std::list<int> container;
  s21::list<int> s21_container;
  s21_container.insert_many_back();
  auto s21_it{s21_container.begin()};
  for (auto it{container.begin()}; s21_it != s21_container.end();
       ++s21_it, ++it) {
    EXPECT_EQ(*s21_it, *it);
  }
}

TEST(ListInsertManyBack, Test3) {
  std::list container{1};
  s21::list<int> s21_container;
  s21_container.insert_many_back(1);
  auto s21_it{s21_container.begin()};
  for (auto it{container.begin()}; s21_it != s21_container.end();
       ++s21_it, ++it) {
    EXPECT_EQ(*s21_it, *it);
  }
}

TEST(ListInsertManyBack, Test4) {
  std::list container{1, 2, 3};
  s21::list<int> s21_container;
  s21_container.insert_many_back(1, 2, 3);
  auto s21_it{s21_container.begin()};
  for (auto it{container.begin()}; s21_it != s21_container.end();
       ++s21_it, ++it) {
    EXPECT_EQ(*s21_it, *it);
  }
}

TEST(ListInsertManyBack, Test5) {
  std::list container{1, 2, 3};
  s21::list s21_container{1, 2, 3};
  s21_container.insert_many_back();
  auto s21_it{s21_container.begin()};
  for (auto it{container.begin()}; s21_it != s21_container.end();
       ++s21_it, ++it) {
    EXPECT_EQ(*s21_it, *it);
  }
}

TEST(ListInsertManyBack, Test6) {
  std::list container{1, 2, 3, 4, 5, 6};
  s21::list s21_container{1, 2, 3};
  s21_container.insert_many_back(4, 5, 6);
  auto s21_it{s21_container.begin()};
  for (auto it{container.begin()}; s21_it != s21_container.end();
       ++s21_it, ++it) {
    EXPECT_EQ(*s21_it, *it);
  }
}

TEST(ListInsertManyBack, Test7) {
  std::list container{1, 2, 3, 5};
  s21::list s21_container{1, 2, 3};
  s21_container.insert_many_back(5);
  auto s21_it{s21_container.begin()};
  for (auto it{container.begin()}; s21_it != s21_container.end();
       ++s21_it, ++it) {
    EXPECT_EQ(*s21_it, *it);
  }
}

TEST(ListInsertManyBack, Test8) {
  std::list container{'a',  'b',  'c',  'x',  'y',  'z',
                      '\t', '\v', '\r', '\b', '\f', ' '};
  s21::list s21_container{'a', 'b', 'c', 'x', 'y', 'z'};
  s21_container.insert_many_back('\t', '\v', '\r', '\b', '\f', ' ');
  auto s21_it{s21_container.begin()};
  for (auto it{container.begin()}; s21_it != s21_container.end();
       ++s21_it, ++it) {
    EXPECT_EQ(*s21_it, *it);
  }
}

TEST(ListInsertManyBack, Test9) {
  std::list<std::string> container{"Non-zero",   "value",     "character",
                                   "whitespace", "otherwise", "The",
                                   "behavior",   "is",        "undefined"};
  s21::list<std::string> s21_container{"Non-zero", "value", "character",
                                       "whitespace", "otherwise"};
  s21_container.insert_many_back("The", "behavior", "is", "undefined");
  auto s21_it{s21_container.begin()};
  for (auto it{container.begin()}; s21_it != s21_container.end();
       ++s21_it, ++it) {
    EXPECT_EQ(*s21_it, *it);
  }
}

TEST(ListInsertManyBack, Test10) {
  const Dummy kArr[]{{0, 22, 10, 2024}, {1, 22, 10, 2024},  {3, 23, 10, 2024},
                     {4, 1, 12, 2024},  {5, 23, 10, 2023},  {6, 1, 1, 2023},
                     {7, 24, 2, 2022},  {8, 1, 1, 2000},    {9, 8, 1, 1992},
                     {10, 1, 1, 2000},  {11, 23, 10, 2024}, {12, 1, 1, 2000}};
  std::list container{Dummy{11, 8, 1, 1992}, Dummy{12, 1, 1, 2000},
                      Dummy{13, 1, 1, 2000}};
  s21::list<Dummy> s21_container;
  for (const auto& i : kArr) {
    container.push_front(i);
    s21_container.push_front(i);
  }
  s21_container.insert_many_back(Dummy{11, 8, 1, 1992}, Dummy{12, 1, 1, 2000},
                                 Dummy{13, 1, 1, 2000});
  auto s21_it{s21_container.begin()};
  for (auto it{container.begin()}; s21_it != s21_container.end();
       ++s21_it, ++it) {
    EXPECT_EQ(*s21_it, *it);
  }
}

TEST(ListInsertMany, Test1) {
  std::list container{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  s21::list<int> s21_container;
  s21_container.insert_many(s21_container.begin(), 1, 2, 3, 4, 5, 6, 7, 8, 9,
                            10);
  auto s21_it{s21_container.begin()};
  for (auto it{container.begin()}; s21_it != s21_container.end();
       ++s21_it, ++it) {
    EXPECT_EQ(*s21_it, *it);
  }
}

TEST(ListInsertMany, Test2) {
  std::list<int> container;
  s21::list<int> s21_container;
  s21_container.insert_many(s21_container.end());
  auto s21_it{s21_container.begin()};
  for (auto it{container.begin()}; s21_it != s21_container.end();
       ++s21_it, ++it) {
    EXPECT_EQ(*s21_it, *it);
  }
}

TEST(ListInsertMany, Test3) {
  std::list container{1};
  s21::list<int> s21_container;
  s21_container.insert_many(s21_container.end(), 1);
  auto s21_it{s21_container.begin()};
  for (auto it{container.begin()}; s21_it != s21_container.end();
       ++s21_it, ++it) {
    EXPECT_EQ(*s21_it, *it);
  }
}

TEST(ListInsertMany, Test4) {
  std::list container{1, 2, 3};
  s21::list<int> s21_container;
  s21_container.insert_many(s21_container.end(), 1, 2, 3);
  auto s21_it{s21_container.begin()};
  for (auto it{container.begin()}; s21_it != s21_container.end();
       ++s21_it, ++it) {
    EXPECT_EQ(*s21_it, *it);
  }
}

TEST(ListInsertMany, Test5) {
  std::list container{1, 2, 3};
  s21::list s21_container{1, 2, 3};
  s21_container.insert_many(s21_container.begin());
  auto s21_it{s21_container.begin()};
  for (auto it{container.begin()}; s21_it != s21_container.end();
       ++s21_it, ++it) {
    EXPECT_EQ(*s21_it, *it);
  }
}

TEST(ListInsertMany, Test6) {
  std::list container{1, 2, 4, 5, 6, 3};
  s21::list s21_container{1, 2, 3};
  auto s21_it{s21_container.begin()};
  std::advance(s21_it, 2);
  auto s21_it_new{s21_container.insert_many(s21_it, 4, 5, 6)};

  EXPECT_EQ(*s21_it_new, 4);
  EXPECT_EQ(*s21_it, 3);

  s21_it = s21_container.begin();
  for (auto it{container.begin()}; s21_it != s21_container.end();
       ++s21_it, ++it) {
    EXPECT_EQ(*s21_it, *it);
  }
}

TEST(ListInsertMany, Test7) {
  std::list container{1, 5, 2, 3};
  s21::list s21_container{1, 2, 3};
  auto s21_it{s21_container.begin()};
  std::advance(s21_it, 1);
  auto s21_it_new{s21_container.insert_many(s21_it, 5)};

  EXPECT_EQ(*s21_it_new, 5);
  EXPECT_EQ(*s21_it, 2);

  s21_it = s21_container.begin();
  for (auto it{container.begin()}; s21_it != s21_container.end();
       ++s21_it, ++it) {
    EXPECT_EQ(*s21_it, *it);
  }
}

TEST(ListInsertMany, Test8) {
  std::list container{'a',  'b',  'c', '\t', '\v', '\r',
                      '\b', '\f', ' ', 'x',  'y',  'z'};
  s21::list s21_container{'a', 'b', 'c', 'x', 'y', 'z'};
  auto s21_it{s21_container.begin()};
  std::advance(s21_it, 3);
  auto s21_it_new{
      s21_container.insert_many(s21_it, '\t', '\v', '\r', '\b', '\f', ' ')};

  EXPECT_EQ(*s21_it_new, '\t');
  EXPECT_EQ(*s21_it, 'x');

  s21_it = s21_container.begin();
  for (auto it{container.begin()}; s21_it != s21_container.end();
       ++s21_it, ++it) {
    EXPECT_EQ(*s21_it, *it);
  }
}

TEST(ListInsertMany, Test9) {
  std::list<std::string> container{"Non-zero",  "value",      "character",
                                   "The",       "behavior",   "is",
                                   "undefined", "whitespace", "otherwise"};
  s21::list<std::string> s21_container{"Non-zero", "value", "character",
                                       "whitespace", "otherwise"};
  auto s21_it{s21_container.end()};
  std::advance(s21_it, -2);
  auto s21_it_new{
      s21_container.insert_many(s21_it, "The", "behavior", "is", "undefined")};

  EXPECT_EQ(*s21_it_new, "The");
  EXPECT_EQ(*s21_it, "whitespace");

  s21_it = s21_container.begin();
  for (auto it{container.begin()}; s21_it != s21_container.end();
       ++s21_it, ++it) {
    EXPECT_EQ(*s21_it, *it);
  }
}

TEST(ListInsertMany, Test10) {
  const Dummy kArr[]{{0, 22, 10, 2024}, {1, 22, 10, 2024},  {3, 23, 10, 2024},
                     {4, 1, 12, 2024},  {5, 23, 10, 2023},  {6, 1, 1, 2023},
                     {7, 24, 2, 2022},  {8, 1, 1, 2000},    {9, 8, 1, 1992},
                     {10, 1, 1, 2000},  {11, 23, 10, 2024}, {12, 1, 1, 2000}};
  std::list container{Dummy{11, 8, 1, 1992}, Dummy{12, 1, 1, 2000},
                      Dummy{13, 1, 1, 2000}};
  s21::list<Dummy> s21_container;
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
}
