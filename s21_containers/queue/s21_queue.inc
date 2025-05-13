namespace s21 {

template <class T>
queue(std::initializer_list<T>) -> queue<T>;

template <class T>
queue<T> &queue<T>::operator=(const queue &rhs) {
  queue(rhs).swap(*this);
  return *this;
}

template <class T>
queue<T> &queue<T>::operator=(queue &&rhs) noexcept {
  queue(rhs).swap(*this);
  return *this;
}

template <class T>
typename queue<T>::const_reference queue<T>::front() noexcept {
  return c_.front();
}

template <class T>
typename queue<T>::const_reference queue<T>::back() noexcept {
  return c_.back();
}

template <class T>
bool queue<T>::empty() const noexcept {
  return c_.empty();
}

template <class T>
typename queue<T>::size_type queue<T>::size() const noexcept {
  return c_.size();
}

template <class T>
void queue<T>::push(const_reference value) {
  c_.push_back(value);
}

template <class T>
void queue<T>::pop() {
  c_.pop_front();
}

template <class T>
void queue<T>::swap(queue &other) noexcept {
  if (this != &other) std::swap(c_, other.c_);
}

template <class T>
template <class... Args>
void queue<T>::insert_many_back(Args &&...args) {
  c_.insert_many_back(args...);
}

}  // namespace s21
