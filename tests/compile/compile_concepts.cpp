#include <type_traits>
#include <shijima/shijima.hpp>

template <class T>
concept AddOneable = requires(T v) {
  { shijima::add_one(v) } -> std::same_as<T>;
};

static_assert(AddOneable<int>);
static_assert(!AddOneable<void*>); // 例：意図的に落とす/通す条件を作る

int main() { return 0; }
