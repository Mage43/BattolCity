#include "������.h"

namespace ���������������� {

	 void ������::��������(const ���������������& ���������������, const ������������& ������������, const ������������������& ���������)
	{
		 ���������.���();
		 ���������������.���������();
		 ������������.���������();

		 glDrawElements(GL_TRIANGLES, ������������.���������������(), GL_UNSIGNED_INT, nullptr);
	}
	 void ������::��������������������(float �, float �, float �, float �)
	 {
		 glClearColor(�, �, �, �);
	 }

	 void ������::����������()
	 {
		 glClear(GL_COLOR_BUFFER_BIT);
	 }

	 void  ������::����������������(unsigned int �����, unsigned int ������, unsigned int �������������, unsigned int ��������������)
	 {
		 glViewport(�������������, ��������������, �����, ������);
	 }

	 std::string ������::������������������������()
	 {
		return (char*)glGetString(GL_RENDERER);
	 }

	 std::string ������::��������������������()
	 {
		return (char*)glGetString(GL_VERSION);
	 }
	
}