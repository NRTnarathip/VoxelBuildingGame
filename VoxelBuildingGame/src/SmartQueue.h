#pragma once
#include <queue>
#include <SmartChunk.h>

//for safety cross threading

class SmartDequeChunkGroup {
private:
	std::mutex mutex;
	std::deque<SmartChunkGroup*> listPooling;//emty or has on delete chunkgroup
public:
	size_t size() {
		mutex.lock();
		int s = (int)listPooling.size();
		mutex.unlock();
		return s;
	}
	SmartChunkGroup* getFront() {
		mutex.lock();
		auto sm = listPooling.front();
		listPooling.pop_front();
		mutex.unlock();

		return sm;
	}
	void push_back(SmartChunkGroup* sm) {
		mutex.lock();
		listPooling.push_back(sm);
		mutex.unlock();
	}
};
class SmartQueueChunkGroup {
private:
	std::mutex mutex;
	std::queue<SmartChunkGroup*> queChunkGroups;
public:
	//will push back
	size_t size() {
		return queChunkGroups.size();
	}
	void push(SmartChunkGroup* smChunk) {
		mutex.lock();
		queChunkGroups.push(smChunk);
		mutex.unlock();
	}
	SmartChunkGroup* front() {
		mutex.lock();
		if (size() == 0) {
			mutex.unlock();
			return NULL;
		}

		auto smCG = queChunkGroups.front();
		mutex.unlock();
		return smCG;
	}
	SmartChunkGroup* getFront() {
		mutex.lock();
		if (size() == 0) {
			mutex.unlock();

			return NULL;
		}

		auto smCG = queChunkGroups.front();
		queChunkGroups.pop();

		mutex.unlock();
		return smCG;
	}
	void TransferData(SmartQueueChunkGroup& other) {
		mutex.lock();
		queChunkGroups = other.queChunkGroups;
		mutex.unlock();

	}
	void TransferData(std::queue<SmartChunkGroup*>& other) {
		mutex.lock();
		queChunkGroups = other;
		mutex.unlock();
	}
};