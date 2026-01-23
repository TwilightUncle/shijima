# tests/ 配下では必ず親で enable_testing 済み (include(CTest)) の想定

# 共通：警告をできる範囲で上げる（最小限）
function(apply_common_warnings tgt)
  if (MSVC)
    target_compile_options(${tgt} PRIVATE /W4 /permissive-)
  else()
    target_compile_options(${tgt} PRIVATE -Wall -Wextra -Wpedantic)
  endif()
endfunction()

# ========== 1) compile-only tests ==========
add_executable(compile_basic
  ${CMAKE_CURRENT_SOURCE_DIR}/compile/compile_basic.cpp
)
add_executable(compile_concepts
  ${CMAKE_CURRENT_SOURCE_DIR}/compile/compile_concepts.cpp
)

target_link_libraries(compile_basic PRIVATE shijima)
target_link_libraries(compile_concepts PRIVATE shijima)

apply_common_warnings(compile_basic)
apply_common_warnings(compile_concepts)

# CTestへ「ビルドができたか」をテストとして登録（実行不要）
add_test(NAME compile_basic
  COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR} --target compile_basic
)
add_test(NAME compile_concepts
  COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR} --target compile_concepts
)

# ========== 2) ODR test ==========
# 複数TUをリンクして ODR/inline/テンプレ等の事故を踏む
add_executable(odr_test
  ${CMAKE_CURRENT_SOURCE_DIR}/odr/odr_main.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/odr/odr_a.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/odr/odr_b.cpp
)
target_link_libraries(odr_test PRIVATE shijima)
apply_common_warnings(odr_test)

add_test(NAME odr_test COMMAND odr_test)

# ========== 3) run tests ==========
add_executable(run_basic ${CMAKE_CURRENT_SOURCE_DIR}/run/run_basic.cpp)
target_link_libraries(run_basic PRIVATE shijima)
apply_common_warnings(run_basic)

add_test(NAME run_basic COMMAND run_basic)
