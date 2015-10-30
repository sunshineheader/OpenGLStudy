#pragma once
#include "GL\glew.h"
#include "GL\freeglut.h"
#include <iostream>
#include <string>
#include <fstream>

class ShaderManager {

public:
	ShaderManager();
	~ShaderManager();

public:
	// ��� shader compile ��״̬
	static bool CheckShanderCompileStatus(GLuint shaderID);
	// ��� shader link �� ״̬
	static bool CheckShaderLinkProgramStatus(GLuint programID);
	// ���ڶ�ȡ GLSL Code
	static std::string ReadShaderCode(const std::string path);
	// ����ȡ�� ShaderCstr
};

