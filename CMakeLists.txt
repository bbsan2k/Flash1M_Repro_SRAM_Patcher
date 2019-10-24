cmake_minimum_required(VERSION 2.8)


project(Flash1M_Repro_SRAM_Patcher)
add_executable(${PROJECT_NAME} "main.cpp" "patchset.cpp")

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17)
