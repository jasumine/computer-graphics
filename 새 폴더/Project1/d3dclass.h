////////////////////////////////////////////////////////////////////////////////
// Filename: d3dclass.h
////////////////////////////////////////////////////////////////////////////////
#ifndef _D3DCLASS_H_
#define _D3DCLASS_H_


/////////////
// LINKING //
/////////////
// 외부 파일, 강제로 추가하는 방법(좋지않다)
#pragma comment(lib, "dxgi.lib")
#pragma comment(lib, "d3d11.lib")

//////////////
// INCLUDES //
//////////////
// DX를 하기 위해 필요
#include <dxgi.h> // interface 기본 헤더 파일
#include <d3dcommon.h> // D3D에서 흔히 많이 사용되는 함수들
#include <d3d11.h> // 11버전 헤드파일
#include <directxmath.h> // 수학관련된 함수

#include "AlignedAllocationPolicy.h" // 16비트로 끊어서 해야함 (DX에 포함되지 않아 따로작성)

using namespace DirectX; // 이름 공간

////////////////////////////////////////////////////////////////////////////////
// Class name: D3DClass
////////////////////////////////////////////////////////////////////////////////
class D3DClass : public AlignedAllocationPolicy<16> // 16비트 -> D3D data는 16비트로 끊어서 넘겨주어야 한다.
{
public:
	D3DClass(); // 생성자
	D3DClass(const D3DClass&);
	~D3DClass(); // 소멸자

	bool Initialize(int, int, bool, HWND, bool, float, float); // 초기화
	void Shutdown(); // 메모리 해제
	
	void BeginScene(float, float, float, float); // 씬을 시작 
	void EndScene(); // 끝낸다.

	// GPU에 있는 리쏘스를 얻어와야 cpu의 정보를 넘겨 줄수 있어서
	ID3D11Device* GetDevice(); //  리쏘쓰를 받아오는 포인터
	ID3D11DeviceContext* GetDeviceContext();

	// 화면에 보이는 과정에 필요한 그래픽 파이프라인
	void GetProjectionMatrix(XMMATRIX&);
	void GetWorldMatrix(XMMATRIX&);
	void GetOrthoMatrix(XMMATRIX&);

	void GetVideoCardInfo(char*, int&);

private:
	bool m_vsync_enabled;
	int m_videoCardMemory;
	char m_videoCardDescription[128];
	IDXGISwapChain* m_swapChain;
	ID3D11Device* m_device;
	ID3D11DeviceContext* m_deviceContext;
	ID3D11RenderTargetView* m_renderTargetView;
	ID3D11Texture2D* m_depthStencilBuffer;
	ID3D11DepthStencilState* m_depthStencilState;
	ID3D11DepthStencilView* m_depthStencilView;
	ID3D11RasterizerState* m_rasterState;
	// Interface , DX = Direct X , D3D = Direct 3D , +숫자는 버전을 뜻한다.
	// 이렇게 시작하면 DX 관련

	XMMATRIX m_projectionMatrix;
	XMMATRIX m_worldMatrix;
	XMMATRIX m_orthoMatrix;
	// 다이렉트 X Math를 의미
	// 궁금하면 f1키를 누르면 된다.
};

#endif