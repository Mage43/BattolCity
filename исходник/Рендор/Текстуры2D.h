#pragma once 

#include<string>
#include<glad/glad.h>

namespace Рендор {
	class Текстуры2D
	{
	public:
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

		void связывать()const;

	private:
		GLuint п_Текстур;
		GLenum п_режим;
		unsigned int п_ширены;
        unsigned int п_высоты;
	};

}
