include(FindBoost)
set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREAD ON)
find_package(
  Boost
  1.46
  REQUIRED filesystem system
)

add_definitions("-std=c++0x")

include_directories(
  src
  ${Boost_INCLUDE_DIRS}
)

link_directories(
  ${Boost_INCLUDE_DIRS}
)

file(
  GLOB_RECURSE
  source_files
  src/*
)

add_library(${PROJECT_NAME}
  SHARED
  ${source_files}
)

target_link_libraries(
  ${PROJECT_NAME}
  ${Boost_LIBRARIES}
)
