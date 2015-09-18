#include "GL\glew.h"
#include "GL\freeglut.h"
#include <iostream>
#include <string>
#include <fstream>
#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include "Vertex.h"
#include "ShapeData.h"
#include "ShapeGenerator.h"

using namespace std;
static int window_position_x = 100;
static int window_position_y = 20;
static GLsizei window_width  = 400/*1100*/;
static GLsizei window_height = 400/*679.8*/;

void MyIniitOpenGL();
void MyReenderOpenGL();
void MyCloseWindow();
void MyResizeWindow(GLsizei width,GLsizei height);

static GLuint VertexBufferID;	// VBO
static GLuint IndexBufferID;	// IBO
static GLuint VertexShaderID;	// VertexShader
static GLuint FragmentShaderID; // FragmentShader
static GLuint ProgramID;        // ProgramID
static GLuint TextureID;        // TextureID
GLuint ShapeIndicesTotal;       // ShapeDrawIndices


void SendDataToOpenGL();
void InitializeShader();
void InitializeTexture();
std::string ReadShaderCode(const std::string path);


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
	glewExperimental = GL_TRUE;
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
	InitializeTexture();
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
	glEnable(GL_DEPTH_TEST);
	// ��ȡUniform ����
	mat4 modelTransformMatrix = glm::translate(mat4(), vec3( 0.0f, 0.0f, -1.5f ));
	mat4 projectionMatrix = glm::perspective(60.0f, 
		(GLfloat)(window_width / window_height), 0.1f, 2.0f);

	GLint modelTransformMatrixUniformLocation =
		glGetUniformLocation(ProgramID, "modelTransformMatrix");
	GLint projectionMatrixUniformLocation = 
		glGetUniformLocation(ProgramID, "projectionMatrix");

	glUniformMatrix4fv(modelTransformMatrixUniformLocation, 1,
		GL_FALSE, &modelTransformMatrix[0][0]);
	glUniformMatrix4fv(projectionMatrixUniformLocation, 1,
		GL_FALSE, &projectionMatrix[0][0]);

	glDrawElements(GL_TRIANGLES, ShapeIndicesTotal, GL_UNSIGNED_INT, nullptr);
	glDisable(GL_DEPTH_TEST);
	glutSwapBuffers();

	//dominatingColor.r = 0.0f;
	//dominatingColor.b = 1.0f;
	//glUniform3fv(dominatingColorUnifromLocation,
	//	1, &dominatingColor[0]);
	//glUniform1f(yFilpUnifromLocation, 1.0f);
	//glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, nullptr);
	//glutSwapBuffers();
}
void MyCloseWindow()
{
	std::cout << "MyCloseWindow() is successful !" << std::endl;
}

void MyResizeWindow(GLsizei width, GLsizei height)
{
	// �ǵ������Ȳ�����λ�룿����������
	glClear(GL_DEPTH_BUFFER_BIT);
	glViewport(0, 0, width, height);
	std::cout << "MyResizeWindow() is successful !" << std::endl;

}


void SendDataToOpenGL()
{
	//std::cout << "SendDataToOpenGL() is successful !" << std::endl;
	//Vertex VertexArray[] =
	//{  
	//	//          X     Y      Z                      R      G      B
	//	glm::vec3(+0.0f, +1.0f, -1.0f),    glm::vec3( +0.0f, +0.0f, +1.0f),   // 0
	//	glm::vec3(-1.0f, -1.0f, +0.5f),    glm::vec3( +1.0f, +0.0f, +0.0f),   // 1
	//	glm::vec3(+1.0f, -1.0f, +0.5f),    glm::vec3( +1.0f, +0.0f, +0.0f),   // 2
	//	glm::vec3(+0.0f, -1.0f, -1.0f),    glm::vec3( +0.0f, +0.0f, +1.0f),   // 3
	//	glm::vec3(+0.0f, +1.0f, -0.5f),    glm::vec3( +0.0f, +0.0f, +1.0f),   // 4
	//	glm::vec3(-1.0f, +1.0f, -0.5f),    glm::vec3( +0.0f, +0.0f, +1.0f)    // 5
	//};
	//
	//GLuint IndexArray[] = 
	//{
	//	0, 1, 2,  //frist triangle
	//	3, 4, 5   //second triangle
	//};

	ShapeData myShape = ShapeGenerator::makeCube();

	glGenBuffers(1, &VertexBufferID);
	glBindBuffer(GL_ARRAY_BUFFER, VertexBufferID);
	glBufferData(GL_ARRAY_BUFFER, myShape.VertexBufferSize(), myShape.vertices, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 6, 0);

	glGenBuffers(1, &IndexBufferID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IndexBufferID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, myShape.IndicesBufferSize(), myShape.indices, GL_STATIC_DRAW);

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 6, (char*)(sizeof(GLfloat) * 3));
	// ������� new �����ٵ��ڴ�� �ͷ��ڴ�
	ShapeIndicesTotal = myShape.NumberIndices;
	myShape.cleanup();
}

void InitializeShader()
{
	//TODO
	// ������ɫ��
	VertexShaderID=glCreateShader(GL_VERTEX_SHADER);
	FragmentShaderID=glCreateShader(GL_FRAGMENT_SHADER);
	// Ϊ��ɫ����Ӵ���
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

void InitializeTexture()
{
	// TODO
	// ����һ������ ID
	//glGenTextures(1, &TextureID);
	//// �󶨵�ǰ������ ID
	//glBindTexture(GL_TEXTURE_2D_ARRAY, TextureID);
	//// 
	//glTexImage2D(GL_TEXTURE_2D_ARRAY, 0, GL_RGBA, window_width / 2, window_height / 2, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL);
	////
	////glGenerateTextureMipmap(GL_TEXTURE_2D_ARRAY);

}
std::string ReadShaderCode(std::string path)
{
	ifstream input(path);
	if (!input.good())
	{
		std::cerr << "file not found !" << std::endl;
		return nullptr;
		exit(1);
	}
	else {
		return std::string(
			std::istreambuf_iterator<char>(input),
			std::istreambuf_iterator<char>()
			);
	}
}



