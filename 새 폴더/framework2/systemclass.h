////////////////////////////////////////////////////////////////////////////////
// Filename: systemclass.h
////////////////////////////////////////////////////////////////////////////////
#ifndef _SYSTEMCLASS_H_
#define _SYSTEMCLASS_H_


///////////////////////////////
// PRE-PROCESSING DIRECTIVES //
///////////////////////////////
#define WIN32_LEAN_AND_MEAN


//////////////
// INCLUDES //
//////////////
#include <windows.h>


///////////////////////
// MY CLASS INCLUDES //
///////////////////////
#include "inputclass.h"
#include "graphicsclass.h"


////////////////////////////////////////////////////////////////////////////////
// Class name: SystemClass
////////////////////////////////////////////////////////////////////////////////
class SystemClass
{
public:
	SystemClass(); // 생성자 2개
	SystemClass(const SystemClass&);
	~SystemClass(); // 소멸자 1개

	bool Initialize(); // 초기화 함수
	void Shutdown(); // 프로그램 종료
	void Run(); // 프로그램 실행

	LRESULT CALLBACK MessageHandler(HWND, UINT, WPARAM, LPARAM);
	// windowprc 함수 역할

private:
	bool Frame();
	void InitializeWindows(int&, int&);
	void ShutdownWindows();

private:
	LPCWSTR m_applicationName; // 이름 정할 수 있음
	HINSTANCE m_hinstance; // instance를 관리 하는 변수
	HWND m_hwnd; // 윈도우의 위치 , 자체 변수

	InputClass* m_Input; // 하위 객체를 가르키는 포인터 2개
	GraphicsClass* m_Graphics;
};


/////////////////////////
// FUNCTION PROTOTYPES //
/////////////////////////
static LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
// window main에 있던 함수를 헤더파일에 넣는다.


/////////////
// GLOBALS //
/////////////
static SystemClass* ApplicationHandle = 0;
// 어디서나 접근 할 수있도록 전역변수 설정


#endif