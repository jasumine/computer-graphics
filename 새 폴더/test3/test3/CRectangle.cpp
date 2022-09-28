#include <iostream>
#include "CRectangle.h"

CRectangle::CRectangle(float x, float y, float w, float h)
{
	m_x = x;
	m_y = y;
	m_w = w;
	m_h = h;
	rect.bottom = (LONG)(m_y - m_h / 2);
	rect.left = (LONG)(m_x);
	rect.right = (LONG)(m_x + m_w / 2);
	rect.top = (LONG)(m_y + m_h / 2);
}

CRectangle::~CRectangle()
{

}

void CRectangle::Draw(HDC pDC)
{
	Rectangle(pDC, (int)m_x, (int)m_y, int(m_w), (int)m_h);
}