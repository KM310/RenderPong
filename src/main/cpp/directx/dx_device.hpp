#pragma once
#include <d3d11.h>
#include <dxgi.h>

class DXDevice {
public:
    static bool Init(HWND hwnd);
    static void Cleanup();

    static ID3D11Device* device;
    static ID3D11DeviceContext* context;
    static IDXGISwapChain* swapChain;
    static ID3D11RenderTargetView* rtv;
};
