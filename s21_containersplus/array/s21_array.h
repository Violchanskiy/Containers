#ifndef SRC_S21_CONTAINERSPLUS_ARRAY_S21_ARRAY_H_
#define SRC_S21_CONTAINERSPLUS_ARRAY_S21_ARRAY_H_

#include <initializer_list>
#include <stdexcept>

namespace s21 {
template <typename T, size_t N>

class array {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = T *;
  using const_iterator = const T *;
  using size_type = size_t;

  array() noexcept;
  array(std::initializer_list<value_type> const &items);
  array(const array &a) noexcept;
  array(array &&a) noexcept;
  ~array() = default;

  array operator=(const array &a) noexcept;
  array &operator=(array<T, N> &&a) noexcept;

  reference at(size_type pos);
  const_reference at(size_type pos) const;
  reference operator[](size_type pos) noexcept;
  const_reference operator[](size_type pos) const noexcept;
  const_reference front() const;
  const_reference back() const;

  iterator data() noexcept;
  const_iterator data() const noexcept;

  iterator begin() noexcept;
  iterator end() noexcept;
  const_iterator cbegin() const noexcept;
  const_iterator cend() const noexcept;

  bool empty() const noexcept;
  size_type size() const noexcept;
  size_type max_size() const noexcept;

  void swap(array &other) noexcept;
  void fill(const_reference value);

 private:
  size_type size_;
  value_type arr_[N];
  void CopyArray(const array &a) noexcept;
};
}  // namespace s21
#include "s21_array.cc"
#endif  // SRC_S21_CONTAINERSPLUS_ARRAY_S21_ARRAY_H_
