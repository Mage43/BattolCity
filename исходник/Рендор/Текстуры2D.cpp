#include "Текстуры2D.h"


namespace Рендор {
	Текстуры2D::Текстуры2D(const GLint ширену, GLint высота,
		const unsigned char* данные,
		const unsigned int конал ,
		const GLenum фильтор ,
		const GLenum режимОбтекания )
		:п_ширены(ширену)
		,п_высоты(высота)
	{
		switch (конал)
		{
		case 4:
			п_режим = GL_RGBA;
			break;
		case 3:
			п_режим = GL_RGB;
			break;
		default:
			п_режим = GL_RGB;
			break;
		}

		glGenTextures(1, &п_Текстур);
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, п_Текстур);
		glTexImage2D(GL_TEXTURE_2D, 0, п_режим, п_ширены, п_высоты, 0, п_режим, GL_UNSIGNED_BYTE, данные);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, режимОбтекания);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, режимОбтекания);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, фильтор);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, фильтор);
		glGenerateMipmap(GL_TEXTURE_2D);
		
		glBindTexture(GL_TEXTURE_2D, 0);

	}
	Текстуры2D& Текстуры2D::operator = (Текстуры2D&& текстуры2D)
	{
		glDeleteTextures(1, &п_Текстур);
		п_Текстур = текстуры2D.п_Текстур;
		текстуры2D.п_Текстур = 0;
		п_режим = текстуры2D.п_режим;
		п_ширены = текстуры2D.п_ширены;
		п_высоты = текстуры2D.п_высоты;
		return*this;
	}


	Текстуры2D::Текстуры2D(Текстуры2D&& текстуры2D)
	{
		п_Текстур =  текстуры2D.п_Текстур;
		текстуры2D.п_Текстур = 0;
		п_режим = текстуры2D.п_режим;
		п_ширены = текстуры2D.п_ширены;
		п_высоты = текстуры2D.п_высоты;

	}


	Текстуры2D::~Текстуры2D()
	{
		glDeleteTextures(1, &п_Текстур);
	}


	void Текстуры2D::связывать()const
	{
		glBindTexture(GL_TEXTURE_2D, п_Текстур);
	}
}