#include <iostream>
#include <string>
#include <fstream>
#include "Cantina.h"

using namespace std;


void main() {
	refei�ao * novaref = new refei�ao;
	cout << "-------------------------CANTINA EDA ------------------------------" << endl;
	InsereRefei��o(novaref);
	ImprimeRefei��o(novaref);


	cin.sync();
	cin.get();
	system("Pause");

}