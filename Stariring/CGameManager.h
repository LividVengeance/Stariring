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
#include "CTarget.h"
#include "CTextLabel.h"
#include "Utilities.h"

// Program Scenes
#include "CMainMenuScene.h"
#include "CSeekScene.h"
#include "CPursueScene.h"
#include "CWanderScene.h"
#include "CArrivalScene.h"


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

	// Camera
	CCamera* gameCamera;
	glm::mat4 view;

	// Labels
	CTextLabel* exampleLabel;

	// Actors
	CInput* gameInputs;
	CActor* gameActor;
	CActorPursue* gameActorPursue;
	CTarget* gameTarget;

	// Game Scenes
	CMainMenuScene* gameMainMenuScene;
	CSeekScene* seekScene;
	CPursueScene* pursueScene;
	CWanderScene* wanderScene;
	CArrivalScene* arrivalScene;
	
	ESceneManager currentScene;

	GLfloat currentTime, previousTime, deltaTime;
	GLint program;
};