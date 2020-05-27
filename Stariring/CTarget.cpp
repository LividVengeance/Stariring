#include "CTarget.h"

CTarget::CTarget(CInput* gameInputs, CCamera* camera, GLint program)
{
	targetInputs = gameInputs;

	float xSize = 30;
	float ySize = 30;

	const char* fileLocation = "Resources/Textures/targetSprite.png";
	targetMesh = new CMesh(program, camera, xSize, ySize, fileLocation);
}

CTarget::~CTarget()
{
}

void CTarget::Update()
{
	targetMesh->Update();
}

void CTarget::Render()
{
	targetMesh->Render();
}

void CTarget::TargetInputs()
{
	targetX = targetInputs->getMouseX();
	targetY = targetInputs->getMouseY();

	float offSetX = Utils::SCR_WIDTH/2;
	float offSetY = Utils::SCR_HEIGHT/2;

	// Places Target
	targetMesh->objPosition.x = -(offSetX - targetX);
	targetMesh->objPosition.y = (offSetY - targetY);

	actorPosition = vec2(targetMesh->objPosition.x, targetMesh->objPosition.y);
}