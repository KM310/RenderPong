#pragma once
#include <d3d11.h>

class DXPipeline {
public:
    static bool Init();
    static void Cleanup();

    static ID3D11VertexShader* vs;
    static ID3D11PixelShader* ps;
    static ID3D11InputLayout* layout;
    static ID3D11Buffer* vertexBuffer;

    static void UpdateBall(float x, float y);
    static void Draw();
};
