#ifndef SRC_S21_CONTAINERS_LIST_S21_LIST_H_
#define SRC_S21_CONTAINERS_LIST_S21_LIST_H_
#include <algorithm>  // Include for min
#include <deque>  // Для использования deque_type::value_type для функции max_size()
#include <initializer_list>  // для инцилизации в List(std::initializer_list<value_type> const &items);
#include <limits>  // Для использования std::numeric_limits для для функции max_size()
#include <memory>  // Для использования __node_alloc_traits для для функции max_size()

namespace s21 {
template <typename T>
class List {
 public:
  // Определение типа элемента контейнера
  using value_type = T;
  // Определение типа ссылки на элемент контейнера
  using reference = T&;
  // Определение типа константной ссылки на элемент контейнера
  using const_reference = const T&;
  // Определение типа размера контейнера
  using size_type = size_t;
  // #include <deque>
  using deque_type = std::deque<T>;

 private:
  struct Node {
    T data;
    Node* next = nullptr;
    Node* prev = nullptr;
  };
  Node* head;
  Node* tail;
  size_type sizeList;

 public:
  class ListIterator;
  class ListConstIterator;
  // Определение типа итератора для обхода контейнера
  using iterator = ListIterator;
  // Определение типа константного итератора для обхода контейнера
  using const_iterator = ListConstIterator;

  // --------------------------------- Iterator
  class ListIterator {
   public:
    using reference = T&;
    using pointer = T*;
    ListIterator();
    ListIterator(const_iterator it);
    ListIterator(typename s21::List<T>::Node* node);
    ListIterator(typename s21::List<T>::Node* node,
                 typename s21::List<T>::Node* last_node);

    reference operator*();
    pointer operator->() const;
    ListIterator& operator++();
    ListIterator operator++(int);
    ListIterator& operator--();
    ListIterator operator--(int);
    bool operator==(const ListIterator& other) const;
    bool operator!=(const ListIterator& other) const;

   private:
    Node* m_node;
    Node* last_node;
    friend class List;
  };

  class ListConstIterator {
   public:
    using reference = const T&;
    using pointer = const T*;

    ListConstIterator();
    ListConstIterator(iterator it);
    ListConstIterator(typename s21::List<T>::Node* node);
    ListConstIterator(typename s21::List<T>::Node* node,
                      typename s21::List<T>::Node* last_node);

    reference operator*();
    pointer operator->() const;
    ListConstIterator& operator++();
    ListConstIterator operator++(int);
    ListConstIterator& operator--();
    ListConstIterator operator--(int);
    bool operator==(const ListConstIterator& other) const;
    bool operator!=(const ListConstIterator& other) const;

   private:
    Node* m_node;
    Node* last_node;
    friend class List;
  };

 public:
  /**
   * \brief Оператор перемещения begin() возвращает итератор, указывающий на
   * первый элемент списка. \throws Нет исключений. \return Итератор,
   * указывающий на первый элемент списка.
   */
  iterator begin() const noexcept;
  /**
   * \brief Оператор перемещения cbegin() возвращает итератор, указывающий на
   * первый элемент списка. \throws Нет исключений. \return Итератор,
   * указывающий на первый элемент списка.
   */
  const_iterator cbegin() const noexcept;

  /**
   * \brief Оператор перемещения end() возвращает итератор, указывающий на
   * последний элемент списка. \throws Нет исключений. \return Итератор,
   * указывающий на последний элемент списка.
   */
  iterator end() const noexcept;
  /**
   * \brief Оператор перемещения end() возвращает итератор, указывающий на
   * последний элемент списка. \throws Нет исключений. \return Итератор,
   * указывающий на последний элемент списка.
   */
  const_iterator cend() const noexcept;
  /**
   * \brief Метод front() возвращает константный итератор, указывающий на первый
   * элемент списка. \throws Нет исключений. \return Константный итератор,
   * указывающий на первый элемент списка.
   */
  const_reference front() const;

  /**
   * \brief Метод back() возвращает константный итератор, указывающий на
   * последний элемент списка. \throws Нет исключений. \return Константный
   * итератор, указывающий на последний элемент списка.
   */
  const_reference back() const;

  // -----------------------------------------------------------------------------------

  /**
   * \brief Базовый конструктор list() инициализирует объект класса List.
   * \throws Нет исключений.
   * \return Новый объект класса List.
   */
  List() noexcept;
  /**
   * \brief Базовый деструктор ~list() освобождает ресурсы, занимаемые объектом
   * класса List. \throws Нет исключений. \return Нет возвращаемого значения.
   */
  ~List() noexcept;
  /**
   * \brief Конструктор list(size_type n) создает список определенного размера,
   * или с элементами определенного значения, или с определенным allocator, или
   * в качестве копии какого-либо другого списка.. \throws При передаче
   * параметров отрицательного значения. \throws При неудчном выделении памяти
   * new. \return Новый объект класса List.
   */
  List(size_type n);
  /**
   * \brief Конструктор list(std::initializer_list<value_type> const &items)
   * создает список на основе переданного списка инициализации. \param items
   * Список инициализации, содержащий элементы, которые будут добавлены в новый
   * список. \throws При  неудчном выделении памяти new. \return Новый объект
   * класса List.
   */
  List(std::initializer_list<value_type> const& items);
  /**
   * \brief Конструктор копирования list(const list &l) создает новый список на
   * основе переданного списка, используя копирование. \param l Список, на
   * основе которого будет создан новый список. \throws Нет исключений. \return
   * Новый объект класса List, содержащий элементы из списка l.
   */
  List(const List& l);
  /**
  \brief Конструктор перемещения list(const list &&l) создает новый список на
  основе переданного списка, используя перемещение. \param l Список, на основе
  которого будет создан новый список. \throws Нет исключений. \return Новый
  объект класса List, содержащий элементы из списка l.
  */
  List(List&& l) noexcept;
  /**
   * \brief Оператор перемещения list(const list &&l) перемещает элементы из
   * переданного списка в новый список. \param l Список, из которого будут
   * перемещены элементы. \throws Нет исключений. \return Новый объект класса
   * List, содержащий перемещенные элементы из списка l.
   */
  List& operator=(List&& l);
  List& operator=(const List& other);
  /**
   * \brief Метод clear() очищает список, удаляя все его элементы.
   * \throws Нет исключений.
   * \return Ничего не возвращает.
   */
  void clear() noexcept;
  /**
   * \brief Оператор empty() проверяет, пуст ли список, возвращая значение true,
   * если список не содержит элементов, и false в противном случае. \throws Нет
   * исключений. \return Значение true, если список пуст, иначе - false.
   */
  bool empty() const noexcept;
  /**
   * \brief Функция max_size() возвращает максимально возможный размер списка.
   * Функция использует std::numeric_limits<size_type>::max() для получения
   * наибольшего значения типа size_type, который определен в классе
   * s21::List<T>. Затем она выполняет деление этого значения на sizeof(typename
   * deque_type::value_type) и еще дополнительно на 2. Это делается для
   * определения максимального количества элементов, которые можно хранить в
   * листе, основываясь на размере элемента и ограничениях системы. \throws Нет
   * исключений. \return size_type - значение максимального размера списка.
   */
  size_type max_size() const noexcept;
  /**
   * \brief Функция size() узнает текущий размер списка.
   * \throws Нет исключений.
   * \return size_type - размер списка s21::List<T> в виде значения.
   */
  size_type size() const noexcept;
  /**
   * \brief Функция insert(iterator pos, const_reference value) вставляет
   * элемент со значением value в позицию, указанную итератором pos. \throws
   * std::out_of_range если список пустой. Исключение генерируется в функции
   * pop_front/pop_back. \return Итератор типа typename s21::List<T>::iterator,
   * указывающий на вставленный элемент списка.
   */
  iterator insert(iterator pos, const_reference value);
  const_iterator insert(const_iterator pos, const_reference value);
  /**
   * \brief Функция push_back(const_reference value) добавляет элемент со
   * значением value в конец списка. \param value Значение элемента, которое
   * будет добавлено в список. \throws std::bad_alloc если выделение памяти для
   * нового узла не удалось. \return Нет возвращаемого значения. */
  void push_back(const_reference value);
  /**
   * \brief Функция push_front(const_reference value) добавляет элемент со
   * значением value в начало списка. \param value Значение элемента, которое
   * будет добавлено в список. \throws std::bad_alloc если выделение памяти для
   * нового узла не удалось. \return Нет возвращаемого значения.
   */
  void push_front(const_reference value);
  /**
   * \brief Функция pop_back() удаляет последний элемент в списке.
   * \throws std::out_of_range если список пустой.
   * \return Нет возвращаемого значения.
   */
  void pop_back();
  /**
   * \brief Функция pop_back() удаляет первый элемент в списке.
   * \throws std::out_of_range если список пустой.
   * \return Нет возвращаемого значения.
   */
  void pop_front();
  /**
   * \brief Функция erase(iterator pos) удаляет элемент, указанный итератором
   * pos, из списка. \param[in] pos Итератор, указывающий на элемент, который
   * нужно удалить. \throws std::out_of_range если список пустой. Исключение
   * генерируется в функции pop_front/pop_back. \return Нет возвращаемого
   * значения.
   */
  void erase(iterator pos);
  void erase(const_iterator pos);
  /**
   * \brief Функция swap(List& other) обменивает содержимое двух списков.
   * \param other Ссылка на другой список, с которым нужно обменять содержимое.
   * \throws Нет исключений.
   * \return Нет возвращаемого значения.
   */
  void swap(List& other) noexcept;
  /**
   * \brief Функция merge(List& other) объединяет содержимое двух списков.
   * \param other Ссылка на другой список, с которым нужно объединить
   * содержимое. \throws std::bad_alloc если выделение памяти для нового узла не
   * удалось. Исключение генерируется в функции push_back. \return Нет
   * возвращаемого значения.
   */
  void merge(List& other);
  /**
   * \brief Функция splice вставляет содержимое одного списка в другой на
   * заданной позиции. \param pos Итератор, указывающий на позицию в текущем
   * списке, куда нужно вставить содержимое другого списка. \param other Ссылка
   * на другой список, содержимое которого будет вставлено в текущий список.
   * \throws std::out_of_range если текущий список или другой список пуст, или
   * если попытка объединения списка с самим собой. \return Нет возвращаемого
   * значения.
   */
  void splice(const_iterator pos, List& other);
  void splice(iterator pos, List& other);
  /**
   * \brief Функция void reverse() инвертирует порядок элементов в списке.
   * \details Функция изменяет текущий список, переставляя элементы в обратном
   * порядке. \throws Нет исключений. \return Нет возвращаемого значения.
   */
  void reverse() noexcept;

  /**
   * \brief Функция void unique() удаляет идущие друг за другом дубликаты из
   * списка. \details Эта функция просматривает текущий список и удаляет все
   * повторяющиеся элементы, оставляя только уникальные значения. \throws Нет
   * исключений. \return Нет возвращаемого значения.
   */
  void unique() noexcept;

  /**
   * \brief Функция void sort() сортирует элементы списка по возрастанию.
   * \details Эта функция изменяет текущий список, упорядочивая его элементы в
   * порядке возрастания. \throws Нет исключений. \return Нет возвращаемого
   * значения.
   */
  void sort() noexcept;

  /**
   * \brief Функция ListIterator insert_many(ListConstIterator pos,
   * Args&&... args) вставляет элементы из аргументов `args` в список, начиная с
   * указанной позиции `pos`. \param pos Итератор, указывающий на позицию, с
   * которой начнется вставка. \param args Аргументы, представляющие элементы,
   * которые нужно вставить в список. \throws std::bad_alloc если выделение
   * памяти для нового узла не удалось. \return Итератор, указывающий на позицию
   * последнего вставленного элемента.
   */
  template <typename... Args>
  ListIterator insert_many(ListConstIterator pos, Args&&... args);
  template <typename... Args>
  ListIterator insert_many(ListIterator pos, Args&&... args);

  /**
   * \brief Функция void insert_many_back(Args&&... args) вставляет элементы из
   * аргументов `args` в конец списка. \param args Аргументы, представляющие
   * элементы, которые нужно вставить в конец списка. \throws std::bad_alloc
   * если выделение памяти для нового узла не удалось.
   */
  template <typename... Args>
  void insert_many_back(Args&&... args);

  /**
   * \brief Функция void insert_many_back(Args&&... args) вставляет элементы из
   * аргументов `args` в начало списка. \param args Аргументы, представляющие
   * элементы, которые нужно вставить в начало списка. \throws std::bad_alloc
   * если выделение памяти для нового узла не удалось.
   */
  template <typename... Args>
  void insert_many_front(Args&&... args);

 private:
  /**
   * \brief Функция initializeEmptyList обнуляет поля объекта List.
   * \details Эта функция устанавливает указатели head и tail в nullptr и
   * сбрасывает размер списка в 0, эффективно обнуляя содержимое списка. \param
   * NodeZero Ссылка на объект List, который нужно обнулить. \throws Нет
   * исключений. \return Нет возвращаемого значения.
   */
  void initializeEmptyList(s21::List<T>& NodeZero) noexcept;
};
}  // namespace s21

#include "s21_ListIterator.cc"
#include "s21_list.cc"
#endif  // SRC_S21_CONTAINERS_LIST_S21_LIST_H_
