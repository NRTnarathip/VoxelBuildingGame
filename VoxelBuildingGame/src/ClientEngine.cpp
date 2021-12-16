#include "MyGUI.h"
#include "ClientEngine.h"
#include <stb/stb_image.h>

ClientEngine* ClientEngine::refThis = NULL;
ClientEngine* ClientEngine::GetInstance() {
    return refThis;
}
ClientEngine::ClientEngine() {
    refThis = this;
}
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
    // Setup Dear ImGui context
    MyGUI myGUI;
    //init game
	game = new Game(window);
    myGUI.SetupImGui(game);

    initialShader();
    game->sceneMain = new Scene("inGame");
    game->init();
    game->start();
    bool show_another_window = true;
    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
    while (!glfwWindowShouldClose(window->glfwWindow))
    { 
        // Take care of all GLFW events
        glfwPollEvents();

        game->counterTime();
        game->processInput(window->glfwWindow);

        //impl imgui
        //Start the Dear ImGui frame
        myGUI.NewFrame();

        game->beforeUpdate();
        game->update();
        game->lastUpdate();
        game->render();

        myGUI.Update();
        myGUI.Render();

        // Swap the back buffer with the front buffer
        glfwSwapBuffers(window->glfwWindow);
    }
    myGUI.CleanUp();
    exit();
}
void ClientEngine::exit() {
    glfwDestroyWindow(window->glfwWindow);
    glfwTerminate();
}