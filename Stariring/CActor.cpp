#include "CActor.h"

CActor::CActor(CInput* gameInputs, CCamera* camera, GLint program, CTarget* target)
{
	actorInputs = gameInputs;
	actorTarget = target;

	float xSize = 30;
	float ySize = 30;

	const char* fileLocation = "Resources/Textures/actorSprite.png";
	actorMesh = new CMesh(program, camera, xSize, ySize, fileLocation);

	actorPosition = vec2(actorMesh->objPosition.x, actorMesh->objPosition.y);
	actorVelocity = vec2(10.0f, 10.0f);
}

CActor::~CActor()
{
}

void CActor::Update()
{
	actorMesh->Update();
}

void CActor::Render()
{
	actorMesh->Render();
}

void CActor::MoveInput(GLfloat deltaTime)
{
	actorPosition = actorPosition + actorVelocity;

	actorVelocity = normalize(actorTarget->actorPosition - actorPosition) * maxVelocity;
}
