#ifndef SRC_S21_CONTAINERSPLUS_MULTISET_S21_MULTISET_H_
#define SRC_S21_CONTAINERSPLUS_MULTISET_S21_MULTISET_H_
#include <vector>

#include "../../s21_containers/rbtree/__tree.h"
namespace s21 {
template <class Key>
class multiset {
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
  explicit multiset() noexcept {}

  multiset(std::initializer_list<value_type> const &items) {
    _tree._insert_iterator_multi(items.begin(), items.end());
  }

  multiset(const multiset &Right) {
    _tree._insert_iterator_multi(Right._tree.begin(), Right._tree.end());
  }

  multiset(multiset &&Right) noexcept : _tree(std::move(Right._tree)) {}

  multiset<Key> &operator=(multiset<Key> &&m) noexcept {
    if (this != &m) {
      _tree = std::move(m._tree);
    }
    return *this;
  }

  multiset<Key> &operator=(multiset<Key> &m) {
    if (this != &m) {
      clear();
      _tree._insert_iterator_multi(m._tree.begin(), m._tree.end());
    }
    return *this;
  }

  ~multiset() {}

  iterator end() noexcept { return _tree.end(); }

  iterator begin() noexcept { return _tree.begin(); }

  const_iterator begin() const noexcept { return _tree.begin(); }

  const_iterator end() const noexcept { return _tree.end(); }

  bool empty() const noexcept { return _tree.empty(); }

  size_type size() const noexcept { return _tree.size(); }

  size_type max_size() const noexcept { return _tree.max_size(); }

  void clear() { return _tree.clear(); }

  iterator insert(const value_type &value) {
    return _tree._insert_multi(value);
  }

  void erase(const_iterator pos) { _tree.erase(pos); }

  void erase(iterator pos) { _tree.erase(pos); }

  void swap(multiset &other) { _tree.swap(other._tree); }

  void merge(multiset &other) {
    if (this == &other) return;
    _tree._insert_iterator_multi(other._tree.begin(), other._tree.end());
    other._tree.clear();
  }

  iterator find(const Key &key) { return _tree.find(key); }

  const_iterator find(const Key &key) const { return _tree.find(key); }

  bool contains(const Key &key) const { return _tree.contains(key); }

  std::pair<iterator, iterator> equal_range(const Key &key) {
    iterator lower = lower_bound(key);
    iterator upper = upper_bound(key);
    return std::make_pair(lower, upper);
  }

  std::pair<const_iterator, const_iterator> equal_range(const Key &key) const {
    const_iterator lower = lower_bound(key);
    const_iterator upper = upper_bound(key);
    return std::make_pair(lower, upper);
  }

  iterator lower_bound(const Key &key) { return _tree.lower_bound(key); }

  const_iterator lower_bound(const Key &key) const {
    return _tree.lower_bound(key);
  }

  const_iterator upper_bound(const Key &key) const {
    return _tree.upper_bound(key);
  }

  iterator upper_bound(const Key &key) { return _tree.upper_bound(key); }

  size_type count(const Key &key) const {
    size_type count = 0;
    auto pair = equal_range(key);
    while (pair.first != pair.second) {
      ++pair.first;
      count++;
    }
    return count;
  }

  template <typename... Args>
  std::vector<std::pair<iterator, bool>> insert_many(Args &&...args) {
    std::vector<std::pair<iterator, bool>> result;
    for (const value_type &arg : {args...}) {
      result.push_back(std::make_pair(_tree._insert_multi(arg), true));
    }
    return result;
  }

  std::vector<std::pair<iterator, bool>> insert_many(void) {
    return std::vector<std::pair<iterator, bool>>();
  }
};
}  // namespace s21
#endif  // SRC_S21_CONTAINERSPLUS_MULTISET_S21_MULTISET_H_
