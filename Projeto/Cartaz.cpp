#include "Cartaz.h"

Cartaz::Cartaz()
{
}
//Metodo construtor
Cartaz::Cartaz(int id,vector<string> autores,string titulo_obra,int num_edicao,string cidade,string editora,int ano,int num_pag,float tam_cm,string assunto,int quant_exemplares,int quant_atual,string tipo,vector<string>palavras_chave,string CDU):ItemAcervo(id,autores,titulo_obra,num_edicao,cidade,editora,ano,num_pag,tam_cm,assunto,quant_exemplares,quant_atual,tipo,palavras_chave,CDU){

}
Cartaz::~Cartaz()
{
}

//Função para exibir informações
void Cartaz::exibirInformacoes(){
	cout << endl << endl << "Tipo do item de acervo: " << Cartaz::getTipo() << endl;
	cout << "Identificador: " << Cartaz::getId() << endl;
	for(int i=0;i<this->autores.size();i++){
		cout << "Autor" << i+1 << ": " << this->autores[i] << endl;
	}
	cout << "Título: " << Cartaz::getTitulo_obra() << endl;
	cout << "Edição: " << Cartaz::getNum_edicao() << endl;
	cout << "Cidade: " << Cartaz::getCidade() << endl;
	cout << "Editora: " << Cartaz::getEditora() << endl;
	cout << "Ano: " << Cartaz::getAno() << endl;
	cout << "CDU: " << Cartaz::getCDU() << endl;
	cout << "Assunto: " << Cartaz::getAssunto() << endl;
	for(int i=0;i < this->palavras_chave.size();i++){
		cout << "Palavra-Chave" << i+1 << ": " << this->palavras_chave[i] << endl;
	}
	cout << "Quantidade Total: " << Cartaz::getQuant_exemplares() << endl;
	cout << "Quantidade Atual: " << Cartaz::getQuant_atual() << endl;
}

//Função para exibir ficha catalografica
void Cartaz::fichacatalografica(){
	 cout << endl << endl << "--------------------------------------------------------------------" << endl << endl;
	 for(int i=0;i<this->autores.size();i++){
		cout << "Autor " << i+1 << ": " << this->autores[i] << ". ";
	 }
	 cout << endl << endl << Cartaz::getTitulo_obra() << " - ";
	 cout << Cartaz::getNum_edicao() << "° Edição - ";
	 cout << Cartaz::getCidade() << " : ";
	 cout << Cartaz::getEditora() << ", ";
	 cout << Cartaz::getAno() << ". " << endl;
	 cout << Cartaz::getNum_pag() << " pág. : " << Cartaz::getTam_cm() << " cm." << endl << endl;
	 cout << "1. " << Cartaz::getAssunto() << ". ";
	 for(int i=0;i < this->palavras_chave.size();i++){
	 	for(int j=0;j <= i;j++){
		 	cout << "I";
		}
		cout << ". " << this->palavras_chave[i] << ". ";
	 }
	 cout << Cartaz::getTitulo_obra() << "." << endl << endl;
	 cout << "\t\t\t\t\t CDU: " << Cartaz::getCDU();
	 cout << endl << endl << "--------------------------------------------------------------------" << endl << endl;
}
