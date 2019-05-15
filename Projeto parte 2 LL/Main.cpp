#include <iostream>
#include "Cantina.h"
#include "Ficheiros.h"
#include <string>
#include <fstream>
#include <locale>
using namespace std;



int main() {
	bool running = true;
	srand(time(NULL));
	int tamanhopNome = contaLinhas("primeiro_nome.txt");
	int tamanhouNome = contaLinhas("ultimo_nome.txt");
	int tamanhocursos = contaLinhas("cursos.txt");
	string * pNome = new string[tamanhopNome];
	string * uNome = new string[tamanhouNome];
	string * cursos = new string[tamanhocursos];
	InserepNome(pNome, "primeiro_nome.txt"); // insere os primeiros nomes no array pNome
	InsereuNome(uNome, "ultimo_nome.txt"); // insere os ultimos nomes no array uNome
	InsereCurso(cursos, "cursos.txt"); // insere os cursos no array cursos

	identidade * filadeespera = NULL;
	filadeespera = criagrupo(filadeespera, pNome, uNome, cursos);
	

	Mesa*mesas = NULL;
	int tamanhodacantina = rand() % 20 + 30;
	mesas = criamesas(mesas, tamanhodacantina);
	
	



	do {
		int ciclos = 10;
		refeicao * novaref = new refeicao;
		InsereRefeição(novaref);
		system("cls");
		cout << "-------------------------CANTINA EDA ------------------------------" << endl;
		ImprimeRefeição(novaref);
		escreveFiladeEspera(filadeespera);
		imprimeCantina(mesas);

		while (ciclos != 0) {

			cout << "(s) seguinte (e) Emergência (g) Gravar (c) Carregar dados (o) Opçoes ";
			char opcao;
			cin >> opcao;
			switch (opcao) {
			case 's':
				int special = rand() % 100;
				if (special >= 95) {
					filadeespera = criaespecial(filadeespera, pNome, uNome, cursos);


				}
				else {
					filadeespera = criagrupo(filadeespera, pNome, uNome, cursos);
				}
				escreveFiladeEspera(filadeespera);
				imprimeCantina(mesas);
				ciclos--;
				break;
			/*case 'e':
				break;
			case 'g':
				break;
			case 'c':
				break;
			case 'o':
				break;*/

			}
		}
	} while (running);


	system("PAUSE");
	return 0;
		
	
}