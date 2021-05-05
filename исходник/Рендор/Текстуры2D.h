#pragma once 

#include<string>
#include<glad/glad.h>

namespace ������ {
	class ��������2D
	{
	public:
		��������2D(const GLint ������,  GLint ������, 
			       const unsigned char* ������, 
			       const unsigned int ����� = 4, 
			       const GLenum ������� = GL_LINEAR, 
			       const GLenum �������������� = GL_CLAMP_TO_EDGE);
		��������2D() = delete;
		��������2D(const ��������2D&) = delete;
		��������2D& operator = (const ��������2D&) = delete;
		��������2D& operator = (��������2D&& ��������2D);
		��������2D(��������2D&& ��������2D);
		~��������2D();

		void ���������()const;

	private:
		GLuint �_�������;
		GLenum �_�����;
		unsigned int �_������;
        unsigned int �_������;
	};

}
