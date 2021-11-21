#pragma once 

#include "¬екторћножество.h"
#include "»ндексЅуффер.h"
#include "Ўейдерна€ѕрограмма.h"

#include <string>

namespace ƒвижок–ендеринга {
	class –ендор
	{
	public:
		static void рисовать(const ¬екторћножество& векторћножество, const »ндексЅуффер& индексЅуффер, const Ўейдерна€ѕрограмма& шейдерна€);
		static void установить„истый÷вет(float к, float г, float с, float а);
		static void совершенно();
		static void областьѕросмотра(unsigned int шрена, unsigned int высота, unsigned int левое—мещение = 0, unsigned int нижнее—мещение = 0);

		static std::string ѕолучитьс—троку–ендерера();
		static std::string ѕолучить—троку¬ерсии();
		
	};
}

