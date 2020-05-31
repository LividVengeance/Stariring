#pragma once

#include "CMesh.h"
#include "CActor.h"

class CActorPursue
{
public:
	CActorPursue(GLint program, CCamera* gameCamera, CActor* _actor);
	~CActorPursue();

	void Update();
	void Render();

	void SteeringSeek(vec2 position);
	void SteeringWander();

	CMesh* actorMesh;
	CCamera* gameCamera;

	CActor* actor;

	vec2 futurePostion;

	vec2 actorPosition;
	vec2 actorVelocity;

	float maxSpeed = 15.0f;
	float maxForce = 2.0f;
	float actorMass = 10.0f;

private:
	float T = 3.0f;
};