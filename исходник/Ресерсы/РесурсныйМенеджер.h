#pragma once 

#include<string>
#include<memory>
#include<map>

namespace ������
{
	class ������������������;
}


class �����������������
{
public:
	����������������� (const std::string& ��������������);
	~�����������������()= default;


	�����������������(const �����������������&) = delete;
	�����������������& operator=(const �����������������&) = delete;
	�����������������& operator=( �����������������&&) = delete;
	�����������������(�����������������&&) = delete;


	std::shared_ptr< ������ ::������������������> ��������������(const std::string& ���������, const std::string& �������������, const std::string& ���������������);
	std::shared_ptr< ������::������������������> �����������������������(const std::string& ���������);
	void ���������������(const std::string& ����������, const std::string& ������������);



private:
	 std::string �������������������(const std::string& ����������������������);

	typedef std::map<const std::string, std::shared_ptr< ������::������������������>> ����������������������;
	���������������������� �_������������������;


	std::string �_����;
};

