#include<iostream>
#include <conio.h>
#include<string>
#include<vector>
#include <locale>
#include "ItemAcervo.h"
#include "Salvardados.h"
#include "Menu.h"
#define usua "admin"
#define login "12345"

using namespace std;

//Padr�o CDU:  nnn.nn:nnn.nn
//Padr�o ISBN: nn-nnnn-nnn-n
//Padr�o ISSN: nnnn-nnnn

//Prot�tipo de fun��o para acesso no sistema
int acesso(char senha[6],char usuario[6]);

int main(int argc, char** argv) {
	
	//Biblioteca Portuguesa
	setlocale(LC_ALL,"Portuguese");
	system("chcp 1252 > nul");
	
	//Vari�veis para usu�rio e login do sistema
	char senha[6],usuario[6];
	
	//Criando vector array ItemAcervo
	vector <ItemAcervo*> items;
	
	//Abrindo o arquivo para ler dados
	SalvarDados *salvardados = new SalvarDados();
	salvardados->lerDadosItemBinario(items);
	
	
	cout << endl << endl << "\tBiblioteca Universit�ria" << endl;
	
	//Login para entrar no sistema
	do{
	}while(acesso(senha,usuario));
	
	//Se passar desse do while quer dizer que foi efetuado com sucesso
	cout << endl << endl << "Login efetuado com sucesso!!!" << endl << endl;
	
	//Instanciando Menu
	Menu *menu = new Menu();
	
	//Chamando menu para opera��es
	menu->menu_principal(items);
	
	//Salvando os dados de cada categoria de item em seu respectivo arquivo bin�rio
	salvardados->SalvarDadosItemBinario(items);
	
	//Desalocando a mem�ria do vector de items
	for(vector <ItemAcervo*>::iterator it = items.begin(); it != items.end(); it++){
		delete(*it);
		*it = NULL;
	}
	
	//Limpando tudo
	items.clear();
	items.resize(0);
	
	//Desalocando mem�ria das variav�is din�micas usadas
	delete menu;
	menu = NULL;
	
	delete salvardados;
	salvardados = NULL;
	
	return 0;
}

//Fun��o para acesso no sistema
int acesso(char senha[6],char usuario[6]){
		cout << endl << "Login: ";
		cin >> usuario;
		cin.clear();
		fflush(stdin);
		cout << "Senha: ";
		for(int i = 0;i<6;i++){
			if(i == 5){
				senha[i] = '\0'; // termina a string.
				break;
			}
			senha[i] = getch();
        	printf ("*");
		}
        cin.clear();
        fflush(stdin);
        if(strcmp(login,senha) == 0 && strcmp(usua,usuario) == 0){
			return 0;
		}
		else{
			cout << endl << endl << "Login ou Senha Incorreta!!!" << endl << endl;
			return 1;
		}
}
