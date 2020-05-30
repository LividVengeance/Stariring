#pragma once

enum ESceneManager
{
	EMainMenuScene,
	ESeekScene,
	EPursueScene,
	EWanderScene,
	EArrivalScene,
};

// KeyBoard States
enum InputState
{
	INPUT_UP,
	INPUT_DOWN,
	INPUT_UP_FIRST,
	INPUT_DOWN_FIRST,
};

namespace Utils
{
	// Screen Size
	const unsigned int SCR_WIDTH = 1200;
	const unsigned int SCR_HEIGHT = 600;
}