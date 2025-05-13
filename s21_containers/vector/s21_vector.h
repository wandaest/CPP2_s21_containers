#ifndef S21_VECTOR_H
#define S21_VECTOR_H

#include <algorithm>
#include <iostream>
#include <limits>
#include <new>

namespace s21 {

template <typename T>
class vector {
 public:
  // Member types
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = T *;
  using const_iterator = const T *;
  using size_type = size_t;

  // Functions
  vector();
  explicit vector(size_type n);
  vector(std::initializer_list<value_type> const &items);
  vector(const vector<T> &v);
  vector(vector &&v);
  ~vector();
  vector<T> &operator=(vector<T> &&v);
  vector<T> &operator=(const vector<T> &v);

  // Element access
  reference at(size_type pos);
  reference operator[](size_type pos);
  const_reference front();
  const_reference back() const;
  T *data();

  // Iterators
  iterator begin();
  iterator end();

  // Capacity
  bool empty() const;
  size_type size() const;
  size_type max_size();
  void reserve(size_type size);
  size_type capacity();
  void shrink_to_fit();

  // Modifiers
  void clear();
  iterator insert(iterator pos, const_reference value);
  void erase(iterator pos);
  void push_back(const_reference value);
  void pop_back();
  void swap(vector &other);

  template <typename... Args>
  iterator insert_many(const_iterator pos, Args &&...args);
  template <typename... Args>
  void insert_many_back(Args &&...args);

 private:
  value_type *values_;
  size_type size_;
  size_type capacity_;
};

}  // namespace s21

#include "s21_vector.tpp"

#endif  // S21_VECTOR_H
