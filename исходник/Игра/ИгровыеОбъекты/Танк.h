#pragma once 

#include <glm/vec2.hpp>
#include <memory>

#include "����������������.h"

namespace ���������������� {
	class ��������������;

}

class  ���� :public ����������������
{
public:
	
	enum  class ����������
	{
		����,
		����,
		����,
		�����
	};

    ����(std::shared_ptr<����������������::��������������> ��������, const float ��������, const glm::vec2& �������, const glm::vec2& ������);

	void ������() const override;
	void �������������������(const ���������� ����������);
	void ���������(const bool ���������);
	void ��������(const uint64_t ������) override;
	void �����������������������������(const ���������� ����������);

private:
	���������� �_����������;
	std::shared_ptr<����������������::��������������> �_��������;
	bool �_���������;
	float �_��������;
	glm::vec2 �_����������������;
};

