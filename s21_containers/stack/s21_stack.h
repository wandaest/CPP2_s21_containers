#ifndef S21_STACK_H
#define S21_STACK_H

#include "../vector/s21_vector.h"

namespace s21 {

template <typename T, class Container = vector<T>>
class stack {
 public:
  // Member types
  using value_type = typename Container::value_type;  // Добавлено typename
  using reference = typename Container::reference;  // Добавлено typename
  using const_reference =
      typename Container::const_reference;  // Добавлено typename
  using size_type = typename Container::size_type;  // Добавлено typename

  // Constructors and Destructor
  stack();  // default constructor
  stack(std::initializer_list<value_type> const
            &items);          // initializer list constructor
  stack(const stack &s);      // copy constructor
  stack(stack &&s) noexcept;  // move constructor
  ~stack();                   // destructor
  stack<T, Container> &operator=(
      stack &&s) noexcept;                         // move assignment operator
  stack<T, Container> &operator=(const stack &s);  // copy assignment operator

  // Element access
  const_reference top() const;  // accesses the top element

  // Capacity
  bool empty() const;      // checks whether the container is empty
  size_type size() const;  // returns the number of elements

  // Modifiers
  void push(const_reference value);  // inserts element at the top
  void pop();                        // removes the top element
  void swap(stack &other) noexcept;  // swaps the contents

  template <typename... Args>
  void insert_many_back(Args &&...args);

 private:
  Container data_;
};

}  // namespace s21

#include "s21_stack.tpp"

#endif
