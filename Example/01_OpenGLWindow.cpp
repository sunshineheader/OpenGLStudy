#include"GL\glew.h"
#include "GL\freeglut.h"
#include <iostream>
#include <fstream>
#include <string>
//#pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"" )
using namespace std;

// 初始化位置
static GLint window_position_x = 50;
static GLint window_position_y = 40;
// 初始化尺寸
static GLint window_width = 1000;
static GLint window_height = 618;

void OnInit();
void OnRender();


int main(int argc,char * argv[])
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE |GLUT_RGBA |GLUT_DEPTH | GLUT_STENCIL);
	glutInitContextVersion(4,2);
	glutInitContextFlags(GLUT_CORE_PROFILE | GLUT_DEBUG);
	glutInitContextProfile(GLUT_FORWARD_COMPATIBLE);
	glutInitWindowPosition(window_position_x, window_position_y);
	glutInitWindowSize(window_width,window_height);
	glutCreateWindow("MyOpenGLWindow");

	GLenum error = glewInit();
	if (GLEW_OK != error)
	{
		std::cerr << "error ..." << glewGetErrorString(error) << std::endl;
		//exit(1);
	}else {
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

	OnInit();
	glutDisplayFunc(OnRender);

	glutMainLoop();
	return 0;

}
void OnInit()
{
	//用来清除窗口颜色
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	cout << "Initialization it sucessfully !" << endl;
}
void OnRender()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

	glutSwapBuffers();
}
