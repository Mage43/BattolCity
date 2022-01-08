#pragma once 

#include <string>
#include <memory>
#include <map>
#include <vector>


namespace ����������������
{
	class ������������������;
	class ��������2D;
	class  ������;
	class ��������������;
}


class �����������������
{
public:
	static void �����������������������(const std::string& ��������������);
	static void ���������������������();

	~�����������������()= delete;
	�����������������() = delete;
	�����������������(const �����������������&) = delete;
	�����������������& operator=(const �����������������&) = delete;
	�����������������& operator=( �����������������&&) = delete;
	�����������������(�����������������&&) = delete;


	static std::shared_ptr< ���������������� ::������������������> ��������������(const std::string& ���������, const std::string& �������������, const std::string& ���������������);
	static std::shared_ptr< ����������������::������������������> �����������������������(const std::string& ���������);
	
	
	static std::shared_ptr< ����������������::��������2D> ���������������(const std::string& ����������, const std::string& ������������);
	static std::shared_ptr< ����������������::��������2D> ����������������2D(const std::string& ����������);


	static std::shared_ptr< ����������������::������> ��������������(const std::string& ���������,
														   const std::string& ����������,
														   const std::string& ���������,
														   const unsigned int ������������, 
														   const unsigned int ������������,
														   const std::string& ���������������������� = "�����������");

	static std::shared_ptr< ����������������::������> ��������������(const std::string& ���������);

	static std::shared_ptr< ����������������::��������������> ����������������������(const std::string& ���������,
																		   const std::string& ����������,
																		   const std::string& ���������,
																	       const unsigned int ������������,
																		   const unsigned int ������������,
																		   const std::string& ���������������������� = "�����������");

	static std::shared_ptr< ����������������::��������������> ����������������������(const std::string& ���������);
	 
	static std::shared_ptr< ����������������::��������2D> ��������������������(std::string ����������,
																	 std::string ������������,
																	 std::vector<std::string>�������������������,
																	 const unsigned int �������������������������,
																     const unsigned int �������������������������);

	static bool ��������JSON��������(const std::string& JSONP����);


private:                                               
	static  std::string �������������������(const std::string& ����������������������) ;

	typedef std::map<const std::string, std::shared_ptr< ����������������::������������������>> ����������������������;
	static ���������������������� �_������������������;

	typedef std::map < const std::string, std::shared_ptr< ����������������::��������2D>> ������������;
	static ������������ �_�������;

	typedef std::map < const std::string, std::shared_ptr< ����������������::������>> ����������;
	static ���������� �_������;

	typedef std::map < const std::string, std::shared_ptr< ����������������::��������������>> ������������������;
	static ������������������ �_��������������;

	static std::string �_����;
	
};

