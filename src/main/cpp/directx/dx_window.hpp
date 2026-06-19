#pragma once
#include <windows.h>

class DXWindow {
public:
    static HWND Create(const char* title, int width, int height);
};
