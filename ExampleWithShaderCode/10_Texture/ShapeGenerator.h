#pragma once
#include <glm\glm.hpp>
#include "Vertex.h"
#include "ShapeData.h"

class ShapeGenerator  {

public:
	ShapeGenerator();
	~ShapeGenerator();
public:
	static ShapeData makeTriangle();
	static ShapeData makeRect();
	static ShapeData makeCube();
	static ShapeData makeCircle();
	static ShapeData makeCone();
};

