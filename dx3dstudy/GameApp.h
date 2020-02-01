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
	Comptr<ID3D11InputLayout> m_pVertexLayout;	//�������벼��
	Comptr<ID3D11Buffer> m_pVertexBuffer;		//���㻺����
	Comptr<ID3D11Buffer> m_pIndexBuffer;		//����������
	Comptr<ID3D11Buffer> m_pConstantBuffer;		//����������
	Comptr<ID3D11VertexShader> m_pVertexShader;	//������ɫ��
	Comptr<ID3D11PixelShader> m_pPixelShader;	//������ɫ��
	ConstantBuffer m_CBuffer;	//�޸�GPU�����������ı���
};

#endif // !GAMEAPP_H
