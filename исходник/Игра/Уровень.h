#pragma once 

#include <vector>
#include <string>
#include <memory>

class ����������������;

class ������� 
{
public:
	�������(const std::vector<std::string>& ���������������);
	void ������()const;
	void ��������(const uint64_t ������);

private:
	size_t �_������;
	size_t �_������;

	std::vector < std::shared_ptr<����������������>>�_������������;
};