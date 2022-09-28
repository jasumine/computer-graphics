#include <Windows.h>
#include "CCircle.h"

CCircle::CCircle(float x, float y, float r)
{
	m_x = x;
	m_y = y;
	m_r = r;

	rect.bottom = (LONG)(m_y - m_r);
	rect.left = (LONG)m_x;
	rect.right = (LONG)(m_x + m_r);
	rect.top = (LONG)(m_y + m_r);
}

CCircle::~CCircle()
{

}

void CCircle::Draw(HDC pDC)
{
	Ellipse(pDC, (int)(m_x - m_r), (int)(m_y - m_r), (int)(m_x + m_r), (int)(m_y + m_r));
}
