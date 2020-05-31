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
	CPursueScene(GLint* _program, CCamera* _gameCamera, CActor* _gameActor, CTarget* _gameTarget, CActorPursue* _actorPursue, CInput* _gameInput);
	~CPursueScene();
	
	void Render();
	void Update(ESceneManager* _currentScene);

	bool Button(float width, float height, CMesh* buttonMesh);

	GLint* program;
	CCamera* gameCamera;
	CActor* gameActor;
	CActorPursue* gameActorPursue;
	CTarget* gameTarget;

	float mouseX;
	float mouseY;
	CMesh* backButtonMesh;
	ESceneManager* currentScene;
	CInput* gameInput;

private:

};



