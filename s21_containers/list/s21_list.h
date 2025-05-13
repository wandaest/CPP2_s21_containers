#ifndef S21_CONTAINERS_LIST_S21_LIST_H_
#define S21_CONTAINERS_LIST_S21_LIST_H_

#include <cstddef>
#include <initializer_list>
#include <iterator>

namespace s21 {

template <class T>
class list {
 public:
  struct ListIterator;
  struct ListConstIterator;

  using value_type = T;
  using reference = T&;
  using const_reference = const T&;
  using iterator = ListIterator;
  using const_iterator = ListConstIterator;
  using size_type = size_t;

  list();
  explicit list(size_type n);
  list(std::initializer_list<value_type> const& items);
  list(const list& other);
  list(list&& other) noexcept;
  ~list() noexcept;

  list& operator=(const list& rhs);
  list& operator=(list&& rhs) noexcept;

  const_reference front() noexcept;
  const_reference back() noexcept;

  iterator begin() noexcept;
  iterator end() noexcept;
  const_iterator begin() const noexcept;
  const_iterator end() const noexcept;

  bool empty() const noexcept;
  size_type size() const noexcept;
  size_type max_size() const noexcept;

  void clear() noexcept;
  iterator insert(iterator pos, const_reference value);
  void erase(iterator pos) noexcept;
  void push_back(const_reference value);
  void pop_back() noexcept;
  void push_front(const_reference value);
  void pop_front() noexcept;
  void swap(list& other) noexcept;
  void merge(list& other);
  void splice(const_iterator pos, list& other) noexcept;
  void splice(const_iterator pos, list& other, const_iterator first,
              const_iterator last) noexcept;
  void reverse() noexcept;
  void unique();
  void sort();

  template <class... Args>
  iterator insert_many(const_iterator pos, Args&&... args);
  template <class... Args>
  void insert_many_back(Args&&... args);
  template <class... Args>
  void insert_many_front(Args&&... args);

 private:
  struct Node;

  Node* head_;
  Node* tail_;
  size_type size_;

  static void NodeInsertBefore(Node* spot, Node* node);
  static void NodeInsertAfter(Node* spot, Node* node);
  static void NodeRemove(Node* node);
  static void Splice(const_iterator pos, const_iterator first,
                     const_iterator last) noexcept;
};
}  // namespace s21

#include "s21_list.inc"

#endif  // S21_CONTAINERS_LIST_S21_LIST_H_
