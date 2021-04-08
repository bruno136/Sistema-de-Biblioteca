#include "Menu.h"

Menu::Menu()
{
}

Menu::~Menu()
{
}

void Menu::menu(int &opcao){
	cout << endl << endl << "\tBiblioteca Universitária" << endl;
	cout << "1 - Emprestar item de Acervo" << endl;
	cout << "2 - Pesquisar Informações de item de Acervo" << endl;
	cout << "3 - Fornecer ficha catalográfica de item de Acervo" << endl;
	cout << "4 - Manter item de Acervo" << endl;
	cout << "5 - Sair" << endl;
	cout << "Entre com a opção desejada: ";
	cin >> opcao;
	cin.clear();
	fflush(stdin);
	if(opcao < 1 || opcao > 5){
		cout << endl << "Opçaõ Inválida!!!" << endl;
		cout << "Entre com uma opção válida!!!" << endl;
	}
}

void Menu::menu_um(int &opcao){
	cout << endl << endl << "\tBiblioteca Universitária" << endl;
	cout << "1 - Listar itens de Acervo" << endl;
	cout << "2 - Emprestar item de Acervo por código" << endl;
	cout << "3 - Voltar ao Menu principal" << endl;
	cout << "Entre com a opção desejada: ";
	cin >> opcao;
	cin.clear();
	fflush(stdin);
	if(opcao < 1 || opcao > 3){
		cout << endl << "Opçaõ Inválida!!!" << endl;
		cout << "Entre com uma opção válida!!!" << endl;
	}
}

void Menu::menu_um_um(int &opcao){
	cout << endl << endl << "\tBiblioteca Universitária" << endl;
	cout << "1 - Listar todos os itens de Acervo" << endl;
	cout << "2 - Listar Livros" << endl;
	cout << "3 - Listar Períodicos" << endl;
	cout << "4 - Listar Trabalhos de Conclusão" << endl;
	cout << "5 - Listar Relatórios" << endl;
	cout << "6 - Listar Mídias" << endl;
	cout << "7 - Listar Cartazes" << endl;
	cout << "8 - Listar Mapas" << endl;
	cout << "9 - Voltar ao menu anterior" << endl;
	cout << "Entre com a opção desejada: ";
	cin >> opcao;
	cin.clear();
	fflush(stdin);
	if(opcao < 1 || opcao > 9){
		cout << endl << "Opçaõ Inválida!!!" << endl;
		cout << "Entre com uma opção válida!!!" << endl;
	}		
}

void Menu::menu_dois(int &opcao){
	cout << endl << endl << "\tBiblioteca Universitária" << endl;
	cout << "1 - Listar itens de Acervo" << endl;
	cout << "2 - Pesquisar informações item de acervo" << endl;
	cout << "3 - Voltar ao Menu principal" << endl;
	cout << "Entre com a opção desejada: ";
	cin >> opcao;
	cin.clear();
	fflush(stdin);
	if(opcao < 1 || opcao > 3){
		cout << endl << "Opçaõ Inválida!!!" << endl;
		cout << "Entre com uma opção válida!!!" << endl;
	}
}

void Menu::menu_tres(int &opcao){
	cout << endl << endl << "\tBiblioteca Universitária" << endl;
	cout << "1 - Listar itens de Acervo" << endl;
	cout << "2 - Fornecer ficha catalográfica de item de acervo" << endl;
	cout << "3 - Voltar ao Menu principal" << endl;
	cout << "Entre com a opção desejada: ";
	cin >> opcao;
	cin.clear();
	fflush(stdin);
	if(opcao < 1 || opcao > 3){
		cout << endl << "Opçaõ Inválida!!!" << endl;
		cout << "Entre com uma opção válida!!!" << endl;
	}
}

void Menu::menu_quatro(int &opcao){
	cout << endl << endl << "\tBiblioteca Universitária" << endl;
	cout << "1 - Listar itens de Acervo" << endl;
	cout << "2 - Cadastrar item de Acervo" << endl;
	cout << "3 - Alterar item de Acervo" << endl;
	cout << "4 - Deletar item de Acervo" << endl;
	cout << "5 - Voltar ao Menu principal" << endl;
	cout << "Entre com a opção desejada: ";
	cin >> opcao;
	cin.clear();
	fflush(stdin);
	if(opcao < 1 || opcao > 5){
		cout << endl << "Opçaõ Inválida!!!" << endl;
		cout << "Entre com uma opção válida!!!" << endl;
	}
}

//Função para menu para cadastrar item no acervo
void Menu::menu_cadastrar(int &opcao){
	cout << endl << endl << "\tBiblioteca Universitária" << endl;
	cout << "1 - Cadastrar Livro" << endl;
	cout << "2 - Cadastrar Períodico" << endl;
	cout << "3 - Cadastrar Trabalhos de Conclusão" << endl;
	cout << "4 - Cadastrar Relatório" << endl;
	cout << "5 - Cadastrar Mídia" << endl;
	cout << "6 - Cadastrar Cartaz" << endl;
	cout << "7 - Cadastrar Mapa" << endl;
	cout << "8 - Voltar ao menu anterior" << endl;
	cout << "Entre com a opção desejada: ";
	cin >> opcao;
	cin.clear();
	fflush(stdin);
	if(opcao < 1 || opcao > 8){
		cout << endl << "Opçaõ Inválida!!!" << endl;
		cout << "Entre com uma opção válida!!!" << endl;
	}				
}

//Protótipo para listagem dos items
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

//Função para cadastrar item no Acervo
void Menu::cadastrando_item(int &opcao,ManterDados *manterdados,vector <ItemAcervo*> &items){
	
	int id = 0;
	id = items.size();
	
	if(opcao == 1){
		//Função para criar Livro
		Livro* livro = manterdados->criarLivro(id);
		//Função para adicionar itens no vetor
		manterdados->addVetorItem(items,livro);
	}
	
	if(opcao == 2){
		//Função para criar Periodico
		Periodico * periodico = manterdados->criarPeriodico(id);
		//Função para adicionar itens no vetor
		manterdados->addVetorItem(items,periodico);
	}
	
	if(opcao == 3){
		//Função para criar Trabalho conclusão
		TrabalhoConclusao * trabalho = manterdados->criarTrabalhoConclusao(id);
		//Função para adicionar itens no vetor
		manterdados->addVetorItem(items,trabalho);
	}
	
	if(opcao == 4){
		//Função para criar Relatorio
		Relatorio * relatorio = manterdados->criarRelatorio(id);
		//Função para adicionar itens no vetor
		manterdados->addVetorItem(items,relatorio);
	}
	
	if(opcao == 5){
		//Função para criar Mídia
		Midia * midia = manterdados->criarMidia(id);
		//Função para adicionar itens no vetor
		manterdados->addVetorItem(items,midia);
	}
	
	if(opcao == 6){
		//Função para criar Cartaz
		Cartaz * cartaz = manterdados->criarCartaz(id);
		//Função para adicionar itens no vetor
		manterdados->addVetorItem(items,cartaz);
	}
	
	if(opcao == 7){
		//Função para criar Mapa
		Mapa * mapa = manterdados->criarMapa(id);
		//Função para adicionar itens no vetor
		manterdados->addVetorItem(items,mapa);
	}	
}

//Função para chamada dos menus
void Menu::menu_principal(vector <ItemAcervo*> &items){
	
	//Instanciando classe para manipular dados dos Items do Acervo
	ManterDados *manterdados = new ManterDados();
	
	//Ordenando o vector em caso de ler do arquivo
	manterdados->ordenar(items);
	
	//Olha o tamnho do vetor
	//cout << endl << items.size();
	
	//Variáveis auxiliar para menu
	int opcao = 0,opcao1_1 = 0,opcao1_2 = 0,opcao2_1 = 0,opcao2_2 = 0,opcao3_1 = 0,opcao3_2 = 0,opcao4_1 = 0;
	int opcao4_2 = 0,opcao4_3 = 0;
	
	do{
		
		//Menu principal
		menu(opcao);
		
		//Caso escolher a opção 1 do menu principal
		if(opcao == 1){
			
			do{
				
				//Outro Menu caso escolher a opção 1
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
		
		//Caso escolher a opção 2 do menu principal
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
					//Pesquisar Informações de item no Acervo
					manterdados->pesquisarInformacoes(items);
				}
				else if(opcao2_1 == 3){
					break;
				}
				
			}while(opcao2_1 != 3);		
		}
		
		//Caso escolher a opção 3 do menu principal
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
					//Fornecer ficha catalográfica de item no Acervo
					manterdados->exibir_fichacatalografica(items);
				}
				else if(opcao3_1 == 3){
					break;
				}
				
			}while(opcao3_1 != 3);
				
		}
		
		//Caso escolher a opção 4 do menu principal
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
						
						//Escolhendo a opção para cadastrar item
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
	
	//Desalocando memória das variavéis dinâmicas usadas
	delete manterdados;
	manterdados = NULL;
	
}
