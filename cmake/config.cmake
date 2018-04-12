mason_use(glfw VERSION 2017-07-13-67c9155)
mason_use(mesa VERSION 13.0.4)
mason_use(sqlite VERSION 3.14.2)
mason_use(libuv VERSION 1.9.1)
mason_use(nunicode VERSION 1.7.1)
mason_use(libpng VERSION 1.6.25)
mason_use(libjpeg-turbo VERSION 1.5.0)
mason_use(webp VERSION 0.5.1)
mason_use(icu VERSION 58.1-min-size)
mason_use(args VERSION 6.2.0 HEADER_ONLY)


macro(mbgl_platform_render)
    target_link_libraries(mbgl-c
        PRIVATE mbgl-filesource
        PRIVATE mbgl-loop-uv
    )

    target_add_mason_package(mbgl-c PUBLIC libuv)
endmacro()
