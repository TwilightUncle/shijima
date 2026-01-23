#pragma once
#include <string_view>

namespace shijima {

    // ヘッダオンリーの例：inline 関数
    inline constexpr std::string_view version() noexcept { return "0.1.0"; }

    // テンプレート例（実体化させてコンパイラ差分を拾う）
    template <class T>
    constexpr T add_one(T v) noexcept { return static_cast<T>(v + 1); }

} // namespace yourlib
