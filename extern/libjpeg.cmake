cmake_minimum_required(VERSION 3.10)

include_directories(${CMAKE_CURRENT_BINARY_DIR}/include)
link_directories(${CMAKE_CURRENT_BINARY_DIR}/lib)

include( ExternalProject )

set( libjpeg_source_path ${CMAKE_CURRENT_BINARY_DIR}/external/libjpeg/src/external_libjpeg/ )
set( libjpeg_cmake_file_path ${libjpeg_source_path}/CMakeLists.txt )

ExternalProject_Add(
  external_libjpeg
  PREFIX            ${CMAKE_CURRENT_BINARY_DIR}/external/zlib
  INSTALL_DIR       ${CMAKE_CURRENT_BINARY_DIR}
  GIT_REPOSITORY    https://github.com/LuaDist/libjpeg.git
  GIT_TAG           8.4.0
  CMAKE_ARGS        -DBUILD_STATIC=ON
                    -DBUILD_EXCUTABLES=ON
                    -DBUILD_TESTS=ON
                    -DCMAKE_INSTALL_PREFIX=${CMAKE_CURRENT_BINARY_DIR}
                    -DCMAKE_COMPILER_IS_GNUCXX=${CMAKE_COMPILER_IS_GNUCXX}
                    -DCMAKE_C_COMPILER=${CMAKE_C_COMPILER}
                    -DCMAKE_C_FLAGS=${GL_BINDING_C_FLAGS}
 )
