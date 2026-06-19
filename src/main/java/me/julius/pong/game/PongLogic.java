package me.julius.pong.game;

public class PongLogic {

    public static float x = 0.0f;
    public static float y = 0.0f;
    private static float vx = 0.01f;
    private static float vy = 0.015f;

    public static void update() {
        x += vx;
        y += vy;

        if (x > 0.95f || x < -0.95f) vx = -vx;
        if (y > 0.95f || y < -0.95f) vy = -vy;
    }
}
