#include <iostream>
#include "Cantina.h"
#include "Ficheiros.h"
#include <string>
#include <fstream>
#include <locale>
#include "Fila.h"
#include "Emergencia.h"
using namespace std;



int main() {
	system("color 0A");
	bool running = true;
	srand(time(NULL));
	int tamanhopNome = contaLinhas("primeiro_nome.txt");
	int tamanhouNome = contaLinhas("ultimo_nome.txt");
	int tamanhocursos = contaLinhas("cursos.txt");
	int aleatorio = rand() % 2 + 2;
	string * pNome = new string[tamanhopNome];
	string * uNome = new string[tamanhouNome];
	string * cursos = new string[tamanhocursos];
	Insere(pNome, "primeiro_nome.txt", tamanhopNome); // insere os primeiros nomes no array pNome
	Insere(uNome, "ultimo_nome.txt", tamanhouNome); // insere os ultimos nomes no array uNome
	Insere(cursos, "cursos.txt", tamanhocursos); // insere os cursos no array cursos

	identidade * filadeespera = NULL;
	filadeespera = criagrupo(filadeespera, pNome, uNome, cursos, aleatorio);


	Mesa*mesas = NULL;
	int tamanhodacantina = rand() % 20 + 30;
	mesas = criamesas(mesas, tamanhodacantina);





	do {
		int ciclos = 10;
		refeicao * novaref = new refeicao;
		InsereRefeicao(novaref);
		system("cls");
		cout << "-------------------------CANTINA EDA ------------------------------" << endl;
		ImprimeRefeicao(novaref);
		escreveFiladeEspera(filadeespera);
		imprimeCantina(mesas);
		
		while (ciclos != 0) {

			cout << "(s) seguinte (e) Emergencia (g) Gravar (c) Carregar dados (o) Opcoes ";
			char opcao;
			cin >> opcao;
			switch (opcao) {
			case 's':
				if (!verificagrupo(filadeespera, novaref->custo)) {
					int e;
					cout << " ***************Atenção ****************** \n Existe um membro do grupo sem plafond \n 0 - remover o grupo \n 1 - remover a pessoa \n Comando: ";
					cin >> e;
					if (e == 0) {
						filadeespera = removeGrupo(filadeespera);
						escreveFiladeEspera(filadeespera);
						imprimeCantina(mesas);
					}
					else if (e == 1) {
						filadeespera = removerPos(filadeespera, retornapos(filadeespera,novaref->custo));
						escreveFiladeEspera(filadeespera);
						imprimeCantina(mesas);
					}
				}
				else {
					filadeespera = insereMesas(filadeespera, mesas);
					reduzduracao(mesas);

					
					int special = rand() % 100;
					if (special >= 95) {
						filadeespera = criaespecial(filadeespera, pNome, uNome, cursos);


					}
					else {
						filadeespera = criagrupo(filadeespera, pNome, uNome, cursos, 1);
					}

					escreveFiladeEspera(filadeespera);
					imprimeCantina(mesas);
					ciclos--;
				}
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
					removeElemento(mesas, alunoid, novaref->custo);
					escreveFiladeEspera(filadeespera);
					cout << endl;
					imprimeCantina(mesas);
				}
				if (emergencia == 1) {
					int numerogrupo;
					cout << "Indique o numero do grupo que quer retirar: ";
					cin >> numerogrupo;
					removegrupo(mesas, numerogrupo);
					escreveFiladeEspera(filadeespera);
					cout << endl;
					imprimeCantina(mesas);

				}
				break;
			case 'g':
			{
				fstream file;
				file.open("refeicao---------------------.txt", ios::out);
				file << novaref->entrada << endl << novaref->principal << endl << novaref->custo << endl;
				file.close();
				file.open("infoFilaEspera---------------.txt", ios::out);
				while (filadeespera != NULL) {
					if (filadeespera->tipo) {
						file << filadeespera->tipo << endl << filadeespera->primeironome << endl
							<< filadeespera->ultimonome << endl
							<< filadeespera->numeroid << endl << filadeespera->curso << endl
							<< filadeespera->plafond << endl << filadeespera->numerogrupo << endl
							<< filadeespera->duracao << endl << filadeespera->n_elementos << endl;
						filadeespera = filadeespera->seguinte;
					}
					else {
						file << filadeespera->tipo << endl << filadeespera->primeironome << endl
							<< filadeespera->ultimonome << endl << filadeespera->numeroid << endl
							<< filadeespera->plafond << endl << filadeespera->numerogrupo << endl
							<< filadeespera->duracao << endl << filadeespera->n_elementos << endl;
						filadeespera = filadeespera->seguinte;
					}
				}
				file.close();
				cout << "******** Tudo Gravado" << endl;
				break;
			}

			case 'c':
				break;
			case 'o':
				cout << "-----------------Opçoes------------------" << endl;
				cout <<" 1 - Alterar plafond de um individuo" << endl;
				cout << " 2 - Alterar o nome de um individuo" << endl;
				cout << "Comando: ";
				int p;
				cin >> p;
				int id;
				int plafondalterado;
				string nome;
				if (p == 1) {
					cout << "Indique o id do aluno/staff que quer alterar o plafond: ";
					cin >> id;
					cout << "Indique o novo plafond: ";
					cin >> plafondalterado;
					identidade * aux = filadeespera;
					while (aux->seguinte != NULL) {
						if (aux->numeroid == id) {
							aux->plafond = plafondalterado;
							break;
						}
						aux = aux->seguinte;
					}
					escreveFiladeEspera(filadeespera);
					imprimeCantina(mesas);
				}
				else if (p == 2) {
					cout << "Indique o id do aluno/staff que quer alterar o nome: ";
					cin >> id;
					cout << "Indique o novo nome: ";
					cin >> nome;
					identidade * aux = filadeespera;
					while (aux->seguinte != NULL) {
						if (aux->numeroid == id) {
							aux->primeironome = nome;
							break;
						}
						aux = aux->seguinte;
					}
					escreveFiladeEspera(filadeespera);
					imprimeCantina(mesas);



				}

				break;

				
			}
		}


		system("PAUSE");
		return 0;


	} while (running);
}