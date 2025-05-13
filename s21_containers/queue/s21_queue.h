#ifndef S21_CONTAINERS_QUEUE_S21_QUEUE_H_
#define S21_CONTAINERS_QUEUE_S21_QUEUE_H_

#include "../list/s21_list.h"

namespace s21 {

template <class T>
class queue {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = size_t;

  queue() = default;
  queue(std::initializer_list<value_type> const &items) : c_{items} {}
  queue(const queue &other) : c_{other.c_} {}
  queue(queue &&other) noexcept : c_{other.c_} {}
  ~queue() noexcept = default;

  queue &operator=(const queue &rhs);
  queue &operator=(queue &&rhs) noexcept;

  const_reference front() noexcept;
  const_reference back() noexcept;

  bool empty() const noexcept;
  size_type size() const noexcept;

  void push(const_reference value);
  void pop();
  void swap(queue &other) noexcept;

  template <class... Args>
  void insert_many_back(Args &&...args);

 private:
  list<T> c_;
};
}  // namespace s21

#include "s21_queue.inc"

#endif  // S21_CONTAINERS_QUEUE_S21_QUEUE_H_
