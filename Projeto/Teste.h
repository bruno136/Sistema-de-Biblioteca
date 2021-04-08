#ifndef TESTE_H
#define TESTE_H
#include "ItemAcervo.h"

class Teste: public ItemAcervo
{
	public:
		Teste();
		Teste(string titulo_obra,int num_edicao,string cidade);
		~Teste();
	protected:
};

#endif
