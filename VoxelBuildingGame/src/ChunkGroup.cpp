#include <ChunkGroup.h>
#include <Game.h>
ChunkGroup::ChunkGroup(glm::ivec2 initPos) {
    pos = initPos;
}

ChunkGroup::~ChunkGroup() {
    for (unsigned char i = 0; i < 8; i++) {
        delete chunks[i];
    }
}
void ChunkGroup::clearChunk() {
    for (auto c : chunks) {
        //clear cnear referance all
        if (c->cnearNorth != NULL ) {
            c->cnearNorth->cnearSouth = NULL;
            c->cnearNorth = NULL;
        }
        if (c->cnearSouth != NULL) {
            c->cnearSouth->cnearNorth = NULL;
            c->cnearSouth = NULL;
        }
        if (c->cnearEast != NULL) {
            c->cnearEast->cnearWest = NULL;
            c->cnearEast = NULL;
        }
        if (c->cnearWest != NULL) {
            c->cnearWest->cnearEast = NULL;
            c->cnearWest = NULL;
        }
    }
}
bool ChunkGroup::checkIsHaveVoxel(Chunk* c) {
    for (int acc = 0; acc < Chunk::CHUNK_SIZE_BLOCK; acc++) {
        if (c->voxels[acc].type > 0) {
            return true;
        }
    }
    return false;
}
void ChunkGroup::render() {
    auto defaultShader = Game::ref->shaders.defaultShader;
    auto mcatlas = Game::ref->shaders.mcatlas;

    for (auto c : chunks) {
        // Mesh must be on gpu to draw
        glm::vec3 pos;
        pos.x = c->pos.x;
        pos.y = c->pos.y;
        pos.z = c->pos.z;

        glm::mat4 model = glm::mat4(1.f);
        model = glm::translate(model, pos);
        defaultShader->Bind();
        defaultShader->SetMat4("model", model);
        mcatlas->Activate(GL_TEXTURE0);

        c->mesh.draw();
    }
}
