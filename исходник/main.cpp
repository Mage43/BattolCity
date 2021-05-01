#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

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
