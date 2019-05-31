#include <iostream>
#include "Cantina.h"
#include "Ficheiros.h"
#include <string>
#include <fstream>
#include <locale>
#include "Fila.h"
#include "Emergencia.h"
#include "Opcoes.h"
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

	
	identidade  pessoalguardado;


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
						filadeespera = removeGrupo(filadeespera, pessoalguardado);
						cout << "Imprimindo pessoal guardado" << endl;
						identidade * aux = &pessoalguardado;
						while (aux != NULL) {
							cout << aux->primeironome << endl;
							aux = aux->seguinte;
						}
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
					reduzduracao(mesas,novaref->custo);
					removeElementos(mesas);
					
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
				else if (emergencia == 1) {
					int numerogrupo;
					cout << "Indique o numero do grupo que quer retirar: ";
					cin >> numerogrupo;
					removegrupoEmergencia(mesas,numerogrupo,novaref->custo);
					escreveFiladeEspera(filadeespera);
					cout << endl;
					imprimeCantina(mesas);

				}
				break;
			case 'g':
				rec(novaref, filadeespera, mesas, tamanhodacantina);
				cout << "******** Tudo Gravado" << endl << endl;
				break;

			case 'c':
				cout << endl << "************** Carregamento de dados" << endl;
				loading(novaref, filadeespera);
				loading_m(mesas);
				ImprimeRefeicao(novaref);
				escreveFiladeEspera(filadeespera);
				imprimeCantina(mesas);
				//cout << "It`s done" << endl;
				break;
			case 'o':
				cout << "-----------------Opçoes------------------" << endl;
				cout << " 1 - Alterar plafond de um individuo" << endl;
				cout << " 2 - Alterar o nome de um individuo" << endl;
				cout << " 3 - Alterar a duracao de um grupo" << endl;
				cout << " 4 - Pesquisa por curso / departamento " << endl;
				cout << " 5 - Ordenar mesas " << endl;
				cout << " 6 - Ordenar identidades alfabeticamente pelo ultimo nome " << endl;
				cout << " 7 - Pesquisar a identidade com base no id " << endl;
				cout << "Comando: ";
				int p;
				cin >> p;
				int id;
				int plafondalterado;
				string pnome;
				string unome;
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
					int decisao = 0;
					cout << "Pretende alterar o nome de alguem que esta na fila (1) ou nas mesas (2): ";
					cin >> decisao;
					cout << "Indique o id do aluno/staff que quer alterar o nome: ";
					cin >> id;
					cout << "Indique o primeiro e ultimo nomes separados por espaço: ";
					cin >> pnome >> unome;
					if (decisao == 1) {
						alterarnome(filadeespera, id, pnome, unome);
						escreveFiladeEspera(filadeespera);
						imprimeCantina(mesas);
					}
					else if (decisao == 2) {
						alterarnome2(mesas, id, pnome, unome);
						escreveFiladeEspera(filadeespera);
						imprimeCantina(mesas);

					}



				}
				else if (p == 3) {
					int commando2 = 0;
					cout << "Pretende alterar a duracao de um grupo que esteja nas (1) mesas ou na fila de espera (2) : ";
					cin >> commando2;

					int numgrupo = 0;
					cout << "Indique o numero do grupo que pretende alterar a duracao: ";
					cin >> numgrupo;

					int novadur = 0;
					cout << "Indique a nova duracao: ";
					cin >> novadur;
					if (novadur >= 2 && novadur <= 5) {

						if (commando2 == 2) {
							alteraduracaofila(filadeespera, numgrupo, novadur);
							escreveFiladeEspera(filadeespera);
							imprimeCantina(mesas);

						}
						else if (commando2 == 1) {
							alteraduracaomesas(mesas, numgrupo, novadur);
							escreveFiladeEspera(filadeespera);
							imprimeCantina(mesas);
						}

					}
					else {
						cout << "Duracao invalida" << endl;
					}


				}
				else if (p == 4) {
					int opcao = 0;
					cout << "Pretende pesquisar por departamento (1) ou por curso (2): " << endl;
					cin >> opcao;
					if (opcao == 1) {
						int departamento = 0;
						cout << "Indique o numero do departamento: ";
						cin >> departamento;
						cout << "_____________________Departamento " << departamento << "___________________" << endl;
						imprime(filadeespera, departamento);
						imprimemesa(mesas, departamento);
						cout << "________________________________________________________" << endl;
					}
					else if (opcao == 2) {
						int opcao = 0;
						cout << "Selecione o curso: " << endl;
						cout << "0 - Economia" << endl;
						cout << "1 - Educação Basica" << endl;
						cout << "2 - Matematica" << endl;
						cout << "3 - Linguas e Relacoes Empresariais" << endl;
						cout << "4 - Gestao" << endl;
						cout << "5 - Estudos da cultura" << endl;
						cout << "6 - Engenharia Informatica" << endl;
						cout << "7 - Engenharia Eletronica e Telecomunicacoes" << endl;
						cout << "8 - Educacao Fisica e Desporto" << endl;
						cout << "9 - Engeharia civil" << endl;
						cout << "10 - Enfermagem" << endl;
						cout << "11 - Direcao e Gestao Hoteleira" << endl;
						cout << "12 - Artes Visuais" << endl;
						cout << "13 - Biologia" << endl;
						cout << "14 - Bioquimica" << endl;
						cout << "15 - Ciencias de Educacao" << endl;
						cout << "16 - Comunicaçao, Cultura e Organizacoes" << endl;
						cout << "17 - Design" << endl;
						cout << "18 - Psicologia" << endl;
						cin >> opcao;

						cout << "_____________________Curso " << cursos[opcao] << "___________________" << endl;
						imprime2(filadeespera,cursos[opcao]);
						imprimemesa2(mesas, cursos[opcao]);
						cout << "________________________________________________________" << endl;


					}

				}
				else if (p == 5) {
					ordena(mesas);
				}
				else if (p == 6) {
					ordenaFmaisM(filadeespera, mesas);
				}
				else if (p == 7) {
				int alunoid;
				cout << "Indique o id da identidae: ";
				cin >> alunoid;
				cout << "_____________________Identidade___________________" << endl;
				imprime3(filadeespera, alunoid);
				imprimemesa3(mesas, alunoid);
				cout << "__________________________________________________" << endl;


				}

				break;

				
			}
		}


	} while (running);

	system("PAUSE");
	return 0;
}