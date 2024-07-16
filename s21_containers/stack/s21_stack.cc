#include "s21_stack.h"

namespace s21 {

template <typename T>
stack<T>::stack() noexcept : topNode(nullptr), size_(0) {}

template <typename T>
stack<T>::stack(const std::initializer_list<value_type> &items) : stack() {
  for (value_type item : items) {
    push(item);
  }
}

template <typename T>
stack<T>::stack(const stack &s) noexcept : stack() {
  *this = s;
}

template <typename T>
stack<T>::stack(stack &&s) noexcept : stack() {
  *this = std::move(s);
}

template <typename T>
stack<T>::~stack() noexcept {
  ClearStack();
}
template <typename T>
stack<T> &stack<T>::operator=(const stack &s) noexcept {
  if (this != &s) {
    ClearStack();
    Node *temp = s.topNode;
    stack<T> tempStack;
    while (temp) {
      tempStack.push(temp->name);
      temp = temp->next;
    }
    while (!tempStack.empty()) {
      push(tempStack.top());
      tempStack.pop();
    }
    size_ = s.size_;
  }
  return *this;
}

template <typename T>
stack<T> &stack<T>::operator=(stack &&s) noexcept {
  if (this != &s) {
    ClearStack();
    std::swap(topNode, s.topNode);
    std::swap(size_, s.size_);
  }
  return *this;
}

template <typename T>
bool stack<T>::empty() const noexcept {
  return topNode == nullptr;
}

template <typename T>
size_t stack<T>::size() const noexcept {
  return size_;
}

template <typename T>
typename stack<T>::const_reference stack<T>::top() const {
  if (empty()) {
    throw std::out_of_range("Stack is empty");
  }
  return topNode->name;
}
template <typename T>
void stack<T>::push(const_reference value) {
  try {
    Node *newNode = new Node(value);
    newNode->next = topNode;
    topNode = newNode;
    size_++;
  } catch (std::bad_alloc &er) {
    ClearStack();
    throw er;
  }
}

template <typename T>
void stack<T>::pop() {
  if (empty()) {
    throw std::out_of_range("Stack is empty");
  }
  Node *temp = topNode;
  topNode = topNode->next;
  delete temp;
  size_--;
}

template <typename T>
void stack<T>::ClearStack() noexcept {
  while (!empty()) {
    pop();
  }
}

template <typename T>
void stack<T>::swap(stack &other) noexcept {
  std::swap(topNode, other.topNode);
  std::swap(size_, other.size_);
}

template <typename T>
template <typename... Args>
void stack<T>::insert_many_front(Args &&...args) {
  for (auto item : {std::forward<Args>(args)...}) {
    push(item);
  }
}

}  // namespace s21
