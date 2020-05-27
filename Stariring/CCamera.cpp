#pragma

#include "CCamera.h"

CCamera::CCamera(GLint* _program)
{
	program = _program;
	// Orthographic Center Camera
	mat4 proj;

	/// Ortho Cam with origin (0,0) in the top left
	float halfScreenWidth = (float)SCR_WIDTH * 0.5f;
	float halfScreenHeight = (float)SCR_HEIGHT * 0.5f;
	//proj = ortho(-halfScreenWidth, halfScreenWidth, -halfScreenHeight, halfScreenHeight, 0.1f, 100.0f);
	proj = glm::perspective(45.0f, halfScreenWidth / halfScreenHeight, 0.1f, 10000.0f);
	GLuint projLoc = glGetUniformLocation(*program, "proj");
	glUniformMatrix4fv(projLoc, 1, GL_FALSE, value_ptr(proj));

	Update();
}

CCamera::~CCamera()
{
}

mat4 CCamera::CameraView()
{
	float halfScreenWidth = (float)SCR_WIDTH * 0.5f;
	float halfScreenHeight = (float)SCR_HEIGHT * 0.5f;
	mat4 proj;
	proj = ortho(-halfScreenWidth, halfScreenWidth, -halfScreenHeight, halfScreenHeight, 0.1f, 100.0f);

	GLuint projLoc = glGetUniformLocation(*program, "proj");
	glUniformMatrix4fv(projLoc, 1, GL_FALSE, value_ptr(proj));
	return(view);
}

void CCamera::Update()
{
	view = lookAt(camPos, camPos + camLookDir, camUpDir);
}

