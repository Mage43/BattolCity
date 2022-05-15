#pragma once

#include "»»гровыхќбъектов.h"

#include <memory>
namespace ƒвижок–ендеринга {
	class —прайт;

}

class  ирпична€—тена : public »»гровыхќбъектов 
{
public:
	 ирпична€—тена(const std::shared_ptr<ƒвижок–ендеринга::—прайт> п—прайт , const glm::vec2& позици€, const glm::vec2& размер, const float вращение);
	virtual void рендор() const override;
	virtual void обновить(const uint64_t дельта) override;
 
private:
	std::shared_ptr<ƒвижок–ендеринга::—прайт> п_п“екущий—прайт;
};

