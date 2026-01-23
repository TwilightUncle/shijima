// 動作要件の強制(ひな形)
// #if defined(__clang__) && !defined(_MSC_VER)
//   #if __clang_major__ < 16
//     #error "shijima requires Clang 16 or later."
//   #endif
// #elif defined(__GNUC__) && !defined(__clang__)
//   #if __GNUC__ < 11
//     #error "shijima requires GCC 11 or later."
//   #endif
// #elif defined(_MSC_VER)
//   // _MSC_VER: 1930=VS2022, 1920=VS2019 など
//   #if _MSC_VER < 1930
//     #error "shijima requires MSVC (Visual Studio 2022 / v143) or later."
//   #endif
// #endif

#pragma once
#include <string_view>

namespace shijima {

    // ヘッダオンリーの例：inline 関数
    inline constexpr std::string_view version() noexcept { return "0.1.0"; }

    // テンプレート例（実体化させてコンパイラ差分を拾う）
    template <class T>
    constexpr T add_one(T v) noexcept { return static_cast<T>(v + 1); }

} // namespace yourlib
