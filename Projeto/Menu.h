#ifndef MENU_H
#define MENU_H
#include<iostream>
#include <conio.h>
#include<string>
#include<vector>
#include <locale>
#include "Cartaz.h"
#include "Livro.h"
#include "ItemAcervo.h"
#include "ManterDados.h"
#include "Mapa.h"
#include "Midia.h"
#include "Periodico.h"
#include "Relatorio.h"
#include "TrabalhoConclusao.h"

using namespace std;

class Menu
{
	public:
		Menu();
		~Menu();
		
		//Protótipo chamada dos menus
		void menu_principal(vector <ItemAcervo*> &items);
		
		//Protótipo da função do menu principal
		void menu(int &opcao);
		
		//Protótipo da função do menu
		void menu_um(int &opcao);
		
		//Protótipo da função do menu
		void menu_um_um(int &opcao);
		
		//Protótipo da função do menu
		void menu_dois(int &opcao);
		
		//Protótipo da função do menu
		void menu_tres(int &opcao);
		
		//Protótipo da função do menu
		void menu_quatro(int &opcao);
		
		//Protótipo de função para menu para cadastrar item no acervo
		void menu_cadastrar(int &opcao);
		
		//Protótipo de função para listagem dos items
		void listagem(int &opcao,ManterDados *manterdados,vector <ItemAcervo*> &items);
		
		//Protótipo de função para cadastrar item no Acervo
		void cadastrando_item(int &opcao,ManterDados *manterdados,vector <ItemAcervo*> &items);

	protected:
};

#endif
