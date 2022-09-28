#include <iostream>
#include "CShape.h"

using namespace std;

CShape::CShape()
{
	m_x = 0;
	m_y = 0;
}

CShape::CShape(int x, int y)			
{
	m_x = x;
	m_y = y;
}

void CShape::Draw() const
{
	cout << "[SHAPE] position = {" << m_x << " , " << m_y << ")" << endl;
}
