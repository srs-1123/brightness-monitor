# brightness-monitor

## 環境構築

### 必要なツール
- Meson (>= 1.0)
- Ninja
- C++コンパイラ (C++17対応)
- CppUTest (テスト実行に必要)

### インストール方法

#### Ubuntu/Debian
```bash
# Mesonとninjaのインストール
```bash
sudo apt install meson ninja-build
```

```bash
# CppUTestのインストール
sudo apt install libcpputest-dev
```

## ビルド方法

```bash
# ビルドディレクトリのセットアップ
meson setup build

# コンパイル
meson compile -C build

# 実行
./build/brightness-monitor
```

### よく使うコマンド

```bash
# ビルドディレクトリを削除して再セットアップ
rm -rf build
meson setup build

# デバッグビルド
meson setup build --buildtype=debug

# リリースビルド
meson setup build --buildtype=release
```

## テストの実行

```bash
# すべてのテストを実行
meson test -C build

# 詳細な出力でテストを実行
meson test -C build --verbose

# テストログを確認
cat build/meson-logs/testlog.txt
```

### テストの追加方法

新しいテストファイルを `tests/` ディレクトリに作成し、`meson.build` に追加してください。
```