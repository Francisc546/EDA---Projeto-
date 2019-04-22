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
		int numeroid, numerogrupo, dura�ao, departamento;
		string curso;
		float plafond;
		bool tipo;

};


struct Mesa {
	int numMesa;
	int tamanho;
	identidade * pessoas;

};

void InsereRefei��o(refei�ao * novaref);
void ImprimeRefei��o(refei�ao * novaref);
int contaLinhas(string filename);
void InserepNome(string * pNome, string filename);
void InsereuNome(string * uNome, string filename);
void InsereCurso(string * cursos, string filename);
void escrevepNome(string * pNome, int tamanho);
void escreveuNome(string * uNome, int tamanho);
void escrevecursos(string * cursos, int tamanho);
void criamesas(int tamanhocantina);
void criaidentidades( string * pNome, string * uNome, string * cursos);
//void criagrupo(string * pNome, string * uNome, string * cursos);
//void criagrupo(identidade * filadeespera, int tamanho, string * pNome, string * uNome, string * cursos);
//identidade * criagrupo(string * pNome, string * uNome, string * cursos);
Mesa * criamesas2();
bool decide(bool tipo);
identidade * criagrupo(string * pNome, string * uNome, string * cursos, int elementos, bool decide, int numerogrupo);
int adicionafila(identidade * filadeespera, int posicaovazia, string * pNome, string * uNome, string * cursos);
void imprimeFila(identidade * filadeespera, int tamanho);