#ifndef SRC_S21_CONTAINERS_QUEUE_S21_QUEUE_H_
#define SRC_S21_CONTAINERS_QUEUE_S21_QUEUE_H_

#include <initializer_list>
#include <new>
#include <stdexcept>
namespace s21 {
template <typename T>
class queue {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = size_t;

  queue() noexcept;
  queue(std::initializer_list<value_type> const &items);
  queue(const queue &q) noexcept;
  queue(queue &&q) noexcept;
  ~queue() noexcept;
  queue &operator=(const queue &q) noexcept;
  queue &operator=(queue &&q) noexcept;

  const_reference front() const;
  const_reference back() const;

  bool empty() const noexcept;
  size_type size() const noexcept;

  void push(const_reference value);
  void pop();
  void swap(queue &other) noexcept;

  template <typename... Args>
  void insert_many_back(Args &&...args);

 private:
  void ClearQueue() noexcept;

  struct Node {
    value_type name;
    Node *next;
    Node *prev;
    Node(const_reference value) : name(value), next(nullptr), prev(nullptr) {}
  };
  Node *topHead;
  Node *topTail;
  size_type size_;
};
}  // namespace s21

#include "s21_queue.cc"
#endif  // SRC_S21_CONTAINERS_QUEUE_S21_QUEUE_H_
