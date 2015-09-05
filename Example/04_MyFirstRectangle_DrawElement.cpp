#include "GL\glew.h"
#include "GL\freeglut.h"
#include <iostream>
#include <fstream>
using namespace std;

static int window_position_x = 50;
static int window_position_y = 40;
static int window_width = 1000;
static int window_height = 618;
// 声明一个 VBO
static GLuint VertexBufferID;
// 声明一个 IBO
static GLuint IndexBufferID;

void MyInitializeOpenGL();
// draw function 
void MyRenderWindow();
void MyResizeWindow(GLsizei width,GLsizei height);
void MyCloseWindow();
// data
void SendDataToOpenGL();

int main(int argc,char*argv[])
{
	// 初始化 glut库
	glutInit(&argc, argv);
	// 初始化显示模式     深度缓冲      颜色缓冲
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	// 强制要一个 0penGL 版本
	glutInitContextVersion(4,2);
	/*指定是否向后兼容 
	 *声明了想要使用的OpenGL渲染环境的类型。对于常规的OpenGL操作，
	 *可以在自己的程序中省略这一调用，然而，如果想要使用向前兼容的OpenGL渲染环境，需要调用这一函数
	 */
	glutInitContextFlags(GLUT_CORE_PROFILE | GLUT_DEBUG);
	// 指定profile是否core的.
	glutInitContextProfile(GLUT_FORWARD_COMPATIBLE);
	glutInitWindowPosition(window_position_x, window_position_y);
	glutInitWindowSize(window_width, window_height);
	glutCreateWindow("MyOpenGLWindow");
	// 初始化 glew 库
	GLenum err=glewInit();
	if (GLEW_OK!=err)
	{
		std::cout << "Error !" << glGetString(err) << std::endl;
	} else {
		if (GL_VERSION_4_2 )
		{
			std::cout << "Dirve is support GL_VERSION_4_2 " << std::endl;
		}
	}
	std::cout << "Using glew is " << glewGetString(GLEW_VERSION) << std::endl;
	std::cout << "Vendor is " << glGetString(GL_VENDOR) << std::endl;
	std::cout << "Renderer is " << glGetString(GL_RENDERER) << std::endl;
	std::cout << "Version is " << glGetString(GL_VERSION) << std::endl;
	std::cout << "GLSL Version is" << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;

	MyInitializeOpenGL();
	glutDisplayFunc(&MyRenderWindow);
	glutReshapeFunc(&MyResizeWindow);
	glutCloseFunc(&MyCloseWindow);

	// 循环
	glutMainLoop();
	return 0;
}

void MyInitializeOpenGL()
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	std::cout << "MyInitializeOpenGL() is successful !" << std::endl;
	SendDataToOpenGL();
}
// draw function 
void MyRenderWindow()
{
	// 清除      颜色缓冲                深度缓冲
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//glDrawArrays(GL_TRIANGLES, 0, 3);
	glDrawElements(GL_POINT_BIT, 6, GL_UNSIGNED_INT, nullptr);
	//glDrawElements(GL_LINE_BIT, 6, GL_UNSIGNED_INT, nullptr);
	//glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
	glutSwapBuffers();
}

void MyResizeWindow(GLsizei width, GLsizei height)
{
	glViewport(0, 0, width, height);
	std::cout << "MyResizeWindow() is successful !" << std::endl;
	//std::cout << "MyOpenGLWindow width is " << width <<" "<< "MyOpenGLWindow height is " << height << std::endl; 
}

void MyCloseWindow()
{
	std::cout << "MyCloseWindow() is successful !" << std::endl;
}

// data
void SendDataToOpenGL()
{
	GLfloat VertexArray[] =
	{
		// X     Y      Z
		-0.5f, +0.5f, +0.0f,
		-0.5f, -0.5f, +0.0f,
		+0.5f, -0.5f, +0.0f,
		+0.5f, +0.5f, +0.0f
	};

	GLuint IndexAyyay[] =
	{
		0, 1, 2,
		0, 2, 3
	};
	glGenBuffers(1, &VertexBufferID);
	glBindBuffer(GL_ARRAY_BUFFER, VertexBufferID);
	glBufferData(GL_ARRAY_BUFFER, sizeof(VertexArray), VertexArray, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 3, 0);

	glGenBuffers(1, &IndexBufferID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IndexBufferID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(IndexAyyay), IndexAyyay, GL_STATIC_DRAW);

	glEnableVertexAttribArray(1);
	/* 打开属性数组       
	* 1 表示对应的属性数组    
	* 3 表示每次读几个点   
	* GL_FLOAT 表示的是数据类型
	* GL_FALSE 表示是否正规化
	* sizeof(GLfloat) * 3 每次读的点的大小 (步长)
	* (char*)(sizeof(GLfloat) * 3 下次读取的起点 */
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 3, (char*)(sizeof(GLfloat) * 3));


}