#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct refeiçao {

	string entrada;
	string principal;
	float custo;
};
struct identidade {
	//int special;
	string primeironome, ultimonome;
	int numeroid, numerogrupo, duracao;
	string curso;
	int plafond;
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
void InsereRefeição(refeiçao * novaref);
void ImprimeRefeição(refeiçao * novaref);
Mesa * criamesas2(int &numeromesas, Mesa*temp, int tamanhodacantina);
bool decide(bool tipo);
identidade * criagrupo(string * pNome, string * uNome, string * cursos, int elementos, bool decide, int numerogrupo); 
void imprimeMesa(Mesa*cantina, int numeromesas);
int adicionagrupo(Mesa * cantina, identidade * filadeespera, int numerodemesas, int tamanho, int valorref);
bool verificagrupo(identidade * filadeespera, int custo);
void atualizagrupo(identidade * filadeespera, int numerogrup, int n_elementos);
void grava(Mesa * cantina, int numeromesas, identidade * filadeespera, refeiçao * novaref);
void opcoes(identidade * filadeespera, int tamanho);
