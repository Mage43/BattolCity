#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "Рендор/ШейдернаяПрограмма.h"
#include "Ресерсы/РесурсныйМенеджер.h"
#include "Рендор/Текстуры2D.h"



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

GLfloat ТекстурРасположение[] = {
    0.5f, 1.0f, 
    1.0f, 0.0f,
    0.0f, 0.0f
};



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


int main(int argc, char** argv)
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

    //находям расположение папки исполнитель
    
    {  РесурсныйМенеджер ресурсныйМенеджер(argv[0]);
        auto загрузитьШейдонуюПрограму = ресурсныйМенеджер.загрускаШедоры("загрускаШедоры", "ресерсы/Шейдор/вершина.txt", "ресерсы/Шейдор/фрогмент.txt");
       if (!загрузитьШейдонуюПрограму)
       {
        std::cerr << "Не могу создать Шейдерная Программа: "<<"загрускаШедоры" << std::endl;
        return -1;
       }

       auto tex = ресурсныйМенеджер.загрускаТекстур("чайник","ресерсы/текстуры/pngfind.com-boy-png-17357.png");
       
        GLuint точка_vbo = 0;
        glGenBuffers(1, &точка_vbo);
        glBindBuffer(GL_ARRAY_BUFFER, точка_vbo);
        glBufferData(GL_ARRAY_BUFFER, sizeof(точка), точка, GL_STATIC_DRAW);



        GLuint цвет_vbo = 0;
        glGenBuffers(1, &цвет_vbo);
        glBindBuffer(GL_ARRAY_BUFFER, цвет_vbo);
        glBufferData(GL_ARRAY_BUFFER, sizeof(цвет), цвет, GL_STATIC_DRAW);

        GLuint текс_во = 0;
        glGenBuffers(1, &текс_во);
        glBindBuffer(GL_ARRAY_BUFFER, текс_во);
        glBufferData(GL_ARRAY_BUFFER, sizeof(ТекстурРасположение), ТекстурРасположение, GL_STATIC_DRAW);

        GLuint vao = 0;
        glGenVertexArrays(1, &vao);
        glBindVertexArray(vao);

      

        glEnableVertexAttribArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, точка_vbo);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);

        glEnableVertexAttribArray(1);
        glBindBuffer(GL_ARRAY_BUFFER, цвет_vbo);
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, nullptr);

        glEnableVertexAttribArray(2);
        glBindBuffer(GL_ARRAY_BUFFER, текс_во);
        glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 0, nullptr);

        загрузитьШейдонуюПрограму->вкл();
        загрузитьШейдонуюПрограму->сохраниетьЗначение("ацй", 0);

        /* Loop until the user closes the window */
        while (!glfwWindowShouldClose(window))
        {
            /* Render here */
            glClear(GL_COLOR_BUFFER_BIT);


            загрузитьШейдонуюПрограму->вкл();
            glBindVertexArray(vao);
            tex->связывать();
            glDrawArrays(GL_TRIANGLES, 0, 3);

            /* Swap front and back buffers */
            glfwSwapBuffers(window);

            /* Poll for and process events */
            glfwPollEvents();
        }
    }
    glfwTerminate();
    return 0;
}
