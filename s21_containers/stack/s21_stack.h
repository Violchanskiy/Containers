#ifndef SRC_S21_CONTAINERS_STACK_S21_STACK_H_
#define SRC_S21_CONTAINERS_STACK_S21_STACK_H_

#include <initializer_list>
#include <new>
#include <stdexcept>

namespace s21 {
template <typename T>
class stack {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = size_t;

  stack() noexcept;
  stack(std::initializer_list<value_type> const &items);
  stack(const stack &s) noexcept;
  stack(stack &&s) noexcept;
  ~stack() noexcept;

  stack &operator=(const stack &s) noexcept;
  stack &operator=(stack &&s) noexcept;

  void swap(stack &other) noexcept;
  bool empty() const noexcept;
  size_type size() const noexcept;

  const_reference top() const;
  void push(const_reference value);
  void pop();

  template <typename... Args>
  void insert_many_front(Args &&...args);

 private:
  void ClearStack() noexcept;

  struct Node {
    value_type name;
    Node *next;
    Node(const_reference value) : name(value), next(nullptr) {}
  };
  Node *topNode;
  size_type size_;
};
}  // namespace s21

#include "s21_stack.cc"

#endif  // SRC_S21_CONTAINERS_STACK_S21_STACK_H_
