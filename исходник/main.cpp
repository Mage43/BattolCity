#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/vec2.hpp>
#include <glm/mat4x4.hpp>

#include <iostream>
#include <chrono>


#include "�������/�����������������.h"
#include "����/����.h"
#include "������/������.h"


glm::ivec2 g_window������(640, 480);
���� �_����(g_window������);

void glfw������������������������(GLFWwindow* window, int �����, int ������)
{
    g_window������.x = �����;
    g_window������.y = ������;
    ����������������::������::����������������(�����, ������);

}

void glfw��������������������(GLFWwindow* window, int ����� , int ����������������, int �����������, int �����)
{
    
    if (����� == GLFW_KEY_ESCAPE && ����������� == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, GL_TRUE);
    }
    �_����.����������������(�����, �����������);
}


int main(int argc, char** argv)
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
    GLFWwindow* window = glfwCreateWindow(g_window������.x, g_window������.y, "BattolCeti", nullptr, nullptr);
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
    std::cout << "������: " << ����������������::������::������������������������() << std::endl;
    std::cout << "OpenGL ������: " << ����������������::������::��������������������() << std::endl;


    ����������������::������::��������������������(0,0,0,1);


    //������� ������������ ����� �����������
    
    { 
        �����������������::�����������������������(argv[0]);
        �_����.�������������();

        auto �������������� = std::chrono::high_resolution_clock::now();

        
        /* Loop until the user closes the window */
        while (!glfwWindowShouldClose(window))
        { 
            /* Poll for and process events */
            glfwPollEvents();

            auto ������������ = std::chrono::high_resolution_clock::now();
            uint64_t ������������ = std::chrono::duration_cast<std::chrono::nanoseconds>(������������ - ��������������).count();
            �������������� = ������������;
            �_����.��������(������������);
     
            /* Render here */
            ����������������::������::����������();

            �_����.��������������();

            /* Swap front and back buffers */
            glfwSwapBuffers(window);

           
        }
        �����������������::���������������������();
    }
    glfwTerminate();
    return 0;
}
