cmake_minimum_required(VERSION 4.1.2 FATAL_ERROR)

project(cheat_menu_project)

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)
find_package(imgui REQUIRED)
find_package(nlohmann_json REQUIRED)

add_subdirectory(cheat_menu)
