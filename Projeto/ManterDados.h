#ifndef MANTERDADOS_H
#define MANTERDADOS_H
#include<iostream>
#include<string>
#include<vector>
#include <locale>
#include "Cartaz.h"
#include "Livro.h"
#include "ItemAcervo.h"
#include "Mapa.h"
#include "Midia.h"
#include "Periodico.h"
#include "Relatorio.h"
#include "TrabalhoConclusao.h"

using namespace std;

class ManterDados
{
	public:
		ManterDados();
		~ManterDados();
		
		//Prot�tipo fun��o para criar Cartaz
		Cartaz* criarCartaz(int cod);
		
		//Prot�tipo fun��o para criar Livro
		Livro* criarLivro(int cod);
		
		//Prot�tipo fun��o para criar Mapa
		Mapa *criarMapa(int cod);
		
		//Prot�tipo fun��o para criar Midia
		Midia* criarMidia(int cod);
		
		//Prot�tipo fun��o para criar Peri�dico
		Periodico* criarPeriodico(int cod);
		
		//Prot�tipo fun��o para criar Relatorio
		Relatorio* criarRelatorio(int cod);
		
		//Prot�tipo fun��o para criar Trabalho de Conclus�o
		TrabalhoConclusao *criarTrabalhoConclusao(int cod);
		
		//Prot�tipo excessao de op��o
		int excessao_opcao(char opcao);
		
		//Prot�tipo excessao para tipo de m�dia
		int excessao_midia(char opcao);
		
		//Prot�tipo excessao para tipo de per�odico
		int excessao_periodico(char opcao);
		
		//Prot�tipo excessao para tipo de Trbalho de Conclus�o
		int excessao_trabalho(char opcao);
		
		//Prot�tipo para verificar se CDU est� no padr�o 
		int vericacaoCDU(string CDU);
		
		//Prot�tipo para verificar se ISBN est� no padr�o 
		int verificacaoISBN(string ISBN);
		
		//Prot�tipo para verificar se ISSN est� no padr�o 
		int verificacaoISSN(string ISSN);
		
		//rot�tipo para preencher dados
		void preencheDados(vector<string> &autores,string &titulo_obra,int &num_edicao,string &cidade,string &editora,int &ano,int &num_pag,float &tam_cm,string &assunto,int &quant_exemplares,vector<string> &palavras_chave,string &CDU);
	
		//Prot�tipo para adicionar itens no vetor
		void addVetorItem(vector <ItemAcervo*> &items, ItemAcervo *item);
		
		//Prot�tipo para remover item do vetor
		void removeVetorItem(vector <ItemAcervo*> &items);
		
		//Prot�tipo para atualizar item do vetor
		void atualizarVetorItem(vector <ItemAcervo*> &items);
		
		//Prot�tipo para listar todos os item
		void listar_todos_Items(vector <ItemAcervo*> &items);
		
		//Prot�tipo para listar livros
		void listar_livros(vector <ItemAcervo*> &items);
		
		//Prot�tipo para listar periodicos
		void listar_periodicos(vector <ItemAcervo*> &items);
		
		//Prot�tipo para listar trabalhos
		void listar_trabalhos(vector <ItemAcervo*> &items);
		
		//Prot�tipo para listar relatorios
		void listar_relatorios(vector <ItemAcervo*> &items);
		
		//Prot�tipo para listar midias
		void listar_midias(vector <ItemAcervo*> &items);
		
		//Prot�tipo para listar cartazes
		void listar_cartazes(vector <ItemAcervo*> &items);
		
		//Prot�tipo para listar mapas
		void listar_mapas(vector <ItemAcervo*> &items);
		
		//Prot�tipo fun��o para emprestar livro
		void emprestarItemAcervo(vector <ItemAcervo*> &items);
		
		//Prot�tipo para pesquisar Informa��es de item no Acervo
		void pesquisarInformacoes(vector <ItemAcervo*> &items);
		
		//Prot�tipo fun��o para ficha catalogr�fica
		void exibir_fichacatalografica(vector <ItemAcervo*> &items);
		
		//Prot�tipo fun��o para ordenar para elementos
		void ordenar(vector <ItemAcervo*> &items);
		
	protected:
};

#endif
#ifndef MANTERDADOS_H
#define MANTERDADOS_H

class ManterDados
{
	public:
		ManterDados();
		~ManterDados();
	protected:
};

#endif
