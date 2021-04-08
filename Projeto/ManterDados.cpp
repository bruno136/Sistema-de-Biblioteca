#include "ManterDados.h"

ManterDados::ManterDados()
{
}

ManterDados::~ManterDados()
{
}

//Função para excessão de opção
int ManterDados::excessao_opcao(char opcao){
	try{
		if(opcao == 'S' || opcao == 's'){
			throw 1;
		}
		else if (opcao == 'N' || opcao == 'n'){
			return 0;
		}
		else{
			cout << endl << "Opção Inválida!!";
			return -1;
		}
	}catch(int repetir){
		if(repetir == 1){
			return 1;
		}	
	}
}

//Função para tipo de mídia
int ManterDados::excessao_midia(char opcao){
	
	//(F - Fita | V - VHS | C - CD | D - DVD)
	if(opcao == 'F'){
		return 1;
	}
	else if (opcao == 'V'){
		return 2;
	}
	else if (opcao == 'C'){
		return 3;
	}
	else if (opcao == 'D'){
		return 4;
	}
	else{
		cout << endl << "Opção Inválida!!";
		return -1;
	}
}

//Função para para tipo de períodico
int ManterDados::excessao_periodico(char opcao){
	
	//(R - Revista | J - Jornal)
	if(opcao == 'R'){
		return 1;
	}
	else if (opcao == 'J'){
		return 2;
	}
	else{
		cout << endl << "Opção Inválida!!";
		return -1;
	}
}

//Função para tipo de Trabalho de Conclusão
int ManterDados::excessao_trabalho(char opcao){
	
	//(M - Monografia | D - Dissertação | T - Tese)
	if(opcao == 'M'){
		return 1;
	}
	else if (opcao == 'D'){
		return 2;
	}
	else if (opcao == 'T'){
		return 3;
	}
	else{
		cout << endl << "Opção Inválida!!";
		return -1;
	}
	
}

//Função para verificar se CDU está no padrão 
int ManterDados::vericacaoCDU(string CDU){
	if(CDU[3] != '.' || CDU[6] != ':' || CDU[10] != '.' || CDU.length() != 13){
		cout << endl << "O campo CDU deve ter 13 digitos!!!" << endl;
		return 1;
	}
	else{
		return 0;
	}
}

//Função para verificar se ISBN está no padrão 
int ManterDados::verificacaoISBN(string ISBN){
	if(ISBN[2] != '-' || ISBN[7] != '-' || ISBN[11] != '-' || ISBN.length() !=  13){
		cout << endl << "O campo ISBN deve ter 13 digitos!!!" << endl;
		return 1;
	}
	else{
		return 0;
	}
}
		
//Função para verificar se ISSN está no padrão 
int ManterDados::verificacaoISSN(string ISSN){
	if(ISSN[4] != '-' ||  ISSN.length() != 9){
		cout << endl << "O campo ISSN deve ter 9 digitos!!!" << endl;
		return 1;
	}
	else{
		return 0;
	}
}
						
//Função para preencher dados com dados no item a ser cadastrado
void ManterDados::preencheDados(vector<string> &autores,string &titulo_obra,int &num_edicao,string &cidade,string &editora,int &ano,int &num_pag,float &tam_cm,string &assunto,int &quant_exemplares,vector<string> &palavras_chave,string &CDU){
	
	string nome;
	char opcao;
	int i = 0;
	
	do{
		cout << endl << "Digite o nome do " << i+1 << "° autor: ";
		i++;
		getline(cin,nome);
		cin.clear();
		fflush(stdin);
		autores.push_back(nome);
		cout << endl << "Deseja inserir mais um autor: (S|N): ";
		cin >> opcao;
		cin.clear();
		fflush(stdin);
	}while(excessao_opcao(opcao) == 1);
	
	cout << endl << "Digite o título da obra: ";
	getline(cin,titulo_obra);
	cin.clear();
	fflush(stdin);
	
	string pal_chave;
	i = 0;
	
	do{
		cout << endl << "Digite a " << i+1 << "° palavra chave: ";
		i++;
		getline(cin,pal_chave);
		cin.clear();
		fflush(stdin);
		palavras_chave.push_back(pal_chave);
		cout << endl << "Deseja inserir mais uma palavra chave: (S|N): ";
		cin >> opcao;
		cin.clear();
		fflush(stdin);
	}while(excessao_opcao(opcao) == 1);
	

	cout << endl << "Digite o número da edição: ";
	cin >> num_edicao;
	cin.clear();
	fflush(stdin);
	
	cout << endl << "Digite a cidade: ";
	getline(cin,cidade);
	cin.clear();
	fflush(stdin);
	
	cout << endl << "Digite a Editora: ";
	getline(cin,editora);
	cin.clear();
	fflush(stdin);
	
	cout << endl << "Digite o ano: ";
	cin >> ano;
	cin.clear();
	fflush(stdin);
	
	cout << endl << "Digite o número de páginas: ";
	cin >> num_pag;
	cin.clear();
	fflush(stdin);
	
	cout << endl << "Digite o tamanho das páginas (cm): ";
	cin >> tam_cm;
	cin.clear();
	fflush(stdin);
		
	cout << endl << "Digite o assunto: ";
	getline(cin,assunto);
	cin.clear();
	fflush(stdin);
	
	cout << endl << "Digite a quantidade de exemplares: ";
	cin >> quant_exemplares;
	cin.clear();
	fflush(stdin);
	
	do{
		cout << endl << "Digite o CDU: ";
		getline(cin,CDU);
		cin.clear();
		fflush(stdin);
	}while(vericacaoCDU(CDU));
	
	
}

//Função para criar Livro
Livro* ManterDados::criarLivro(int cod){
	
	Livro *livro = NULL;
	vector<string> autores;
	string titulo_obra;
	int num_edicao;
	string cidade;
	string editora;
	int ano;
	int num_pag;
	float tam_cm;
	string ISBN;
	string assunto;
	int quant_exemplares;
	int quant_atual;
	string tipo = "Livro";
	vector<string>palavras_chave;
	string CDU;
	
	cout << endl << "Cadastro de Livro: " << endl;
	preencheDados(autores,titulo_obra,num_edicao,cidade,editora,ano,num_pag,tam_cm,assunto,quant_exemplares,palavras_chave,CDU);
	
	do{
		cout << endl << "Digite O ISBN: ";
		getline(cin,ISBN);
		cin.clear();
		fflush(stdin);		
	}while(verificacaoISBN(ISBN));
	
	
	cod++;
	quant_atual = quant_exemplares;
	
	livro = new Livro(cod,autores,titulo_obra,num_edicao,cidade,editora,ano,num_pag,tam_cm,assunto,quant_exemplares,quant_atual,tipo,palavras_chave,CDU,ISBN);
	
	return livro;
	
}

//Função para criar Cartaz
Cartaz* ManterDados::criarCartaz(int cod){
	
	Cartaz *cartaz = NULL;
	vector<string> autores;
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
	string tipo = "Cartaz";
	vector<string>palavras_chave;
	string CDU;
	
	cout << endl << "Cadastro de Cartaz: " << endl;
	
	preencheDados(autores,titulo_obra,num_edicao,cidade,editora,ano,num_pag,tam_cm,assunto,quant_exemplares,palavras_chave,CDU);
	cod++;
	quant_atual = quant_exemplares;


	cartaz = new Cartaz(cod,autores,titulo_obra,num_edicao,cidade,editora,ano,num_pag,tam_cm,assunto,quant_exemplares,quant_atual,tipo,palavras_chave,CDU);
	
	return cartaz;
}

//Função para criar Mapa
Mapa* ManterDados::criarMapa(int cod){
	
	Mapa *mapa = NULL;
	vector<string> autores;
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
	string tipo = "Mapa";
	vector<string>palavras_chave;
	string CDU;
	
	cout << endl << "Cadastro de Mapa: " << endl;
	
	preencheDados(autores,titulo_obra,num_edicao,cidade,editora,ano,num_pag,tam_cm,assunto,quant_exemplares,palavras_chave,CDU);
	cod++;
	quant_atual = quant_exemplares;
	
	
	mapa = new Mapa(cod,autores,titulo_obra,num_edicao,cidade,editora,ano,num_pag,tam_cm,assunto,quant_exemplares,quant_atual,tipo,palavras_chave,CDU);
	
	return mapa;
}

//Função para criar Midia
Midia* ManterDados::criarMidia(int cod){
	
	Midia *midia = NULL;
	vector<string> autores;
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
	vector<string>palavras_chave;
	string CDU;
	char opcao;
	
	cout << endl << "Cadastro de Mídia: " << endl;
	
	preencheDados(autores,titulo_obra,num_edicao,cidade,editora,ano,num_pag,tam_cm,assunto,quant_exemplares,palavras_chave,CDU);
	cod++;
	quant_atual = quant_exemplares;
	
	//Trecho para escolha do tipo de midia
	do{
		cout << endl << "Digite o tipo da mídia (F - Fita | V - VHS | C - CD | D - DVD): ";
		cin >> opcao;
		cin.clear();
		fflush(stdin);
	}while(excessao_midia(opcao) == -1);
	
	if(excessao_midia(opcao) == 1){
		tipo = "Fita";
	}
	else if(excessao_midia(opcao) == 2){
		tipo = "VHS";
	}
	else if(excessao_midia(opcao) == 3){
		tipo = "CD";
	}
	else{
		tipo = "DVD";
	}
	
	midia = new Midia(cod,autores,titulo_obra,num_edicao,cidade,editora,ano,num_pag,tam_cm,assunto,quant_exemplares,quant_atual,tipo,palavras_chave,CDU);
	
	return midia;
}

//Função para criar Periódico
Periodico* ManterDados::criarPeriodico(int cod){
	
	Periodico *periodico = NULL;
	vector<string> autores;
	string titulo_obra;
	int num_edicao;
	string cidade;
	string editora;
	int ano;
	int num_pag;
	float tam_cm;
	string ISSN;
	string assunto;
	int quant_exemplares;
	int quant_atual;
	string tipo;
	vector<string>palavras_chave;
	string CDU;
	char opcao;
	
	cout << endl << "Cadastro de Períodico: " << endl;
	
	preencheDados(autores,titulo_obra,num_edicao,cidade,editora,ano,num_pag,tam_cm,assunto,quant_exemplares,palavras_chave,CDU);
	cod++;
	quant_atual = quant_exemplares;
	
	//Trecho para escolha do tipo de periodico
	do{
		cout << endl << "Digite o tipo de períodico (R - Revista | J - Jornal): ";
		cin >> opcao;
		cin.clear();
		fflush(stdin);
	}while(excessao_periodico(opcao) == -1);
	
	if(excessao_periodico(opcao) == 1){
		tipo = "Revista";
	}
	else{
		tipo = "Jornal";
	}
	
	do{
		cout << endl << "Digite o ISSN: ";
		getline(cin,ISSN);
		cin.clear();
		fflush(stdin);	
	}while(verificacaoISSN(ISSN));

	
	periodico = new Periodico(cod,autores,titulo_obra,num_edicao,cidade,editora,ano,num_pag,tam_cm,assunto,quant_exemplares,quant_atual,tipo,palavras_chave,CDU,ISSN);
	
	return periodico;
}

//Função para criar Relatorio
Relatorio* ManterDados::criarRelatorio(int cod){
	
	Relatorio *relatorio = NULL;
	vector<string> autores;
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
	string tipo = "Relatório";
	vector<string>palavras_chave;
	string CDU;
	
	cout << endl << "Cadastro de Relatório: " << endl;
	
	preencheDados(autores,titulo_obra,num_edicao,cidade,editora,ano,num_pag,tam_cm,assunto,quant_exemplares,palavras_chave,CDU);
	cod++;
	quant_atual = quant_exemplares;
	
	relatorio = new Relatorio(cod,autores,titulo_obra,num_edicao,cidade,editora,ano,num_pag,tam_cm,assunto,quant_exemplares,quant_atual,tipo,palavras_chave,CDU);
	
	return relatorio;
}

//Função para criar Trabalho de Conclusão
TrabalhoConclusao* ManterDados::criarTrabalhoConclusao(int cod){
	
	TrabalhoConclusao *trabalho = NULL;
	vector<string> autores;
	string titulo_obra;
	int num_edicao;
	string cidade;
	string editora;
	int ano;
	int num_pag;
	float tam_cm;
	string ISBN;
	string assunto;
	int quant_exemplares;
	int quant_atual;
	string tipo;
	vector<string>palavras_chave;
	string CDU;
	char opcao;
	
	cout << endl << "Cadastro de Trabalho de Conclusão: " << endl;
	
	preencheDados(autores,titulo_obra,num_edicao,cidade,editora,ano,num_pag,tam_cm,assunto,quant_exemplares,palavras_chave,CDU);
	cod++;
	quant_atual = quant_exemplares;
	
	//Trecho para escolha do tipo de trabalho de conclusão
	do{
		cout << endl << "Digite o tipo de trabalho de conclusão (M - Monografia | D - Dissertação | T - Tese): ";
		cin >> opcao;
		cin.clear();
		fflush(stdin);
	}while(excessao_trabalho(opcao) == -1);
	
	if(excessao_trabalho(opcao) == 1){
		tipo = "Monografia";
	}
	else if(excessao_trabalho(opcao) == 2){
		tipo = "Dissertação";
	}
	else{
		tipo = "Tese";
	}
	
	do{
		cout << endl << "Digite O ISBN: ";
		getline(cin,ISBN);
		cin.clear();
		fflush(stdin);		
	}while(verificacaoISBN(ISBN));
	
	trabalho = new TrabalhoConclusao(cod,autores,titulo_obra,num_edicao,cidade,editora,ano,num_pag,tam_cm,assunto,quant_exemplares,quant_atual,tipo,palavras_chave,CDU,ISBN);
	
	return trabalho;
}

//Função para adicionar itens no vetor
void ManterDados::addVetorItem(vector <ItemAcervo*> &items, ItemAcervo *item){
	items.push_back(item);
}

//Função para remover item do acervo
void ManterDados::removeVetorItem(vector <ItemAcervo*> &items){
	
	int id = 0;
	int i=0;
	char opcao;
	int cont = 0;
	cout << endl << "Digite o id do item: ";
	cin >> id;
	cin.clear();
	fflush(stdin);
	
	
	if(!items.empty()){
		for(vector <ItemAcervo*>::iterator it = items.begin(); it != items.end(); it ++) {
			ItemAcervo *item = *it;
			
			//Essa condição é para verificar se quer mesmo remover item
			if(id == item->getId()){
				do{
					cout << endl << item->getTipo() << " \"" << item->getTitulo_obra() << "\" encontrado! Deseja mesmo remove-lo (S/N)?: " ;
					cin >> opcao;
					cin.clear();
					fflush(stdin);
				}while(excessao_opcao(opcao) == -1);
				cont++;	
			}
			
			if((id == item->getId()) && excessao_opcao(opcao) == 1){
				items.erase(items.begin() + i);
				cout << endl << item->getTipo() << " \"" << item->getTitulo_obra() << "\" removido com sucesso !!!" ;
				cont++;
				break;
			}
			i++;
		}
		
		if(cont == 0){
			cout << endl << endl << "Nenhum item com esse id encontrado!!!";
		}
	}
	else{
		cout << endl << "Não existe item no acervo!!!" << endl;
	}
}

//Função para atualizar item do vetor alterar os dados do Item
void ManterDados::atualizarVetorItem(vector <ItemAcervo*> &items){
	
	int id = 0;
	cout << endl << "Digite o id do item: ";
	cin >> id;
	cin.clear();
	fflush(stdin);
	
	if(!items.empty() && (id > 0 && id <= items.size()) ){
		vector<string> autores;
		string titulo_obra;
		int num_edicao;
		string cidade;
		string editora;
		int ano;
		int num_pag;
		float tam_cm;
		string ISBN;
		string ISSN;
		string assunto;
		int quant_exemplares;
		int quant_atual;
		string tipo;
		vector<string>palavras_chave;
		string CDU;
		char opcao;
		int cont =0;
		
			for(vector <ItemAcervo*>::iterator it = items.begin(); it != items.end(); it ++) {
			
				ItemAcervo *item = *it;
				
				//Essa condição é para verificar se quer mesmo atualizar item
				if(id == item->getId()){
					do{
						cout << endl << item->getTipo() << " \"" << item->getTitulo_obra() << "\" encontrado! Deseja mesmo alterar-la (S/N)?: " ;
						cin >> opcao;
						cin.clear();
						fflush(stdin);
					}while(excessao_opcao(opcao) == -1);
					cont++;	
				}
				
				if((id == item->getId()) && dynamic_cast<Mapa*>(item) && excessao_opcao(opcao) == 1){
					Mapa* mapa = dynamic_cast<Mapa*>(item);
					mapa->limpar_autores_palavraschave();
					preencheDados(autores,titulo_obra,num_edicao,cidade,editora,ano,num_pag,tam_cm,assunto,quant_exemplares,palavras_chave,CDU);
					mapa->setAutores(autores),mapa->setTitulo_obra(titulo_obra),mapa->setNum_edicao(num_edicao),mapa->setCidade(cidade),mapa->setEditora(editora);
					mapa->setAno(ano),mapa->setNum_pag(num_pag),mapa->setTam_cm(tam_cm),mapa->setAssunto(assunto),mapa->setQuantExemplares(quant_exemplares),mapa->setQuantAtual(quant_exemplares),mapa->setPalavras_chave(palavras_chave),mapa->setCDU(CDU);
					cout << endl << endl << item->getTipo() << " \"" << item->getTitulo_obra() << "\" atualizado com sucesso!!!";
				}
				else if((id == item->getId()) && dynamic_cast<Cartaz*>(item) && excessao_opcao(opcao) == 1){
					Cartaz* cartaz = dynamic_cast<Cartaz*>(item);
					cartaz->limpar_autores_palavraschave();
					preencheDados(autores,titulo_obra,num_edicao,cidade,editora,ano,num_pag,tam_cm,assunto,quant_exemplares,palavras_chave,CDU);
					cartaz->setAutores(autores),cartaz->setTitulo_obra(titulo_obra),cartaz->setNum_edicao(num_edicao),cartaz->setCidade(cidade),cartaz->setEditora(editora);
					cartaz->setAno(ano),cartaz->setNum_pag(num_pag),cartaz->setTam_cm(tam_cm),cartaz->setAssunto(assunto),cartaz->setQuantExemplares(quant_exemplares),cartaz->setQuantAtual(quant_exemplares),cartaz->setPalavras_chave(palavras_chave),cartaz->setCDU(CDU);
					cout << endl << endl << item->getTipo() << " \"" << item->getTitulo_obra() << "\" atualizado com sucesso!!!";
				}
				else if((id == item->getId()) && dynamic_cast<Livro*>(item) && excessao_opcao(opcao) == 1){
					Livro* livro = dynamic_cast<Livro*>(item);
					livro->limpar_autores_palavraschave();
					preencheDados(autores,titulo_obra,num_edicao,cidade,editora,ano,num_pag,tam_cm,assunto,quant_exemplares,palavras_chave,CDU);
					cout << endl << "Digite O ISBN: ";
					getline(cin,ISBN);
					cin.clear();
					fflush(stdin);
					livro->setAutores(autores),livro->setTitulo_obra(titulo_obra),livro->setNum_edicao(num_edicao),livro->setCidade(cidade),livro->setEditora(editora);
					livro->setAno(ano),livro->setNum_pag(num_pag),livro->setTam_cm(tam_cm),livro->setAssunto(assunto),livro->setQuantExemplares(quant_exemplares);
					livro->setQuantAtual(quant_exemplares),livro->setPalavras_chave(palavras_chave),livro->setCDU(CDU),livro->setISBN(ISBN);
					cout << endl << endl << item->getTipo() << " \"" << item->getTitulo_obra() << "\" atualizado com sucesso!!!";
				}
				else if((id == item->getId()) && dynamic_cast<Midia*>(item) && excessao_opcao(opcao) == 1){
					Midia* midia = dynamic_cast<Midia*>(item);
					midia->limpar_autores_palavraschave();
					cout << endl << "Digite o tipo do trabalho (Fita/VHS/CD/DVD): ";
					getline(cin,tipo);
					cin.clear();
					fflush(stdin);
					preencheDados(autores,titulo_obra,num_edicao,cidade,editora,ano,num_pag,tam_cm,assunto,quant_exemplares,palavras_chave,CDU);
					midia->setAutores(autores),midia->setTitulo_obra(titulo_obra),midia->setNum_edicao(num_edicao),midia->setCidade(cidade),midia->setEditora(editora);
					midia->setAno(ano),midia->setNum_pag(num_pag),midia->setTam_cm(tam_cm),midia->setAssunto(assunto),midia->setQuantExemplares(quant_exemplares);
					midia->setQuantAtual(quant_exemplares),midia->setPalavras_chave(palavras_chave),midia->setCDU(CDU);
					midia->setTipo(tipo);
					cout << endl << endl << item->getTipo() << " \"" << item->getTitulo_obra() << "\" atualizado com sucesso!!!";
				}
				else if((id == item->getId()) && dynamic_cast<Relatorio*>(item) && excessao_opcao(opcao) == 1){
					Relatorio* relatorio = dynamic_cast<Relatorio*>(item);
					relatorio->limpar_autores_palavraschave();
					preencheDados(autores,titulo_obra,num_edicao,cidade,editora,ano,num_pag,tam_cm,assunto,quant_exemplares,palavras_chave,CDU);
					relatorio->setAutores(autores),relatorio->setTitulo_obra(titulo_obra),relatorio->setNum_edicao(num_edicao),relatorio->setCidade(cidade),relatorio->setEditora(editora);
					relatorio->setAno(ano),relatorio->setNum_pag(num_pag),relatorio->setTam_cm(tam_cm),relatorio->setAssunto(assunto);
					relatorio->setQuantExemplares(quant_exemplares),relatorio->setQuantAtual(quant_exemplares);
					relatorio->setPalavras_chave(palavras_chave),relatorio->setCDU(CDU);
					cout << endl << endl << item->getTipo() << " \"" << item->getTitulo_obra() << "\" atualizado com sucesso!!!";
				}
				else if((id == item->getId()) && dynamic_cast<TrabalhoConclusao*>(item) && excessao_opcao(opcao) == 1){
					TrabalhoConclusao* trabalho = dynamic_cast<TrabalhoConclusao*>(item);
					trabalho->limpar_autores_palavraschave();
					cout << endl << "Digite o tipo do trabalho (monografia/dissertação/tese): ";
					getline(cin,tipo);
					cin.clear();
					fflush(stdin);
					preencheDados(autores,titulo_obra,num_edicao,cidade,editora,ano,num_pag,tam_cm,assunto,quant_exemplares,palavras_chave,CDU);
					cout << endl << "Digite O ISBN: ";
					getline(cin,ISBN);
					cin.clear();
					fflush(stdin);
					trabalho->setAutores(autores),trabalho->setTitulo_obra(titulo_obra),trabalho->setNum_edicao(num_edicao),trabalho->setCidade(cidade),trabalho->setEditora(editora);
					trabalho->setAno(ano),trabalho->setNum_pag(num_pag),trabalho->setTam_cm(tam_cm),trabalho->setAssunto(assunto),trabalho->setQuantExemplares(quant_exemplares);
					trabalho->setQuantAtual(quant_exemplares),trabalho->setPalavras_chave(palavras_chave),trabalho->setCDU(CDU),trabalho->setISBN(ISBN);
					trabalho->setTipo(tipo);
					cout << endl << endl << item->getTipo() << " \"" << item->getTitulo_obra() << "\" atualizado com sucesso!!!";
				}
				else if((id == item->getId()) && dynamic_cast<Periodico*>(item) && excessao_opcao(opcao) == 1){
					Periodico* periodico = dynamic_cast<Periodico*>(item);
					periodico->limpar_autores_palavraschave();
					cout << endl << "Digite o tipo do trabalho (revista/jornal): ";
					getline(cin,tipo);
					cin.clear();
					fflush(stdin);
					preencheDados(autores,titulo_obra,num_edicao,cidade,editora,ano,num_pag,tam_cm,assunto,quant_exemplares,palavras_chave,CDU);
					cout << endl << "Digite o ISSN: ";
					getline(cin,ISSN);
					cin.clear();
					fflush(stdin);
					periodico->setAutores(autores),periodico->setTitulo_obra(titulo_obra),periodico->setNum_edicao(num_edicao),periodico->setCidade(cidade),periodico->setEditora(editora);
					periodico->setAno(ano),periodico->setNum_pag(num_pag),periodico->setTam_cm(tam_cm),periodico->setAssunto(assunto),periodico->setQuantExemplares(quant_exemplares);
					periodico->setQuantAtual(quant_exemplares),periodico->setPalavras_chave(palavras_chave),periodico->setCDU(CDU),periodico->setISSN(ISSN);
					periodico->setTipo(tipo);
					cout << endl << endl << item->getTipo() << " \"" << item->getTitulo_obra() << "\" atualizado com sucesso!!!";
				}
				else if(cont == 0){
					cout << endl << "Nenhum item com esse id encontrado no acervo!!!";
				}
		}
			//Verificar caso dê erro
			autores.clear();
			palavras_chave.clear();
	}
	else{
		cout << endl << "Nenhum item no acervo!!!";
	}
}

//Função para listar todos os item
void ManterDados::listar_todos_Items(vector <ItemAcervo*> &items){
	if(!items.empty()){
		for(vector <ItemAcervo*>::iterator it = items.begin(); it != items.end(); it ++) {
				ItemAcervo *item = *it; 
				item->exibirInformacoes();
		}
	}
	else{
		cout << endl << "Nenhum item no acervo!!!";
	}
}

//Função para listar livros
void ManterDados::listar_livros(vector <ItemAcervo*> &items){
	int cont = 0;
	if(!items.empty()){
		for(vector <ItemAcervo*>::iterator it = items.begin(); it != items.end(); it ++) {
			ItemAcervo *item = *it;
			if(dynamic_cast<Livro*>(item)){
				item->exibirInformacoes();
				cont++;
			}
		}
		if(cont == 0){
			cout << endl << "Nenhum Livro no acervo!!!";
		}
	}
	else{
		cout << endl << "Nenhum Livro no acervo!!!";
	}
}

//Função para listar periodicos
void ManterDados::listar_periodicos(vector <ItemAcervo*> &items){
	int cont = 0;
	if(!items.empty()){
		for(vector <ItemAcervo*>::iterator it = items.begin(); it != items.end(); it ++){
			ItemAcervo *item = *it;
			if(dynamic_cast<Periodico*>(item)){
				item->exibirInformacoes();
				cont++;
			}
		}
		if(cont == 0){
			cout << endl << "Nenhum Períodico no acervo!!!";
		}	
	}
	else{
		cout << endl << "Nenhum Períodico no acervo!!!";
	}
}

//Função para listar trabalhos de conclusão
void ManterDados::listar_trabalhos(vector <ItemAcervo*> &items){
	int cont = 0;
	if(!items.empty()){
		for(vector <ItemAcervo*>::iterator it = items.begin(); it != items.end(); it ++) {
			ItemAcervo *item = *it;
			if(dynamic_cast<TrabalhoConclusao*>(item)){
				item->exibirInformacoes();
				cont++;
			}
		}
		if(cont == 0){
			cout << endl << "Nenhum Trabalho de Conclusão no acervo!!!";
		}
	}
	else{
		cout << endl << "Nenhum Trabalho de Conclusão no acervo!!!";
	}
}

//Função para listar relatorios	
void ManterDados::listar_relatorios(vector <ItemAcervo*> &items){
	int cont = 0;
	if(!items.empty()){
		for(vector <ItemAcervo*>::iterator it = items.begin(); it != items.end(); it ++) {
			ItemAcervo *item = *it;
			if(dynamic_cast<Relatorio*>(item)){
				item->exibirInformacoes();
				cont++;
			}
		}
		if(cont == 0){
			cout << endl << "Nenhum Relatório no acervo!!!";
		}
	}
	else{
		cout << endl << "Nenhum Relatório no acervo!!!";
	}
}

//Função para listar midias
void ManterDados::listar_midias(vector <ItemAcervo*> &items){
	int cont = 0;
	if(!items.empty()){
		for(vector <ItemAcervo*>::iterator it = items.begin(); it != items.end(); it ++) {
			ItemAcervo *item = *it;
			if(dynamic_cast<Midia*>(item)){
				item->exibirInformacoes();
				cont++;
			}
		}
		if(cont == 0){
			cout << endl << "Nenhuma Mídia no acervo!!!";
		}
	}
	else{
		cout << endl << "Nenhuma Mídia no acervo!!!";
	}
}

//Função para listar cartazes		
void ManterDados::listar_cartazes(vector <ItemAcervo*> &items){
	int cont = 0;
	if(!items.empty()){
		for(vector <ItemAcervo*>::iterator it = items.begin(); it != items.end(); it ++) {
			ItemAcervo *item = *it;
			if(dynamic_cast<Cartaz*>(item)){
				item->exibirInformacoes();
				cont++;
			}
		}
		if(cont == 0){
			cout << endl << "Nenhum Cartaz no acervo!!!";
		}
	}
	else{
		cout << endl << "Nenhum Cartaz no acervo!!!";
	}
}

//Função para listar mapas		
void ManterDados::listar_mapas(vector <ItemAcervo*> &items){
	int cont = 0;
	if(!items.empty()){
		for(vector <ItemAcervo*>::iterator it = items.begin(); it != items.end(); it ++) {
			ItemAcervo *item = *it;
			if(dynamic_cast<Mapa*>(item)){
				item->exibirInformacoes();
				cont++;
			}
		}
		if(cont == 0){
			cout << endl << "Nenhum Mapa no acervo!!!";
		}
	}
	else{
		cout << endl << "Nenhum Mapa no acervo!!!";
	}
}

//Função para emprestar algum item do acervo
void ManterDados::emprestarItemAcervo(vector <ItemAcervo*> &items){
	
		int id = 0;
		int cont = 0;
		int verifica_id = 0;
		cout << endl << "Digite o id do item: ";
		cin >> id;
		cin.clear();
		fflush(stdin);
		
	if(!items.empty() && (id > 0 && id <= items.size())){
		
		int quant = 0;
		
		for(int i=0; i < items.size();i++){
			if(id == items[i]->getId() && items[i]->getQuant_atual() <= 0){
				verifica_id++;
			}
			if(id == items[i]->getId() && items[i]->getQuant_atual() > 0){
				quant = (items[i]->getQuant_atual()) - 1;
				items[i]->setQuantAtual(quant);
				cout << endl << items[i]->getTipo() << " " << items[i]->getTitulo_obra() << " emprestado!!!" << endl;
				cont ++;
			}
		}
		
		if(cont == 0 && verifica_id != 0){
			cout << endl << "Item indisponível na Biblioteca Universitária!!!" << endl;
		}
		
	}
	else{
		cout << endl << "Nenhum item com esse id no acervo para ser emprestado!!!";
	}
}

//Função para pesquisar Informações de item no Acervo
void ManterDados::pesquisarInformacoes(vector <ItemAcervo*> &items){
	
	if(!items.empty()){
		int id = 0;
		int cont = 0;
		cout << endl << "Digite o id do item: ";
		cin >> id;
		cin.clear();
		fflush(stdin);
		
		for(vector <ItemAcervo*>::iterator it = items.begin(); it != items.end(); it ++) {
			
			ItemAcervo *item = *it;
			
			if((id == item->getId()) && dynamic_cast<Mapa*>(item)){
				Mapa* mapa = dynamic_cast<Mapa*>(item);
				mapa->exibirInformacoes();
				cont++;
			}
			if((id == item->getId()) && dynamic_cast<Cartaz*>(item)){
				Cartaz* cartaz = dynamic_cast<Cartaz*>(item);
				cartaz->exibirInformacoes();
				cont++;
			}
			if((id == item->getId()) && dynamic_cast<Livro*>(item)){
				Livro* livro = dynamic_cast<Livro*>(item);
				livro->exibirInformacoes();
				cont++;
			}
			if((id == item->getId()) && dynamic_cast<Midia*>(item)){
				Midia* midia = dynamic_cast<Midia*>(item);
				midia->exibirInformacoes();
				cont++;
			}
			if((id == item->getId()) && dynamic_cast<Relatorio*>(item)){
				Relatorio* relatorio = dynamic_cast<Relatorio*>(item);
				relatorio->exibirInformacoes();
				cont++;
			}
			if((id == item->getId()) && dynamic_cast<TrabalhoConclusao*>(item)){
				TrabalhoConclusao* trabalho = dynamic_cast<TrabalhoConclusao*>(item);
				trabalho->exibirInformacoes();
				cont++;
			}
			if((id == item->getId()) && dynamic_cast<Periodico*>(item)){
				Periodico* periodico = dynamic_cast<Periodico*>(item);
				periodico->exibirInformacoes();
				cont++;
			}
		}
		
		if(cont == 0){
			cout << endl << "Nenhum item com esse id encontrado no acervo!!!";
		}	
	}
	else{
		cout << endl << "Nenhum item com esse id encontrado no acervo!!!";
	}
}

//Função para visualizar ficha catalográfica de algum item do acervo
void ManterDados::exibir_fichacatalografica(vector <ItemAcervo*> &items){
	
	if(!items.empty()){
		
		int id = 0;
		int cont = 0;
		cout << endl << "Digite o id do item: ";
		cin >> id;
		cin.clear();
		fflush(stdin);
		
		for(vector <ItemAcervo*>::iterator it = items.begin(); it != items.end(); it ++) {
			
			ItemAcervo *item = *it;
			
			if((id == item->getId()) && dynamic_cast<Mapa*>(item)){
				Mapa* mapa = dynamic_cast<Mapa*>(item);
				mapa->fichacatalografica();
				cont++;
			}
			if((id == item->getId()) && dynamic_cast<Cartaz*>(item)){
				Cartaz* cartaz = dynamic_cast<Cartaz*>(item);
				cartaz->fichacatalografica();
				cont++;
			}
			if((id == item->getId()) && dynamic_cast<Livro*>(item)){
				Livro* livro = dynamic_cast<Livro*>(item);
				livro->fichacatalografica();
				cont++;
			}
			if((id == item->getId()) && dynamic_cast<Midia*>(item)){
				Midia* midia = dynamic_cast<Midia*>(item);
				midia->fichacatalografica();
				cont++;
			}
			if((id == item->getId()) && dynamic_cast<Relatorio*>(item)){
				Relatorio* relatorio = dynamic_cast<Relatorio*>(item);
				relatorio->fichacatalografica();
				cont++;
			}
			if((id == item->getId()) && dynamic_cast<TrabalhoConclusao*>(item)){
				TrabalhoConclusao* trabalho = dynamic_cast<TrabalhoConclusao*>(item);
				trabalho->fichacatalografica();
				cont++;
			}
			if((id == item->getId()) && dynamic_cast<Periodico*>(item)){
				Periodico* periodico = dynamic_cast<Periodico*>(item);
				periodico->fichacatalografica();
				cont++;
			}	
		}
		if(cont == 0){
			cout << endl << "Nenhum item com esse id encontrado no acervo!!!";
		}	
	}
	else{
		cout << endl << "Nenhum item no acervo!!!";
	}
}

//Função para ordenar elementos do vetor de items quando ler dados do arquivo binário
void ManterDados::ordenar(vector <ItemAcervo*> &items){
	
		//Algoritmo para ordenar items no acervo após fazer a busca do arquivo
			for (int p = 1; p < items.size(); p++)
		{
				ItemAcervo *tmp = items[p];
				int j;
				for (j = p; j > 0 && tmp->getId() < items[j-1]->getId(); j--)
				items[j] = items[j-1];
				items[j] = tmp;
		} 
		
}
