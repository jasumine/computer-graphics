////////////////////////////////////////////////////////////////////////////////
// Filename: graphicsclass.h
////////////////////////////////////////////////////////////////////////////////
#ifndef _GRAPHICSCLASS_H_
#define _GRAPHICSCLASS_H_


//////////////
// INCLUDES //
//////////////
#include <windows.h>


/////////////
// GLOBALS //
/////////////
const bool FULL_SCREEN = false; // true로 바꾸면 전체화면으로 시작
const bool VSYNC_ENABLED = true;
const float SCREEN_DEPTH = 1000.0f;
const float SCREEN_NEAR = 0.1f;


////////////////////////////////////////////////////////////////////////////////
// Class name: GraphicsClass
////////////////////////////////////////////////////////////////////////////////
class GraphicsClass
{
public:
	GraphicsClass();
	GraphicsClass(const GraphicsClass&);
	~GraphicsClass();

	bool Initialize(int, int, HWND); // 초기화
	void Shutdown(); // 종료함수
	bool Frame();

private:
	bool Render();

private:

};

#endif