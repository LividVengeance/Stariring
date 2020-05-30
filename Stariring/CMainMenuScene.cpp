#include "CMainMenuScene.h"

CMainMenuScene::CMainMenuScene(GLint* _program, CCamera* _gameCamera, CInput* _gameInputs)
{
	program = _program;
	gameCamera = _gameCamera;
	gameInputs = _gameInputs;

	// Create button meshes
	int playMeshScaleX = 200;
	int playMeshScaleY = 50;
	const char* fileLocationSeek = "Resources/Textures/seekButtonSprite.png";
	seekButtonMesh = new CMesh(*program, gameCamera, playMeshScaleX, playMeshScaleY, fileLocationSeek);

	const char* fileLocationPursue = "Resources/Textures/pursueButtonSprite.png";
	pursueButtonMesh = new CMesh(*program, gameCamera, playMeshScaleX, playMeshScaleY, fileLocationPursue);

	const char* fileLocationWander = "Resources/Textures/wanderButtonSprite.png";
	wanderButtonMesh = new CMesh(*program, gameCamera, playMeshScaleX, playMeshScaleY, fileLocationWander);

	const char* fileLocationArrival = "Resources/Textures/arrivalButtonSprite.png";
	arrivalButtonMesh = new CMesh(*program, gameCamera, playMeshScaleX, playMeshScaleY, fileLocationArrival);

	const char* fileLocationTitle = "Resources/Textures/steeringBehaviourSprite.png";
	titleMesh = new CMesh(*program, gameCamera, 600, playMeshScaleY, fileLocationTitle);

	seekButtonMesh->objPosition.y		+= 150;
	seekButtonMesh->objPosition.x		-= 400;

	pursueButtonMesh->objPosition.y		+= 100;
	pursueButtonMesh->objPosition.x		-= 400;

	wanderButtonMesh->objPosition.y		+= 50;
	wanderButtonMesh->objPosition.x		-= 400;

	arrivalButtonMesh->objPosition.x	-= 400;

	titleMesh->objPosition.y			+= 250;
	titleMesh->objPosition.x			-= 200;
}

CMainMenuScene::~CMainMenuScene()
{
}

void CMainMenuScene::Render()
{
	seekButtonMesh->Render();
	pursueButtonMesh->Render();
	wanderButtonMesh->Render();
	arrivalButtonMesh->Render();
	titleMesh->Render();
}

void CMainMenuScene::Update(GLfloat* deltaTIme, ESceneManager* _currentScene)
{
	currentScene = _currentScene;
	seekButtonMesh->Update();
	pursueButtonMesh->Update();
	wanderButtonMesh->Update();
	arrivalButtonMesh->Update();
	titleMesh->Update();

	

	// Mouse has clicked button check
	if (Button(200, 50, seekButtonMesh) || gameInputs->getKeyState('e'))
	{
		// Seek Button
		*currentScene = ESeekScene;
	}
	if (Button(200, 50, pursueButtonMesh) || gameInputs->getKeyState('r'))
	{
		// Pursue Button
		*currentScene = EPursueScene;
	}
	if (Button(200, 50, wanderButtonMesh))
	{
		// Wander Button
		*currentScene = EWanderScene;
	}
	if (Button(200, 50, arrivalButtonMesh) || gameInputs->getKeyState('y'))
	{
		// Arrival Button
		*currentScene = EArrivalScene;
	}
}

bool CMainMenuScene::Button(float width, float height, CMesh* buttonMesh)
{
	mouseX = gameInputs->getMouseX();
	mouseY = gameInputs->getMouseY();

	float offSetX = Utils::SCR_WIDTH / 2;
	float offSetY = Utils::SCR_HEIGHT / 2;

	if (mouseX > buttonMesh->objPosition.x - width/2 && 
		mouseX < buttonMesh->objPosition.x + width/2 && 
		mouseY > buttonMesh->objPosition.y - height/2 && 
		mouseY < buttonMesh->objPosition.y + height/2 && 
		gameInputs->getClick(0))
	{
		return(true);
	}
	else
	{
		return(false);
	}
}