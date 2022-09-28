////////////////////////////////////////////////////////////////////////////////
// Filename: d3dclass.h
////////////////////////////////////////////////////////////////////////////////
#ifndef _D3DCLASS_H_
#define _D3DCLASS_H_


/////////////
// LINKING //
/////////////
// �ܺ� ����, ������ �߰��ϴ� ���(�����ʴ�)
#pragma comment(lib, "dxgi.lib")
#pragma comment(lib, "d3d11.lib")

//////////////
// INCLUDES //
//////////////
// DX�� �ϱ� ���� �ʿ�
#include <dxgi.h> // interface �⺻ ��� ����
#include <d3dcommon.h> // D3D���� ���� ���� ���Ǵ� �Լ���
#include <d3d11.h> // 11���� �������
#include <directxmath.h> // ���а��õ� �Լ�

#include "AlignedAllocationPolicy.h" // 16��Ʈ�� ��� �ؾ��� (DX�� ���Ե��� �ʾ� �����ۼ�)

using namespace DirectX; // �̸� ����

////////////////////////////////////////////////////////////////////////////////
// Class name: D3DClass
////////////////////////////////////////////////////////////////////////////////
class D3DClass : public AlignedAllocationPolicy<16> // 16��Ʈ -> D3D data�� 16��Ʈ�� ��� �Ѱ��־�� �Ѵ�.
{
public:
	D3DClass(); // ������
	D3DClass(const D3DClass&);
	~D3DClass(); // �Ҹ���

	bool Initialize(int, int, bool, HWND, bool, float, float); // �ʱ�ȭ
	void Shutdown(); // �޸� ����
	
	void BeginScene(float, float, float, float); // ���� ���� 
	void EndScene(); // ������.

	// GPU�� �ִ� ����� ���;� cpu�� ������ �Ѱ� �ټ� �־
	ID3D11Device* GetDevice(); //  ����� �޾ƿ��� ������
	ID3D11DeviceContext* GetDeviceContext();

	// ȭ�鿡 ���̴� ������ �ʿ��� �׷��� ����������
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
	// Interface , DX = Direct X , D3D = Direct 3D , +���ڴ� ������ ���Ѵ�.
	// �̷��� �����ϸ� DX ����

	XMMATRIX m_projectionMatrix;
	XMMATRIX m_worldMatrix;
	XMMATRIX m_orthoMatrix;
	// ���̷�Ʈ X Math�� �ǹ�
	// �ñ��ϸ� f1Ű�� ������ �ȴ�.
};

#endif