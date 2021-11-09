#include "������.h"


#include "������������������.h"
#include "��������2D.h"

#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace ������ {
	
	������::������(std::shared_ptr <��������2D> ���������,
		           std::shared_ptr< ������������������>�������������������,
		           std::string ���������������������������,
		     const glm::vec2& �������,
	         const glm::vec2& ������,
		     const float �������)
		: �_���������(std::move(���������))
		, �_�������������������(std::move(�������������������))
		, �_�������(�������)
		, �_������(������)
		, �_�������(�������)
	{
        const GLfloat  �������������������[] = {
        /* 1---2
		   | / |
		   0---3
		*/ 

        //X     Y
         0.f, 0.f, 
         0.f, 1.f, 
         1.f, 1.f,
		 1.f, 0.f
		};

		auto ������������������� = �_���������->���������������������������(std::move(���������������������������));


		const GLfloat �����������������[] = {
			   //U     V	
			   �������������������.����������UV.x, �������������������.����������UV.y,
			   �������������������.����������UV.x, �������������������.�����������UV.y,
			   �������������������.�����������UV.x, �������������������.�����������UV.y,
               �������������������.�����������UV.x, �������������������.����������UV.y
			   
		};

		const GLuint ������[] = {
			0, 1, 2,
			2, 3, 0
		};

		glGenVertexArrays(1, &�_VAO);
		glBindVertexArray(�_VAO);

		�_����������������������.����(�������������������, 2 * 4 * sizeof(GLfloat));
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, nullptr);

		�_�����������������������.����(�����������������, 2 * 4 * sizeof(GLfloat));
		glEnableVertexAttribArray(1);
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, nullptr);

		�_������������.����(������, 6 * sizeof(GLuint));

		glBindBuffer(GL_ARRAY_BUFFER, 0);       
		glBindVertexArray(0);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0); // ����������� ������ �������� *�����* 

	}
	 ������::~������()
	{
		glDeleteVertexArrays(1, &�_VAO);
	}

	void ������::���������������()const
	{
		�_�������������������->���();

		glm::mat4 ������(1.f);

		������ = glm::translate(������, glm::vec3(�_�������, 0.f));
		������ = glm::translate(������, glm::vec3(0.5f * �_������.x, 0.5f * �_������.y, 0.f));
		������ = glm::rotate(������, glm::radians(�_�������), glm::vec3(0.f, 0.f, 1.f));
		������ = glm::translate(������, glm::vec3(-0.5f * �_������.x, -0.5f * �_������.y, 0.f));
		������ = glm::scale(������, glm::vec3(�_������, 1.f));

		glBindVertexArray(�_VAO);
		�_�������������������->����������������4("modelMat", ������);

		glActiveTexture(GL_TEXTURE0);
		�_���������->���������();

		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
		glBindVertexArray(0);
	}


	void ������::����������������(const glm::vec2& �������)
	{
		�_������� = �������;

	}


	void ������::���������������(const glm::vec2& ������)
	{
		�_������ = ������;
	}


	void ������::����������������(const  float �������)
	{
		�_������� = �������;

	}


	
}