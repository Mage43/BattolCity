#pragma once

#include <glm/vec2.hpp>

class »»гровыхќбъектов
{
public:
	»»гровыхќбъектов(const glm::vec2& позици€, const glm::vec2& размер, const float вращение);
	virtual void рендор() const = 0;
	virtual void обновить(const uint64_t дельта) = 0;
	virtual ~»»гровыхќбъектов() ;

protected:
	glm::vec2 п_позици€;
	glm::vec2 п_размер;
	float п_вращение;

};


