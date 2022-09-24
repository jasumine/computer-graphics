#include <iostream>
#include "CRectangle.h"

using namespace std;

CRectangle::CRectangle(int x, int y, float w, float h)
{
	m_x = x;
	m_y = y;
	m_w = w;
	m_h = w;
}

void CRectangle::Draw() const
{
	cout << "[RECTANGLE] position = (" << m_x << "," << m_y << "), size = (" << m_w << " , " << m_h << ")" << endl;
}