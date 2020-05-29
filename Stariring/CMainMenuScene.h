#pragma once

#include "CCamera.h"
#include "CInput.h"
#include "CMesh.h"

class CMainMenuScene
{
public:
	CMainMenuScene(GLint* _program, CCamera* _gameCamera, CInput* _gameInputs);
	~CMainMenuScene();

	void Render();
	void Update(GLfloat* deltaTime, ESceneManager* _currentScene);

	float mouseX;
	float mouseY;

	float offSetX = Utils::SCR_WIDTH / 2;
	float offSextY = Utils::SCR_HEIGHT / 2;

	ESceneManager* currentScene;

	GLint* program;
	CCamera* gameCamera;

	CMesh* playButtonMesh;
	CMesh* exitButtonMesh;

	CInput* gameInputs;

private:

};

