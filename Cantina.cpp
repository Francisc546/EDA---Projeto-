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
int contaLinhas(string filename) {
	int nLinhas = 0;
	ifstream file(filename);
	string temp = "";
	while (getline(file, temp)) {
		nLinhas++;
	}
	file.close();
	return nLinhas;
}

void InserepNome(string * pNome, string filename) {
	int i = 0;
	ifstream file;
	file.open(filename);
	string aux;
	while (file >> aux) {
		pNome[i] = aux;
		i++;

	}
	file.close();

}
void InsereuNome(string * uNome, string filename) {
	int i = 0;
	ifstream file;
	file.open(filename);
	string aux;
	while (file >> aux) {
		uNome[i] = aux;
		i++;

	}
	file.close();

}
void InsereCurso(string * cursos, string filename) {
	int i = 0;
	ifstream file;
	file.open(filename);
	string aux;
	while (getline(file,aux)) {
		cursos[i] = aux;
		i++;

	}
	file.close();
}



void escrevepNome(string * pNome, int tamanho) {
	for (int i = 0; i < tamanho; i++) {
		cout << pNome[i] << endl;

	}
}

void escreveuNome(string * uNome, int tamanho) {
	for (int i = 0; i < tamanho; i++) {
		cout << uNome[i] << endl;
	}
}

void escrevecursos(string * cursos, int tamanho) {
	for (int i = 0; i < tamanho; i++) {
		cout << cursos[i] << endl;
	}
}

void criamesas(int tamanhocantina) {
	int i = 0;
	int n_mesa = 1;
	while (i < tamanhocantina) {
		if (tamanhocantina > 5) {
			int lugares = rand() % 4 + 2;
			Mesa* mesa = new Mesa;
			mesa->numMesa = n_mesa;
			mesa->tamanho = lugares;

			tamanhocantina = tamanhocantina - lugares;
			n_mesa = n_mesa + 1;
			cout << "Numero de mesa: " << mesa->numMesa << endl << "Lugares da mesa: " << mesa->tamanho << endl << endl;


		}
		else {
			Mesa* mesa = new Mesa;
			mesa->numMesa = n_mesa;
			mesa->tamanho = tamanhocantina;
			tamanhocantina = tamanhocantina - tamanhocantina;
			cout << "Numero de mesa: " << mesa->numMesa << endl << "Lugares da mesa: " << mesa->tamanho << endl << endl;

		}
	}
}

/*void criaidentidades(string * pNome, string * uNome, string * cursos) {
	int spawn = rand() % 100;
	int i = rand() % 43;
	int j = rand() % 96;
	int k = rand() % 18;
	int dinheiro = rand() % 100 + 1;
	if (spawn >= 75) {
		identidade::staff * staff = new identidade::staff();
		staff->primeironome = pNome[i];
		staff->ultimonome = uNome[j];
		staff->plafond = dinheiro;
		cout << "Nome do staff: " << staff->primeironome << " " << staff->ultimonome << " Plafond: " << staff->plafond << endl;
	}
	else
	{
		identidade::aluno * aluno = new identidade::aluno();
		aluno->primeironome = pNome[i];
		aluno->ultimonome = uNome[j];
		aluno->curso = cursos[k];
		aluno->plafond = dinheiro;
		cout << "Nome do aluno: " << aluno->primeironome << " " << aluno->ultimonome << " Curso: " << aluno->curso << " Plafond: " << aluno->plafond << endl;
	}
}*/

/*void criagrupo(string * pNome, string * uNome, string * cursos) {
		int r = 0;
		int spawn = rand() % 100;
		int numero = rand() % 20 + 1; // numero grupo
		int tamanho = rand() % 10 + 1; // tamanho do grupo
		int duraçaoref = rand() % 4 + 2;
		grupo * novogrupo = new grupo;
		novogrupo->numerogrupo = numero;
		identidade * grupo = new identidade[tamanho];
		while (r < tamanho) {
		if (spawn >= 75) {
			int i = rand() % 43;
			int j = rand() % 96;
			int k = rand() % 18;
			int dinheiro = rand() % 100 + 1;
			int id = rand() % 2087318 + 2000000; //numero aluno/funcionario
			grupo[r].primeironome = pNome[i];
			grupo[r].ultimonome = uNome[j];
			grupo[r].plafond = dinheiro;
			grupo[r].numeroid = id;
			grupo[r].numerogrupo = novogrupo->numerogrupo;
			grupo[r].duraçao = duraçaoref;
			cout << grupo[r].primeironome << " " << grupo[r].ultimonome << ", ID: " << grupo[r].numeroid << " , Departamento " << grupo[r].numerogrupo << " , Plafond: " << grupo[r].plafond << " euros" << endl;
			r++;

		}
		else {
			int i = rand() % 43;
			int j = rand() % 96;
			int k = rand() % 18;
			int dinheiro = rand() % 100 + 1;
			int id = rand() % 2087318 + 2000000; // numero aluno/funcionario;
			grupo[r].primeironome = pNome[i];
			grupo[r].ultimonome = uNome[j];
			grupo[r].plafond = dinheiro;
			grupo[r].curso = cursos[k];
			grupo[r].numeroid = id;
			grupo[r].numerogrupo = novogrupo->numerogrupo;
			grupo[r].duraçao = duraçaoref;
			cout << grupo[r].primeironome << " " << grupo[r].ultimonome << ",Curso: " << grupo[r].curso << " ,ID: " << grupo[r].numeroid << " ,Grupo " << grupo[r].numerogrupo << " ,Plafond: " << grupo[r].plafond << "euros" << endl;
			r++;
		}
		}
		novogrupo->grupopessoas = grupo;
		

}*/
/*identidade * criagrupo(string * pNome, string * uNome, string * cursos) {
	int tamanho = rand() % 10 + 1;
	int numgrupo = rand() % 20 + 1;
	int duraçaoref = rand() & 4 + 2;
	identidade * grupo = new identidade[tamanho];
	for (int r = 0; r < tamanho; r++) {
		int i = rand() % 43;
		int j = rand() % 96;
		int k = rand() % 18;
		int dinheiro = rand() % 100 + 1;
		int id = rand() % 2087318 + 2000000; // numero aluno/funcionario;
		grupo[r].primeironome = pNome[i];
		grupo[r].ultimonome = uNome[j];
		grupo[r].plafond = dinheiro;
		grupo[r].curso = cursos[k];
		grupo[r].numeroid = id;
		grupo[r].numerogrupo = numgrupo;
		grupo[r].duraçao = duraçaoref;
		cout << grupo[r].primeironome << " " << grupo[r].ultimonome << ", Curso: " << grupo[r].curso << " , ID: " << grupo[r].numeroid << " , Grupo " << grupo[r].numerogrupo << " , Plafond: " << grupo[r].plafond << " euros , Duraçao: " << grupo[r].duraçao << endl;

	}
	return grupo;
}*/

Mesa * criamesas2() {
	int i = 0;
	int n_mesa = 1;
	int tamanhodacantina = rand() % 51 + 30;
	Mesa * temp = new Mesa[50];
	while (i < tamanhodacantina) {
		Mesa  novamesa;
		novamesa.tamanho = rand() % 4 + 2;
		novamesa.numMesa = n_mesa;
		novamesa.pessoas = new identidade[novamesa.tamanho];
		temp[n_mesa - 1] = novamesa;
		i = i + novamesa.tamanho;
		n_mesa++;
	}
	Mesa * cantina = new Mesa[n_mesa];
	for (int k = 0; k < n_mesa; k++) {
		cantina[k] = temp[k];
	}
	delete[] temp;
	return cantina;

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
	for (int r = 0; r < elementos; r++) {
		int i = rand() % 43;
		int j = rand() % 96;
		int k = rand() % 18;
		int duracaoref = rand() % 4 + 2;
		novogrupo[r].primeironome = pNome[i];
		novogrupo[r].ultimonome = uNome[j];
		novogrupo[r].tipo = d;
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
	int numerogrup = rand() % 50 + 1; 
	
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

			cout << " -> " << "ALUNO" << ", " << filadeespera[i].primeironome << " " << filadeespera[i].ultimonome << ", " << filadeespera[i].curso << ", " << filadeespera[i].numeroid << ", " << filadeespera[i].numerogrupo << ", " << filadeespera[i].plafond << " euros, (Duracao: " << filadeespera[i].duracao << ")" <<  endl;
		}
		else {
			cout << " -> " << "STAFF" << ", " << filadeespera[i].primeironome << " " << filadeespera[i].ultimonome << ", " << filadeespera[i].curso << ", " << filadeespera[i].numeroid << ", " << filadeespera[i].numerogrupo << ", " << filadeespera[i].plafond << " euros, (Duracao: " << filadeespera[i].duracao << ")" << endl;
		}
		//cout << " -> " << filadeespera[i].tipo << " " << filadeespera[i].primeironome << endl;// << " " << filadeespera[i].ultimonome << ", " << filadeespera[i].curso << ", " << filadeespera[i].numeroid << ", " << filadeespera[i].numerogrupo << ", " << filadeespera[i].plafond << endl;

		cout << endl;
		
	}
}