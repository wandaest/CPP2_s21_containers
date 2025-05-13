#include "s21_vector.h"

namespace s21 {
// Functions
template <typename T>
vector<T>::vector() : values_(nullptr), size_(0), capacity_(0) {}

template <typename T>
vector<T>::vector(size_type n) : size_{n}, capacity_{n} {
  values_ = reinterpret_cast<value_type *>(
      new int8_t[capacity_ * sizeof(value_type)]);
  size_type i = 0;
  try {
    for (; i < n; ++i) {
      new (values_ + i) value_type();
    }
  } catch (...) {
    for (size_type j = i; j > 0; --j) {
      (values_ + j - 1)->~T();
    }
    delete[] reinterpret_cast<int8_t *>(values_);
    throw;
  }
}

template <typename T>
vector<T>::vector(std::initializer_list<value_type> const &items)
    : vector(items.size()) {
  size_type i = 0;
  for (const auto &item : items) {
    values_[i++] = item;
  }
  size_ = items.size();
}

template <typename T>
vector<T>::vector(const vector &v)
    : values_(new value_type[v.capacity_]),
      size_(v.size_),
      capacity_(v.capacity_) {
  std::copy(v.values_, v.values_ + v.size_, values_);
}

template <typename T>
vector<T>::vector(vector &&v) : size_(v.size_), capacity_(v.capacity_) {
  values_ = std::move(v.values_);
  v.values_ = nullptr;
  v.size_ = 0;
}

template <typename T>
vector<T> &vector<T>::operator=(vector<T> &&v) {
  if (this != &v) {
    clear();
    delete[] reinterpret_cast<int8_t *>(values_);
    values_ = v.values_;
    size_ = v.size_;
    capacity_ = v.capacity_;
    v.values_ = nullptr;
    v.size_ = 0;
  }
  return *this;
}

template <typename T>
vector<T> &vector<T>::operator=(const vector &other) {
  if (this != &other) {
    vector temp(other);
    *this = std::move(temp);
  }
  return *this;
}

template <typename T>
vector<T>::~vector() {
  clear();
  delete[] reinterpret_cast<int8_t *>(values_);
}

// Element access
template <typename T>
typename vector<T>::reference vector<T>::at(size_type pos) {
  if (pos < size_) return values_[pos];
  throw std::out_of_range("Index out range");
}

template <typename T>
typename vector<T>::reference vector<T>::operator[](size_type pos) {
  return values_[pos];
}

template <typename T>
typename vector<T>::const_reference vector<T>::front() {
  return values_[0];
}

template <typename T>
typename vector<T>::const_reference vector<T>::back() const {
  return values_[size_ - 1];
}

template <typename T>
typename vector<T>::iterator vector<T>::data() {
  return values_;
}

// Iterators
template <typename T>
typename vector<T>::iterator vector<T>::begin() {
  return values_;
}

template <typename T>
typename vector<T>::iterator vector<T>::end() {
  return values_ + size_;
}

// Capacity
template <typename T>
bool vector<T>::empty() const {
  return size_ == 0;
}

template <typename T>
typename vector<T>::size_type vector<T>::size() const {
  return size_;
}

template <typename T>
typename vector<T>::size_type vector<T>::max_size() {
  return std::numeric_limits<size_type>::max() / sizeof(value_type) / 2;
}

template <typename T>
void vector<T>::reserve(size_type size) {
  if (size > capacity_) {
    value_type *newValues =
        reinterpret_cast<value_type *>(new int8_t[size * sizeof(value_type)]);
    try {
      for (size_type i = 0; i < size_; ++i) {
        new (newValues + i) value_type(std::move(values_[i]));
        values_[i].~T();
      }
      delete[] reinterpret_cast<int8_t *>(values_);
      values_ = newValues;
      capacity_ = size;
    } catch (...) {
      delete[] reinterpret_cast<int8_t *>(newValues);
      throw;
    }
  }
}

template <typename T>
typename vector<T>::size_type vector<T>::capacity() {
  return capacity_;
}

template <typename T>
void vector<T>::shrink_to_fit() {
  if (size_ < capacity_) {
    value_type *newValues =
        reinterpret_cast<value_type *>(new int8_t[size_ * sizeof(value_type)]);
    try {
      for (size_type i = 0; i < size_; ++i) {
        new (newValues + i) value_type(std::move(values_[i]));
        values_[i].~T();
      }
      delete[] reinterpret_cast<int8_t *>(values_);
      values_ = newValues;
      capacity_ = size_;
    } catch (...) {
      delete[] reinterpret_cast<int8_t *>(newValues);
      throw;
    }
  }
}

// Modifiers
template <typename T>
void vector<T>::clear() {
  for (size_type i = 0; i < size_; ++i) {
    (values_ + i)->~T();
  }
  size_ = 0;
}

template <typename T>
typename vector<T>::iterator vector<T>::insert(iterator pos,
                                               const_reference value) {
  vector<value_type> newVector(size_ + 1);
  size_type j = 0;
  size_type position = pos - this->begin();
  for (size_type i = 0; i < newVector.size_; ++i) {
    if (i == position) {
      newVector.values_[i] = value;
    } else {
      newVector.values_[i] = values_[j++];
    }
  }
  *this = std::move(newVector);
  return values_ + position;
}

template <typename T>
void vector<T>::erase(iterator pos) {
  std::copy(pos + 1, end(), pos);
  --size_;
}

template <typename T>
void vector<T>::push_back(const_reference value) {
  if (size_ < capacity_) {
    new (values_ + size_) value_type(value);
    ++size_;
  } else {
    size_type new_capacity = (capacity_ == 0) ? 1 : capacity_ * 2;
    vector<value_type> newVector(new_capacity);

    size_type &i = newVector.size_;
    for (i = 0; i != size_; ++i) {
      newVector.values_[i] = std::move(values_[i]);
    }
    newVector.values_[i] = value;
    ++i;
    *this = std::move(newVector);
  }
}

template <typename T>
void vector<T>::pop_back() {
  values_[--size_].~value_type();
}

template <typename T>
void vector<T>::swap(vector &other) {
  std::swap(values_, other.values_);
  std::swap(size_, other.size_);
  std::swap(capacity_, other.capacity_);
}

template <class T>
vector(std::initializer_list<T>) -> vector<T>;

template <typename T>
template <typename... Args>
typename vector<T>::iterator vector<T>::insert_many(const_iterator pos,
                                                    Args &&...args) {
  if constexpr (sizeof...(args) > 0) {
    const auto position{pos - begin()};
    const size_type elements{size_ + sizeof...(args)};

    if (capacity_ < elements) reserve(elements);

    iterator current{begin() + position};
    if (size_ != 0) {
      iterator l{values_ + size_}, r{values_ + elements};
      do {
        new (--r) value_type(*--l);
      } while (l != current);
    }

    for (const auto &i : {args...}) {
      new (current) value_type(i);
      ++current;
    }
    size_ = elements;

    return values_ + position;
  }

  return const_cast<iterator>(pos);
}

template <typename T>
template <typename... Args>
void vector<T>::insert_many_back(Args &&...args) {
  if constexpr (sizeof...(args) > 0)
    for (const auto &i : {args...}) push_back(i);
}

}  // namespace s21
