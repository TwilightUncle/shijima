#include <shijima/shijima.hpp>
#include <cassert>

int odr_a();
int odr_b();

int main() {
  // 2つのTUから同じヘッダのinline/template を参照してリンクする
  assert(odr_a() == 2);
  assert(odr_b() == 3);
  return 0;
}
