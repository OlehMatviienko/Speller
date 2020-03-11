cmake_minimum_required(VERSION 3.10)
project(speller)

set(CMAKE_CXX_STANDARD 11)

add_executable(speller sources/main.cpp sources/BTrie.cpp sources/vectorCheker.cpp sources/HashTable.cpp sources/Cheker.cpp)