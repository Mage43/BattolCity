#include "РесурсныйМенеджер.h"
#include "../Рендор/ШейдернаяПрограмма.h"
#include "../Рендор/Текстуры2D.h"

#include<sstream>
#include<fstream>
#include<iostream>

#define STB_IMAGE_IMPLEMENTATION
#define STBI_ONLY_PNG
#include "stb_image.h"

РесурсныйМенеджер::РесурсныйМенеджер(const std::string& Путьисполнимый)
{
	size_t нашел = Путьисполнимый.find_last_of("/\\");
	п_Путь = Путьисполнимый.substr(0, нашел);
}

 std::string РесурсныйМенеджер:: получитьСтрокуФайла(const std::string& относительныйФайлаПути)
{
	 std::ifstream ф;
	 ф.open(п_Путь + "/" + относительныйФайлаПути.c_str(), std::ios::in | std::ios::binary);
	 if (!ф.is_open())
	 {
		 std::cerr << "ОШИБКА ПРИ ОТКРЫВАНИЕ ФАЙЛА: "<< относительныйФайлаПути << std::endl;
		 return std::string{};
	 }


	 std::stringstream буфер;
	 буфер << ф.rdbuf();
	 return буфер.str();

}


 std::shared_ptr< Рендор::ШейдернаяПрограмма> РесурсныйМенеджер::загрускаШедоры(const std::string& ИмяШедора, const std::string& ВершинныйПуть, const std::string& ФрагментныйПуть)
 {
	 std::string ВершинныйШейдер = получитьСтрокуФайла(ВершинныйПуть);
	 if (ВершинныйШейдер.empty())
	 {
		 std::cerr << "Нет Вершинный Шейдер!" << std::endl;
		 return nullptr;
	 }


	 std::string ФрагментныйШейдер = получитьСтрокуФайла(ФрагментныйПуть);
	 if (ФрагментныйШейдер.empty())
	 {
		 std::cerr << "Нет Фрагментный Шейдер!" << std::endl;
		 return nullptr;
	 }
	 std::shared_ptr<Рендор::ШейдернаяПрограмма>& новыйШедор = п_ШейдернаяПрограмма.emplace(ИмяШедора, std::make_shared<Рендор::ШейдернаяПрограмма>(ВершинныйШейдер, ФрагментныйШейдер)).first->second;
	 if (новыйШедор->возКапеляции())
	 {
		 return новыйШедор;
	 }

	 std::cerr << "Не копелирулся шейдор програма\n "
		 << "Вершинный" << ВершинныйПуть << "\n"
		 << "Фрагментный" << ФрагментныйПуть << std::endl;

	 return nullptr;
 }

 std::shared_ptr< Рендор::ШейдернаяПрограмма> РесурсныйМенеджер::получатьШудоровПрограмм(const std::string& ИмяШедора)
 {
	 ШейдернаяПрограммаПлан::const_iterator им = п_ШейдернаяПрограмма.find(ИмяШедора);
	 if (им != п_ШейдернаяПрограмма.end())
	 {
		 return им->second;
	 }
	 std::cerr<<"Не нашли шейдор програма: "<< ИмяШедора<< std::endl;

	 return nullptr;
	 
 }


 std::shared_ptr< Рендор::Текстуры2D> РесурсныйМенеджер::загрускаТекстур(const std::string& ИмяТекстур, const std::string& ПутьТекстуры)
 {
	 int канал = 0;
	 int ширена = 0;
	 int высота = 0;
     stbi_set_flip_vertically_on_load(true);
	unsigned char* пиксель = stbi_load(std::string(п_Путь + "/" + ПутьТекстуры).c_str(), &ширена, &высота, &канал, 0);
	

	if (!пиксель)
	{
		std::cerr << "Не загружен фота: " << ИмяТекстур << std::endl;
		return nullptr;
	}

	std::shared_ptr< Рендор::Текстуры2D>новаяТекстура = п_Текстур.emplace(ИмяТекстур, std::make_shared< Рендор::Текстуры2D>(ширена, высота, пиксель, канал,
		                                                                                                                   GL_NEAREST, GL_CLAMP_TO_EDGE)).first->second;
    stbi_image_free(пиксель);
	return новаяТекстура;
 }

 /*std::shared_ptr<Рендор::Текстуры2D> РесурсныйМенеджер::получатьТекстуры2D(const std::string& ИмяТекстур)
 {
	 return std::shared_ptr<Рендор::Текстуры2D>();
 }*/

 std::shared_ptr< Рендор::Текстуры2D> РесурсныйМенеджер::получатьТекстуры2D(const std::string& ИмяТекстур)
 { 
	 ТекстурыПлан::const_iterator им = п_Текстур.find(ИмяТекстур);
	 if (им != п_Текстур.end())
	 {
		 return им->second;
	 }
	 std::cerr << "Не нашли шейдор програма: " << ИмяТекстур << std::endl;

	 return nullptr;


 }
 
	
 
