#include <algorithm>
#include <stdexcept>

namespace s21 {

template <typename T, size_t N>
array<T, N>::array(std::initializer_list<value_type> const &items) {
  std::copy(items.begin(), items.end(), a_);
  if (items.size() < N) std::fill(a_ + items.size(), a_ + N, value_type{});
}

template <typename T, typename... Args>
array(T, Args...) -> array<T, sizeof...(Args) + 1>;

template <typename T, size_t N>
typename array<T, N>::reference array<T, N>::at(size_type pos) {
  if (pos < N) return a_[pos];
  throw std::out_of_range("Out of range error");
}

template <typename T, size_t N>
typename array<T, N>::reference array<T, N>::operator[](
    size_type pos) noexcept {
  return a_[pos];
}

template <typename T, size_t N>
typename array<T, N>::const_reference array<T, N>::front() noexcept {
  return a_[0];
}

template <typename T, size_t N>
typename array<T, N>::const_reference array<T, N>::back() noexcept {
  return a_[N - 1];
}

template <typename T, size_t N>
typename array<T, N>::iterator array<T, N>::data() noexcept {
  return a_;
}

template <typename T, size_t N>
typename array<T, N>::iterator array<T, N>::begin() noexcept {
  return a_;
}

template <typename T, size_t N>
typename array<T, N>::iterator array<T, N>::end() noexcept {
  return a_ + N;
}

template <typename T, size_t N>
typename array<T, N>::const_iterator array<T, N>::begin() const noexcept {
  return a_;
}

template <typename T, size_t N>
typename array<T, N>::const_iterator array<T, N>::end() const noexcept {
  return a_ + size();
}

template <typename T, size_t N>
bool array<T, N>::empty() const noexcept {
  return N == 0;
}

template <typename T, size_t N>
typename array<T, N>::size_type array<T, N>::size() const noexcept {
  return N;
}

template <typename T, size_t N>
typename array<T, N>::size_type array<T, N>::max_size() const noexcept {
  return N;
}

template <typename T, size_t N>
void array<T, N>::swap(array &other) noexcept {
  std::swap(a_, other.a_);
}

template <typename T, size_t N>
void array<T, N>::fill(const_reference value) {
  std::fill_n(a_, N, value);
}

}  // namespace s21
