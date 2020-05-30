#pragma once

#include "CCamera.h"
#include "CInput.h"
#include "CMesh.h"

#include "CActor.h"
#include "CTarget.h"
#include "CActorPursue.h"

class CPursueScene
{
public:
	CPursueScene(GLint* _program, CCamera* _gameCamera, CActor* _gameActor, CTarget* _gameTarget, CActorPursue* _actorPursue);
	~CPursueScene();
	
	void Render();
	void Update();

	GLint* program;
	CCamera* gameCamera;
	CActor* gameActor;
	CActorPursue* gameActorPursue;
	CTarget* gameTarget;

private:

};



