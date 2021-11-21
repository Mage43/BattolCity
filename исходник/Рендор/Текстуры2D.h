#pragma once 

#include <string>
#include <map>
#include <glad/glad.h>
#include <glm/vec2.hpp>

namespace ДвижокРендеринга { 
	class Текстуры2D
	{
	public:

		struct РасположениеТекстур2D
		{
			glm::vec2 СлеваВнизуUV;

			glm::vec2 ПравоСверхуUV;


			РасположениеТекстур2D(const glm::vec2& _СлеваВнизуUV, const glm::vec2& _ПравоСверхуUV)
				: СлеваВнизуUV(_СлеваВнизуUV)

				, ПравоСверхуUV(_ПравоСверхуUV)
			{}

			РасположениеТекстур2D()
				: СлеваВнизуUV(0.f)

				, ПравоСверхуUV(1.f)
			{}
		};

		Текстуры2D(const GLint ширену,  GLint высота, 
			       const unsigned char* данные, 
			       const unsigned int конал = 4, 
			       const GLenum фильтор = GL_LINEAR, 
			       const GLenum режимОбтекания = GL_CLAMP_TO_EDGE);
		Текстуры2D() = delete;
		Текстуры2D(const Текстуры2D&) = delete;
		Текстуры2D& operator = (const Текстуры2D&) = delete;
		Текстуры2D& operator = (Текстуры2D&& текстуры2D);
		Текстуры2D(Текстуры2D&& текстуры2D);
		~Текстуры2D();

		void добавлятьРасположениеТекстур(std::string имя, const glm::vec2& СлеваВнизуUV, const glm::vec2& ПравоСверхуUV);
		const РасположениеТекстур2D& получитьРасположениеТекстур(const std::string& имя) const;
		unsigned int ширена() const { return п_ширены; }
		unsigned int высота() const { return п_высоты; }

		void связывать()const;

	private:
		GLuint п_Текстур;
		GLenum п_режим;
		unsigned int п_ширены;
        unsigned int п_высоты;

		std::map<std::string, РасположениеТекстур2D> п_расположениеТекстур;
	};

}
