#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Рендор/ШейдернаяПрограмма.h"

#include <iostream>

GLfloat точка[] = {
  0.0f, 0.5f, 0.0f,
  0.5f,-0.5f, 0.0f,
 -0.5f,-0.5f, 0.0f
};

GLfloat цвет[] = {
    1.0f, 0.0f, 0.0f,
    0.0f, 1.0f, 0.0f,
    0.0f, 0.0f, 1.0f
};

const char* вершинный_шейдер =
"#version 460\n"
"layout(location = 0) in vec3 vertex_position;"
"layout(location = 1) in vec3 vertex_color;"
"out vec3 color;"
"void main() {"
"   color = vertex_color;"
"   gl_Position = vec4(vertex_position, 1.0);"
"}";

const char* фрагментный_шейдер =
"#version 460\n"
"in vec3 color ;"
"out vec4 frag_color;"
"void main() {"
"   frag_color = vec4(color, 1.0);"
"}";




int g_windowРазмерX = 640;
int g_windowРазмерY = 480;

void glfwОбратноеВызовРазмераОкна(GLFWwindow* window, int шрена, int высота)
{
    g_windowРазмерX = шрена;
    g_windowРазмерY = высота;
    glViewport(0, 0, g_windowРазмерX, g_windowРазмерY);
}

void glfwОбратноеВызовНажатие(GLFWwindow* window, int клава, int сконированиеКода, int действовать, int режим)
{
    if (клава == GLFW_KEY_ESCAPE && сконированиеКода == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, GL_TRUE);
    }
}


int main(void)
{
    setlocale(LC_ALL, "rus");



    /* Initialize the library */
    if (!glfwInit())
    {
        std::cout << "не отрылось файл" << std::endl;
        return -1;
    }
    /*Версия major,minor и  функциия опинчии */
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    /* Create a windowed mode window and its OpenGL context */
    GLFWwindow* window = glfwCreateWindow(g_windowРазмерX, g_windowРазмерY, "BattolCeti", nullptr, nullptr);
    if (!window)
    {
        std::cout << "ошибка при открытия окна " << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwSetWindowSizeCallback(window, glfwОбратноеВызовРазмераОкна);
    glfwSetKeyCallback(window, glfwОбратноеВызовНажатие);

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    if (!gladLoadGL())
    {
        std::cout << "Не могу загрузить GLAD" << std::endl;
        return -1;
    }
    /*вод ркндор версия OpenGL */
    std::cout << "Рендор: " << glGetString(GL_RENDERER) << std::endl;
    std::cout << "OpenGL версия: " << glGetString(GL_VERSION) << std::endl;



    glClearColor(1, 1, 0, 1);

    std::string ВершинныйШейдер(вершинный_шейдер);
    std::string ФрагментныйПрограмма(фрагментный_шейдер);
    Рендор::ШейдернаяПрограмма шейдернаяПрограмма(ВершинныйШейдер, ФрагментныйПрограмма);
    
    if (!шейдернаяПрограмма.возКапеляции())
    {
        std::cerr << "Не могу создать ШейдернаяПрограмма " << std::endl;
        return -1;
    }

    GLuint точка_vbo = 0;
    glGenBuffers(1, &точка_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, точка_vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(точка), точка, GL_STATIC_DRAW);



    GLuint цвет_vbo = 0;
    glGenBuffers(1, &цвет_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, цвет_vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(цвет), цвет, GL_STATIC_DRAW);


    GLuint vao = 0;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, точка_vbo);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);

    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, цвет_vbo);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, nullptr);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);


        шейдернаяПрограмма.вкл();
        glBindVertexArray(vao);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
