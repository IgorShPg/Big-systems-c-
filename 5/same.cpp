#include <type_traits>
#include <cstdint>

template <typename... Ts>
struct are_same;

template <>
struct are_same<> : std::true_type {};

template <typename T, typename U>
struct is_same_helper : std::is_same<std::remove_cv_t<std::remove_reference_t<T>>, std::remove_cv_t<std::remove_reference_t<U>>> {};


template <typename T, typename... Ts>
struct are_same<T, Ts...> : std::conjunction<is_same_helper<T, Ts>...> {};

template <typename... Ts>
constexpr bool are_same_v = are_same<Ts...>::value;

int main()
{
    static_assert(are_same_v<int, int32_t, signed int>, "compile assert");
    static_assert(!are_same_v<int, int32_t, unsigned int>, "compile assert");
    static_assert(are_same_v<int&, const int32_t, volatile signed int&&>, "compile assert");
    return 0;
}