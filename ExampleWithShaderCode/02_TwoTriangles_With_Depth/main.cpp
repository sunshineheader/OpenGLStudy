#include "GL\glew.h"
#include "GL\freeglut.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

static int window_position_x = 100;
static int window_position_y = 20;
static GLsizei window_width  = 1100;
static GLsizei window_height = 679.8;

void MyIniitOpenGL();
void MyReenderOpenGL();
void MyCloseWindow();
void MyResizeWindow(GLsizei width,GLsizei height);

static GLuint VertexBufferID;	// VBO
static GLuint IndexBufferID;	// IBO
static GLuint VertexShaderID;	// VertexShader
static GLuint FragmentShaderID; // FragmentShader
static GLuint ProgramID;        // ProgramID

void SendDataToOpenGL();
void InitializeShader();
std::string ReadShaderCode(std::string path);


int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH | GLUT_STENCIL);
	glutInitContextVersion(4, 2);
	glutInitContextFlags(GLUT_CORE_PROFILE|GLUT_DEBUG);
	glutInitContextProfile(GLUT_FORWARD_COMPATIBLE);
	glutInitWindowPosition(window_position_x, window_position_y);
	glutInitWindowSize(window_width, window_height);
	glutCreateWindow("MyOpenGLWindow");
	// initialize glew 
	//glewExperimental = GL_TRUE;
	GLenum state = glewInit();
	if (GLEW_OK != state)
	{
		std::cout << "Error !" << glGetString(state) << std::endl;
	} else {
		if (GL_VERSION_4_2)
		{
			std::cout << "Drive is support GL_VERSION_4_2 !" << std::endl;
		}
	}
	cout << "Using glew is " << glewGetString(GLEW_VERSION) << endl;
	cout << "Vendor is " << glGetString(GL_VENDOR) << endl;
	cout << "Renderer is " << glGetString(GL_RENDERER) << endl;
	cout << "Version is " << glGetString(GL_VERSION) << endl;
	cout << "GLSL Version is " << glGetString(GL_SHADING_LANGUAGE_VERSION) << endl;

	MyIniitOpenGL();
	glutDisplayFunc(&MyReenderOpenGL);
	glutCloseFunc(&MyCloseWindow);
	glutReshapeFunc(&MyResizeWindow);
	glutMainLoop();
	return 0;

}

void MyIniitOpenGL()
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	std::cout << "initialze MyinitialzeOpenGL() function successful ..." << std::endl;
	SendDataToOpenGL();
	InitializeShader();
}

// draw function 
void MyReenderOpenGL()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT | GL_DOUBLEBUFFER);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
	glutSwapBuffers();
}
void MyCloseWindow()
{
	std::cout << "MyCloseWindow() is successful !" << std::endl;
}

void MyResizeWindow(GLsizei width, GLsizei height)
{
	glViewport(0, 0, width, height);
	std::cout << "MyResizeWindow() is successful !" << std::endl;
}

void SendDataToOpenGL()
{
	//std::cout << "SendDataToOpenGL() is successful !" << std::endl;
	GLfloat VertexArray[] =
	{
		// X     Y      Z          R      G      B
		+0.0f, +1.0f, +0.0f,     +0.0f, +1.0f, +0.0f,   // 0
		-1.0f, -1.0f, +0.0f,     +0.0f, +0.0f, +0.0f,   // 1
		+1.0f, -1.0f, +0.0f,     +0.0f, +1.0f, +0.0f,   // 2
		+0.0f, -1.0f, +0.0f,     +0.0f, +1.0f, +0.0f,   // 3
		+1.0f, +1.0f, +0.0f,     +1.0f, +1.0f, +0.0f,   // 4
		-1.0f, +1.0f, +0.0f,     +1.0f, +0.0f, +0.0f    // 5
	};
	GLuint IndexArray[] = 
	{
		0, 1, 2,  //frist triangle
		3, 4, 5   //second triangle
	};
	glGenBuffers(1, &VertexBufferID);
	glBindBuffer(GL_ARRAY_BUFFER, VertexBufferID);
	glBufferData(GL_ARRAY_BUFFER, sizeof(VertexArray), VertexArray, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 6, 0);

	glGenBuffers(1, &IndexBufferID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IndexBufferID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(IndexArray), IndexArray, GL_STATIC_DRAW);

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 6, (char*)(sizeof(GLfloat) * 3));
	/* ����������
	* 1 ��ʾ��Ӧ����������
	* 3 ��ʾÿ�ζ�������
	* GL_FLOAT ��ʾ������������
	* GL_FALSE ��ʾ�Ƿ����滯
	* sizeof(GLfloat) * 3 ÿ�ζ��ĵ�Ĵ�С (����)
	* (char*)(sizeof(GLfloat) * 3 �´ζ�ȡ����� 
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 6, (char*)(sizeof(GLfloat) * 6))
	*/
}

void InitializeShader()
{
	//TODO
	// ������ɫ��
	VertexShaderID=glCreateShader(GL_VERTEX_SHADER);
	FragmentShaderID=glCreateShader(GL_FRAGMENT_SHADER);
	// Ϊ��ɫ�����Ӵ���
	// VertexShader
	const GLchar * ShaderCodeCstr[1];
	string VertexShaderCode = ReadShaderCode("VertexShader.glsl");
	ShaderCodeCstr[0] = VertexShaderCode.c_str();
	glShaderSource(VertexShaderID, 1, ShaderCodeCstr, 0);
	// FragmentShader
	string FragmentShaderCode = ReadShaderCode("FragmentShader.glsl");
	ShaderCodeCstr[0] = FragmentShaderCode.c_str();
	glShaderSource(FragmentShaderID, 1, ShaderCodeCstr, 0);
	// ������ɫ�� compile shader
	glCompileShader(VertexShaderID);
	glCompileShader(FragmentShaderID);
	// �����ɫ����״̬ compile error
	// VertexShader Compile Error !
	GLint Successful;
	glGetShaderiv(VertexShaderID, GL_COMPILE_STATUS, &Successful);
	if (!Successful)
	{
		GLchar Buffer[1024];
		GLsizei BufferSize;
		glGetShaderInfoLog(VertexShaderID, GL_INFO_LOG_LENGTH, &BufferSize, Buffer);
		std::cerr << "VertexShader Compile Error ! \n" <<Buffer<< std::endl;
	}
	else
	{
		GLchar Buffer[1024];
		GLsizei BufferSize;
		glGetShaderInfoLog(VertexShaderID, GL_INFO_LOG_LENGTH, &BufferSize, Buffer);
		std::cout << "VertexShader Compile Successfully ! \n" << Buffer << std::endl;
	}
	// FragmentShader Compile Error !
	glGetShaderiv(FragmentShaderID, GL_COMPILE_STATUS, &Successful);
	if (!Successful)
	{
		GLchar Buffer[1024];
		GLsizei BufferSize;
		glGetShaderInfoLog(FragmentShaderID, GL_INFO_LOG_LENGTH, &BufferSize, Buffer);
		std::cerr << "FragmentShader Compile Error ! \n" << Buffer << std::endl;
	}
	else
	{
		GLchar Buffer[1024];
		GLsizei BufferSize;
		glGetShaderInfoLog(FragmentShaderID, GL_INFO_LOG_LENGTH, &BufferSize, Buffer);
		std::cout << "FragmentShader Compile Successfully ! \n" << Buffer << std::endl;
	}
	// �ܶ���������createProgram �ͼ�ⲻ�� link shader �Ĵ��� 
	ProgramID = glCreateProgram();
	// ������ɫ�� attach shader
	glAttachShader(ProgramID, VertexShaderID);
	glAttachShader(ProgramID, FragmentShaderID);
	// ������ɫ�� link shader link program
	glLinkProgram(ProgramID);
	// �����ɫ�������Ӵ��� link error
	glGetProgramiv(ProgramID, GL_LINK_STATUS, &Successful);
	if (!Successful)
	{
		GLchar buffer[1024];
		GLsizei buffersize;
		glGetProgramInfoLog(ProgramID, GL_INFO_LOG_LENGTH, &buffersize, buffer);
		std::cout << "link program error ! \n" << buffer << std::endl;
	}
	else
	{
		GLchar buffer[1024];
		GLsizei buffersize;
		glGetProgramInfoLog(ProgramID, GL_INFO_LOG_LENGTH, &buffersize, buffer);
		std::cout << "link program successful ! \n" << buffer << std::endl;

	}
	// ʹ�ó���  use prgram
	glUseProgram(ProgramID);
}

std::string ReadShaderCode(std::string path)
{
	ifstream input(path);
	if (!input.good())
	{
		std::cerr << "file not found !" << std::endl;
		return nullptr;
		exit(1);
	} else {
		return std::string(
			std::istreambuf_iterator<char>(input),
			std::istreambuf_iterator<char>()
			);
	}
}