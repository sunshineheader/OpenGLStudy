#include "ShaderManager.h"
ShaderManager::ShaderManager()
{
}


ShaderManager::~ShaderManager()
{
}

// 检查 shader compile 的状态
bool ShaderManager::CheckShanderCompileStatus(GLuint ShaderID)
{
	GLint Successful;
	glGetShaderiv(ShaderID, GL_COMPILE_STATUS, &Successful);
	if (!Successful)
	{
		GLchar Buffer[1024];
		GLsizei BufferSize;
		glGetShaderInfoLog(ShaderID, GL_INFO_LOG_LENGTH, &BufferSize, Buffer);
		std::cerr << "Shader Compile Error ! \n" << Buffer << std::endl;
		return false;
	}
	std::cout << "Shader Compile Successful ! \n" << std::endl;
	return true;
}

// 检查 shader link 的 状态
bool ShaderManager::CheckShaderLinkProgramStatus(GLuint programID)
{
	GLint Successful;
	glGetProgramiv(programID, GL_LINK_STATUS, &Successful);
	if (!Successful)
	{
		GLchar buffer[1024];
		GLsizei buffersize;
		glGetProgramInfoLog(programID, GL_INFO_LOG_LENGTH, &buffersize, buffer);
		std::cout << "Link Program Error ! \n" << buffer << std::endl;
		return false;
	}
	std::cout << "Link Program Successful ! \n" << std::endl;
	return true;
}

std::string ShaderManager::ReadShaderCode(std::string  path)
{
	std::fstream input(path);
	if (!input.good())
	{
		std::cerr << "shader file not found" << std::endl;
		exit(1);
		return nullptr;
	}
	return std::string(
		std::istreambuf_iterator<char>(input),
		std::istreambuf_iterator<char>()
		);

}