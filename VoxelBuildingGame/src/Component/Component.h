#ifndef COMPONENT_H
#define COMPONENT_H
#include <Component/GameObject.h>

class Component : public GameObject {
private:
	GameObject* m_gameObject;
public:
	void setupGameObject(GameObject* refObject) { m_gameObject = refObject; }
	virtual void init() {};
	virtual void update() {};
	virtual void draw() {};
};

#endif
