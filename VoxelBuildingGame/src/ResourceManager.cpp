#include "ResourceManager.h"
#include "ClientEngine.h"
#include <string>
#include <iostream>
#include <filesystem>
#include <algorithm>

ResourceManager* ResourceManager::instance = nullptr;

Shader* ResourceManager::addShader(std::string pathVertexAndFragment, std::string shaderName) {
    auto pathVert = pathVertexAndFragment + ".vert";
    auto pathFrag = pathVertexAndFragment + ".frag";
    auto newShader = new Shader(pathVert.c_str(), pathFrag.c_str());
    m_shaders.emplace(shaderName, newShader);
    return newShader;
}

Texture* ResourceManager::addTexture(const char* pathFile, bool isMipmapping) {
    auto texture = new Texture(pathFile, false, isMipmapping, GL_CLAMP_TO_BORDER, GL_NEAREST);
    m_textures.emplace(pathFile, texture);
    return texture;
}
Sprite* ResourceManager::addSprite(Sprite* sprite, std::string key) {
    sprite->setupRenderData();
    m_sprites.emplace(key, sprite);
    return sprite;
}
void ResourceManager::loadAllResouces() {
    namespace fs = std::filesystem;
    //load resouce all shader
    std::string pathShaders = "src/Shader";
    int isFileExist = 0;
    for (const auto& entry : fs::directory_iterator(pathShaders)) {
        if (isFileExist > 0) {
            isFileExist = 0;
            continue;
        }

        std::string filename = entry.path().string();
        std::string pathFileShader = entry.path().string();

        filename.replace(0, pathShaders.length()+1, "");
        filename = filename.substr(0, filename.length() - 5);

        std::replace(pathFileShader.begin(), pathFileShader.end(), '\\', '/');
        pathFileShader = pathFileShader.substr(0, pathFileShader.length() - 5);
        addShader(pathFileShader, filename);
        isFileExist++;
    }
    //auto defaultShader = addShader("src/Shader/defualt", "default");
    //addShader("src/Shader/gameobject", "gameobject");
    //auto shaderRender2D = addShader("src/Shader/sprite", "sprite");
    auto& graphicSetting = ClientEngine::GetInstance().graphicSetting;
   /* defaultShader->Bind();
    defaultShader->SetVar("tex", 0);
    defaultShader->SetFloat("aoStrength", 0.45f);
    defaultShader->SetFloat("fogMin", graphicSetting.fogMin);
    defaultShader->SetFloat("fogMax", graphicSetting.fogMax);
    defaultShader->UnBind();*/

    auto book = addTexture("assets/textures/gui/book.png", false);
    auto bgMainMenu = addTexture("assets/textures/gui/presets/dirt_background.png", false);
    addTexture("src/Texture/mcatlas.png", true);
    //add steam sprites;
    addSprite(new Sprite(bgMainMenu), "bgMainMenu");
    //res->addSprite(new Sprite(book), "book");
}