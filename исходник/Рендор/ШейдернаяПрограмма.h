#pragma once

#include <glad/glad.h>
#include <string>

namespace Рендор {
    class  ШейдернаяПрограмма
    { 
    public:
        ШейдернаяПрограмма(const std::string& ВершинныйШейдер, const std::string& ФрагментныйШейдер);
        ~ШейдернаяПрограмма();
        bool возКапеляции()const { return проверка_КомпеляцииШедор; }
        void вкл() const;

        ШейдернаяПрограмма() = delete;
        ШейдернаяПрограмма(ШейдернаяПрограмма&) = delete;
        ШейдернаяПрограмма& operator=(const ШейдернаяПрограмма&) = delete;
        ШейдернаяПрограмма& operator=( ШейдернаяПрограмма&& ШейдернаяПрограмма) noexcept;
        ШейдернаяПрограмма(ШейдернаяПрограмма&& ШейдернаяПрограмма) noexcept;

    private:
        bool сотворитьШейдер(const std::string& источник, const GLenum ТипШейдера, GLint& шейдераАдрес);

        bool проверка_КомпеляцииШедор = false;
        GLuint идиф_шедор = 0 ;
    };
}
