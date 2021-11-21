#include "–ендор.h"

namespace ƒвижок–ендеринга {

	 void –ендор::рисовать(const ¬екторћножество& векторћножество, const »ндексЅуффер& индексЅуффер, const Ўейдерна€ѕрограмма& шейдерна€)
	{
		 шейдерна€.вкл();
		 векторћножество.св€зывать();
		 индексЅуффер.св€зывать();

		 glDrawElements(GL_TRIANGLES, индексЅуффер.получить—читать(), GL_UNSIGNED_INT, nullptr);
	}
	 void –ендор::установить„истый÷вет(float к, float г, float с, float а)
	 {
		 glClearColor(к, г, с, а);
	 }

	 void –ендор::совершенно()
	 {
		 glClear(GL_COLOR_BUFFER_BIT);
	 }

	 void  –ендор::областьѕросмотра(unsigned int шрена, unsigned int высота, unsigned int левое—мещение, unsigned int нижнее—мещение)
	 {
		 glViewport(левое—мещение, нижнее—мещение, шрена, высота);
	 }

	 std::string –ендор::ѕолучитьс—троку–ендерера()
	 {
		return (char*)glGetString(GL_RENDERER);
	 }

	 std::string –ендор::ѕолучить—троку¬ерсии()
	 {
		return (char*)glGetString(GL_VERSION);
	 }
	
}