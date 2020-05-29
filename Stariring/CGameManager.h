#pragma once

#include <glew.h>
#include <freeglut.h>
#include <SOIL.h>
#include <iostream>

#include "glm.hpp"
#include "gtc/matrix_transform.hpp"
#include "gtc/type_ptr.hpp"

#include "CActor.h"
#include "CCamera.h"
#include "CInput.h"
#include "CMesh.h"
#include "CShaderLoader.h"
#include "CTextLabel.h"
#include "Utilities.h"
#include "CTarget.h"
#include "CGameScene.h"
#include "CMainMenuScene.h"


using namespace glm;
using namespace std;

class CGameManager
{
public:
	CGameManager(int argc, char** argv);
	~CGameManager();

	void KeyBoardDown(unsigned char key, int x, int y);
	void KeyBoardUp(unsigned char key, int x, int y);
	void MousePassiveMove(int x, int y);
	void MouseClick(int button, int state, int x, int y);
	void MouseMove(int x, int y);

	void Update();
	void Render();
	void ManagerMain();

private:
	GLuint VBO, EBO, VAO;
	glm::mat4 playerMatModel;

	CCamera* gameCamera;

	glm::mat4 view;

	// Labels
	CTextLabel* exampleLabel;

	// Actors
	CInput* gameInputs;
	CActor* gameActor;
	CTarget* gameTarget;

	// Game Scenes
	CGameScene* gameScene;
	CMainMenuScene* gameMainMenuScene;

	ESceneManager currentScene;

	GLfloat currentTime, previousTime, deltaTime;
	GLint program;
};