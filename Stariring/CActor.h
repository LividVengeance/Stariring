#pragma once
#include <math.h>
#include <iostream>

#include <stdio.h>  
#include <stdlib.h> 
#include <time.h> 

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
	void Reset();

	void UpdateArrival();
	void UpdateWander();

	// Steering memes
	void SteeringSeek();
	vec2 SteeringWander();
	void SteeringArrival();
	
	void Wrap();

	CMesh* actorMesh;
	glm::mat4 model;

	CTarget* actorTarget;

	vec2 actorPosition;
	vec2 actorVelocity;
	vec2 previousActorVelocity = vec2(0, 0);

	float slowingRadius = 100.0f;
	float maxSpeed = 5.0f;
	float maxForce = 0.2f;

	// Wander
	float wanderAngle = 10.0f;
	float changeAngle = 0.35f;

private:
	CInput* actorInputs;
};