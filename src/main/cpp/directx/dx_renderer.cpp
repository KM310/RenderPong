#include "dx_renderer.hpp"
#include "dx_window.hpp"
#include "dx_device.hpp"
#include "dx_pipeline.hpp"

static HWND hwnd = nullptr;

extern "C" {

JNIEXPORT void JNICALL Java_me_julius_pong_directx_DirectXRenderer_initNative
  (JNIEnv*, jobject) {
    hwnd = DXWindow::Create("DirectX Pong", 800, 600);
    ShowWindow(hwnd, SW_SHOW);

    DXDevice::Init(hwnd);
    DXPipeline::Init();
}

JNIEXPORT jboolean JNICALL Java_me_julius_pong_directx_DirectXRenderer_loopNative
  (JNIEnv* env, jobject) {

    jclass logic = env->FindClass("me/julius/pong/game/PongLogic");
    jfieldID xField = env->GetStaticFieldID(logic, "x", "F");
    jfieldID yField = env->GetStaticFieldID(logic, "y", "F");

    float x = env->GetStaticFloatField(logic, xField);
    float y = env->GetStaticFloatField(logic, yField);

    DXPipeline::UpdateBall(x, y);
    DXPipeline::Draw();

    MSG msg;
    while (PeekMessageA(&msg, nullptr, 0, 0, PM_REMOVE)) {
        if (msg.message == WM_QUIT) return JNI_FALSE;
        TranslateMessage(&msg);
        DispatchMessageA(&msg);
    }

    return JNI_TRUE;
}

JNIEXPORT void JNICALL Java_me_julius_pong_directx_DirectXRenderer_destroyNative
  (JNIEnv*, jobject) {
    DXPipeline::Cleanup();
    DXDevice::Cleanup();
}

}
