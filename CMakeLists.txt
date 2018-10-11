cmake_minimum_required(VERSION 2.8)
CMAKE_POLICY(SET CMP0012 NEW)
PROJECT(Smart_Door)
FIND_PACKAGE(OpenCV 3.4.1 REQUIRED)
MESSAGE("OpenCV Version: ${OpenCV_VERSION}")
INCLUDE_DIRECTORIES(${OpenCV_INCLUDE_DIR})
LINK_DIRECTORIES(${OpenCV_LINK_DIR})

#Starting from here define your own library
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/include)
INCLUDE_DIRECTORIES(/usr/local/include)
LINK_DIRECTORIES(/usr/local/lib)
ADD_SUBDIRECTORY(src)

set(EXTRA_LIBS ${EXTRA_LIBS} faceDetection faceRecognition wiringPi wiringPiDev SocketServer NasserSockets pthread  ${OpenCV_LIBS})


SET(MAIN main.cpp)
ADD_EXECUTABLE(${PROJECT_NAME} ${MAIN})
TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${EXTRA_LIBS})


