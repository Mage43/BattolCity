#include "��������2D.h"


namespace ������ {
	��������2D::��������2D(const GLint ������, GLint ������,
		const unsigned char* ������,
		const unsigned int ����� ,
		const GLenum ������� ,
		const GLenum �������������� )
		:�_������(������)
		,�_������(������)
	{
		switch (�����)
		{
		case 4:
			�_����� = GL_RGBA;
			break;
		case 3:
			�_����� = GL_RGB;
			break;
		default:
			�_����� = GL_RGB;
			break;
		}

		glGenTextures(1, &�_�������);
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, �_�������);
		glTexImage2D(GL_TEXTURE_2D, 0, �_�����, �_������, �_������, 0, �_�����, GL_UNSIGNED_BYTE, ������);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, ��������������);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, ��������������);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, �������);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, �������);
		glGenerateMipmap(GL_TEXTURE_2D);
		
		glBindTexture(GL_TEXTURE_2D, 0);

	}
	��������2D& ��������2D::operator = (��������2D&& ��������2D)
	{
		glDeleteTextures(1, &�_�������);
		�_������� = ��������2D.�_�������;
		��������2D.�_������� = 0;
		�_����� = ��������2D.�_�����;
		�_������ = ��������2D.�_������;
		�_������ = ��������2D.�_������;
		return*this;
	}


	��������2D::��������2D(��������2D&& ��������2D)
	{
		�_������� =  ��������2D.�_�������;
		��������2D.�_������� = 0;
		�_����� = ��������2D.�_�����;
		�_������ = ��������2D.�_������;
		�_������ = ��������2D.�_������;

	}


	��������2D::~��������2D()
	{
		glDeleteTextures(1, &�_�������);
	}


	void ��������2D::���������()const
	{
		glBindTexture(GL_TEXTURE_2D, �_�������);
	}
}