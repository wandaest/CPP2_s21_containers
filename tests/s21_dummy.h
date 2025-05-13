#ifndef TESTS_S21_DUMMY_H
#define TESTS_S21_DUMMY_H

struct Dummy {
  int id;
  int day, month, year;
};

bool operator<(const Dummy& lhs, const Dummy& rhs);
bool operator==(const Dummy& lhs, const Dummy& rhs);

#endif  // TESTS_S21_DUMMY_H
