#pragma once

#include <glad/glad.h>
#include <string>
#include <glm/mat4x4.hpp>


namespace ���������������� {
    class  ������������������
    { 
    public:
        ������������������(const std::string& ���������������, const std::string& �����������������);
        ~������������������();
        bool ������������()const { return ��������_���������������; }
        void ���() const;
        void ������������������(const std::string& ���, GLint ��������);
        void ����������������4(const std::string& ���, glm::mat4 & �������);

        ������������������() = delete;
        ������������������(������������������&) = delete;
        ������������������& operator=(const ������������������&) = delete;
        ������������������& operator=( ������������������&& ������������������) noexcept;
        ������������������(������������������&& ������������������) noexcept;

    private:
        bool ���������������(const std::string& ��������, const GLenum ����������, GLint& ������������);

        bool ��������_��������������� = false;
        GLuint ����_����� = 0 ;
    };
}
