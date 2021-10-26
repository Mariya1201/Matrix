cmake_minimum_required(VERSION 2.8)

project(Matrica)

set(Matrica_src Test.cpp Matrix.cpp main.cpp )
set(Matrica_hdr Header.h)

add_executable(${PROJECT_NAME} ${Matrica_src} ${Matrica_hdr})