#include "Спрайт.h"


#include "ШейдернаяПрограмма.h"
#include "Текстуры2D.h"

#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace Рендор {
	
	Спрайт::Спрайт(const std::shared_ptr <Текстуры2D> пТекстуры,
		const std::shared_ptr< ШейдернаяПрограмма>пШейдернаяПрограмма,
		const glm::vec2& позиция,
		const glm::vec2& размер,
		const float повород)
		: п_пТекстуры(std::move(пТекстуры))
		, п_пШейдернаяПрограмма(std::move(пШейдернаяПрограмма))
		, п_позиция(позиция)
		, п_размер(размер)
		, п_повород(повород)
	{
        const GLfloat  вершинныйКоординаты[] = {
        //X     Y
         0.f, 0.f, 
         0.f, 1.f, 
         1.f, 1.f, 

		 1.f, 1.f,
		 1.f, 0.f,
		 0.f, 0.f
      
		};

		GLfloat ТекстурКоординаты[] = {
			   //U     V	
			   0.f, 0.f,
		       0.f, 1.f,
		       1.f, 1.f,

		       1.f, 1.f,
		       1.f, 0.f,
		       0.f, 0.f
		};

		glGenVertexArrays(1, &п_VAO);
		glBindVertexArray(п_VAO);

		glGenBuffers(1, &п_вершинныйКоординатыVBO);
		glBindBuffer(GL_ARRAY_BUFFER,п_вершинныйКоординатыVBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(вершинныйКоординаты), &вершинныйКоординаты, GL_STATIC_DRAW);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, nullptr);


		glGenBuffers(1, &п_ТекстурКоординатыVBO);
		glBindBuffer(GL_ARRAY_BUFFER, п_ТекстурКоординатыVBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(ТекстурКоординаты), &ТекстурКоординаты, GL_STATIC_DRAW);
		glEnableVertexAttribArray(1);
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, nullptr);

		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);

	}
	 

	void Спрайт::отопрожениеСпра()const
	{
		п_пШейдернаяПрограмма->вкл();

		glm::mat4 модель(1.f);

		модель = glm::translate(модель, glm::vec3(п_позиция, 0.f));
		модель = glm::translate(модель, glm::vec3(0.5f * п_размер.x, 0.5f * п_размер.y, 0.f));
		модель = glm::rotate(модель, glm::radians(п_повород), glm::vec3(0.f, 0.f, 1.f));
		модель = glm::translate(модель, glm::vec3(-0.5f * п_размер.x, -0.5f * п_размер.y, 0.f));
		модель = glm::scale(модель, glm::vec3(п_размер, 1.f));

		glBindVertexArray(п_VAO);
		п_пШейдернаяПрограмма->сохранитьМатрицу4("modelMat", модель);

		glActiveTexture(GL_TEXTURE0);
		п_пТекстуры->связывать();
		glDrawArrays(GL_TRIANGLES, 0, 6);
		glBindVertexArray(0);
	}


	void Спрайт::сохранитьПозицию(const glm::vec2& позиция)
	{
		п_позиция = позиция;

	}


	void Спрайт::сохранитьРазмер(const glm::vec2& размер)
	{
		п_размер = размер;
	}


	void Спрайт::сохранитьПовород(const  const float повород)
	{
		п_повород = повород;

	}


	Спрайт::~Спрайт()
	{
        glDeleteBuffers(1, &п_вершинныйКоординатыVBO);
		glDeleteBuffers(1, &п_ТекстурКоординатыVBO);
		glDeleteVertexArrays(1, &п_VAO);
	}
}