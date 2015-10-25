#include"GL\glew.h"
#include "GL\freeglut.h"
#include <iostream>
#include <glm\glm.hpp>
#include "ShaderManager.h">
//#pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"" )
using namespace std;

static GLuint VertexBufferID;
static GLuint IndexBufferID;
static GLuint VertexShaderID;	// VertexShader
static GLuint FragmentShaderID; // FragmentShader
static GLuint ProgramID;        // ProgramID
static GLuint glScaleLocation;


static GLfloat VertexData[]
{
	    +0.5f, -0.5f, +0.0f,
		+1.0f, +0.0f, +0.0f,
		+0.0f, +0.5f, +0.0f,
		+0.0f, +1.0f, +0.0f,
		-0.5f, -0.5f, +0.0f,
		+0.0f, +0.0f, +1.0f,
};
static GLuint IndexData[]
{
	0, 1, 2

};

static void CreateVertexBufferData()
{
	glGenBuffers(1, &VertexBufferID);
	glBindBuffer(GL_ARRAY_BUFFER, VertexBufferID);
	glBufferData(GL_ARRAY_BUFFER, sizeof(VertexData), VertexData, GL_STATIC_DRAW);
	glGenBuffers(1, &IndexBufferID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IndexBufferID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(IndexData), IndexData, GL_STATIC_DRAW);
}

void CreateShaderAndComplie()
{
	//TODO
	// 创建着色器
	VertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	FragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
	// 为着色器添加代码
	// VertexShader
	string VertexShaderCode = ShaderManager::ReadShaderCode("VertexShader.glsl");
	const GLchar * ShaderCodeCstr = VertexShaderCode.c_str();
	glShaderSource(VertexShaderID, 1, &ShaderCodeCstr, 0);
	// FragmentShader
	string FragmentShaderCode = ShaderManager::ReadShaderCode("FragmentShader.glsl");
	ShaderCodeCstr = FragmentShaderCode.c_str();
	glShaderSource(FragmentShaderID, 1, &ShaderCodeCstr, 0);
	// 编译着色器 compile shader
	glCompileShader(VertexShaderID);
	glCompileShader(FragmentShaderID);
	// 检查着色器的状态 compile error
	// VertexShader Compile Error !
	ShaderManager::CheckShanderCompileStatus(VertexShaderID);
	ShaderManager::CheckShanderCompileStatus(FragmentShaderID);
	// 很多人忘记了createProgram 就检测不出 link shader 的错误 
	ProgramID = glCreateProgram();
	// 附加着色器 attach shader
	glAttachShader(ProgramID, VertexShaderID);
	glAttachShader(ProgramID, FragmentShaderID);
	// 链接着色器 link shader link program
	glLinkProgram(ProgramID);
	// 检查着色器的连接错误 link error
	ShaderManager::CheckShaderLinkProgramStatus(ProgramID);
	glValidateProgram(ProgramID);
	// 使用程序  use prgram
	glUseProgram(ProgramID);
	glScaleLocation = glGetUniformLocation(ProgramID, "gScale");
	assert(glScaleLocation != 0xFFFFFFFF);
}


// init data
void MyOpenGLWindowInit()
{
	//用来清除窗口颜色
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	cout << "Initialization it sucessfully !" << endl;
}
// draw  function
void MyOpenGLWindowDisplay()
{
	static GLfloat Scale = 0.000;
	Scale += 0.01;
	glUniform1f(glScaleLocation, std::sinf(Scale));
	//用来清除缓冲区
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 6, 0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 6, (char*)(sizeof(GLfloat) * 3));
	glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, nullptr);
	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	glutSwapBuffers();
}

// 注册回调函数
void MyOpenGLCallBackIniit()
{
	glutDisplayFunc(&MyOpenGLWindowDisplay);
	glutIdleFunc(&MyOpenGLWindowDisplay);
}
int main(int argc, char * argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH | GLUT_STENCIL);
	glutInitContextVersion(4, 2);
	glutInitContextFlags(GLUT_CORE_PROFILE | GLUT_DEBUG);
	glutInitContextProfile(GLUT_FORWARD_COMPATIBLE);
	glutInitWindowPosition(100, 10);
	glutInitWindowSize(1000, 618);
	glutCreateWindow("MyOpenGLWindow");

	GLenum error = glewInit();
	if (GLEW_OK != error)
	{
		std::cerr << "error ..." << glewGetErrorString(error) << std::endl;
		//exit(1);
	}
	else {
		if (GL_VERSION_4_2)
		{
			std::cout << "Dirve support opnegl 4.2" << std::endl;
		}
	}
	cout << "Using glew is " << glewGetString(GLEW_VERSION) << endl;
	cout << "Vendor is " << glGetString(GL_VENDOR) << endl;
	cout << "Renderer is " << glGetString(GL_RENDERER) << endl;
	cout << "Version is " << glGetString(GL_VERSION) << endl;
	cout << "GLSL Version is" << glGetString(GL_SHADING_LANGUAGE_VERSION) << endl;

	MyOpenGLWindowInit();
	CreateVertexBufferData();
	CreateShaderAndComplie();
	MyOpenGLCallBackIniit();
	glutMainLoop();
	return 0;

}
