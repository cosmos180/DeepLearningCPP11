cmake_minimum_required(VERSION 2.8.12)
project(DeepLearning CXX)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

aux_source_directory(${PROJECT_SRC_ROOT}/target target_src)

# add_library(DeepLearning ${target_src})
target_compile_features(DeepLearning PUBLIC cxx_std_17)
# target_link_libraries(DeepLearning)

# CTest is a testing tool that can be used to test your project.
# enable_testing()
# add_test(NAME example
#          WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/bin
#          COMMAND example)
