#include "������������.h"

namespace ������ {

	������������::������������()
		:�_id(0)
	{

	}

	������������::~������������()
	{
		glDeleteBuffers(1, &�_id);

	}

	������������& ������������::operator = (������������&& ������������) noexcept
	{
		�_id = ������������.�_id;
		������������.�_id = 0;
		return *this;

	}

	������������::������������(������������&& ������������) noexcept
	{
		�_id = ������������.�_id;
		������������.�_id = 0;

	}

	void ������������::����(const void* ������, const unsigned int ������)
	{
		glGenBuffers(1, &�_id);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, �_id);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, ������, ������, GL_STATIC_DRAW);

	}

	void ������������::���������() const
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, �_id);

	}

	void ������������::�����������() const
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}

}