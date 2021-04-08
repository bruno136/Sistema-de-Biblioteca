#include "Menu.h"

Menu::Menu()
{
}

Menu::~Menu()
{
}

void Menu::menu(int &opcao){
	cout << endl << endl << "\tBiblioteca Universit�ria" << endl;
	cout << "1 - Emprestar item de Acervo" << endl;
	cout << "2 - Pesquisar Informa��es de item de Acervo" << endl;
	cout << "3 - Fornecer ficha catalogr�fica de item de Acervo" << endl;
	cout << "4 - Manter item de Acervo" << endl;
	cout << "5 - Sair" << endl;
	cout << "Entre com a op��o desejada: ";
	cin >> opcao;
	cin.clear();
	fflush(stdin);
	if(opcao < 1 || opcao > 5){
		cout << endl << "Op�a� Inv�lida!!!" << endl;
		cout << "Entre com uma op��o v�lida!!!" << endl;
	}
}

void Menu::menu_um(int &opcao){
	cout << endl << endl << "\tBiblioteca Universit�ria" << endl;
	cout << "1 - Listar itens de Acervo" << endl;
	cout << "2 - Emprestar item de Acervo por c�digo" << endl;
	cout << "3 - Voltar ao Menu principal" << endl;
	cout << "Entre com a op��o desejada: ";
	cin >> opcao;
	cin.clear();
	fflush(stdin);
	if(opcao < 1 || opcao > 3){
		cout << endl << "Op�a� Inv�lida!!!" << endl;
		cout << "Entre com uma op��o v�lida!!!" << endl;
	}
}

void Menu::menu_um_um(int &opcao){
	cout << endl << endl << "\tBiblioteca Universit�ria" << endl;
	cout << "1 - Listar todos os itens de Acervo" << endl;
	cout << "2 - Listar Livros" << endl;
	cout << "3 - Listar Per�odicos" << endl;
	cout << "4 - Listar Trabalhos de Conclus�o" << endl;
	cout << "5 - Listar Relat�rios" << endl;
	cout << "6 - Listar M�dias" << endl;
	cout << "7 - Listar Cartazes" << endl;
	cout << "8 - Listar Mapas" << endl;
	cout << "9 - Voltar ao menu anterior" << endl;
	cout << "Entre com a op��o desejada: ";
	cin >> opcao;
	cin.clear();
	fflush(stdin);
	if(opcao < 1 || opcao > 9){
		cout << endl << "Op�a� Inv�lida!!!" << endl;
		cout << "Entre com uma op��o v�lida!!!" << endl;
	}		
}

void Menu::menu_dois(int &opcao){
	cout << endl << endl << "\tBiblioteca Universit�ria" << endl;
	cout << "1 - Listar itens de Acervo" << endl;
	cout << "2 - Pesquisar informa��es item de acervo" << endl;
	cout << "3 - Voltar ao Menu principal" << endl;
	cout << "Entre com a op��o desejada: ";
	cin >> opcao;
	cin.clear();
	fflush(stdin);
	if(opcao < 1 || opcao > 3){
		cout << endl << "Op�a� Inv�lida!!!" << endl;
		cout << "Entre com uma op��o v�lida!!!" << endl;
	}
}

void Menu::menu_tres(int &opcao){
	cout << endl << endl << "\tBiblioteca Universit�ria" << endl;
	cout << "1 - Listar itens de Acervo" << endl;
	cout << "2 - Fornecer ficha catalogr�fica de item de acervo" << endl;
	cout << "3 - Voltar ao Menu principal" << endl;
	cout << "Entre com a op��o desejada: ";
	cin >> opcao;
	cin.clear();
	fflush(stdin);
	if(opcao < 1 || opcao > 3){
		cout << endl << "Op�a� Inv�lida!!!" << endl;
		cout << "Entre com uma op��o v�lida!!!" << endl;
	}
}

void Menu::menu_quatro(int &opcao){
	cout << endl << endl << "\tBiblioteca Universit�ria" << endl;
	cout << "1 - Listar itens de Acervo" << endl;
	cout << "2 - Cadastrar item de Acervo" << endl;
	cout << "3 - Alterar item de Acervo" << endl;
	cout << "4 - Deletar item de Acervo" << endl;
	cout << "5 - Voltar ao Menu principal" << endl;
	cout << "Entre com a op��o desejada: ";
	cin >> opcao;
	cin.clear();
	fflush(stdin);
	if(opcao < 1 || opcao > 5){
		cout << endl << "Op�a� Inv�lida!!!" << endl;
		cout << "Entre com uma op��o v�lida!!!" << endl;
	}
}

//Fun��o para menu para cadastrar item no acervo
void Menu::menu_cadastrar(int &opcao){
	cout << endl << endl << "\tBiblioteca Universit�ria" << endl;
	cout << "1 - Cadastrar Livro" << endl;
	cout << "2 - Cadastrar Per�odico" << endl;
	cout << "3 - Cadastrar Trabalhos de Conclus�o" << endl;
	cout << "4 - Cadastrar Relat�rio" << endl;
	cout << "5 - Cadastrar M�dia" << endl;
	cout << "6 - Cadastrar Cartaz" << endl;
	cout << "7 - Cadastrar Mapa" << endl;
	cout << "8 - Voltar ao menu anterior" << endl;
	cout << "Entre com a op��o desejada: ";
	cin >> opcao;
	cin.clear();
	fflush(stdin);
	if(opcao < 1 || opcao > 8){
		cout << endl << "Op�a� Inv�lida!!!" << endl;
		cout << "Entre com uma op��o v�lida!!!" << endl;
	}				
}

//Prot�tipo para listagem dos items
void Menu::listagem(int &opcao,ManterDados *manterdados,vector <ItemAcervo*> &items){
	if(opcao == 1){
		manterdados->listar_todos_Items(items);
	}
	else if(opcao == 2){
		manterdados->listar_livros(items);
	}
	else if(opcao == 3){
		manterdados->listar_periodicos(items);
	}
	else if(opcao == 4){
		manterdados->listar_trabalhos(items);
	}
	else if(opcao == 5){
		manterdados->listar_relatorios(items);
	}
	else if(opcao == 6){
		manterdados->listar_midias(items);
	}
	else if(opcao == 7){
		manterdados->listar_cartazes(items);
	}
	else if(opcao == 8){
		manterdados->listar_mapas(items);
	}
}

//Fun��o para cadastrar item no Acervo
void Menu::cadastrando_item(int &opcao,ManterDados *manterdados,vector <ItemAcervo*> &items){
	
	int id = 0;
	id = items.size();
	
	if(opcao == 1){
		//Fun��o para criar Livro
		Livro* livro = manterdados->criarLivro(id);
		//Fun��o para adicionar itens no vetor
		manterdados->addVetorItem(items,livro);
	}
	
	if(opcao == 2){
		//Fun��o para criar Periodico
		Periodico * periodico = manterdados->criarPeriodico(id);
		//Fun��o para adicionar itens no vetor
		manterdados->addVetorItem(items,periodico);
	}
	
	if(opcao == 3){
		//Fun��o para criar Trabalho conclus�o
		TrabalhoConclusao * trabalho = manterdados->criarTrabalhoConclusao(id);
		//Fun��o para adicionar itens no vetor
		manterdados->addVetorItem(items,trabalho);
	}
	
	if(opcao == 4){
		//Fun��o para criar Relatorio
		Relatorio * relatorio = manterdados->criarRelatorio(id);
		//Fun��o para adicionar itens no vetor
		manterdados->addVetorItem(items,relatorio);
	}
	
	if(opcao == 5){
		//Fun��o para criar M�dia
		Midia * midia = manterdados->criarMidia(id);
		//Fun��o para adicionar itens no vetor
		manterdados->addVetorItem(items,midia);
	}
	
	if(opcao == 6){
		//Fun��o para criar Cartaz
		Cartaz * cartaz = manterdados->criarCartaz(id);
		//Fun��o para adicionar itens no vetor
		manterdados->addVetorItem(items,cartaz);
	}
	
	if(opcao == 7){
		//Fun��o para criar Mapa
		Mapa * mapa = manterdados->criarMapa(id);
		//Fun��o para adicionar itens no vetor
		manterdados->addVetorItem(items,mapa);
	}	
}

//Fun��o para chamada dos menus
void Menu::menu_principal(vector <ItemAcervo*> &items){
	
	//Instanciando classe para manipular dados dos Items do Acervo
	ManterDados *manterdados = new ManterDados();
	
	//Ordenando o vector em caso de ler do arquivo
	manterdados->ordenar(items);
	
	//Olha o tamnho do vetor
	//cout << endl << items.size();
	
	//Vari�veis auxiliar para menu
	int opcao = 0,opcao1_1 = 0,opcao1_2 = 0,opcao2_1 = 0,opcao2_2 = 0,opcao3_1 = 0,opcao3_2 = 0,opcao4_1 = 0;
	int opcao4_2 = 0,opcao4_3 = 0;
	
	do{
		
		//Menu principal
		menu(opcao);
		
		//Caso escolher a op��o 1 do menu principal
		if(opcao == 1){
			
			do{
				
				//Outro Menu caso escolher a op��o 1
				menu_um(opcao1_1);
				
				if(opcao1_1 == 1){
					
					do{
						
						menu_um_um(opcao1_2);
						
						//Listagem de todos os items e categorias do acervo
						listagem(opcao1_2,manterdados,items);
						
						if(opcao1_2 == 9){
							break;
						}
				
					}while(opcao1_2 != 9);
					
				}
				else if(opcao1_1 == 2){
					//Emprestar um item do acervo
					manterdados->emprestarItemAcervo(items);
				}
				else if(opcao == 3){
					break;
				}		
			}while(opcao1_1 != 3);	
		}
		
		//Caso escolher a op��o 2 do menu principal
		if(opcao == 2){
			
			do{
			
				menu_dois(opcao2_1);
				
				if(opcao2_1 == 1){
					
					do{
						menu_um_um(opcao2_2);
						
						//Listagem de todos os items e categorias do acervo
						listagem(opcao2_2,manterdados,items);
						
						if(opcao2_2 == 9){
							break;
						}
						
					}while(opcao2_2 != 9);
				}
				else if(opcao2_1 == 2){
					//Pesquisar Informa��es de item no Acervo
					manterdados->pesquisarInformacoes(items);
				}
				else if(opcao2_1 == 3){
					break;
				}
				
			}while(opcao2_1 != 3);		
		}
		
		//Caso escolher a op��o 3 do menu principal
		if(opcao == 3){
			
			do{
			
				menu_tres(opcao3_1);
				
				if(opcao3_1 == 1){
					
					do{
						menu_um_um(opcao3_2);
						
						//Listagem de todos os items e categorias do acervo
						listagem(opcao3_2,manterdados,items);
						
						if(opcao3_2 == 9){
							break;
						}
						
					}while(opcao3_2 != 9);
				}
				else if(opcao3_1 == 2){
					//Fornecer ficha catalogr�fica de item no Acervo
					manterdados->exibir_fichacatalografica(items);
				}
				else if(opcao3_1 == 3){
					break;
				}
				
			}while(opcao3_1 != 3);
				
		}
		
		//Caso escolher a op��o 4 do menu principal
		if(opcao == 4){
			
			do{
				
				menu_quatro(opcao4_1);
				
				if(opcao4_1 == 1){
					
					do{
						
						menu_um_um(opcao4_2);
						
						//Listagem de todos os items e categorias do acervo
						listagem(opcao4_2,manterdados,items);
						
						if(opcao4_2 == 9){
							break;
						}
						
					}while(opcao4_2 != 9);
				}
				
				else if(opcao4_1 == 2){
					
					do{
						
						menu_cadastrar(opcao4_3);
						
						//Escolhendo a op��o para cadastrar item
						cadastrando_item(opcao4_3,manterdados,items);
						
					}while(opcao4_3 != 8);
					
				}
				else if(opcao4_1 == 3){
					//Atualizando um item
					manterdados->atualizarVetorItem(items);
				}
				else if(opcao4_1 == 4){
					//Removendo um item
					manterdados->removeVetorItem(items);
				}
				else if(opcao4_1 == 5){
					break;
				}
			}while(opcao4_1 != 5);
			
		}
	}while(opcao != 5);
	
	//Desalocando mem�ria das variav�is din�micas usadas
	delete manterdados;
	manterdados = NULL;
	
}
