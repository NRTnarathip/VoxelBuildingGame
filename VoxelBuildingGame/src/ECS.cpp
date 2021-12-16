#include <ECS.h>

void Entity::Render() {
	for (auto& c : components) {
		c->render();
	}

	if (shader and mesh) {
		if (mesh->isHaveData()) {
			//printf("Draw entity '%s'\n", this->GetName().c_str());

			shader->Bind();
			glm::mat4 model = glm::mat4(1.0f);
			model = glm::translate(model, transform.position);
			shader->SetMat4("model",model);
			mesh->draw();
		}
	}
}