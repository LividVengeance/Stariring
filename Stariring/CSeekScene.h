#pragma once
#include "CCamera.h"
#include "CInput.h"
#include "CMesh.h"
#include "CActor.h"
#include "CTarget.h"

class CSeekScene
{
public:
	CSeekScene(GLint* _program, CCamera* _gameCamera, CActor* _gameActor, CTarget* _gameTarge);
	~CSeekScene();

	void Render();
	void Update(GLfloat* deltaTime);

	GLint* program;
	CCamera* gameCamera;
	CActor* gameActor;
	CTarget* gameTarget;

private:

};
