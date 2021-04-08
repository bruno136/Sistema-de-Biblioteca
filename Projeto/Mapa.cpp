#include "Mapa.h"

Mapa::Mapa()
{
}
//Metodo construtor
Mapa::Mapa(int id,vector<string> autores,string titulo_obra,int num_edicao,string cidade,string editora,int ano,int num_pag,float tam_cm,string assunto,int quant_exemplares,int quant_atual,string tipo,vector<string>palavras_chave,string CDU):ItemAcervo(id,autores,titulo_obra,num_edicao,cidade,editora,ano,num_pag,tam_cm,assunto,quant_exemplares,quant_atual,tipo,palavras_chave,CDU){
	
}
Mapa::~Mapa()
{
}

//Função para exibir informações
void Mapa::exibirInformacoes(){
	cout << endl << endl << "Tipo do item de acervo: " << Mapa::getTipo() << endl;
	cout << "Identificador: " << Mapa::getId() << endl;
	for(int i=0;i<this->autores.size();i++){
		cout << "Autor" << i+1 << ": " << this->autores[i] << endl;
	}
	cout << "Título: " << Mapa::getTitulo_obra() << endl;
	cout << "Edição: " << Mapa::getNum_edicao() << endl;
	cout << "Cidade: " << Mapa::getCidade() << endl;
	cout << "Editora: " << Mapa::getEditora() << endl;
	cout << "Ano: " << Mapa::getAno() << endl;
	cout << "CDU: " << Mapa::getCDU() << endl;
	cout << "Assunto: " << Mapa::getAssunto() << endl;
	for(int i=0;i < this->palavras_chave.size();i++){
		cout << "Palavra-Chave" << i+1 << ": " << this->palavras_chave[i] << endl;
	}
	cout << "Quantidade Total: " << Mapa::getQuant_exemplares() << endl;
	cout << "Quantidade Atual: " << Mapa::getQuant_atual() << endl;
}

//Função para exibir ficha catlografica
void Mapa::fichacatalografica(){
	 cout << endl << endl << "--------------------------------------------------------------------" << endl << endl;
	 for(int i=0;i<this->autores.size();i++){
		cout << "Autor " << i+1 << ": " << this->autores[i] << ". ";
	 }
	 cout << endl << endl << Mapa::getTitulo_obra() << " - ";
	 cout << Mapa::getNum_edicao() << "° Edição - ";
	 cout << Mapa::getCidade() << " : ";
	 cout << Mapa::getEditora() << ", ";
	 cout << Mapa::getAno() << ". " << endl;
	 cout << Mapa::getNum_pag() << " pág. : " << Mapa::getTam_cm() << " cm." << endl << endl;
	 cout << "1. " << Mapa::getAssunto() << ". ";
	 for(int i=0;i < this->palavras_chave.size();i++){
	 	for(int j=0;j <= i;j++){
		 	cout << "I";
		}
		cout << ". " << this->palavras_chave[i] << ". ";
	 }
	 cout << Mapa::getTitulo_obra() << "." << endl << endl;
	 cout << "\t\t\t\t\t CDU: " << Mapa::getCDU();
	 cout << endl << endl << "--------------------------------------------------------------------" << endl << endl;
}
