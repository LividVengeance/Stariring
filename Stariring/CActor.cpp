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
	actorVelocity = vec2(1.0f, 1.0f);
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
	actorPosition = actorPosition + actorVelocity;

	actorDesiredVelocity = normalize(actorTarget->actorPosition - actorPosition) * maxVelocity;
	actorSteering = actorDesiredVelocity - actorVelocity;

	actorSteering = glm::normalize(actorSteering) * clamp((float)glm::length(actorSteering), 0.0f, maxForce);

	std::cout << glm::length(actorVelocity ) << std::endl;

	actorVelocity = glm::normalize(actorVelocity + actorSteering) * clamp((float)glm::length(actorVelocity), 0.0f, maxSpeed);

	if (isnan(actorVelocity.x) or isnan(actorVelocity.y))
	{
		actorVelocity = glm::vec2(0, 0);
	}

	actorPosition = actorPosition + actorVelocity;
}

void CActor::SteeringWander()
{

}

void CActor::SteeringArrival()
{
	actorVelocity = glm::normalize(actorVelocity + actorSteering) * clamp(glm::length(actorVelocity), 0.0f, maxSpeed);
	actorPosition = actorPosition + actorVelocity;

	// Calculating desired velocity
	actorDesiredVelocity = actorTarget->actorPosition - actorPosition;
	distance = glm::length(actorDesiredVelocity);

	// Check distance inside slow area
	if (distance < slowingRadius)
	{
		// Actor is in the slowing area
		actorDesiredVelocity = glm::normalize(actorDesiredVelocity) * maxVelocity * (distance / slowingRadius);
	}
	else
	{
		// Actor outside slowing area
		actorDesiredVelocity = glm::normalize(actorDesiredVelocity) * maxVelocity;
	}

	actorSteering = actorDesiredVelocity - actorVelocity;

	actorVelocity = glm::normalize(actorVelocity + actorSteering) * clamp(glm::length(actorVelocity), 0.0f, maxSpeed);
	actorPosition = actorPosition + actorVelocity;
}

void CActor::Wrap()
{
	float width = Utils::SCR_WIDTH/2;
	float height = Utils::SCR_HEIGHT / 2;

	if (actorPosition.x < -width)
	{
		actorPosition.x += Utils::SCR_WIDTH;
	}
	else if (actorPosition.x > Utils::SCR_WIDTH)
	{
		actorPosition -= Utils::SCR_WIDTH;
	}

	if (actorPosition.y < -height)
	{
		actorPosition.y += Utils::SCR_HEIGHT;
	}
	else if (actorPosition.y > Utils::SCR_HEIGHT)
	{
		actorPosition.y -= Utils::SCR_HEIGHT;
	}
}