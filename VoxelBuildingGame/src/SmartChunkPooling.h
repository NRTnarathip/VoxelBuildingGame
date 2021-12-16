#pragma once
#include <vector>
#include <iostream>
#include <SmartChunk.h>
#include <deque>
#include <mutex>

class SmartChunkPooling {
private:
	std::mutex mutex;
	std::deque<SmartChunkGroup*> listPooling;//emty or has on delete chunkgroup
public:
	SmartChunkGroup* makeSmartChunk(glm::ivec2 pos) {
		mutex.lock();
		int poolSize = listPooling.size();
		mutex.unlock();

		SmartChunkGroup* sm = NULL;
		if (poolSize == 0) {
			
			//create new SmartChunk* 
			//dont add to list pooling
			sm = new SmartChunkGroup(pos);
			sm->lock();
			auto posChunk = glm::ivec3(pos.x, 0, pos.y);
			for (int y = 0; y < 8; y++) {
				posChunk.y = y << 5;
				sm->get()->chunks[y] = new Chunk(posChunk);
			}
		}
		//have pooling object
		else {
			sm = listPooling.front();
			sm->lock();

			listPooling.pop_front();

			//setup chunk group data
			auto chunkGroup = sm->get();
			chunkGroup->pos = pos;

			//setup chunk sub data
			auto posChunk = glm::ivec3(pos.x, 0, pos.y);
			for (int y = 0; y < 8; y++) {
				posChunk.y = y << 5;
				chunkGroup->chunks[y]->pos = posChunk;

				chunkGroup->chunks[y]->mesh.setupMesh();
			}
		}
		
		sm->onSetup();
		sm->unlock();
		return sm;
	}
	//dont forget use mutex
	void collectPooling(SmartChunkGroup* smChunk) {
		//clear chunk all
		smChunk->onDelete();
		for (auto c : smChunk->get()->chunks) {
			memset(c->voxels, 0, sizeof(c->voxels));

			c->mesh.clearOnGPU();
		}
		mutex.lock();
		listPooling.push_back(smChunk);
		mutex.unlock();
	}
};