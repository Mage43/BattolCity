#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "������/������������������.h"

#include <iostream>

GLfloat �����[] = {
  0.0f, 0.5f, 0.0f,
  0.5f,-0.5f, 0.0f,
 -0.5f,-0.5f, 0.0f
};

GLfloat ����[] = {
    1.0f, 0.0f, 0.0f,
    0.0f, 1.0f, 0.0f,
    0.0f, 0.0f, 1.0f
};

const char* ���������_������ =
"#version 460\n"
"layout(location = 0) in vec3 vertex_position;"
"layout(location = 1) in vec3 vertex_color;"
"out vec3 color;"
"void main() {"
"   color = vertex_color;"
"   gl_Position = vec4(vertex_position, 1.0);"
"}";

const char* �����������_������ =
"#version 460\n"
"in vec3 color ;"
"out vec4 frag_color;"
"void main() {"
"   frag_color = vec4(color, 1.0);"
"}";




int g_window������X = 640;
int g_window������Y = 480;

void glfw������������������������(GLFWwindow* window, int �����, int ������)
{
    g_window������X = �����;
    g_window������Y = ������;
    glViewport(0, 0, g_window������X, g_window������Y);
}

void glfw��������������������(GLFWwindow* window, int �����, int ����������������, int �����������, int �����)
{
    if (����� == GLFW_KEY_ESCAPE && ���������������� == GLFW_PRESS)
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
        std::cout << "�� �������� ����" << std::endl;
        return -1;
    }
    /*������ major,minor �  �������� ������� */
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    /* Create a windowed mode window and its OpenGL context */
    GLFWwindow* window = glfwCreateWindow(g_window������X, g_window������Y, "BattolCeti", nullptr, nullptr);
    if (!window)
    {
        std::cout << "������ ��� �������� ���� " << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwSetWindowSizeCallback(window, glfw������������������������);
    glfwSetKeyCallback(window, glfw��������������������);

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    if (!gladLoadGL())
    {
        std::cout << "�� ���� ��������� GLAD" << std::endl;
        return -1;
    }
    /*��� ������ ������ OpenGL */
    std::cout << "������: " << glGetString(GL_RENDERER) << std::endl;
    std::cout << "OpenGL ������: " << glGetString(GL_VERSION) << std::endl;



    glClearColor(1, 1, 0, 1);

    std::string ���������������(���������_������);
    std::string ��������������������(�����������_������);
    ������::������������������ ������������������(���������������, ��������������������);
    
    if (!������������������.������������())
    {
        std::cerr << "�� ���� ������� ������������������ " << std::endl;
        return -1;
    }

    GLuint �����_vbo = 0;
    glGenBuffers(1, &�����_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, �����_vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(�����), �����, GL_STATIC_DRAW);



    GLuint ����_vbo = 0;
    glGenBuffers(1, &����_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, ����_vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(����), ����, GL_STATIC_DRAW);


    GLuint vao = 0;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, �����_vbo);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);

    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, ����_vbo);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, nullptr);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);


        ������������������.���();
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
