#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

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

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
