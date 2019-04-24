#include <iostream>
#include <string>
#include <fstream>
#include <locale>
#include "Cantina.h"

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
	int numeromesas = 0;
	int tamanhodacantina = rand() % 21 + 30;


	/*int tamanhocantina = rand() % 21 + 30;
	if (tamanhocantina >= 30 && tamanhocantina <= 50) {
		char opçao;
		refeiçao * novaref = new refeiçao;
		cout << "-------------------------CANTINA EDA ------------------------------" << endl;
		InsereRefeição(novaref);
		ImprimeRefeição(novaref);


		cout << "(S) seguinte (e) Emergência (g) Gravar (c) Carregar dados (o) Opçoes ";
		cin >> opçao;
		switch (opçao) {
		case 's':

		}




	}


	;*/
	/*int posicaovazia = 0;
	identidade * filadeespera = new identidade[50];
	for (int i = 0; posicaovazia < 50; posicaovazia++) {
		//adicionafila(filadeespera, posicaovazia, pNome, uNome, cursos);
		posicaovazia = adicionafila(filadeespera, posicaovazia, pNome, uNome, cursos);
	}
	imprimeFila(filadeespera, 50);*/
	Mesa * temp = new Mesa[50];
	criamesas2(numeromesas,temp,tamanhodacantina);

	
	Mesa * cantina = new Mesa[numeromesas];
	for (int k = 0; k < numeromesas; k++) {
		cantina[k] = temp[k];
	}
	delete[] temp;
	for (int i = 0; i < numeromesas; i++) {
		cout << "Mesa: " << cantina[i].numMesa << " Tamanho: " << cantina[i].tamanho << endl;
	}
	

	//cout << numeromesas<<endl;
	//Mesa * cantina = new Mesa[n_mesa];
	
	//imprimeMesa(cantina, numeromesas);






	system("Pause");

}