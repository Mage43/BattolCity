#pragma once 

#include "¬екторЅуффер.h"
#include "»ндексЅуффер.h"
#include "¬екторћножество.h"

#include <glad/glad.h>
#include <glm/vec2.hpp>

#include <memory>
#include <string>

namespace –ендор{

	class “екстуры2D;
	class Ўейдерна€ѕрограмма;

	class —прайт
	{
	 public:
		 —прайт(std::shared_ptr <“екстуры2D> п“екстуры, 
			    std::shared_ptr< Ўейдерна€ѕрограмма>пЎейдерна€ѕрограмма,  
			    std::string исходный–асположение“екстур,
	 	  const glm::vec2& позици€ = glm::vec2(0.f), 
		  const glm::vec2& размер = glm::vec2(1.f),
		  const float повород = 0.f);
		
		~—прайт();

        —прайт(const —прайт&) = delete;
		—прайт& operator = (const —прайт&) = delete;

		virtual void отопрожение—пра()const;
		        void сохранитьѕозицию(const glm::vec2& позици€);
		        void сохранить–азмер(const glm::vec2& размер);
		        void сохранитьѕовород(const  float повород);


	protected :
		std::shared_ptr <“екстуры2D> п_п“екстуры;
		std::shared_ptr< Ўейдерна€ѕрограмма>п_пЎейдерна€ѕрограмма;
		glm::vec2 п_позици€;
		glm::vec2 п_размер;
		float  п_повород;

		¬екторћножество п_¬екторћножество;
		¬екторЅуффер п_вектор оординатыЅуффер;
		¬екторЅуффер п_“екстур оординатыЅуффер;
		»ндексЅуффер п_индексЅуффер;
	};
}