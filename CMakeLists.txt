cmake_minimum_required(VERSION 3.20)
project(shijima VERSION 0.1.0 LANGUAGES CXX)

# --- 基本設定 ---
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# --- ヘッダオンリーを INTERFACE で表現 ---
add_library(shijima INTERFACE)
target_include_directories(shijima INTERFACE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

# MSVCに既定の文字コードを伝える
if (MSVC)
  target_compile_options(shijima INTERFACE /utf-8)
endif()

# --- テスト ---
include(CTest)
if(BUILD_TESTING)
  add_subdirectory(tests)
endif()
