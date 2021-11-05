# OS

## env.Linux
[llvm linker](https://lld.llvm.org/)

## build
1. `gn gen out`
2. `ninja -C out`

## boot
1. [set up tftp](https://community.arm.com/oss-platforms/w/docs/495/tftp-remote-network-kernel-using-u-boot)
2. move kernel elf to `mv ./out/ChicoryOS /tftpboot/`
3. run qemu `./qemu`
4. set uboot ftpserver ip `setenv serverip xxxxx`
5. get file to memory `tftp ChicoryOS`
6. bootelf from memory `bootelf 0x40200000`


