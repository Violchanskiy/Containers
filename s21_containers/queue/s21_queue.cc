#include "s21_queue.h"

namespace s21 {
template <typename T>
queue<T>::queue() noexcept : topHead(nullptr), topTail(nullptr), size_(0) {}

template <typename T>
queue<T>::queue(std::initializer_list<value_type> const &items) : queue() {
  for (value_type item : items) {
    push(item);
  }
}

template <typename T>
queue<T>::queue(const queue &q) noexcept : queue() {
  *this = q;
}

template <typename T>
queue<T>::queue(queue &&q) noexcept : queue() {
  *this = std::move(q);
}
template <typename T>
queue<T>::~queue() noexcept {
  ClearQueue();
}

template <typename T>
queue<T> &queue<T>::operator=(const queue &q) noexcept {
  if (this != &q) {
    ClearQueue();
    Node *temp = q.topHead;
    while (temp) {
      push(temp->name);
      temp = temp->prev;
    }
    size_ = q.size_;
  }
  return *this;
}

template <typename T>
queue<T> &queue<T>::operator=(queue &&q) noexcept {
  if (this != &q) {
    ClearQueue();
    std::swap(topHead, q.topHead);
    std::swap(topTail, q.topTail);
    std::swap(size_, q.size_);
  }
  return *this;
}

template <typename T>
void queue<T>::push(const_reference value) {
  try {
    Node *newNode = new Node(value);
    if (topHead == nullptr) topHead = newNode;
    if (topTail == nullptr)
      topTail = newNode;
    else {
      topTail->prev = newNode;
      newNode->next = topTail;
      newNode->prev = nullptr;
      topTail = newNode;
    }
    size_++;
  } catch (std::bad_alloc &er) {
    ClearQueue();
    throw er;
  }
}

template <typename T>
void queue<T>::pop() {
  if (empty()) {
    throw std::out_of_range("Queue is empty");
  }
  Node *temp = topHead;
  topHead = temp->prev;
  delete temp;
  size_--;
}

template <typename T>
typename queue<T>::const_reference queue<T>::front() const {
  if (empty()) {
    throw std::out_of_range("Queue is empty");
  }
  return topHead->name;
}

template <typename T>
typename queue<T>::const_reference queue<T>::back() const {
  if (empty()) {
    throw std::out_of_range("Queue is empty");
  }
  return topTail->name;
}

template <typename T>
bool queue<T>::empty() const noexcept {
  return topHead == nullptr;
}

template <typename T>
size_t queue<T>::size() const noexcept {
  return size_;
}

template <typename T>
void queue<T>::ClearQueue() noexcept {
  while (!empty()) {
    pop();
  }
  topTail = nullptr;
}

template <typename T>
void queue<T>::swap(queue &other) noexcept {
  std::swap(topHead, other.topHead);
  std::swap(topTail, other.topTail);
  std::swap(size_, other.size_);
}

template <typename T>
template <typename... Args>
void queue<T>::insert_many_back(Args &&...args) {
  for (auto item : {std::forward<Args>(args)...}) {
    push(item);
  }
}
}  // namespace s21
