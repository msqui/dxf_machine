cmake_minimum_required (VERSION 2.6)

project (dxf_machine)

set(LIBRARY_OUTPUT_PATH out/${CMAKE_BUILD_TYPE})

set(LIB_SUBDIR lib)
set(FRONTEND_SUBDIR frontend)
set(TEST_SUBDIR tst)

add_subdirectory(${LIB_SUBDIR})

add_subdirectory(${FRONTEND_SUBDIR} EXCLUDE_FROM_ALL)

add_subdirectory(${TEST_SUBDIR} EXCLUDE_FROM_ALL)
