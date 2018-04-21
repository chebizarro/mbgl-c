cmake_minimum_required(VERSION 3.4)
project(mbgl-c LANGUAGES CXX C)
set(CMAKE_CXX_STANDARD 14)

option(WITH_CXX11ABI "Use cxx11abi mason packages" OFF)
option(WITH_COVERAGE "Enable coverage reports" OFF)
option(WITH_OSMESA   "Use OSMesa headless backend" OFF)
option(WITH_EGL      "Use EGL backend" OFF)

include(cmake/mason.cmake)

if(WITH_CXX11ABI)
    set(MASON_CXXABI_SUFFIX -cxx11abi)
    if(CMAKE_COMPILER_IS_GNUCXX)
        #add_definitions(-D_GLIBCXX_USE_CXX11_ABI=1)
    endif()
else()
    if(CMAKE_COMPILER_IS_GNUCXX)
       # add_definitions(-D_GLIBCXX_USE_CXX11_ABI=0)
    endif()
endif()

if(WITH_OSMESA AND WITH_EGL)
    message(FATAL_ERROR "WITH_OSMESA and WITH_EGL are mutually exclusive.")
endif()

if(WITH_EGL)
    add_definitions(-DMBGL_USE_GLES2=1)
endif()

if($ENV{CI})
    add_compile_options(-DCI_BUILD=1)
endif()


mason_use(geometry VERSION 0.9.2 HEADER_ONLY)
mason_use(variant VERSION 1.1.4 HEADER_ONLY)
mason_use(unique_resource VERSION cba309e HEADER_ONLY)
mason_use(rapidjson VERSION 1.1.0 HEADER_ONLY)
mason_use(boost VERSION 1.65.1 HEADER_ONLY)
mason_use(geojsonvt VERSION 6.3.0 HEADER_ONLY)
mason_use(supercluster VERSION 0.2.2 HEADER_ONLY)
mason_use(kdbush VERSION 0.1.1-1 HEADER_ONLY)
mason_use(earcut VERSION 0.12.4 HEADER_ONLY)
mason_use(protozero VERSION 1.5.2 HEADER_ONLY)
mason_use(pixelmatch VERSION 0.10.0 HEADER_ONLY)
mason_use(geojson VERSION 0.4.2 HEADER_ONLY)
mason_use(polylabel VERSION 1.0.3 HEADER_ONLY)
mason_use(wagyu VERSION 0.4.3 HEADER_ONLY)
mason_use(shelf-pack VERSION 2.1.1 HEADER_ONLY)
mason_use(cheap-ruler VERSION 2.5.3 HEADER_ONLY)
mason_use(vector-tile VERSION 1.0.1 HEADER_ONLY)

add_definitions(-DRAPIDJSON_HAS_STDSTRING=1)
add_definitions(-D_GLIBCXX_USE_CXX11_ABI=1)

set(CMAKE_CONFIGURATION_TYPES Debug Release RelWithDebugInfo Sanitize)

add_definitions(-I/home/bizarro/Documents/Projects/ThirdParty/mapbox-gl-native/include)
add_definitions(-I/home/bizarro/Documents/Projects/ThirdParty/mapbox-gl-native/platform/default)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -ftemplate-depth=1024 -fPIC -fvisibility=hidden -Wall -Wextra -Wshadow -Wnon-virtual-dtor -Werror -Wno-variadic-macros -Wno-unknown-pragmas")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fPIC -fvisibility=hidden -Wall -Wextra -Wshadow -Werror -Wno-variadic-macros -Wno-unknown-pragmas")
if(APPLE AND CMAKE_CXX_COMPILER_ID MATCHES ".*Clang")
    # -Wno-error=unused-command-line-argument is required due to https://llvm.org/bugs/show_bug.cgi?id=7798
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-error=unused-command-line-argument")
endif()
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Os -DNDEBUG")
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "${CMAKE_CXX_FLAGS_RELWITHDEBINFO} -O3 -DNDEBUG")
set(CMAKE_CXX_FLAGS_SANITIZE "${CMAKE_CXX_FLAGS_SANITIZE} -O1 -g -fno-omit-frame-pointer -fno-optimize-sibling-calls")


if(CMAKE_CXX_COMPILER_ID MATCHES ".*Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-error=unknown-warning-option")
elseif(CMAKE_COMPILER_IS_GNUCXX)
    # https://svn.boost.org/trac/boost/ticket/9240
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fext-numeric-literals")
endif()

# Technique from https://crascit.com/2016/04/09/using-ccache-with-cmake/
find_program(CCACHE_PROGRAM ccache)
if(CCACHE_PROGRAM)
    if(CMAKE_CXX_COMPILER_ID MATCHES ".*Clang")
        # ccache splits up the compile steps, so we end up with unused arguments in some steps.
        # Clang also thinks that ccache isn't interactive, so we explicitly need to enable color.
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Qunused-arguments -fcolor-diagnostics")
    endif()
else()
    message(STATUS "Can't find ccache — consider installing ccache to improve recompilation performance")
endif()

include(cmake/config.cmake)
include(cmake/files.cmake)
include(cmake/libmbglc.cmake)
include(cmake/renderer.cmake)

