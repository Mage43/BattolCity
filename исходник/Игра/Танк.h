#pragma once 

#include <glm/vec2.hpp>
#include <memory>

namespace ���������������� {
	class ��������������;

}

class  ����
{
public:
	

	

	enum  class ����������
	{
		����,
		����,
		����,
		�����
	};

    ����(std::shared_ptr<����������������::��������������> ��������, const float ��������, const glm::vec2& �������);

	void ����������������()const ;
	void �������������������(const ���������� ����������);
	void ���������(const bool ���������);
	void ����������(const uint64_t ������);
	void �����������������������������(const ���������� ����������);


private:
	���������� �_����������;
	std::shared_ptr<����������������::��������������> �_��������;
	bool �_���������;
	float �_��������;
	glm::vec2 �_�������;
	glm::vec2 �_����������������;
};

