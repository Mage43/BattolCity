#pragma once

#include "����������������.h"

#include <memory>
namespace ���������������� {
	class ������;

}

class �������������� : public ���������������� 
{
public:
	��������������(const std::shared_ptr<����������������::������> ������� , const glm::vec2& �������, const glm::vec2& ������, const float ��������);
	virtual void ������() const override;
	virtual void ��������(const uint64_t ������) override;
 
private:
	std::shared_ptr<����������������::������> �_��������������;
};

