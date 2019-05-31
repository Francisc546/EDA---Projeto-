
#include <iostream>
#include <fstream>
#include <string>
#include "Cantina.h"

using namespace std;

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


void Insere(string * Nome, string filename, int tamanho) {
	int i = 0;
	ifstream file;
	file.open(filename);
	for (int i = 0; i < tamanho; i++) {
		getline(file, Nome[i]);
	}
	file.close();
}





void InsereFicheiros(string * nome, string filename) {

	int i = 0;
	ifstream file;
	file.open(filename);
	string aux;
	while (getline(file, aux)) {
		nome[i] = aux;
		i++;

	}
	file.close();
}
void escreveFicheiros(string *nome, int tamanho) {

	for (int i = 0; i < tamanho; i++) {
		cout << nome[i] << endl;
	}
}

void rec(refeicao * novaref, identidade* filadeespera, Mesa* mesas, int tdc) {
	fstream file;
	file.open("refeicao---------------------.txt", ios::out);
	file << novaref->entrada << endl << novaref->principal << endl << novaref->custo << endl;
	file.close();

	file.open("infoFilaEspera---------------.txt", ios::out);
	while (filadeespera != NULL) {
		file << filadeespera->tipo << endl << filadeespera->entidade << endl
			<< filadeespera->primeironome << endl << filadeespera->ultimonome << endl
			<< filadeespera->numeroid << endl << filadeespera->plafond << endl
			<< filadeespera->numerogrupo << endl << filadeespera->duracao << endl << filadeespera->n_elementos << endl;
		if (filadeespera->tipo) {
			file << filadeespera->curso << endl;
		}
		filadeespera = filadeespera->seguinte;

	}
	file.close();

	file.open("infoMesa---------------------.txt", ios::out);
	file << tdc << endl;

	while (mesas != NULL) {
		file << mesas->numMesa << endl << mesas->tamanho << endl << mesas->vagas << endl;
		while (mesas->pessoas != NULL) {
			file /*<< mesas->pessoas->tipo << endl*/ << mesas->pessoas->primeironome << endl << mesas->pessoas->ultimonome << endl
				<< mesas->pessoas->curso << endl << mesas->pessoas->duracao << endl << mesas->pessoas->entidade << endl
				<< mesas->pessoas->numerogrupo << endl << mesas->pessoas->numeroid << endl << mesas->pessoas->n_elementos << endl
				<< mesas->pessoas->plafond << endl;
			mesas->pessoas = mesas->pessoas->seguinte;
		}
		mesas = mesas->seguinte;
	}
	file.close();
}

void loading(refeicao* novaref, identidade* filadeespera) {
	fstream file;
	file.open("refeicao---------------------.txt");
	getline(file, novaref->entrada);
	getline(file, novaref->principal);
	file >> novaref->custo;
	file.close();
	filadeespera = NULL; //apagar todos manualmente
	int nElementos = contaLinhas("infoFilaEspera---------------.txt") / 9;
	file.open("infoFilaEspera---------------.txt");
	for (int c = 0; c < nElementos - 1; c++) {
		identidade* aux_f = new identidade;
		string tipo, entidade, primeironome, ultimonome, numeroid, plafond, numerogrupo, duracao, n_elementos, curso;
		getline(file, tipo);
		aux_f->tipo = tipo == "1";
		getline(file, entidade);
		aux_f->entidade = entidade;
		getline(file, primeironome);
		aux_f->primeironome = primeironome;
		getline(file, ultimonome);
		aux_f->ultimonome = ultimonome;
		getline(file, numeroid);
		aux_f->numeroid = stoi(numeroid);
		getline(file, plafond);
		aux_f->plafond = stoi(plafond);
		getline(file, numerogrupo);
		aux_f->numerogrupo = stoi(numerogrupo);
		getline(file, duracao);
		aux_f->duracao = stoi(duracao);
		getline(file, n_elementos);
		aux_f->n_elementos = stoi(n_elementos);
		if (aux_f->tipo == 1) {
			getline(file, curso);
			aux_f->curso = curso;
		}

		if (filadeespera == NULL) {
			filadeespera = aux_f;
			aux_f->seguinte = NULL;
		}
		else {
			aux_f->seguinte = filadeespera;
			filadeespera = aux_f;
		}
	}
	file.close();
}
void loading_m(Mesa* mesas) {
	fstream file;
	cout << "$$$$$$$$$$$$$$$$$$$$$ Mesas information $$$$$$$$$$$$$$$$$$$$$" << endl;
	file.open("infoMesa---------------------.txt");
	int tdc;
	int t = 0;

	file >> tdc;
	//cout << tdc << endl;
	while (t < tdc) {
		file >> mesas->numMesa;
		//cout << "Numero de mesa: " << mesas->numMesa << endl;
		file >> mesas->tamanho;
		//cout << "Tamanho da mesa: " << mesas->tamanho << endl;
		t += mesas->tamanho;
		file >> mesas->vagas;
		//cout << "Numero de vagas: " << mesas->vagas << endl;
		string tipo, entidade, primeironome, ultimonome, numeroid, plafond, numerogrupo, duracao, n_elementos, curso;
		getline(file, primeironome);

		for (int i = mesas->tamanho - mesas->vagas; i > 0; i--) {
			identidade* aux_m = new identidade;
			//string tipo, entidade, primeironome, ultimonome, numeroid, plafond, numerogrupo, duracao, n_elementos, curso;
			/*
			getline(file, tipo);
			aux_m->tipo = tipo == "1";
			cout << aux_m->tipo << endl;
			*/
			getline(file, primeironome);
			aux_m->primeironome = primeironome;
			//cout << aux_m->primeironome << endl;

			getline(file, ultimonome);
			aux_m->ultimonome = ultimonome;
			//cout << aux_m->ultimonome << endl;

			getline(file, curso);
			aux_m->curso = curso;
			//cout << "Curso: " << aux_m->curso << endl;

			getline(file, duracao);
			aux_m->duracao = stoi(duracao);
			//cout << aux_m->duracao << endl;

			getline(file, entidade);
			aux_m->entidade = entidade;
			//cout << aux_m->entidade << endl;

			getline(file, numerogrupo);
			aux_m->numerogrupo = stoi(numerogrupo);
			//cout << aux_m->numerogrupo << endl;

			getline(file, numeroid);
			aux_m->numeroid = stoi(numeroid);
			//cout << aux_m->numeroid << endl;

			getline(file, n_elementos);
			aux_m->n_elementos = stoi(n_elementos);
			//cout << aux_m->n_elementos << endl;

			getline(file, plafond);
			aux_m->plafond = stoi(plafond);
			//cout << aux_m->plafond << endl;

			if (mesas->pessoas == NULL) {
				mesas->pessoas = aux_m;
				aux_m->seguinte = NULL;
			}
			else {
				aux_m->seguinte = mesas->pessoas;
				mesas->pessoas = aux_m;
			}
			//cout << "/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/" << endl;
		}
		//cout << "*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$ next" << endl;
	}
	file.close();
}

