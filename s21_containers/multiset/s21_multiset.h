#ifndef S21_CONTAINERS_MULTISET_S21_MULTISET_H_
#define S21_CONTAINERS_MULTISET_S21_MULTISET_H_

/*

#include <cstddef>
#include <initializer_list>

namespace s21 {

template <typename Key>
class multiset {
  using key_type = Key;
  using value_type = Key;
  using reference = value_type &;
  using const_reference = const value_type &;
  using iterator = typename BinaryTree<Key>::iterator;
  using const_iterator = typename BinaryTree<Key>::const_iterator;
  using size_type = size_t;

 public:
  multiset() = default;
  multiset(std::initializer_list<value_type> const &items);
  multiset(const multiset &other);
  multiset(multiset &&other) noexcept;
  ~multiset() = default;

  multiset &operator=(const multiset &rhs);
  multiset &operator=(multiset &&rhs);

  iterator begin() noexcept;
  iterator end() noexcept;
  const_iterator begin() const noexcept;
  const_iterator end() const noexcept;

  bool empty() const noexcept;
  size_type size() const noexcept;
  size_type max_size() const noexcept;

  void clear();
  iterator insert(const value_type &value);
  void erase(iterator pos);
  void swap(multiset &other);
  void merge(multiset &other);

  size_type count(const Key &key);
  iterator find(const Key &key);
  bool contains(const Key &key);
  std::pair<iterator, iterator> equal_range(const Key &key);
  iterator lower_bound(const Key &key);
  iterator upper_bound(const Key &key);

 private:
  BinaryTree<Key> tree_;
  size_type size_{};
};
}  // namespace s21

*/

#endif  // S21_CONTAINERS_MULTISET_S21_MULTISET_H_
