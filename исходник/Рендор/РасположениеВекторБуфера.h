#pragma once

#include <vector>
#include <glad/glad.h>

namespace ���������������� {

	struct �������������������������������� {
		GLint �������;
		GLenum ���;
		GLboolean �������������;
		unsigned int ������;
	};

	class ������������������������
	{
	public:
		������������������������();
		
		void �������������(const size_t �������);
		unsigned int ����������()const { return �_���; }
		void  ����������������������������������(const unsigned int �������, const bool �������������);
		const std::vector<��������������������������������>& �������������������������() const { return �_������������������; }

	private:
		std::vector<��������������������������������>�_������������������;
		unsigned int �_���;
	};
}
