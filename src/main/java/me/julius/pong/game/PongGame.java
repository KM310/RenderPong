package me.julius.pong.game;

import me.julius.pong.*;
import me.julius.pong.opengl.OpenGLRenderer;
import me.julius.pong.vulkan.VulkanRenderer;
import me.julius.pong.directx.DirectXRenderer;

public class PongGame {

    public static RendererType selectedRenderer;

    public static void startGame() {

        Renderer renderer = switch (selectedRenderer) {
            case OPENGL -> new OpenGLRenderer();
            case VULKAN -> new VulkanRenderer();
            case DIRECTX -> new DirectXRenderer();
        };

        renderer.init();

        while (renderer.loop()) { }

        renderer.destroy();
    }
}
