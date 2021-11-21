#pragma once 
#include <glad/glad.h>

namespace ƒвижок–ендеринга {

	class »ндексЅуффер
	{
	public:
		»ндексЅуффер();
		~»ндексЅуффер();

		»ндексЅуффер(const »ндексЅуффер&) = delete;
		»ндексЅуффер& operator = (const »ндексЅуффер&) = delete;
		»ндексЅуффер& operator = (»ндексЅуффер&& векторЅуффер) noexcept;
		»ндексЅуффер(»ндексЅуффер&& векторЅуффер) noexcept;

		void инит(const void* данные, const unsigned int считать);
		void св€зывать() const;
		void разв€зывать() const;
		unsigned int получить—читать()const { return п_считать; }

	private:
		GLuint п_id;
		unsigned int п_считать;
	};



}