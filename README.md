# RenderPong – Native DirectX Renderer + Java Game VM

RenderPong is a hybrid rendering project that combines a **Java-based game VM** with a **native DirectX 11 rendering engine** written in C++.  
The game logic (Pong) runs entirely inside the JVM, while the renderer is implemented as a **native DLL** connected through **JNI**.

This project serves as the foundation for a modular rendering engine that can later support OpenGL, Vulkan, or software rendering backends.

---

## 🚀 Features

- 🖥️ **Native DirectX 11 renderer (C++)**
- 🔗 **JNI bridge** between Java and C++
- 🎮 **Java-based game VM**
- 🧱 Clean engine modules:
  - Window
  - Device
  - Pipeline
  - Renderer
- 🎨 HLSL shaders (vertex + pixel)
- 🔄 Dynamic vertex buffer updates
- ⚙️ CMake build system for the native DLL
- 🧩 Swappable renderer architecture (DX / GL / Vulkan [Only Stub right now] )

## Importent❗ 

- Windows 10/11 Only 
- Requieres JDK 21
- Requires X64_X86
- For Compiling you need CMake and VSC++/MSVC 
