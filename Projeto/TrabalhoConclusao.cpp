#include "TrabalhoConclusao.h"

TrabalhoConclusao::TrabalhoConclusao()
{
}
//Metodo construtor
TrabalhoConclusao::TrabalhoConclusao(int id,vector<string> autores,string titulo_obra,int num_edicao,string cidade,string editora,int ano,int num_pag,float tam_cm,string assunto,int quant_exemplares,int quant_atual,string tipo,vector<string>palavras_chave,string CDU,string ISBN):ItemAcervo(id,autores,titulo_obra,num_edicao,cidade,editora,ano,num_pag,tam_cm,assunto,quant_exemplares,quant_atual,tipo,palavras_chave,CDU){
	setISBN(ISBN);
}
TrabalhoConclusao::~TrabalhoConclusao()
{
}

string TrabalhoConclusao::getISBN(){
	return this->ISBN;
}

void TrabalhoConclusao::setISBN(string ISBN){
	this->ISBN = ISBN;
}

//Função para exibir informações
void TrabalhoConclusao::exibirInformacoes(){
	cout << endl << endl << "Tipo do item de acervo: " << TrabalhoConclusao::getTipo() << endl;
	cout << "Identificador: " << TrabalhoConclusao::getId() << endl;
	for(int i=0;i<this->autores.size();i++){
		cout << "Autor" << i+1 << ": " << this->autores[i] << endl;
	}
	cout << "Título: " << TrabalhoConclusao::getTitulo_obra() << endl;
	cout << "Edição: " << TrabalhoConclusao::getNum_edicao() << endl;
	cout << "Cidade: " << TrabalhoConclusao::getCidade() << endl;
	cout << "Editora: " << TrabalhoConclusao::getEditora() << endl;
	cout << "Ano: " << TrabalhoConclusao::getAno() << endl;
	cout << "CDU: " << TrabalhoConclusao::getCDU() << endl;
	cout << "Assunto: " << TrabalhoConclusao::getAssunto() << endl;
	for(int i=0;i < this->palavras_chave.size();i++){
		cout << "Palavra-Chave" << i+1 << ": " << this->palavras_chave[i] << endl;
	}
	cout << "Quantidade Total: " << TrabalhoConclusao::getQuant_exemplares() << endl;
	cout << "Quantidade Atual: " << TrabalhoConclusao::getQuant_atual() << endl;
	cout << "ISBN: " << TrabalhoConclusao::getISBN() << endl << endl;
}

//Função para exibir ficha catalografica
void TrabalhoConclusao::fichacatalografica(){
	 cout << endl << endl << "--------------------------------------------------------------------" << endl << endl;
	 for(int i=0;i<this->autores.size();i++){
		cout << "Autor " << i+1 << ": " << this->autores[i] << ". ";
	 }
	 cout << endl << endl << TrabalhoConclusao::getTitulo_obra() << " - ";
	 cout << TrabalhoConclusao::getNum_edicao() << "° Edição - ";
	 cout << TrabalhoConclusao::getCidade() << " : ";
	 cout << TrabalhoConclusao::getEditora() << ", ";
	 cout << TrabalhoConclusao::getAno() << ". " << endl;
	 cout << TrabalhoConclusao::getNum_pag() << " pág. : " << TrabalhoConclusao::getTam_cm() << " cm." << endl << endl;
	 cout << "ISBN: " << TrabalhoConclusao::getISBN() << endl << endl;
	 cout << "1. " << TrabalhoConclusao::getAssunto() << ". ";
	 for(int i=0;i < this->palavras_chave.size();i++){
	 	for(int j=0;j <= i;j++){
		 	cout << "I";
		}
		cout << ". " << this->palavras_chave[i] << ". ";
	 }
	 cout << TrabalhoConclusao::getTitulo_obra() << "." << endl << endl;
	 cout << "\t\t\t\t\t CDU: " << TrabalhoConclusao::getCDU();
	 cout << endl << endl << "--------------------------------------------------------------------" << endl << endl;
}

//Função para tratamento de cópia de struct para salvar em arquivo
StructItemAcervoISBN TrabalhoConclusao::copyStructISBN(){
	

	StructItemAcervoISBN sp;
	
	string autores_aux;
	char autores[1000];
	
	string palavras_aux;
	char palavraschaves[1000];
	
	sp.id = getId();
	strcpy(sp.titulo_obra, getTitulo_obra().c_str());
	sp.num_edicao = getNum_edicao();
	strcpy(sp.cidade, getCidade().c_str());
	strcpy(sp.editora, getEditora().c_str());
	sp.ano = getAno();
	sp.num_pag = getNum_pag();
	sp.tam_cm = getTam_cm();
	strcpy(sp.assunto,getAssunto().c_str());
	sp.quant_exemplares = getQuant_exemplares();
	sp.quant_atual = getQuant_atual();
	strcpy(sp.tipo,getTipo().c_str());
	strcpy(sp.CDU,getCDU().c_str());
	strcpy(sp.ISBN,getISBN().c_str());
	
	//Trabalhando o armazenamento de um vetor de string em char
	
	///Trecho para autores
	for(int i=0;i<this->autores.size();i++){
		autores_aux += this->autores[i] + ";";
	}
	strcpy(autores,autores_aux.c_str());
	
	///Trecho para palavras chaves
	for(int i=0;i<this->palavras_chave.size();i++){
		palavras_aux += this->palavras_chave[i] + ";";
	}
	strcpy(palavraschaves,palavras_aux.c_str());
	
	strcpy(sp.autores, autores);
	strcpy(sp.palavraschaves, palavraschaves);
	
	return sp;

}
