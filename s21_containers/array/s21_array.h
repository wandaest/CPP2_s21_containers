#ifndef S21_CONTAINERS_ARRAY_S21_ARRAY_H_
#define S21_CONTAINERS_ARRAY_S21_ARRAY_H_

#include <cstddef>
#include <initializer_list>

namespace s21 {
template <typename T, size_t N>
struct array {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = T *;
  using const_iterator = const T *;
  using size_type = size_t;

  array() = default;
  array(std::initializer_list<value_type> const &items);

  reference at(size_type pos);
  reference operator[](size_type pos) noexcept;
  const_reference front() noexcept;
  const_reference back() noexcept;
  iterator data() noexcept;

  iterator begin() noexcept;
  iterator end() noexcept;
  const_iterator begin() const noexcept;
  const_iterator end() const noexcept;

  bool empty() const noexcept;
  size_type size() const noexcept;
  size_type max_size() const noexcept;

  void swap(array &other) noexcept;
  void fill(const_reference value);

 private:
  value_type a_[N];
};
}  // namespace s21

#include "s21_array.inc"

#endif  // S21_CONTAINERS_ARRAY_S21_ARRAY_H_
