#pragma once 

#include <array>
#include <glm/vec2.hpp>
#include <iostream>

class Танк;

class Игра
{
public:
	Игра(const  glm::ivec2& windowРазмер);
	~Игра();

	void воспроизводить();
	void Обновить(const uint64_t дельта);
	void установитьКнопку(const int клава, const int действовать);
	bool инициализация();

	
private:
   std::array<bool, 349> п_клавы; 

   enum class ПИгрыСостояние {
	   Активный,
	   Пауза

   };

   glm::ivec2 п_windowРазмер;
   ПИгрыСостояние п_пТекущийИгрыСостояние;
   std::unique_ptr<Танк> п_ПТанк;
   std::unique_ptr<Танк> п_ПТанк1;
   

};

