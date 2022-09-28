#pragma once
#include "CShape.h"
class CRectangle :
    public CShape
{
public:
    float m_w, m_h;

    CRectangle(int x, int y, float w, float h);

    void Draw() const;
};

