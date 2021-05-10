#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/vec2.hpp>
#include <glm/mat4x4.hpp>
#include<glm/gtc/matrix_transform.hpp>

#include <iostream>

#include "–ендор/Ўейдерна€ѕрограмма.h"
#include "–есерсы/–есурсныйћенеджер.h"
#include "–ендор/“екстуры2D.h"
#include "–ендор/—прайт.h"



GLfloat точка[] = {
  0.0f, 50.f, 0.0f,
  50.f,-50.f, 0.0f,
 -50.f,-50.f, 0.0f
};

GLfloat цвет[] = {
    1.0f, 0.0f, 0.0f,
    0.0f, 1.0f, 0.0f,
    0.0f, 0.0f, 1.0f
};

GLfloat “екстур–асположение[] = {
    0.5f, 1.0f, 
    1.0f, 0.0f,
    0.0f, 0.0f
};


glm::ivec2 g_window–азмер(640, 480);


void glfwќбратное¬ызов–азмераќкна(GLFWwindow* window, int шрена, int высота)
{
    g_window–азмер.x = шрена;
    g_window–азмер.y = высота;
    glViewport(0, 0, шрена, высота);
}

void glfwќбратное¬ызовЌажатие(GLFWwindow* window, int клава, int сконирование ода, int действовать, int режим)
{
    if (клава == GLFW_KEY_ESCAPE && сконирование ода == GLFW_PRESS)
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
    /*¬ерси€ major,minor и  функции€ опинчии */
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    /* Create a windowed mode window and its OpenGL context */
    GLFWwindow* window = glfwCreateWindow(g_window–азмер.x, g_window–азмер.y, "BattolCeti", nullptr, nullptr);
    if (!window)
    {
        std::cout << "ошибка при открыти€ окна " << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwSetWindowSizeCallback(window, glfwќбратное¬ызов–азмераќкна);
    glfwSetKeyCallback(window, glfwќбратное¬ызовЌажатие);

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    if (!gladLoadGL())
    {
        std::cout << "Ќе могу загрузить GLAD" << std::endl;
        return -1;
    }
    /*вод ркндор верси€ OpenGL */
    std::cout << "–ендор: " << glGetString(GL_RENDERER) << std::endl;
    std::cout << "OpenGL верси€: " << glGetString(GL_VERSION) << std::endl;



    glClearColor(1, 1, 0, 1);

    //наход€м расположение папки исполнитель
    
    {  –есурсныйћенеджер ресурсныйћенеджер(argv[0]);
        auto загрузитьЎейдонуюѕрограму = ресурсныйћенеджер.загрускаЎедоры("загрускаЎедоры", "ресерсы/Ўейдор/вершина.txt", "ресерсы/Ўейдор/фрогмент.txt");
       if (!загрузитьЎейдонуюѕрограму)
       {
        std::cerr << "Ќе могу создать Ўейдерна€ ѕрограмма: "<<"загрускаЎедоры" << std::endl;
        return -1;
       }

         auto загрузить—прайтЎейдонуюѕрограму = ресурсныйћенеджер.загрускаЎедоры("загруска—прайтЎедоры", "ресерсы/Ўейдор/в—принт.txt", "ресерсы/Ўейдор/ф—принт.txt");
       if (!загрузить—прайтЎейдонуюѕрограму)
       {
        std::cerr << "Ќе могу создать —прайт Ўейдерна€ ѕрограмма: "<<"загруска—прайтЎедоры" << std::endl;
        return -1;
       }

       auto tex = ресурсныйћенеджер.загруска“екстур("чайник","ресерсы/текстуры/mrap_16x16.png");
       
       std::vector<std::string> расположение“екстур»м€ = { "ѕравыземл€","÷еземли","Ћевыйземл€","камень" };
       auto п“екстурјтлос = ресурсныйћенеджер.загруска“екстурјтлос("ѕоумолчанию“екстурјтлос", "ресерсы/текстуры/fdghk.png", std::move(расположение“екстур»м€), 51, 50);

       auto загрузить—прайт = ресурсныйћенеджер.загруска—прайт(" ”ѕ", "ѕоумолчанию“екстурјтлос", "загруска—прайтЎедоры", 100, 100, "камень");

       загрузить—прайт->сохранитьѕозицию(glm::vec2(300, 100));
       
       

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
        glBufferData(GL_ARRAY_BUFFER, sizeof(“екстур–асположение), “екстур–асположение, GL_STATIC_DRAW);

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
        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, nullptr);

        загрузитьЎейдонуюѕрограму->вкл();
        загрузитьЎейдонуюѕрограму->сохраниеть«начение("ацй", 0);

        glm::mat4 модельћатриц_1 = glm::mat4(1.f);
        модельћатриц_1 = glm::translate(модельћатриц_1, glm::vec3(50.f, 50.f, 0.f));

        glm::mat4 модельћатриц_2 = glm::mat4(1.f);
        модельћатриц_2 = glm::translate(модельћатриц_2, glm::vec3(590.f, 50.f, 0.f));


        glm::mat4 проекци€ћатриц = glm::ortho(0.f,static_cast<float>( g_window–азмер.x), 0.f, static_cast<float>(g_window–азмер.y), -100.f, 100.f);

        загрузитьЎейдонуюѕрограму->сохранитьћатрицу4("projectionMat", проекци€ћатриц);

        загрузить—прайтЎейдонуюѕрограму->вкл();
         загрузить—прайтЎейдонуюѕрограму->сохраниеть«начение("ацй", 0);
        загрузить—прайтЎейдонуюѕрограму->сохранитьћатрицу4("projectionMat", проекци€ћатриц);

        
        
        /* Loop until the user closes the window */
        while (!glfwWindowShouldClose(window))
        {
            /* Render here */
            glClear(GL_COLOR_BUFFER_BIT);


            загрузитьЎейдонуюѕрограму->вкл();
            glBindVertexArray(vao);
            tex->св€зывать();
            загрузитьЎейдонуюѕрограму->сохранитьћатрицу4("modelMat", модельћатриц_1);
            glDrawArrays(GL_TRIANGLES, 0, 3);

            загрузитьЎейдонуюѕрограму->сохранитьћатрицу4("modelMat", модельћатриц_2);
            glDrawArrays(GL_TRIANGLES, 0, 3);

            загрузить—прайт->отопрожение—пра();

            /* Swap front and back buffers */
            glfwSwapBuffers(window);

            /* Poll for and process events */
            glfwPollEvents();
        }
    }
    glfwTerminate();
    return 0;
}
