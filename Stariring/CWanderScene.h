#pragma once
#include "CCamera.h"
#include "CInput.h"
#include "CMesh.h"
#include "CActor.h"
#include "CTarget.h"

class CWanderScene
{
public:
	CWanderScene(GLint* _program, CCamera* _gameCamera, CActor* _gameActor, CTarget* _gameTarget, CInput* _gameInput);
	~CWanderScene();

	void Update(ESceneManager* currentScene);
	void Render();

	bool Button(float width, float height, CMesh* buttonMesh);

	GLint* program;
	CCamera* gameCamera;
	CActor* gameActor;
	CTarget* gameTarget;

	float mouseX;
	float mouseY;
	CMesh* backButtonMesh;
	ESceneManager* currentScene;
	CInput* gameInput;

private:

};

