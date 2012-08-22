enable_testing()

set(EXECUTABLE_OUTPUT_PATH out)

include(FindGTest)
find_package(GTest REQUIRED)
find_package(Threads)

add_definitions("-std=c++0x")

include_directories(
  src
  ../${LIB_SUBDIR}/src
  ${GTEST_INCLUDE_DIRS}
)

link_directories(
  ${CMAKE_CURRENT_BINARY_DIR}/../${LIB_SUBDIR}/${LIBRARY_OUTPUT_PATH}
)

file(
  GLOB_RECURSE
  test_source_files
  src/*
)

add_executable(test
  ${test_source_files}
)

target_link_libraries(test
  ${PROJECT_NAME}
  ${GTEST_BOTH_LIBRARIES}
  ${CMAKE_THREAD_LIBS_INIT}
)
