#pragma once

namespace Utils
{
	// Screen Size
	const unsigned int SCR_WIDTH = 1200;
	const unsigned int SCR_HEIGHT = 600;

	ESceneManager currentScene;
}

// KeyBoard States
enum InputState
{
	INPUT_UP,
	INPUT_DOWN,
	INPUT_UP_FIRST,
	INPUT_DOWN_FIRST,
};

enum ESceneManager
{
	EMainMenuScene,
	EGameScene,
};
