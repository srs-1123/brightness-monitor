# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project Overview

Brightness Monitor is a Yocto-based embedded Linux system for Raspberry Pi 4 (64-bit). The project uses Poky 5.0.9 (Scarthgap) as the base distribution and integrates Raspberry Pi hardware support through meta-raspberrypi.

## Build System Architecture

### Layer Structure

The project follows standard Yocto architecture with submodules in `layers/`:

- **poky**: Core Yocto build system (meta, meta-poky, meta-yocto-bsp)
- **meta-raspberrypi**: Raspberry Pi BSP layer with hardware-specific recipes
- **meta-openembedded**: Extended OE layers (meta-oe, meta-python, meta-multimedia, meta-networking)

All submodules are pinned to the `scarthgap` branch for version consistency.

### Build Configuration

Configuration files in `build/conf/`:

- `bblayers.conf`: Defines which layers are active in the build
- `local.conf`: Machine settings, build parallelism, licenses, and mirrors
  - Machine: `raspberrypi4-64`
  - Build threads: Configured with `BB_NUMBER_THREADS = "4"` and `PARALLEL_MAKE = "-j 4"`
  - License acceptance: `LICENSE_FLAGS_ACCEPTED = "synaptics-killswitch"` for Pi firmware
  - GNU mirrors: Configured to use kernel.org mirrors to avoid ftp.gnu.org connection issues

### Build Environment

The build environment must be sourced before any Yocto commands:

```bash
source layers/poky/oe-init-build-env build
```

This sets up BitBake and changes to the `build/` directory. All subsequent BitBake commands must be run from within this environment.

## Common Build Commands

### Initial Setup

```bash
# Clone with all submodules
git clone --recurse-submodules <repository-url>
cd brightness-monitor

# Update existing submodules
git submodule update --init --recursive
```

### Building Images

```bash
# Setup build environment (must run first)
source layers/poky/oe-init-build-env build

# Build minimal image
bitbake core-image-minimal

# Clean a specific recipe
bitbake -c clean <recipe-name>

# Force rebuild from scratch
bitbake -c cleansstate <recipe-name>

# Build with verbose output for debugging
bitbake -v <recipe-name>
```

### Examining the Build

```bash
# Show recipe dependencies
bitbake -g core-image-minimal

# Show available recipes
bitbake-layers show-recipes

# Show layer information
bitbake-layers show-layers

# Find recipe providing a package
bitbake-layers show-recipes '*<search-term>*'

# Show recipe metadata
bitbake -e <recipe-name> | less

# Run devshell for recipe debugging
bitbake -c devshell <recipe-name>
```

### Build Artifacts

Built images are located at:
```
build/tmp/deploy/images/raspberrypi4-64/
```

Key artifacts:
- `.wic` or `.wic.bz2`: Complete disk image for SD card
- `.rootfs.ext4`: Root filesystem
- `.manifest`: List of packages in the image

## Prerequisites

Required system packages (Debian/Ubuntu):
```bash
sudo apt-get update
sudo apt-get install -y \
  gawk wget git diffstat unzip texinfo gcc build-essential \
  chrpath socat cpio python3 python3-pip python3-pexpect \
  xz-utils debianutils iputils-ping python3-git python3-jinja2 \
  libegl1-mesa libsdl1.2-dev python3-subunit mesa-common-dev \
  zstd liblz4-tool file locales
```

Required locale:
```bash
sudo locale-gen en_US.UTF-8
sudo update-locale LANG=en_US.UTF-8
```

## GitHub Integration

Two workflows are configured:

1. **claude.yml**: Responds to `@claude` mentions in issues and PR comments
2. **claude-code-review.yml**: Automatically reviews PRs on open/synchronize events

Both require `CLAUDE_CODE_OAUTH_TOKEN` to be configured in repository secrets.

## Working with Recipes

When creating or modifying recipes:

- Recipe files use `.bb` extension and follow BitBake syntax
- Recipe appends use `.bbappend` and must match the base recipe name
- Common recipe tasks: `do_fetch`, `do_unpack`, `do_patch`, `do_configure`, `do_compile`, `do_install`
- Variables use BitBake syntax: `VARIABLE = "value"` or `VARIABLE:append = " additional"`

## Important Notes

- The build environment is NOT persistent across shell sessions - must source `oe-init-build-env` each time
- BitBake maintains extensive caching in `build/tmp/` - this directory can grow very large (100GB+)
- Shared state cache (`build/sstate-cache/`) enables faster rebuilds and should be preserved
- Downloads directory (`build/downloads/`) caches upstream sources and can be shared between builds
- Changes to `local.conf` or `bblayers.conf` may require full rebuild depending on what changed
