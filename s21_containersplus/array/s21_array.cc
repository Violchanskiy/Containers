#include "s21_array.h"

namespace s21 {
template <typename T, size_t N>
array<T, N>::array() noexcept : size_(N) {}

template <typename T, size_t N>
array<T, N>::array(const array &a) noexcept : array() {
  CopyArray(a);
}

template <typename T, size_t N>
array<T, N>::array(std::initializer_list<value_type> const &items) : array() {
  if (items.size() > N)
    throw std::out_of_range("Too many initializers for array");
  std::copy(items.begin(), items.end(), arr_);
}

template <typename T, size_t N>
array<T, N>::array(array &&a) noexcept : array() {
  CopyArray(a);
}

template <typename T, size_t N>
array<T, N> array<T, N>::operator=(const array &a) noexcept {
  CopyArray(a);
  return *this;
}

template <typename T, size_t N>
array<T, N> &array<T, N>::operator=(array &&a) noexcept {
  CopyArray(a);
  return *this;
}

template <typename T, size_t N>
typename array<T, N>::reference array<T, N>::operator[](
    size_type pos) noexcept {
  return arr_[pos];
}

template <typename T, size_t N>
typename array<T, N>::const_reference array<T, N>::operator[](
    size_type pos) const noexcept {
  return arr_[pos];
}

template <typename T, size_t N>
typename array<T, N>::reference array<T, N>::at(size_type pos) {
  if (pos >= size_) {
    throw std::out_of_range("Index out of range");
  }
  return arr_[pos];
}

template <typename T, size_t N>
typename array<T, N>::const_reference array<T, N>::at(size_type pos) const {
  if (pos >= size_) {
    throw std::out_of_range("Index out of range");
  }
  return arr_[pos];
}

template <typename T, size_t N>
void array<T, N>::swap(array &other) noexcept {
  std::swap(arr_, other.arr_);
}

template <typename T, size_t N>
bool array<T, N>::empty() const noexcept {
  return size_ == 0;
}

template <typename T, size_t N>
typename array<T, N>::const_reference array<T, N>::front() const {
  return arr_[0];
}

template <typename T, size_t N>
typename array<T, N>::const_reference array<T, N>::back() const {
  return arr_[N - 1];
}

template <typename T, size_t N>
typename array<T, N>::iterator array<T, N>::begin() noexcept {
  return arr_;
}
template <typename T, size_t N>
typename array<T, N>::iterator array<T, N>::end() noexcept {
  return arr_ + N;
}

template <typename T, size_t N>
typename array<T, N>::const_iterator array<T, N>::cbegin() const noexcept {
  return arr_;
}

template <typename T, size_t N>
typename array<T, N>::const_iterator array<T, N>::cend() const noexcept {
  return arr_ + N;
}

template <typename T, size_t N>
typename array<T, N>::iterator array<T, N>::data() noexcept {
  return arr_;
}
template <typename T, size_t N>
typename array<T, N>::const_iterator array<T, N>::data() const noexcept {
  return arr_;
}

template <typename T, size_t N>
typename array<T, N>::size_type array<T, N>::size() const noexcept {
  return size_;
}

template <typename T, size_t N>
typename array<T, N>::size_type array<T, N>::max_size() const noexcept {
  return size_;
}

template <typename T, size_t N>
void array<T, N>::fill(const_reference value) {
  std::fill(arr_, arr_ + N, value);
}

template <typename T, size_t N>
void array<T, N>::CopyArray(const array &a) noexcept {
  for (size_type i = 0; i < size_; i++) {
    arr_[i] = a.arr_[i];
  }
}
}  // namespace s21
