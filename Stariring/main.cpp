#pragma once

#include <glew.h>
#include <freeglut.h>
#include <SOIL.h>
#include <iostream>

#include <stdio.h>  
#include <stdlib.h> 
#include <time.h> 

#include "glm.hpp"
#include "gtc/matrix_transform.hpp"
#include "gtc/type_ptr.hpp"

#include "CCamera.h"
#include "CGameManager.h"
#include "CInput.h"
#include "CShaderLoader.h"


int main(int argc, char** argv)
{
	srand(time(NULL));

	CGameManager mainGameManager(argc, argv);
	mainGameManager.ManagerMain();

	return(0);
}