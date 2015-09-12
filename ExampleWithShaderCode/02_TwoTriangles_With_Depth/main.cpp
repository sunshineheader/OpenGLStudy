#include "GL\glew.h"
#include "GL\freeglut.h"
#include <iostream>
#include <fstream>
#include <string>

//#pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"" )

using namespace std;

const int window_position_x = 100;
const int window_position_y = 50;
const int window_width = 1000;
const int window_height = 618;

//声明一个vertex_buffer_id
GLuint vertex_buffer_id;
//声明一个element_buffer_id
GLuint indices_buffer_id;
//声明一个program_id；
GLuint  program_id;



void OnInit();

void send_data_to_OpenGL();

void initall_shader();

void OnShutdown();

void OnResize(int width, int height);

void OnRender();

std::string read_shader_code(const char* path);

const char*VertexShaderCode =

"#version 330  core	\n"
""
"in layout (location=0) vec3 VertexPosition;  "
"in layout (location=1) vec3 VertexColor;  "
"out vec3 theColor;  "

"void main()"
"{"
"   gl_Position = vec4(VertexPosition,1.0);    "
"   theColor =VertexColor;   "
"}";

const char*FragmentShaderCode =
"#version 330  core	\n"
""
"in vec3 theColor;  "
"out vec4 FragColor;  "
""
"void main() "
"{"
"   FragColor = vec4(theColor,1.0); "
"}";

int main(int argc,char**argv)
{
	//初始化glut库
	glutInit(&argc, argv);
	//初始化显示模式，    双缓冲模式， RGBA颜色模式，深度缓冲位， 可用的模板缓冲
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH | GLUT_STENCIL);
    //选择OpenGL版本
	glutInitContextVersion(4, 2);
	/*指定是否向后兼容
	*声明了想要使用的OpenGL渲染环境的类型。对于常规的OpenGL操作，
	*可以在自己的程序中省略这一调用，然而，如果想要使用向前兼容的OpenGL渲染环境，需要调用这一函数 */
	glutInitContextFlags(GLUT_CORE_PROFILE | GLUT_DEBUG);
	//指定 profile 是否是 core 的
	glutInitContextProfile(GLUT_FORWARD_COMPATIBLE);
	//初始化窗口位置
	glutInitWindowPosition(window_position_x, window_position_y);
	//初始化窗口尺寸大小
	glutInitWindowSize(window_width, window_height);
	//设置窗口标题
	glutCreateWindow("hello my opengl version 4.2");
	glewExperimental = GL_TRUE;
	//初始化glew库
	GLenum err=glewInit();
	if (GLEW_OK != err){
		std::cerr << "Error:" << glewGetErrorString(err) << std::endl;
	}
	else{
	if (GLEW_VERSION_4_2){
			std::cout << "Dirve support opnegl 4.2" << std::endl;
		}
	}
	cout << "Using glew is " << glewGetString(GLEW_VERSION) << endl;
	cout << "Vendor is " << glGetString(GL_VENDOR) << endl;
	cout << "Renderer is " << glGetString(GL_RENDERER) << endl;
	cout << "Version is " << glGetString(GL_VERSION) << endl;
	cout << "GLSL Version is" << glGetString(GL_SHADING_LANGUAGE_VERSION) << endl;
	OnInit();
	glutCloseFunc(&OnShutdown);
	glutDisplayFunc(&OnRender);
	glutReshapeFunc(&OnResize);
	glutMainLoop();
	//system("PAUSE");
	return 0;

}
void OnInit()
{
	//用来清除窗口颜色
	glClearColor(0.0f, 0.0f, 0.0f,0.0f);
	cout << "Initialization it sucessfully !" << endl;
	send_data_to_OpenGL();
	initall_shader();
}

void send_data_to_OpenGL()
{
	//创建一个vertices
	GLfloat vertices[] =
	{   /* 
		//围绕着 （0,0）点画的两个三角形
		// X     Y      Z         R      G      B
		+0.0f, +0.0f, +0.0f,    +1.0f, +0.0f, +0.0f,  // 0
		-1.0f, -1.0f, +0.0,     +1.0f, +1.0f, +0.0f,  // 1
		+1.0f, -1.0f, +0.0f,    +0.0f, +1.0f, +1.0f,  // 2  //+0.0f, +0.0f, +0.0f,
        +1.0f, +1.0f, +0.0f,    +0.0f, +1.0f, +0.0f,  // 3
        -1.0f, +1.0f, +0.0f,	+0.0f, +0.0f, +1.0f   // 4
		*/

		// X     Y      Z          R      G      B
		+0.0f, +1.0f, +0.9f,     +1.0f, +0.0f, +0.0f,   // 0
		-1.0f, -1.0f, -0.9f,     +0.0f, +1.0f, +0.0f,   // 1
		+1.0f, -1.0f, -0.9f,     +0.0f, +0.0f, +1.0f,   // 2
		+0.0f, -1.0f, -1.0f,     +0.0f, +0.0f, +1.0f,   // 3
		+1.0f, +1.0f, +1.0f,     +0.0f, +1.0f, +0.0f,   // 4
		-1.0f, +1.0f, +1.0f,     +1.0f, +0.0f, +0.0f    // 5
							    
	};
	//创建一个indices
	GLuint indices[] =
	{   /*
		//围绕着 （0,0）点画的两个三角形
		0, 1, 2, //first triangle
		0, 3, 4  // second triangle
		*/		
		0, 1, 2,  //frist triangle
		3, 4, 5   //second triangle
	};
	//分配一个ID
	glGenBuffers(1, &vertex_buffer_id);
	//绑定一个Buffer
	glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer_id);
	//数据源
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	//开启第0个属性数组 position
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 6, 0);
	//开启第一个属性数组
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 6, (char*)(sizeof(GLfloat) * 3));
	//数组索引 element
	glGenBuffers(1, &indices_buffer_id);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indices_buffer_id);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

}
void OnShutdown()
{
	cout << "Shutdown sucessful !" << endl;
}

void OnResize(int width,int height)
{
	glViewport(0, 0, (GLsizei)width, (GLsizei)height);
}
void OnRender()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT | GL_DOUBLEBUFFER);
	//glDrawArrays(GL_TRIANGLES,0,6);
	glDrawElements(GL_TRIANGLES,6,GL_UNSIGNED_INT,nullptr);
	//glFlush();
	glutSwapBuffers();
}

void initall_shader()
{
	//create shader 
	GLuint vertexShader=glCreateShader(GL_VERTEX_SHADER);
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

	//code for shader,vertexshader fragmentshader
	const GLchar*vertexshadercode[1];
	std::string vertexstringcode = read_shader_code("VertexShader.glsl");
	vertexshadercode[0] = vertexstringcode.c_str();
	glShaderSource(vertexShader, 1, vertexshadercode, 0);

	//const GLchar*fragmentshadercode[1];
	vertexstringcode = read_shader_code("FragmentShader.glsl");
	vertexshadercode[0] = vertexstringcode.c_str();
	glShaderSource(fragmentShader, 1, vertexshadercode, 0);

	//compileshader
	glCompileShader(vertexShader);
	glCompileShader(fragmentShader);

	GLint successful;
	//compile error
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &successful);
	if (!successful)
	{
		GLchar buffer[1024];
		GLsizei buffersize;
		glGetShaderInfoLog(vertexShader, GL_INFO_LOG_LENGTH, &buffersize, buffer);
		std::cout << "comoile vertex shader error ! \n" << buffer << endl;
	}
	else
	{
		GLchar buffer[1024];
		GLsizei buffersize;
		glGetShaderInfoLog(vertexShader, GL_INFO_LOG_LENGTH,&buffersize, buffer);
		std::cout << "compile vertrx shader successful ! \n" << buffer << std::endl;
	}

	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &successful);
	if (!successful)
	{
		GLchar buffer[1024];
		GLsizei buffersize;
		glGetShaderInfoLog(fragmentShader, GL_INFO_LOG_LENGTH, &buffersize, buffer);
		std::cout << "compile fragment shader error !" <<buffer <<endl;
	}
	else
	{
		GLchar buffer[1024];
		GLsizei buffersize;
		glGetShaderInfoLog(fragmentShader, GL_INFO_LOG_LENGTH, &buffersize, buffer);
		std::cout << "compile fragment shader successful !" << buffer << endl;
	}

	//attachshader create progran id
	 program_id = glCreateProgram();
	 glAttachShader(program_id, vertexShader);
	 glAttachShader(program_id, fragmentShader);

	 //link program
	 glLinkProgram(program_id);

     //check link
	 glGetProgramiv(program_id, GL_LINK_STATUS, &successful);
	 if (!successful)
	 {
		 GLchar buffer[1024];
		 GLsizei buffersize;
		 glGetProgramInfoLog(program_id, GL_INFO_LOG_LENGTH, &buffersize, buffer);
		 std::cout << "link program error" << buffer << std::endl;
	 }
	 else
	 {
		 GLchar buffer[1024];
		 GLsizei buffersize;
		 glGetProgramInfoLog(program_id, GL_INFO_LOG_LENGTH, &buffersize, buffer);
		 std::cout << "link program successful ! " << buffer << std::endl;

	 }
	 //use prgram
	 glUseProgram(program_id);
}

std::string read_shader_code(const char* path) 
{
	std::ifstream input(path);
	//input.open()
	if (!input.good())
	{
		std::cout << "file not found !" << std::endl;
		//system("PAUSE");
		exit(1);
	}else{

		return std::string(
			std::istreambuf_iterator<char>(input),
			std::istreambuf_iterator<char>()
			);
	}

}


/*
void create_shaders()
{
	//create shader
	 vertex_shader_id = glCreateShader(GL_VERTEX_SHADER);
	 fragment_shader_id = glCreateShader(GL_FRAGMENT_SHADER);

	 //vertex shader code
	 const GLchar*char_shader_code[1];
	 std::string string_shader_code = read_shader_code("ShaderCode/VertexShader.glsl");
	 char_shader_code[0] = string_shader_code.c_str();
	 glShaderSource(vertex_shader_id, 1, char_shader_code, nullptr);
	 //fragment shader code
	 string_shader_code = read_shader_code("ShaderCode/FragmentShader.glsl");
	 char_shader_code[0] = string_shader_code.c_str();
	 glShaderSource(fragment_shader_id, 1, char_shader_code, nullptr);

	 //cmmpile shader
	 glCompileShader(vertex_shader_id);
	 glCompileShader(fragment_shader_id);

	 GLint sucess;
	 glGetShaderiv(vertex_shader_id, GL_COMPILE_STATUS, &sucess);
	 if (!sucess)
	 {
		 GLchar info[1024];
		 glGetShaderInfoLog(vertex_shader_id, sizeof(info), nullptr, info);
		 std::cout << "something error" << std::endl;
	 }
	 else
	 {
		 GLchar info[1024];
		 glGetShaderInfoLog(vertex_shader_id, sizeof(info), nullptr, info);
		 std::cout << "something successful"  <<info<< std::endl;
	 }

	 //attch shader
	 program_id = glCreateProgram();
	 glAttachShader(program_id, vertex_shader_id);
	 glAttachShader(program_id, fragment_shader_id);

	 //link shader program
	 glLinkProgram(program_id);

	 if (sucess== 0) {
		 GLchar errorInfo[1024];
		 glGetProgramInfoLog(program_id, sizeof(errorInfo), nullptr, errorInfo);
		 fprintf(stderr, "Error linking shader program: '%s'\n", errorInfo);
	 }

	 //use program
	 glUseProgram(program_id);

}
*/