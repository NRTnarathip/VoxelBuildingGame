#pragma once
#define CHUNK_SIZE 32

class GraphicSetting {
public:
	GraphicSetting() {
		fogMin = CHUNK_SIZE * 12;
		fogMax = CHUNK_SIZE * 16;
	}
	bool parserConfig() {
		return true;
	}
	int fogMin,fogMax;
	int renderDistance = 4; 
};