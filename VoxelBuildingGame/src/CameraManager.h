#pragma once
#include <Camera.h>
#include <list>
class CameraManager {
private:
	static CameraManager* instance;
	Camera* m_currentCamera = nullptr;

	std::list<Camera*> m_cameras;
public:
	CameraManager();
	//Singletons should not be cloneable.
	CameraManager(CameraManager& other) = delete;
	//Singletons should not be assignable.
	void operator=(const CameraManager&) = delete;

	static CameraManager& GetInstance() { return *instance; };

	void uploadCameraMatrix();
	Camera* getCurrentCamera();
	void switchCamera(Camera* other);
	Camera* newCamera();

public:
	//function global
	static Camera* GetCurrentCamera() { return instance->m_currentCamera; }
	static Camera* SwitchCamera(Camera* other) { instance->switchCamera(other); }
};