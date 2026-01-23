$ErrorActionPreference = "Stop"

Write-Host "== MSVC ==" -ForegroundColor Cyan
cmake --preset msvc-release
cmake --build --preset msvc-release
ctest --preset msvc-release

Write-Host "== WSL GCC ==" -ForegroundColor Cyan
wsl cmake --preset wsl-gcc-release
wsl cmake --build --preset wsl-gcc-release
wsl ctest --preset wsl-gcc-release

Write-Host "== WSL Clang ==" -ForegroundColor Cyan
wsl cmake --preset wsl-clang-release
wsl cmake --build --preset wsl-clang-release
wsl ctest --preset wsl-clang-release

Write-Host "All done." -ForegroundColor Green
