add_executable(mbgl-render
    bin/renderer.c
)

target_include_directories(mbgl-render
    PUBLIC include
)

add_library(mbgl-core STATIC IMPORTED)
add_library(mbgl-filesource STATIC IMPORTED)
add_library(mbgl-loop-uv STATIC IMPORTED)

set_property(TARGET mbgl-core PROPERTY
   IMPORTED_LOCATION /home/bizarro/Documents/Projects/src/github.com/go-spatial/atto/deps/lib/libmbgl-core.a)

set_property(TARGET mbgl-filesource PROPERTY
   IMPORTED_LOCATION /home/bizarro/Documents/Projects/src/github.com/go-spatial/atto/deps/lib/libmbgl-filesource.a)

set_property(TARGET mbgl-loop-uv PROPERTY
   IMPORTED_LOCATION /home/bizarro/Documents/Projects/src/github.com/go-spatial/atto/deps/lib/libmbgl-loop-uv.a)

target_link_libraries(mbgl-render
    PRIVATE mbgl-c
	PRIVATE mbgl-core
	PRIVATE mbgl-filesource
	PRIVATE mbgl-loop-uv
	PUBLIC -lGL
	PUBLIC -lX11
	PUBLIC -lcurl
)

target_add_mason_package(mbgl-render PUBLIC sqlite)

target_link_libraries(mbgl-render
 	PRIVATE mbgl-core
)

target_add_mason_package(mbgl-render PRIVATE boost)
target_add_mason_package(mbgl-render PRIVATE geojson)
target_add_mason_package(mbgl-render PUBLIC libuv)
target_add_mason_package(mbgl-render PUBLIC nunicode)
target_add_mason_package(mbgl-render PUBLIC libpng)
target_add_mason_package(mbgl-render PUBLIC libjpeg-turbo)
target_add_mason_package(mbgl-render PUBLIC webp)
target_add_mason_package(mbgl-render PRIVATE icu)
target_add_mason_package(mbgl-render PUBLIC libuv)

