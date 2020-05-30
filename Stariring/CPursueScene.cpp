#include "CPursueScene.h"

CPursueScene::CPursueScene(GLint* _program, CCamera* _gameCamera, CActor* _gameActor, CTarget* _gameTarget, CActorPursue* _actorPursue)
{
	program = _program;
	gameCamera = _gameCamera;
	gameActor = _gameActor;
	gameTarget = _gameTarget;
	gameActorPursue = _actorPursue;
}

CPursueScene::~CPursueScene()
{
}

void CPursueScene::Render()
{
	gameActor->Render();
	gameTarget->Render();
	gameActorPursue->Render();
}

void CPursueScene::Update()
{
	gameCamera->Update();
	gameActor->Update();
	gameTarget->TargetInputs();
	gameTarget->Update();
	gameActorPursue->Update();
}