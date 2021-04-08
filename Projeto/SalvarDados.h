#ifndef SALVARDADOS_H
#define SALVARDADOS_H
#include <fstream>
#include "Cartaz.h"
#include "Livro.h"
#include "ItemAcervo.h"
#include "ManterDados.h"
#include "Mapa.h"
#include "Midia.h"
#include "Periodico.h"
#include "Relatorio.h"
#include "TrabalhoConclusao.h"

class SalvarDados
{
	public:
		
		SalvarDados();
		~SalvarDados();
		
		void clean(char *var);
		void addVetorItem(vector <ItemAcervo*> &items,ItemAcervo *p);
		void SalvarDadosItemBinario(vector <ItemAcervo*> &items);
		void lerDadosItemBinario(vector <ItemAcervo *> &items);
		
	protected:
};

#endif
