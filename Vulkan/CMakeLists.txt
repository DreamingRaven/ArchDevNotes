# GeorgeRaven:18/01/13 (yy/mm/dd)
project(RavenVulkanExperiments)
cmake_minimum_required(VERSION 3.9)
set(CMAKE_CXX_STANDARD 11)

find_package(Vulkan REQUIRED)
find_package(glfw3 REQUIRED)
find_package(glm REQUIRED)

include_directories(${Vulkan_INCLUDE_DIR})
add_executable(${PROJECT_NAME}
        main.cpp
        VulkanEngine.cpp
        VulkanEngine.h)
target_link_libraries(${PROJECT_NAME} Vulkan::Vulkan glfw) # **not 100% on Vulkan::Vulkan

# ** Vulkan seems to implement a similar import to Eigen3:Eigen needs checking!
