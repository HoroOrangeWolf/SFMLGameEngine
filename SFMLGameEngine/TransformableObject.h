#pragma once
class TransformableObject
{
public:
	virtual void translate() = 0;
	virtual void rotate() = 0;
	virtual void scale() = 0;

};

