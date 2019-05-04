#include <iostream>
#include <string>
#include <fstream>
#include <locale>
#include "Cantina.h"
#include "Ficheiros.h"
#include "Fila.h"
#include "Emergencia.h"
#include <vector>
#include <algorithm>

using namespace std;


void main() {
	//system("color 4F")
	locale::global(locale(""));
	srand(time(NULL));
	bool running = true; // visto que o programa nao tem limite de iterações é criada uma variavel do tipo bool que se mantem true ao longo do programa

	int tamanhopNome = contaLinhas("primeiro_nome.txt");
	string * pNome = new string[tamanhopNome];
	InserepNome(pNome, "primeiro_nome.txt"); // insere os primeiros nomes no array pNome
	int tamanhouNome = contaLinhas("ultimo_nome.txt");
	string * uNome = new string[tamanhouNome]; 
	InsereuNome(uNome, "ultimo_nome.txt"); // insere os ultimos nomes no array uNome
	int tamanhocursos = contaLinhas("cursos.txt");
	string * cursos = new string[tamanhocursos];
	InsereCurso(cursos, "cursos.txt"); // insere os cursos no array cursos
	
	int numeromesas = 0;
	int tamanhodacantina = rand() % 20 + 30; // gerado o tamanho da cantina

	
	int posicaovazia = 0;
	identidade * filadeespera = new identidade[50]; // criada a fila de espera (máximo 50 pessoas)
	for (int i = 0; posicaovazia < 50; posicaovazia++) {
		posicaovazia = adicionafila(filadeespera, posicaovazia, pNome, uNome, cursos); // aqui é preenchida a fila de espera (adiciona pessoas à fila de espera na posiçao vazia)
	}
	


	Mesa * temp = new Mesa[50]; // criado uma array do tipo mesa , capacidade maxima 50
	temp = criamesas2(numeromesas, temp, tamanhodacantina); // são geradas as mesas com tamanho aleatório


	Mesa * cantina = new Mesa[numeromesas]; // criado um novo array desta vez com tamanho equivalente ao numero de mesas gerado;
	for (int k = 0; k < numeromesas; k++) {
		cantina[k] = temp[k];
		
	}
	delete[] temp;
	

	


	posicaovazia--;
	
	

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
		
			cout << "(s) seguinte (e) Emergência (g) Gravar (c) Carregar dados (o) Opçoes ";
			int count_elementos = 0;
			char opcao;
			cin >> opcao;
			switch (opcao) {

			case 's':
				if (!verificagrupo(filadeespera, novaref->custo)) { //verifica o grupo
					int e;
					cout << " ***************Atenção ****************** \n Existe um membro do grupo sem plafond \n 0 - remover o grupo \n 1 - remover a pessoa \n Comando: ";
					cin >> e;
					if (e == 0) {
						apagaFilaEspera(filadeespera, filadeespera[0].n_elementos); // apaga os elementos da lista de espera
						posicaovazia = posicaovazia - (filadeespera[0].n_elementos)+1;  
						posicaovazia = adicionafila(filadeespera, posicaovazia, pNome, uNome, cursos); // atualiza a posicao vazia
					}
					else {
						posicaovazia = posicaovazia - apagaElementoFilaespera(filadeespera, novaref->custo) + 1; // elimina um elemento da fila

					}
				}
				else {
					
						count_elementos = adicionagrupo(cantina, filadeespera, numeromesas, 50, novaref->custo); // adiciona um grupo a mesa
						apagaFilaEspera(filadeespera, count_elementos);// elimina essa grupo da fila de espera
						posicaovazia = posicaovazia - (count_elementos)+1;
						posicaovazia = adicionafila(filadeespera, posicaovazia, pNome, uNome, cursos); // atualiza a posicao vazia
						int i = 0;
						while (i < numeromesas) {
							for (int j = 0; j < cantina[i].tamanho; j++) {
								cantina[i].pessoas[j].duracao--;
								if (cantina[i].pessoas[j].duracao == 0) {
									cout << "**************IDENTIDADE REMOVIDA*******************" << endl;
									cout << cantina[i].pessoas[j].primeironome << " " << cantina[i].pessoas[j].ultimonome << ", Plafond atualizado: " << cantina[i].pessoas[j].plafond - novaref->custo << endl;
									cout << "******************************************************" << endl;
									int aux = cantina[i].tamanho;
									identidade * p_temp = new identidade[aux];
									cantina[i].pessoas[j] = p_temp[j];
									delete[] p_temp;
									cantina[i].vagas = cantina[i].tamanho;
								}
							}
							i++;
						}
						/* ciclo criado para quando acabar a duração remover os elementos da mesa*/
				}
				ciclos--; 
				imprimeCantina(cantina, numeromesas);
				imprimeFila(filadeespera, 50);
				break;
			case 'e':
				int emergencia;
				cout << "******************Situaçao de Emergencia************************" << endl;
				cout << "0 - Remover aluno/staff da cantina \n1 - Remover grupo da cantina " << endl;
				cout << "Comando: ";
				cin >> emergencia;
				if (emergencia == 0) {
					int alunoid;
					cout << "Indique o numero do aluno/staff que quer remover: ";
					cin >> alunoid;
					removeElemento(cantina, alunoid, numeromesas, novaref->custo); // remove o elemento da mesa
					count_elementos = adicionagrupo(cantina, filadeespera, numeromesas, 50, novaref->custo);
					apagaFilaEspera(filadeespera, count_elementos);
					posicaovazia = posicaovazia - (count_elementos)+1;
					posicaovazia = adicionafila(filadeespera, posicaovazia, pNome, uNome, cursos);
					// adiciona grupo a mesa, nao espera para o proximo ciclo , e atualiza a posicao vazia
					imprimeFila(filadeespera, 50);
					cout << endl;
					imprimeCantina(cantina, numeromesas);


				}
				else if (emergencia == 1) {
					int numerogrupo;
					cout << "Indique o numero do grupo que quer retirar: ";
					cin >> numerogrupo;
					removeGrupo(cantina, numerogrupo, numeromesas, novaref->custo); // remove o grupo
					count_elementos = adicionagrupo(cantina, filadeespera, numeromesas, 50, novaref->custo);
					apagaFilaEspera(filadeespera, count_elementos);
					posicaovazia = posicaovazia - (count_elementos)+1;
					posicaovazia = adicionafila(filadeespera, posicaovazia, pNome, uNome, cursos);
					// adiciona grupo a mesa, nao espera para o proximo ciclo , e atualiza a posicao vazia
					imprimeFila(filadeespera, 50);
					cout << endl;
					imprimeCantina(cantina, numeromesas);
				}
				break;

			case 'g':
				grava(cantina,numeromesas,filadeespera,novaref);
				break;
			case 'c': 
			{
				string nome;
				cout << "Escreva o nome do Ficheiro que quer ler da seguinte forma - nome.txt" << endl;
				cin >> nome;
				int tamanho = 0;
				tamanho = contaLinhas(nome);
				string *nomef = new string[tamanho];
				InsereFicheiros(nomef, nome);
				escreveFicheiros(nomef, tamanho);
				}
				break;

			case 'o':

				cout << "-----------------Opçoes------------------" << endl;
				cout << " 0 Apresentar todos os membros da cantina" << endl << " 1 Alterar plafond de um individuo" << endl;
				cout << "Comando: ";
				int p;
				cin >> p;
				if (p == 1) {
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
				else if (p == 0) {
					//opcoes(filadeespera, 50);
					for (int i = 0; i < 50; i++) {
						if (filadeespera[i].tipo == 1) {
							cout << filadeespera[i].primeironome << " " << filadeespera[i].ultimonome << ", " << filadeespera[i].curso << ", grupo " << filadeespera[i].numerogrupo << ", plafond " << filadeespera[i].plafond << endl;
						}
						else {
							cout << filadeespera[i].primeironome << " " << filadeespera[i].ultimonome << ", departamento " << filadeespera[i].numerogrupo << ", plafond " << filadeespera[i].plafond << endl;
						}
					}
					int j = 0;
					while (j < numeromesas) {
						for (int r = 0; r < cantina[j].tamanho; r++) {
							if (cantina[j].pessoas[r].tipo == 1) {
								cout << cantina[j].pessoas[r].primeironome << " " << cantina[j].pessoas[r].ultimonome << ", " << cantina[j].pessoas[r].curso << ", grupo" << cantina[j].pessoas[r].numerogrupo << ", plafond " << cantina[j].pessoas[r].plafond << endl;
							}
							else {
								cout << cantina[j].pessoas[r].primeironome << " " << cantina[j].pessoas[r].ultimonome << ", departamento" << cantina[j].pessoas[r].numerogrupo << ", plafond " << cantina[j].pessoas[r].plafond << endl;
							}
						}
						j++;
					}
				}
				break;
			}

		} 
	} while (running);
		
	system("Pause");
}