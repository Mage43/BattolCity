#include "»ндексЅуффер.h"

namespace –ендор {

	»ндексЅуффер::»ндексЅуффер()
		:п_id(0)
	{

	}

	»ндексЅуффер::~»ндексЅуффер()
	{
		glDeleteBuffers(1, &п_id);

	}

	»ндексЅуффер& »ндексЅуффер::operator = (»ндексЅуффер&& иекторЅуффер) noexcept
	{
		п_id = иекторЅуффер.п_id;
		иекторЅуффер.п_id = 0;
		return *this;

	}

	»ндексЅуффер::»ндексЅуффер(»ндексЅуффер&& иекторЅуффер) noexcept
	{
		п_id = иекторЅуффер.п_id;
		иекторЅуффер.п_id = 0;

	}

	void »ндексЅуффер::инит(const void* данные, const unsigned int размер)
	{
		glGenBuffers(1, &п_id);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, п_id);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, размер, данные, GL_STATIC_DRAW);

	}

	void »ндексЅуффер::св€зывать() const
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, п_id);

	}

	void »ндексЅуффер::разв€зывать() const
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}

}