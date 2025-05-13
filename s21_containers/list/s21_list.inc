namespace s21 {

template <class T>
struct list<T>::ListIterator {
  friend class list;

  using iterator_category = std::bidirectional_iterator_tag;
  using difference_type = std::ptrdiff_t;
  using value_type = T;
  using pointer = T*;
  using reference = T&;

  iterator& operator++() noexcept {
    node = node->next;
    return *this;
  }

  iterator operator++(int) noexcept {
    iterator dummy{node};
    operator++();
    return dummy;
  }

  iterator& operator--() noexcept {
    node = node->prev;
    return *this;
  }

  iterator operator--(int) noexcept {
    iterator dummy{node};
    operator--();
    return dummy;
  }

  pointer operator->() noexcept { return node->data; }

  reference operator*() noexcept { return *(operator->()); }

  bool operator==(const iterator& rhs) const noexcept {
    return this->node == rhs.node;
  }

  bool operator!=(const iterator& rhs) const noexcept {
    return !(*this == rhs);
  }

 private:
  Node* node;

  explicit ListIterator(Node* ptr) noexcept : node{ptr} {}
  explicit ListIterator(const ListConstIterator& iterator)
      : node{iterator.node} {}
};

template <class T>
struct list<T>::ListConstIterator {
  friend class list;

  using iterator_category = std::bidirectional_iterator_tag;
  using difference_type = std::ptrdiff_t;
  using value_type = T;
  using pointer = const T*;
  using reference = const T&;

  ListConstIterator(const ListIterator& iterator) : node{iterator.node} {}

  const const_iterator& operator++() noexcept {
    node = node->next;
    return *this;
  }

  const_iterator operator++(int) noexcept {
    const_iterator dummy{node};
    operator++();
    return dummy;
  }

  const const_iterator& operator--() noexcept {
    node = node->prev;
    return *this;
  }

  const_iterator operator--(int) noexcept {
    const_iterator dummy{node};
    operator--();
    return dummy;
  }

  pointer operator->() const noexcept { return node->data; }

  const_reference operator*() const noexcept { return *(operator->()); }

  bool operator==(const const_iterator& rhs) const noexcept {
    return this->node == rhs.node;
  }

  bool operator!=(const const_iterator& rhs) const noexcept {
    return !(*this == rhs);
  }

 private:
  Node* node;

  explicit ListConstIterator(Node* ptr) noexcept : node{ptr} {}
};

template <class T>
struct list<T>::Node {
  Node* prev;
  Node* next;
  value_type* data{new value_type{}};

  Node() = default;

  explicit Node(const_reference ref) : data{new value_type{ref}} {}

  Node(value_type* data, Node* prev) : prev{prev}, data{data} {}
  Node(value_type* data, Node* prev, Node* next)
      : prev{prev}, next{next}, data{data} {}

  ~Node() { delete data; }

  static Node* Split(Node* head) {
    Node* fast{head};
    Node* slow{head};

    while (fast != nullptr and fast->next != nullptr and
           fast->next->next != nullptr) {
      fast = fast->next->next;
      slow = slow->next;
    }

    Node* temp{slow->next};
    slow->next = nullptr;
    if (temp != nullptr) temp->prev = nullptr;
    return temp;
  }

  static void SetPointers(Node* lhs, Node* rhs) {
    lhs->next = rhs;
    rhs->prev = lhs;
  }

  static Node* Merge(Node* lhs, Node* rhs) {
    Node dummy{nullptr, nullptr, nullptr};
    Node* ptr{&dummy};

    while (lhs != nullptr and rhs != nullptr) {
      if (rhs->data != nullptr and *rhs->data < *lhs->data) {
        SetPointers(ptr, rhs);
        rhs = rhs->next;
      } else {
        SetPointers(ptr, lhs);
        lhs = lhs->next;
      }
      ptr = ptr->next;
    }
    if (lhs != nullptr) SetPointers(ptr, lhs);
    if (rhs != nullptr) SetPointers(ptr, rhs);

    return dummy.next;
  }

  static Node* MergeSort(Node* head) {
    if (head == nullptr or head->next == nullptr) return head;

    Node* second{Split(head)};
    head = MergeSort(head);
    second = MergeSort(second);
    return Merge(head, second);
  }
};

template <class T>
list<T>::list()
    : head_{new Node{nullptr, nullptr}},
      tail_{new Node{nullptr, head_}},
      size_{0} {
  head_->next = tail_;
  tail_->next = nullptr;
}

template <class T>
list<T>::list(size_type n) : list() {
  size_ = n;
  while (n--) NodeInsertAfter(head_, new Node{});
}

template <class T>
list<T>::list(std::initializer_list<value_type> const& items) : list<T>() {
  for (const auto& i : items) push_back(i);
}

template <class T>
list(std::initializer_list<T>) -> list<T>;

template <class T>
list<T>::list(const list& other) : list<T>() {
  for (const_iterator i{other.begin()}; i != other.end(); ++i) push_back(*i);
}

template <class T>
list<T>::list(list&& other) noexcept
    : head_{other.head_}, tail_{other.tail_}, size_{other.size_} {
  other.head_ = other.tail_ = nullptr;
}

template <class T>
list<T>::~list() noexcept {
  while (head_ != nullptr) {
    Node* ptr{head_};
    head_ = head_->next;
    delete ptr;
  }
}

template <class T>
list<T>& list<T>::operator=(const list& rhs) {
  list(rhs).swap(*this);
  return *this;
}

template <class T>
list<T>& list<T>::operator=(list&& rhs) noexcept {
  list(rhs).swap(*this);
  return *this;
}

template <class T>
typename list<T>::const_reference list<T>::front() noexcept {
  return *(head_->next->data);
}

template <class T>
typename list<T>::const_reference list<T>::back() noexcept {
  return *(tail_->prev->data);
}

template <class T>
typename list<T>::iterator list<T>::begin() noexcept {
  return iterator(head_->next);
}

template <class T>
typename list<T>::iterator list<T>::end() noexcept {
  return iterator(tail_);
}

template <class T>
typename list<T>::const_iterator list<T>::begin() const noexcept {
  return const_iterator(head_->next);
}

template <class T>
typename list<T>::const_iterator list<T>::end() const noexcept {
  return const_iterator(tail_);
}

template <class T>
bool list<T>::empty() const noexcept {
  return size_ == 0;
}

template <class T>
typename list<T>::size_type list<T>::size() const noexcept {
  return size_;
}

template <class T>
typename list<T>::size_type list<T>::max_size() const noexcept {
  return 0;
}

template <class T>
void list<T>::clear() noexcept {
  for (const_iterator it{begin()}; it != end();) {
    Node* ptr{it.node};
    ++it;
    delete ptr;
  }
  Node::SetPointers(head_, tail_);
  size_ = 0;
}

template <class T>
typename list<T>::iterator list<T>::insert(iterator pos,
                                           const_reference value) {
  NodeInsertBefore(pos.node, new Node{value});
  ++size_;
  return --pos;
}

template <class T>
void list<T>::erase(iterator pos) noexcept {
  NodeRemove(pos.node);
  --size_;
}

template <class T>
void list<T>::push_back(const_reference value) {
  NodeInsertBefore(tail_, new Node{value});
  ++size_;
}

template <class T>
void list<T>::pop_back() noexcept {
  NodeRemove(tail_->prev);
  --size_;
}

template <class T>
void list<T>::push_front(const_reference value) {
  NodeInsertAfter(head_, new Node{value});
  ++size_;
}

template <class T>
void list<T>::pop_front() noexcept {
  NodeRemove(head_->next);
  --size_;
}

template <class T>
void list<T>::swap(list& other) noexcept {
  if (this != &other) {
    std::swap(head_, other.head_);
    std::swap(tail_, other.tail_);
    std::swap(size_, other.size_);
  }
}

template <class T>
void list<T>::merge(list& other) {
  if (this != &other) {
    if (this->empty()) {
      this->splice(this->begin(), other);
    } else if (!other.empty()) {
      list<T> dummy;
      dummy.size_ = this->size_ + other.size_;
      other.size_ = 0;
      Node* current{dummy.head_};
      const_iterator lhs_pos{this->begin()};
      const_iterator rhs_pos{other.begin()};
      const_iterator lhs_end{this->end()};
      const_iterator rhs_end{other.end()};
      while (lhs_pos != lhs_end and rhs_pos != rhs_end) {
        if (*rhs_pos < *lhs_pos) {
          Node::SetPointers(current, (rhs_pos++).node);
        } else {
          Node::SetPointers(current, (lhs_pos++).node);
        }
        current = current->next;
      }
      Node::SetPointers(current, dummy.tail_);
      Node::SetPointers(this->head_, lhs_pos.node);
      Node::SetPointers(other.head_, rhs_pos.node);
      if (lhs_pos != lhs_end) {
        Splice(dummy.end(), lhs_pos, lhs_end);
      } else if (rhs_pos != rhs_end) {
        Splice(dummy.end(), rhs_pos, rhs_end);
      }
      this->swap(dummy);
    }
  }
}

template <typename T>
void list<T>::Splice(const_iterator pos, const_iterator first,
                     const_iterator last) noexcept {
  pos.node->prev->next = first.node;
  first.node->prev->next = last.node;
  last.node->prev->next = pos.node;

  Node* dummy{pos.node->prev};
  pos.node->prev = last.node->prev;
  last.node->prev = first.node->prev;
  first.node->prev = dummy;
}

template <class T>
void list<T>::splice(const_iterator pos, list& other) noexcept {
  if (!other.empty()) {
    Splice(pos, other.begin(), other.end());
    this->size_ += other.size_;
    other.size_ = 0;
  }
}

template <class T>
void list<T>::splice(const_iterator pos, list& other, const_iterator first,
                     const_iterator last) noexcept {
  if (first != last) {
    size_type counter{0};
    for (const_iterator i{first}; i != last; ++i) ++counter;

    Splice(pos, first, last);
    this->size_ += counter;
    other.size_ -= counter;
  }
}

template <class T>
void list<T>::reverse() noexcept {
  if (size_ > 1) {
    Node* prev{nullptr};
    tail_ = head_;

    for (Node* current{head_}; current != nullptr;) {
      prev = current->prev;
      current->prev = current->next;
      current->next = prev;
      current = current->prev;
    }
    head_ = prev->prev;
  }
}

template <class T>
void list<T>::unique() {
  if (!empty()) {
    const_iterator i{begin()};
    const_iterator current{i};
    while (++i != end()) {
      if (*current == *i) {
        NodeRemove(i.node);
        i = current;
        --size_;
      } else {
        current = i;
      }
    }
  }
}

template <class T>
void list<T>::sort() {
  if (size_ > 1) {
    head_->next = Node::MergeSort(head_->next);
    head_->next->prev = head_;
  }
}

template <class T>
void list<T>::NodeInsertBefore(Node* spot, Node* node) {
  NodeInsertAfter(spot->prev, node);
}

template <class T>
void list<T>::NodeInsertAfter(Node* spot, Node* node) {
  node->prev = spot;
  node->next = spot->next;
  spot->next->prev = node;
  spot->next = node;
}

template <class T>
void list<T>::NodeRemove(Node* node) {
  node->prev->next = node->next;
  node->next->prev = node->prev;
  delete node;
}

template <class T>
template <class... Args>
typename list<T>::iterator list<T>::insert_many(const_iterator pos,
                                                Args&&... args) {
  if (sizeof...(args) == 0) return iterator{pos};

  list other{args...};
  iterator ret{other.begin()};
  splice(pos, other);
  return ret;
}

template <class T>
template <class... Args>
void list<T>::insert_many_back(Args&&... args) {
  list other{args...};
  splice(end(), other);
}

template <class T>
template <class... Args>
void list<T>::insert_many_front(Args&&... args) {
  list other{args...};
  splice(begin(), other);
}

};  // namespace s21
