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
	Comptr<ID3D11InputLayout> m_pVertexLayout;
	Comptr<ID3D11Buffer> m_pVertexBuffer;
	Comptr<ID3D11VertexShader> m_pVertexShader;
	Comptr<ID3D11PixelShader> m_pPixelShader;
};

#endif // !GAMEAPP_H
