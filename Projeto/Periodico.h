#ifndef PERIODICO_H
#define PERIODICO_H
#include "ItemAcervo.h"
#include<string.h>

//Struct para item com ISSN
struct StructItemAcervoISSN{
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
	char ISSN[100];
};

class Periodico: public ItemAcervo
{
	private:
		string ISSN;
	public:
		Periodico();
		Periodico(int id,vector<string> autores,string titulo_obra,int num_edicao,string cidade,string editora,int ano,int num_pag,float tam_cm,string assunto,int quant_exemplares,int quant_atual,string tipo,vector<string>palavras_chave,string CDU,string ISSN);
		~Periodico();
		
		string getISSN();
		void setISSN(string ISSN);
		void exibirInformacoes();
		void fichacatalografica();
		StructItemAcervoISSN copyStructISSN();
		
	protected:
};

#endif
