#pragma once 
#include <glad/glad.h>

namespace ������ {

	class ������������
	{
	public:
		������������();
		~������������();

		������������(const ������������&) = delete;
		������������& operator = (const ������������&) = delete;
		������������& operator = (������������&& ������������) noexcept;
		������������(������������&& ������������) noexcept;

		void ����(const void* ������, const unsigned int ������);
		void ���������() const;
		void �����������() const;
	private:
		GLuint �_id;
	};



}