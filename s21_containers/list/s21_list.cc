#include "s21_list.h"

#include <list>
template <typename T>
s21::List<T>::List() noexcept {
  initializeEmptyList(*this);
}

template <typename T>
void s21::List<T>::initializeEmptyList(s21::List<T>& NodeZero) noexcept {
  NodeZero.head = nullptr;
  NodeZero.tail = nullptr;
  NodeZero.sizeList = 0;
}

template <typename T>
void s21::List<T>::clear() noexcept {
  Node* tmp = head;
  while (tmp != nullptr) {
    Node* nextTmp = tmp->next;
    delete tmp;
    tmp = nextTmp;
  }
  initializeEmptyList(*this);
}

template <typename T>
s21::List<T>::~List() noexcept {
  clear();
}

template <typename T>
s21::List<T>::List(size_type n) {
  initializeEmptyList(*this);
  if (n <= 0 || n >= max_size()) {
    throw std::out_of_range("Invalid value for memory allocation");
  } else {
    sizeList = n;
    try {
      for (size_type i = 0; i != sizeList; i++) {
        Node* newNode = new Node();
        if (head == nullptr) {
          head = newNode;
          tail = newNode;
        } else {
          tail->next = newNode;
          newNode->prev = tail;
          tail = newNode;
        }
        newNode->data = 0;
      }
    } catch (const std::bad_alloc& e) {
      clear();
      throw;
    }
  }
}

template <typename T>
s21::List<T>::List(std::initializer_list<value_type> const& items) {
  initializeEmptyList(*this);
  if (items.size() == 0) return;
  try {
    //  цикл "for-each" (или "range-based for loop"), который перебирает
    //  элементы в переданном объекте items типа
    //  std::initializer_list<value_type>.
    for (const auto& item : items) {
      Node* newNode = new Node();
      newNode->data = item;
      if (head == nullptr) {
        head = newNode;
        tail = newNode;
      } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
      }
      sizeList++;
    }
  } catch (const std::bad_alloc& e) {
    clear();
    throw;
  }
}

template <typename T>
s21::List<T>::List(const List& l) : head(nullptr), tail(nullptr), sizeList(0) {
  if (l.size() == 0) return;
  try {
    Node* shiftNode = l.head;
    while (shiftNode != nullptr) {
      Node* newNode = new Node();
      newNode->data = T(shiftNode->data);
      if (head == nullptr) {
        head = newNode;
        tail = newNode;
      } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
      }
      sizeList++;
      shiftNode = shiftNode->next;
    }
  } catch (const std::bad_alloc& e) {
    clear();
    throw;
  }
}

template <typename T>
s21::List<T>::List(List&& l) noexcept
    : head(std::move(l.head)), tail(std::move(l.tail)), sizeList(l.sizeList) {
  initializeEmptyList(l);
}

template <typename T>
s21::List<T>& s21::List<T>::operator=(s21::List<T>&& l) {
  if (this != &l) {
    // Очищаем текущий список
    clear();

    // Перемещаем ресурсы из другого списка
    head = std::move(l.head);
    tail = std::move(l.tail);

    // Устанавливаем размер списка
    sizeList = 0;

    // Перемещаем размер из другого списка
    sizeList = l.sizeList;
    initializeEmptyList(l);
  }
  return *this;
}

template <typename T>
typename s21::List<T>::const_reference s21::List<T>::front() const {
  if (tail == nullptr) throw std::out_of_range("The list is empty");
  return head->data;
}

template <typename T>
typename s21::List<T>::const_reference s21::List<T>::back() const {
  if (tail == nullptr) throw std::out_of_range("The list is empty");
  return tail->data;
}

template <typename T>
typename s21::List<T>::iterator s21::List<T>::begin() const noexcept {
  return iterator(this->head);
}

template <typename T>
typename s21::List<T>::const_iterator s21::List<T>::cbegin() const noexcept {
  return const_iterator(this->head);
}

template <typename T>
typename s21::List<T>::iterator s21::List<T>::end() const noexcept {
  return iterator(nullptr, this->tail);
}

template <typename T>
typename s21::List<T>::const_iterator s21::List<T>::cend() const noexcept {
  return const_iterator(nullptr, this->tail);
}

template <typename T>
bool s21::List<T>::empty() const noexcept {
  return !sizeList;
}

template <typename T>
typename s21::List<T>::size_type s21::List<T>::size() const noexcept {
  return sizeList;
}

template <typename T>
typename s21::List<T>::size_type s21::List<T>::max_size() const noexcept {
  // return std::numeric_limits<size_type>::max() /
  //        sizeof(typename deque_type::value_type) / 2;
  return std::allocator<Node>().max_size();
}

template <typename T>
typename s21::List<T>::iterator s21::List<T>::insert(
    typename s21::List<T>::iterator pos, const_reference value) {
  if (pos == begin()) {
    push_front(value);
    pos = this->head;
  } else if (pos == end()) {
    push_back(value);
    pos = this->tail;
  } else {
    typename s21::List<T>::Node* newPos = pos.m_node;  // Куда вставить элемент
    typename s21::List<T>::Node* newValue = new typename s21::List<T>::Node();
    newValue->data = value;
    newValue->next = newPos;
    newValue->prev = newPos->prev;
    newPos->prev->next = newValue;
    newPos->prev = newValue;
    this->sizeList++;
    return iterator(newValue);
  }
  return pos;
}

template <typename T>
typename s21::List<T>::const_iterator s21::List<T>::insert(
    typename s21::List<T>::const_iterator pos, const_reference value) {
  if (pos == begin()) {
    push_front(value);
    pos = this->head;
  } else if (pos == end()) {
    push_back(value);
    pos = this->tail;
  } else {
    typename s21::List<T>::Node* newPos = pos.m_node;  // Куда вставить элемент
    typename s21::List<T>::Node* newValue = new typename s21::List<T>::Node();
    newValue->data = value;
    newValue->next = newPos;
    newValue->prev = newPos->prev;
    newPos->prev->next = newValue;
    newPos->prev = newValue;
    this->sizeList++;
    return iterator(newValue);
  }
  return pos;
}

template <typename T>
void s21::List<T>::erase(typename s21::List<T>::iterator pos) {
  if (pos == nullptr)
    return;
  else if (pos == begin())
    pop_front();
  else if (pos.m_node == this->tail)
    pop_back();
  else {
    Node* PosNode = pos.m_node;
    PosNode->prev->next = PosNode->next;
    PosNode->next->prev = PosNode->prev;
    delete PosNode;
    sizeList--;
  }
}

template <typename T>
void s21::List<T>::erase(typename s21::List<T>::const_iterator pos) {
  if (pos == nullptr)
    return;
  else if (pos == begin())
    pop_front();
  else if (pos.m_node == this->tail)
    pop_back();
  else {
    Node* PosNode = pos.m_node;
    PosNode->prev->next = PosNode->next;
    PosNode->next->prev = PosNode->prev;
    delete PosNode;
    sizeList--;
  }
}

template <typename T>
void s21::List<T>::push_back(typename s21::List<T>::const_reference value) {
  try {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;
    if (tail == nullptr) {
      head = tail = newNode;
      newNode->prev = nullptr;
    } else {
      tail->next = newNode;
      newNode->prev = tail;
      tail = newNode;
    }
    sizeList += 1;
  } catch (const std::bad_alloc& e) {
    clear();
    throw;
  }
}

template <typename T>
void s21::List<T>::push_front(typename s21::List<T>::const_reference value) {
  try {
    Node* NewNode = new Node();
    NewNode->data = value;
    NewNode->prev = nullptr;
    if (head == nullptr) {
      head = tail = NewNode;
    } else {
      head->prev = NewNode;
      NewNode->next = head;
      head = NewNode;
    }
    sizeList += 1;
  } catch (const std::bad_alloc& e) {
    clear();
    throw;
  }
}

template <typename T>
void s21::List<T>::pop_back() {
  if (tail == nullptr)
    throw std::out_of_range("The list is empty");
  else if (tail->prev == nullptr) {
    delete tail;
    head = tail = nullptr;
    sizeList = 0;
  } else {
    Node* TailNode = tail;
    tail = TailNode->prev;
    tail->next = nullptr;
    delete TailNode;
    sizeList--;
  }
}

template <typename T>
void s21::List<T>::pop_front() {
  if (head == nullptr)
    throw std::out_of_range("The list is empty");
  else if (head->next == nullptr) {
    delete head;
    head = tail = nullptr;
    sizeList = 0;
  } else {
    Node* HeadNode = head;
    head = HeadNode->next;
    HeadNode->prev = nullptr;
    delete HeadNode;
    sizeList--;
  }
}

template <typename T>
void s21::List<T>::swap(s21::List<T>& other) noexcept {
  std::swap(head, other.head);
  std::swap(tail, other.tail);
  std::swap(sizeList, other.sizeList);
}

template <typename T>
void s21::List<T>::merge(s21::List<T>& other) {
  s21::List<T> NewNode;
  Node* HeadOther = other.head;
  Node* HeadNode = this->head;
  while (HeadNode && HeadOther) {
    if (HeadNode->data <= HeadOther->data) {
      NewNode.push_back(HeadNode->data);
      HeadNode = HeadNode->next;
    } else {
      NewNode.push_back(HeadOther->data);
      HeadOther = HeadOther->next;
    }
  }
  while (HeadNode) {
    NewNode.push_back(HeadNode->data);
    HeadNode = HeadNode->next;
  }
  while (HeadOther) {
    NewNode.push_back(HeadOther->data);
    HeadOther = HeadOther->next;
  }
  this->swap(NewNode);
}

template <typename T>
void s21::List<T>::splice(typename s21::List<T>::const_iterator pos,
                          s21::List<T>& other) {
  if (this == &other || other.empty() || empty())
    throw std::out_of_range("Empty value");
  Node* PosNode = pos.m_node;
  Node* TailOther = other.tail;
  if (pos == cend()) PosNode = tail;
  if (PosNode->prev) PosNode->prev->next = other.head;
  if (other.head) other.head->prev = PosNode->prev;
  TailOther->next = PosNode;
  PosNode->prev = TailOther;
  if (PosNode == tail) tail = TailOther;
  sizeList += other.sizeList;
  other.sizeList = 0;
  if (pos.m_node == head) head = other.head;
  other.head = nullptr;
  other.tail = nullptr;
}

template <typename T>
void s21::List<T>::splice(typename s21::List<T>::iterator pos,
                          s21::List<T>& other) {
  if (this == &other || other.empty() || empty())
    throw std::out_of_range("Empty value");
  Node* PosNode = pos.m_node;
  Node* TailOther = other.tail;
  if (pos == cend()) PosNode = tail;
  if (PosNode->prev) PosNode->prev->next = other.head;
  if (other.head) other.head->prev = PosNode->prev;
  TailOther->next = PosNode;
  PosNode->prev = TailOther;
  if (PosNode == tail) tail = TailOther;
  sizeList += other.sizeList;
  other.sizeList = 0;
  if (pos.m_node == head) head = other.head;
  other.head = nullptr;
  other.tail = nullptr;
}

template <typename T>
void s21::List<T>::reverse() noexcept {
  if (head == nullptr || tail == nullptr || head == tail) return;

  Node* current = head;
  Node* prevNode = nullptr;

  while (current != nullptr) {
    Node* nextNode = current->next;
    current->next = prevNode;
    current->prev = nextNode;
    prevNode = current;
    current = nextNode;
  }

  Node* temp = head;
  head = tail;
  tail = temp;
}

template <typename T>
void s21::List<T>::unique() noexcept {
  if (head == nullptr || tail == nullptr) return;
  Node* HeadNode = head;
  while (HeadNode->next != nullptr) {
    if (HeadNode->next->data == HeadNode->data) {
      Node* NextNode = HeadNode->next;
      HeadNode->next = NextNode->next;
      if (NextNode == tail) tail = HeadNode;
      delete NextNode;
      sizeList--;
    } else
      HeadNode = HeadNode->next;
  }
}

template <typename T>
void s21::List<T>::sort() noexcept {
  if (head == nullptr || tail == nullptr) return;
  bool FlagSort = true;
  while (FlagSort) {
    FlagSort = false;
    Node* HeadNode = head;
    Node* NextNode = head->next;

    while (NextNode != nullptr) {
      if (NextNode->data < HeadNode->data) {
        T NumNode = NextNode->data;
        NextNode->data = HeadNode->data;
        HeadNode->data = NumNode;
        FlagSort = true;
      }
      HeadNode = HeadNode->next;
      NextNode = NextNode->next;
    }
  }
}

template <typename T>
template <typename... Args>
typename s21::List<T>::ListIterator s21::List<T>::insert_many(
    ListConstIterator pos, Args&&... args) {
  ListIterator newPos = ListIterator(pos.m_node);
  ListIterator newPosArg = ListIterator(pos.m_node);
  int flag = 0;
  if (pos == cbegin())
    flag = 1;
  else if (pos == cend())
    flag = 2;
  for (const auto& arg : {args...}) {
    if (flag == 1) newPos = begin();
    if (flag == 2) newPos = end();
    newPosArg = insert(newPos, arg);
    --newPos;
  }
  return newPosArg;
}

template <typename T>
template <typename... Args>
typename s21::List<T>::ListIterator s21::List<T>::insert_many(ListIterator pos,
                                                              Args&&... args) {
  ListIterator newPos = ListIterator(pos.m_node);
  ListIterator newPosArg = ListIterator(pos.m_node);
  int flag = 0;
  if (pos == cbegin())
    flag = 1;
  else if (pos == cend())
    flag = 2;
  for (const auto& arg : {args...}) {
    if (flag == 1) newPos = begin();
    if (flag == 2) newPos = end();
    newPosArg = insert(newPos, arg);
    --newPos;
  }
  return newPosArg;
}

template <typename T>
template <typename... Args>
void s21::List<T>::insert_many_back(Args&&... args) {
  for (const auto& arg : {std::forward<Args>(args)...}) push_back(arg);
}

template <typename T>
template <typename... Args>
void s21::List<T>::insert_many_front(Args&&... args) {
  for (const auto& arg : {std::forward<Args>(args)...}) push_front(arg);
}

template <typename T>
s21::List<T>& s21::List<T>::operator=(const s21::List<T>& other) {
  if (this != &other) {
    // Очищаем текущий список
    clear();

    // Копируем элементы из другого списка
    for (const auto& item : other) {
      push_back(item);
    }
  }
  return *this;
}
