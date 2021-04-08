#include "SalvarDados.h"
#include <string.h>
#include <string>

SalvarDados::SalvarDados()
{
}

SalvarDados::~SalvarDados()
{
}

//Função para limpar string de vector de string
void SalvarDados::clean(char *var){
	int i=0;
	while(var[i] != '\0'){
		var[i] = '\0';
		i++;
	}
}

//Função para adicionar Item no vetor
void SalvarDados::addVetorItem(vector <ItemAcervo*> &items,ItemAcervo *p){
	
	items.push_back(p);
	
}

//Função para salvar dados lidos no arquivo binario
void SalvarDados::SalvarDadosItemBinario(vector <ItemAcervo*> &items){
	
	
	ofstream livro; //arquivo para livro
	ofstream periodico; //arquivo para periodico
	ofstream trabalho; //arquivo para trabalho
	ofstream relatorio; //arquivo para relatorio
	ofstream midia; //arquivo para midia
	ofstream cartaz; //arquivo para cartaz
	ofstream mapa; //arquivo para mapa
	
	//Arquivo para mapa
	mapa.open("mapa.dat", ios::binary | ios::trunc);
	
	if(mapa.is_open()){
		for(vector<ItemAcervo *>::iterator it = items.begin(); it != items.end(); it ++){
			ItemAcervo *p = *it;
			if(dynamic_cast<Mapa*>(p)){
				Mapa* mapas = dynamic_cast<Mapa*>(p);
				StructItemAcervo ps = mapas->copyStruct();
				mapa.write((char*) &ps, sizeof(StructItemAcervo));
			}
		}	
		mapa.close();	
	}
	
	//Arquivo para relatorio
	relatorio.open("relatorio.dat", ios::binary | ios::trunc);
	
	if(relatorio.is_open()){
		for(vector<ItemAcervo *>::iterator it = items.begin(); it != items.end(); it ++){
			ItemAcervo *p = *it;
			if(dynamic_cast<Relatorio*>(p)){
				Relatorio* relatorios = dynamic_cast<Relatorio*>(p);
				StructItemAcervo ps = relatorios->copyStruct();
				relatorio.write((char*) &ps, sizeof(StructItemAcervo));
			}
		}	
		relatorio.close();	
	}
	
	//Arquivo para Cartaz
	cartaz.open("cartaz.dat", ios::binary | ios::trunc);
	
	if(cartaz.is_open()){
		for(vector<ItemAcervo *>::iterator it = items.begin(); it != items.end(); it ++){
			ItemAcervo *p = *it;
			if(dynamic_cast<Cartaz*>(p)){
				Cartaz* cartazes = dynamic_cast<Cartaz*>(p);
				StructItemAcervo ps = cartazes->copyStruct();
				cartaz.write((char*) &ps, sizeof(StructItemAcervo));
			}
		}	
		cartaz.close();	
	}
	
	//Arquivo para Midia
	midia.open("midia.dat", ios::binary | ios::trunc);
	
	if(midia.is_open()){
		for(vector<ItemAcervo *>::iterator it = items.begin(); it != items.end(); it ++){
			ItemAcervo *p = *it;
			if(dynamic_cast<Midia*>(p)){
				Midia* midias = dynamic_cast<Midia*>(p);
				StructItemAcervo ps = midias->copyStruct();
				midia.write((char*) &ps, sizeof(StructItemAcervo));
			}
		}	
		midia.close();	
	}
	
	//Arquivo para Livro
	livro.open("livro.dat", ios::binary | ios::trunc);
	
	if(livro.is_open()){
		for(vector<ItemAcervo *>::iterator it = items.begin(); it != items.end(); it ++){
			ItemAcervo *p = *it;
			if(dynamic_cast<Livro*>(p)){
				Livro* livros = dynamic_cast<Livro*>(p);
				StructItemAcervoISBN ps = livros->copyStructISBN();
				livro.write((char*) &ps, sizeof(StructItemAcervoISBN));
			}
		}	
		livro.close();	
	}
	
	//Arquivo para Trabalho de Conclusão
	trabalho.open("TrabalhoConclusao.dat", ios::binary | ios::trunc);
	
	if(trabalho.is_open()){
		for(vector<ItemAcervo *>::iterator it = items.begin(); it != items.end(); it ++){
			ItemAcervo *p = *it;
			if(dynamic_cast<TrabalhoConclusao*>(p)){
				TrabalhoConclusao* trabalhos = dynamic_cast<TrabalhoConclusao*>(p);
				StructItemAcervoISBN ps = trabalhos->copyStructISBN();
				trabalho.write((char*) &ps, sizeof(StructItemAcervoISBN));
			}
		}	
		trabalho.close();	
	}
	
	//Arquivo para Periodico
	periodico.open("periodico.dat", ios::binary | ios::trunc);
	
	if(periodico.is_open()){
		for(vector<ItemAcervo *>::iterator it = items.begin(); it != items.end(); it ++){
			ItemAcervo *p = *it;
			if(dynamic_cast<Periodico*>(p)){
				Periodico* periodicos = dynamic_cast<Periodico*>(p);
				StructItemAcervoISSN ps = periodicos->copyStructISSN();
				periodico.write((char*) &ps, sizeof(StructItemAcervoISSN));
			}
		}	
		periodico.close();	
	}
}

//Função para ler dados do arquvo binario e salvar em um vector
void SalvarDados::lerDadosItemBinario(vector <ItemAcervo *> &items){
	
	//Variaveis dos arquivos binarios
	ifstream arquivo;
	ifstream relatorio;
	ifstream cartaz;
	ifstream midia;
	ifstream livro;
	ifstream periodico;
	ifstream trabalho;
	
	//abrindo arquivos binarios
	arquivo.open("mapa.dat", ios::binary);
	relatorio.open("relatorio.dat", ios::binary);
	cartaz.open("cartaz.dat", ios::binary);
	midia.open("midia.dat", ios::binary);
	livro.open("livro.dat", ios::binary);
	periodico.open("periodico.dat", ios::binary);
	trabalho.open("TrabalhoConclusao.dat", ios::binary);
	
	///Abrindo arquivo Mapa
	if(arquivo.is_open()){
		
		StructItemAcervo ps;
	
		
		while(arquivo.read((char*) &ps, sizeof(StructItemAcervo))){
			
			char nomes[1000],nome_aux[1000];
			int aux = 0,aux1 = 0;
			vector<string> autores_aux;
			
			char palavras[1000],palavra_aux[1000];
			int aux2 = 0,aux3 = 0;
			vector<string> palavras_aux;
			
			Mapa *p = new Mapa();
			p->setId(ps.id),p->setTitulo_obra(ps.titulo_obra),p->setNum_edicao(ps.num_edicao);
			p->setCidade(ps.cidade),p->setEditora(ps.editora),p->setAno(ps.ano);
			p->setNum_pag(ps.num_pag),p->setTam_cm(ps.tam_cm),p->setAssunto(ps.assunto);
			p->setQuantExemplares(ps.quant_exemplares),p->setQuantAtual(ps.quant_atual);
			p->setTipo(ps.tipo),p->setCDU(ps.CDU);
			strcpy(nomes,ps.autores);
			strcpy(palavras,ps.palavraschaves);
			
			//Recuperar nome dos autores
			for(int i=0;i<strlen(nomes);i++){
				if(nomes[i] != ';'){
					nome_aux[aux1] = nomes[i];
					aux1++;
				}
				if(nomes[i] == ';'){
					autores_aux.push_back(nome_aux);
					clean(nome_aux);
					aux1 = 0;
				}
			}
			
			//Recuperar nome das palvras chaves
			for(int i=0;i<strlen(palavras);i++){
				if(palavras[i] != ';'){
					palavra_aux[aux3] = palavras[i];
					aux3++;
				}
				if(palavras[i] == ';'){
					palavras_aux.push_back(palavra_aux);
					clean(palavra_aux);
					aux3 = 0;
				}
			}
			p->setAutores(autores_aux);
			p->setPalavras_chave(palavras_aux);
			addVetorItem(items,p);
		}
		
		//Fechando arquivo
		arquivo.close();
		
	}
	
	
	///Abrindo arquivo Relatorio
	if(relatorio.is_open()){
		
		StructItemAcervo ps;
	
		
		while(relatorio.read((char*) &ps, sizeof(StructItemAcervo))){
			
			char nomes[1000],nome_aux[1000];
			int aux = 0,aux1 = 0;
			vector<string> autores_aux;
			
			char palavras[1000],palavra_aux[1000];
			int aux2 = 0,aux3 = 0;
			vector<string> palavras_aux;
			
			Relatorio *p = new Relatorio();
			p->setId(ps.id),p->setTitulo_obra(ps.titulo_obra),p->setNum_edicao(ps.num_edicao);
			p->setCidade(ps.cidade),p->setEditora(ps.editora),p->setAno(ps.ano);
			p->setNum_pag(ps.num_pag),p->setTam_cm(ps.tam_cm),p->setAssunto(ps.assunto);
			p->setQuantExemplares(ps.quant_exemplares),p->setQuantAtual(ps.quant_atual);
			p->setTipo(ps.tipo),p->setCDU(ps.CDU);
			strcpy(nomes,ps.autores);
			strcpy(palavras,ps.palavraschaves);
			
			//Recuperar nome dos autores
			for(int i=0;i<strlen(nomes);i++){
				if(nomes[i] != ';'){
					nome_aux[aux1] = nomes[i];
					aux1++;
				}
				if(nomes[i] == ';'){
					autores_aux.push_back(nome_aux);
					clean(nome_aux);
					aux1 = 0;
				}
			}
			
			//Recuperar nome das palvras chaves
			for(int i=0;i<strlen(palavras);i++){
				if(palavras[i] != ';'){
					palavra_aux[aux3] = palavras[i];
					aux3++;
				}
				if(palavras[i] == ';'){
					palavras_aux.push_back(palavra_aux);
					clean(palavra_aux);
					aux3 = 0;
				}
			}
			p->setAutores(autores_aux);
			p->setPalavras_chave(palavras_aux);
			addVetorItem(items,p);
		}
		
		//Fechando arquivo
		relatorio.close();
		
	}
	
	///Abrindo arquivo Cartaz
	if(cartaz.is_open()){
		
		StructItemAcervo ps;
	
		
		while(cartaz.read((char*) &ps, sizeof(StructItemAcervo))){
			
			char nomes[1000],nome_aux[1000];
			int aux = 0,aux1 = 0;
			vector<string> autores_aux;
			
			char palavras[1000],palavra_aux[1000];
			int aux2 = 0,aux3 = 0;
			vector<string> palavras_aux;
			
			Cartaz *p = new Cartaz();
			p->setId(ps.id),p->setTitulo_obra(ps.titulo_obra),p->setNum_edicao(ps.num_edicao);
			p->setCidade(ps.cidade),p->setEditora(ps.editora),p->setAno(ps.ano);
			p->setNum_pag(ps.num_pag),p->setTam_cm(ps.tam_cm),p->setAssunto(ps.assunto);
			p->setQuantExemplares(ps.quant_exemplares),p->setQuantAtual(ps.quant_atual);
			p->setTipo(ps.tipo),p->setCDU(ps.CDU);
			strcpy(nomes,ps.autores);
			strcpy(palavras,ps.palavraschaves);
			
			//Recuperar nome dos autores
			for(int i=0;i<strlen(nomes);i++){
				if(nomes[i] != ';'){
					nome_aux[aux1] = nomes[i];
					aux1++;
				}
				if(nomes[i] == ';'){
					autores_aux.push_back(nome_aux);
					clean(nome_aux);
					aux1 = 0;
				}
			}
			
			//Recuperar nome das palvras chaves
			for(int i=0;i<strlen(palavras);i++){
				if(palavras[i] != ';'){
					palavra_aux[aux3] = palavras[i];
					aux3++;
				}
				if(palavras[i] == ';'){
					palavras_aux.push_back(palavra_aux);
					clean(palavra_aux);
					aux3 = 0;
				}
			}
			p->setAutores(autores_aux);
			p->setPalavras_chave(palavras_aux);
			addVetorItem(items,p);
		}
		
		//Fechando arquivo
		cartaz.close();
		
	}
	
	///Abrindo arquivo Midia
	if(midia.is_open()){
		
		StructItemAcervo ps;
	
		
		while(midia.read((char*) &ps, sizeof(StructItemAcervo))){
			
			char nomes[1000],nome_aux[1000];
			int aux = 0,aux1 = 0;
			vector<string> autores_aux;
			
			char palavras[1000],palavra_aux[1000];
			int aux2 = 0,aux3 = 0;
			vector<string> palavras_aux;
			
			Midia *p = new Midia();
			p->setId(ps.id),p->setTitulo_obra(ps.titulo_obra),p->setNum_edicao(ps.num_edicao);
			p->setCidade(ps.cidade),p->setEditora(ps.editora),p->setAno(ps.ano);
			p->setNum_pag(ps.num_pag),p->setTam_cm(ps.tam_cm),p->setAssunto(ps.assunto);
			p->setQuantExemplares(ps.quant_exemplares),p->setQuantAtual(ps.quant_atual);
			p->setTipo(ps.tipo),p->setCDU(ps.CDU);
			strcpy(nomes,ps.autores);
			strcpy(palavras,ps.palavraschaves);
			
			//Recuperar nome dos autores
			for(int i=0;i<strlen(nomes);i++){
				if(nomes[i] != ';'){
					nome_aux[aux1] = nomes[i];
					aux1++;
				}
				if(nomes[i] == ';'){
					autores_aux.push_back(nome_aux);
					clean(nome_aux);
					aux1 = 0;
				}
			}
			
			//Recuperar nome das palvras chaves
			for(int i=0;i<strlen(palavras);i++){
				if(palavras[i] != ';'){
					palavra_aux[aux3] = palavras[i];
					aux3++;
				}
				if(palavras[i] == ';'){
					palavras_aux.push_back(palavra_aux);
					clean(palavra_aux);
					aux3 = 0;
				}
			}
			p->setAutores(autores_aux);
			p->setPalavras_chave(palavras_aux);
			addVetorItem(items,p);
		}
		
		//Fechando arquivo
		midia.close();
		
	}
	
	///Abrindo arquivo Livro
	if(livro.is_open()){
		
		StructItemAcervoISBN ps;
	
		
		while(livro.read((char*) &ps, sizeof(StructItemAcervoISBN))){
			
			char nomes[1000],nome_aux[1000];
			int aux = 0,aux1 = 0;
			vector<string> autores_aux;
			
			char palavras[1000],palavra_aux[1000];
			int aux2 = 0,aux3 = 0;
			vector<string> palavras_aux;
			
			Livro *p = new Livro();
			p->setId(ps.id),p->setTitulo_obra(ps.titulo_obra),p->setNum_edicao(ps.num_edicao);
			p->setCidade(ps.cidade),p->setEditora(ps.editora),p->setAno(ps.ano);
			p->setNum_pag(ps.num_pag),p->setTam_cm(ps.tam_cm),p->setAssunto(ps.assunto);
			p->setQuantExemplares(ps.quant_exemplares),p->setQuantAtual(ps.quant_atual);
			p->setTipo(ps.tipo),p->setCDU(ps.CDU),p->setISBN(ps.ISBN);
			strcpy(nomes,ps.autores);
			strcpy(palavras,ps.palavraschaves);
			
			//Recuperar nome dos autores
			for(int i=0;i<strlen(nomes);i++){
				if(nomes[i] != ';'){
					nome_aux[aux1] = nomes[i];
					aux1++;
				}
				if(nomes[i] == ';'){
					autores_aux.push_back(nome_aux);
					clean(nome_aux);
					aux1 = 0;
				}
			}
			
			//Recuperar nome das palvras chaves
			for(int i=0;i<strlen(palavras);i++){
				if(palavras[i] != ';'){
					palavra_aux[aux3] = palavras[i];
					aux3++;
				}
				if(palavras[i] == ';'){
					palavras_aux.push_back(palavra_aux);
					clean(palavra_aux);
					aux3 = 0;
				}
			}
			p->setAutores(autores_aux);
			p->setPalavras_chave(palavras_aux);
			addVetorItem(items,p);
		}
		
		//Fechando arquivo
		livro.close();
		
	}
	
	///Abrindo arquivo Trabalho de conclusão
	if(trabalho.is_open()){
		
		StructItemAcervoISBN ps;
	
		
		while(trabalho.read((char*) &ps, sizeof(StructItemAcervoISBN))){
			
			char nomes[1000],nome_aux[1000];
			int aux = 0,aux1 = 0;
			vector<string> autores_aux;
			
			char palavras[1000],palavra_aux[1000];
			int aux2 = 0,aux3 = 0;
			vector<string> palavras_aux;
			
			Livro *p = new Livro();
			p->setId(ps.id),p->setTitulo_obra(ps.titulo_obra),p->setNum_edicao(ps.num_edicao);
			p->setCidade(ps.cidade),p->setEditora(ps.editora),p->setAno(ps.ano);
			p->setNum_pag(ps.num_pag),p->setTam_cm(ps.tam_cm),p->setAssunto(ps.assunto);
			p->setQuantExemplares(ps.quant_exemplares),p->setQuantAtual(ps.quant_atual);
			p->setTipo(ps.tipo),p->setCDU(ps.CDU),p->setISBN(ps.ISBN);
			strcpy(nomes,ps.autores);
			strcpy(palavras,ps.palavraschaves);
			
			//Recuperar nome dos autores
			for(int i=0;i<strlen(nomes);i++){
				if(nomes[i] != ';'){
					nome_aux[aux1] = nomes[i];
					aux1++;
				}
				if(nomes[i] == ';'){
					autores_aux.push_back(nome_aux);
					clean(nome_aux);
					aux1 = 0;
				}
			}
			
			//Recuperar nome das palvras chaves
			for(int i=0;i<strlen(palavras);i++){
				if(palavras[i] != ';'){
					palavra_aux[aux3] = palavras[i];
					aux3++;
				}
				if(palavras[i] == ';'){
					palavras_aux.push_back(palavra_aux);
					clean(palavra_aux);
					aux3 = 0;
				}
			}
			p->setAutores(autores_aux);
			p->setPalavras_chave(palavras_aux);
			addVetorItem(items,p);
		}
		
		//Fechando arquivo
		trabalho.close();
		
	}
	
	///Abrindo arquivo Períodico
	if(periodico.is_open()){
		
		StructItemAcervoISSN ps;
	
		
		while(periodico.read((char*) &ps, sizeof(StructItemAcervoISSN))){
			
			char nomes[1000],nome_aux[1000];
			int aux = 0,aux1 = 0;
			vector<string> autores_aux;
			
			char palavras[1000],palavra_aux[1000];
			int aux2 = 0,aux3 = 0;
			vector<string> palavras_aux;
			
			Periodico *p = new Periodico();
			p->setId(ps.id),p->setTitulo_obra(ps.titulo_obra),p->setNum_edicao(ps.num_edicao);
			p->setCidade(ps.cidade),p->setEditora(ps.editora),p->setAno(ps.ano);
			p->setNum_pag(ps.num_pag),p->setTam_cm(ps.tam_cm),p->setAssunto(ps.assunto);
			p->setQuantExemplares(ps.quant_exemplares),p->setQuantAtual(ps.quant_atual);
			p->setTipo(ps.tipo),p->setCDU(ps.CDU),p->setISSN(ps.ISSN);
			strcpy(nomes,ps.autores);
			strcpy(palavras,ps.palavraschaves);
			
			//Recuperar nome dos autores
			for(int i=0;i<strlen(nomes);i++){
				if(nomes[i] != ';'){
					nome_aux[aux1] = nomes[i];
					aux1++;
				}
				if(nomes[i] == ';'){
					autores_aux.push_back(nome_aux);
					clean(nome_aux);
					aux1 = 0;
				}
			}
			
			//Recuperar nome das palvras chaves
			for(int i=0;i<strlen(palavras);i++){
				if(palavras[i] != ';'){
					palavra_aux[aux3] = palavras[i];
					aux3++;
				}
				if(palavras[i] == ';'){
					palavras_aux.push_back(palavra_aux);
					clean(palavra_aux);
					aux3 = 0;
				}
			}
			p->setAutores(autores_aux);
			p->setPalavras_chave(palavras_aux);
			addVetorItem(items,p);
		}
		
		//Fechando arquivo
		periodico.close();
		
	}
	
}
