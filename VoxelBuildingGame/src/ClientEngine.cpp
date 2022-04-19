#include "ClientEngine.h"
#include <stb/stb_image.h>
#include "Input.h"

ClientEngine* ClientEngine::instance = nullptr;

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}
int ClientEngine::initialOpenGL() {
    //Init opengl
    glfwInit();

    //opengl init version 3.3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window->glfwWindow = glfwCreateWindow(window->initWidth, window->initHeight, window->titleName, NULL, NULL);

    if (window->glfwWindow == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window->glfwWindow);
    glfwSwapInterval(1); // Enable vsync
    glfwSetFramebufferSizeCallback(window->glfwWindow, framebuffer_size_callback);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_FRONT);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    //init icon app
    GLFWimage images[1];
    int w, h, c;
    unsigned char* data = stbi_load("src/icon/icon_128.png", &w, &h, &c, 4);
    images[0].width = w;
    images[0].height = h;
    images[0].pixels = data;
    printf("Icon 128 data size %d\n", w * h * c);

    glfwSetWindowIcon(window->glfwWindow, 1, images);
    return 0;
}
int ClientEngine::initialShader() {
    //init shaders
    game->shaders.defaultShader = new Shader("src/Shader/defualt.vert", "src/Shader/defualt.frag");
    game->shaders.mcatlas = new Texture("src/Texture/mcatlas.png", true, true, GL_REPEAT, GL_NEAREST);
    game->shaders.defaultShader->Bind();
    game->shaders.defaultShader->SetVar("tex", 0);
    game->shaders.defaultShader->SetFloat("aoStrength", .45f);
    game->shaders.defaultShader->UnBind();
    game->shaders.skyShader = new Shader("src/Shader/sky.vert", "src/Shader/sky.frag");


    //init with graphic setting
    game->shaders.defaultShader->SetFloat("fogMin", graphicSetting.fogMin);
    game->shaders.defaultShader->SetFloat("fogMax", graphicSetting.fogMax);

    return 0;
}
void ClientEngine::launch() {
    //---init opengl
    window = new Window("Voxel Game");
    initialOpenGL();

    //init core engine
    m_input = new Input();
    m_input->initKeyMapping();

    //init game
	game = new Game(window);
    initialShader();
    game->init();
    while (!glfwWindowShouldClose(window->glfwWindow))
    { 
        // Take care of all GLFW events
        glfwPollEvents();
        m_input->update();
        game->counterTime();
        game->processInput();
        game->beforeUpdate();
        game->update();
        game->lastUpdate();
        game->render();

        // Swap the back buffer with the front buffer
        glfwSwapBuffers(window->glfwWindow);
    }
    exit();
}
void ClientEngine::exit() {
    glfwDestroyWindow(window->glfwWindow);
    glfwTerminate();
}

