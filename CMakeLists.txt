cmake_minimum_required(VERSION 3.5.1)
project(Double_Int)

include_directories(${PROJECT_SOURCE_DIR} include/Eigen)
include_directories(${PROJECT_SOURCE_DIR} include)

add_executable(${PROJECT_NAME} src/main.cpp src/DoubleIntegrator.cpp src/LQRcontrol.cpp)

find_package(Python3 COMPONENTS Development NumPy)
target_include_directories(${PROJECT_NAME} PRIVATE ${Python3_INCLUDE_DIRS} ${Python3_NumPy_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} Python3::Python Python3::NumPy)


