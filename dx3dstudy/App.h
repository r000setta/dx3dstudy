#pragma once

#include <d3d11_1.h>
#include <wrl/client.h>
#include <string>
#include <DirectXMath.h>
#include "GameTimer.h"

#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "dxgi.lib")
#pragma comment(lib, "dxguid.lib")
#pragma comment(lib, "D3DCompiler.lib")
#pragma comment(lib, "winmm.lib")

class App {
public:
	App(HINSTANCE hInstance);
	virtual ~App();

	HINSTANCE AppInst() const;
	HWND MainWnd() const;
	float AspectRatio() const;

	int Run();

	virtual bool Init();
	virtual void OnResize();
	virtual void UpdateScene(float dt) = 0;
	virtual void DrawScene() = 0;
	virtual LRESULT MsgProc(HWND hwnd, UINT msg, WPARAM wPraram, LPARAM lParam);

protected:
	bool initMainWindow();
	bool initDirect3D();

	void calculateFrameStats();
protected:
	HINSTANCE m_hAppInst;	//Ӧ�þ��
	HWND m_hMainWnd;	//�����ھ��
	bool m_AppPaused;	//�Ƿ���ͣ
	bool m_Minimized;	//�Ƿ���С��
	bool m_Maximized;	//�Ƿ����
	bool m_Resizing;	//���ڴ�С�Ƿ�仯
	bool m_Enable4xMsaa;	//�Ƿ���4�����ز���
	UINT m_4xMsaaQuality;	//MSAA֧�ֵ������ȼ�

	GameTimer m_Timer;	//��ʱ��

	template<class T>
	using Comptr = Microsoft::WRL::ComPtr<T>;

	Comptr<ID3D11Device> m_pd3dDevice;	//d3d11�豸
	Comptr<ID3D11DeviceContext> m_pd3dImmediateContext;	//d3d11�豸������
	Comptr<IDXGISwapChain> m_pSwapChain;	//d3d11������
	Comptr<ID3D11Device1> m_pd3dDevice1;	//d3d11.1�豸
	Comptr<ID3D11DeviceContext1> m_pd3dImmediateContext1;	//d3d11.1�豸������
	Comptr<IDXGISwapChain1> m_pSwapChain1;		//d3d11.1������

	Comptr<ID3D11Texture2D> m_pDepthSthencilBuffer;	//���ģ�建����
	Comptr<ID3D11RenderTargetView> m_pRenderTargetView;	//��ȾĿ����ͼ
	Comptr<ID3D11DepthStencilView> m_pDepthStencilView;	//���ģ����ͼ
	D3D11_VIEWPORT m_ScreenViewport;	//�ӿ�	

	std::wstring m_MainWndCaption;	//�����ڱ���

	int m_ClientWidth;
	int m_ClientHeight;
	
};