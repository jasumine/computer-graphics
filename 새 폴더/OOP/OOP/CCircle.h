#pragma once
#include "CShape.h"
class CCircle :
    public CShape
{
public:
    float m_r;

    CCircle(int x, int y, float r);

    void Draw() const;
        
};

