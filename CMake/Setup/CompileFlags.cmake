function(setup_compiler_flags)
    string(JOIN " " common_compiler_flags
#            "-v"
            "-Wall"
            "-Wextra"
            "-Werror"
            "-nostartfiles"
            "-nostdlib"
            "-nostdinc"
            "--no-standard-libraries"
            "-Wno-unused-command-line-argument"
            "-Wno-unknown-warning-option"
            "-Wno-unused-parameter"
            )

    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${common_compiler_flags}" PARENT_SCOPE)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${common_compiler_flags}" PARENT_SCOPE)
    set(CMAKE_ASM_FLAGS "${CMAKE_ASM_FLAGS} ${common_compiler_flags}" PARENT_SCOPE)
endfunction()

setup_compiler_flags()
include(${CMAKE_CURRENT_SOURCE_DIR}/Arch/arm64/CompileFlags.cmake)


macro(disable_compiler_link_flags)
    set(CMAKE_C_LINK_FLAGS "")
    set(CMAKE_CXX_LINK_FLAGS "")
endmacro()
