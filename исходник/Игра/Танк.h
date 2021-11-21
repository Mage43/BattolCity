#pragma once 

#include <glm/vec2.hpp>
#include <memory>

namespace ƒвижок–ендеринга {
	class јнимаци€—прайт;

}

class  “анк
{
public:
	

	

	enum  class ќриентаци€
	{
		¬ерх,
		¬низ,
		Ћево,
		ѕраво
	};

    “анк(std::shared_ptr<ƒвижок–ендеринга::јнимаци€—прайт> п—прайта, const float скорость, const glm::vec2& позици€);

	void отопрожение“анка()const ;
	void сохранитьќриентаци€(const ќриентаци€ ориентаци€);
	void двигатьс€(const bool двигатьс€);
	void обновлени€(const uint64_t дельта);
	void сохранитьќриентаци€Ѕез—прайта(const ќриентаци€ ориентаци€);


private:
	ќриентаци€ п_ориентаци€;
	std::shared_ptr<ƒвижок–ендеринга::јнимаци€—прайт> п_п—прайта;
	bool п_двигатьс€;
	float п_скорость;
	glm::vec2 п_позици€;
	glm::vec2 п_сдвинутьс€—ћеста;
};

