#pragma once
class CShape
{
public:
	int m_x, m_y;

	CShape();
	CShape(int x, int y);

	virtual void Draw() const;
};

