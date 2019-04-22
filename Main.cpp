#include <iostream>
#include <string>
#include <fstream>
#include "Cantina.h"
#include <locale>

using namespace std;


void main() {
	locale::global(locale(""));
	srand(time(NULL));

	
	int tamanhopNome = contaLinhas("primeiro_nome.txt");
	string * pNome = new string[tamanhopNome];
	InserepNome(pNome, "primeiro_nome.txt");
	int tamanhouNome = contaLinhas("ultimo_nome.txt");
	string * uNome = new string[tamanhouNome];
	InsereuNome(uNome, "ultimo_nome.txt");
	int tamanhocursos = contaLinhas("cursos.txt");
	string * cursos = new string[tamanhocursos];
	InsereCurso(cursos, "cursos.txt");

	/*int tamanhocantina = rand() % 21 + 30;
	if (tamanhocantina >= 30 && tamanhocantina <= 50) {
		char opçao;
		refeiçao * novaref = new refeiçao;
		cout << "-------------------------CANTINA EDA ------------------------------" << endl;
		InsereRefeição(novaref);
		ImprimeRefeição(novaref);
		grupo * filadeespera = new grupo[50];

		cout << "(S) seguinte (e) Emergência (g) Gravar (c) Carregar dados (o) Opçoes ";
		cin >> opçao;
		switch (opçao) {
			case 's':
			
		}




	}
	
	
	;*/
	//identidade * filadeespera = new identidade[50];
	//criagrupo(pNome, uNome, cursos);
	identidade p;
	p.curso = "INFORMATICA";
	Mesa * cantina = criamesas2();
	cantina[4].pessoas[0] = p;

	cout << cantina[4].pessoas[0].curso;
	




	/*refeiçao * novaref = new refeiçao;
	cout << "-------------------------CANTINA EDA ------------------------------" << endl;
	InsereRefeição(novaref);
	ImprimeRefeição(novaref);*/
	

	
	


	
	system("Pause");
}