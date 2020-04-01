cmake_minimum_required(VERSION 3.10)
project(speller)

list(APPEND SOURCES src/sources/main.cpp
        src/sources/TrieChecker.cpp
        src/sources/VectorChecker.cpp
        src/sources/HashTableChecker.cpp
        src/sources/Checker.cpp
        src/sources/BinTreeChecker.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})
target_include_directories(speller PUBLIC src/headers)

