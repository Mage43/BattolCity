#pragma once 

#include "¬екторЅуффер.h"
#include "»ндексЅуффер.h"
#include "¬екторћножество.h"

#include <glad/glad.h>
#include <glm/vec2.hpp>

#include <memory>
#include <string>

namespace ƒвижок–ендеринга{

	class “екстуры2D;
	class Ўейдерна€ѕрограмма;

	class —прайт
	{
	 public:
		 —прайт(std::shared_ptr <“екстуры2D> п“екстуры, 
			    std::shared_ptr< Ўейдерна€ѕрограмма>пЎейдерна€ѕрограмма,  
			    std::string исходный–асположение“екстур);
		
		~—прайт();

        —прайт(const —прайт&) = delete;
		—прайт& operator = (const —прайт&) = delete;

		virtual void отопрожение—пра(const glm::vec2& позици€, const glm::vec2& размер, const float вращение)const;

	protected :
		std::shared_ptr <“екстуры2D> п_п“екстуры;
		std::shared_ptr< Ўейдерна€ѕрограмма>п_пЎейдерна€ѕрограмма;
		¬екторћножество п_¬екторћножество;
		¬екторЅуффер п_вектор оординатыЅуффер;
		¬екторЅуффер п_“екстур оординатыЅуффер;
		»ндексЅуффер п_индексЅуффер;
	};
}