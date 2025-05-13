#include "all_tests_s21.h"

bool operator<(const Dummy& lhs, const Dummy& rhs) {
  if (lhs.year < rhs.year) return true;
  if (lhs.year > rhs.year) return false;
  if (lhs.month < rhs.month) return true;
  if (lhs.month > rhs.month) return false;
  if (lhs.day < rhs.day) return true;
  return false;
}

bool operator==(const Dummy& lhs, const Dummy& rhs) {
  return lhs.id == rhs.id && lhs.year == rhs.year && lhs.month == rhs.month &&
         lhs.day == rhs.day;
}
