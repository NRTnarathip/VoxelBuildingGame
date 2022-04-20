#pragma once
#include "Renderer/shaderClass.h"
#include <vector>

class ResourceManager {
private:
	static ResourceManager* instance;
public:
    ResourceManager() {
        instance = this;
    }
	static ResourceManager* GetInstance() { return instance; }
    std::vector<Shader*> m_shaders;
    std::vector<Texture*> m_textures;
    Shader* addShader(const char* pathVertexFile, const char* pathFragmentFile) {
        auto newShader = new Shader(pathVertexFile, pathFragmentFile);
        m_shaders.push_back(newShader);
        return newShader;
    }
};