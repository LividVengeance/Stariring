#include "CMainMenuScene.h"

CMainMenuScene::CMainMenuScene(GLint* _program, CCamera* _gameCamera, CInput* _gameInputs)
{
	program = _program;
	gameCamera = _gameCamera;
	gameInputs = _gameInputs;

	// Create button meshes
	int playMeshScale = 30;
	const char* fileLocationPlay = "Resources/Textures/playSprite.png";
	playButtonMesh = new CMesh(*program, gameCamera, playMeshScale, playMeshScale, fileLocationPlay);

	const char* fileLocationExit = "Resources/Textures/exitSprite.png";
	exitButtonMesh = new CMesh(*program, gameCamera, playMeshScale, playMeshScale, fileLocationExit);
}

CMainMenuScene::~CMainMenuScene()
{
}

void CMainMenuScene::Render()
{
	playButtonMesh->Render();
	exitButtonMesh->Render();
}

void CMainMenuScene::Update(GLfloat* deltaTIme)
{
	mouseX = gameInputs->getMouseX();
	mouseY = gameInputs->getMouseY();

	// Mouse has clicked button check
	if (mouseX > playButtonMesh->objPosition.x - 50 && mouseX < playButtonMesh->objPosition.x + 50
		&& mouseY > playButtonMesh->objPosition.y - 25 && mouseY < playButtonMesh->objPosition.y + 25
		&& gameInputs->getClick(1))
	{
		// Play Button
		Utils::currentScene = EGameScene;
	}
	if (mouseX > exitButtonMesh->objPosition.x - 50 && mouseX < exitButtonMesh->objPosition.x + 50
		&& mouseY > exitButtonMesh->objPosition.y - 25 && mouseY < exitButtonMesh->objPosition.y + 25
		&& gameInputs->getClick(1))
	{
		// Exit Button
		
		// ______EXIT PROGRAM_______
	}
}