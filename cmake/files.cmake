set(MBGLC_CORE_FILES

    include/mbgl-c/map/map.h
    include/mbgl-c/util/geo.h
    include/mbgl-c/map/mode.h
    include/mbgl-c/util/size.h
    include/mbgl-c/style/style.h
    include/mbgl-c/util/image.h
    include/mbgl-c/actor/scheduler.h
    include/mbgl-c/storage/file_source.h
    include/mbgl-c/map/map_observer.h
    include/mbgl-c/gl/headless_frontend.h
    include/mbgl-c/storage/online_file_source.h
    include/mbgl-c/util/default_thread_pool.h

    src/mbgl-c/map/map.cpp
    src/mbgl-c/util/geo.cpp
    src/mbgl-c/util/size.cpp
    src/mbgl-c/style/style.cpp
    src/mbgl-c/util/image.cpp
    src/mbgl-c/map/map_observer.cpp
    src/mbgl-c/gl/headless_frontend.cpp
    src/mbgl-c/storage/online_file_source.cpp
    src/mbgl-c/util/default_thread_pool.cpp

)
