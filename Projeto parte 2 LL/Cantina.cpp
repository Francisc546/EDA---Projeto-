#include <iostream>
#include <fstream>
#include <string>
#include "Cantina.h"
#include "Ficheiros.h"

using namespace std;


void InsereRefeicao(refeicao * novaref) {
	cout << "**************REFEICAO NOVA*****************" << endl;
	cout << "Necessario uma nova refeicao, por favor atualize os seguintes dados" << endl;
	cout << "Introduza a entrada: " << endl;
	cin.sync();
	cin.seekg(0);
	getline(cin, novaref->entrada); // uso do getline para obter a linha toda e não apenas a primeira palavra
	cout << "Introduza o prato principal: " << endl;
	getline(cin, novaref->principal);
	cout << "Introduza o custo da refeicao: " << endl;
	cin >> novaref->custo;
}


void ImprimeRefeicao(refeicao * novaref) {
	cout << "Refeicao Atual: " << endl;
	cout << "\t Entrada: " << novaref->entrada << endl;
	cout << "\t Prato Principal: " << novaref->principal << endl;
	cout << "\t Custo: " << novaref->custo << " euros " << endl;

}


identidade * adiciona_filadeespera(identidade*filadeespera, identidade*novo) {
	if (filadeespera == NULL) {
		filadeespera = novo;
		filadeespera->seguinte = NULL;
	}
	else {
		identidade * aux = filadeespera;
		while (aux->seguinte != NULL) {
			aux = aux->seguinte;

		}
		aux->seguinte = novo;
		novo->seguinte = NULL;
	}
	return filadeespera;
}
 
Mesa * adiciona_mesas(Mesa*mesas, Mesa*novo) {
	if (mesas == NULL) {
		mesas = novo;
		mesas->seguinte = NULL;
	}
	else {
		Mesa * aux = mesas;
		while (aux->seguinte != NULL) {
			aux = aux->seguinte;
		}
		aux->seguinte = novo;
		novo->seguinte = NULL;
	}
	return mesas;
}
Mesa * criamesas(Mesa*mesas, int tamanhodacantina) {
	int tamanho = tamanhodacantina;
	int n_mesa = 1;
	int i = 0;
	while (i < tamanhodacantina) {
		if (tamanhodacantina > 5) {
			Mesa* novamesa = new Mesa;
			int lugares = rand() % 4 + 2;
			novamesa->tamanho = lugares;
			novamesa->vagas = novamesa->tamanho;
			novamesa->numMesa = n_mesa;
			novamesa->pessoas = new identidade[novamesa->tamanho];
			i = i + lugares;
			n_mesa++;
			mesas = adiciona_mesas(mesas, novamesa);
		}
		else {
			Mesa* novamesa = new Mesa;
			int lugares = tamanhodacantina;
			novamesa->tamanho = lugares;
			novamesa->vagas = novamesa->tamanho;
			novamesa->numMesa = n_mesa;
			novamesa->pessoas = new identidade[novamesa->tamanho];
			i = i + lugares;
			n_mesa++;
			mesas = adiciona_mesas(mesas, novamesa);
		}
		
	}
	return mesas;

}

void imprimeCantina(Mesa * mesas) {
	Mesa*aux = mesas;
	while (aux != NULL) {
		cout << "MESA N " << aux->numMesa << "   TAMANHO  " << aux->tamanho << endl;
		for (int z = 0; z < aux->tamanho; z++) {

			if (aux->pessoas[z].tipo == 1) {// se for aluno
				cout << aux->pessoas[z].primeironome << " , aluno , grupo " << aux->pessoas[z].numerogrupo << " | " << aux->pessoas[z].numeroid << " | " << aux->pessoas[z].curso << " | (ciclos restantes: " << aux->pessoas[z].duracao << ") Plafond : " << aux->pessoas[z].plafond << endl;

			}
			else { // se for staff

				cout << aux->pessoas[z].primeironome << " , staff , departamento " << aux->pessoas[z].numerogrupo << " | " << aux->pessoas[z].numeroid << " | (ciclos restantes: " << aux->pessoas[z].duracao << ") Plafond : " << aux->pessoas[z].plafond << endl;
			}
		}
		aux = aux->seguinte;
		
	}

}




bool decide(bool tipo) { // funcao que decide qual vai ser o tipo do grupo criado, se for gerado um numero abaixo de 75 é aluno , caso contrario é staff
	int spawn = rand() % 100 + 1;
	if (spawn <= 75) {
		return true;
	}
	else {
		return false;
	}

}



identidade * criagrupo(identidade*filadeespera, string * pNome, string * uNome, string * cursos) {
	int aletorio = rand() % 2+2;
	for (int i = 0; i < aletorio; i++) {
		bool tipo = true;
		tipo = decide(tipo);
		int elementos = rand() % 10 + 1;
		int numerogrupo = rand() % 400 + 100;
		int duracao_ref = rand() % 4 + 2;
		int k = rand() % 18; // seleciona um curso ( o ficheiro possui 19 cursos , mas como o array começa na posição 0 logo tem de ser ate 18)
		for (int r = 0; r < elementos; r++) {
			identidade * grupo = new identidade;
			int i = rand() % 43; // seleciona um primeiro nome do array
			int j = rand() % 96; // seleciona um ultimo nome do array
			grupo->primeironome = pNome[i];
			grupo->ultimonome = uNome[j];
			grupo->duracao = duracao_ref;
			grupo->tipo = tipo;
			if (tipo) {
				int id = rand() % 2087318 + 2000000;
				int dinheiro = rand() % 100 + 1;
				grupo->numerogrupo = numerogrupo;
				grupo->numeroid = id;
				grupo->plafond = dinheiro;
				grupo->duracao = duracao_ref;
				grupo->curso = cursos[k];

			}
			else {
				int id = rand() % 2087318 + 2000000;
				int dinheiro = rand() % 100 + 1;
				grupo->numerogrupo = numerogrupo;
				grupo->numeroid = id;
				grupo->plafond = dinheiro;
				grupo->duracao = duracao_ref;

			}
			filadeespera = adiciona_filadeespera(filadeespera, grupo);
		}
	}
	


	return filadeespera;
}


identidade * criaespecial (identidade*filadeespera, string * pNome, string * uNome, string * cursos){
	identidade * especial = new identidade;
	bool tipo = true;
	tipo = decide(tipo);
	int numerogrupo = rand() % 400 + 100;
	int duracao_ref = rand() % 4 + 2;
	int k = rand() % 18; // seleciona um curso ( o ficheiro possui 19 cursos , mas como o array começa na posição 0 logo tem de ser ate 18)
	int i = rand() % 43; // seleciona um primeiro nome do array
	int j = rand() % 96; // seleciona um ultimo nome do array
	especial->primeironome = pNome[i];
	especial->ultimonome = uNome[j];
	especial->duracao = duracao_ref;
	especial->tipo = tipo;
	especial->n_elementos = 1;
	if (tipo) {
		int id = rand() % 2087318 + 2000000;
		int dinheiro = rand() % 100 + 1;
		especial->numerogrupo = numerogrupo;
		especial->numeroid = id;
		especial->plafond = dinheiro;
		especial->duracao = duracao_ref;
		especial->curso = cursos[k];

	}
	else {
		int id = rand() % 2087318 + 2000000;
		int dinheiro = rand() % 100 + 1;
		especial->numerogrupo = numerogrupo;
		especial->numeroid = id;
		especial->plafond = dinheiro;
		especial->duracao = duracao_ref;

	}
	filadeespera = especial;
	return filadeespera;


}

void escreveFiladeEspera(identidade * filadeespera) {
	identidade * aux = filadeespera;

	while (aux != NULL) {
		if (aux->tipo == 1) {

			cout << " -> " << "ALUNO" << ", " << aux->primeironome << " " << aux->ultimonome << ", " << aux->curso << ", " << aux->numeroid << ", Grupo: " << aux->numerogrupo << ", " << aux->plafond << " euros, (Duracao: " << aux->duracao << ")" << endl;
		}
		else {
			cout << " -> " << "STAFF" << ", " << aux->primeironome << " " << aux->ultimonome << ", " << aux->curso << ", " << aux->numeroid << ", Departamento: " << aux->numerogrupo << ", " << aux->plafond << " euros, (Duracao: " << aux->duracao << ")" << endl;
		}

		aux = aux->seguinte;	
	}
	cout << endl;
}


bool verificagrupo(identidade * filadeespera, int custo) { // funçao que verifica o plafond um a um dos elementos do grupo


	int num_grupo = filadeespera->numerogrupo;
	identidade * aux = filadeespera;
	while(aux->seguinte->numerogrupo != num_grupo){
		if (aux->plafond < custo) {
			return false;
			break;
		}
		
		aux = aux->seguinte;
		
	}
	return true;

}

/*identidade * removerInicio(identidade * filadeespera) {
	identidade * aux = filadeespera;
	filadeespera = filadeespera->seguinte;
	delete aux;
	return filadeespera;
}

void removerFim(identidade * filadeespera) {
	identidade * iterator = filadeespera;

	while (iterator->seguinte->seguinte != NULL) {
		iterator = iterator->seguinte;
	}

	identidade * aux = iterator->seguinte;
	iterator->seguinte = NULL;
	delete aux;
}*/
void removeElemento(identidade * filadeespera, int custo) {
	int num_grupo = filadeespera->numerogrupo;
	identidade * iterator = filadeespera;
	while (iterator->seguinte->numerogrupo != num_grupo) {
		if (iterator->plafond < custo) {
			identidade * aux = iterator->seguinte;
			iterator->seguinte = iterator->seguinte->seguinte;
			delete aux;
		}
	}

}