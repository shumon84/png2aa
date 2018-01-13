cmake_minimum_required( VERSION 3.2 )

include_directories(${CMAKE_CURRENT_BINARY_DIR}/include)
link_directories(${CMAKE_CURRENT_BINARY_DIR}/lib)

include( ExternalProject )

set( libpng_source_path ${CMAKE_CURRENT_BINARY_DIR}/external/libpng/src/external_libpng/ )
set( libpng_cmake_file_path ${libpng_source_path}/CMakeLists.txt )

ExternalProject_Add( external_libpng
  DEPENDS           external_zlib
  PREFIX            ${CMAKE_CURRENT_BINARY_DIR}/external/libpng
  INSTALL_DIR       ${CMAKE_CURRENT_BINARY_DIR}
  # http://www.libpng.org/pub/png/libpng.html
  GIT_REPOSITORY    git://git.code.sf.net/p/libpng/code
  GIT_TAG           v1.6.9
  CMAKE_ARGS        -DPNG_SHARED=off
                    -DPNG_STATIC=on
                    -DPNG_TESTS=on
                    -DPNG_DEBUG=off
                    -DPNGARG=off
                    -DBUILD_SHARED_LIBS=FALSE
                    -DCMAKE_INSTALL_PREFIX=${CMAKE_CURRENT_BINARY_DIR}
                    -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
                    -DCMAKE_TOOLCHAIN_FILE=${CMAKE_TOOLCHAIN_FILE}
                    -DCMAKE_COMPILER_IS_GNUCXX=${CMAKE_COMPILER_IS_GNUCXX}
                    -DCMAKE_C_COMPILER=${CMAKE_C_COMPILER}
                    -DCMAKE_C_FLAGS=${GL_BINDING_C_FLAGS}
)
