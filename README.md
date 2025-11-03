# Brightness Monitor

Raspberry Pi 4用Yoctoプロジェクト

## 前提条件

### 必要なaptパッケージ

Yoctoビルドには以下のパッケージが必要です:

```bash
sudo apt-get update
sudo apt-get install -y \
  gawk wget git diffstat unzip texinfo gcc build-essential \
  chrpath socat cpio python3 python3-pip python3-pexpect \
  xz-utils debianutils iputils-ping python3-git python3-jinja2 \
  libegl1-mesa libsdl1.2-dev python3-subunit mesa-common-dev \
  zstd liblz4-tool file locales
```

### ロケール設定

Yoctoビルドには`en_US.UTF-8`ロケールが必要です:

```bash
sudo locale-gen en_US.UTF-8
sudo update-locale LANG=en_US.UTF-8
```

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
