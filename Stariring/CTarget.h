#pragma once

#include "CInput.h"
#include "CMesh.h"
#include "CCamera.h"
#include "Utilities.h"

class CTarget
{
public:
	CTarget(CInput* gameInputs, CCamera* camera, GLint program);
	~CTarget();

	void Update();
	void Render();
	void TargetInputs();

	CMesh* targetMesh;

	int targetX = 0;
	int targetY = 0;

private:

	CInput* targetInputs;
};

