#include "ShapeGenerator.h"
// 可以定义一个宏 markroo
#define NUMBER_ARRAY_ELEMENTS(a) sizeof(a) / sizeof(*a);

ShapeGenerator::ShapeGenerator()
{
}

ShapeGenerator::~ShapeGenerator()
{
}

ShapeData ShapeGenerator::makeTriangle()
{
	ShapeData ret;

	Vertex VertexArray[] =
	{
		//          X      Y      Z                 R      G      B
		glm::vec3(+0.0f, +1.0f, -1.0f), glm::vec3(+0.0f, +0.0f, +1.0f),   // 0
		glm::vec3(-1.0f, -1.0f, +0.5f), glm::vec3(+1.0f, +0.0f, +0.0f),   // 1
		glm::vec3(+1.0f, -1.0f, +0.5f), glm::vec3(+1.0f, +0.0f, +0.0f),   // 2
		glm::vec3(+0.0f, -1.0f, -1.0f), glm::vec3(+0.0f, +0.0f, +1.0f),   // 3
		glm::vec3(+1.0f, +1.0f, -0.5f), glm::vec3(+0.0f, +0.0f, +1.0f),   // 4
		glm::vec3(-1.0f, +1.0f, -0.5f), glm::vec3(+0.0f, +0.0f, +1.0f),   // 5
	};
	//ret.vertices = VertexArray; //解决方案
	//ret.NumberVertices = NUMBER_ARRAY_ELEMENTS(VertexArray);
	ret.NumberVertices = sizeof(VertexArray) / sizeof(*VertexArray);
	ret.vertices = new Vertex[ret.NumberVertices];
	memcpy(ret.vertices, VertexArray, sizeof(VertexArray));

	GLuint IndexArray[] =
	{
		0, 1, 2,  //frist triangle
		3, 4, 5   //second triangle
	};
	//ret.indices = IndexArray; //解决方案
	//ret.NumberIndices = NUMBER_ARRAY_ELEMENTS(IndexArray);
	ret.NumberIndices = sizeof(IndexArray) / sizeof(*IndexArray);
	ret.indices = new GLuint[ret.NumberIndices];
	memcpy(ret.indices, IndexArray, sizeof(IndexArray));

	return ret;
}