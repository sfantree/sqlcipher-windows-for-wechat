cmake_minimum_required(VERSION 3.13)
project(openssl_demo)

set(CMAKE_C_COMPILER gcc)
set(CMAKE_C_FLAGS -m32)
set(CMAKE_CXX_COMPILER g++)
set(CMAKE_CXX_FLAGS -m32)
set(CMAKE_CXX_STANDARD 11)

#add_subdirectory(sqlcipher)
#G:\Users\lin\CLionProjects\openssl-demo\sqlcipher\src
include_directories(${CMAKE_SOURCE_DIR}/sqlcipher/src)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/openssl/include)
file(GLOB_RECURSE sqlcipherSrc RELATIVE ${CMAKE_SOURCE_DIR} "sqlcipher/src/sqlcipher/*.c")
file(GLOB_RECURSE sqlcipherHeader RELATIVE ${CMAKE_SOURCE_DIR} "sqlcipher/src/sqlcipher/*.h")
file(GLOB_RECURSE sqlliteSrc RELATIVE ${CMAKE_SOURCE_DIR} "sqlcipher/src/sqlite/*.c")
file(GLOB_RECURSE sqlliteHeader RELATIVE ${CMAKE_SOURCE_DIR} "sqlcipher/src/sqlite/*.c")

# libsqlcipher.dll
add_library(sqlcipher SHARED ${sqlliteHeader} ${sqlliteSrc} ${sqlcipherHeader} ${sqlcipherSrc})
target_link_libraries(sqlcipher ${CMAKE_CURRENT_SOURCE_DIR}/openssl/lib/libeay32MD.lib ${CMAKE_CURRENT_SOURCE_DIR}/openssl/lib/ssleay32MD.lib)
###


# sqlcipherCli.exe
#include_directories(${CMAKE_CURRENT_SOURCE_DIR}/openssl/include)
#add_executable(openssl_demo main.cpp)
#target_link_libraries(openssl_demo ${CMAKE_CURRENT_SOURCE_DIR}/openssl/lib/libeay32MD.lib ${CMAKE_CURRENT_SOURCE_DIR}/openssl/lib/ssleay32MD.lib)
#G:\Users\lin\CLionProjects\openssl-demo\sqlcipher\src\sqlite
include_directories(${CMAKE_SOURCE_DIR}/sqlcipher/src/sqlite)
add_executable(sqlcipherCli shell.c)
target_link_libraries(sqlcipherCli sqlcipher)