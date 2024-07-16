#ifndef SRC_S21_CONTAINERS_MAP_S21_MAP_H_
#define SRC_S21_CONTAINERS_MAP_S21_MAP_H_
#include <vector>

#include "../rbtree/__tree.h"
namespace s21 {
template <class Key, class T>
class map {
 public:
  using key_type = Key;
  using mapped_type = T;
  using value_type = std::pair<const key_type, mapped_type>;
  using reference = value_type &;
  using const_reference = const value_type &;
  using size_type = std::size_t;
  using _base = s21::__tree<key_type, std::pair<key_type, mapped_type>,
                            s21::First_Value<std::pair<key_type, mapped_type>>>;
  using iterator = typename _base::iterator;
  using const_iterator = typename _base::const_iterator;

 private:
  _base _tree;

 public:
  explicit map() : _tree() {}

  map(const map &Right) {
    _tree._insert_iterator(Right._tree.begin(), Right._tree.end());
  }

  map(map &&Right) noexcept : _tree(std::move(Right._tree)) {}

  map(std::initializer_list<value_type> IList) {
    _tree._insert_iterator(IList.begin(), IList.end());
  }

  map<Key, T> &operator=(map<Key, T> &m) {
    _tree.clear();
    if (this != &m) {
      _tree._insert_iterator(m._tree.begin(), m._tree.end());
    }
    return *this;
  }

  map<Key, T> &operator=(map<Key, T> &&m) noexcept {
    _tree = std::move(m._tree);
    return *this;
  }

  T &operator[](const Key &key) {
    iterator it = _tree.find(key);
    if (it == _tree.end()) {
      return _tree.insert_unique({key, T()}).first->second;
    }
    return it->second;
  }

  const T &operator[](const Key &key) const {
    iterator it = _tree.find(key);
    return it->second;
  }

  ~map() {}

  std::pair<iterator, bool> insert(const value_type &Val) {
    return _tree.insert_unique(Val);
  }

  std::pair<iterator, bool> insert(const Key &key, const T &obj) {
    return _tree.insert_unique(std::make_pair(key, obj));
  }

  std::pair<iterator, bool> insert_or_assign(const Key &key, const T &obj) {
    return _tree.insert_or_assign(std::make_pair(key, obj));
  }

  iterator end() noexcept { return _tree.end(); }

  iterator begin() noexcept { return _tree.begin(); }

  const_iterator begin() const noexcept { return _tree.begin(); }

  const_iterator end() const noexcept { return _tree.end(); }

  T &at(const key_type &key) {
    auto sr = find(key);
    if (sr == _tree.end()) {
      throw std::out_of_range("map::at: key not found");
    }
    return sr->second;
  }

  const T &at(const key_type &key) const {
    auto sr = find(key);
    if (sr == _tree.end()) {
      throw std::out_of_range("map::at: key not found");
    }
    return sr->second;
  }

  bool empty() const { return _tree.empty(); }

  size_type size() const { return _tree.size(); }

  size_type max_size() const { return _tree.max_size(); }

  void clear() { this->_tree.clear(); }

  void erase(iterator pos) {
    auto del = pos;
    pos++;
    _tree.erase(del);
  }

  void erase(const_iterator pos) { _tree.erase(pos); }

  void erase(const Key &key) {
    iterator it = _tree.find(key);
    _tree.erase(it);
  }

  void swap(map &other) { _tree.swap(other._tree); }

  void merge(map &other) {
    if (this == &other) {
      return;
    }
    auto last = other.end();
    for (auto first = other.begin(); first != last;) {
      auto del = first;
      std::pair<iterator, bool> Pair = _tree.insert_unique(*first);
      ++first;
      if (Pair.second == true) {
        other.erase(del);
        first = other.find(first->first);
      }
    }
  }

  iterator find(const Key &key) { return _tree.find(key); }

  const_iterator find(const Key &key) const { return _tree.find(key); }

  bool contains(const Key &key) const { return _tree.contains(key); }

  template <typename... Args>
  std::vector<std::pair<iterator, bool>> insert_many(Args &&...args) {
    std::vector<std::pair<iterator, bool>> result;
    for (const auto &arg : {args...}) {
      result.push_back(_tree.insert_unique(arg));
    }
    return result;
  }
  std::vector<std::pair<iterator, bool>> insert_many(void) {
    return std::vector<std::pair<iterator, bool>>();
  }

 private:
};
}  // namespace s21
#endif  // SRC_S21_CONTAINERS_MAP_S21_MAP_H_
