#include <iostream>
#include <string>
#include <fstream>
#include "Cantina.h"

using namespace std;


int main() {
	refeiçao * novaref = new refeiçao;
	cout << "-------------------------CANTINA EDA ------------------------------" << endl;
	InsereRefeição(novaref);
	ImprimeRefeição(novaref);


	cin.sync();
	cin.get();
	system("Pause");
	return 0;
}