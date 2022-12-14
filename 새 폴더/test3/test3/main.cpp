// Main.cpp
#include <windows.h>
#include "CShape.h"
#include "CCircle.h"
#include "CRectangle.h"

LONG WINAPI WndProc(HWND, UINT, WPARAM, LPARAM); // 메세지 처리 함수

// main 함수
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE
	hPrevInstance, LPSTR lpszCmdLine, int nCmdShow)
{
	WNDCLASS wc;
	HWND hwnd;
	MSG msg; // message

	wc.style = 0;
	wc.lpfnWndProc = (WNDPROC)WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon(NULL, IDI_WINLOGO);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = "MyWndClass";
	RegisterClass(&wc); 

	// 실제 생성함수
	hwnd = CreateWindow(
		"MyWndClass", // WNDCLASS name
		"SDK Application", // Window title
		WS_OVERLAPPEDWINDOW,// Window style
		CW_USEDEFAULT, // Horizontal position
		CW_USEDEFAULT, // Vertical position 
		300, // Initial width
		200, // Initial height
		HWND_DESKTOP, // Handle of parent window
		NULL, // Menu handle
		hInstance, // Application's instance handle
		NULL // Window-creation data
	);

	ShowWindow(hwnd, nCmdShow); // 윈도우 창에 띄운다
	UpdateWindow(hwnd);
	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}

// callback 함수
// WM으로 시작하면 메세지 함수
LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc;
	
	// 객체생성
	CShape* shapes[5] = { NULL };

	shapes[0] = new CCircle(100, 100, 50);
	shapes[1] = new CRectangle(300, 300, 100, 100);
	shapes[2] = new CRectangle(200, 100, 50, 150);
	shapes[3] = new CCircle(100, 300, 150);
	shapes[4] = new CRectangle(200, 200, 200, 200);

	switch (message) {

	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps); // 그리기 시작 함수
		// Ellipse(hdc, 0, 0, 200, 100); // win내 간단한 그리기 함수(GDI)
		// 0,0 시작, 가로 200 세로, 100

		RECT rect;
		GetClientRect(hwnd, &rect);
		// DrawText(hdc, "hello, Windows", -1, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);

		for (int i = 0; i < 5; i++)
		{
			shapes[i]->Draw(hdc);
		}

		EndPaint(hwnd, &ps); // 그리기 끝 함수
		return 0;

	case WM_LBUTTONDOWN:
		MessageBox(hwnd, "haha", "Test!", MB_OK);
		break;

	// 메세지는 여기 계속 추가 하면 된다. 

	case WM_DESTROY:
		// 메모리 해제
		for (int i = 0; i < 5; i++)
		{
			delete shapes[i];
			shapes[i] = NULL;
		}

		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd, message, wParam, lParam);
}

