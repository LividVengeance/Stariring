#include "CArrivalScene.h"

CArrivalScene::CArrivalScene(GLint* _program, CCamera* _gameCamera, CActor* _gameActor, CTarget* _gameTarget)
{
	program = _program;
	gameCamera = _gameCamera;
	gameActor = _gameActor;
	gameTarget = _gameTarget;
}

CArrivalScene::~CArrivalScene()
{
}

void CArrivalScene::Render()
{
	gameActor->Render();
	gameTarget->Render();
}

void CArrivalScene::Update()
{
	gameCamera->Update();
	gameActor->UpdateArrival();
	gameTarget->TargetInputs();
	gameTarget->Update();
}