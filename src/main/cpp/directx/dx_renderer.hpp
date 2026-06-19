#pragma once
#include <jni.h>

class DXRenderer {
public:
    static void Init();
    static bool Loop(JNIEnv* env);
    static void Destroy();
};
