#include <iostream>
#include <string>
#include <fstream>
#include "Cantina.h"

using namespace std;


void main() {
	
	int tamanhopNome = contaLinhas("primeiro_nome.txt");
	string * pNome = new string[tamanhopNome];
	InsereVetor(pNome, "primeiro_nome.txt");
	int tamanhouNome = contaLinhas("ultimo_nome.txt");
	string * uNome = new string[tamanhouNome];
	InsereVetor(pNome, "ultimo_nome.txt");
	int tamanhocursos = contaLinhas("cursos.txt");
	string * cursos = new string[tamanhocursos];
	InsereVetor(pNome, "cursos.txt");
	/*refei�ao * novaref = new refei�ao;
	cout << "-------------------------CANTINA EDA ------------------------------" << endl;
	InsereRefei��o(novaref);
	ImprimeRefei��o(novaref);*/

	


	
	system("Pause");

}