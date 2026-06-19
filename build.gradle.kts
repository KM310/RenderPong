plugins {
    id("java")
    application
}

group = "me.julius.pong"
version = "1.0-SNAPSHOT"

repositories {
    mavenCentral()
}

val lwjglVersion = "3.3.3"
val lwjglNatives = "natives-windows"

dependencies {
    implementation("org.lwjgl:lwjgl:$lwjglVersion")
    implementation("org.lwjgl:lwjgl:$lwjglVersion:$lwjglNatives")

    implementation("org.lwjgl:lwjgl-opengl:$lwjglVersion")
    implementation("org.lwjgl:lwjgl-opengl:$lwjglVersion:$lwjglNatives")

    implementation("org.lwjgl:lwjgl-glfw:$lwjglVersion")
    implementation("org.lwjgl:lwjgl-glfw:$lwjglVersion:$lwjglNatives")

    implementation("org.lwjgl:lwjgl-stb:$lwjglVersion")
    implementation("org.lwjgl:lwjgl-stb:$lwjglVersion:$lwjglNatives")

    implementation("org.lwjgl:lwjgl-vulkan:$lwjglVersion")

    testImplementation(platform("org.junit:junit-bom:6.0.0"))
    testImplementation("org.junit.jupiter:junit-jupiter")
}

application {
    mainClass.set("me.julius.pong.Main")
}

tasks.test {
    useJUnitPlatform()
}

java {
    toolchain {
        languageVersion.set(JavaLanguageVersion.of(21))
    }
}
