#pragma once
#include <freeglut.h>
#include <SOIL.h>
#include <iostream>

#include "CCamera.h"
#include "CActor.h"

class CGameScene
{
public:
	CGameScene(GLint* _program, CCamera* _gameCamera, CActor* _gameActor, CTarget* _gameTarge);
	~CGameScene();

	void Render();
	void Update(GLfloat* deltaTime);

	GLint* program;
	CCamera* gameCamera;
	CActor* gameActor;
	CTarget* gameTarget;

private:

};
