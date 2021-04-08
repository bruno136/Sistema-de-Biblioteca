#include "Midia.h"

Midia::Midia()
{
}
//Metodo construtor
Midia::Midia(int id,vector<string> autores,string titulo_obra,int num_edicao,string cidade,string editora,int ano,int num_pag,float tam_cm,string assunto,int quant_exemplares,int quant_atual,string tipo,vector<string>palavras_chave,string CDU):ItemAcervo(id,autores,titulo_obra,num_edicao,cidade,editora,ano,num_pag,tam_cm,assunto,quant_exemplares,quant_atual,tipo,palavras_chave,CDU){
	
}
Midia::~Midia()
{
}

//Função para exibir informações
void Midia::exibirInformacoes(){
	cout << endl << endl << "Tipo do item de acervo: " << Midia::getTipo() << endl;
	cout << "Identificador: " << Midia::getId() << endl;
	for(int i=0;i<this->autores.size();i++){
		cout << "Autor" << i+1 << ": " << this->autores[i] << endl;
	}
	cout << "Título: " <<Midia::getTitulo_obra() << endl;
	cout << "Edição: " << Midia::getNum_edicao() << endl;
	cout << "Cidade: " << Midia::getCidade() << endl;
	cout << "Editora: " << Midia::getEditora() << endl;
	cout << "Ano: " << Midia::getAno() << endl;
	cout << "CDU: " << Midia::getCDU() << endl;
	cout << "Assunto: " << Midia::getAssunto() << endl;
	for(int i=0;i < this->palavras_chave.size();i++){
		cout << "Palavra-Chave" << i+1 << ": " << this->palavras_chave[i] << endl;
	}
	cout << "Quantidade Total: " << Midia::getQuant_exemplares() << endl;
	cout << "Quantidade Atual: " << Midia::getQuant_atual() << endl;
}

//Função para exibir ficha catalografica
void Midia::fichacatalografica(){
	 cout << endl << endl << "--------------------------------------------------------------------" << endl << endl;
	 for(int i=0;i<this->autores.size();i++){
		cout << "Autor " << i+1 << ": " << this->autores[i] << ". ";
	 }
	 cout << endl << endl << Midia::getTitulo_obra() << " - ";
	 cout << Midia::getNum_edicao() << "° Edição - ";
	 cout << Midia::getCidade() << " : ";
	 cout << Midia::getEditora() << ", ";
	 cout << Midia::getAno() << ". " << endl;
	 cout << Midia::getNum_pag() << " pág. : " << Midia::getTam_cm() << " cm." << endl << endl;
	 cout << "1. " << Midia::getAssunto() << ". ";
	 for(int i=0;i < this->palavras_chave.size();i++){
	 	for(int j=0;j <= i;j++){
		 	cout << "I";
		}
		cout << ". " << this->palavras_chave[i] << ". ";
	 }
	 cout << Midia::getTitulo_obra() << "." << endl << endl;
	 cout << "\t\t\t\t\t CDU: " << Midia::getCDU();
	 cout << endl << endl << "--------------------------------------------------------------------" << endl << endl;
}
