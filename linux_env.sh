#!/bin/bash
sudo apt-get update && apt-get install --fix-missing -y build-essential \
    binutils \
    qemu-system-aarch64 \
    gdb-multiarch \
    file \
    ninja-build \
    make \
    cmake \
    clang \
    llvm \
    lld \
    clang-format \
    clang-tidy \
    openssh-server \
    ssh \
    rsync \
    less \
    vim \
    iwyu
sudo apt-get clean
sudo apt-get autoremove
sudo rm -rf /var/cache/apt/archives
