#include <iostream>
#include <string>
#include <fstream>

using namespace std;


struct refei�ao {

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

void InsereRefei��o(refei�ao * novaref) {
	cout << "**************REFEICAO NOVA*****************" << endl;
	cout << "Necessario uma nova refeicao, por favor atualize os seguintes dados" << endl;
	cout << "Introduza a entrada: ";
	getline(cin, novaref->entrada);
	cout << "Introduza o prato principal: ";
	getline(cin, novaref->principal);
	cout << "Introduza o custo da refeicao: ";
	cin >> novaref->custo;
	
}

void ImprimeRefei��o(refei�ao * novaref) {
	cout << "Refeicao Atual: " << endl;
	cout << "\t Entrada: " << novaref->entrada << endl;
	cout << "\t Prato Principal: " << novaref->principal << endl;
	cout << "\t Custo: " << novaref->custo << " euros " << endl;

}

void main() {
	refei�ao * novaref = new refei�ao;


	cout << "-------------------------CANTINA EDA ------------------------------" << endl;
	InsereRefei��o(novaref);
	ImprimeRefei��o(novaref);


	cin.sync();
	cin.get();
	system("Pause");

}