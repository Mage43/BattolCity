#include "�����������������.h"
#include "../������/������������������.h"
#include "../������/��������2D.h"

#include<sstream>
#include<fstream>
#include<iostream>

#define STB_IMAGE_IMPLEMENTATION
#define STBI_ONLY_PNG
#include "stb_image.h"

�����������������::�����������������(const std::string& ��������������)
{
	size_t ����� = ��������������.find_last_of("/\\");
	�_���� = ��������������.substr(0, �����);
}

 std::string �����������������:: �������������������(const std::string& ����������������������)
{
	 std::ifstream �;
	 �.open(�_���� + "/" + ����������������������.c_str(), std::ios::in | std::ios::binary);
	 if (!�.is_open())
	 {
		 std::cerr << "������ ��� ���������� �����: "<< ���������������������� << std::endl;
		 return std::string{};
	 }


	 std::stringstream �����;
	 ����� << �.rdbuf();
	 return �����.str();

}


 std::shared_ptr< ������::������������������> �����������������::��������������(const std::string& ���������, const std::string& �������������, const std::string& ���������������)
 {
	 std::string ��������������� = �������������������(�������������);
	 if (���������������.empty())
	 {
		 std::cerr << "��� ��������� ������!" << std::endl;
		 return nullptr;
	 }


	 std::string ����������������� = �������������������(���������������);
	 if (�����������������.empty())
	 {
		 std::cerr << "��� ����������� ������!" << std::endl;
		 return nullptr;
	 }
	 std::shared_ptr<������::������������������>& ���������� = �_������������������.emplace(���������, std::make_shared<������::������������������>(���������������, �����������������)).first->second;
	 if (����������->������������())
	 {
		 return ����������;
	 }

	 std::cerr << "�� ����������� ������ ��������\n "
		 << "���������" << ������������� << "\n"
		 << "�����������" << ��������������� << std::endl;

	 return nullptr;
 }

 std::shared_ptr< ������::������������������> �����������������::�����������������������(const std::string& ���������)
 {
	 ����������������������::const_iterator �� = �_������������������.find(���������);
	 if (�� != �_������������������.end())
	 {
		 return ��->second;
	 }
	 std::cerr<<"�� ����� ������ ��������: "<< ���������<< std::endl;

	 return nullptr;
	 
 }


 std::shared_ptr< ������::��������2D> �����������������::���������������(const std::string& ����������, const std::string& ������������)
 {
	 int ����� = 0;
	 int ������ = 0;
	 int ������ = 0;
     stbi_set_flip_vertically_on_load(true);
	unsigned char* ������� = stbi_load(std::string(�_���� + "/" + ������������).c_str(), &������, &������, &�����, 0);
	

	if (!�������)
	{
		std::cerr << "�� �������� ����: " << ���������� << std::endl;
		return nullptr;
	}

	std::shared_ptr< ������::��������2D>������������� = �_�������.emplace(����������, std::make_shared< ������::��������2D>(������, ������, �������, �����,
		                                                                                                                   GL_NEAREST, GL_CLAMP_TO_EDGE)).first->second;
    stbi_image_free(�������);
	return �������������;
 }

 /*std::shared_ptr<������::��������2D> �����������������::����������������2D(const std::string& ����������)
 {
	 return std::shared_ptr<������::��������2D>();
 }*/

 std::shared_ptr< ������::��������2D> �����������������::����������������2D(const std::string& ����������)
 { 
	 ������������::const_iterator �� = �_�������.find(����������);
	 if (�� != �_�������.end())
	 {
		 return ��->second;
	 }
	 std::cerr << "�� ����� ������ ��������: " << ���������� << std::endl;

	 return nullptr;


 }
 
	
 
