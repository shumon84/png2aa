cmake_minimum_required( VERSION 3.2 )

include_directories(${CMAKE_CURRENT_BINARY_DIR}/include)
link_directories(${CMAKE_CURRENT_BINARY_DIR}/lib)

include( ExternalProject )

set( zlib_source_path ${CMAKE_CURRENT_BINARY_DIR}/external/zlib/src/external_zlib/ )
set( zlib_cmake_file_path ${zlib_source_path}/CMakeLists.txt )

ExternalProject_Add( external_zlib
  PREFIX            ${CMAKE_CURRENT_BINARY_DIR}/external/zlib
  INSTALL_DIR       ${CMAKE_CURRENT_BINARY_DIR}
  # http://www.zlib.net/
  GIT_REPOSITORY    http://github.com/madler/zlib.git
  GIT_TAG           v1.2.8
  CMAKE_ARGS        -DASM686=off
                    -DAMD64=off
                    -DCMAKE_INSTALL_PREFIX=${CMAKE_CURRENT_BINARY_DIR}
                    -DCMAKE_COMPILER_IS_GNUCXX=${CMAKE_COMPILER_IS_GNUCXX}
                    -DCMAKE_C_COMPILER=${CMAKE_C_COMPILER}
                    -DCMAKE_C_FLAGS=${GL_BINDING_C_FLAGS}
)
