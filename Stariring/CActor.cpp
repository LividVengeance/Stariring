#include "CActor.h"

CActor::CActor(CInput* gameInputs, CCamera* camera, GLint program, CTarget* target)
{
	actorInputs = gameInputs;
	actorTarget = target;

	float xSize = 30;
	float ySize = 30;

	const char* fileLocation = "Resources/Textures/actorSprite.png";
	actorMesh = new CMesh(program, camera, xSize, ySize, fileLocation);

	actorPosition = vec2(actorMesh->objPosition);
	actorVelocity = vec2(2.0f, 2.0f);
}

CActor::~CActor()
{
}

void CActor::Update()
{
	SteeringSeek();

	actorMesh->objPosition = glm::vec3(actorPosition, 0);
	actorMesh->Update();
}

void CActor::Render()
{
	actorMesh->Render();
}

void CActor::SteeringSeek()
{
	actorPosition = actorPosition + actorVelocity;
	 
	actorDesiredVelocity = normalize(actorTarget->actorPosition - actorPosition) * maxVelocity;
	actorSteering = actorDesiredVelocity - actorVelocity;

	actorSteering = glm::normalize(actorSteering) * clamp(glm::length(actorSteering), 0.0f, maxForce);
	actorSteering = actorSteering / actorMass;

	actorVelocity = glm::normalize(actorVelocity + actorSteering) * clamp(glm::length(actorVelocity), 0.0f, maxSpeed);

	if (actorVelocity.x > 9999999 || actorVelocity.y > 999999)
	{
		actorVelocity.x = 0.0f;
		actorVelocity.y = 0.0f;
	}

	actorPosition = actorPosition + actorVelocity;
}
