namespace s21 {
template <typename Arg, typename Result>
struct UnaryFunction {
  using arg_type = Arg;
  using res_type = Result;
};

template <typename T>
struct Value : public UnaryFunction<T, T> {
  T &operator()(T &x) const { return x; }
  const T &operator()(const T &x) const { return x; }
};

template <typename Pair>
struct First_Value : public UnaryFunction<Pair, typename Pair::first_type> {
  typename Pair::first_type &operator()(Pair &x) const { return x.first; }

  const typename Pair::first_type &operator()(const Pair &x) const {
    return x.first;
  }
};
}  // namespace s21