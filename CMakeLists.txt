cmake_minimum_required(VERSION 3.10)

set(EXTERN_SOURCE_DIR extern)
include(${EXTERN_SOURCE_DIR}/zlib.cmake)
include(${EXTERN_SOURCE_DIR}/libpng.cmake)
include(${EXTERN_SOURCE_DIR}/libjpeg.cmake)

set(SOURCE src)
add_executable(
  png2aa
  ${SOURCE}/ascii.c
  ${SOURCE}/bmp.c
  ${SOURCE}/bmp_simple.c
  ${SOURCE}/bound_box.c
  ${SOURCE}/color.c
  ${SOURCE}/convert.c
  ${SOURCE}/image.c
  ${SOURCE}/jpeg.c
  ${SOURCE}/main.c
  ${SOURCE}/option.c
  ${SOURCE}/png.c
  ${SOURCE}/pnm.c
  ${SOURCE}/read.c
  )
include_directories(${PROJECT_SOURCE_DIR})

add_dependencies(
  png2aa
  external_zlib
  external_libpng
  external_libjpeg
  )
target_link_libraries(
  png2aa
  png
  z
  jpeg
  m
 )
