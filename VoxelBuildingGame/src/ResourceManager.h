#pragma once
#include "Renderer/shaderClass.h"
#include <vector>
#include <map>
#include <string>
#include "GUI/Sprite.h"

class ResourceManager {
private:
	static ResourceManager* instance;
public:
    ResourceManager() {
        instance = this;
    }
	static ResourceManager* GetInstance() { return instance; }
    std::map<std::string, Shader*> m_shaders;
    std::map<std::string, Sprite*> m_sprites;
    std::map<std::string, Texture*> m_textures;
    Texture* addTexture(const char* pathFile, bool isMipmapping);
    Shader* addShader(std::string pathVertexAndFragment, std::string shaderName);
    Sprite* addSprite(Sprite* sprite, std::string key);
    void loadAllResouces();
};