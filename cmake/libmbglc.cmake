add_library(mbgl-c STATIC
    ${MBGLC_CORE_FILES}
)

target_include_directories(mbgl-c
    PUBLIC include
)

target_add_mason_package(mbgl-c PUBLIC geometry)
target_add_mason_package(mbgl-c PUBLIC variant)
#target_add_mason_package(mbgl-c PRIVATE boost)
target_add_mason_package(mbgl-c PRIVATE geojson)

#mbgl_c()
#mbgl_platform_core()
