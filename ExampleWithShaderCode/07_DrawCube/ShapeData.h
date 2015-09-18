#pragma once
#include "GL\glew.h"
#include "Vertex.h"

struct ShapeData
{
	Vertex* vertices;
	GLuint  NumberVertices;
	GLuint* indices;
	GLuint  NumberIndices;

	ShapeData() 
		:vertices(nullptr)
		, NumberVertices(0)
		, indices(nullptr)
		, NumberIndices(0)
	{
	}

	~ShapeData()
	{
	}

	GLsizeiptr VertexBufferSize() const
	{
		return NumberVertices*sizeof(Vertex);
	}
	GLsizeiptr IndicesBufferSize() const
	{
		return NumberIndices*sizeof(Vertex);
	}

	void cleanup()
	{
		delete[]vertices;
		delete[]indices;
		NumberVertices = 0;
		NumberIndices = 0;
	}
};