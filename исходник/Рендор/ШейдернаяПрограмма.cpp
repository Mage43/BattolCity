#include "������������������.h"

#include <iostream>

namespace ������ {
	������������������::������������������(const std::string& ���������������, const std::string& �����������������)
	{
		
		GLint �������������������� = 0 ;
		if (!���������������(���������������, GL_VERTEX_SHADER, ��������������������))
		{
			std::cerr << "��������� ������ ������ �� ����� ����������" << std::endl;
			return;
		}

		GLint ���������������������� = 0;
		if (!���������������(�����������������, GL_FRAGMENT_SHADER, ����������������������))
		{
			std::cerr << "����������� ������ ������ �� ����� ����������" << std::endl;
			glDeleteShader(��������������������);
			return;
		}

		����_����� = glCreateProgram();
		glAttachShader(����_�����, ��������������������);
		glAttachShader(����_�����, ����������������������);
		glLinkProgram(����_�����);

		GLint �����  ;
		glGetProgramiv(����_�����, GL_LINK_STATUS, &�����);
		if (!�����)
		{
			GLchar ��������[1024];
			glGetShaderInfoLog(����_�����, 1024, nullptr, ��������);
			std::cerr << "������::������:������ �� ����� ��������\n"<< �������� << std::endl;
			
		}
		else
		{
			��������_��������������� = true;
		}
		
		glDeleteShader(��������������������);
		glDeleteShader(����������������������);
	}

	bool ������������������::���������������(const std::string& ��������, const GLenum ����������, GLint &������������)
	{
		������������ = glCreateShader(����������);
		const char* ��� = ��������.c_str();
		glShaderSource(������������, 1, &���, nullptr);
		glCompileShader(������������);


		GLint �����;
		glGetShaderiv(������������, GL_COMPILE_STATUS, &�����);
		if (!�����)
		{
			GLchar ��������[1024];
			glGetShaderInfoLog(������������, 1024, nullptr, ��������);
			std::cerr << "������::������:������ �� ����� ����������\n"<< ��������<<std::endl;
			return false;
		}
		return true;
	}

	������������������::~������������������()
	{
		glDeleteProgram(����_�����);
	}

	void ������������������::���() const
	{
		glUseProgram(����_�����);
	}
	������������������& ������������������::operator=( ������������������&& ������������������) noexcept
	{
		glDeleteProgram(����_�����);
		����_����� = ������������������.����_�����;
		��������_��������������� = ������������������.��������_���������������;


		������������������.����_����� = 0;
		������������������.��������_��������������� = false;
		return* this; 
	}

	 ������������������::������������������ (������������������&& ������������������) noexcept
	{
		 ����_����� = ������������������.����_�����;
		 ��������_��������������� = ������������������.��������_���������������;


		 ������������������.����_����� = 0;
		 ������������������.��������_��������������� = false;
	}
}
