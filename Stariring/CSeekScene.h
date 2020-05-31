#pragma once
#include "CCamera.h"
#include "CInput.h"
#include "CMesh.h"
#include "CActor.h"
#include "CTarget.h"

class CSeekScene
{
public:
	CSeekScene(GLint* _program, CCamera* _gameCamera, CActor* _gameActor, CTarget* _gameTarge, CInput* _gameInput);
	~CSeekScene();

	void Render();
	void Update(GLfloat* deltaTime, ESceneManager* currentScene);

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
