#ifndef ITEMACERVO_H
#define ITEMACERVO_H
#include <iostream>
#include<string>
#include<vector>

using namespace std;

struct StructItemAcervo{
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
};

class ItemAcervo
{
	private:
		int id;
		string titulo_obra;
		int num_edicao;
		string cidade;
		string editora;
		int ano;
		int num_pag;
		float tam_cm;
		string assunto;
		int quant_exemplares;
		int quant_atual;
		string tipo;
		string CDU;
		
	public:
		ItemAcervo();
		ItemAcervo(int id,vector<string> autores,string titulo_obra,int num_edicao,string cidade,string editora,int ano,int num_pag,float tam_cm,string assunto,int quant_exemplares,int quant_atual,string tipo,vector<string>palavras_chave,string CDU);
		virtual~ItemAcervo();
		
		int getId();
		void getAutores(vector<string> autores);
		string getTitulo_obra();
		int getNum_edicao();
		string getCidade();
		string getEditora();
		int getAno();
		int getNum_pag();
		float getTam_cm();
		string getAssunto();
		int getQuant_exemplares();
		int getQuant_atual();
		string getTipo();
		void getPalavras_chave(vector<string>palavras_chave);
		string getCDU();
		
		void setId(int id);
		void setAutores(vector<string> autores);
		void setTitulo_obra(string titulo_obra);
		void setNum_edicao(int num_edicao);
		void setCidade(string cidade);
		void setEditora(string editora);
		void setAno(int ano);
		void setNum_pag(int num_pag);
		void setTam_cm(float tam_cm);
		void setAssunto(string assunto);
		void setQuantExemplares(int quant_exemplares);
		void setQuantAtual(int quant_atual);
		void setTipo(string tipo);
		void setPalavras_chave(vector<string>palavras_chave);
		void setCDU(string CDU);
		void limpar_autores_palavraschave();
		
		void exibirInformacoes();
		
		StructItemAcervo copyStruct();
	
		
	protected:
		vector<string> autores;
		vector<string>palavras_chave;
};

#endif
