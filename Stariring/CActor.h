#pragma once

#include "CMesh.h"
#include "CInput.h"

class CActor
{
public:
	CActor(CInput* gameInputs, CCamera* camera, GLint program);
	~CActor();

	void Update();
	void Render();
	void MoveInput(GLfloat deltaTime);

	CMesh* actorMesh;
	glm::mat4 model;

	vec2 actorPosition;
	vec2 actorVelocity;

private:
	CInput* actorInputs;
};