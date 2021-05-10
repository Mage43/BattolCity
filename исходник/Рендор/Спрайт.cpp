#include "—прайт.h"


#include "Ўейдерна€ѕрограмма.h"
#include "“екстуры2D.h"

#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace –ендор {
	
	—прайт::—прайт(const std::shared_ptr <“екстуры2D> п“екстуры,
		const std::shared_ptr< Ўейдерна€ѕрограмма>пЎейдерна€ѕрограмма,
		const std::string исходный–асположение“екстур,
		const glm::vec2& позици€,
		const glm::vec2& размер,
		const float повород)
		: п_п“екстуры(std::move(п“екстуры))
		, п_пЎейдерна€ѕрограмма(std::move(пЎейдерна€ѕрограмма))
		, п_позици€(позици€)
		, п_размер(размер)
		, п_повород(повород)
	{
        const GLfloat  вершинный оординаты[] = {
        //X     Y
         0.f, 0.f, 
         0.f, 1.f, 
         1.f, 1.f, 

		 1.f, 1.f,
		 1.f, 0.f,
		 0.f, 0.f
      
		};
		auto расположение“екстур = п“екстуры->получить–асположение“екстур(std::move(исходный–асположение“екстур));


		GLfloat “екстур оординаты[] = {
			   //U     V	
			   расположение“екстур.—лева¬низуUV.x, расположение“екстур.—лева¬низуUV.y,
			   расположение“екстур.—лева¬низуUV.x, расположение“екстур.ѕраво—верхуUV.y,
			   расположение“екстур.ѕраво—верхуUV.x, расположение“екстур.ѕраво—верхуUV.y,

			   расположение“екстур.ѕраво—верхуUV.x, расположение“екстур.ѕраво—верхуUV.y,
			   расположение“екстур.ѕраво—верхуUV.x, расположение“екстур.—лева¬низуUV.y,
			   расположение“екстур.—лева¬низуUV.x, расположение“екстур.—лева¬низуUV.y
		};

		glGenVertexArrays(1, &п_VAO);
		glBindVertexArray(п_VAO);

		glGenBuffers(1, &п_вершинный оординатыVBO);
		glBindBuffer(GL_ARRAY_BUFFER,п_вершинный оординатыVBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(вершинный оординаты), &вершинный оординаты, GL_STATIC_DRAW);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, nullptr);


		glGenBuffers(1, &п_“екстур оординатыVBO);
		glBindBuffer(GL_ARRAY_BUFFER, п_“екстур оординатыVBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(“екстур оординаты), &“екстур оординаты, GL_STATIC_DRAW);
		glEnableVertexAttribArray(1);
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, nullptr);

		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);

	}
	 —прайт::~—прайт()
	{
        glDeleteBuffers(1, &п_вершинный оординатыVBO);
		glDeleteBuffers(1, &п_“екстур оординатыVBO);
		glDeleteVertexArrays(1, &п_VAO);
	}

	void —прайт::отопрожение—пра()const
	{
		п_пЎейдерна€ѕрограмма->вкл();

		glm::mat4 модель(1.f);

		модель = glm::translate(модель, glm::vec3(п_позици€, 0.f));
		модель = glm::translate(модель, glm::vec3(0.5f * п_размер.x, 0.5f * п_размер.y, 0.f));
		модель = glm::rotate(модель, glm::radians(п_повород), glm::vec3(0.f, 0.f, 1.f));
		модель = glm::translate(модель, glm::vec3(-0.5f * п_размер.x, -0.5f * п_размер.y, 0.f));
		модель = glm::scale(модель, glm::vec3(п_размер, 1.f));

		glBindVertexArray(п_VAO);
		п_пЎейдерна€ѕрограмма->сохранитьћатрицу4("modelMat", модель);

		glActiveTexture(GL_TEXTURE0);
		п_п“екстуры->св€зывать();
		glDrawArrays(GL_TRIANGLES, 0, 6);
		glBindVertexArray(0);
	}


	void —прайт::сохранитьѕозицию(const glm::vec2& позици€)
	{
		п_позици€ = позици€;

	}


	void —прайт::сохранить–азмер(const glm::vec2& размер)
	{
		п_размер = размер;
	}


	void —прайт::сохранитьѕовород(const  float повород)
	{
		п_повород = повород;

	}


	
}