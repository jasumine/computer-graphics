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
	SystemClass(); // ������ 2��
	SystemClass(const SystemClass&);
	~SystemClass(); // �Ҹ��� 1��

	bool Initialize(); // �ʱ�ȭ �Լ�
	void Shutdown(); // ���α׷� ����
	void Run(); // ���α׷� ����

	LRESULT CALLBACK MessageHandler(HWND, UINT, WPARAM, LPARAM);
	// windowprc �Լ� ����

private:
	bool Frame();
	void InitializeWindows(int&, int&);
	void ShutdownWindows();

private:
	LPCWSTR m_applicationName; // �̸� ���� �� ����
	HINSTANCE m_hinstance; // instance�� ���� �ϴ� ����
	HWND m_hwnd; // �������� ��ġ , ��ü ����

	InputClass* m_Input; // ���� ��ü�� ����Ű�� ������ 2��
	GraphicsClass* m_Graphics;
};


/////////////////////////
// FUNCTION PROTOTYPES //
/////////////////////////
static LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
// window main�� �ִ� �Լ��� ������Ͽ� �ִ´�.


/////////////
// GLOBALS //
/////////////
static SystemClass* ApplicationHandle = 0;
// ��𼭳� ���� �� ���ֵ��� �������� ����


#endif