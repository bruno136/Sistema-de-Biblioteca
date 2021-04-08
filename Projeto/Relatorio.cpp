#include "Relatorio.h"

Relatorio::Relatorio()
{
}
//Metodo construtor
Relatorio::Relatorio(int id,vector<string> autores,string titulo_obra,int num_edicao,string cidade,string editora,int ano,int num_pag,float tam_cm,string assunto,int quant_exemplares,int quant_atual,string tipo,vector<string>palavras_chave,string CDU):ItemAcervo(id,autores,titulo_obra,num_edicao,cidade,editora,ano,num_pag,tam_cm,assunto,quant_exemplares,quant_atual,tipo,palavras_chave,CDU){
	
}
Relatorio::~Relatorio()
{
}

//Função para exibir informações
void Relatorio::exibirInformacoes(){
	cout << endl << endl << "Tipo do item de acervo: " << Relatorio::getTipo() << endl;
	cout << "Identificador: " << Relatorio::getId() << endl;
	for(int i=0;i<this->autores.size();i++){
		cout << "Autor" << i+1 << ": " << this->autores[i] << endl;
	}
	cout << "Título: " << Relatorio::getTitulo_obra() << endl;
	cout << "Edição: " << Relatorio::getNum_edicao() << endl;
	cout << "Cidade: " << Relatorio::getCidade() << endl;
	cout << "Editora: " << Relatorio::getEditora() << endl;
	cout << "Ano: " << Relatorio::getAno() << endl;
	cout << "CDU: " << Relatorio::getCDU() << endl;
	cout << "Assunto: " << Relatorio::getAssunto() << endl;
	for(int i=0;i < this->palavras_chave.size();i++){
		cout << "Palavra-Chave" << i+1 << ": " << this->palavras_chave[i] << endl;
	}
	cout << "Quantidade Total: " << Relatorio::getQuant_exemplares() << endl;
	cout << "Quantidade Atual: " << Relatorio::getQuant_atual() << endl;
}

//Função para exibir ficha catalografica
void Relatorio::fichacatalografica(){
	 cout << endl << endl << "--------------------------------------------------------------------" << endl << endl;
	 for(int i=0;i<this->autores.size();i++){
		cout << "Autor " << i+1 << ": " << this->autores[i] << ". ";
	 }
	 cout << endl << endl << Relatorio::getTitulo_obra() << " - ";
	 cout << Relatorio::getNum_edicao() << "° Edição - ";
	 cout << Relatorio::getCidade() << " : ";
	 cout << Relatorio::getEditora() << ", ";
	 cout << Relatorio::getAno() << ". " << endl;
	 cout << Relatorio::getNum_pag() << " pág. : " << Relatorio::getTam_cm() << " cm." << endl << endl;
	 cout << "1. " << Relatorio::getAssunto() << ". ";
	 for(int i=0;i < this->palavras_chave.size();i++){
	 	for(int j=0;j <= i;j++){
		 	cout << "I";
		}
		cout << ". " << this->palavras_chave[i] << ". ";
	 }
	 cout << Relatorio::getTitulo_obra() << "." << endl << endl;
	 cout << "\t\t\t\t\t CDU: " << Relatorio::getCDU();
	 cout << endl << endl << "--------------------------------------------------------------------" << endl << endl;
}
