#include "CWanderScene.h"

CWanderScene::CWanderScene(GLint* _program, CCamera* _gameCamera, CActor* _gameActor, CTarget* _gameTarget, CInput* _gameInput)
{
	program = _program;
	gameCamera = _gameCamera;
	gameActor = _gameActor;
	gameTarget = _gameTarget;
	gameInput = _gameInput;

	int meshScaleX = 200;
	int meshScaleY = 50;

	const char* fileLocation = "Resources/Textures/backButtonSprite.png";
	backButtonMesh = new CMesh(*program, gameCamera, meshScaleX, meshScaleY, fileLocation);

	backButtonMesh->objPosition.x += 450;
	backButtonMesh->objPosition.y -= 250;
}

CWanderScene::~CWanderScene()
{
}

void CWanderScene::Render()
{
	backButtonMesh->Render();

	gameActor->Render();
	gameTarget->Render();
}

void CWanderScene::Update(ESceneManager* _currentScene)
{
	currentScene = _currentScene;
	backButtonMesh->Update();

	gameCamera->Update();
	gameActor->UpdateWander();
	gameTarget->TargetInputs();
	gameTarget->Update();

	// Mouse has clicked button check
	if (Button(200, 50, backButtonMesh))
	{
		// Seek Button
		*currentScene = EMainMenuScene;
		gameActor->Reset();
	}
}

bool CWanderScene::Button(float width, float height, CMesh* buttonMesh)
{
	mouseX = gameInput->getMouseX();
	mouseY = gameInput->getMouseY();

	float offSetX = Utils::SCR_WIDTH / 2;
	float offSetY = Utils::SCR_HEIGHT / 2;

	if (-(offSetX - mouseX) > buttonMesh->objPosition.x - width / 2 &&
		-(offSetX - mouseX) < buttonMesh->objPosition.x + width / 2 &&
		offSetY - mouseY > buttonMesh->objPosition.y - height / 2 &&
		offSetY - mouseY < buttonMesh->objPosition.y + height / 2 &&
		(gameInput->getClick(0) || gameInput->getClick(1)))
	{
		return(true);
	}
	else
	{
		return(false);
	}
}