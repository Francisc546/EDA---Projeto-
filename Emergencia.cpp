#include <iostream>
#include "Emergencia.h"
using namespace std;

void removeAluSta() {
	int number;
	cout << "Qual o número do aluno/staff: ";
	cin >> number;
}

void removeGruDepart() {
	int number;
	cout << "Qual o número do aluno/staff: ";
	cin >> number;
}

void painelEmergencia() {
	int comando;
	cout << "***** EMERGENCIA *****" << endl << "Situação de emergência" << endl << "3. Remover aluno/staff da cantina"
		<< endl << "4. Remover grupo/departamento da cantina" << endl;
	while (comando != 3 || comando != 4) {
		cout << "**** Comando: ";
		cin >> comando;
		if (comando == 3) {
			removeAluSta();
		}
		else if (comando == 4) {
			removeGruDepart();
		}
		else {
			cout << "Comando errado! Tente outra vez" << endl;
		}
	}
}
