#include <type_traits>
#include <iostream>

template <char ...c> struct TString {
    static constexpr char characters[sizeof...(c) + 1] = {c..., '\0'};
};

template <typename CharT, CharT ...c>
constexpr TString<c...> operator"" _s() {
    return {};
}

template <char ...c1, char ...c2>
constexpr auto operator==(TString<c1...>, TString<c2...>) {
  return std::is_same<TString<c1...>, TString<c2...>>{};
}

template <char ...c1, char ...c2>
constexpr auto operator+(TString<c1...>, TString<c2...>) {
  return TString<c1..., c2...>{};
}

int main() {
    constexpr auto hello = "hello"_s + " world"_s;
    static_assert(hello == "hello world"_s);
    return 0;
}
