cmake_minimum_required(VERSION 2.8.9)
project(BRLiveRecognition)

# BR variables
set(BR_DIR "/home/colin/usr")

# QT variables
find_package(Qt5Concurrent REQUIRED)
find_package(Qt5Core REQUIRED)

# OpenCV variables
find_package(OpenCV 2.4.5 REQUIRED)

# extra include directories
#include_directories("/home/colin/usr/include")
#include_directories("/home/colin/usr/include/openbr/")
include_directories("/usr/local/include/openbr/")

include_directories("/usr/include/qt")
include_directories("/usr/include/qt/QtConcurrent")
include_directories("/usr/include/qt/QtCore")

# extra library directories
link_directories("/home/colin/usr/lib")
link_directories(${QT5})

set(CMAKE_CXX_FLAGS "-fPIC")

# program sources
file(GLOB src "src/*.cpp" "src/*.c")

# executable
add_executable(BRLiveRecognition ${src})
target_link_libraries(BRLiveRecognition openbr)
target_link_libraries(BRLiveRecognition Qt5Concurrent)
target_link_libraries(BRLiveRecognition Qt5Core)
target_link_libraries(BRLiveRecognition opencv_core)
target_link_libraries(BRLiveRecognition opencv_highgui)
target_link_libraries(BRLiveRecognition opencv_ml)
target_link_libraries(BRLiveRecognition opencv_objdetect)
target_link_libraries(BRLiveRecognition opencv_gpu)
