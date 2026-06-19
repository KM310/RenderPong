package me.julius.pong.vulkan;

import me.julius.pong.Renderer;

public class VulkanRenderer implements Renderer {

    static {
        System.load("C:\\Users\\Julius\\Downloads\\RenderPong\\build\\libs\\vulkan_renderer.dll");
    }

    private native void initNative();
    private native boolean loopNative();
    private native void destroyNative();

    @Override
    public void init() {
        initNative();
    }

    @Override
    public boolean loop() {
        return loopNative();
    }

    @Override
    public void destroy() {
        destroyNative();
    }
}
