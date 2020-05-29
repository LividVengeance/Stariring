#pragma once
#include "CCamera.h"
#include "CInput.h"
#include "CMesh.h"
#include "CActor.h"
#include "CTarget.h"

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
