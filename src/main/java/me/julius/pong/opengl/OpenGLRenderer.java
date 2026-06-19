package me.julius.pong.opengl;

import me.julius.pong.Renderer;
import me.julius.pong.game.PongLogic;
import org.lwjgl.glfw.GLFW;
import org.lwjgl.opengl.GL;

import static org.lwjgl.opengl.GL11.*;

public class OpenGLRenderer implements Renderer {

    private long window;

    @Override
    public void init() {
        GLFW.glfwInit();
        window = GLFW.glfwCreateWindow(800, 600, "Pong – OpenGL", 0, 0);
        GLFW.glfwMakeContextCurrent(window);
        GL.createCapabilities();
    }

    @Override
    public boolean loop() {
        if (GLFW.glfwWindowShouldClose(window)) return false;

        glClear(GL_COLOR_BUFFER_BIT);

        PongLogic.update();

        glBegin(GL_QUADS);
        glVertex2f(PongLogic.x - 0.05f, PongLogic.y - 0.05f);
        glVertex2f(PongLogic.x + 0.05f, PongLogic.y - 0.05f);
        glVertex2f(PongLogic.x + 0.05f, PongLogic.y + 0.05f);
        glVertex2f(PongLogic.x - 0.05f, PongLogic.y + 0.05f);
        glEnd();

        GLFW.glfwSwapBuffers(window);
        GLFW.glfwPollEvents();

        return true;
    }

    @Override
    public void destroy() {
        GLFW.glfwTerminate();
    }
}
