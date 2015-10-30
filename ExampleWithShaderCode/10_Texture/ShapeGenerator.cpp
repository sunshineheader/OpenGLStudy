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
		glm::vec3(+0.0f, +1.0f, -1.0f), glm::vec3(+0.0f, +0.0f, +1.0f), glm::vec2(),  // 0
		glm::vec3(-1.0f, -1.0f, +0.5f), glm::vec3(+1.0f, +0.0f, +0.0f), glm::vec2(),  // 1
		glm::vec3(+1.0f, -1.0f, +0.5f), glm::vec3(+1.0f, +0.0f, +0.0f), glm::vec2(),  // 2
		glm::vec3(+0.0f, -1.0f, -1.0f), glm::vec3(+0.0f, +0.0f, +1.0f), glm::vec2(),  // 3
		glm::vec3(+1.0f, +1.0f, -0.5f), glm::vec3(+0.0f, +0.0f, +1.0f), glm::vec2(),  // 4
		glm::vec3(-1.0f, +1.0f, -0.5f), glm::vec3(+0.0f, +0.0f, +1.0f), glm::vec2()   // 5
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
ShapeData ShapeGenerator::makeRect()
{
	ShapeData ret;
	Vertex RectVertices[] = 
	{
		glm::vec3(-0.5f, +0.5f, +0.0f), glm::vec3(+1.0f, +0.0f, +0.0f), glm::vec2(), // 0
		glm::vec3(-0.5f, -0.5f, +0.0f), glm::vec3(+0.0f, +1.0f, +0.0f), glm::vec2(), // 1
		glm::vec3(+0.5f, -0.5f, +0.0f), glm::vec3(+0.0f, +0.0f, +1.0f), glm::vec2(), // 2
		glm::vec3(+0.5f, +0.5f, +0.0f), glm::vec3(+0.0f, +1.0f, +0.0f), glm::vec2() // 3
	};
	//ret.vertices = TriangleVerticesArray; //解决方案
	//ret.NumberVertices = NUMBER_ARRAY_ELEMENTS(TriangleVerticesArray);
	ret.NumberVertices = sizeof(RectVertices) / sizeof(*RectVertices);
	ret.vertices = new Vertex[ret.NumberVertices];
	memcpy(ret.vertices, RectVertices, sizeof(RectVertices));

	GLuint RectIndexArray[] =
	{
		0, 1, 2,  //frist triangle
		2, 3, 0   //second triangle
	};
	//ret.indices = TriangleIndexArray; //解决方案
	//ret.NumberIndices = NUMBER_ARRAY_ELEMENTS(TriangleIndexArray);
	ret.NumberIndices = sizeof(RectIndexArray) / sizeof(*RectIndexArray);
	ret.indices = new GLuint[ret.NumberIndices];
	memcpy(ret.indices, RectIndexArray, sizeof(RectIndexArray));
	return ret;
}

ShapeData ShapeGenerator::makeCube()
{
	ShapeData ret;
	Vertex CubeVerticesArray[] =
	{
		//          X      Y      Z                 R      G      B
		// face 0:
		glm::vec3(+1.0f, +1.0f, +1.0f), glm::vec3(+1.0f, +0.0f, +0.0f),glm::vec2(), // vertex 0
		glm::vec3(-1.0f, +1.0f, +1.0f), glm::vec3(+0.5f, +0.3f, +0.2f),glm::vec2(), // vertex 1
		glm::vec3(+1.0f, -1.0f, +1.0f), glm::vec3(+0.0f, +0.0f, +1.0f),glm::vec2(), // vertex 2
		glm::vec3(-1.0f, -1.0f, +1.0f), glm::vec3(+1.0f, +1.0f, -1.0f),glm::vec2(), // vertex 3
		// face 1:
		glm::vec3(+1.0f, +1.0f, +1.0f), glm::vec3(+1.0f, +0.0f, +1.0f), glm::vec2(), // vertex 0
		glm::vec3(+1.0f, -1.0f, +1.0f), glm::vec3(+0.0f, +0.5f, +0.2f), glm::vec2(), // vertex 1
		glm::vec3(+1.0f, +1.0f, -1.0f), glm::vec3(+0.8f, +0.6f, +0.4f), glm::vec2(), // vertex 2
		glm::vec3(+1.0f, -1.0f, -1.0f), glm::vec3(+0.3f, +1.0f, +0.5f), glm::vec2(), // vertex 3
		// face 2:													 
		glm::vec3(+1.0f, +1.0f, +1.0f), glm::vec3(+0.2f, +0.5f, +0.2f), glm::vec2(), // vertex 0
		glm::vec3(+1.0f, +1.0f, -1.0f), glm::vec3(+0.9f, +0.3f, +0.7f), glm::vec2(), // vertex 1
		glm::vec3(-1.0f, +1.0f, +1.0f), glm::vec3(+0.3f, +0.7f, +0.5f), glm::vec2(), // vertex 2
		glm::vec3(-1.0f, +1.0f, -1.0f), glm::vec3(+0.5f, +0.7f, +0.5f), glm::vec2(), // vertex 3
		// face 3:
		glm::vec3(+1.0f, +1.0f, -1.0f), glm::vec3(+0.7f, +0.8f, +0.2f), glm::vec2(), // vertex 0
		glm::vec3(+1.0f, -1.0f, -1.0f), glm::vec3(+0.5f, +0.7f, +0.3f), glm::vec2(), // vertex 1
		glm::vec3(-1.0f, +1.0f, -1.0f), glm::vec3(+0.4f, +0.7f, +0.7f), glm::vec2(), // vertex 2
		glm::vec3(-1.0f, -1.0f, -1.0f), glm::vec3(+0.2f, +0.5f, +1.0f), glm::vec2(), // vertex 3
		// face 4:
		glm::vec3(-1.0f, +1.0f, +1.0f), glm::vec3(+0.6f, +1.0f, +0.7f), glm::vec2(), // vertex 0
		glm::vec3(-1.0f, +1.0f, -1.0f), glm::vec3(+0.6f, +0.4f, +0.8f), glm::vec2(), // vertex 1
		glm::vec3(-1.0f, -1.0f, +1.0f), glm::vec3(+0.2f, +0.8f, +0.7f), glm::vec2(), // vertex 2
		glm::vec3(-1.0f, -1.0f, -1.0f), glm::vec3(+0.2f, +0.7f, +1.0f), glm::vec2(), // vertex 3
		// face 5:
		glm::vec3(+1.0f, -1.0f, +1.0f), glm::vec3(+0.8f, +0.3f, +0.7f), glm::vec2(), // vertex 0
		glm::vec3(-1.0f, -1.0f, +1.0f), glm::vec3(+0.8f, +0.9f, +0.5f), glm::vec2(), // vertex 1
		glm::vec3(+1.0f, -1.0f, -1.0f), glm::vec3(+0.5f, +0.8f, +0.5f), glm::vec2(), // vertex 2
		glm::vec3(-1.0f, -1.0f, -1.0f), glm::vec3(+0.9f, +1.0f, +0.2f), glm::vec2(), // vertex 3
	};

	//ret.vertices = CubeVerticesArray;
	ret.NumberVertices= sizeof(CubeVerticesArray) / sizeof(*CubeVerticesArray);
	ret.vertices = new Vertex[ret.NumberVertices];
	memcpy(ret.vertices, CubeVerticesArray, sizeof(CubeVerticesArray));

	GLuint CubeIndicesArray[] = 
	{
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

ShapeData ShapeGenerator::makeCone()
{
	ShapeData ret;
	Vertex ConeVertexData[] =
	{
		//Vertices[0] = Vector3f(-1.0f, -1.0f, 0.0f);
		glm::vec3(-0.5f, -0.5f, +0.0f), glm::vec3(+1.0f, +0.0f, +0.0f), glm::vec2(),
		//Vertices[1] = Vector3f(0.0f, -1.0f, 1.0f);
		glm::vec3(+0.0f, -0.5f, +0.5f), glm::vec3(+0.0f, +1.0f, +0.0f), glm::vec2(),
		//Vertices[2] = Vector3f(1.0f, -1.0f, 0.0f);
		glm::vec3(+0.5f, -0.5f, +0.0f), glm::vec3(+0.0f, +0.0f, +1.0f), glm::vec2(),
		//Vertices[3] = Vector3f(0.0f, 1.0f, 0.0f);
		glm::vec3(+0.0f, +0.5f, +0.0f), glm::vec3(+0.0f, +1.0f, +0.0f), glm::vec2()
	}; 
	//ret.vertices = TriangleVerticesArray; //解决方案
	//ret.NumberVertices = NUMBER_ARRAY_ELEMENTS(TriangleVerticesArray);
	ret.NumberVertices = sizeof(ConeVertexData) / sizeof(*ConeVertexData);
	ret.vertices = new Vertex[ret.NumberVertices];
	memcpy(ret.vertices, ConeVertexData, sizeof(ConeVertexData));

    GLuint ConeIndexData[] = { 
	   0, 3, 1,
	   1, 3, 2,
	   2, 3, 0,
	   0, 1, 2 
	};
	//ret.indices = TriangleIndexArray; //解决方案
	//ret.NumberIndices = NUMBER_ARRAY_ELEMENTS(TriangleIndexArray);
	ret.NumberIndices = sizeof(ConeIndexData) / sizeof(*ConeIndexData);
	ret.indices = new GLuint[ret.NumberIndices];
	memcpy(ret.indices, ConeIndexData, sizeof(ConeIndexData));
	return ret;
}