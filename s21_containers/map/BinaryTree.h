#ifndef S21_CONTAINERS_MAP_S21_BINARY_TREE_H_
#define S21_CONTAINERS_MAP_S21_BINARY_TREE_H_

#include <limits>
#include <vector>

namespace s21 {
template <typename Key, typename T>
class BinaryTree {
 private:
  struct Node {
    Node *head_, *left_, *right_;
    Key key_;
    T value_;
    Node();
    Node(Key key, T value);
    ~Node();
    void clear();
  };

  class iterator {
   public:
    iterator left_edge();
    iterator right_edge();
    Node* ptr_;
    iterator();
    iterator(Node* ptr);
    operator Node*() const { return ptr_; }
    Node* operator->();
    iterator step_left();
    iterator step_right();
    iterator step_up();
    iterator prev();
    iterator next();
    iterator& operator--();
    iterator& operator++();
    iterator operator--(int);
    iterator operator++(int);
    // iterator create_sub_node(Key key, T value, bool flag);
    iterator create_sub_node(Key key, bool flag);
    iterator copy() const;
  };

  Node* operator->() const { return *this->root_; };
  void update(iterator iter);
  void erase_one_child(iterator iter, bool flag);
  void erase_two_child(iterator iter, bool flag);
  void erase_no_child(iterator iter, bool flag);
  void erase_root(iterator iter);
  void erase_node(iterator pos);
  void erase_update(iterator iter);
  void extract(iterator from, iterator to, bool flag);
  void splice(iterator from, iterator to, bool flag);
  void extract_root(iterator from, iterator to, BinaryTree& other, bool flag);
  void merge_update(iterator pos);
  std::pair<iterator, bool> find(const Key& key) const;
  std::pair<iterator, bool> find_or_create(Key key);
  int children_location(iterator pos);
  // int compare(const Key& key) const;

 public:
  using key_type = Key;
  using mapped_type = T;
  using value_type = std::pair<const key_type, mapped_type>;
  using reference = value_type&;
  using const_reference = const value_type&;
  using const_iterator = const BinaryTree<Key, T>::iterator;
  using size_type = size_t;
  using iterator = BinaryTree<Key, T>::iterator;

  BinaryTree();
  BinaryTree(std::initializer_list<value_type> const& items);
  BinaryTree(const BinaryTree& m);
  BinaryTree(BinaryTree&& m);
  BinaryTree& operator=(BinaryTree&& m);
  ~BinaryTree();
  T& at(const Key& key);
  T& operator[](const Key& key);
  bool contains(const Key& key) const;
  void clear();
  iterator begin() const;
  iterator end() const;
  size_type size() const;
  size_type max_size() const;
  bool empty() const;
  std::pair<iterator, bool> insert_or_assign(const Key& key, const T& obj);
  std::pair<iterator, bool> insert(const Key& key, const T& obj);
  std::pair<iterator, bool> insert(const value_type& value);
  void merge(BinaryTree& other);
  void erase(iterator pos);
  void swap(BinaryTree& other);
  template <typename... Args>
  std::vector<std::pair<iterator, bool>> insert_many(Args&&... args);

 protected:
  iterator root_, begin_, end_;
  size_type size_;
};

};  // namespace s21

#include "BinaryTree.tpp"

#endif  // S21_CONTAINERS_MAP_S21_BINARY_TREE_H_
