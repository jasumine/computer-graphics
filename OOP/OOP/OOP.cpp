#include <iostream>
#include "CCircle.h"
#include "CRectangle.h"
#include "CShape.h"

int main()
{
	CShape a(100, 40);
	CRectangle b(120, 40, 50, 20);
	CCircle c(200, 100, 50);

	a.Draw();
	b.Draw();
	c.Draw();

	return 0;


}
