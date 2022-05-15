#pragma once 

#include "������������.h"
#include "������������.h"
#include "���������������.h"

#include <glad/glad.h>
#include <glm/vec2.hpp>

#include <memory>
#include <string>

namespace ����������������{

	class ��������2D;
	class ������������������;

	class ������
	{
	 public:
		 ������(std::shared_ptr <��������2D> ���������, 
			    std::shared_ptr< ������������������>�������������������,  
			    std::string ���������������������������);
		
		~������();

        ������(const ������&) = delete;
		������& operator = (const ������&) = delete;

		virtual void ���������������(const glm::vec2& �������, const glm::vec2& ������, const float ��������)const;

	protected :
		std::shared_ptr <��������2D> �_���������;
		std::shared_ptr< ������������������>�_�������������������;
		��������������� �_���������������;
		������������ �_����������������������;
		������������ �_�����������������������;
		������������ �_������������;
	};
}