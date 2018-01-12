cmake_minimum_required(VERSION 3.9)
project(RavenVulkanExperiments)

set(CMAKE_CXX_STANDARD 11)

find_package(Vulkan REQUIRED)
include_directories(${Vulkan_INCLUDE_DIR})
add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} Vulkan::Vulkan)