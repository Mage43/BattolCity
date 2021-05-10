#pragma once 

#include <glad/glad.h>
#include <glm/vec2.hpp>

#include <memory>
#include <string>

namespace ������{

	class ��������2D;
	class ������������������;

	class ������
	{
	 public:
		 ������(const std::shared_ptr <��������2D> ���������, 
			    const std::shared_ptr< ������������������>�������������������,  
			    const std::string ���������������������������,
			    const glm::vec2& ������� = glm::vec2(0.f), 
			    const glm::vec2& ������ = glm::vec2(1.f),
		        const float ������� = 0.f);
		
		~������();

        ������(const ������&) = delete;
		������& operator = (const ������&) = delete;

		void ���������������()const;
		void ����������������(const glm::vec2& �������);
		void ���������������(const glm::vec2& ������);
		void ����������������(const  float �������);


	private:
		std::shared_ptr <��������2D> �_���������;
		std::shared_ptr< ������������������>�_�������������������;
		glm::vec2 �_�������;
		glm::vec2 �_������;
		float  �_�������;
		GLuint �_VAO;
		GLuint �_�������������������VBO;
		GLuint �_�����������������VBO;

	};
}