#include "GL\glew.h"
#include "GL\freeglut.h"
#include<iostream>
using namespace std;

// 声明一个 VBO
GLuint VertexBifferId;

// 顶点数组 保存三角形的 position
static GLfloat VertexArray[] =
{
	// X     Y      Z
	+0.0f, +0.5f, +0.0f,
	-0.5f, -0.5f, +0.0f,
	+0.5f, -0.5f, +0.0f
};

void MyInit();

// Draw
void MyRender();

void MyCloseWindow();

// 重置OpenGL的视口 ViewPort
void MyResizeWindow(GLsizei width, GLsizei height);

int main(int argc,char* argv[])
{
	//初始化glut库
	glutInit(&argc,argv);
	//初始化显示模式，    双缓冲模式， RGBA颜色模式，深度缓冲位， 可用的模板缓冲
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH | GLUT_STENCIL);
	//强制选择一个OpenGL版本
	glutInitContextVersion(4, 2);
	glutInitContextFlags(GLUT_CORE_PROFILE | GLUT_DEBUG);
	glutInitContextProfile(GLUT_FORWARD_COMPATIBLE);
	glutInitWindowPosition(50,10);
	glutInitWindowSize(1000,618);
	glutCreateWindow("MyOpenGLWindow");

	glewExperimental = GL_TRUE;
	GLenum error=glewInit();
	if (GLEW_OK!=error)
	{
		std::cerr << "Error" << glGetString(error) << std::endl;

	} else {
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
	MyInit();
	glutCloseFunc(&MyCloseWindow);
	glutDisplayFunc(&MyRender);
	glutReshapeFunc(&MyResizeWindow);

	// 循环
	glutMainLoop();
	return 0;
}
// 
void MyInit()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	cout << "Initialization it sucessfully !" << endl;
	// 产生一个 VBO
	glGenBuffers(1, &VertexBifferId);
	// 绑定 VBO
	glBindBuffer(GL_ARRAY_BUFFER, VertexBifferId);
	// 描述 数据源 Data
	glBufferData(GL_ARRAY_BUFFER, sizeof(VertexArray), VertexArray, GL_STATIC_DRAW);
	// 开启属性数组
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
}
// Draw function
void MyRender()
{
	// 清除     颜色缓冲              深度缓冲               模板缓冲
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

	glDrawArrays(GL_TRIANGLES,0,3);
	// 交换 buffer
	glutSwapBuffers();
}
void MyCloseWindow()
{

	std::cout << "Window close successful " << std::endl;

}

void MyResizeWindow(GLsizei width,GLsizei height)
{

	glViewport(0,0,width,height);

}