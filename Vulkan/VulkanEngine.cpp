// GeorgeRaven:18/01/13 (yy/mm/dd)
#include "VulkanEngine.h"

//private: ---

/// func to handle VK instance creation :: void(null)
void VulkanEngine::createInstance() {

    // general pattern for vulkan function params:
        // pointer to struct with creation info
        // pointer to custom allocator callbacks, here nullptr
        // pointer to variable that which stores the new object handle

    // finding + enumerating vk extensions
    uint32_t vkExtensionCount = 0;
    std::vector<VkExtensionProperties> vkExtensions(vkExtensionCount);
    vkEnumerateInstanceExtensionProperties(nullptr, &vkExtensionCount, vkExtensions.data());
    std::cout << vkExtensionCount   << " vk extensions supported:"   << std::endl;
    for (const auto& extension : vkExtensions) {
        std::cout << "\t" << extension.extensionName << std::endl;
    } // TODO: find out why this does not print (likely never steps into 'range' for loop)

    // finding + enumerating glfw extensions
    uint32_t glfwExtensionCount = 0;
    const char** glfwExtensions;
    glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);
    std::cout << glfwExtensionCount << " glfw extensions supported." << std::endl;

    // declare struct optional for Vulkan
    VkApplicationInfo appInfo = {};
    // fill useful field of above struct struct
    appInfo.sType =                 VK_STRUCTURE_TYPE_APPLICATION_INFO;
    appInfo.pApplicationName =      WINDOW_NAME;//"Hello Triangle";
    appInfo.applicationVersion =    VK_MAKE_VERSION(1, 0, 0);
    appInfo.pEngineName =           "No Engine";
    appInfo.engineVersion =         VK_MAKE_VERSION(1, 0, 0);
    appInfo.apiVersion =            VK_API_VERSION_1_0;

    // declare mandatory struct for instance creation
    VkInstanceCreateInfo createInfo = {};
    // fill struct; instance creation
    createInfo.sType =                      VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    createInfo.pApplicationInfo =           &appInfo;
    // fill struct; glfw extensions.        here for style
    createInfo.enabledExtensionCount =      glfwExtensionCount;
    createInfo.ppEnabledExtensionNames =    glfwExtensions;
    // fill struct; layers to enable...     for validation
    createInfo.enabledLayerCount =          0;

    //VkResult result = vkCreateInstance(&createInfo, nullptr, &instance);
    if (vkCreateInstance(&createInfo, nullptr, &instance_m) != VK_SUCCESS) {
        throw std::runtime_error("failed to create Vulkan instance!");
    }
}

/// func to initialise GLFW window :: void(null)
void VulkanEngine::initWindow() {

    glfwInit();
    // configure glfw through hints
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    window_m = glfwCreateWindow(width_m, height_m, WINDOW_NAME, nullptr, nullptr);
}

/// func to initialise VK :: void(null)
void VulkanEngine::initVulkan() {

//    glm::mat4 matrix;
//    glm::vec4 vec;
//    auto test = matrix * vec;

    createInstance();
}

/// funct to control window :: void(null)
void VulkanEngine::mainLoop() {

    while(!glfwWindowShouldClose(window_m)) {
        //glfwPollEvents();
        glfwWaitEventsTimeout(0.7);
    }
}

/// func to clean up window :: void(null)
void VulkanEngine::cleanup() {
    vkDestroyInstance(instance_m, nullptr);
    glfwDestroyWindow(window_m);
    glfwTerminate();
}

// public: ---

/// func to coordinate the whole process of GLFW + VK starting :: void(null)
void VulkanEngine::run() {

    width_m  = 800; // TODO implement constructor that assigns these
    height_m = 600;

    initWindow();
    initVulkan();
    mainLoop();
    cleanup();
}