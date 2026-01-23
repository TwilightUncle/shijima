# shijima

コンパイル時の処理をまとめたライブラリ

ライブラリ名は静寂(しじま)より

## 開発環境

`Windows11`上で、`WSL2`を利用した開発を想定しています  

あらかじめ下記を用意しておく必要があります

- Windows:
  - 以下がインストール済みであること
    - Visual Studio 2022
    - CMake
- WSL2(Ubuntu)
  - 以下コマンドを実行しておく
    ```sh
    sudo apt update
    sudo apt install -y build-essential clang ninja-build cmake
    ```

## Test

以下のコマンドによりテストを実行します

```powershell
# ローカル実行コマンド
pwsh ./tools/run-local.ps1
```
