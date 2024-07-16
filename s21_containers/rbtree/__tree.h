#ifndef SRC_S21_CONTAINERS_RBTREE___TREE_H_
#define SRC_S21_CONTAINERS_RBTREE___TREE_H_

#include <iostream>
#include <limits>

namespace s21 {

template <class Key, class T, class KeyVal>
class __tree {
  template <class U>
  class _tree_iterator;

 public:
  using value_type = T;
  using key_type = Key;
  using size_type = std::size_t;
  using iterator = _tree_iterator<value_type>;
  using const_iterator = _tree_iterator<const value_type>;

  using key_val = KeyVal;

 private:
  struct _node {
    value_type data;
    _node *parent;
    _node *left;
    _node *right;
    bool isRed;

    _node() noexcept
        : parent(nullptr), left(nullptr), right(nullptr), isRed(0) {}
    _node(const value_type &val)
        : data(val), parent(nullptr), left(nullptr), right(nullptr), isRed(1) {}
  };

  using point_node = _node *;

  template <class U>
  class _tree_iterator {
   public:
    friend class s21::__tree<Key, T, KeyVal>;
    using iterator_category = std::bidirectional_iterator_tag;
    using difference_type = std::ptrdiff_t;
    using value_type = U;
    using pointer = value_type *;
    using reference = value_type &;

   private:
    point_node _pos;
    point_node _nil;
    point_node _mend;

   public:
    _tree_iterator() noexcept;
    explicit _tree_iterator(point_node __x, point_node _nil,
                            point_node _mend) noexcept;
    _tree_iterator(const _tree_iterator<typename std::remove_const<U>::type>
                       &other) noexcept;
    _tree_iterator<U> &operator=(
        const _tree_iterator<typename std::remove_const<U>::type>
            other) noexcept;
    bool operator==(const _tree_iterator &__x) const;
    bool operator!=(const _tree_iterator &__x) const;
    reference operator*() const;
    pointer operator->() const;
    _tree_iterator<U> &operator++();
    _tree_iterator<U> &operator--();
    _tree_iterator<U> operator--(int);
    _tree_iterator<U> operator++(int);
  };

 private:
  point_node _head;
  point_node _nil;
  size_type __size;

  key_type key(value_type data) const;
  key_type key(point_node node) const;
  point_node &root(void) const;
  point_node &_node_end(void) const;
  point_node &_node_begin(void) const;

 public:
  explicit __tree();
  __tree(__tree &&Right);
  __tree<Key, T, KeyVal> &operator=(__tree<Key, T, KeyVal> &&m);
  ~__tree();
  iterator begin() noexcept;
  const_iterator begin() const noexcept;
  iterator end() noexcept;
  const_iterator end() const noexcept;
  std::pair<iterator, bool> insert_or_assign(const value_type &obj);
  std::pair<iterator, bool> insert_unique(const value_type &Val);
  iterator _insert_multi(const value_type &Val);
  template <class InputIterator>
  void _insert_iterator(InputIterator First, InputIterator Last);
  template <class InputIterator>
  void _insert_iterator_multi(InputIterator First, InputIterator Last);
  void erase(iterator pos);
  void erase(const_iterator pos);
  iterator find(const key_type &k);
  const_iterator find(const key_type &k) const;
  iterator lower_bound(const key_type &k);
  const_iterator lower_bound(const key_type &k) const;
  iterator upper_bound(const key_type &k);
  const_iterator upper_bound(const key_type &k) const;
  bool empty() const noexcept;
  size_type size() const noexcept;
  size_type max_size() const noexcept;
  void clear();
  void swap(__tree &other);
  bool contains(const Key &key) const noexcept;

 private:
  void clear(point_node curr) noexcept;
  void init();
  point_node search(const key_type &k, point_node curr) noexcept;
  point_node search(const key_type &k, point_node curr) const noexcept;
  void rotate_left(point_node node) noexcept;
  void rotate_right(point_node node) noexcept;
  iterator _insert_node(point_node parent, value_type Val);
  point_node _erase_node(point_node del);
  void deleteFixup(point_node node) noexcept;
  void insert_fixup(point_node node) noexcept;
};
}  // namespace s21

template <class Key, class T, class KeyVal>
template <class U>
s21::__tree<Key, T, KeyVal>::_tree_iterator<U>::_tree_iterator() noexcept
    : _pos(nullptr), _nil(nullptr), _mend(nullptr) {}

template <class Key, class T, class KeyVal>
template <class U>
s21::__tree<Key, T, KeyVal>::_tree_iterator<U>::_tree_iterator(
    point_node __x, point_node _nil, point_node _mend) noexcept
    : _pos(__x), _nil(_nil), _mend(_mend) {}

template <class Key, class T, class KeyVal>
template <class U>
s21::__tree<Key, T, KeyVal>::_tree_iterator<U>::_tree_iterator(
    const _tree_iterator<typename std::remove_const<U>::type> &other) noexcept
    : _pos(other._pos), _nil(other._nil), _mend(other._mend) {}

template <class Key, class T, class KeyVal>
template <class U>
typename s21::__tree<Key, T, KeyVal>::_tree_iterator<U> &
s21::__tree<Key, T, KeyVal>::_tree_iterator<U>::operator=(
    const _tree_iterator<typename std::remove_const<U>::type> other) noexcept {
  if (this != &other) {
    _pos = other._pos;
    _nil = other._nil;
    _mend = other._mend;
  }
  return *this;
}

template <class Key, class T, class KeyVal>
template <class U>
bool s21::__tree<Key, T, KeyVal>::_tree_iterator<U>::operator==(
    const _tree_iterator &__x) const {
  return _pos == __x._pos;
}

template <class Key, class T, class KeyVal>
template <class U>
bool s21::__tree<Key, T, KeyVal>::_tree_iterator<U>::operator!=(
    const _tree_iterator &__x) const {
  return _pos != __x._pos;
}

template <class Key, class T, class KeyVal>
template <class U>
typename s21::__tree<Key, T, KeyVal>::_tree_iterator<U>::reference
s21::__tree<Key, T, KeyVal>::_tree_iterator<U>::operator*() const {
  return _pos->data;
}

template <class Key, class T, class KeyVal>
template <class U>
typename s21::__tree<Key, T, KeyVal>::_tree_iterator<U>::pointer
s21::__tree<Key, T, KeyVal>::_tree_iterator<U>::operator->() const {
  return &(_pos->data);
}

template <class Key, class T, class KeyVal>
template <class U>
typename s21::__tree<Key, T, KeyVal>::_tree_iterator<U>
    &s21::__tree<Key, T, KeyVal>::_tree_iterator<U>::operator++() {
  if (_pos == _mend->left)
    _pos = _nil;
  else if (_pos->right != _nil) {
    _pos = _pos->right;
    while (_pos->left != _nil) _pos = _pos->left;
  } else {
    point_node parent = _pos->parent;
    while (parent != nullptr && _pos == parent->right) {
      _pos = parent;
      parent = parent->parent;
    }
    _pos = parent;
  }
  return *this;
}

template <class Key, class T, class KeyVal>
template <class U>
typename s21::__tree<Key, T, KeyVal>::_tree_iterator<U>
    &s21::__tree<Key, T, KeyVal>::_tree_iterator<U>::operator--() {
  if (_pos == _nil) {
    _pos = _mend->left;
  } else {
    if (_pos->left != _nil) {
      _pos = _pos->left;
      while (_pos->right != _nil) _pos = _pos->right;
    } else {
      point_node parent = _pos->parent;
      while (parent != nullptr && _pos == parent->left) {
        _pos = parent;
        parent = parent->parent;
      }
      _pos = parent;
    }
  }
  return *this;
}

template <class Key, class T, class KeyVal>
template <class U>
typename s21::__tree<Key, T, KeyVal>::_tree_iterator<U>
s21::__tree<Key, T, KeyVal>::_tree_iterator<U>::operator--(int) {
  _tree_iterator<U> tmp = *this;
  --(*this);
  return tmp;
}

template <class Key, class T, class KeyVal>
template <class U>
typename s21::__tree<Key, T, KeyVal>::_tree_iterator<U>
s21::__tree<Key, T, KeyVal>::_tree_iterator<U>::operator++(int) {
  _tree_iterator<U> tmp = *this;
  ++(*this);
  return tmp;
}

template <class Key, class T, class KeyVal>
typename s21::__tree<Key, T, KeyVal>::key_type s21::__tree<Key, T, KeyVal>::key(
    value_type data) const {
  return key_val()(data);
}

template <class Key, class T, class KeyVal>
typename s21::__tree<Key, T, KeyVal>::key_type s21::__tree<Key, T, KeyVal>::key(
    point_node node) const {
  return key_val()(node->data);
}

template <class Key, class T, class KeyVal>
typename s21::__tree<Key, T, KeyVal>::point_node &
s21::__tree<Key, T, KeyVal>::root(void) const {
  return _head->parent;
}

template <class Key, class T, class KeyVal>
typename s21::__tree<Key, T, KeyVal>::point_node &
s21::__tree<Key, T, KeyVal>::_node_end(void) const {
  return _head->left;
}

template <class Key, class T, class KeyVal>
typename s21::__tree<Key, T, KeyVal>::point_node &
s21::__tree<Key, T, KeyVal>::_node_begin(void) const {
  return _head->right;
}

template <class Key, class T, class KeyVal>
s21::__tree<Key, T, KeyVal>::__tree()
    : _head(nullptr), _nil(nullptr), __size(0) {
  init();
}

template <class Key, class T, class KeyVal>
s21::__tree<Key, T, KeyVal>::__tree(__tree &&Right)
    : _head(Right._head), _nil(Right._nil), __size(Right.__size) {
  Right.init();
}

template <class Key, class T, class KeyVal>
typename s21::__tree<Key, T, KeyVal> &s21::__tree<Key, T, KeyVal>::operator=(
    __tree<Key, T, KeyVal> &&m) {
  if (this == &m) {
    return *this;
  }
  clear(root());
  delete _head;
  delete _nil;

  _head = m._head;
  _nil = m._nil;
  __size = m.__size;
  m.init();
  return *this;
}

template <class Key, class T, class KeyVal>
s21::__tree<Key, T, KeyVal>::~__tree() {
  if (root() != _nil) clear(root());
  delete _head;
  delete _nil;
}

template <class Key, class T, class KeyVal>
typename s21::__tree<Key, T, KeyVal>::iterator
s21::__tree<Key, T, KeyVal>::begin() noexcept {
  if (root() == _nil) return iterator(end());
  return iterator(_node_begin(), _nil, _head);
}

template <class Key, class T, class KeyVal>
typename s21::__tree<Key, T, KeyVal>::const_iterator
s21::__tree<Key, T, KeyVal>::begin() const noexcept {
  if (root() == _nil) return const_iterator(end());
  return const_iterator(_node_begin(), _nil, _head);
}

template <class Key, class T, class KeyVal>
typename s21::__tree<Key, T, KeyVal>::iterator
s21::__tree<Key, T, KeyVal>::end() noexcept {
  return iterator(_nil, _nil, _head);
}

template <class Key, class T, class KeyVal>
typename s21::__tree<Key, T, KeyVal>::const_iterator
s21::__tree<Key, T, KeyVal>::end() const noexcept {
  return iterator(_nil, _nil, _head);
}

template <class Key, class T, class KeyVal>
std::pair<typename s21::__tree<Key, T, KeyVal>::iterator, bool>
s21::__tree<Key, T, KeyVal>::insert_or_assign(const value_type &obj) {
  point_node curr = root();
  point_node parent = nullptr;
  while (curr != _nil) {
    parent = curr;
    if (key(obj) < key(curr)) {
      curr = curr->left;
    } else if (key(obj) > key(curr)) {
      curr = curr->right;
    } else {
      curr->data = obj;
      return std::pair<iterator, bool>(iterator(curr, _nil, _head), false);
    }
  }
  return std::pair<iterator, bool>(_insert_node(parent, obj), true);
}

template <class Key, class T, class KeyVal>
std::pair<typename s21::__tree<Key, T, KeyVal>::iterator, bool>
s21::__tree<Key, T, KeyVal>::insert_unique(const value_type &Val) {
  point_node curr = root();
  point_node parent = nullptr;
  while (curr != _nil) {
    parent = curr;
    if (key(Val) < key(curr)) {
      curr = curr->left;
    } else if (key(Val) > key(curr)) {
      curr = curr->right;
    } else
      return std::pair<iterator, bool>(iterator(curr, _nil, _head), false);
  }
  return std::pair<iterator, bool>(_insert_node(parent, Val), true);
}

template <class Key, class T, class KeyVal>
typename s21::__tree<Key, T, KeyVal>::iterator
s21::__tree<Key, T, KeyVal>::_insert_multi(const value_type &Val) {
  point_node curr = root();
  point_node parent = nullptr;
  while (curr != _nil) {
    parent = curr;
    if (key(Val) > key(curr)) {
      curr = curr->right;
    } else {
      curr = curr->left;
    }
  }
  return _insert_node(parent, Val);
}

template <class Key, class T, class KeyVal>
template <class InputIterator>
void s21::__tree<Key, T, KeyVal>::_insert_iterator(InputIterator First,
                                                   InputIterator Last) {
  while (First != Last) {
    insert_unique(*First);
    ++First;
  }
}

template <class Key, class T, class KeyVal>
template <class InputIterator>
void s21::__tree<Key, T, KeyVal>::_insert_iterator_multi(InputIterator First,
                                                         InputIterator Last) {
  while (First != Last) {
    _insert_multi(*First);
    ++First;
  }
}

template <class Key, class T, class KeyVal>
void s21::__tree<Key, T, KeyVal>::erase(iterator pos) {
  point_node del = pos._pos;
  delete _erase_node(del);
}

template <class Key, class T, class KeyVal>
void s21::__tree<Key, T, KeyVal>::erase(const_iterator pos) {
  point_node del = pos._pos;
  delete _erase_node(del);
}

template <class Key, class T, class KeyVal>
typename s21::__tree<Key, T, KeyVal>::iterator
s21::__tree<Key, T, KeyVal>::find(const key_type &k) {
  point_node find = search(k, root());
  if (find == _nil || find == nullptr)
    return end();
  else
    return iterator(find, _nil, _head);
}

template <class Key, class T, class KeyVal>
typename s21::__tree<Key, T, KeyVal>::const_iterator
s21::__tree<Key, T, KeyVal>::find(const key_type &k) const {
  point_node find = search(k, root());
  if (find == _nil || find == nullptr)
    return end();
  else
    return const_iterator(find, _nil, _head);
}

template <class Key, class T, class KeyVal>
typename s21::__tree<Key, T, KeyVal>::iterator
s21::__tree<Key, T, KeyVal>::lower_bound(const key_type &k) {
  point_node root_node = root();
  point_node result = _nil;
  while (root_node != _nil) {
    if (k <= key(root_node)) {
      result = root_node;
      root_node = root_node->left;
    } else
      root_node = root_node->right;
  }
  return iterator(result, _nil, _head);
}

template <class Key, class T, class KeyVal>
typename s21::__tree<Key, T, KeyVal>::const_iterator
s21::__tree<Key, T, KeyVal>::lower_bound(const key_type &k) const {
  point_node root_node = root();
  point_node result = _nil;
  while (root_node != _nil) {
    if (k <= key(root_node)) {
      result = root_node;
      root_node = root_node->left;
    } else
      root_node = root_node->right;
  }
  return const_iterator(result, _nil, _head);
}

template <class Key, class T, class KeyVal>
typename s21::__tree<Key, T, KeyVal>::iterator
s21::__tree<Key, T, KeyVal>::upper_bound(const key_type &k) {
  point_node root_node = root();
  point_node result = _nil;
  while (root_node != _nil) {
    if (k < key(root_node)) {
      result = root_node;
      root_node = root_node->left;
    } else
      root_node = root_node->right;
  }
  return iterator(result, _nil, _head);
}

template <class Key, class T, class KeyVal>
typename s21::__tree<Key, T, KeyVal>::const_iterator
s21::__tree<Key, T, KeyVal>::upper_bound(const key_type &k) const {
  point_node root_node = root();
  point_node result = _nil;
  while (root_node != _nil) {
    if (k < key(root_node)) {
      result = root_node;
      root_node = root_node->left;
    } else
      root_node = root_node->right;
  }
  return const_iterator(result, _nil, _head);
}

template <class Key, class T, class KeyVal>
bool s21::__tree<Key, T, KeyVal>::empty() const noexcept {
  return root() == _nil ? true : false;
}

template <class Key, class T, class KeyVal>
typename s21::__tree<Key, T, KeyVal>::size_type
s21::__tree<Key, T, KeyVal>::size() const noexcept {
  return __size;
}

template <class Key, class T, class KeyVal>
typename s21::__tree<Key, T, KeyVal>::size_type
s21::__tree<Key, T, KeyVal>::max_size() const noexcept {
  return std::allocator<_node>().max_size();
}

template <class Key, class T, class KeyVal>
void s21::__tree<Key, T, KeyVal>::clear() {
  clear(root());
  root() = _nil;
  _node_begin() = _nil;
  _node_end() = _nil;
  __size = 0;
}

template <class Key, class T, class KeyVal>
void s21::__tree<Key, T, KeyVal>::swap(__tree &other) {
  std::swap(_head, other._head);
  std::swap(_nil, other._nil);
  std::swap(__size, other.__size);
}

template <class Key, class T, class KeyVal>
bool s21::__tree<Key, T, KeyVal>::contains(const Key &key) const noexcept {
  return search(key, root()) == _nil ? false : true;
}

template <class Key, class T, class KeyVal>
void s21::__tree<Key, T, KeyVal>::clear(point_node curr) noexcept {
  if (curr == _nil || curr == nullptr) return;

  clear(curr->right);
  clear(curr->left);
  delete (curr);
}

template <class Key, class T, class KeyVal>
void s21::__tree<Key, T, KeyVal>::init() {
  try {
    _head = new _node();
    _nil = new _node();
    __size = 0;
    _head->parent = _head->left = _head->right = _nil;
  } catch (const std::bad_alloc &e) {
    clear(root());
    delete _head;
    delete _nil;
    throw;
  }
}

template <class Key, class T, class KeyVal>
typename s21::__tree<Key, T, KeyVal>::point_node
s21::__tree<Key, T, KeyVal>::search(const key_type &k,
                                    point_node curr) noexcept {
  if (curr == _nil) return _nil;
  if (k == key(curr))
    return curr;
  else if (k < key(curr))
    return search(k, curr->left);
  else
    return search(k, curr->right);
}

template <class Key, class T, class KeyVal>
typename s21::__tree<Key, T, KeyVal>::point_node
s21::__tree<Key, T, KeyVal>::search(const key_type &k,
                                    point_node curr) const noexcept {
  if (curr == _nil) return _nil;
  if (k == key(curr))
    return curr;
  else if (k < key(curr))
    return search(k, curr->left);
  else
    return search(k, curr->right);
}

template <class Key, class T, class KeyVal>
void s21::__tree<Key, T, KeyVal>::rotate_left(point_node node) noexcept {
  point_node right_child = node->right;
  node->right = right_child->left;
  if (right_child->left != _nil) right_child->left->parent = node;
  if (right_child != _nil) right_child->parent = node->parent;
  if (node->parent == nullptr)
    root() = right_child;
  else if (node == node->parent->left)
    node->parent->left = right_child;
  else
    node->parent->right = right_child;
  right_child->left = node;
  node->parent = right_child;
}

template <class Key, class T, class KeyVal>
void s21::__tree<Key, T, KeyVal>::rotate_right(point_node node) noexcept {
  point_node left_child = node->left;
  node->left = left_child->right;
  if (left_child->right != _nil) left_child->right->parent = node;
  if (left_child != _nil) left_child->parent = node->parent;
  if (node->parent == nullptr)
    root() = left_child;
  else if (node == node->parent->right)
    node->parent->right = left_child;
  else
    node->parent->left = left_child;
  left_child->right = node;
  node->parent = left_child;
}

template <class Key, class T, class KeyVal>
typename s21::__tree<Key, T, KeyVal>::iterator
s21::__tree<Key, T, KeyVal>::_insert_node(point_node parent, value_type Val) {
  try {
    point_node new_node = new _node(Val);
    new_node->left = new_node->right = _nil;
    new_node->parent = parent;
    if (parent == nullptr)
      root() = new_node;
    else if (key(Val) > key(parent))
      parent->right = new_node;
    else
      parent->left = new_node;

    if (_node_end() == _nil || key(new_node) > key(_node_end()))
      _node_end() = new_node;

    if (_node_begin() == _nil || key(new_node) <= key(_node_begin()))
      _node_begin() = new_node;

    insert_fixup(new_node);
    __size++;
    return iterator(new_node, _nil, _head);
  } catch (const std::bad_alloc &e) {
    clear(root());
    delete _head;
    delete _nil;
    throw;
  }
}

template <class Key, class T, class KeyVal>
void s21::__tree<Key, T, KeyVal>::insert_fixup(point_node node) noexcept {
  while (node != root() && node->parent->isRed) {
    if (node->parent == node->parent->parent->left) {
      point_node uncle = node->parent->parent->right;
      if (uncle->isRed) {
        // Случай 1: Дядя красный
        node->parent->isRed = false;
        uncle->isRed = false;
        node->parent->parent->isRed = true;
        node = node->parent->parent;
      } else {
        if (node == node->parent->right) {
          // Случай 2: Дядя черный и узел - правый потомок
          node = node->parent;
          rotate_left(node);
        }
        // Случай 3: Дядя черный и узел - левый потомок
        node->parent->isRed = false;
        node->parent->parent->isRed = true;
        rotate_right(node->parent->parent);
      }
    } else {
      point_node uncle = node->parent->parent->left;
      if (uncle->isRed) {
        // Случай 1: Дядя красный
        node->parent->isRed = false;
        uncle->isRed = false;
        node->parent->parent->isRed = true;
        node = node->parent->parent;
      } else {
        if (node == node->parent->left) {
          // Случай 2: Дядя черный и узел - левый потомок
          node = node->parent;
          rotate_right(node);
        }
        // Случай 3: Дядя черный и узел - правый потомок
        node->parent->isRed = false;
        node->parent->parent->isRed = true;
        rotate_left(node->parent->parent);
      }
    }
  }
  root()->isRed = false;
}

template <class Key, class T, class KeyVal>
typename s21::__tree<Key, T, KeyVal>::point_node
s21::__tree<Key, T, KeyVal>::_erase_node(point_node del) {
  if (del == nullptr || del == _nil) return nullptr;
  __size--;
  if (del == root() && del->left == _nil && del->right == _nil) {
    clear();
    return nullptr;
  }
  if (del == _node_end()) {
    _node_end() = (del->left == _nil) ? del->parent : del->left;
  }
  if (del == _node_begin()) {
    _node_begin() = (del->right == _nil) ? del->parent : del->right;
  }
  point_node pos_child;
  point_node pos_replac;
  if (del->left == _nil || del->right == _nil) {
    pos_child = del;
  } else {
    pos_child = del->right;
    while (pos_child->left != _nil) pos_child = pos_child->left;
  }
  if (pos_child->left != _nil) {
    pos_replac = pos_child->left;
  } else
    pos_replac = pos_child->right;

  pos_replac->parent = pos_child->parent;

  if (pos_child->parent != nullptr) {
    if (pos_child == pos_child->parent->left)
      pos_child->parent->left = pos_replac;
    else
      pos_child->parent->right = pos_replac;
  } else
    root() = pos_replac;
  if (del != pos_child) {
    del->data = pos_child->data;
    if (pos_child == _node_end()) _node_end() = del;
    if (pos_child == _node_begin()) _node_begin() = del;
  }
  if (!pos_child->isRed) {
    deleteFixup(pos_replac);
  }
  return pos_child;
}

template <class Key, class T, class KeyVal>
void s21::__tree<Key, T, KeyVal>::deleteFixup(point_node node) noexcept {
  while (node != root() && (node->isRed == 0)) {
    if (node == node->parent->left) {
      point_node broth = node->parent->right;
      //Случай 1 брат красный
      if (broth->isRed) {
        broth->isRed = 0;
        node->parent->isRed = 1;
        rotate_left(node->parent);
        broth = node->parent->right;
      }
      //Случай 2 если правый и левы потомок черные и если брат черный,вершина
      //красная
      if (!broth->left->isRed && !broth->right->isRed) {
        broth->isRed = 1;
        node = node->parent;
      } else {
        //Случай 3 брат черный его правый потомок тоже черный
        if (!broth->right->isRed) {
          broth->isRed = 1;
          broth->left->isRed = 0;
          rotate_right(broth);
          broth = node->parent->right;
        }
        //Случай 4 финал
        broth->isRed = node->parent->isRed;
        node->parent->isRed = 0;
        broth->right->isRed = 0;
        rotate_left(node->parent);
        node = root();
      }
    } else {
      point_node broth = node->parent->left;
      //Случай 1 брат красный
      if (broth->isRed) {
        broth->isRed = 0;
        node->parent->isRed = 1;
        rotate_right(node->parent);
        broth = node->parent->left;
      }
      //Случай 2 если правый и левы потомок черные и если брат черный, вершина
      // //красная
      if (!broth->right->isRed && !broth->left->isRed) {
        broth->isRed = 1;
        node = node->parent;
      } else {
        //Случай 3 брат черный его правый потомок тоже черный
        if (!broth->left->isRed) {
          broth->isRed = 1;
          broth->right->isRed = 0;
          rotate_left(broth);
          broth = node->parent->left;
        }
        //Случай 4 финал
        broth->isRed = node->parent->isRed;
        node->parent->isRed = 0;
        broth->left->isRed = 0;
        rotate_right(node->parent);
        node = root();
      }
    }
  }
  node->isRed = 0;
}
#include "support.cc"
#endif  // SRC_S21_CONTAINERS_RBTREE___TREE_H_
