#include <iostream>
#include "CCircle.h"

using namespace std;

CCircle::CCircle(int x, int y, float r)
{
	m_x = x;
	m_y = y;
	m_r = r;
}

void CCircle::Draw() const
{
	cout << "[CIRCLE] position = (" << m_x << " , " << m_y << "), radius = " << m_r << endl;
}
