#pragma once

#include <glm/vec2.hpp>

class ����������������
{
public:
	����������������(const glm::vec2& �������, const glm::vec2& ������, const float ��������);
	virtual void ������() const = 0;
	virtual void ��������(const uint64_t ������) = 0;
	virtual ~����������������() ;

protected:
	glm::vec2 �_�������;
	glm::vec2 �_������;
	float �_��������;

};


