#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct refei�ao {

	string entrada;
	string principal;
	float custo;
};
struct identidade {

	string primeironome, ultimonome;
	int numeroid, numerogrupo, duracao;
	string curso;
	float plafond;
	bool tipo;
	int n_elementos;

};


struct Mesa {
	int numMesa;
	int tamanho;
	int vagas;
	identidade * pessoas;

};
void imprimeCantina(Mesa*cantina, int numeromesas);

void imprimeMesa(Mesa*cantina, int numeromesas);
void InsereRefei��o(refei�ao * novaref);
void ImprimeRefei��o(refei�ao * novaref);
Mesa * criamesas2(int &numeromesas, Mesa*temp, int tamanhodacantina);
bool decide(bool tipo);
identidade * criagrupo(string * pNome, string * uNome, string * cursos, int elementos, bool decide, int numerogrupo);
int adicionafila(identidade * filadeespera, int posicaovazia, string * pNome, string * uNome, string * cursos);
void imprimeFila(identidade * filadeespera, int tamanho); 
void adicionamesa(Mesa * cantina, identidade * filadeespera, int numerodemesas, int tamanho);
void imprimeMesa(Mesa*cantina, int numeromesas);
int adicionagrupo(Mesa * cantina, identidade * filadeespera, int numerodemesas, int tamanho, int valorref);
void apagaFilaEspera(identidade * f, int n_elem);
void adicionaGrupos(Mesa * cantina, identidade * filadeespera, int numeromesas, int tamanho);
bool verificagrupo(identidade * filadeespera, int custo);
int apagaElementoFilaespera(identidade * filadeespera, int custo);
void atualizagrupo(identidade * filadeespera, int numerogrup, int n_elementos);