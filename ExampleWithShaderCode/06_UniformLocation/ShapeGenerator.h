#pragma once
#include <glm\glm.hpp>
#include "Vertex.h"
#include "ShapeData.h"
class ShapeGenerator {

public:
	ShapeGenerator();
	~ShapeGenerator();
public:
	static ShapeData makeTriangle();
};

