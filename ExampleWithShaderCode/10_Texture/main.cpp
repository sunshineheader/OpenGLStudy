#include "GL\glew.h"
#include "GL\freeglut.h"
#include <iostream>
#include "ShaderManager.h"
#include "FreeImage.h"
using namespace std;

GLuint TextureID;

// 向OpenGL描述数据
void InitData();
// 向OpenGL描述纹理
void InitTexture();
// shader 函数
void AddShader();
// OpenGL的显示函数
void MyOpenGLDisplay();
// 加载图片
void load_image(const char *fname);

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

	glClearColor(0.0f,0.1f,0.1f,0.1f);
	InitData();
	InitTexture();
	AddShader();
	glutDisplayFunc(&MyOpenGLDisplay);
	glutMainLoop();
	return 0;
}

void InitData()
{
	GLfloat VertexData[] =
	{
		// X     Y      Z     U       V
		+0.0f, +1.0f, +0.0f, +10.0f, +10.0f, // vertex 0
		-1.0f, -1.0f, +0.0f, +0.0f,  +10.0f, // vertex 1
		+1.0f, -1.0f, +0.0f, +10.5f, +0.0f,  // vertex 2
	};
	GLushort IndicesData[] = 
	{
		0, 1, 2
	};

	GLuint VBO;
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(VertexData), VertexData, GL_STATIC_DRAW);

	GLuint IBO;
	glGenBuffers(1,&IBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(IndicesData), IndicesData, GL_STATIC_DRAW);

}
void InitTexture()
{
	glGenTextures(1, &TextureID);
	glBindTexture(GL_TEXTURE_2D, TextureID);
	load_image("store.png");
}
void AddShader()
{
	auto VertexShaderID=glCreateShader(GL_VERTEX_SHADER);
	auto FragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
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
	auto ProgramID = glCreateProgram();
	// 附加着色器 attach shader
	glAttachShader(ProgramID, VertexShaderID);
	glAttachShader(ProgramID, FragmentShaderID);
	// 链接着色器 link shader link program
	glLinkProgram(ProgramID);
	// 检查着色器的连接错误 link error
	ShaderManager::CheckShaderLinkProgramStatus(ProgramID);
	GLint texture_location = glGetUniformLocation(ProgramID, "gSampler");

	// 使用程序  use prgram
	glUseProgram(ProgramID);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, TextureID);

	// set texture uniform
	glUniform1i(texture_location, 0);
}
void MyOpenGLDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT | GL_DOUBLEBUFFER);
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(GLfloat)*5, 0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(GLfloat)*5, (char*)0 + sizeof(GLfloat)*3);
	glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_SHORT, nullptr);
	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	glutSwapBuffers();
}


void load_image(const char *fname) {

	// active only for static linking
#ifdef FREEIMAGE_LIB
	FreeImage_Initialise();
#endif

	FIBITMAP *bitmap;
	// Get the format of the image file
	FREE_IMAGE_FORMAT fif = FreeImage_GetFileType(fname, 0);

	// If the format can't be determined, try to guess the format from the file name
	if (fif == FIF_UNKNOWN) {
		fif = FreeImage_GetFIFFromFilename(fname);
	}

	// Load the data in bitmap if possible
	if (fif != FIF_UNKNOWN && FreeImage_FIFSupportsReading(fif)) {
		bitmap = FreeImage_Load(fif, fname);
	}
	else {
		bitmap = NULL;
	}

	// PROCESS IMAGE if bitmap was successfully initialized
	if (bitmap) {
		unsigned int w = FreeImage_GetWidth(bitmap);
		unsigned int h = FreeImage_GetHeight(bitmap);
		unsigned pixel_size = FreeImage_GetBPP(bitmap);
		// Get a pointer to the pixel data
		BYTE *data = (BYTE*)FreeImage_GetBits(bitmap);

		// Process only RGB and RGBA images
		if (pixel_size == 24) {
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, w, h, 0, GL_BGR, GL_UNSIGNED_BYTE, (GLvoid*)data);
		}
		else if (pixel_size == 32) {
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_BGRA, GL_UNSIGNED_BYTE, (GLvoid*)data);
		}
		else {
			std::cerr << "pixel size = " << pixel_size << " don't know how to process this case. I'm out!" << std::endl;
			exit(-1);
		}

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	}
	else {
		std::cerr << "Unable to load the image file " << fname << " I'm out!" << std::endl;
		exit(-1);
	}

	// Clean bitmap;
	FreeImage_Unload(bitmap);

	// active only for static linking
#ifdef FREEIMAGE_LIB
	FreeImage_DeInitialise();
#endif	

}