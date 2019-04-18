#include <iostream>
#include <fstream>
#include <string>
#include "Cantina.h"
using namespace std;

void InsereRefeição(refeiçao * novaref) {
	cout << "**************REFEICAO NOVA*****************" << endl;
	cout << "Necessario uma nova refeicao, por favor atualize os seguintes dados" << endl;
	cout << "Introduza a entrada: ";
	getline(cin, novaref->entrada);
	cout << "Introduza o prato principal: ";
	getline(cin, novaref->principal);
	cout << "Introduza o custo da refeicao: ";
	cin >> novaref->custo;
}


void ImprimeRefeição(refeiçao * novaref) {
	cout << "Refeicao Atual: " << endl;
	cout << "\t Entrada: " << novaref->entrada << endl;
	cout << "\t Prato Principal: " << novaref->principal << endl;
	cout << "\t Custo: " << novaref->custo << " euros " << endl;

}
