#include "CSeekScene.h"

CSeekScene::CSeekScene(GLint* _program, CCamera* _gameCamera, CActor* _gameActor, CTarget* _gameTarget)
{
	program = _program;
	gameCamera = _gameCamera;
	gameActor = _gameActor;
	gameTarget = _gameTarget;

}

CSeekScene::~CSeekScene()
{
}

void CSeekScene::Render()
{
	gameActor->Render();
	gameTarget->Render();
}

void CSeekScene::Update(GLfloat* deltaTime)
{
	gameCamera->Update();
	gameActor->Update();
	gameTarget->TargetInputs();
	gameTarget->Update();
}