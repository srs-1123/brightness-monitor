# Brightness Monitor

Raspberry Pi 4用Yoctoプロジェクト

## ビルド手順

```bash
# 1. サブモジュール込みでクローン
git clone --recurse-submodules <repository-url>
cd brightness-monitor

# 2. ビルド環境セットアップ
source layers/poky/oe-init-build-env build

# 3. イメージビルド
bitbake core-image-minimal
```

## 設定

- **ターゲット**: Raspberry Pi 4 (64bit)
- **ディストリビューション**: Poky 5.0.9 (Scarthgap)
- **出力先**: `build/tmp/deploy/images/raspberrypi4-64/`
