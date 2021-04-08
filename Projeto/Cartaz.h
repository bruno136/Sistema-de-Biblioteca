#ifndef CARTAZ_H
#define CARTAZ_H
#include "ItemAcervo.h"

class Cartaz: public ItemAcervo
{
	public:
		Cartaz();
		Cartaz(int id,vector<string> autores,string titulo_obra,int num_edicao,string cidade,string editora,int ano,int num_pag,float tam_cm,string assunto,int quant_exemplares,int quant_atual,string tipo,vector<string>palavras_chave,string CDU);
		~Cartaz();
		
		void exibirInformacoes();
		void fichacatalografica();
		
	protected:
};

#endif
