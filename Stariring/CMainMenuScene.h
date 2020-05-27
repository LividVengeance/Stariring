#pragma once
#include "CCamera.h"
#include "CMesh.h"
#include "CInput.h"

class CMainMenuScene
{
public:
	CMainMenuScene(GLint* _program, CCamera* _gameCamera, CInput* _gameInputs);
	~CMainMenuScene();

	void Render();
	void Update(GLfloat* deltaTime);

	float mouseX;
	float mouseY;

	float offSetX = Utils::SCR_WIDTH / 2;
	float offSextY = Utils::SCR_HEIGHT / 2;

	GLint* program;
	CCamera* gameCamera;

	CMesh* playButtonMesh;
	CMesh* exitButtonMesh;

	CInput* gameInputs;

private:

};

