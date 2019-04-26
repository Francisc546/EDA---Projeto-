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
	bool running = true;

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

	refeiçao * novaref = new refeiçao;
	InsereRefeição(novaref);
	system("cls");
	cout << "-------------------------CANTINA EDA ------------------------------" << endl;
	ImprimeRefeição(novaref);
	int posicaovazia = 0;
	identidade * filadeespera = new identidade[50];
	for (int i = 0; posicaovazia < 50; posicaovazia++) {
		//adicionafila(filadeespera, posicaovazia, pNome, uNome, cursos);
		posicaovazia = adicionafila(filadeespera, posicaovazia, pNome, uNome, cursos);
	}
	/*cout << "################" << endl;
	imprimeFila(filadeespera, 50);
	cout << "################" << endl;*/


	Mesa * temp = new Mesa[50];
	temp = criamesas2(numeromesas, temp, tamanhodacantina);


	Mesa * cantina = new Mesa[numeromesas];
	for (int k = 0; k < numeromesas; k++) {
		cantina[k] = temp[k];
		//cout << "TAMANHO NO MAIN: "<< cantina[k].tamanho;
	}
	delete[] temp;

	//adicionaGrupos(cantina, filadeespera, numeromesas, 50);
	//count_elementos = adicionagrupo(cantina, filadeespera, numeromesas, 50);
	//adicionaGrupos(cantina, filadeespera, numeromesas, 50);

	cout << "################" << endl;
	imprimeFila(filadeespera, 50);
	cout << "################" << endl;


	//adicionaGrupos(cantina, filadeespera, numeromesas, 50);
	int enter;
	posicaovazia--;
	/*for (int i = 0; i < numeromesas; i++) {
		int count_elementos = adicionagrupo(cantina, filadeespera, numeromesas, 50);
		apagaFilaEspera(filadeespera, count_elementos);
		posicaovazia = posicaovazia - (count_elementos)+1;
		cout << "################" << endl;
		imprimeFila(filadeespera, 50);
		cout << "Posicao vazia: " << posicaovazia << endl;
		cout << "################" << endl;
		posicaovazia = adicionafila(filadeespera, posicaovazia, pNome, uNome, cursos);
		cout << "################" << endl;
		imprimeFila(filadeespera, 50);
		cout << "################" << endl;
		//imprimeFila(filadeespera, 50);
		imprimeCantina(cantina, numeromesas);

	}*/

	/*cout << "################" << endl;
	imprimeFila(filadeespera, 50);
	cout << "################" << endl;*/



	do
	{
		cout << "(S) seguinte (E) Emergência (G) Gravar (C) Carregar dados (O) Opçoes ";
		char opcao;
		int count_elementos = 0;
		cin >> opcao;
		switch (opcao) {

		case 'S':
			count_elementos = adicionagrupo(cantina, filadeespera, numeromesas, 50);
			apagaFilaEspera(filadeespera, count_elementos);
			posicaovazia = posicaovazia - (count_elementos)+1;
			cout << "################" << endl;
			imprimeFila(filadeespera, 50);
			cout << "Posicao vazia: " << posicaovazia << endl;
			cout << "################" << endl;
			posicaovazia = adicionafila(filadeespera, posicaovazia, pNome, uNome, cursos);
			/*cout << "################" << endl;
			imprimeFila(filadeespera, 50);
			cout << "################" << endl;
			//imprimeFila(filadeespera, 50);*/
			imprimeCantina(cantina, numeromesas);
			break;
		case 'E':
			break;
		case 'G':
			break;

		}
 
	} while (running);
	system("Pause");
}