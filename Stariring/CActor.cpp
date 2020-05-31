#include "CActor.h"

CActor::CActor(CInput* gameInputs, CCamera* camera, GLint program, CTarget* target)
{
	actorInputs = gameInputs;
	actorTarget = target;

	float xSize = 30;
	float ySize = 30;

	const char* fileLocation = "Resources/Textures/actorSprite.png";
	actorMesh = new CMesh(program, camera, xSize, ySize, fileLocation);
}

CActor::~CActor()
{
}

void CActor::Update()
{
	SteeringSeek();

	actorMesh->objPosition = glm::vec3(actorPosition, 0);
	actorMesh->Update();

	Wrap();
}

void CActor::UpdateArrival()
{
	SteeringArrival();

	actorMesh->objPosition = glm::vec3(actorPosition, 0);
	actorMesh->Update();

	Wrap();
}

void CActor::Render()
{
	actorMesh->Render();
}

void CActor::SteeringSeek()
{
	vec2 actorDesiredVelocity;
	vec2 actorDesiredPoisiton = actorTarget->actorPosition - actorPosition;

	actorDesiredVelocity = glm::normalize(actorDesiredPoisiton) * maxSpeed;

	vec2 actorSteering = actorDesiredVelocity - actorVelocity;

	actorSteering = glm::normalize(actorSteering) * clamp((float)glm::length(actorSteering), 0.0f, maxForce);
	actorVelocity += actorSteering;
	actorVelocity = glm::normalize(actorVelocity) * clamp((float)glm::length(actorVelocity), 0.0f, maxSpeed);

	if (isnan(actorVelocity.x) or isnan(actorVelocity.y))
	{
		actorVelocity = glm::vec2(0, 0);
	}

	actorPosition += actorVelocity;
}

void CActor::SteeringWander()
{

}

void CActor::SteeringArrival()
{
	vec2 actorDesiredVelocity;
	vec2 actorDesiredPoisiton = actorTarget->actorPosition - actorPosition;

	// Check distance inside slow area
	if (glm::length(actorDesiredPoisiton) < slowingRadius)
	{
		// Actor is in the slowing area
		actorDesiredVelocity = glm::normalize(actorDesiredPoisiton) * maxForce * (glm::length(actorDesiredPoisiton) / slowingRadius);
	}
	else
	{
		// Actor outside slowing area
		actorDesiredVelocity = glm::normalize(actorDesiredPoisiton) * maxSpeed;
	}

	vec2 actorSteering = actorDesiredVelocity - actorVelocity;

	actorSteering = glm::normalize(actorSteering) * clamp((float)glm::length(actorSteering), 0.0f, maxForce);
	actorVelocity += actorSteering;
	actorVelocity = glm::normalize(actorVelocity) * clamp((float)glm::length(actorVelocity), 0.0f, maxSpeed);

	if (isnan(actorVelocity.x) or isnan(actorVelocity.y))
	{
		actorVelocity = glm::vec2(0, 0);
	}

	actorPosition += actorVelocity;

	//float actorAngleOfRotation = glm::degrees(atan2(actorVelocity.y, actorVelocity.x)) - 90;
}

void CActor::Wrap()
{
	float width = Utils::SCR_WIDTH / 2;
	float height = Utils::SCR_HEIGHT / 2;

	if (actorPosition.x < -width)
	{
		actorPosition.x += Utils::SCR_WIDTH;
	}
	else if (actorPosition.x > width)
	{
		actorPosition -= Utils::SCR_WIDTH;
	}

	if (actorPosition.y < -height)
	{
		actorPosition.y += Utils::SCR_HEIGHT;
	}
	else if (actorPosition.y > height)
	{
		actorPosition.y -= Utils::SCR_HEIGHT;
	}
}