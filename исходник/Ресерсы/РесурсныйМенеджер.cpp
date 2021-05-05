#include "–есурсныйћенеджер.h"
#include "../–ендор/Ўейдерна€ѕрограмма.h"
#include "../–ендор/“екстуры2D.h"

#include<sstream>
#include<fstream>
#include<iostream>

#define STB_IMAGE_IMPLEMENTATION
#define STBI_ONLY_PNG
#include "stb_image.h"

–есурсныйћенеджер::–есурсныйћенеджер(const std::string& ѕутьисполнимый)
{
	size_t нашел = ѕутьисполнимый.find_last_of("/\\");
	п_ѕуть = ѕутьисполнимый.substr(0, нашел);
}

 std::string –есурсныйћенеджер:: получить—троку‘айла(const std::string& относительный‘айлаѕути)
{
	 std::ifstream ф;
	 ф.open(п_ѕуть + "/" + относительный‘айлаѕути.c_str(), std::ios::in | std::ios::binary);
	 if (!ф.is_open())
	 {
		 std::cerr << "ќЎ»Ѕ ј ѕ–» ќ“ –џ¬јЌ»≈ ‘ј…Ћј: "<< относительный‘айлаѕути << std::endl;
		 return std::string{};
	 }


	 std::stringstream буфер;
	 буфер << ф.rdbuf();
	 return буфер.str();

}


 std::shared_ptr< –ендор::Ўейдерна€ѕрограмма> –есурсныйћенеджер::загрускаЎедоры(const std::string& »м€Ўедора, const std::string& ¬ершинныйѕуть, const std::string& ‘рагментныйѕуть)
 {
	 std::string ¬ершинныйЎейдер = получить—троку‘айла(¬ершинныйѕуть);
	 if (¬ершинныйЎейдер.empty())
	 {
		 std::cerr << "Ќет ¬ершинный Ўейдер!" << std::endl;
		 return nullptr;
	 }


	 std::string ‘рагментныйЎейдер = получить—троку‘айла(‘рагментныйѕуть);
	 if (‘рагментныйЎейдер.empty())
	 {
		 std::cerr << "Ќет ‘рагментный Ўейдер!" << std::endl;
		 return nullptr;
	 }
	 std::shared_ptr<–ендор::Ўейдерна€ѕрограмма>& новыйЎедор = п_Ўейдерна€ѕрограмма.emplace(»м€Ўедора, std::make_shared<–ендор::Ўейдерна€ѕрограмма>(¬ершинныйЎейдер, ‘рагментныйЎейдер)).first->second;
	 if (новыйЎедор->воз апел€ции())
	 {
		 return новыйЎедор;
	 }

	 std::cerr << "Ќе копелирулс€ шейдор програма\n "
		 << "¬ершинный" << ¬ершинныйѕуть << "\n"
		 << "‘рагментный" << ‘рагментныйѕуть << std::endl;

	 return nullptr;
 }

 std::shared_ptr< –ендор::Ўейдерна€ѕрограмма> –есурсныйћенеджер::получатьЎудоровѕрограмм(const std::string& »м€Ўедора)
 {
	 Ўейдерна€ѕрограммаѕлан::const_iterator им = п_Ўейдерна€ѕрограмма.find(»м€Ўедора);
	 if (им != п_Ўейдерна€ѕрограмма.end())
	 {
		 return им->second;
	 }
	 std::cerr<<"Ќе нашли шейдор програма: "<< »м€Ўедора<< std::endl;

	 return nullptr;
	 
 }


 std::shared_ptr< –ендор::“екстуры2D> –есурсныйћенеджер::загруска“екстур(const std::string& »м€“екстур, const std::string& ѕуть“екстуры)
 {
	 int канал = 0;
	 int ширена = 0;
	 int высота = 0;
     stbi_set_flip_vertically_on_load(true);
	unsigned char* пиксель = stbi_load(std::string(п_ѕуть + "/" + ѕуть“екстуры).c_str(), &ширена, &высота, &канал, 0);
	

	if (!пиксель)
	{
		std::cerr << "Ќе загружен фота: " << »м€“екстур << std::endl;
		return nullptr;
	}

	std::shared_ptr< –ендор::“екстуры2D>нова€“екстура = п_“екстур.emplace(»м€“екстур, std::make_shared< –ендор::“екстуры2D>(ширена, высота, пиксель, канал,
		GL_NEAREST, GL_CLAMP_TO_EDGE)).first->second;
    stbi_image_free(пиксель);
	return нова€“екстура;
 }


 std::shared_ptr< –ендор::“екстуры2D> –есурсныйћенеджер::получать“екстуры2D(const std::string& »м€“екстур)
 { 
	 “екстурыѕлан::const_iterator им = п_“екстур.find(»м€“екстур);
	 if (им != п_“екстур.end())
	 {
		 return им->second;
	 }
	 std::cerr << "Ќе нашли шейдор програма: " << »м€“екстур << std::endl;

	 return nullptr;


 }
 
	
 
