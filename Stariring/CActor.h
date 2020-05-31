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

	float slowingRadius = 100.0f;
	float maxSpeed = 15.0f;
	float maxForce = 2.0f;
	float actorMass = 5.0f;

	// Wander
	float wanderAngle = 10.0f;
	int changeAngle = 10;

private:
	CInput* actorInputs;
};