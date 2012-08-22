set(EXECUTABLE_OUTPUT_PATH out/${CMAKE_BUILD_TYPE})

include(FindBoost)
set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREAD ON)
find_package(
  Boost
  1.46
  REQUIRED program_options
)

add_definitions("-std=c++0x")

include_directories(
  src
  ../${LIB_SUBDIR}/include
  ${Boost_INCLUDE_DIRS}
)

link_directories(
  ${CMAKE_CURRENT_BINARY_DIR}/../${LIB_SUBDIR}/${LIBRARY_OUTPUT_PATH}
  ${Boost_INCLUDE_DIRS}
)

file(
  GLOB_RECURSE
  frontend_source_files
  src/*
)

add_executable(frontend
  ${frontend_source_files}
)

target_link_libraries(frontend
  ${PROJECT_NAME}
  ${Boost_LIBRARIES}
)
