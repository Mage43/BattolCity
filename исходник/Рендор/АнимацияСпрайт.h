#pragma once 

#include "������.h"

#include <map>
#include <vector>


namespace ����������������{

	

	class �������������� : public ������
	{
	 public:
		 ��������������(std::shared_ptr <��������2D> ���������,
			            std::shared_ptr< ������������������>�������������������,  
			            std::string ���������������������������,
			      const glm::vec2& ������� = glm::vec2(0.f), 
			      const glm::vec2& ������ = glm::vec2(1.f),
		          const float ������� = 0.f);

		 void �����������������(std::string ���������, std::vector < std::pair < std::string, uint64_t>> �������������������������);

		 void ���������������()const override;

		 void ������������������(const std::string& �������������);

		 void ��������(const uint64_t ������);
		 
	private:
		std::map < std::string, std::vector<std::pair<std::string, uint64_t>>> �_�����C��������;
		size_t �_����������� = 0;
		uint64_t �_���������������������� = 0;
		std::map < std::string, std::vector<std::pair<std::string, uint64_t>>>::const_iterator �_����������������������������;
	  mutable bool �_������� = false;
	};

}