#pragma once 

#include <array>
#include <glm/vec2.hpp>
#include <iostream>

class ����;

class ����
{
public:
	����(const  glm::ivec2& window������);
	~����();

	void ��������������();
	void ��������(const uint64_t ������);
	void ����������������(const int �����, const int �����������);
	bool �������������();

	
private:
   std::array<bool, 349> �_�����; 

   enum class �������������� {
	   ��������,
	   �����

   };

   glm::ivec2 �_window������;
   �������������� �_���������������������;
   std::unique_ptr<����> �_�����;
   std::unique_ptr<����> �_�����1;
   

};

