#pragma once 

#include <string>
#include <map>
#include <glad/glad.h>
#include <glm/vec2.hpp>

namespace ���������������� { 
	class ��������2D
	{
	public:

		struct �������������������2D
		{
			glm::vec2 ����������UV;

			glm::vec2 �����������UV;


			�������������������2D(const glm::vec2& _����������UV, const glm::vec2& _�����������UV)
				: ����������UV(_����������UV)

				, �����������UV(_�����������UV)
			{}

			�������������������2D()
				: ����������UV(0.f)

				, �����������UV(1.f)
			{}
		};

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

		void ����������������������������(std::string ���, const glm::vec2& ����������UV, const glm::vec2& �����������UV);
		const �������������������2D& ���������������������������(const std::string& ���) const;
		unsigned int ������() const { return �_������; }
		unsigned int ������() const { return �_������; }

		void ���������()const;

	private:
		GLuint �_�������;
		GLenum �_�����;
		unsigned int �_������;
        unsigned int �_������;

		std::map<std::string, �������������������2D> �_�������������������;
	};

}
