cmake_minimum_required(VERSION 3.17)
project(ParticleSwarmOptimization)

set(CMAKE_CXX_STANDARD 14)

add_executable(ParticleSwarmOptimization main.cpp testFunctions.h)

#Agregamos python para poder usar matplotlibcpp
find_package(Python2 COMPONENTS Development NumPy)
target_include_directories(ParticleSwarmOptimization PRIVATE ${Python2_INCLUDE_DIRS} ${Python2_NumPy_INCLUDE_DIRS})
target_link_libraries(ParticleSwarmOptimization Python2::Python Python2::NumPy)