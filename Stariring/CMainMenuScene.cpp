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

	playButtonMesh->objPosition.y += 100;
	exitButtonMesh->objPosition.y -= 100;
}

CMainMenuScene::~CMainMenuScene()
{
}

void CMainMenuScene::Render()
{
	playButtonMesh->Render();
	exitButtonMesh->Render();
}

void CMainMenuScene::Update(GLfloat* deltaTIme, ESceneManager* _currentScene)
{
	currentScene = _currentScene;
	playButtonMesh->Update();
	exitButtonMesh->Update();

	

	// Mouse has clicked button check
	if (Button(100, 50, playButtonMesh) || gameInputs->getKeyState('e'))
	{
		// Play Button
		*currentScene = EGameScene;
	}
	if (Button(100, 50, exitButtonMesh))
	{
		// Exit Button
		
		// ______EXIT PROGRAM_______
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