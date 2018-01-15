// GeorgeRaven:18/01/13 (yy/mm/dd)

#ifndef RAVENVULKANEXPERIMENTS_VULKANENGINE_H
#define RAVENVULKANEXPERIMENTS_VULKANENGINE_H
#define WINDOW_NAME "So long and thanks for all the fish"

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>

#include <iostream>
#include <vector>

class VulkanEngine {
private:
    // members
    GLFWwindow* window_m;
    VkInstance instance_m;
    int height_m;
    int width_m;
    // funcs
    void createInstance();
    void initWindow();
    void initVulkan();
    void mainLoop();
    void cleanup();
protected:
public:
    void run();
    VulkanEngine() = default;
};


#endif //RAVENVULKANEXPERIMENTS_VULKANENGINE_H