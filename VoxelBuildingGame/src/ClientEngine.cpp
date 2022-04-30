#include "ClientEngine.h"
#include <stb/stb_image.h>
#include "Input.h"

ClientEngine* ClientEngine::instance = nullptr;

void framebuffer_size_callback(GLFWwindow* glWindow, int width, int height)
{
    glViewport(0, 0, width, height);
    Window::GetInstance()->onWindowResize(width, height);
}
int ClientEngine::setupWindow() {
    //Init opengl
    glfwInit();

    //opengl init version 3.3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = new Window("Guycraft");
    auto glWindow = glfwCreateWindow(window->width, window->height, window->title, NULL, NULL);
    window->window = glWindow;

    if (glWindow == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(glWindow);
    glfwSwapInterval(1); // Enable vsync
    glfwSetFramebufferSizeCallback(glWindow, framebuffer_size_callback);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    //gl options render
    glEnable(GL_BLEND);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glCullFace(GL_FRONT);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    //init icon app
    GLFWimage images[1];
    int w, h, c;
    unsigned char* data = stbi_load("src/icon/icon_128.png", &w, &h, &c, 4);
    images[0].width = w;
    images[0].height = h;
    images[0].pixels = data;
    //printf("Icon 128 data size %d\n", w * h * c);

    glfwSetWindowIcon(glWindow, 1, images);
    return 0;
}
void ClientEngine::launch() {
    //---init window
    setupWindow();
    auto glfwWindow = window->window;

    m_gui = new GUI(glfwWindow);

    //init core engine
    m_input = new Input(glfwWindow);
    m_input->initKeyMapping();

    m_resouceManager = new ResourceManager();
    m_resouceManager->loadAllResouces();

    m_textRenderer = new TextRenderer(glfwWindow);
    m_textRenderer->setupGL();

    //init game
	game = new Game(window);
    game->init();
    while (!glfwWindowShouldClose(glfwWindow))
    { 
        glClearColor(0.f, 0.0f, 0.0f, 1.f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        m_input->update();
        game->UpdateInFrame();

        // Swap the back buffer with the front buffer
        glfwSwapBuffers(glfwWindow);
    }
    exit();
}
void ClientEngine::exit() {
    glfwDestroyWindow(window->window);
    glfwTerminate();
}

