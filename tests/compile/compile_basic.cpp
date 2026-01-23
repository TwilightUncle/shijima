#include <shijima/shijima.hpp>

static_assert(shijima::add_one(1) == 2);
static_assert(shijima::version().size() > 0);

int main() { return 0; } // 実行しない想定だが TU として成立させる
