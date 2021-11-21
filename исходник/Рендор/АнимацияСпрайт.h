#pragma once 

#include "—прайт.h"

#include <map>
#include <vector>


namespace ƒвижок–ендеринга{

	

	class јнимаци€—прайт : public —прайт
	{
	 public:
		 јнимаци€—прайт(std::shared_ptr <“екстуры2D> п“екстуры,
			            std::shared_ptr< Ўейдерна€ѕрограмма>пЎейдерна€ѕрограмма,  
			            std::string исходный–асположение“екстур,
			      const glm::vec2& позици€ = glm::vec2(0.f), 
			      const glm::vec2& размер = glm::vec2(1.f),
		          const float повород = 0.f);

		 void вставить—осто€ние(std::string состо€ние, std::vector < std::pair < std::string, uint64_t>> ƒлительность адра“екстуры);

		 void отопрожение—пра()const override;

		 void сохранить—осто€ние(const std::string& новы—осто€ние);

		 void ќбновить(const uint64_t дельта);
		 
	private:
		std::map < std::string, std::vector<std::pair<std::string, uint64_t>>> п_картаCосто€ний;
		size_t п_текущий адр = 0;
		uint64_t п_текущийјнимаций¬ремени = 0;
		std::map < std::string, std::vector<std::pair<std::string, uint64_t>>>::const_iterator п_п“екущийјнимацийƒлительность;
	  mutable bool п_гр€зный = false;
	};

}