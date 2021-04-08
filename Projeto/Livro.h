#ifndef LIVRO_H
#define LIVRO_H
#include "ItemAcervo.h"
#include<string.h>

//Struct para item com ISBN
struct StructItemAcervoISBN{
	int id;
	char titulo_obra[100];
	int num_edicao;
	char cidade[100];
	char editora[100];
	int ano;
	int num_pag;
	float tam_cm;
	char assunto[100];
	int quant_exemplares;
	int quant_atual;
	char tipo[100];
	char CDU[100];
	char autores[1000];
	char palavraschaves[1000];
	char ISBN[100];
};

class Livro: public ItemAcervo
{
	private:
		string ISBN;
	public:
		Livro();
		Livro(int id,vector<string> autores,string titulo_obra,int num_edicao,string cidade,string editora,int ano,int num_pag,float tam_cm,string assunto,int quant_exemplares,int quant_atual,string tipo,vector<string>palavras_chave,string CDU,string ISBN);
		~Livro();
		string getISBN();
		void setISBN(string ISBN);
		void exibirInformacoes();
		void fichacatalografica();
		StructItemAcervoISBN copyStructISBN();
		
	protected:
};

#endif
