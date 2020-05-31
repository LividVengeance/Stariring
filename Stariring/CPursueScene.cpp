#include "CPursueScene.h"

CPursueScene::CPursueScene(GLint* _program, CCamera* _gameCamera, CActor* _gameActor, CTarget* _gameTarget, CActorPursue* _actorPursue, CInput* _gameInput)
{
	program = _program;
	gameCamera = _gameCamera;
	gameActor = _gameActor;
	gameTarget = _gameTarget;
	gameActorPursue = _actorPursue;
	gameInput = _gameInput;

	int meshScaleX = 200;
	int meshScaleY = 50;

	const char* fileLocation = "Resources/Textures/backButtonSprite.png";
	backButtonMesh = new CMesh(*program, gameCamera, meshScaleX, meshScaleY, fileLocation);

	backButtonMesh->objPosition.x += 450;
	backButtonMesh->objPosition.y -= 250;
}

CPursueScene::~CPursueScene()
{
}

void CPursueScene::Render()
{
	backButtonMesh->Render();

	gameActor->Render();
	gameTarget->Render();
	gameActorPursue->Render();
}

void CPursueScene::Update(ESceneManager* _currentScene)
{
	currentScene = _currentScene;
	backButtonMesh->Update();

	gameCamera->Update();
	gameActor->Update();
	gameTarget->TargetInputs();
	gameTarget->Update();
	gameActorPursue->Update();

	// Mouse has clicked button check
	if (Button(200, 50, backButtonMesh))
	{
		// Seek Button
		*currentScene = EMainMenuScene;
	}
}

bool CPursueScene::Button(float width, float height, CMesh* buttonMesh)
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