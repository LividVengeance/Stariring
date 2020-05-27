#pragma once

#include "CGameManager.h"

CGameManager* globalPointerGM;

CGameManager::CGameManager(int argc, char** argv)
{
	globalPointerGM = this;

	// Setup and create at glut controlled window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(50, 50);
	glutInitWindowSize(Utils::SCR_WIDTH, Utils::SCR_HEIGHT);
	glutCreateWindow("Artificial Intelligence Summative Three - GD2P01");

	// Sets up all GL function callbacks based on pc hardware
	if (glewInit() != GLEW_OK)
	{
		// If glew fails to setup will throw error message
		std::cout << "Glew Faild to initialize. Now aborting." << std::endl;
		system("pause");
	}

	// Sets the clear colour
	glClearColor(0.0, 0.0, 0.0, 1.0); // Sets to Red

	// Enabling Culling
	glCullFace(GL_BACK);
	glFrontFace(GL_CCW);
	glEnable(GL_CULL_FACE);

	program = CShaderLoader::CreateProgram("Resources/Shaders/Basic.vs",
		"Resources/Shaders/Basic.fs");

	// Create Camera
	gameCamera = new CCamera(&program);

	// Create Input Controller
	gameInputs = new CInput();

	// Creates the target for actor
	gameTarget = new CTarget(gameInputs, gameCamera, program);

	// Creates the main actor
	gameActor = new CActor(gameInputs, gameCamera, program, gameTarget);

	// Creates the scene for the game
	gameScene = new CGameScene(&program, gameCamera, gameActor, gameTarget);

	// Creates the main menu scene
	gameMainMenuScene = new CMainMenuScene(&program, gameCamera, gameInputs);

	Utils::currentScene = EMainMenuScene;
}

CGameManager::~CGameManager()
{
}

void CGameManager::Render()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glUseProgram(program);

	// Create Camera One
	view = gameCamera->CameraView();

	GLuint viewLoc = glGetUniformLocation(program, "view");
	glUniformMatrix4fv(viewLoc, 1, GL_FALSE, value_ptr(view));

	GLint currentTimeLoc = glGetUniformLocation(program, "currentTime");
	glUniform1f(currentTimeLoc, currentTime);

	// Renders based on current scene
	if (Utils::currentScene == EMainMenuScene)
	{
		gameMainMenuScene->Render();
	}
	else if (Utils::currentScene == EGameScene)
	{
		gameScene->Render();
	}

	glBindVertexArray(0);		// Unbinding VAO
	glUseProgram(0);

	glutSwapBuffers();
}

void CGameManager::Update()
{
	// Update information
	currentTime = glutGet(GLUT_ELAPSED_TIME);	// Get current time
	currentTime = currentTime * 0.001f;			// Converting to time seconds (From miliseconds)
	deltaTime = currentTime - previousTime;
	previousTime = currentTime;

	// Updates based on current scene
	if (Utils::currentScene == EMainMenuScene)
	{
		gameMainMenuScene->Update(&deltaTime);
	}
	else if (Utils::currentScene == EGameScene)
	{
		gameScene->Update(&deltaTime);
	}

	glutPostRedisplay();
}

void CGameManager::KeyBoardDown(unsigned char key, int x, int y)
{
	gameInputs->KeyboardDown(key, x, y);
}

void CGameManager::KeyBoardUp(unsigned char key, int x, int y)
{
	gameInputs->KeyboardUp(key, x, y);
}

void CGameManager::MousePassiveMove(int x, int y)
{
	gameInputs->MousePassiveMove(x, y);
}

void CGameManager::MouseClick(int button, int state, int x, int y)
{
	gameInputs->MouseClick(button, state, x, y);
}

void CGameManager::MouseMove(int x, int y)
{
	gameInputs->MouseMove(x, y);
}

void KeyboardDownRedirect(unsigned char key, int x, int y)
{
	globalPointerGM->KeyBoardDown(key, x, y);
}

void KeyboardUpRedirect(unsigned char key, int x, int y)
{
	globalPointerGM->KeyBoardUp(key, x, y);
}

void MousePassiveMoveRedirect(int x, int y)
{
	globalPointerGM->MousePassiveMove(x, y);
}

void MouseClickRedirect(int button, int state, int x, int y)
{
	globalPointerGM->MouseClick(button, state, x, y);
}

void MouseMoveRedirect(int x, int y)
{
	globalPointerGM->MouseMove(x, y);
}

void RenderRedirect()
{
	/// Allows glut to look at func in class
	globalPointerGM->Render();
}

void UpdateRedirect()
{
	/// Allows glut to look at func in class
	globalPointerGM->Update();
}

void CGameManager::ManagerMain()
{
	/// Register callbacks
	glutDisplayFunc(RenderRedirect);
	glutIdleFunc(UpdateRedirect);

	// KeyBoard Inputs
	glutKeyboardFunc(KeyboardDownRedirect);
	glutKeyboardUpFunc(KeyboardUpRedirect);

	// Mouse Inputs
	glutMouseFunc(MouseClickRedirect);
	glutMotionFunc(MouseMoveRedirect);
	glutPassiveMotionFunc(MousePassiveMoveRedirect);

	glutMainLoop();
}