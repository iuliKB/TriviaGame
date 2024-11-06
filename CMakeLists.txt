cmake_minimum_required(VERSION 3.10)
project(TriviaGame)

# aici setam standartul C++
set(CMAKE_CXX_STANDARD 11)

# aici adaugamfișierele sursă
set(SOURCES src/main.cpp src/Intrebare.cpp)

# ai creem executabilul
add_executable(TriviaGame ${SOURCES})
