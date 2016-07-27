#cmake 최소 버전
cmake_minimum_required(VERSION 2.8)

#project name
#PROJECT(helloworld)
#PROJECT(drone_client)
PROJECT(SerialPort_test)

#컴파일되고 있는 내용 보여주기
SET(CMAKE_VERBOSE_MAKEFILE ON)

# cmake -D build=debug 같은 debug mode, release mode 를 체크
if ("${build}" MATCHES "debug")
 SET (CMAKE_BUILD_TYPE "debug")
else ("${build}" MATCHES "debug")
 SET (CMAKE_BUILD_TYPE "release")
endif ("${build}" MATCHES "debug")

#빌드 비트를 확인
#if ("${bit}" MATCHES "32")
# ADD_DEFINITIONS(-DCALIB_CFG_COMPILE_BIT=32 -m32)
# SET (CMAKE_EXE_LINKER_FLAGS -m32)
#else ("${bit}" MATCHES "32")
# ADD_DEFINITIONS(-DCALIB_CFG_COMPILE_BIT=64 -m64)
# SET (CMAKE_EXE_LINKER_FLAGS -m64)
#endif ("${bit}" MATCHES "32")


ADD_SUBDIRECTORY(src)
