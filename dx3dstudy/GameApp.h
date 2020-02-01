#pragma once
#ifndef GAMEAPP_H
#define GAMEAPP_H
#include "App.h"

class GameApp :public App
{
public:
	struct VertexPosColor
	{
		DirectX::XMFLOAT3 pos;
		DirectX::XMFLOAT4 color;
		static const D3D11_INPUT_ELEMENT_DESC inputLayout[2];
	};

	struct ConstantBuffer
	{
		DirectX::XMMATRIX world;
		DirectX::XMMATRIX view;
		DirectX::XMMATRIX proj;
	};

public:
	GameApp(HINSTANCE hInstance);
	~GameApp();

	bool Init();
	void OnResize();
	void UpdateScene(float dt);
	void DrawScene();

private:
	bool InitEffect();
	bool InitResource();
	
private:
	Comptr<ID3D11InputLayout> m_pVertexLayout;	//顶点输入布局
	Comptr<ID3D11Buffer> m_pVertexBuffer;		//顶点缓冲区
	Comptr<ID3D11Buffer> m_pIndexBuffer;		//索引缓冲区
	Comptr<ID3D11Buffer> m_pConstantBuffer;		//常量缓冲区
	Comptr<ID3D11VertexShader> m_pVertexShader;	//顶点着色器
	Comptr<ID3D11PixelShader> m_pPixelShader;	//像素着色器
	ConstantBuffer m_CBuffer;	//修改GPU常量缓冲区的变量
};

#endif // !GAMEAPP_H
