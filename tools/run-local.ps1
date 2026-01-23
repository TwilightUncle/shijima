$ErrorActionPreference = "Stop"

Write-Host "== MSVC ==" -ForegroundColor Cyan
cmake --preset msvc-release
cmake --build --preset msvc-release
ctest --preset msvc-release

Write-Host "== WSL GCC ==" -ForegroundColor Cyan
wsl cmake --preset linux-gcc-release
wsl cmake --build --preset linux-gcc-release
wsl ctest --preset linux-gcc-release

Write-Host "== WSL Clang ==" -ForegroundColor Cyan
wsl cmake --preset linux-clang-release
wsl cmake --build --preset linux-clang-release
wsl ctest --preset linux-clang-release

Write-Host "All done." -ForegroundColor Green
