#pragma once 

#include <string>
#include <memory>
#include <map>
#include <vector>


namespace ƒвижок–ендеринга
{
	class Ўейдерна€ѕрограмма;
	class “екстуры2D;
	class  —прайт;
	class јнимаци€—прайт;
}


class –есурсныйћенеджер
{
public:
	static void сохронитьѕуть»сполнимый(const std::string& ѕутьисполнимый);
	static void выгрузить¬се–есурсный();

	~–есурсныйћенеджер()= delete;
	–есурсныйћенеджер() = delete;
	–есурсныйћенеджер(const –есурсныйћенеджер&) = delete;
	–есурсныйћенеджер& operator=(const –есурсныйћенеджер&) = delete;
	–есурсныйћенеджер& operator=( –есурсныйћенеджер&&) = delete;
	–есурсныйћенеджер(–есурсныйћенеджер&&) = delete;


	static std::shared_ptr< ƒвижок–ендеринга ::Ўейдерна€ѕрограмма> загрускаЎедоры(const std::string& »м€Ўедора, const std::string& ¬ершинныйѕуть, const std::string& ‘рагментныйѕуть);
	static std::shared_ptr< ƒвижок–ендеринга::Ўейдерна€ѕрограмма> получатьЎудоровѕрограмм(const std::string& »м€Ўедора);
	
	
	static std::shared_ptr< ƒвижок–ендеринга::“екстуры2D> загруска“екстур(const std::string& »м€“екстур, const std::string& ѕуть“екстуры);
	static std::shared_ptr< ƒвижок–ендеринга::“екстуры2D> получать“екстуры2D(const std::string& »м€“екстур);


	static std::shared_ptr< ƒвижок–ендеринга::—прайт> загруска—прайт(const std::string& »м€—прайт,
														   const std::string& »м€“екстур,
														   const std::string& »м€Ўедора,
														   const unsigned int спрайтЎирена, 
														   const unsigned int спрайт¬ысота,
														   const std::string& расположение“екстур»м€ = "поумолчанию");

	static std::shared_ptr< ƒвижок–ендеринга::—прайт> получать—прайт(const std::string& »м€—прайт);

	static std::shared_ptr< ƒвижок–ендеринга::јнимаци€—прайт> загрускајнимаци€—прайт(const std::string& »м€—прайт,
																		   const std::string& »м€“екстур,
																		   const std::string& »м€Ўедора,
																	       const unsigned int спрайтЎирена,
																		   const unsigned int спрайт¬ысота,
																		   const std::string& расположение“екстур»м€ = "поумолчанию");

	static std::shared_ptr< ƒвижок–ендеринга::јнимаци€—прайт> получатьјнимаци€—прайт(const std::string& »м€—прайт);
	 
	static std::shared_ptr< ƒвижок–ендеринга::“екстуры2D> загруска“екстурјтлос(std::string »м€“екстур,
																	 std::string ѕуть“екстуры,
																	 std::vector<std::string>расположение“екстур,
																	 const unsigned int расположение“екстурЎирена,
																     const unsigned int расположение“екстур¬ысота);

	static bool загрускаJSON–есурсов(const std::string& JSONPѕуть);


private:                                               
	static  std::string получить—троку‘айла(const std::string& относительный‘айлаѕути) ;

	typedef std::map<const std::string, std::shared_ptr< ƒвижок–ендеринга::Ўейдерна€ѕрограмма>> Ўейдерна€ѕрограммаѕлан;
	static Ўейдерна€ѕрограммаѕлан п_Ўейдерна€ѕрограмма;

	typedef std::map < const std::string, std::shared_ptr< ƒвижок–ендеринга::“екстуры2D>> “екстурыѕлан;
	static “екстурыѕлан п_“екстур;

	typedef std::map < const std::string, std::shared_ptr< ƒвижок–ендеринга::—прайт>> —прайтѕлан;
	static —прайтѕлан п_—прайт;

	typedef std::map < const std::string, std::shared_ptr< ƒвижок–ендеринга::јнимаци€—прайт>> јнимаци€—прайтѕлан;
	static јнимаци€—прайтѕлан п_јнимаци€—прайт;

	static std::string п_ѕуть;
	
};

