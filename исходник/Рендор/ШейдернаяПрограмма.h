#pragma once

#include <glad/glad.h>
#include <string>
#include <glm/mat4x4.hpp>


namespace ƒвижок–ендеринга {
    class  Ўейдерна€ѕрограмма
    { 
    public:
        Ўейдерна€ѕрограмма(const std::string& ¬ершинныйЎейдер, const std::string& ‘рагментныйЎейдер);
        ~Ўейдерна€ѕрограмма();
        bool воз апел€ции()const { return проверка_ омпел€цииЎедор; }
        void вкл() const;
        void сохраниеть«начение(const std::string& им€, GLint значение);
        void сохранитьћатрицу4(const std::string& им€, glm::mat4 & матрица);

        Ўейдерна€ѕрограмма() = delete;
        Ўейдерна€ѕрограмма(Ўейдерна€ѕрограмма&) = delete;
        Ўейдерна€ѕрограмма& operator=(const Ўейдерна€ѕрограмма&) = delete;
        Ўейдерна€ѕрограмма& operator=( Ўейдерна€ѕрограмма&& Ўейдерна€ѕрограмма) noexcept;
        Ўейдерна€ѕрограмма(Ўейдерна€ѕрограмма&& Ўейдерна€ѕрограмма) noexcept;

    private:
        bool сотворитьЎейдер(const std::string& источник, const GLenum “ипЎейдера, GLint& шейдерајдрес);

        bool проверка_ омпел€цииЎедор = false;
        GLuint идиф_шедор = 0 ;
    };
}
