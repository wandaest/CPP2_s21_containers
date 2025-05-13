#include "BinaryTree.h"

namespace s21 {
// Node functions

template <typename Key, typename T>
BinaryTree<Key, T>::Node::Node() {
  left_ = nullptr;
  right_ = nullptr;
  head_ = nullptr;
  key_ = Key();
  value_ = T();
}

template <typename Key, typename T>
BinaryTree<Key, T>::Node::Node(Key key, T value) {
  left_ = nullptr;
  right_ = nullptr;
  head_ = nullptr;
  key_ = key;
  value_ = value;
}

template <typename Key, typename T>
BinaryTree<Key, T>::Node::~Node() {
  left_ = nullptr;
  right_ = nullptr;
  head_ = nullptr;
  // key_ = 0;
  // value_ = 0;
}

template <typename Key, typename T>
void BinaryTree<Key, T>::Node::clear() {
  if (left_) left_->clear();
  if (right_) right_->clear();
  delete this;
}

// BinaryTree functions

template <typename Key, typename T>
BinaryTree<Key, T>::BinaryTree() {
  root_ = nullptr;
  size_ = 0;
  begin_ = nullptr;
  end_ = nullptr;
}

template <typename Key, typename T>
BinaryTree<Key, T>::BinaryTree(std::initializer_list<value_type> const& items) {
  root_ = nullptr;
  size_ = 0;
  begin_ = nullptr;
  end_ = new Node();
  for (auto i : items) insert(i);
}

template <typename Key, typename T>
BinaryTree<Key, T>::BinaryTree(const BinaryTree& m) {
  root_ = m.root_.copy();
  begin_ = root_.left_edge();
  end_ = root_.right_edge();
  size_ = m.size_;
}

template <typename Key, typename T>
BinaryTree<Key, T>::BinaryTree(BinaryTree&& m) {
  root_ = m.root_;
  begin_ = m.begin_;
  end_ = m.end_;
  size_ = m.size_;
  m.root_ = nullptr;  // заменить на clear()
  m.begin_ = nullptr;
  m.end_ = nullptr;
  m.size_ = 0;
}

template <typename Key, typename T>
BinaryTree<Key, T>& BinaryTree<Key, T>::operator=(BinaryTree&& m) {
  std::move(m);
}

template <typename Key, typename T>
BinaryTree<Key, T>::~BinaryTree() {
  clear();
}

template <typename Key, typename T>
T& BinaryTree<Key, T>::at(const Key& key) {
  std::pair<typename BinaryTree<Key, T>::iterator, bool> res = find(key);
  if (res.second) {
    return res.first->value_;
  } else {
    throw std::out_of_range("map::at");
  }
}

template <typename Key, typename T>
T& BinaryTree<Key, T>::operator[](const Key& key) {
  std::pair<typename BinaryTree<Key, T>::iterator, bool> res =
      find_or_create(key);
  return res.first->value_;
}

template <typename Key, typename T>
bool BinaryTree<Key, T>::contains(const Key& key) const {
  return find(key).second;
}

template <typename Key, typename T>
void BinaryTree<Key, T>::clear() {
  if (root_) root_->clear();
  root_ = nullptr;
  begin_ = nullptr;
  end_ = nullptr;
  size_ = 0;
}

template <typename Key, typename T>
bool BinaryTree<Key, T>::empty() const {
  return !root_;
}

template <typename Key, typename T>
typename BinaryTree<Key, T>::iterator BinaryTree<Key, T>::begin() const {
  return begin_;
}

template <typename Key, typename T>
typename BinaryTree<Key, T>::iterator BinaryTree<Key, T>::end() const {
  return end_;
}

template <typename Key, typename T>
typename BinaryTree<Key, T>::size_type BinaryTree<Key, T>::size() const {
  return size_;
}

template <typename Key, typename T>
typename BinaryTree<Key, T>::size_type BinaryTree<Key, T>::max_size() const {
  return std::numeric_limits<typename BinaryTree<Key, T>::size_type>::max() /
         sizeof(BinaryTree);
}

template <typename Key, typename T>
std::pair<typename BinaryTree<Key, T>::iterator, bool>
BinaryTree<Key, T>::find_or_create(Key key) {
  iterator res;
  bool flag = true;
  if (root_) {
    iterator i = root_;
    while (i && i != end_) {
      if (key == i.ptr_->key_) {
        res = i;
        flag = false;
        break;
      } else if (key > i.ptr_->key_) {
        if (i.ptr_->right_ && i.ptr_->right_ != end_) {
          i.ptr_ = i.ptr_->right_;
        } else {
          res = i.create_sub_node(key, 1);
          break;
        }
      } else {
        if (i.ptr_->left_) {
          i.ptr_ = i.ptr_->left_;
        } else {
          res = i.create_sub_node(key, 0);
          break;
        }
      }
    }
  } else {
    root_ = new Node();
    res = root_;
    res.ptr_->key_ = key;
  }
  if (flag) update(res);
  return std::pair<typename BinaryTree<Key, T>::iterator, bool>(res, flag);
}

template <typename Key, typename T>
std::pair<typename BinaryTree<Key, T>::iterator, bool>
BinaryTree<Key, T>::insert_or_assign(const Key& key, const T& obj) {
  std::pair<typename BinaryTree<Key, T>::iterator, bool> res =
      find_or_create(key);
  res.first->value_ = obj;
  return res;
}

template <typename Key, typename T>
std::pair<typename BinaryTree<Key, T>::iterator, bool>
BinaryTree<Key, T>::insert(const Key& key, const T& obj) {
  bool flag = true;
  iterator i = root_;
  if (root_) {
    while (i.ptr_ != end_.ptr_) {
      if (key < i.ptr_->key_) {
        if (i.ptr_->left_) {
          i = i.step_left();
        } else {
          i = i.create_sub_node(key, false);
          i.ptr_->value_ = obj;
          break;
        }
      } else if (key > i.ptr_->key_) {
        if (i.ptr_->right_ && i.ptr_->right_ != end_) {
          i = i.step_right();
        } else {
          i = i.create_sub_node(key, true);
          i.ptr_->value_ = obj;
          break;
        }
      } else {
        flag = false;
        i.ptr_->value_ = obj;
        break;
      }
    }
  } else {
    root_ = new Node(key, obj);
    i.ptr_ = root_;
  }
  if (flag) {
    update(i);
  } else {
    i.ptr_ = i.ptr_->head_;
  }
  return std::pair<typename BinaryTree<Key, T>::iterator, bool>(i, flag);
}

template <typename Key, typename T>
std::pair<typename BinaryTree<Key, T>::iterator, bool>
BinaryTree<Key, T>::insert(const value_type& value) {
  return std::pair<typename BinaryTree<Key, T>::iterator, bool>(
      insert(value.first, value.second));
}

template <typename Key, typename T>
void BinaryTree<Key, T>::update(iterator iter) {
  size_++;
  if (begin_) {
    if (iter.ptr_->key_ < begin_.ptr_->key_) begin_ = iter;
  } else {
    begin_ = iter;
  }

  if (end_) {
    if (end_.ptr_->head_) {
      if (iter.ptr_->key_ > end_.ptr_->head_->key_) {
        end_.ptr_->head_->right_ = iter;
        iter.ptr_->right_ = end_;
        end_.ptr_->head_ = iter;
      }
    } else {
      end_.ptr_->head_ = iter.ptr_;
      iter.ptr_->right_ = end_.ptr_;
    }
  } else {
    end_ = new Node();
    end_.ptr_->head_ = begin_;
    begin_.ptr_->right_ = end_;
  }
}

template <typename Key, typename T>
void BinaryTree<Key, T>::erase(iterator pos) {
  if (pos.ptr_->head_) {
    erase_node(pos);
  } else {
    erase_root(pos);
  }
  erase_update(pos);
}

template <typename Key, typename T>
void BinaryTree<Key, T>::erase_node(iterator pos) {
  int cnt = children_location(pos);
  if (cnt == 2) {
    if (pos.ptr_->head_->left_ == pos.ptr_) {
      erase_two_child(pos, 0);
    } else {
      erase_two_child(pos, 1);
    }
  } else if (cnt == 0) {
    if (pos.ptr_->head_->left_ == pos.ptr_) {
      erase_no_child(pos, 0);
    } else {
      erase_no_child(pos, 1);
    }
  } else if (cnt == -1) {
    erase_one_child(pos, 0);
  } else {
    erase_one_child(pos, 1);
  }
}

template <typename Key, typename T>
void BinaryTree<Key, T>::erase_update(iterator iter) {
  if (iter == begin_) begin_.ptr_ = iter.ptr_->head_;
  if (!root_) {
    delete end_;
    end_ = nullptr;
  }
  delete iter.ptr_;
  size_--;
}

template <typename Key, typename T>
void BinaryTree<Key, T>::erase_one_child(iterator iter, bool flag) {
  // flag сообщает, слева или справа находится удаляемая точка от ее родителя!
  if (flag) {
    if (iter.ptr_->right_) {
      iter.ptr_->head_->right_ = iter.ptr_->right_;
      iter.ptr_->right_->head_ = iter.ptr_->head_;
    } else {
      iter.ptr_->head_->right_ = iter.ptr_->left_;
      iter.ptr_->left_->head_ = iter.ptr_->head_;
    }
  } else {
    if (iter.ptr_->right_) {
      iter.ptr_->head_->left_ = iter.ptr_->right_;
      iter.ptr_->right_->head_ = iter.ptr_->head_;
    } else {
      iter.ptr_->head_->left_ = iter.ptr_->left_;
      iter.ptr_->left_->head_ = iter.ptr_->head_;
    }
  }
}

template <typename Key, typename T>
void BinaryTree<Key, T>::erase_two_child(iterator iter, bool flag) {
  iterator tmp;
  if (flag) {
    iter.ptr_->head_->right_ = iter.ptr_->left_;
    iter.ptr_->left_->head_ = iter.ptr_->head_;
    tmp = iterator(iter.ptr_->left_).right_edge();
    tmp.ptr_->right_ = iter.ptr_->right_;
    iter.ptr_->right_->head_ = tmp.ptr_;
  } else {
    iter.ptr_->head_->left_ = iter.ptr_->right_;
    iter.ptr_->right_->head_ = iter.ptr_->head_;
    tmp = iterator(iter.ptr_->right_).left_edge();
    tmp.ptr_->left_ = iter.ptr_->left_;
    iter.ptr_->left_->head_ = tmp.ptr_;
  }
}

template <typename Key, typename T>
void BinaryTree<Key, T>::erase_no_child(iterator iter, bool flag) {
  if (flag) {
    iter.ptr_->head_->right_ = nullptr;
  } else {
    iter.ptr_->head_->left_ = nullptr;
  }
}

template <typename Key, typename T>
void BinaryTree<Key, T>::erase_root(iterator iter) {
  if (iter.ptr_->left_ && iter.ptr_->right_ && iter.ptr_->right_ != end_.ptr_) {
    root_ = iter.ptr_->right_;
    iter.ptr_->right_->head_ = nullptr;
    iterator tmp = iterator(iter.ptr_->right_).left_edge();
    tmp.ptr_->left_ = iter.ptr_->left_;
    iter.ptr_->left_->head_ = tmp.ptr_;
  } else if (iter.ptr_->left_) {
    root_ = iter.ptr_->left_;
    iter.ptr_->left_->head_ = nullptr;
    if (iter.ptr_->right_ == end_.ptr_) {
      end_.ptr_->head_ = root_;
      root_.ptr_->right_ = end_;
    }
  } else if (iter.ptr_->right_ && iter.ptr_->right_ != end_.ptr_) {
    root_ = iter.ptr_->right_;
    iter.ptr_->right_->head_ = nullptr;
  } else {
    root_ = nullptr;
  }
}

template <typename Key, typename T>
std::pair<typename BinaryTree<Key, T>::iterator, bool> BinaryTree<Key, T>::find(
    const Key& key) const {
  bool flag = false;
  auto i = root_;
  while (i && i != end_) {
    if (key < i.ptr_->key_) {
      if (i.ptr_->left_) {
        i = i.step_left();
      } else {
        break;
      }
    } else if (key > i.ptr_->key_) {
      if (i.ptr_->right_) {
        i = i.step_right();
      } else {
        break;
      }
    } else {
      flag = true;
      break;
    }
  }
  return std::pair<typename BinaryTree<Key, T>::iterator, bool>(i, flag);
}

template <typename Key, typename T>
void BinaryTree<Key, T>::merge(BinaryTree& other) {
  std::pair<typename BinaryTree<Key, T>::iterator, bool> tmp;
  auto i = other.begin();
  iterator tmp_i = nullptr;
  while (i != other.end()) {
    tmp = find(i.ptr_->key_);
    if (!tmp.second) {
      tmp_i = i.next();
      other.merge_update(i);
      if (i != other.root_) {
        if (i.ptr_->key_ > tmp.first->key_) {
          extract(i, tmp.first, 1);
        } else {
          extract(i, tmp.first, 0);
        }
      } else {
        if (i.ptr_->key_ > tmp.first->key_) {
          extract_root(i, tmp.first, other, 1);
        } else {
          extract_root(i, tmp.first, other, 0);
        }
      }
      update(tmp.first);
      i = tmp_i;
    } else {
      i++;
    }
  }
  if (!other.root_) {
    delete other.end_;
    other.end_ = nullptr;
  }
}

template <typename Key, typename T>
void BinaryTree<Key, T>::extract(iterator from, iterator to, bool flag) {
  erase_node(from);
  splice(from, to, flag);
}

template <typename Key, typename T>
void BinaryTree<Key, T>::splice(iterator from, iterator to, bool flag) {
  if (flag) {
    to.ptr_->right_ = from;
    from.ptr_->head_ = to;
  } else {
    to.ptr_->left_ = from;
    from.ptr_->head_ = to;
  }
  from.ptr_->left_ = nullptr;
  from.ptr_->right_ = nullptr;
}

template <typename Key, typename T>
void BinaryTree<Key, T>::extract_root(iterator from, iterator to,
                                      BinaryTree& other, bool flag) {
  other.erase_root(other.root_);
  splice(from, to, flag);
}

template <typename Key, typename T>
int BinaryTree<Key, T>::children_location(iterator pos) {
  int cnt;
  if (pos.ptr_->left_ && pos.ptr_->right_) {
    cnt = 2;
  } else if (pos.ptr_->left_) {
    cnt = -1;
  } else if (pos.ptr_->right_) {
    cnt = 1;
  } else {
    cnt = 0;
  }
  return cnt;
}

template <typename Key, typename T>
void BinaryTree<Key, T>::merge_update(iterator pos) {
  if (pos == begin_) begin_.ptr_ = pos.next();
  size_--;
}

template <typename Key, typename T>
void BinaryTree<Key, T>::swap(BinaryTree& other) {
  BinaryTree* tmp = new BinaryTree;
  tmp->root_ = this->root_;
  tmp->begin_ = this->begin_;
  tmp->end_ = this->end_;
  tmp->size_ = this->size_;
  this->root_ = other.root_;
  this->begin_ = other.begin_;
  this->end_ = other.end_;
  this->size_ = other.size_;
  other.root_ = tmp->root_;
  other.begin_ = tmp->begin_;
  other.end_ = tmp->end_;
  other.size_ = tmp->size_;
  tmp->root_ = nullptr;
  tmp->begin_ = nullptr;
  tmp->end_ = nullptr;
  tmp->size_ = 0;
  delete tmp;
}

template <typename Key, typename T>
template <typename... Args>
std::vector<std::pair<typename BinaryTree<Key, T>::iterator, bool>>
BinaryTree<Key, T>::insert_many(Args&&... args) {
  std::vector<std::pair<typename BinaryTree<Key, T>::iterator, bool>> res;
  for (auto i : {args...}) res.push_back(insert(i));
  return res;
}

// iterators

template <typename Key, typename T>
BinaryTree<Key, T>::iterator::iterator() {
  ptr_ = nullptr;
}

template <typename Key, typename T>
BinaryTree<Key, T>::iterator::iterator(Node* ptr) {
  ptr_ = ptr;
}

template <typename Key, typename T>
typename BinaryTree<Key, T>::Node* BinaryTree<Key, T>::iterator::operator->() {
  return ptr_;
}

// Note: function makes only a down to the left step. Use
// it only from the root node!
template <typename Key, typename T>
typename BinaryTree<Key, T>::iterator
BinaryTree<Key, T>::iterator::step_left() {
  return iterator(ptr_->left_);
}

template <typename Key,
          typename T>  // Note: function makes only a up to the right step. Use
                       // it only from the root node!
typename BinaryTree<Key, T>::iterator
BinaryTree<Key, T>::iterator::step_right() {
  return iterator(ptr_->right_);
}

template <typename Key, typename T>
typename BinaryTree<Key, T>::iterator BinaryTree<Key, T>::iterator::step_up() {
  return iterator(ptr_->head_);
}

template <typename Key, typename T>
typename BinaryTree<Key, T>::iterator
BinaryTree<Key, T>::iterator::left_edge() {
  iterator res = *this;
  iterator tmp = *this;
  while (true) {
    tmp = res.step_left();
    if (tmp) {
      res = tmp;
    } else {
      return res;
    }
  }
}

template <typename Key, typename T>
typename BinaryTree<Key, T>::iterator
BinaryTree<Key, T>::iterator::right_edge() {
  iterator res = *this;
  iterator tmp = *this;
  while (true) {
    tmp = res.step_right();
    if (tmp) {
      res = tmp;
    } else {
      return res;
    }
  }
}

template <typename Key, typename T>
typename BinaryTree<Key, T>::iterator BinaryTree<Key, T>::iterator::prev() {
  iterator iter(ptr_);
  if (iter->left_) {
    iter = iter.step_left();
    iter = iter.right_edge();
  } else {
    if (iter->head_->left_ == iter) {
      iter = iter.step_up();
      iter = iter.step_up();
    } else {
      iter = iter.step_up();
    }
  }
  return iter;
}

template <typename Key, typename T>
typename BinaryTree<Key, T>::iterator BinaryTree<Key, T>::iterator::next() {
  iterator iter(ptr_);
  if (iter->right_) {
    iter = iter.step_right();
    iter = iter.left_edge();
  } else {
    if (iter->head_->right_ == iter) {
      iter = iter.step_up();
      iter = iter.step_up();
    } else {
      iter = iter.step_up();
    }
  }
  return iter;
}

template <typename Key, typename T>
typename BinaryTree<Key, T>::iterator&
BinaryTree<Key, T>::iterator::operator--() {
  *this = this->prev();
  return *this;
}

template <typename Key, typename T>
typename BinaryTree<Key, T>::iterator&
BinaryTree<Key, T>::iterator::operator++() {
  *this = this->next();
  return *this;
}

template <typename Key, typename T>
typename BinaryTree<Key, T>::iterator BinaryTree<Key, T>::iterator::operator--(
    int) {
  iterator res = *this;
  --*this;
  return res;
}

template <typename Key, typename T>
typename BinaryTree<Key, T>::iterator BinaryTree<Key, T>::iterator::operator++(
    int) {
  iterator res = *this;
  ++*this;
  return res;
}

template <typename Key, typename T>
// typename BinaryTree<Key, T>::iterator BinaryTree<Key,
// T>::iterator::create_sub_node(Key key, T value, bool flag) {
typename BinaryTree<Key, T>::iterator
BinaryTree<Key, T>::iterator::create_sub_node(Key key, bool flag) {
  // iterator res = new Node(key, value);
  iterator res = new Node();
  res.ptr_->key_ = key;
  res.ptr_->head_ = ptr_;
  if (flag) {
    ptr_->right_ = res;
  } else {
    ptr_->left_ = res;
  }
  return res;
}

template <typename Key, typename T>
typename BinaryTree<Key, T>::iterator BinaryTree<Key, T>::iterator::copy()
    const {
  iterator res = new Node;
  if (ptr_->left_) {
    res.ptr_->left_ = iterator(ptr_->left_).copy();
    res.ptr_->left_->head_ = res;
  }
  if (ptr_->right_) {
    res.ptr_->right_ = iterator(ptr_->right_).copy();
    res.ptr_->right_->head_ = res;
  }
  res.ptr_->key_ = ptr_->key_;
  res.ptr_->value_ = ptr_->value_;
  return res;
}

};  // namespace s21
