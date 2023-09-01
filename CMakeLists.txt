cmake_minimum_required (VERSION 3.6)

project (cpp_learning)

include_directories (./head)

aux_source_directory (./src SRC_LIST)

aux_source_directory (./main MAIN)

add_compile_options (-g)

add_executable (HelloWorld ${SRC_LIST} ${MAIN})
