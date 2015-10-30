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
	// 检查 shader compile 的状态
	static bool CheckShanderCompileStatus(GLuint shaderID);
	// 检查 shader link 的 状态
	static bool CheckShaderLinkProgramStatus(GLuint programID);
	// 用于读取 GLSL Code
	static std::string ReadShaderCode(const std::string path);
	// 用于取得 ShaderCstr
};

