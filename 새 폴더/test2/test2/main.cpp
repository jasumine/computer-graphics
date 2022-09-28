// Main.cpp
#include <windows.h>
LONG WINAPI WndProc(HWND, UINT, WPARAM, LPARAM); // 메세지 처리함수

// main 함수
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE
	hPrevInstance, LPSTR lpszCmdLine, int nCmdShow)
{
	WNDCLASS wc;
	HWND hwnd;
	MSG msg; // message
 
	// 만들기 위해 필요한 것들 
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

	// 실제 생성하는 함수
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

	ShowWindow(hwnd, nCmdShow); // 윈도우창에 띄운다
	UpdateWindow(hwnd);
	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}

// callback 함수 - 불러오는 것
// WM으로 시작하면 메세지 함수
LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc;

	switch (message) {
	
	case WM_PAINT: // 
		hdc = BeginPaint(hwnd, &ps); // 시작
		Ellipse(hdc, 0, 0, 200, 100); // win 간단한거 그리기 함수(GDI)
		// 0,0 시작 가로 200 세로 100 원그리기

		RECT rect;
		GetClientRect(hwnd, &rect);
		DrawText(hdc, "hello, Windows", -1, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);


		EndPaint(hwnd, &ps); // 끝

		return 0;

	case WM_LBUTTONDOWN:
		MessageBox(hwnd, "haha", "Test!", MB_OK);
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	// 메세지 추가는 여기서 하면 된다.
	return DefWindowProc(hwnd, message, wParam, lParam);
}