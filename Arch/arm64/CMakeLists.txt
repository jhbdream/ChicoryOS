project(ObjArch C CXX ASM)


find_asm_source_files(AsmSourceFiles ${ObjArch_SOURCE_DIR}/boot)
aux_source_directory(${ObjArch_SOURCE_DIR} ObjArchSrc)
add_library(${PROJECT_NAME}
        OBJECT
        ${ObjArchSrc}
        ${AsmSourceFiles})


add_executable(Kernel.elf
        $<TARGET_OBJECTS:ObjArch>
        $<TARGET_OBJECTS:ObjKernel>
        )
#target_link_options(Kernel.elf PRIVATE "LINKER:SHELL:-T ${ObjArch_SOURCE_DIR}/kernel.lds")