#include <iostream>
#include <string>
#include <fstream>

using namespace std;


struct refeiçao {

	string entrada;
	string principal;
	float custo;
};
struct pessoa {
	string primeironome;
	string ultimonome;
	int numero;
	int numerogrupo;
	string curso;
	float plafond;

};

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

void main() {
	refeiçao * novaref = new refeiçao;


	cout << "-------------------------CANTINA EDA ------------------------------" << endl;
	InsereRefeição(novaref);
	ImprimeRefeição(novaref);


	cin.sync();
	cin.get();
	system("Pause");

}