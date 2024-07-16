#ifndef SRC_S21_CONTAINERS_VECTOR_S21_VECTOR_H_
#define SRC_S21_CONTAINERS_VECTOR_S21_VECTOR_H_
#include <initializer_list>

namespace s21 {
template <typename T>
class Vector {
 public:
  // Определение типа элемента вектора
  using value_type = T;
  // Определение типа ссылки на элемент вектора
  using reference = T&;
  // Определение типа константной ссылки на элемент вектора
  using const_reference = const T&;
  // Определение типа размера вектора
  using size_type = size_t;

 private:
  T* data_;
  size_type sizeVector;
  size_type capacityVector;

 public:
  //----------------------------- Iterator ------------------
  class VectorIterator;
  class VectorConstIterator;
  // Определение типа итератора для обхода вектора
  using iterator = VectorIterator;
  // Определение типа константного итератора для обхода вектора
  using const_iterator = VectorConstIterator;

  class VectorIterator {
   public:
    using value_type = T;
    using reference = T&;
    using pointer = T*;
    using difference_type = std::ptrdiff_t;
    VectorIterator();
    VectorIterator(pointer ptr);
    reference operator*() const;
    pointer operator->();
    VectorIterator& operator++();
    VectorIterator operator++(int);
    VectorIterator& operator--();
    VectorIterator operator--(int);
    VectorIterator& operator+=(difference_type n);
    VectorIterator operator+(difference_type n) const;
    VectorIterator& operator-=(difference_type n);
    VectorIterator operator-(difference_type n) const;
    difference_type operator-(const VectorIterator& other) const;
    bool operator==(const VectorIterator& other) const;
    bool operator!=(const VectorIterator& other) const;
    bool operator<(const VectorIterator& other) const;
    bool operator>(const VectorIterator& other) const;
    bool operator<=(const VectorIterator& other) const;
    bool operator>=(const VectorIterator& other) const;

   private:
    pointer current;
    friend class Vector;
  };

  class VectorConstIterator {
   public:
    using value_type = T;
    using reference = const T&;
    using pointer = const T*;
    using difference_type = std::ptrdiff_t;
    VectorConstIterator();
    VectorConstIterator(pointer ptr);
    reference operator*();
    pointer operator->();
    VectorConstIterator& operator++();
    VectorConstIterator operator++(int);
    VectorConstIterator& operator--();
    VectorConstIterator operator--(int);
    VectorConstIterator& operator+=(difference_type n);
    VectorConstIterator operator+(difference_type n) const;
    VectorConstIterator& operator-=(difference_type n);
    VectorConstIterator operator-(difference_type n) const;
    difference_type operator-(const VectorConstIterator& other) const;
    bool operator==(const VectorConstIterator& other) const;
    bool operator!=(const VectorConstIterator& other) const;
    bool operator<(const VectorConstIterator& other) const;
    bool operator>(const VectorConstIterator& other) const;
    bool operator<=(const VectorConstIterator& other) const;
    bool operator>=(const VectorConstIterator& other) const;

   private:
    pointer current;
    friend class Vector;
  };
  //----------------------------------------------------------------------------------------------------------------

  /**
   * \brief Конструктор Vector() создает пустой вектор, не выделяя память под
   * элементы. \throws Нет исключений. \return Нет возвращаемого значения.
   */
  Vector() noexcept;
  /**
   * \brief Конструктор Vector(size_type n) создает вектор размера n и
   * инициализирует его элементы значениями по умолчанию типа T. \param n Размер
   * создаваемого вектора. \throws std::bad_alloc, если не удалось выделить
   * память под элементы. \return Нет возвращаемого значения.
   */
  Vector(size_type n);
  /**
   * \brief Деструктор ~Vector() освобождает выделенную память и уничтожает
   * объект вектора. \throws Нет исключений. \return Нет возвращаемого значения.
   */
  ~Vector() noexcept;
  /**
   * \brief Конструктор Vector(std::initializer_list<value_type> const
   * &items) создает вектор, инициализируя его элементами из списка
   * инициализации items. \param items Список инициализации элементами для
   * вектора. \throws std::bad_alloc, если не удалось выделить память под
   * элементы. \return Нет возвращаемого значения.
   */
  Vector(std::initializer_list<value_type> const& items);
  /**
   * \brief Конструктор Vector(const Vector<T> &v) создает копию вектора
   * `v`, инициализируя данный вектор его элементами. \param v Вектор, который
   * будет скопирован. \throws std::bad_alloc, если не удалось выделить память
   * под элементы. \return Нет возвращаемого значения.
   */
  Vector(const Vector& v);
  /**
   * \brief Конструктор Vector(Vector &&v) создает вектор, перемещая
   * данные из вектора `v` и оставляя `v` в пустом состоянии. \param v Вектор,
   * из которого будут перемещены данные. \throws Нет исключений. \return Нет
   * возвращаемого значения.
   */
  Vector(Vector&& v);
  /**
   * \brief Оператор присваивания operator=(Vector &&v) выполняет перемещение
   * данных из вектора `v` в текущий вектор, оставляя `v` в пустом состоянии.
   * \param v Вектор, из которого будут перемещены данные.
   * \throws Нет исключений.
   * \return Ссылку на текущий вектор после присваивания.
   */
  Vector& operator=(Vector&& v);
  Vector& operator=(Vector& v);
  /**
   * \brief Функция void clear() очищает вектор, освобождая выделенную память и
   * сбрасывая его размеры в ноль. \throws Нет исключений. \return Нет
   * возвращаемого значения.
   */
  void clear() noexcept;
  /**
   * \brief Функция size_type size()возвращает текущий размер вектора, то есть
   * количество его элементов. \throws Нет исключений. \return Размер вектора.
   */
  size_type size() const noexcept;
  /**
   * \brief Функция size_type smax_size() возвращает максимально возможный
   * размер вектора, учитывая ограничения системы. \throws Нет исключений.
   * \return Максимально возможный размер вектора.
   */
  size_type max_size() const noexcept;
  /**
   * \brief Функция VectorIterator begin() возвращает итератор, указывающий
   * на начало вектора. \throws Нет исключений. \return Итератор, указывающий на
   * начало вектора.
   */
  VectorIterator begin() noexcept;
  VectorConstIterator cbegin() const noexcept;
  /**
   * \brief Функция VectorIterator end() возвращает итератор, указывающий на
   * конец вектора. \throws Нет исключений. \return Итератор, указывающий на
   * конец вектора.
   */
  VectorIterator end() noexcept;
  VectorConstIterator cend() const noexcept;
  /**
   * \brief Функция const_reference front() возвращает ссылку на первый элемент
   * вектора. \throws std::out_of_range если вектор пуст. \return Ссылка на
   * первый элемент вектора.
   */
  const_reference front() const;
  /**
   * \brief Функция const_reference back() возвращает ссылку на последний
   * элемент вектора. \throws std::out_of_range если вектор пуст. \return Ссылка
   * на последний элемент вектора.
   */
  const_reference back() const;
  /**
   * \brief Оператор [] T& operator[](size_type pos) возвращает ссылку на
   * элемент вектора по заданному индексу без проверки выхода за границы. \param
   * pos Индекс элемента, на который будет возвращена ссылка. \return Ссылка на
   * элемент вектора.
   */
  T& operator[](size_type pos) const;
  T& operator[](size_type pos);
  /**
   * \brief Функция reference at(size_type pos) возвращает ссылку на элемент
   * вектора по заданному индексу, проверяя выход за границы. \param pos Индекс
   * элемента, на который будет возвращена ссылка. \throws std::out_of_range
   * если индекс выходит за границы вектора. \return Ссылка на элемент вектора.
   */
  const_reference at(size_type pos) const;
  reference at(size_type pos);
  /**
   * \brief Функция T* data() предоставляет прямой доступ к базовому массиву
   * элементов вектора. \throws Нет исключений. \return Указатель на базовый
   * массив элементов вектора.
   */
  T* data() noexcept;
  /**
   * \brief Функция bool empty() проверяет, пуст ли вектор.
   * \throws Нет исключений.
   * \return `true`, если вектор пуст, и `false`, если не пуст.
   */
  bool empty() const noexcept;
  /**
   * \brief Функция void reserve(size_type size) выделяет дополнительную память
   * для хранения указанного количества элементов вектора, если это необходимо.
   * \param size Количество элементов, для которых нужно выделить память.
   * \throws std::bad_alloc в случае неудачи при выделении памяти.
   */
  void reserve(size_type size);
  /**
   * \brief Функция size_type capacity() const возвращает текущую емкость
   * вектора, то есть количество элементов, для которых выделена память. \return
   * Текущая емкость вектора.
   */
  size_type capacity() const noexcept;
  /**
   * \brief Функция void s21::Vector<T>::shrink_to_fit() уменьшает выделенную
   * память вектора до минимально необходимого размера, чтобы уменьшить его
   * потребление памяти. \throws std::bad_alloc в случае неудачи при выделении
   * памяти.
   */
  void shrink_to_fit();
  /**
   * \brief Функция VectorIteratorinsert(VectorIterator pos,
   * const_reference value) вставляет элемент со значением `value` в вектор по
   * указанной позиции `pos`. \param pos Итератор, указывающий на позицию, куда
   * нужно вставить элемент. \param value Значение, которое нужно вставить в
   * вектор. \return Итератор, указывающий на вставленный элемент. \throws
   * std::out_of_range в случае недопустимой позиции `pos`. \throws
   * std::bad_alloc в случае неудачи при выделении памяти.
   */
  VectorConstIterator insert(VectorConstIterator pos, const_reference value);
  VectorIterator insert(VectorIterator pos, const_reference value);
  /**
   * \brief Функция void erase(VectorIterator pos) удаляет элемент из
   * вектора, находящийся на позиции `pos`. \param pos Итератор, указывающий на
   * позицию элемента, который нужно удалить. \throws std::out_of_range в случае
   * недопустимой позиции `pos`.
   */
  void erase(VectorIterator pos);
  void erase(VectorConstIterator pos);
  /**
   * \brief Функция void push_back(const_reference value) добавляет элемент со
   * значением `value` в конец вектора. \param value Значение, которое нужно
   * добавить в конец вектора. \throws std::bad_alloc в случае неудачи при
   * выделении памяти.
   */
  void push_back(const_reference value);
  /**
   * \brief Функция void pop_back() удаляет последний элемент из вектора, если
   * вектор не пуст. \throws Нет исключений.
   */
  void pop_back() noexcept;
  /**
   * \brief Функция void swap(Vector& other) обменивает содержимое данного
   * вектора с содержимым другого вектора `other`. \throws Нет исключений.
   * \param other Другой вектор, с которым нужно обменять содержимое.
   */
  void swap(Vector& other) noexcept;
  /**
   * \brief  Функция VectorIterator insert_many(VectorConstIterator pos,
   * Args&&... args); вставляет элементы, переданные в аргументах `args`, в
   * вектор, начиная с позиции `pos`. \param pos Итератор, указывающий на
   * позицию, с которой начнется вставка. \param args Аргументы, представляющие
   * элементы, которые нужно вставить в вектор. \throws std::out_of_range в
   * случае недопустимой позиции `pos`. \throws std::bad_alloc в случае неудачи
   * при выделении памяти. \return Итератор, указывающий на позицию после
   * последнего вставленного элемента.
   */
  template <typename... Args>
  VectorIterator insert_many(VectorIterator pos, Args&&... args);
  template <typename... Args>
  VectorIterator insert_many(VectorConstIterator pos, Args&&... args);

  /**
   * \brief Функция void insert_many_back(Args&&... args) вставляет элементы,
   * переданные в аргументах `args`, в вектор в конец, начиная с текущей
   * позиции. \param args Аргументы, представляющие элементы, которые нужно
   * вставить в вектор. \throws std::bad_alloc в случае неудачи при выделении
   * памяти. \return Нет возвращаемого значения.
   */
  template <typename... Args>
  void insert_many_back(Args&&... args);

 private:
  /**
   * \brief Функция void initializeEmptyVector(Vector<T>& data_)  Функция
   * выполняет обнуление (сброс) состояния вектора `data_`. \throws Нет
   * исключений. \param data_ Вектор, состояние которого требуется обнулить.
   */
  void initializeEmptyVector() noexcept;
  /**
   * \brief Функция newCapacityVector() обновляет вместимость вектора, если
   * необходимо. \throws Нет исключений. \param data_ Вектор, для которого
   * требуется обновить вместимость.
   */
  void newCapacityVector() noexcept;
};
}  // namespace s21
#include "s21_vector.cc"
#include "s21_vectorIterator.cc"
#endif  // SRC_S21_CONTAINERS_VECTOR_S21_VECTOR_H_
