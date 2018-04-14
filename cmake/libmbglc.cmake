add_library(mbgl-c STATIC
    ${MBGLC_CORE_FILES}
)

add_library(mbgl-core STATIC IMPORTED)
set_property(TARGET mbgl-core PROPERTY
    IMPORTED LOCATION /opt/src/github.com/mapbox/mapbox-gl-native/build/linux-x86_64/RelWithDebInfo/libmbgl-core.a)

target_include_directories(mbgl-c
    PUBLIC include
    PRIVATE src
)

target_link_libraries(mbgl-c PUBLIC mbgl-core)

target_add_mason_package(mbgl-c PUBLIC geometry)
target_add_mason_package(mbgl-c PUBLIC variant)
#target_add_mason_package(mbgl-c PRIVATE boost)
target_add_mason_package(mbgl-c PRIVATE geojson)

#mbgl_platform_core()
