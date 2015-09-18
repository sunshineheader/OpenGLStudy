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

	Vertex TriangleVerticesArray[] =
	{
		//          X      Y      Z                 R      G      B
		glm::vec3(+0.0f, +1.0f, -1.0f), glm::vec3(+0.0f, +0.0f, +1.0f),   // 0
		glm::vec3(-1.0f, -1.0f, +0.5f), glm::vec3(+1.0f, +0.0f, +0.0f),   // 1
		glm::vec3(+1.0f, -1.0f, +0.5f), glm::vec3(+1.0f, +0.0f, +0.0f),   // 2
		glm::vec3(+0.0f, -1.0f, -1.0f), glm::vec3(+0.0f, +0.0f, +1.0f),   // 3
		glm::vec3(+1.0f, +1.0f, -0.5f), glm::vec3(+0.0f, +0.0f, +1.0f),   // 4
		glm::vec3(-1.0f, +1.0f, -0.5f), glm::vec3(+0.0f, +0.0f, +1.0f),   // 5
	};
	//ret.vertices = TriangleVerticesArray; //解决方案
	//ret.NumberVertices = NUMBER_ARRAY_ELEMENTS(TriangleVerticesArray);
	ret.NumberVertices = sizeof(TriangleVerticesArray) / sizeof(*TriangleVerticesArray);
	ret.vertices = new Vertex[ret.NumberVertices];
	memcpy(ret.vertices, TriangleVerticesArray, sizeof(TriangleVerticesArray));

	GLuint TriangleIndexArray[] =
	{
		0, 1, 2,  //frist triangle
		3, 4, 5   //second triangle
	};
	//ret.indices = TriangleIndexArray; //解决方案
	//ret.NumberIndices = NUMBER_ARRAY_ELEMENTS(TriangleIndexArray);
	ret.NumberIndices = sizeof(TriangleIndexArray) / sizeof(*TriangleIndexArray);
	ret.indices = new GLuint[ret.NumberIndices];
	memcpy(ret.indices, TriangleIndexArray, sizeof(TriangleIndexArray));

	return ret;
}

ShapeData ShapeGenerator::makeCube()
{
	ShapeData ret;
	Vertex CubeVerticesArray[] = 
	{
		////          X      Y      Z                    R      G      B
		//glm::vec3(-1.0f, +1.0f, +1.0f),    glm::vec3(+1.0f, +0.0f, +0.0f),   // 0
		//glm::vec3(+1.0f, +1.0f, +1.0f),    glm::vec3(+0.0f, +1.0f, +0.0f),   // 1
		//glm::vec3(+1.0f, +1.0f, -1.0f),    glm::vec3(+0.0f, +0.0f, +1.0f),   // 2
		//glm::vec3(-1.0f, +1.0f, -1.0f),    glm::vec3(+1.0f, +1.0f, -1.0f),   // 3

		//glm::vec3(-1.0f, +1.0f, -1.0f),    glm::vec3(+1.0f, +0.0f, +1.0f),   // 4
		//glm::vec3(+1.0f, +1.0f, -1.0f),    glm::vec3(+0.0f, +0.5f, +0.2f),   // 5
		//glm::vec3(+1.0f, -1.0f, -1.0f),    glm::vec3(+0.8f, +0.6f, +0.4f),   // 6
		//glm::vec3(-1.0f, -1.0f, -1.0f),    glm::vec3(+0.3f, +1.0f, +0.5f),   // 7

		//glm::vec3(+1.0f, +1.0f, -1.0f),    glm::vec3(+0.2f, +0.5f, +0.2f),   // 8
		//glm::vec3(+1.0f, +1.0f, +1.0f),    glm::vec3(+0.9f, +0.3f, +0.7f),   // 9
		//glm::vec3(+1.0f, -1.0f, +1.0f),    glm::vec3(+0.3f, +0.7f, +0.5f),   // 10
		//glm::vec3(+1.0f, -1.0f, -1.0f),    glm::vec3(+0.5f, +0.7f, +0.5f),   // 11

		//glm::vec3(-1.0f, +1.0f, +1.0f),    glm::vec3(+0.7f, +0.8f, +0.2f),   // 12
		//glm::vec3(-1.0f, +1.0f, -1.0f),    glm::vec3(+0.5f, +0.7f, +0.3f),   // 13
		//glm::vec3(-1.0f, -1.0f, -1.0f),    glm::vec3(+0.4f, +0.7f, +0.7f),   // 14
		//glm::vec3(-0.0f, -1.0f, +1.0f),    glm::vec3(+0.2f, +0.5f, +1.0f),   // 15

		//glm::vec3(+1.0f, +1.0f, +1.0f),    glm::vec3(+0.6f, +1.0f, +0.7f),   // 16
		//glm::vec3(-1.0f, +1.0f, -1.0f),    glm::vec3(+0.6f, +0.4f, +0.8f),   // 17
		//glm::vec3(-1.0f, -1.0f, +1.0f),    glm::vec3(+0.2f, +0.8f, +0.7f),   // 18
		//glm::vec3(+1.0f, -1.0f, +1.0f),    glm::vec3(+0.2f, +0.7f, +1.0f),   // 19

		//glm::vec3(+1.0f, -1.0f, -1.0f),    glm::vec3(+0.8f, +0.3f, +0.7f),   // 20
		//glm::vec3(-1.0f, -1.0f, -1.0f),    glm::vec3(+0.8f, +0.9f, +0.5f),   // 21
		//glm::vec3(-1.0f, -1.0f, +1.0f),    glm::vec3(+0.5f, +0.8f, +0.5f),   // 22
		//glm::vec3(+1.0f, -1.0f, +1.0f),    glm::vec3(+0.9f, +1.0f, +0.2f),   // 23


		//          X      Y      Z                 R      G      B
		// face 0:
		glm::vec3(+1.0f, +1.0f, +1.0f), glm::vec3(+1.0f, +0.0f, +0.0f), // vertex 0
		glm::vec3(-1.0f, +1.0f, +1.0f), glm::vec3(+0.5f, +0.3f, +0.2f), // vertex 1
		glm::vec3(+1.0f, -1.0f, +1.0f), glm::vec3(+0.0f, +0.0f, +1.0f), // vertex 2
		glm::vec3(-1.0f, -1.0f, +1.0f), glm::vec3(+1.0f, +1.0f, -1.0f), // vertex 3
		// face 1:
		glm::vec3(+1.0f, +1.0f, +1.0f), glm::vec3(+1.0f, +0.0f, +1.0f), // vertex 0
		glm::vec3(+1.0f, -1.0f, +1.0f), glm::vec3(+0.0f, +0.5f, +0.2f), // vertex 1
		glm::vec3(+1.0f, +1.0f, -1.0f), glm::vec3(+0.8f, +0.6f, +0.4f), // vertex 2
		glm::vec3(+1.0f, -1.0f, -1.0f), glm::vec3(+0.3f, +1.0f, +0.5f), // vertex 3
		// face 2:													 
		glm::vec3(+1.0f, +1.0f, +1.0f), glm::vec3(+0.2f, +0.5f, +0.2f), // vertex 0
		glm::vec3(+1.0f, +1.0f, -1.0f), glm::vec3(+0.9f, +0.3f, +0.7f), // vertex 1
		glm::vec3(-1.0f, +1.0f, +1.0f), glm::vec3(+0.3f, +0.7f, +0.5f), // vertex 2
		glm::vec3(-1.0f, +1.0f, -1.0f), glm::vec3(+0.5f, +0.7f, +0.5f), // vertex 3
		// face 3:
		glm::vec3(+1.0f, +1.0f, -1.0f), glm::vec3(+0.7f, +0.8f, +0.2f), // vertex 0
		glm::vec3(+1.0f, -1.0f, -1.0f), glm::vec3(+0.5f, +0.7f, +0.3f), // vertex 1
		glm::vec3(-1.0f, +1.0f, -1.0f), glm::vec3(+0.4f, +0.7f, +0.7f), // vertex 2
		glm::vec3(-1.0f, -1.0f, -1.0f), glm::vec3(+0.2f, +0.5f, +1.0f), // vertex 3
		// face 4:
		glm::vec3(-1.0f, +1.0f, +1.0f), glm::vec3(+0.6f, +1.0f, +0.7f), // vertex 0
		glm::vec3(-1.0f, +1.0f, -1.0f), glm::vec3(+0.6f, +0.4f, +0.8f), // vertex 1
		glm::vec3(-1.0f, -1.0f, +1.0f), glm::vec3(+0.2f, +0.8f, +0.7f), // vertex 2
		glm::vec3(-1.0f, -1.0f, -1.0f), glm::vec3(+0.2f, +0.7f, +1.0f), // vertex 3
		// face 5:
		glm::vec3(+1.0f, -1.0f, +1.0f), glm::vec3(+0.8f, +0.3f, +0.7f), // vertex 0
		glm::vec3(-1.0f, -1.0f, +1.0f), glm::vec3(+0.8f, +0.9f, +0.5f), // vertex 1
		glm::vec3(+1.0f, -1.0f, -1.0f), glm::vec3(+0.5f, +0.8f, +0.5f), // vertex 2
		glm::vec3(-1.0f, -1.0f, -1.0f), glm::vec3(+0.9f, +1.0f, +0.2f), // vertex 3
	};

	//ret.vertices = CubeVerticesArray;
	ret.NumberVertices= sizeof(CubeVerticesArray) / sizeof(*CubeVerticesArray);
	ret.vertices = new Vertex[ret.NumberVertices];
	memcpy(ret.vertices, CubeVerticesArray, sizeof(CubeVerticesArray));

	GLuint CubeIndicesArray[] = 
	{
		//// top 上面
		//0, 1, 2, // frist  triangle
		//0, 2, 3, // second triangle
		//// front 前面
		//4, 5, 6, // frist  triangle
		//4, 6, 7, // second triangle
		//// right 右面
		//8, 9,  10, // frist  triangle
		//8, 10, 11, // second triangle
		//// left  左面
		//12, 13, 14, // frist  triangle
		//12, 14, 15, // second triangle
		//// back 后面
		//16, 17, 18, // frist  triangle
		//16, 18, 19, // second triangle
		//// button  下面
		//20, 21, 22, // frist  triangle
		//20, 22, 23, // second triangle

		// face 0:
		0, 1, 2,      // first triangle
		2, 1, 3,      // second triangle
		// face 1:
		4, 5, 6,      // first triangle
		6, 5, 7,      // second triangle
		// face 2:
		8, 9, 10,     // first triangle
		10, 9, 11,    // second triangle
		// face 3:
		12, 13, 14,   // first triangle
		14, 13, 15,   // second triangle
		// face 4:
		16, 17, 18,   // first triangle
		18, 17, 19,   // second triangle
		// face 5:
		20, 21, 22,   // first triangle
		22, 21, 23,   // second triangle
	};
	//ret.indices = CubeIndicesArray;
	ret.NumberIndices = sizeof(CubeIndicesArray) / sizeof(*CubeIndicesArray);
	ret.indices = new GLuint[ret.NumberIndices];
	memcpy(ret.indices, CubeIndicesArray, sizeof(CubeIndicesArray));

	return ret;
}

ShapeData ShapeGenerator::makeCircle()
{
	ShapeData ret;

	return ret;
}