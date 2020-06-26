# EOOS RT.
#
# @author    Sergey Baigudin, sergey@baigudin.software
# @copyright 2019-2020, Sergey Baigudin, Baigudin Software

cmake_minimum_required(VERSION 3.15)

add_library(target-eoos STATIC)

add_subdirectory(interface)
add_subdirectory(library)
add_subdirectory(system)
