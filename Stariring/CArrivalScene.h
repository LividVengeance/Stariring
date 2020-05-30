#pragma once

#include "CCamera.h"
#include "CInput.h"
#include "CMesh.h"

#include "CActor.h"
#include "CTarget.h"

class CArrivalScene
{
public:
	CArrivalScene(GLint* _program, CCamera* _gameCamera, CActor* _gameActor, CTarget* _gameTarget);
	~CArrivalScene();

	void Render();
	void Update();

	GLint* program;
	CCamera* gameCamera;
	CActor* gameActor;
	CTarget* gameTarget;

private:

};

