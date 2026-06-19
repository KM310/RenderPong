#include "dx_pipeline.hpp"
#include "dx_device.hpp"
#include <d3dcompiler.h>

ID3D11VertexShader* DXPipeline::vs = nullptr;
ID3D11PixelShader* DXPipeline::ps = nullptr;
ID3D11InputLayout* DXPipeline::layout = nullptr;
ID3D11Buffer* DXPipeline::vertexBuffer = nullptr;

bool DXPipeline::Init() {
    ID3DBlob* vsBlob = nullptr;
    ID3DBlob* psBlob = nullptr;

    D3DCompileFromFile(L"src/main/cpp/directx/shaders/vertex.hlsl",
        nullptr, nullptr, "main", "vs_4_0", 0, 0, &vsBlob, nullptr);

    D3DCompileFromFile(L"src/main/cpp/directx/shaders/pixel.hlsl",
        nullptr, nullptr, "main", "ps_4_0", 0, 0, &psBlob, nullptr);

    DXDevice::device->CreateVertexShader(vsBlob->GetBufferPointer(), vsBlob->GetBufferSize(), nullptr, &vs);
    DXDevice::device->CreatePixelShader(psBlob->GetBufferPointer(), psBlob->GetBufferSize(), nullptr, &ps);

    D3D11_INPUT_ELEMENT_DESC layoutDesc[] = {
        {"POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0,
         D3D11_INPUT_PER_VERTEX_DATA, 0}
    };

    DXDevice::device->CreateInputLayout(
        layoutDesc, 1,
        vsBlob->GetBufferPointer(), vsBlob->GetBufferSize(),
        &layout
    );

    vsBlob->Release();
    psBlob->Release();

    // Ball quad
    float s = 0.05f;
    float verts[] = {
        -s, -s, 0,
        -s,  s, 0,
         s, -s, 0,
         s,  s, 0
    };

    D3D11_BUFFER_DESC bd{};
    bd.Usage = D3D11_USAGE_DYNAMIC;
    bd.ByteWidth = sizeof(verts);
    bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;
    bd.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;

    D3D11_SUBRESOURCE_DATA init{};
    init.pSysMem = verts;

    DXDevice::device->CreateBuffer(&bd, &init, &vertexBuffer);

    return true;
}

void DXPipeline::UpdateBall(float x, float y) {
    float s = 0.05f;
    float verts[] = {
        x - s, y - s, 0,
        x - s, y + s, 0,
        x + s, y - s, 0,
        x + s, y + s, 0
    };

    D3D11_MAPPED_SUBRESOURCE map{};
    DXDevice::context->Map(vertexBuffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &map);
    memcpy(map.pData, verts, sizeof(verts));
    DXDevice::context->Unmap(vertexBuffer, 0);
}

void DXPipeline::Draw() {
    float clear[4] = {0.1f, 0.2f, 0.4f, 1.0f};
    DXDevice::context->OMSetRenderTargets(1, &DXDevice::rtv, nullptr);
    DXDevice::context->ClearRenderTargetView(DXDevice::rtv, clear);

    UINT stride = sizeof(float) * 3;
    UINT offset = 0;

    DXDevice::context->IASetVertexBuffers(0, 1, &vertexBuffer, &stride, &offset);
    DXDevice::context->IASetInputLayout(layout);
    DXDevice::context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP);

    DXDevice::context->VSSetShader(vs, nullptr, 0);
    DXDevice::context->PSSetShader(ps, nullptr, 0);

    DXDevice::context->Draw(4, 0);

    DXDevice::swapChain->Present(1, 0);
}

void DXPipeline::Cleanup() {
    if (vertexBuffer) vertexBuffer->Release();
    if (layout) layout->Release();
    if (vs) vs->Release();
    if (ps) ps->Release();
}
