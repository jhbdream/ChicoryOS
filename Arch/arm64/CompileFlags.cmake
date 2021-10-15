function(setup_arch_compiler_flags)
    string(JOIN " " arch_compiler_flags
            "--target=aarch64-unknown-linux-elf"
            "-mcpu=cortex-a53"
            "-mfpu=none"
            "-mfloat-abi=soft"
            "-fuse-ld=lld"
            "-T ${CMAKE_CURRENT_SOURCE_DIR}/Arch/arm64/kernel.lds"
            )

    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${arch_compiler_flags}" PARENT_SCOPE)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${arch_compiler_flags}" PARENT_SCOPE)
    set(CMAKE_ASM_FLAGS "${CMAKE_ASM_FLAGS} ${arch_compiler_flags}" PARENT_SCOPE)
    set(CMAKE_ASM_FLAGS "${CMAKE_C_LINK_FLAG} ${arch_compiler_flags}" PARENT_SCOPE)
endfunction()

setup_arch_compiler_flags()
