#pragma once 

#include <vector>
#include <string>
#include <memory>

class »»гровыхќбъектов;

class ”ровень 
{
public:
	”ровень(const std::vector<std::string>& уровеньќписание);
	void рендор()const;
	void обновить(const uint64_t дельта);

private:
	size_t п_шерена;
	size_t п_высота;

	std::vector < std::shared_ptr<»»гровыхќбъектов>>п_картыќбъекты;
};