cmake_minimum_required(VERSION 3.5)

project(portscan)

include_directories(${PROJECT_BINARY_DIR}/include)

add_executable(portscan 
	src/portscan.c
	src/utils.c)
