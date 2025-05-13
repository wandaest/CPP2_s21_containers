#ifndef S21_CONTAINERS_MAP_S21_MAP_H_
#define S21_CONTAINERS_MAP_S21_MAP_H_

#include "BinaryTree.h"

namespace s21 {
template <class Key, class T>
class map : public BinaryTree<Key, T> {
 public:
  using key_type = Key;
  using mapped_type = T;
  using value_type = std::pair<const key_type, mapped_type>;
  using reference = value_type&;
  using const_reference = const value_type&;
  using const_iterator = typename BinaryTree<Key, T>::const_iterator;
  using size_type = size_t;
  using iterator = typename BinaryTree<Key, T>::iterator;

  // constructors
  map();  // default constructor, creates empty map
  map(std::initializer_list<value_type> const&
          items);  // initializer list constructor, creates the map
                   // initizialized using std::initializer_list
  map(const map& m);
  map(map&& m);
  ~map();
  map& operator=(map&& m);
  T& at(const Key& key);
  T& operator[](const Key& key);
  iterator begin() const;
  iterator end() const;
  bool empty() const;
  size_type size() const;
  size_type max_size() const;
  void clear();
  void merge(map& other);
  void swap(map& other);
  void erase(iterator pos);
  std::pair<iterator, bool> insert_or_assign(const Key& key, const T& obj);
  std::pair<iterator, bool> insert(const Key& key, const T& obj);
  std::pair<iterator, bool> insert(const value_type& value);
  bool contains(const Key& key) const;
  template <typename... Args>
  std::vector<std::pair<iterator, bool>> insert_many(Args&&... args);
};
};  // namespace s21

#include "s21_map.tpp"

#endif  // S21_CONTAINERS_MAP_S21_MAP_H_
