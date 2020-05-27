#include "CActor.h"

CActor::CActor(CInput* gameInputs, CCamera* camera, GLint program)
{
	actorInputs = gameInputs;

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
	actorMesh->Update();
}

void CActor::Render()
{
	actorMesh->Render();
}

void CActor::MoveInput(GLfloat deltaTime)
{
	int actorX = actorInputs->getMouseX();
	int actorY = actorInputs->getMouseY();

	actorPostion.x = actorX;
	actorPostion.z = actorY;

 
}
