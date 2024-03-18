cmake_minimum_required(VERSION 3.0)

project(Tetris)

aux_source_directory(. src)

add_executable(Tetris ${src})

set(CXX_STANDARD 20)