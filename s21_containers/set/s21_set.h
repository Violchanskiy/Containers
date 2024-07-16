#ifndef SRC_S21_CONTAINERS_SET_S21_SET_H_
#define SRC_S21_CONTAINERS_SET_S21_SET_H_
#include <vector>

#include "../rbtree/__tree.h"
namespace s21 {
template <class Key>
class set {
 public:
  using key_type = Key;
  using value_type = Key;
  using reference = value_type &;
  using const_reference = const value_type &;
  using _base = s21::__tree<key_type, value_type, s21::Value<Key>>;
  using iterator = typename _base::iterator;
  using const_iterator = typename _base::const_iterator;
  using size_type = std::size_t;

 private:
  _base _tree;

 public:
  explicit set() noexcept {}

  set(std::initializer_list<value_type> const &items) {
    _tree._insert_iterator(items.begin(), items.end());
  }

  set(const set &Right) {
    _tree._insert_iterator(Right._tree.begin(), Right._tree.end());
  }

  set(set &&Right) noexcept : _tree(std::move(Right._tree)) {}

  set<Key> &operator=(set<Key> &&m) noexcept {
    if (this != &m) {
      _tree = std::move(m._tree);
    }
    return *this;
  }

  set<Key> &operator=(set<Key> &m) {
    if (this != &m) {
      clear();
      _tree._insert_iterator(m._tree.begin(), m._tree.end());
    }
    return *this;
  }

  ~set() {}

  iterator end() noexcept { return _tree.end(); }

  iterator begin() noexcept { return _tree.begin(); }

  const_iterator begin() const noexcept { return _tree.begin(); }

  const_iterator end() const noexcept { return _tree.end(); }

  bool empty() const noexcept { return _tree.empty(); }

  size_type size() const noexcept { return _tree.size(); }

  size_type max_size() const noexcept { return _tree.max_size(); }

  void clear() { return _tree.clear(); }

  std::pair<iterator, bool> insert(const value_type &value) {
    return _tree.insert_unique(value);
  }

  void erase(const_iterator pos) { _tree.erase(pos); }

  void erase(iterator pos) { _tree.erase(pos); }

  void erase(const Key &key) {
    auto it = _tree.find(key);
    _tree.erase(it);
  }

  void swap(set &other) { _tree.swap(other._tree); }

  void merge(set &other) {
    if (this == &other) {
      return;
    }
    auto last = other.end();
    for (auto first = other.begin(); first != last;) {
      auto del = first;
      auto Pair = _tree.insert_unique(*first);
      ++first;
      if (Pair.second == true) {
        other.erase(del);
        first = other.find(*first);
      }
    }
  }

  iterator find(const Key &key) { return _tree.find(key); }

  const_iterator find(const Key &key) const { return _tree.find(key); }

  bool contains(const Key &key) const { return _tree.contains(key); }

  template <typename... Args>
  std::vector<std::pair<iterator, bool>> insert_many(Args &&...args) {
    std::vector<std::pair<iterator, bool>> result;
    for (const value_type &arg : {args...}) {
      result.push_back(_tree.insert_unique(arg));
    }
    return result;
  }

  std::vector<std::pair<iterator, bool>> insert_many(void) {
    return std::vector<std::pair<iterator, bool>>();
  }
};
}  // namespace s21
#endif  // SRC_S21_CONTAINERS_SET_S21_SET_H_
