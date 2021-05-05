#pragma once

#include <glad/glad.h>
#include <string>

namespace ������ {
    class  ������������������
    { 
    public:
        ������������������(const std::string& ���������������, const std::string& �����������������);
        ~������������������();
        bool ������������()const { return ��������_���������������; }
        void ���() const;
        void ������������������(const std::string& ���, GLint ��������);


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
