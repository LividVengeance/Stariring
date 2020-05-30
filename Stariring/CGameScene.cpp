#include "CGameScene.h"

CGameScene::CGameScene(GLint* _program, CCamera* _gameCamera, CActor* _gameActor, CTarget* _gameTarget)
{
	program = _program;
	gameCamera = _gameCamera;
	gameActor = _gameActor;
	gameTarget = _gameTarget;

}

CGameScene::~CGameScene()
{
}

void CGameScene::Render()
{
	gameActor->Render();
	gameTarget->Render();
}

void CGameScene::Update(GLfloat* deltaTime)
{
	gameCamera->Update();
	gameActor->Update();
	gameTarget->TargetInputs();
	gameTarget->Update();
}