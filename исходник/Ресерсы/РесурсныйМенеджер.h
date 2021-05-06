#pragma once 

#include<string>
#include<memory>
#include<map>


namespace –ендор
{
	class Ўейдерна€ѕрограмма;
	class “екстуры2D;
	class  —прайт;
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
	
	
	std::shared_ptr< –ендор::“екстуры2D>  загруска“екстур(const std::string& »м€“екстур, const std::string& ѕуть“екстуры);
	std::shared_ptr< –ендор::“екстуры2D> получать“екстуры2D(const std::string& »м€“екстур);


	std::shared_ptr< –ендор::—прайт> загруска—прайт(const std::string& »м€—прайт,
	                                                const std::string& »м€“екстур,
		                                            const std::string& »м€Ўедора,
	                                                const unsigned int спрайтЎирена, 
		                                            const unsigned int спрайт¬ысота);

	std::shared_ptr< –ендор::—прайт> получать—прайт(const std::string& »м€—прайт);



private:
	 std::string получить—троку‘айла(const std::string& относительный‘айлаѕути);

	typedef std::map<const std::string, std::shared_ptr< –ендор::Ўейдерна€ѕрограмма>> Ўейдерна€ѕрограммаѕлан;
	Ўейдерна€ѕрограммаѕлан п_Ўейдерна€ѕрограмма;

	typedef std::map < const std::string, std::shared_ptr< –ендор::“екстуры2D>> “екстурыѕлан;
	“екстурыѕлан п_“екстур;

	typedef std::map < const std::string, std::shared_ptr< –ендор::—прайт>> —прайтѕлан;
	—прайтѕлан п_—прайт;

	std::string п_ѕуть;
};

