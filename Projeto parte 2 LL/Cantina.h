#pragma once
#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct refeicao {

	string entrada;
	string principal;
	float custo;
};
struct identidade {
	string entidade;
	string primeironome, ultimonome;
	int numeroid, numerogrupo, duracao;
	string curso;
	int plafond;
	bool tipo;
	int n_elementos;
	identidade * seguinte;
};


struct Mesa {
	int numMesa;
	int tamanho;
	int vagas;
	identidade * pessoas;
	Mesa* seguinte;

};
identidade * criagrupo(identidade*filadeespera, string * pNome, string * uNome, string * cursos,int aleatorio);
void escreveFiladeEspera(identidade * filadeespera);
identidade * adiciona_filadeespera(identidade*filadeespera, identidade*novo);
void imprimeCantina(Mesa * mesas);
Mesa * criamesas(Mesa*mesas, int tamanhodacantina);
Mesa * adiciona_mesas(Mesa*mesas, Mesa*novo);
void InsereRefeicao(refeicao * novaref);
void ImprimeRefeicao(refeicao * novaref);
identidade * criaespecial(identidade*filadeespera, string * pNome, string * uNome, string * cursos);
bool verificagrupo(identidade * filadeespera, int custo);
identidade* adiciona_cantina(Mesa*mesas, identidade* pessoa);
identidade * insereMesas(identidade*filadeespera, Mesa*mesas);
Mesa * reduzduracao(Mesa *mesas);
identidade * alteraduracaofila(identidade * filadeespera, int numgrupo, int duracao);
Mesa * alteraduracaomesas(Mesa * mesas, int numgrupo, int duracao);
identidade * alterarnome(identidade * filadeespera, int id, string pnome, string unome);
Mesa * alterarnome2(Mesa* mesas, int id, string pnome, string unome);
void imprime(identidade * guardado);