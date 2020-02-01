//***************************************************************************************
// d3dUtil.h by X_Jun(MKXJun) (C) 2018-2019 All Rights Reserved.
// Licensed under the MIT License.
//
// D3Dʵ�ù��߼�
// Direct3D utility tools.
//***************************************************************************************

#ifndef D3DUTIL_H
#define D3DUTIL_H

#include <d3d11_1.h>			// �Ѱ���Windows.h
#include <DirectXCollision.h>	// �Ѱ���DirectXMath.h
#include <DirectXPackedVector.h>
#include <DirectXColors.h>
#include <d3dcompiler.h>
#include <vector>
#include <string>

//
// �����
//

// Ĭ�Ͽ���ͼ�ε�����������
// �������Ҫ����ܣ���ͨ��ȫ���ı��滻����ֵ����Ϊ0
#ifndef GRAPHICS_DEBUGGER_OBJECT_NAME
#define GRAPHICS_DEBUGGER_OBJECT_NAME (1)
#endif

// ��ȫCOM����ͷź�
#define SAFE_RELEASE(p) { if ((p)) { (p)->Release(); (p) = nullptr; } }

//
// ����������غ���
//

// ------------------------------
// D3D11SetDebugObjectName����
// ------------------------------
// ΪD3D�豸���������Ķ�����ͼ�ε����������ö�����
// [In]ID3D11DeviceChild	D3D11�豸�������Ķ���
// [In]name					������
template<UINT TNameLength>
inline void D3D11SetDebugObjectName(_In_ ID3D11DeviceChild* resource, _In_ const char(&name)[TNameLength])
{
#if (defined(DEBUG) || defined(_DEBUG)) && (GRAPHICS_DEBUGGER_OBJECT_NAME)
	resource->SetPrivateData(WKPDID_D3DDebugObjectName, TNameLength - 1, name);
#else
	UNREFERENCED_PARAMETER(resource);
	UNREFERENCED_PARAMETER(name);
#endif
}

// ------------------------------
// DXGISetDebugObjectName����
// ------------------------------
// ΪDXGI������ͼ�ε����������ö�����
// [In]IDXGIObject			DXGI����
// [In]name					������
template<UINT TNameLength>
inline void DXGISetDebugObjectName(_In_ IDXGIObject* resource, _In_ const char(&name)[TNameLength])
{
#if (defined(DEBUG) || defined(_DEBUG)) && (GRAPHICS_DEBUGGER_OBJECT_NAME)
	resource->SetPrivateData(WKPDID_D3DDebugObjectName, TNameLength - 1, name);
#else
	UNREFERENCED_PARAMETER(resource);
	UNREFERENCED_PARAMETER(name);
#endif
}

//
// ��ɫ��������غ���
//

// ------------------------------
// CreateShaderFromFile����
// ------------------------------
// [In]csoFileNameInOut ����õ���ɫ���������ļ�(.cso)������ָ��������Ѱ�Ҹ��ļ�����ȡ
// [In]hlslFileName     ��ɫ�����룬��δ�ҵ���ɫ���������ļ��������ɫ������
// [In]entryPoint       ��ڵ�(ָ����ʼ�ĺ���)
// [In]shaderModel      ��ɫ��ģ�ͣ���ʽΪ"*s_5_0"��*����Ϊc,d,g,h,p,v֮һ
// [Out]ppBlobOut       �����ɫ����������Ϣ
HRESULT CreateShaderFromFile(
	const WCHAR* csoFileNameInOut,
	const WCHAR* hlslFileName,
	LPCSTR entryPoint,
	LPCSTR shaderModel,
	ID3DBlob** ppBlobOut);




#endif
