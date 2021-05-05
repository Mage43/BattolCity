#pragma once 

#include <glad/glad.h>
#include <glm/vec2.hpp>

#include <string>
#include <memory>

namespace Рендор{

	class Текстуры2D;
	class ШейдернаяПрограмма;

	class Спрайт
	{
	public:
		Спрайт(const std::shared_ptr <Текстуры2D> пТекстуры, 
			   const std::shared_ptr< ШейдернаяПрограмма>пШейдернаяПрограмма, 
			   const glm::vec2& позиция = glm::vec2(0.f), 
			   const glm::vec2& размер = glm::vec2(1.f),
		       const float повород = 0.f);
		
		~Спрайт();
        Спрайт(const Спрайт&) = delete;
		Спрайт& operator = (const Спрайт&) = delete;

		void отопрожениеСпра()const;
		void сохранитьПозицию(const glm::vec2& позиция);
		void сохранитьРазмер(const glm::vec2& размер);
		void сохранитьПовород(const  const float повород);


	private:
		std::shared_ptr <Текстуры2D> п_пТекстуры;
		std::shared_ptr< ШейдернаяПрограмма>п_пШейдернаяПрограмма;
		glm::vec2 п_позиция;
		glm::vec2 п_размер;
		float  п_повород;

	};
}