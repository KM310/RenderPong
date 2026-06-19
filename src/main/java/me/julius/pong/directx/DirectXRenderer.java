package me.julius.pong.directx;

import me.julius.pong.Renderer;
import me.julius.pong.game.PongLogic;

public class DirectXRenderer implements Renderer {

    static {
        System.load("C:\\Users\\Julius\\Downloads\\RenderPong\\build\\libs\\directx_renderer.dll");
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
        PongLogic.update(); // Ball bewegen
        return loopNative(); // DX zeichnet
    }

    @Override
    public void destroy() {
        destroyNative();
    }
}


