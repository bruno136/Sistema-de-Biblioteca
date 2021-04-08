#ifndef TRABALHOCONCLUSAO_H
#define TRABALHOCONCLUSAO_H
#include "ItemAcervo.h"
#include "Livro.h"

class TrabalhoConclusao: public ItemAcervo
{
	private:
		string ISBN;
		
	public:
		TrabalhoConclusao();
		TrabalhoConclusao(int id,vector<string> autores,string titulo_obra,int num_edicao,string cidade,string editora,int ano,int num_pag,float tam_cm,string assunto,int quant_exemplares,int quant_atual,string tipo,vector<string>palavras_chave,string CDU,string ISBN);
		~TrabalhoConclusao();
		string getISBN();
		void setISBN(string ISBN);
		
		void exibirInformacoes();
		void fichacatalografica();
		StructItemAcervoISBN copyStructISBN();
		
	protected:
};

#endif
