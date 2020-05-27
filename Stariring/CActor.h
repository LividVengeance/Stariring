#pragma once

#include "CMesh.h"
#include "CInput.h"
#include "CTarget.h"

class CActor
{
public:
	CActor(CInput* gameInputs, CCamera* camera, GLint program, CTarget* target);
	~CActor();

	void Update();
	void Render();
	void MoveInput(GLfloat deltaTime);

	CMesh* actorMesh;
	glm::mat4 model;

	CTarget* actorTarget;

	vec2 actorPosition;
	vec2 actorVelocity;

	float maxVelocity = 10.0f;

private:
	CInput* actorInputs;
};