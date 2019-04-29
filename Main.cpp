#include <iostream>
#include <string>
#include <fstream>
#include <locale>
#include "Cantina.h"
#include "Ficheiros.h"
#include "Fila.h"
#include "Emergencia.h"

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

	/*refeiçao * novaref = new refeiçao;
	InsereRefeição(novaref);
	system("cls");
	cout << "-------------------------CANTINA EDA ------------------------------" << endl;
	0ImprimeRefeição(novaref);*/
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
	identidade * plafondinsuf = new identidade[100];

	//adicionaGrupos(cantina, filadeespera, numeromesas, 50);
	//count_elementos = adicionagrupo(cantina, filadeespera, numeromesas, 50);
	//adicionaGrupos(cantina, filadeespera, numeromesas, 50);

	//cout << "################" << endl;
	//imprimeFila(filadeespera, 50);
	//cout << "################" << endl;


	//adicionaGrupos(cantina, filadeespera, numeromesas, 50);
	
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


	do {
		int ciclos = 10;
		refeiçao * novaref = new refeiçao;
		InsereRefeição(novaref);
		system("cls");
		cout << "-------------------------CANTINA EDA ------------------------------" << endl;
		ImprimeRefeição(novaref);
		imprimeCantina(cantina, numeromesas);
		imprimeFila(filadeespera, 50);
		while(ciclos != 0){
		
			cout << "(S) seguinte (E) Emergência (G) Gravar (C) Carregar dados (O) Opçoes ";
			int count_elementos = 0;
			char opcao;
			cin >> opcao;
			switch (opcao) {

			case 'S':
				if (!verificagrupo(filadeespera, novaref->custo)) {
					int e;
					cout << " ***************Atenção ****************** \n Existe um membro do grupo sem plafond \n 0 - remover o grupo \n 1 - remover a pessoa \n Comando: ";
					cin >> e;
					if (e == 0) {
						apagaFilaEspera(filadeespera, filadeespera[0].n_elementos + 1);
						posicaovazia = posicaovazia - (filadeespera[0].n_elementos) + 1;
						posicaovazia = adicionafila(filadeespera, posicaovazia, pNome, uNome, cursos);
					}
					else {
						posicaovazia = posicaovazia - apagaElementoFilaespera(filadeespera, novaref->custo) + 1;

					}
				}
				else {
					count_elementos = adicionagrupo(cantina, filadeespera, numeromesas, 50, novaref->custo);
					apagaFilaEspera(filadeespera, count_elementos);
					posicaovazia = posicaovazia - (count_elementos)+1;
					/*cout << "################" << endl;
					cout << "Posicao vazia: " << posicaovazia << endl;
					cout << "################" << endl;*/
					posicaovazia = adicionafila(filadeespera, posicaovazia, pNome, uNome, cursos);
					int i = 0;
					while (i < numeromesas) {
						for (int j = 0; j < cantina[i].tamanho; j++) {
							cantina[i].pessoas[j].duracao--;
						}
						i++;
					}
					
				}
				ciclos--;
				imprimeCantina(cantina, numeromesas);
				imprimeFila(filadeespera, 50);
				break;
			case 'E':
				int emergencia;
				cout << "******************Situaçao de Emergencia************************" << endl;
				cout << "0 - Remover aluno/staff da cantina \n1 - Remover grupo da cantina " << endl;
				cin >> emergencia;
				if (emergencia == 0) {
					int alunoid;
					cout << "Indique o numero do aluno/staff que quer remover: ";
					cin >> alunoid;
					removeElemento(cantina, alunoid, numeromesas, novaref->custo);
					imprimeFila(filadeespera, 50);
					imprimeCantina(cantina, numeromesas);

				}
				break;
			case 'G':

				break;

			case 'O':

				cout << "-----------------Opçoes------------------" << endl;
				cout << "1º Apresentar por ordem alfabética os membros" << endl << "2º Alterar plafond de um individuo" << endl;
				int p;
				cin >> p;
				if (p == 2) {
					int id;
					int plafondalterado;
					cout << "Indique o id do aluno/staff que quer alterar o Plafond " << endl;
					cin >> id;
					cout << "Indique o novo plafond: ";
					cin >> plafondalterado;
					for (int i = 0; i < 50; i++) {
						if (filadeespera[i].numeroid == id) {
							filadeespera[i].plafond = plafondalterado;
							imprimeCantina(cantina, numeromesas);
							imprimeFila(filadeespera, 50);
						}
						else {
							cout << "Aluno não encontrado" << endl;

						}
						break;
					}
				}
				break;
			}

		} 
	} while (running);
		
	system("Pause");
}