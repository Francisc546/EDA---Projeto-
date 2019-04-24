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

Mesa * criamesas2(int &numeromesas, Mesa*temp, int tamanhodacantina) {
	int i = 0;
	int n_mesa = 1;
	int tamanho =  tamanhodacantina;
	cout << tamanhodacantina << endl;
	while (i < tamanhodacantina) {
		if (tamanhodacantina > 5) {
			Mesa  novamesa;
			int lugares = rand() % 4 + 2;
			novamesa.tamanho = lugares;
			novamesa.numMesa = n_mesa;
			novamesa.pessoas = new identidade[novamesa.tamanho];
			temp[n_mesa - 1] = novamesa;
			i = i + novamesa.tamanho;
			n_mesa++;
			numeromesas++;
			

			
		}
		else {
			Mesa  novamesa;
			int lugares = tamanhodacantina;
			novamesa.tamanho = lugares;
			novamesa.numMesa = n_mesa;
			novamesa.pessoas = new identidade[novamesa.tamanho];
			temp[n_mesa - 1] = novamesa;
			i = i + novamesa.tamanho;
			n_mesa++;
			numeromesas++;
			
		}
	}
	cout << "Numero de mesas: "<< numeromesas << endl;
	cout << "Tamanho: " << tamanhodacantina<<endl;

	return temp;

}




bool decide(bool tipo) {
	int spawn = rand() % 100 + 1;
	if (spawn <= 75) {
		return true;
	}
	else {
		return false;
	}

}

identidade * criagrupo(string * pNome, string * uNome, string * cursos, int elementos, bool d, int numerogrupo) {
	identidade * novogrupo = new identidade[elementos];
	int duracaoref = rand() % 4 + 2;

	for (int r = 0; r < elementos; r++) {
		int i = rand() % 43;
		int j = rand() % 96;
		int k = rand() % 18;
		novogrupo[r].primeironome = pNome[i];
		novogrupo[r].ultimonome = uNome[j];
		novogrupo[r].tipo = d;
		novogrupo[r].n_elementos = elementos;
		//cout << "-- "<<novogrupo[r].primeironome << endl;
		if (d) {
			int id = rand() % 2087318 + 2000000;
			int dinheiro = rand() % 100 + 1;
			novogrupo[r].numerogrupo = numerogrupo;
			novogrupo[r].curso = cursos[k];
			novogrupo[r].numeroid = id;
			novogrupo[r].plafond = dinheiro;
			novogrupo[r].duracao = duracaoref;

		}
		else {
			int id = rand() % 2087318 + 2000000;
			int dinheiro = rand() % 100 + 1;
			novogrupo[r].numerogrupo = numerogrupo;
			novogrupo[r].numeroid = id;
			novogrupo[r].plafond = dinheiro;
			novogrupo[r].duracao = duracaoref;

		}

	}

	return novogrupo;
}

int adicionafila(identidade * filadeespera, int posicaovazia, string * pNome, string * uNome, string * cursos) {
	bool tipo = true;
	tipo = decide(tipo);
	int elementos = rand() % 10 + 1;
	//criagrupo(pNome, uNome, cursos, elementos,tipo);
	int numerogrup = rand() % 400 + 100;

	if (posicaovazia > 50 - 10)
		elementos = 50 - posicaovazia;


	identidade * novogrupo = criagrupo(pNome, uNome, cursos, elementos, tipo, numerogrup);

	for (int i = 0; i < elementos && (posicaovazia + i < 50); i++) {
		filadeespera[posicaovazia] = novogrupo[i];
		posicaovazia++;

	}



	return posicaovazia - 1;

}

void imprimeFila(identidade * filadeespera, int tamanho) {
	for (int i = 0; i < tamanho; i++) {
		//string tipo = filadeespera[i].tipo ? " ALUNO " : " STAFF";
		//identidade pessoa = filadeespera[i];
		if (filadeespera[i].tipo == 1) {

			cout << " -> " << "ALUNO" << ", " << filadeespera[i].primeironome << " " << filadeespera[i].ultimonome << ", " << filadeespera[i].curso << ", " << filadeespera[i].numeroid << ", Grupo: " << filadeespera[i].numerogrupo << ", " << filadeespera[i].plafond << " euros, (Duracao: " << filadeespera[i].duracao << ")" << endl;
		}
		else {
			cout << " -> " << "STAFF" << ", " << filadeespera[i].primeironome << " " << filadeespera[i].ultimonome << ", " << filadeespera[i].curso << ", " << filadeespera[i].numeroid << ", Departamento: " << filadeespera[i].numerogrupo << ", " << filadeespera[i].plafond << " euros, (Duracao: " << filadeespera[i].duracao << ")" << endl;
		}
		//cout << " -> " << filadeespera[i].tipo << " " << filadeespera[i].primeironome << endl;// << " " << filadeespera[i].ultimonome << ", " << filadeespera[i].curso << ", " << filadeespera[i].numeroid << ", " << filadeespera[i].numerogrupo << ", " << filadeespera[i].plafond << endl;

		cout << endl;

	}
}

void imprimeMesa(Mesa*cantina, int numeromesas) {
	for (int i = 0; i < numeromesas; i++) {
		cout << cantina[i].numMesa<<endl;
	}

}

void adicionamesa(Mesa * cantina, identidade * filadeespera, int numerodemesas, int tamanho) {
	int i = 0;
	int j = 0;
	int num_elmentos = filadeespera[0].n_elementos;
	int count_elementos = 0;
	while (i < numerodemesas) {
		int k = 0;
		//while( j < tamanho) {
		cout << "MESA N " << cantina[i].numMesa << "   TAMANHO  " << cantina[i].tamanho << endl;
			for (int z = 0; z < cantina[i].tamanho && j <tamanho && count_elementos<num_elmentos; z++){
		
				cantina[i].pessoas[z] = filadeespera[j];
				cout << cantina[i].pessoas[z].primeironome<<" | "<< cantina[i].pessoas[z].numerogrupo<< endl;
				k++;
				j++;
				count_elementos++;
			}
			i++;
		}
		
		
	//}
}

	