package me.julius.pong.menu;

import me.julius.pong.RendererType;
import me.julius.pong.game.PongGame;

import javax.swing.*;

public class Menu {

    public static void main(String[] args) {

        JFrame frame = new JFrame("Renderer auswählen");
        frame.setSize(300, 200);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setLayout(null);

        JButton dx = new JButton("DirectX");
        dx.setBounds(50, 20, 200, 30);
        dx.addActionListener(e -> {
            PongGame.selectedRenderer = RendererType.DIRECTX;
            frame.dispose();
            PongGame.startGame();
        });

        JButton gl = new JButton("OpenGL");
        gl.setBounds(50, 60, 200, 30);
        gl.addActionListener(e -> {
            PongGame.selectedRenderer = RendererType.OPENGL;
            frame.dispose();
            PongGame.startGame();
        });

        JButton vk = new JButton("Vulkan");
        vk.setBounds(50, 100, 200, 30);
        vk.addActionListener(e -> {
            PongGame.selectedRenderer = RendererType.VULKAN;
            frame.dispose();
            PongGame.startGame();
        });

        frame.add(dx);
        frame.add(gl);
        frame.add(vk);

        frame.setVisible(true);
    }
}

