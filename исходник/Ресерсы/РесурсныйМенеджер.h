#pragma once 

#include<string>
#include<memory>
#include<map>

namespace –ендор
{
	class Ўейдерна€ѕрограмма;
}


class –есурсныйћенеджер
{
public:
	–есурсныйћенеджер (const std::string& ѕутьисполнимый);
	~–есурсныйћенеджер()= default;


	–есурсныйћенеджер(const –есурсныйћенеджер&) = delete;
	–есурсныйћенеджер& operator=(const –есурсныйћенеджер&) = delete;
	–есурсныйћенеджер& operator=( –есурсныйћенеджер&&) = delete;
	–есурсныйћенеджер(–есурсныйћенеджер&&) = delete;


	std::shared_ptr< –ендор ::Ўейдерна€ѕрограмма> загрускаЎедоры(const std::string& »м€Ўедора, const std::string& ¬ершинныйѕуть, const std::string& ‘рагментныйѕуть);
	std::shared_ptr< –ендор::Ўейдерна€ѕрограмма> получатьЎудоровѕрограмм(const std::string& »м€Ўедора);
	void загруска“екстур(const std::string& »м€“екстур, const std::string& ѕуть“екстуры);



private:
	 std::string получить—троку‘айла(const std::string& относительный‘айлаѕути);

	typedef std::map<const std::string, std::shared_ptr< –ендор::Ўейдерна€ѕрограмма>> Ўейдерна€ѕрограммаѕлан;
	Ўейдерна€ѕрограммаѕлан п_Ўейдерна€ѕрограмма;


	std::string п_ѕуть;
};

