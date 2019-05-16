#include <iostream>
#include "Cantina.h"
#include "Ficheiros.h"
#include <string>
#include <fstream>
#include <locale>
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
	filadeespera = criagrupo(filadeespera, pNome, uNome, cursos,aleatorio);


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

			cout << "(s) seguinte (e) Emergência (g) Gravar (c) Carregar dados (o) Opçoes ";
			char opcao;
			cin >> opcao;
			switch (opcao) {
			case 's':
				if (!verificagrupo(filadeespera, novaref->custo)) {
					int e;
					cout << " ***************Atenção ****************** \n Existe um membro do grupo sem plafond \n 0 - remover o grupo \n 1 - remover a pessoa \n Comando: ";
					cin >> e;
					if (e == 0) {
					}
					else if (e == 1) {
						removerPos(filadeespera, retornapos(filadeespera,novaref->custo),novaref->custo);
						escreveFiladeEspera(filadeespera);
						imprimeCantina(mesas);
					}
				}
				else {
					int special = rand() % 100;
					if (special >= 95) {
						filadeespera = criaespecial(filadeespera, pNome, uNome, cursos);


					}
					else {
						filadeespera = criagrupo(filadeespera, pNome, uNome, cursos,1);
					}

					escreveFiladeEspera(filadeespera);
					imprimeCantina(mesas);
					ciclos--;
					break;
					/*case 'e':
						break;*/
					case 'g':
						{
						fstream file;
						file.open("refeicao---------------------.txt", ios::out);
						file << novaref->entrada << endl << novaref->principal << endl << novaref->custo << endl;
						file.close();
						/*file.open("infoMesa---------------------.txt", ios::out);
						while (mesas != NULL) {
							file << mesas->numMesa << endl << mesas->tamanho << endl << mesas->vagas;
							while(mesas->pessoas != NULL) {
								file << mesas->pessoas << endl;
								mesas->pessoas = mesas->pessoas->seguinte;
							}
							mesas = mesas->seguinte;
						}
						file.close();*/
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
						
					/*case 'c':
						break;
					case 'o':
						break;*/

				}
			}
		}


		system("PAUSE");
		return 0;


	} while (running);
}
