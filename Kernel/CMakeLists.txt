project(ObjKernel)

aux_source_directory(${ObjKernel_SOURCE_DIR} ObjKernelSrc)
aux_source_directory(${ObjKernel_SOURCE_DIR}/drivers ObjKernelDriversSrc)

add_library(${PROJECT_NAME}
        OBJECT
        ${ObjKernelSrc}
        ${ObjKernelDriversSrc}
        )

