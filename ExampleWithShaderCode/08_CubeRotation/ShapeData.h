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
		:vertices(0)
		, NumberVertices(0)
		, indices(0)
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