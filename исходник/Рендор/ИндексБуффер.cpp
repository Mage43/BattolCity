#include "������������.h"

namespace ���������������� {

	������������::������������()
		: �_id(0)
		, �_�������(0)
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
		�_������� = ������������.�_�������;
		������������.�_������� = 0;
		return *this;

	}

	������������::������������(������������&& ������������) noexcept
	{
		�_id = ������������.�_id;
		������������.�_id = 0;
		�_������� = ������������.�_�������;
		������������.�_������� = 0;
	}

	void ������������::����(const void* ������, const unsigned int �������)
	{
		�_������� = �������;
		glGenBuffers(1, &�_id);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, �_id);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, ������� * sizeof(GLuint), ������, GL_STATIC_DRAW);

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