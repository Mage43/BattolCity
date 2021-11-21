#pragma once

#include <vector>
#include <glad/glad.h>

namespace ƒвижок–ендеринга {

	struct –асположение¬екторЅуфераЁлемента {
		GLint считать;
		GLenum тип;
		GLboolean нормализовать;
		unsigned int размер;
	};

	class –асположение¬екторЅуфера
	{
	public:
		–асположение¬екторЅуфера();
		
		void резервЁлемент(const size_t считать);
		unsigned int получитЎаг()const { return п_шаг; }
		void  добавитьѕоплавок омпоновкиЁлемента(const unsigned int считать, const bool нормализовать);
		const std::vector<–асположение¬екторЅуфераЁлемента>& получит омпоновкиЁлемента() const { return п_ омпоновкиЁлемента; }

	private:
		std::vector<–асположение¬екторЅуфераЁлемента>п_ омпоновкиЁлемента;
		unsigned int п_шаг;
	};
}
