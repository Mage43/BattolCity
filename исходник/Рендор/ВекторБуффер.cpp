#include "¬екторЅуффер.h"

namespace ƒвижок–ендеринга {

	¬екторЅуффер::¬екторЅуффер()
		:п_id(0)
	{
	
	}

	¬екторЅуффер::~¬екторЅуффер()
	{
		glDeleteBuffers(1, &п_id);
	
	}

	¬екторЅуффер& ¬екторЅуффер::operator = ( ¬екторЅуффер&& векторЅуффер) noexcept
	{
		п_id = векторЅуффер.п_id;
		векторЅуффер.п_id = 0;
		return *this;

	}

	¬екторЅуффер::¬екторЅуффер(¬екторЅуффер&& векторЅуффер) noexcept
	{
		п_id = векторЅуффер.п_id;
		векторЅуффер.п_id = 0;

	}

	void ¬екторЅуффер::инит(const void* данные, const unsigned int размер)
	{
		glGenBuffers(1, &п_id);
		glBindBuffer(GL_ARRAY_BUFFER, п_id);
		glBufferData(GL_ARRAY_BUFFER, размер, данные, GL_STATIC_DRAW);

	}

	void ¬екторЅуффер::обновление(const void* данные, const unsigned int размер) const
	{
		glBindBuffer(GL_ARRAY_BUFFER, п_id);
		glBufferSubData(GL_ARRAY_BUFFER, 0, размер, данные);

	}

	void ¬екторЅуффер::св€зывать() const
	{
		glBindBuffer(GL_ARRAY_BUFFER, п_id);

	}

	void ¬екторЅуффер::разв€зывать() const
	{
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

}