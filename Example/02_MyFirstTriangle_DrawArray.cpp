#include "GL\glew.h"
#include "GL\freeglut.h"
#include<iostream>
using namespace std;

// ����һ�� VBO
GLuint VertexBifferId;

// �������� ���������ε� position
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

// ����OpenGL���ӿ� ViewPort
void MyResizeWindow(GLsizei width, GLsizei height);

int main(int argc,char* argv[])
{
	//��ʼ��glut��
	glutInit(&argc,argv);
	//��ʼ����ʾģʽ��    ˫����ģʽ�� RGBA��ɫģʽ����Ȼ���λ�� ���õ�ģ�建��
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH | GLUT_STENCIL);
	//ǿ��ѡ��һ��OpenGL�汾
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

	// ѭ��
	glutMainLoop();
	return 0;
}
// 
void MyInit()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	cout << "Initialization it sucessfully !" << endl;
	// ����һ�� VBO
	glGenBuffers(1, &VertexBifferId);
	// �� VBO
	glBindBuffer(GL_ARRAY_BUFFER, VertexBifferId);
	// ���� ����Դ Data
	glBufferData(GL_ARRAY_BUFFER, sizeof(VertexArray), VertexArray, GL_STATIC_DRAW);
	// ������������
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
}
// Draw function
void MyRender()
{
	// ���     ��ɫ����              ��Ȼ���               ģ�建��
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

	glDrawArrays(GL_TRIANGLES,0,3);
	// ���� buffer
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