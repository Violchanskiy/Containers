#include "s21_vector.h"

template <typename T>
s21::Vector<T>::Vector() noexcept {
  initializeEmptyVector();
}

template <typename T>
void s21::Vector<T>::initializeEmptyVector() noexcept {
  data_ = nullptr;
  sizeVector = capacityVector = 0;
}

template <typename T>
s21::Vector<T>::Vector(size_type n) {
  try {
    if (max_size() <= n) throw std::out_of_range("No memory");
    sizeVector = capacityVector = n;
    data_ = new T[n];
    // uninitialized_fill_n - для заполнения не инициализированной памяти
    // заданным значением. Не вызывая конструкторы элементов.
    std::uninitialized_fill_n(data_, n, T());
  } catch (const std::bad_alloc& e) {
    clear();
    throw;
  }
}

template <typename T>
s21::Vector<T>::~Vector() noexcept {
  clear();
}

template <typename T>
void s21::Vector<T>::clear() noexcept {
  if (data_) delete[] data_;
  data_ = nullptr;
  sizeVector = capacityVector = 0;
}

template <typename T>
s21::Vector<T>::Vector(std::initializer_list<value_type> const& items) {
  try {
    sizeVector = capacityVector = items.size();
    data_ = new T[sizeVector];
    size_type i = 0;
    for (const auto& item : items) data_[i++] = item;  // цикл диапазона
  } catch (const std::bad_alloc& e) {
    clear();
    throw;
  }
}

template <typename T>
s21::Vector<T>::Vector(const Vector<T>& v) : Vector() {
  try {
    sizeVector = capacityVector = v.size();
    data_ = new T[sizeVector];
    for (size_type i = 0; i < sizeVector; i++) data_[i] = v[i];
  } catch (const std::bad_alloc& e) {
    clear();
    throw;
  }
}

template <typename T>
s21::Vector<T>::Vector(Vector&& v)
    : data_(std::move(v.data_)),
      sizeVector(std::move(v.sizeVector)),
      capacityVector(std::move(v.capacityVector)) {
  v.initializeEmptyVector();
}

template <typename T>
s21::Vector<T>& s21::Vector<T>::operator=(Vector&& v) {
  if (this != &v) {
    clear();
    data_ = std::move(v.data_);
    std::swap(data_.sizeVector, v.sizeVector);
    std::swap(data_.capacityVector, v.capacityVector);
  }
  return *this;
}

template <typename T>
s21::Vector<T>& s21::Vector<T>::operator=(Vector& v) {
  if (this != &v) {
    clear();
    try {
      sizeVector = capacityVector = v.size();
      data_ = new T[sizeVector];
      for (size_type i = 0; i < sizeVector; i++) data_[i] = v[i];
    } catch (const std::bad_alloc& e) {
      clear();
      throw;
    }
  }
  return *this;
}

template <typename T>
typename s21::Vector<T>::size_type s21::Vector<T>::size() const noexcept {
  return sizeVector;
}

template <typename T>
typename s21::Vector<T>::size_type s21::Vector<T>::max_size() const noexcept {
  return std::allocator<T>().max_size();
}

template <typename T>
typename s21::Vector<T>::VectorIterator s21::Vector<T>::begin() noexcept {
  return VectorIterator(data_);
}

template <typename T>
typename s21::Vector<T>::VectorConstIterator s21::Vector<T>::cbegin()
    const noexcept {
  return VectorConstIterator(data_);
}

template <typename T>
typename s21::Vector<T>::VectorIterator s21::Vector<T>::end() noexcept {
  return VectorIterator(data_ + sizeVector);
}

template <typename T>
typename s21::Vector<T>::VectorConstIterator s21::Vector<T>::cend()
    const noexcept {
  return VectorConstIterator(data_ + sizeVector);
}

template <typename T>
typename s21::Vector<T>::const_reference s21::Vector<T>::front() const {
  if (sizeVector >= 1)
    return data_[0];
  else
    throw std::out_of_range("Index out of range");
}

template <typename T>
typename s21::Vector<T>::const_reference s21::Vector<T>::back() const {
  if (sizeVector >= 1)
    return data_[sizeVector - 1];
  else
    throw std::out_of_range("Index out of range");
}

template <typename T>
T& s21::Vector<T>::operator[](size_type pos) const {
  return data_[pos];
}

template <typename T>
T& s21::Vector<T>::operator[](size_type pos) {
  return data_[pos];
}

template <typename T>
typename s21::Vector<T>::const_reference s21::Vector<T>::at(
    size_type pos) const {
  if (pos >= sizeVector) {
    throw std::out_of_range("Index out of range");
  }
  return data_[pos];
}

template <typename T>
typename s21::Vector<T>::reference s21::Vector<T>::at(size_type pos) {
  if (pos >= sizeVector) {
    throw std::out_of_range("Index out of range");
  }
  return data_[pos];
}

template <typename T>
T* s21::Vector<T>::data() noexcept {
  return data_;
}

template <typename T>
bool s21::Vector<T>::empty() const noexcept {
  return sizeVector == 0;
}

template <typename T>
typename s21::Vector<T>::size_type s21::Vector<T>::capacity() const noexcept {
  return capacityVector;
}

template <typename T>
void s21::Vector<T>::shrink_to_fit() {
  try {
    if (sizeVector < capacityVector) {
      T* newData = new T[sizeVector];
      for (size_type i = 0; i < sizeVector; ++i) newData[i] = data_[i];
      delete[] data_;
      data_ = newData;
      capacityVector = sizeVector;
    }
  } catch (const std::bad_alloc& e) {
    clear();
    throw;
  }
}

template <typename T>
void s21::Vector<T>::reserve(size_type size) {
  try {
    if (max_size() <= sizeVector + size) throw std::out_of_range("No memory");

    T* newData = new T[sizeVector + size];
    for (size_type i = 0; i != sizeVector; i++) newData[i] = data_[i];
    delete[] data_;
    data_ = newData;
    capacityVector = sizeVector + size;

  } catch (const std::bad_alloc& e) {
    clear();
    throw;
  }
}

template <typename T>
typename s21::Vector<T>::VectorIterator s21::Vector<T>::insert(
    VectorIterator pos, const_reference value) {
  if (pos < begin() || pos > end()) throw std::out_of_range("Invalid position");
  size_type index = pos - begin();
  newCapacityVector();
  // сдвиг элементов внутри вектора для создания места для вставки нового
  // элемента
  for (size_type i = sizeVector; i > index; --i) data_[i] = data_[i - 1];
  data_[index] = value;
  sizeVector++;
  return begin() + index;
}

template <typename T>
typename s21::Vector<T>::VectorConstIterator s21::Vector<T>::insert(
    VectorConstIterator pos, const_reference value) {
  if (pos < cbegin() || pos > cend())
    throw std::out_of_range("Invalid position");
  size_type index = pos - cbegin();
  newCapacityVector();
  // сдвиг элементов внутри вектора для создания места для вставки нового
  // элемента
  for (size_type i = sizeVector; i > index; --i) data_[i] = data_[i - 1];
  data_[index] = value;
  sizeVector++;
  return cbegin() + index;
}

template <typename T>
void s21::Vector<T>::erase(VectorIterator pos) {
  if (pos < begin() || pos > end()) throw std::out_of_range("Invalid position");
  size_type index = pos - begin();
  //  сдвиг элементов влево после удаления элемента вектора
  for (size_type i = index; i < sizeVector - 1; ++i) data_[i] = data_[i + 1];
  // устанавливаем последний элемент в значение по умолчанию или уменьшаем
  // размер вектора.
  data_[sizeVector - 1] = T();
  sizeVector--;
}

template <typename T>
void s21::Vector<T>::erase(VectorConstIterator pos) {
  if (pos < begin() || pos > end()) throw std::out_of_range("Invalid position");
  size_type index = pos - begin();
  //  сдвиг элементов влево после удаления элемента вектора
  for (size_type i = index; i < sizeVector - 1; ++i) data_[i] = data_[i + 1];
  // устанавливаем последний элемент в значение по умолчанию или уменьшаем
  // размер вектора.
  data_[sizeVector - 1] = T();
  sizeVector--;
}

template <typename T>
void s21::Vector<T>::push_back(const_reference value) {
  newCapacityVector();
  data_[sizeVector] = value;
  sizeVector++;
}

template <typename T>
void s21::Vector<T>::newCapacityVector() noexcept {
  if (sizeVector >= capacityVector) {
    size_type newCapacity = capacityVector == 0 ? 1 : capacityVector * 2;
    reserve(newCapacity);
  }
}

template <typename T>
void s21::Vector<T>::pop_back() noexcept {
  if (sizeVector > 0) {
    sizeVector--;
    shrink_to_fit();
  }
}

template <typename T>
void s21::Vector<T>::swap(Vector& other) noexcept {
  std::swap(data_, other.data_);
  std::swap(sizeVector, other.sizeVector);
  std::swap(capacityVector, other.capacityVector);
}

template <typename T>
template <typename... Args>
typename s21::Vector<T>::VectorIterator s21::Vector<T>::insert_many(
    VectorIterator pos, Args&&... args) {
  Vector<value_type> tmp{args...};
  if (tmp.size() == 0) return begin();
  if (capacity() < tmp.size()) reserve(tmp.size() - capacity());
  size_t index = (pos < cbegin()) ? 0 : static_cast<size_t>(pos - cbegin());
  for (size_t i = 0; i < tmp.size(); ++i) insert(begin() + index, tmp[i]);

  return begin() + index;
}

template <typename T>
template <typename... Args>
typename s21::Vector<T>::VectorIterator s21::Vector<T>::insert_many(
    VectorConstIterator pos, Args&&... args) {
  Vector<value_type> tmp{args...};
  if (tmp.size() == 0) return begin();
  if (capacity() < tmp.size()) reserve(tmp.size() - capacity());
  size_t index = (pos < cbegin()) ? 0 : static_cast<size_t>(pos - cbegin());
  for (size_t i = 0; i < tmp.size(); ++i) insert(cbegin() + index, tmp[i]);

  return begin() + index;
}

template <typename T>
template <typename... Args>
void s21::Vector<T>::insert_many_back(Args&&... args) {
  Vector<value_type> tmp{args...};
  for (size_t i = 0; i < tmp.size(); ++i) push_back(tmp[i]);
}
