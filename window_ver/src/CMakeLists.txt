# 64 bit build
if (ENABLE64BIT)
	SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -m64")
endif (ENABLE64BIT)

# 빌드된 라이브러리
SET (LIBRARY_OUTPUT_PATH ../lib)

# 소스빌드에 필요한 헤더 파일
INCLUDE_DIRECTORIES (../include)

# 소스파일의 리스트
#SET (LIBSRCS main.c helloworld.c )

# library build, helloworld::library_name, STATIC::정적||SHARED::공유 으로 빌드
#ADD_LIBRARY(helloworld SHARED helloworld.c)
ADD_LIBRARY(SerialPort_lib SHARED SerialComm.cpp SerialPort.cpp)
#ADD_LIBRARY(drone_client SHARED blob.cpp Commander.cpp CommanderDescent.cpp CommanderMove.cpp CommanderMoveFront.cpp CommanderNeutral.cpp CommanderQuit.cpp CommanderRise.cpp CommanderStart.cpp CommanderTrunLeft.cpp drone_network2.cpp droneserial.cpp KalmanFilter.cpp liveencoder.cpp qtthread.cpp sender.cpp session.cpp stdafx.cpp stream.cpp subapplication.cpp)



if (ENABLE64BIT)
	SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -m64")
endif (ENABLE64BIT)

#ADD_EXECUTABLE(drone_client_test drone_test.cpp)
#TARGET_LINK_LIBRARIES(drone_client_test drone_client)
ADD_EXECUTABLE(SerialPort_test main.cpp)
TARGET_LINK_LIBRARIES(SerialPort_test SerialPort_lib)


#SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O3")
#INSTALL(TARGETS hello DESTINATION bin)
#INSTALL(TARGETS helloworld DESTINATION lib)
#INSTALL(FILES helloworld.h DESTINATION include)
