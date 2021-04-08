#include "Periodico.h"

Periodico::Periodico()
{
}
//Metodo construtor
Periodico::Periodico(int id,vector<string> autores,string titulo_obra,int num_edicao,string cidade,string editora,int ano,int num_pag,float tam_cm,string assunto,int quant_exemplares,int quant_atual,string tipo,vector<string>palavras_chave,string CDU,string ISSN):ItemAcervo(id,autores,titulo_obra,num_edicao,cidade,editora,ano,num_pag,tam_cm,assunto,quant_exemplares,quant_atual,tipo,palavras_chave,CDU){
	setISSN(ISSN);
}

Periodico::~Periodico()
{
}

string Periodico::getISSN(){
	return this->ISSN;
}
void Periodico::setISSN(string ISSN){
	this->ISSN = ISSN;
}

//Função para exibir informações
void Periodico::exibirInformacoes(){
	cout << endl << endl << "Tipo do item de acervo: " << Periodico::getTipo() << endl;
	cout << "Identificador: " << Periodico::getId() << endl;
	for(int i=0;i<this->autores.size();i++){
		cout << "Autor" << i+1 << ": " << this->autores[i] << endl;
	}
	cout << "Título: " << Periodico::getTitulo_obra() << endl;
	cout << "Edição: " << Periodico::getNum_edicao() << endl;
	cout << "Cidade: " << Periodico::getCidade() << endl;
	cout << "Editora: " << Periodico::getEditora() << endl;
	cout << "Ano: " << Periodico::getAno() << endl;
	cout << "CDU: " << Periodico::getCDU() << endl;
	cout << "Assunto: " << Periodico::getAssunto() << endl;
	for(int i=0;i < this->palavras_chave.size();i++){
		cout << "Palavra-Chave" << i+1 << ": " << this->palavras_chave[i] << endl;
	}
	cout << "Quantidade Total: " << Periodico::getQuant_exemplares() << endl;
	cout << "Quantidade Atual: " << Periodico::getQuant_atual() << endl;
	cout << "ISSN: " << Periodico::getISSN() << endl << endl;
}

//Função para exibir ficha catalografica
void Periodico::fichacatalografica(){
	 cout << endl << endl << "--------------------------------------------------------------------" << endl << endl;
	 for(int i=0;i<this->autores.size();i++){
		cout << "Autor " << i+1 << ": " << this->autores[i] << ". ";
	 }
	 cout << endl << endl << Periodico::getTitulo_obra() << " - ";
	 cout << Periodico::getNum_edicao() << "° Edição - ";
	 cout << Periodico::getCidade() << " : ";
	 cout << Periodico::getEditora() << ", ";
	 cout << Periodico::getAno() << ". " << endl;
	 cout << Periodico::getNum_pag() << " pág. : " << Periodico::getTam_cm() << " cm." << endl << endl;
	 cout << "ISSN: " << Periodico::getISSN() << endl << endl;
	 cout << "1. " << Periodico::getAssunto() << ". ";
	 for(int i=0;i < this->palavras_chave.size();i++){
	 	for(int j=0;j <= i;j++){
		 	cout << "I";
		}
		cout << ". " << this->palavras_chave[i] << ". ";
	 }
	 cout <<  Periodico::getTitulo_obra() << "." << endl << endl;
	 cout << "\\t\t\t\t\t CDU: " << Periodico::getCDU();
	 cout << endl << endl << "--------------------------------------------------------------------" << endl << endl;
}

//Função para tratamento de cópia de struct para salvar em arquivo
StructItemAcervoISSN Periodico::copyStructISSN(){
	

	StructItemAcervoISSN sp;
	
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
	strcpy(sp.ISSN,getISSN().c_str());
	
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
