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
		char op�ao;
		refei�ao * novaref = new refei�ao;
		cout << "-------------------------CANTINA EDA ------------------------------" << endl;
		InsereRefei��o(novaref);
		ImprimeRefei��o(novaref);
	

		cout << "(S) seguinte (e) Emerg�ncia (g) Gravar (c) Carregar dados (o) Op�oes ";
		cin >> op�ao;
		switch (op�ao) {
		case 's':
			
		}




	}
	
	
	;*/
	int posicaovazia = 0;
	identidade * filadeespera = new identidade[50];
	for (int i = 0; posicaovazia < 50; posicaovazia++) {
		//adicionafila(filadeespera, posicaovazia, pNome, uNome, cursos);
		posicaovazia = adicionafila(filadeespera, posicaovazia, pNome, uNome, cursos);
	}
	imprimeFila(filadeespera,50);
	
	
	


	
	system("Pause");

}