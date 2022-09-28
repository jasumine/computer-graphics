#pragma once
#include "CShape.h"
class CRectangle :
    public CShape
{
private:
    float m_w, m_h;

public:
    CRectangle(float x, float y, float w, float h);
    ~CRectangle();

    void Draw(HDC pDC);
};

