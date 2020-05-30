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

	void UpdateArrival();

	// Steering memes
	void SteeringSeek();
	void SteeringWander();
	void SteeringArrival();
	
	void Wrap();

	CMesh* actorMesh;
	glm::mat4 model;

	CTarget* actorTarget;

	vec2 actorPosition;
	vec2 actorVelocity;
	vec2 actorDesiredVelocity;
	vec2 actorSteering;

	float distance;
	float slowingRadius = 100.0f;

	float maxVelocity = 10.0f;
	float maxSpeed = 10.0f;
	float maxForce = 0.2f;

private:
	CInput* actorInputs;
};