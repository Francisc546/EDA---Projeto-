#include <iostream>
#include <string>
#include <fstream>
#include <locale>
#include "Cantina.h"
#include "Ficheiros.h"

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
	int tamanhodacantina = rand() % 20 + 30;

	/*refei�ao * novaref = new refei�ao;
	InsereRefei��o(novaref);
	system("cls");
	cout << "-------------------------CANTINA EDA ------------------------------" << endl;
	ImprimeRefei��o(novaref);
	cout << "(S) seguinte (E) Emerg�ncia (G) Gravar (C) Carregar dados (O) Op�oes ";
	char opcao;
	cin >> opcao;
	switch (isupper(opcao)) {
	case 'S':
		ad*/





		int posicaovazia = 0;
		identidade * filadeespera = new identidade[50];
		for (int i = 0; posicaovazia < 50; posicaovazia++) {
			//adicionafila(filadeespera, posicaovazia, pNome, uNome, cursos);
			posicaovazia = adicionafila(filadeespera, posicaovazia, pNome, uNome, cursos);
		}
		imprimeFila(filadeespera, 50);

		Mesa * temp = new Mesa[50];
		temp = criamesas2(numeromesas, temp, tamanhodacantina);


		Mesa * cantina = new Mesa[numeromesas];
		for (int k = 0; k < numeromesas; k++) {
			cantina[k] = temp[k];
			//cout << "TAMANHO NO MAIN: "<< cantina[k].tamanho;
		}
		delete[] temp;
		adicionamesa(cantina, filadeespera, numeromesas, 50);
		



		/*cout << "(S) seguinte (e) Emerg�ncia (g) Gravar (c) Carregar dados (o) Op�oes ";
		cin >> op�ao;
		switch (op�ao) {
		case 's':

		}*/












		system("Pause");
	}
