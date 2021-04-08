#include "ItemAcervo.h"
#include <string.h>

ItemAcervo::ItemAcervo()
{
}
ItemAcervo::ItemAcervo(int id,vector<string> autores,string titulo_obra,int num_edicao,string cidade,string editora,int ano,int num_pag,float tam_cm,string assunto,int quant_exemplares,int quant_atual,string tipo,vector<string>palavras_chave,string CDU){
	setId(id);
	setAutores(autores);
	setTitulo_obra(titulo_obra);
	setNum_edicao(num_edicao);
	setCidade(cidade);
	setEditora(editora);
	setAno(ano);
	setNum_pag(num_pag);
	setTam_cm(tam_cm);
	setAssunto(assunto);
	setQuantExemplares(quant_exemplares);
	setQuantAtual(quant_atual);
	setTipo(tipo);
	setPalavras_chave(palavras_chave);
	setCDU(CDU);
}
ItemAcervo::~ItemAcervo()
{
}

int ItemAcervo::getId(){
	return this->id;
}
void ItemAcervo::getAutores(vector<string> autores){
	if(!this->autores.empty()){
		for(int i=0;i<(this->autores.size());i++){
			autores.push_back(this->autores[i]);
		}
	}
}
string ItemAcervo::getTitulo_obra(){
	return this->titulo_obra;
}
int ItemAcervo::getNum_edicao(){
	return this->num_edicao;
}
string ItemAcervo::getCidade(){
	return this->cidade;
}
string ItemAcervo::getEditora(){
	return this->editora;
}
int ItemAcervo::getAno(){
	return this->ano;
}
int ItemAcervo::getNum_pag(){
	return this->num_pag;
}
float ItemAcervo::getTam_cm(){
	return this->tam_cm;
}
string ItemAcervo::getAssunto(){
	return this->assunto;
}
int ItemAcervo::getQuant_exemplares(){
	return this->quant_exemplares;
}
int ItemAcervo::getQuant_atual(){
	return this->quant_atual;
}
string ItemAcervo::getTipo(){
	return this->tipo;
}
void ItemAcervo::getPalavras_chave(vector<string>palavras_chave){
	if(!this->palavras_chave.empty()){
		for(int i=0;i<(this->palavras_chave.size());i++){
			palavras_chave.push_back(this->palavras_chave[i]);
		}
	}
}
string ItemAcervo::getCDU(){
	return this->CDU;
}


		
void ItemAcervo::setId(int id){
	this->id = id;
}
void ItemAcervo::setAutores(vector<string> autores){
	if(!autores.empty()){
		for(int i=0;i<(autores.size());i++){
			this->autores.push_back(autores[i]);
		}
	}
}
void ItemAcervo::setTitulo_obra(string titulo_obra){
	this->titulo_obra = titulo_obra;
}
void ItemAcervo::setNum_edicao(int num_edicao){
	this->num_edicao = num_edicao;
}
void ItemAcervo::setCidade(string cidade){
	this->cidade = cidade;
}
void ItemAcervo::setEditora(string editora){
	this->editora = editora;
}
void ItemAcervo::setAno(int ano){
	this->ano = ano;
}
void ItemAcervo::setNum_pag(int num_pag){
	this->num_pag = num_pag;
}
void ItemAcervo::setTam_cm(float tam_cm){
	this->tam_cm = tam_cm;
}
void ItemAcervo::setAssunto(string assunto){
	this->assunto = assunto;
}
void ItemAcervo::setQuantExemplares(int quant_exemplares){
	this->quant_exemplares = quant_exemplares;
}
void ItemAcervo::setQuantAtual(int quant_atual){
	this->quant_atual = quant_atual;
}
void ItemAcervo::setTipo(string tipo){
	this->tipo = tipo;
}
void ItemAcervo::setPalavras_chave(vector<string>palavras_chave){
	if(!palavras_chave.empty()){
		for(int i=0;i<(palavras_chave.size());i++){
			this->palavras_chave.push_back(palavras_chave[i]);
		}
	}
}
void ItemAcervo::setCDU(string CDU){
	this->CDU = CDU;
}

//Função para limpar vetor de palavras chaves
void ItemAcervo::limpar_autores_palavraschave(){
	for(int i=0; i < this->autores.size() ;i++){
		this->autores.erase(autores.begin() + i);
	}
	for(int i=0; i < this->palavras_chave.size() ;i++){
		this->palavras_chave.erase(palavras_chave.begin() + i);
	}
	this->autores.clear();
	this->palavras_chave.clear();
}

//Função para informações
void ItemAcervo::exibirInformacoes(){
	cout << endl << "Id: " << this->id << " Título: " << this->titulo_obra;
}

//Função de struct para salvar em arquivo binário
StructItemAcervo ItemAcervo::copyStruct(){
	

	StructItemAcervo sp;
	
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
