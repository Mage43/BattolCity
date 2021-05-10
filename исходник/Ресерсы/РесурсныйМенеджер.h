#pragma once 

#include <string>
#include <memory>
#include <map>
#include <vector>


namespace ������
{
	class ������������������;
	class ��������2D;
	class  ������;
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
	
	
	std::shared_ptr< ������::��������2D> ���������������(const std::string& ����������, const std::string& ������������);
	std::shared_ptr< ������::��������2D> ����������������2D(const std::string& ����������);


	std::shared_ptr< ������::������> ��������������(const std::string& ���������,
	                                                const std::string& ����������,
		                                            const std::string& ���������,
	                                                const unsigned int ������������, 
		                                            const unsigned int ������������,
	                                                const std::string& ���������������������� = "�����������");

	std::shared_ptr< ������::������> ��������������(const std::string& ���������);

	std::shared_ptr< ������::��������2D> ��������������������(const std::string ����������, 
		                                                      const std::string ������������,
		                                                      const std::vector<std::string>�������������������,
	                                                          const unsigned int �������������������������,
	                                                          const unsigned int �������������������������);


private:                                               
	 std::string �������������������(const std::string& ����������������������) const;

	typedef std::map<const std::string, std::shared_ptr< ������::������������������>> ����������������������;
	���������������������� �_������������������;

	typedef std::map < const std::string, std::shared_ptr< ������::��������2D>> ������������;
	������������ �_�������;

	typedef std::map < const std::string, std::shared_ptr< ������::������>> ����������;
	���������� �_������;

	std::string �_����;
};

