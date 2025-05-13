#include "s21_stack.h"

namespace s21 {
template <typename T, class Container>
stack<T, Container>::stack() : data_(Container()) {}

template <typename T, class Container>
stack<T, Container>::stack(
    std::initializer_list<typename stack<T, Container>::value_type> const&
        items)
    : data_(items) {}

template <typename T, class Container>
stack<T, Container>::stack(const stack& s) : data_(s.data_) {}

template <typename T, class Container>
stack<T, Container>::stack(stack&& s) noexcept : data_(std::move(s.data_)) {}

template <typename T, class Container>
stack<T, Container>& stack<T, Container>::operator=(stack&& s) noexcept {
  if (this != &s) {
    data_ = std::move(s.data_);
  }
  return *this;
}

template <typename T, class Container>
stack<T, Container>& stack<T, Container>::operator=(const stack& s) {
  if (this != &s) {
    data_ = s.data_;
  }
  return *this;
}

template <typename T, class Container>
stack<T, Container>::~stack() {}

template <typename T, class Container>
typename stack<T, Container>::const_reference stack<T, Container>::top() const {
  return data_.back();
}

template <typename T, class Container>
bool stack<T, Container>::empty() const {
  return data_.empty();
}

template <typename T, class Container>
typename stack<T, Container>::size_type stack<T, Container>::size() const {
  return data_.size();
}

template <typename T, class Container>
void stack<T, Container>::push(const_reference value) {
  data_.push_back(value);
}

template <typename T, class Container>
void stack<T, Container>::pop() {
  data_.pop_back();
}

template <typename T, class Container>
void stack<T, Container>::swap(stack& other) noexcept {
  data_.swap(other.data_);
}

template <typename T>
stack(std::initializer_list<T>) -> stack<T>;

template <typename T, class Container>
template <typename... Args>
void stack<T, Container>::insert_many_back(Args&&... args) {
  data_.insert_many_back(args...);
}

}  // namespace s21
