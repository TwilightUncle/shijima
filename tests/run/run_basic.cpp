#include <shijima/shijima.hpp>
#include <cassert>
#include <string_view>

int main() {
  std::string_view v = shijima::version();
  assert(!v.empty());

  int x = 41;
  assert(shijima::add_one(x) == 42);
  return 0;
}
