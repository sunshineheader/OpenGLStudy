#include "GL\glew.h"
#include "GL\freeglut.h"
#include <iostream>
#include <fstream>
using namespace std;

static int window_position_x = 50;
static int window_position_y = 40;
static int window_width = 1000;
static int window_height = 618;
// ����һ�� VBO
static GLuint VertexBufferID;
// ����һ�� IBO
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
	// ��ʼ�� glut��
	glutInit(&argc, argv);
	// ��ʼ����ʾģʽ     ��Ȼ���      ��ɫ����
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	// ǿ��Ҫһ�� 0penGL �汾
	glutInitContextVersion(4,2);
	/*ָ���Ƿ������� 
	 *��������Ҫʹ�õ�OpenGL��Ⱦ���������͡����ڳ����OpenGL������
	 *�������Լ��ĳ�����ʡ����һ���ã�Ȼ���������Ҫʹ����ǰ���ݵ�OpenGL��Ⱦ��������Ҫ������һ����
	 */
	glutInitContextFlags(GLUT_CORE_PROFILE | GLUT_DEBUG);
	// ָ��profile�Ƿ�core��.
	glutInitContextProfile(GLUT_FORWARD_COMPATIBLE);
	glutInitWindowPosition(window_position_x, window_position_y);
	glutInitWindowSize(window_width, window_height);
	glutCreateWindow("MyOpenGLWindow");
	// ��ʼ�� glew ��
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

	// ѭ��
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
	// ���      ��ɫ����                ��Ȼ���
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
	/* ����������       
	* 1 ��ʾ��Ӧ����������    
	* 3 ��ʾÿ�ζ�������   
	* GL_FLOAT ��ʾ������������
	* GL_FALSE ��ʾ�Ƿ����滯
	* sizeof(GLfloat) * 3 ÿ�ζ��ĵ�Ĵ�С (����)
	* (char*)(sizeof(GLfloat) * 3 �´ζ�ȡ����� */
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 3, (char*)(sizeof(GLfloat) * 3));


}