#pragma once

#include "CCamera.h"
#include "CInput.h"
#include "CMesh.h"

#include "CActor.h"
#include "CTarget.h"

class CArrivalScene
{
public:
	CArrivalScene(GLint* _program, CCamera* _gameCamera, CActor* _gameActor, CTarget* _gameTarget, CInput* _gameInput);
	~CArrivalScene();

	void Render();
	void Update(ESceneManager* _currentScene);

	bool Button(float width, float height, CMesh* buttonMesh);

	float mouseX;
	float mouseY;

	ESceneManager* currentScene;

	GLint* program;
	CCamera* gameCamera;
	CActor* gameActor;
	CTarget* gameTarget;

	CInput* gameInput;

	CMesh* backButtonMesh;

private:

};

