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
	HINSTANCE m_hAppInst;	//应用句柄
	HWND m_hMainWnd;	//主窗口句柄
	bool m_AppPaused;	//是否暂停
	bool m_Minimized;	//是否最小化
	bool m_Maximized;	//是否最大化
	bool m_Resizing;	//窗口大小是否变化
	bool m_Enable4xMsaa;	//是否开启4倍多重采样
	UINT m_4xMsaaQuality;	//MSAA支持的质量等级

	GameTimer m_Timer;	//计时器

	template<class T>
	using Comptr = Microsoft::WRL::ComPtr<T>;

	Comptr<ID3D11Device> m_pd3dDevice;	//d3d11设备
	Comptr<ID3D11DeviceContext> m_pd3dImmediateContext;	//d3d11设备上下文
	Comptr<IDXGISwapChain> m_pSwapChain;	//d3d11交换链
	Comptr<ID3D11Device1> m_pd3dDevice1;	//d3d11.1设备
	Comptr<ID3D11DeviceContext1> m_pd3dImmediateContext1;	//d3d11.1设备上下文
	Comptr<IDXGISwapChain1> m_pSwapChain1;		//d3d11.1交换链

	Comptr<ID3D11Texture2D> m_pDepthSthencilBuffer;	//深度模板缓冲区
	Comptr<ID3D11RenderTargetView> m_pRenderTargetView;	//渲染目标视图
	Comptr<ID3D11DepthStencilView> m_pDepthStencilView;	//深度模板视图
	D3D11_VIEWPORT m_ScreenViewport;	//视口	

	std::wstring m_MainWndCaption;	//主窗口标题

	int m_ClientWidth;
	int m_ClientHeight;
	
};