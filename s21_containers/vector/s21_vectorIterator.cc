#include "s21_vector.h"

template <typename T>
s21::Vector<T>::VectorIterator::VectorIterator() : current(nullptr) {}

template <typename T>
s21::Vector<T>::VectorIterator::VectorIterator(pointer ptr) : current(ptr) {}

template <typename T>
typename s21::Vector<T>::reference s21::Vector<T>::VectorIterator::operator*()
    const {
  if (current) return *current;
  throw std::out_of_range("Dereferencing an invalid iterator");
}

template <typename T>
typename s21::Vector<T>::VectorIterator::pointer
s21::Vector<T>::VectorIterator::operator->() {
  if (current) return &(*current);
  throw std::out_of_range("Dereferencing an invalid iterator");
}

template <typename T>
typename s21::Vector<T>::VectorIterator&
s21::Vector<T>::VectorIterator::operator++() {
  if (current) current++;
  return *this;
}

template <typename T>
typename s21::Vector<T>::VectorIterator
s21::Vector<T>::VectorIterator::operator++(int) {
  VectorIterator tmp = *this;
  ++(*this);
  return tmp;
}

template <typename T>
typename s21::Vector<T>::VectorIterator&
s21::Vector<T>::VectorIterator::operator--() {
  if (current) current--;
  return *this;
}

template <typename T>
typename s21::Vector<T>::VectorIterator
s21::Vector<T>::VectorIterator::operator--(int) {
  VectorIterator tmp = *this;
  --(*this);
  return tmp;
}

template <typename T>
typename s21::Vector<T>::VectorIterator&
s21::Vector<T>::VectorIterator::operator+=(difference_type n) {
  current += n;
  return *this;
}

template <typename T>
typename s21::Vector<T>::VectorIterator
s21::Vector<T>::VectorIterator::operator+(difference_type n) const {
  VectorIterator result = *this;
  return result += n;
}

template <typename T>
typename s21::Vector<T>::VectorIterator&
s21::Vector<T>::VectorIterator::operator-=(difference_type n) {
  if (current) current -= n;
  return *this;
}

template <typename T>
typename s21::Vector<T>::VectorIterator
s21::Vector<T>::VectorIterator::operator-(difference_type n) const {
  VectorIterator result = *this;
  return result -= n;
}

template <typename T>
typename s21::Vector<T>::VectorIterator::difference_type
s21::Vector<T>::VectorIterator::operator-(const VectorIterator& other) const {
  return current - other.current;
}

template <typename T>
bool s21::Vector<T>::VectorIterator::operator==(
    const VectorIterator& other) const {
  return current == other.current;
}

template <typename T>
bool s21::Vector<T>::VectorIterator::operator!=(
    const VectorIterator& other) const {
  return !(*this == other);
}

template <typename T>
bool s21::Vector<T>::VectorIterator::operator<(
    const VectorIterator& other) const {
  return current < other.current;
}

template <typename T>
bool s21::Vector<T>::VectorIterator::operator>(
    const VectorIterator& other) const {
  return current > other.current;
}

template <typename T>
bool s21::Vector<T>::VectorIterator::operator<=(
    const VectorIterator& other) const {
  return current <= other.current;
}

template <typename T>
bool s21::Vector<T>::VectorIterator::operator>=(
    const VectorIterator& other) const {
  return current >= other.current;
}

//----------------------------------- Const Iterator
//-------------------------------------------------------------------

template <typename T>
s21::Vector<T>::VectorConstIterator::VectorConstIterator() : current(nullptr) {}

template <typename T>
s21::Vector<T>::VectorConstIterator::VectorConstIterator(pointer ptr)
    : current(ptr) {}

template <typename T>
typename s21::Vector<T>::VectorConstIterator::reference
s21::Vector<T>::VectorConstIterator::operator*() {
  if (current) return *current;
  throw std::out_of_range("Dereferencing an invalid iterator");
}

template <typename T>
typename s21::Vector<T>::VectorConstIterator::pointer
s21::Vector<T>::VectorConstIterator::operator->() {
  if (current) return &(*current);
  throw std::out_of_range("Dereferencing an invalid iterator");
}

template <typename T>
typename s21::Vector<T>::VectorConstIterator&
s21::Vector<T>::VectorConstIterator::operator++() {
  if (current) current++;
  return *this;
}

template <typename T>
typename s21::Vector<T>::VectorConstIterator
s21::Vector<T>::VectorConstIterator::operator++(int) {
  VectorConstIterator tmp = *this;
  ++(*this);
  return tmp;
}

template <typename T>
typename s21::Vector<T>::VectorConstIterator&
s21::Vector<T>::VectorConstIterator::operator--() {
  if (current) current--;
  return *this;
}

template <typename T>
typename s21::Vector<T>::VectorConstIterator
s21::Vector<T>::VectorConstIterator::operator--(int) {
  VectorConstIterator tmp = *this;
  --(*this);
  return tmp;
}

template <typename T>
typename s21::Vector<T>::VectorConstIterator&
s21::Vector<T>::VectorConstIterator::operator+=(difference_type n) {
  if (current) current += n;
  return *this;
}

template <typename T>
typename s21::Vector<T>::VectorConstIterator
s21::Vector<T>::VectorConstIterator::operator+(difference_type n) const {
  VectorConstIterator result = *this;
  return result += n;
}

template <typename T>
typename s21::Vector<T>::VectorConstIterator&
s21::Vector<T>::VectorConstIterator::operator-=(difference_type n) {
  if (current) current -= n;
  return *this;
}

template <typename T>
typename s21::Vector<T>::VectorConstIterator
s21::Vector<T>::VectorConstIterator::operator-(difference_type n) const {
  VectorConstIterator result = *this;
  return result -= n;
}

template <typename T>
typename s21::Vector<T>::VectorConstIterator::difference_type
s21::Vector<T>::VectorConstIterator::operator-(
    const VectorConstIterator& other) const {
  return current - other.current;
}

template <typename T>
bool s21::Vector<T>::VectorConstIterator::operator==(
    const VectorConstIterator& other) const {
  return current == other.current;
}

template <typename T>
bool s21::Vector<T>::VectorConstIterator::operator!=(
    const VectorConstIterator& other) const {
  return !(*this == other);
}

template <typename T>
bool s21::Vector<T>::VectorConstIterator::operator<(
    const VectorConstIterator& other) const {
  return current < other.current;
}

template <typename T>
bool s21::Vector<T>::VectorConstIterator::operator>(
    const VectorConstIterator& other) const {
  return current > other.current;
}

template <typename T>
bool s21::Vector<T>::VectorConstIterator::operator<=(
    const VectorConstIterator& other) const {
  return current <= other.current;
}

template <typename T>
bool s21::Vector<T>::VectorConstIterator::operator>=(
    const VectorConstIterator& other) const {
  return current >= other.current;
}