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
		
		//Prot�tipo chamada dos menus
		void menu_principal(vector <ItemAcervo*> &items);
		
		//Prot�tipo da fun��o do menu principal
		void menu(int &opcao);
		
		//Prot�tipo da fun��o do menu
		void menu_um(int &opcao);
		
		//Prot�tipo da fun��o do menu
		void menu_um_um(int &opcao);
		
		//Prot�tipo da fun��o do menu
		void menu_dois(int &opcao);
		
		//Prot�tipo da fun��o do menu
		void menu_tres(int &opcao);
		
		//Prot�tipo da fun��o do menu
		void menu_quatro(int &opcao);
		
		//Prot�tipo de fun��o para menu para cadastrar item no acervo
		void menu_cadastrar(int &opcao);
		
		//Prot�tipo de fun��o para listagem dos items
		void listagem(int &opcao,ManterDados *manterdados,vector <ItemAcervo*> &items);
		
		//Prot�tipo de fun��o para cadastrar item no Acervo
		void cadastrando_item(int &opcao,ManterDados *manterdados,vector <ItemAcervo*> &items);

	protected:
};

#endif
