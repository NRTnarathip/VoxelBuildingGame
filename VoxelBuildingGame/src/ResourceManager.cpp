#include "ResourceManager.h"
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

}