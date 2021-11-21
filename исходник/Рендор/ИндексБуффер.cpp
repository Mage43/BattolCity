#include "»ндексЅуффер.h"

namespace ƒвижок–ендеринга {

	»ндексЅуффер::»ндексЅуффер()
		: п_id(0)
		, п_считать(0)
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
		п_считать = иекторЅуффер.п_считать;
		иекторЅуффер.п_считать = 0;
		return *this;

	}

	»ндексЅуффер::»ндексЅуффер(»ндексЅуффер&& иекторЅуффер) noexcept
	{
		п_id = иекторЅуффер.п_id;
		иекторЅуффер.п_id = 0;
		п_считать = иекторЅуффер.п_считать;
		иекторЅуффер.п_считать = 0;
	}

	void »ндексЅуффер::инит(const void* данные, const unsigned int считать)
	{
		п_считать = считать;
		glGenBuffers(1, &п_id);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, п_id);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, считать * sizeof(GLuint), данные, GL_STATIC_DRAW);

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