cmake_minimum_required(VERSION 3.20)
project(directx_renderer LANGUAGES CXX)

# Output DLL
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# C++ Standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Create temp directory for OBJ files
file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/build_temp)

# JNI include paths
find_package(JNI REQUIRED)

include_directories(
    ${JNI_INCLUDE_DIRS}
    ${CMAKE_CURRENT_SOURCE_DIR}
)

# Shader copy
file(COPY shaders DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})

# Source files
set(SOURCES
    dx_window.cpp
    dx_device.cpp
    dx_pipeline.cpp
    dx_renderer.cpp
)

# Build DLL
add_library(directx_renderer SHARED ${SOURCES})

# Force .obj output directory
target_compile_options(directx_renderer PRIVATE /Fo${CMAKE_BINARY_DIR}/build_temp/)

# Link DirectX libs
target_link_libraries(directx_renderer
    d3d11
    dxgi
    D3DCompiler
    user32
    gdi32
)
