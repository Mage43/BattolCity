#pragma once 
#include <glad/glad.h>

namespace –ендор {

	class »ндексЅуффер
	{
	public:
		»ндексЅуффер();
		~»ндексЅуффер();

		»ндексЅуффер(const »ндексЅуффер&) = delete;
		»ндексЅуффер& operator = (const »ндексЅуффер&) = delete;
		»ндексЅуффер& operator = (»ндексЅуффер&& векторЅуффер) noexcept;
		»ндексЅуффер(»ндексЅуффер&& векторЅуффер) noexcept;

		void инит(const void* данные, const unsigned int размер);
		void св€зывать() const;
		void разв€зывать() const;
	private:
		GLuint п_id;
	};



}