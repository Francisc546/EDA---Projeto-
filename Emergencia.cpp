#include <iostream>
#include "Emergencia.h"
using namespace std;

void removeAluSta() {
	int number;
	cout << "Qual o n�mero do aluno/staff: ";
	cin >> number;
}

void removeGruDepart() {
	int number;
	cout << "Qual o n�mero do aluno/staff: ";
	cin >> number;
}

void painelEmergencia() {
	int comando = 0;
	cout << "***** EMERGENCIA *****" << endl << "Situa��o de emerg�ncia" << endl << "3. Remover aluno/staff da cantina"
		<< endl << "4. Remover grupo/departamento da cantina" << endl;
	while (comando != 3 || comando != 4) {
		cout << "**** Comando: ";
		cin >> comando;
		switch (comando) {
			case (3)
				removeAluSta();
				break
			case (4)
				removeGruDepart();
				break
			default
				cout << "Comando errado! Tente outra vez" << endl;
				break
		}
	}
}
