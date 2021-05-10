#include "������.h"


#include "������������������.h"
#include "��������2D.h"

#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace ������ {
	
	������::������(const std::shared_ptr <��������2D> ���������,
		const std::shared_ptr< ������������������>�������������������,
		const std::string ���������������������������,
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
        //X     Y
         0.f, 0.f, 
         0.f, 1.f, 
         1.f, 1.f, 

		 1.f, 1.f,
		 1.f, 0.f,
		 0.f, 0.f
      
		};
		auto ������������������� = ���������->���������������������������(std::move(���������������������������));


		GLfloat �����������������[] = {
			   //U     V	
			   �������������������.����������UV.x, �������������������.����������UV.y,
			   �������������������.����������UV.x, �������������������.�����������UV.y,
			   �������������������.�����������UV.x, �������������������.�����������UV.y,

			   �������������������.�����������UV.x, �������������������.�����������UV.y,
			   �������������������.�����������UV.x, �������������������.����������UV.y,
			   �������������������.����������UV.x, �������������������.����������UV.y
		};

		glGenVertexArrays(1, &�_VAO);
		glBindVertexArray(�_VAO);

		glGenBuffers(1, &�_�������������������VBO);
		glBindBuffer(GL_ARRAY_BUFFER,�_�������������������VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(�������������������), &�������������������, GL_STATIC_DRAW);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, nullptr);


		glGenBuffers(1, &�_�����������������VBO);
		glBindBuffer(GL_ARRAY_BUFFER, �_�����������������VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(�����������������), &�����������������, GL_STATIC_DRAW);
		glEnableVertexAttribArray(1);
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, nullptr);

		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);

	}
	 ������::~������()
	{
        glDeleteBuffers(1, &�_�������������������VBO);
		glDeleteBuffers(1, &�_�����������������VBO);
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
		glDrawArrays(GL_TRIANGLES, 0, 6);
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