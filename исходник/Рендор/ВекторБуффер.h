#pragma once 
#include <glad/glad.h>

namespace ДвижокРендеринга {

	class ВекторБуффер
	{
	public:
		 ВекторБуффер();
		~ВекторБуффер();

		ВекторБуффер(const ВекторБуффер&) = delete;
		ВекторБуффер& operator = (const ВекторБуффер&) = delete;
		ВекторБуффер& operator = ( ВекторБуффер&& векторБуффер) noexcept;
		ВекторБуффер(ВекторБуффер&& векторБуффер) noexcept;

		void инит(const void* данные, const unsigned int размер);
		void обновление(const void* данные, const unsigned int размер) const;
		void связывать() const;
		void развязывать() const;
	private:
		GLuint п_id;
	};


}