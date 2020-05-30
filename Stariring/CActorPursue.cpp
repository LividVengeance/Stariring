#include "CActorPursue.h"

CActorPursue::CActorPursue(GLint program, CCamera* gameCamera, CActor* _actor)
{
	actor = _actor;

	float xSize = 30;
	float ySize = 30;

	const char* fileLocation = "Resources/Textures/actorPursueSprite.png";
	actorMesh = new CMesh(program, gameCamera, xSize, ySize, fileLocation);

	actorMesh->objPosition.x = rand() % Utils::SCR_WIDTH/2;
	actorMesh->objPosition.y = rand() % Utils::SCR_HEIGHT/2;


	actorPosition = vec2(actorMesh->objPosition.x, actorMesh->objPosition.y);
	actorVelocity = vec2(1.0f, 1.0f);
}

CActorPursue::~CActorPursue()
{
}

void CActorPursue::Update()
{
	SteeringWander();

	actorMesh->objPosition = glm::vec3(actorPosition, 0);
	actorMesh->Update();
}

void CActorPursue::Render()
{
	actorMesh->Render();
}

void CActorPursue::SteeringWander()
{
	vec2 distActor = actor->actorPosition - actorPosition;
	T = glm::length(distActor) / maxVelocity;

	futurePostion = actor->actorPosition + (actor->actorVelocity * T);
	SteeringSeek(futurePostion);

}

void CActorPursue::SteeringSeek(vec2 position)
{
	actorPosition = actorPosition + actorVelocity;

	actorDesiredVelocity = normalize(position - actorPosition) * maxVelocity;
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
