
find_package(Threads)

###########
#  GTest  #

# Note: I'm not used the 'find_package' with GTest. On Debian, source with the
# CMakeLists.txt is at '/usr/src/gtest'.
set (GTEST_DIR /usr/src/gtest)
include(ExternalProject)
ExternalProject_Add(GTest
  SOURCE_DIR ${GTEST_DIR}
  BUILD_IN_SOURCE 0
  # Installation step. Disable install step.
  INSTALL_COMMAND ""
)

ExternalProject_Get_Property (GTest SOURCE_DIR BINARY_DIR)
message(STATUS "GTest bin dir: " ${BINARY_DIR})
link_directories(${BINARY_DIR})

###############
#  Test file  #

enable_testing ()

file(GLOB TESTS_SRC ${CMAKE_CURRENT_SOURCE_DIR}/test_*.cpp)

# Main loop for all C++ test files in the current dir.
foreach(testfile ${TESTS_SRC})
  get_filename_component(basename ${testfile} NAME_WE)
  add_executable(${basename} ${testfile})
  add_dependencies(${basename} GTest)
  # 'CMAKE_THREAD_LIBS_INIT' can be empty on Windows.
  target_link_libraries(${basename} gtest_main gtest ${CMAKE_THREAD_LIBS_INIT})
  add_test(${basename} ${basename})
endforeach()
