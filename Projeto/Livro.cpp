#include "Livro.h"

Livro::Livro()
{
}
//Metodo construtor
Livro::Livro(int id,vector<string> autores,string titulo_obra,int num_edicao,string cidade,string editora,int ano,int num_pag,float tam_cm,string assunto,int quant_exemplares,int quant_atual,string tipo,vector<string>palavras_chave,string CDU,string ISBN):ItemAcervo(id,autores,titulo_obra,num_edicao,cidade,editora,ano,num_pag,tam_cm,assunto,quant_exemplares,quant_atual,tipo,palavras_chave,CDU){
	setISBN(ISBN);
}
Livro::~Livro()
{
}

string Livro::getISBN(){
	return this->ISBN;
}

void Livro::setISBN(string ISBN){
	this->ISBN = ISBN;
}

//Função para exibir informações
void Livro::exibirInformacoes(){
	cout << endl << endl << "Tipo do item de acervo: " << Livro::getTipo() << endl;
	cout << "Identificador: " << Livro::getId() << endl;
	for(int i=0;i<this->autores.size();i++){
		cout << "Autor" << i+1 << ": " << this->autores[i] << endl;
	}
	cout << "Título: " << Livro::getTitulo_obra() << endl;
	cout << "Edição: " << Livro::getNum_edicao() << endl;
	cout << "Cidade: " << Livro::getCidade() << endl;
	cout << "Editora: " << Livro::getEditora() << endl;
	cout << "Ano: " << Livro::getAno() << endl;
	cout << "CDU: " << Livro::getCDU() << endl;
	cout << "Assunto: " << Livro::getAssunto() << endl;
	for(int i=0;i < this->palavras_chave.size();i++){
		cout << "Palavra-Chave" << i+1 << ": " << this->palavras_chave[i] << endl;
	}
	cout << "Quantidade Total: " << Livro::getQuant_exemplares() << endl;
	cout << "Quantidade Atual: " << Livro::getQuant_atual() << endl;
	cout << "ISBN: " << Livro::getISBN() << endl << endl;
}

//Função para exibir ficha catalografica
void Livro::fichacatalografica(){
	 cout << endl << endl << "--------------------------------------------------------------------" << endl << endl;
	 for(int i=0;i<this->autores.size();i++){
		cout << "Autor " << i+1 << ": " << this->autores[i] << ". ";
	 }
	 cout << endl << endl << Livro::getTitulo_obra() << " - ";
	 cout << Livro::getNum_edicao() << "° Edição - ";
	 cout << Livro::getCidade() << " : ";
	 cout << Livro::getEditora() << ", ";
	 cout << Livro::getAno() << ". " << endl;
	 cout << Livro::getNum_pag() << " pág. : " << Livro::getTam_cm() << " cm." << endl << endl;
	 cout << "ISBN: " << Livro::getISBN() << endl << endl;
	 cout << "1. " << Livro::getAssunto() << ". ";
	 for(int i=0;i < this->palavras_chave.size();i++){
	 	for(int j=0;j <= i;j++){
		 	cout << "I";
		}
		cout << ". " << this->palavras_chave[i] << ". ";
	 }
	 cout <<  Livro::getTitulo_obra() << "." << endl << endl;
	 cout << "\t\t\t\t\t CDU: " << Livro::getCDU();
	 cout << endl << endl << "--------------------------------------------------------------------" << endl << endl;
}

//Função para tratamento de cópia de struct para salvar em arquivo
StructItemAcervoISBN Livro::copyStructISBN(){
	

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
