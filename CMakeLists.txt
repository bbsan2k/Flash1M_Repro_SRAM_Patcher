cmake_minimum_required(VERSION 3.19)

project(Flash1M_Repro_SRAM_Patcher)
add_executable(${PROJECT_NAME} "main.cpp"
    "patchset.cpp"
    "flash512.cpp"
    "flash1m.cpp"
    "eeprom.cpp"
    "flash.cpp")

add_executable(SaveIdentifier SaveIdentifier.cpp)

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17)
set_property(TARGET SaveIdentifier PROPERTY CXX_STANDARD 17)
