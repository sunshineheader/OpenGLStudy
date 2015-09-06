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

GLuint VertexBufferID; // VBO
GLuint IndexBufferID;  // IBO
static void SendDataToOpenGL();


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
}

// draw function 
void MyReenderOpenGL()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT | GL_DOUBLEBUFFER);
	glDrawElements(GL_LINE_BIT, 6, GL_UNSIGNED_INT, nullptr);
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
		+0.0f, +1.0f, +0.0f,     +0.0f, +0.0f, +0.0f,   // 0
		-1.0f, -1.0f, +0.0f,     +0.0f, +0.0f, +0.0f,   // 1
		+1.0f, -1.0f, +0.0f,     +0.0f, +0.0f, +0.0f,   // 2
		+0.0f, -1.0f, +0.0f,     +0.0f, +0.0f, +0.0f,   // 3
		+1.0f, +1.0f, +0.0f,     +0.0f, +0.0f, +0.0f,   // 4
		-1.0f, +1.0f, +0.0f,     +0.0f, +0.0f, +0.0f    // 5
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
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 6, (char*)(sizeof(GLfloat) * 6));
	/* 打开属性数组
	* 1 表示对应的属性数组
	* 3 表示每次读几个点
	* GL_FLOAT 表示的是数据类型
	* GL_FALSE 表示是否正规化
	* sizeof(GLfloat) * 3 每次读的点的大小 (步长)
	* (char*)(sizeof(GLfloat) * 3 下次读取的起点 
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 6, (char*)(sizeof(GLfloat) * 6))
	*/

}