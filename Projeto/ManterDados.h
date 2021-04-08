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
		
		//Protótipo função para criar Cartaz
		Cartaz* criarCartaz(int cod);
		
		//Protótipo função para criar Livro
		Livro* criarLivro(int cod);
		
		//Protótipo função para criar Mapa
		Mapa *criarMapa(int cod);
		
		//Protótipo função para criar Midia
		Midia* criarMidia(int cod);
		
		//Protótipo função para criar Periódico
		Periodico* criarPeriodico(int cod);
		
		//Protótipo função para criar Relatorio
		Relatorio* criarRelatorio(int cod);
		
		//Protótipo função para criar Trabalho de Conclusão
		TrabalhoConclusao *criarTrabalhoConclusao(int cod);
		
		//Protótipo excessao de opção
		int excessao_opcao(char opcao);
		
		//Protótipo excessao para tipo de mídia
		int excessao_midia(char opcao);
		
		//Protótipo excessao para tipo de períodico
		int excessao_periodico(char opcao);
		
		//Protótipo excessao para tipo de Trbalho de Conclusão
		int excessao_trabalho(char opcao);
		
		//Protótipo para verificar se CDU está no padrão 
		int vericacaoCDU(string CDU);
		
		//Protótipo para verificar se ISBN está no padrão 
		int verificacaoISBN(string ISBN);
		
		//Protótipo para verificar se ISSN está no padrão 
		int verificacaoISSN(string ISSN);
		
		//rotótipo para preencher dados
		void preencheDados(vector<string> &autores,string &titulo_obra,int &num_edicao,string &cidade,string &editora,int &ano,int &num_pag,float &tam_cm,string &assunto,int &quant_exemplares,vector<string> &palavras_chave,string &CDU);
	
		//Protótipo para adicionar itens no vetor
		void addVetorItem(vector <ItemAcervo*> &items, ItemAcervo *item);
		
		//Protótipo para remover item do vetor
		void removeVetorItem(vector <ItemAcervo*> &items);
		
		//Protótipo para atualizar item do vetor
		void atualizarVetorItem(vector <ItemAcervo*> &items);
		
		//Protótipo para listar todos os item
		void listar_todos_Items(vector <ItemAcervo*> &items);
		
		//Protótipo para listar livros
		void listar_livros(vector <ItemAcervo*> &items);
		
		//Protótipo para listar periodicos
		void listar_periodicos(vector <ItemAcervo*> &items);
		
		//Protótipo para listar trabalhos
		void listar_trabalhos(vector <ItemAcervo*> &items);
		
		//Protótipo para listar relatorios
		void listar_relatorios(vector <ItemAcervo*> &items);
		
		//Protótipo para listar midias
		void listar_midias(vector <ItemAcervo*> &items);
		
		//Protótipo para listar cartazes
		void listar_cartazes(vector <ItemAcervo*> &items);
		
		//Protótipo para listar mapas
		void listar_mapas(vector <ItemAcervo*> &items);
		
		//Protótipo função para emprestar livro
		void emprestarItemAcervo(vector <ItemAcervo*> &items);
		
		//Protótipo para pesquisar Informações de item no Acervo
		void pesquisarInformacoes(vector <ItemAcervo*> &items);
		
		//Protótipo função para ficha catalográfica
		void exibir_fichacatalografica(vector <ItemAcervo*> &items);
		
		//Protótipo função para ordenar para elementos
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
