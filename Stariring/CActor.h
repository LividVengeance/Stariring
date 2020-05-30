#pragma once
#include <math.h>
#include <iostream>

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
	void SteeringSeek();

	CMesh* actorMesh;
	glm::mat4 model;

	CTarget* actorTarget;

	vec2 actorPosition;
	vec2 actorVelocity;
	vec2 actorDesiredVelocity;
	vec2 actorSteering;

	float maxVelocity = 10.0f;
	float maxSpeed = 10.0f;
	float maxForce = 10.0f;
	float actorMass = 10.0f;

private:
	CInput* actorInputs;
};