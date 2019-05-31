#include <iostream>
#include <fstream>
#include <string>
#include "Cantina.h"
#include "Ficheiros.h"
#include "Fila.h"
#include "Emergencia.h"

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

identidade * adiciona_especial(identidade*filadeespera, identidade*novo) {
	identidade * aux = novo;
	novo->seguinte = filadeespera;
	filadeespera = novo;
	return filadeespera;
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
			novamesa->pessoas = NULL;
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
			novamesa->pessoas = NULL;
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
		cout << "MESA N: " << aux->numMesa << "   TAMANHO:  " << aux->tamanho << endl;
		identidade * aux2 = aux->pessoas;
		while (aux2 != NULL) {
			if (aux2->tipo == 0)
				cout << aux2->entidade << aux2->primeironome << " , Departamento " << aux2->numerogrupo << " | " << aux2->numeroid << " | (ciclos restantes: " << aux2->duracao << ") Plafond : " << aux2->plafond << endl;
			else
				cout << aux2->entidade << aux2->primeironome << " , grupo " << aux2->numerogrupo << " | " << aux2->numeroid << " | " << aux2->curso << " | (ciclos restantes: " << aux2->duracao << ") Plafond : " << aux2->plafond << endl;
			aux2 = aux2->seguinte;

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



identidade * criagrupo(identidade*filadeespera, string * pNome, string * uNome, string * cursos, int aleatorio) {
	for (int i = 0; i < aleatorio; i++) {
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
			grupo->n_elementos = elementos;
			if (tipo) {
				int id = rand() % 2087318 + 2000000;
				int dinheiro = rand() % 100 + 1;
				grupo->numerogrupo = numerogrupo;
				grupo->numeroid = id;
				grupo->plafond = dinheiro;
				grupo->duracao = duracao_ref;
				grupo->curso = cursos[k];
				grupo->entidade = "Aluno ";

			}
			else {
				int id = rand() % 2087318 + 2000000;
				int dinheiro = rand() % 100 + 1;
				grupo->numerogrupo = numerogrupo;
				grupo->numeroid = id;
				grupo->plafond = dinheiro;
				grupo->duracao = duracao_ref;
				grupo->entidade = "Staff ";

			}
			filadeespera = adiciona_filadeespera(filadeespera, grupo);
		}
	}



	return filadeespera;
}


identidade * criaespecial(identidade*filadeespera, string * pNome, string * uNome, string * cursos) {
	identidade * especial = new identidade;
	int numerogrupo = rand() % 400 + 100;
	int duracao_ref = rand() % 4 + 2;
	int k = rand() % 18; // seleciona um curso ( o ficheiro possui 19 cursos , mas como o array começa na posição 0 logo tem de ser ate 18)
	int i = rand() % 43; // seleciona um primeiro nome do array
	int j = rand() % 96; // seleciona um ultimo nome do array
	especial->primeironome = pNome[i];
	especial->ultimonome = uNome[j];
	especial->duracao = duracao_ref;
	especial->entidade = "Especial ";
	especial->n_elementos = 1;
	int id = rand() % 2087318 + 2000000;
	int dinheiro = rand() % 100 + 1;
	especial->numerogrupo = numerogrupo;
	especial->numeroid = id;
	especial->plafond = dinheiro;
	especial->duracao = duracao_ref;
	especial->curso = cursos[k];


	filadeespera = adiciona_especial(filadeespera, especial);
	return filadeespera;


}

void escreveFiladeEspera(identidade * filadeespera) {
	identidade * aux = filadeespera;

	while (aux != NULL) {
		if (aux->tipo == 0)
			cout << " -> " << aux->entidade << ", " << aux->primeironome << " " << aux->ultimonome << ", " << aux->numeroid << ", Departamento: " << aux->numerogrupo << ", " << aux->plafond << " euros, (Duracao: " << aux->duracao << ")" << endl;
		else
			cout << " -> " << aux->entidade << ", " << aux->primeironome << " " << aux->ultimonome << ", " << aux->curso << ", " << aux->numeroid << ", Grupo: " << aux->numerogrupo << ", " << aux->plafond << " euros, (Duracao: " << aux->duracao << ")" << endl;
		aux = aux->seguinte;
	}

	cout << endl;
}

bool verificagrupo(identidade * filadeespera, int custo) { // funçao que verifica o plafond um a um dos elementos do grupo


	int num_grupo = filadeespera->numerogrupo;
	identidade * aux = filadeespera;
	while (aux->numerogrupo == num_grupo) {
		if (aux->plafond < custo) {
			cout << aux->plafond << endl;
			return false;
			break;
		}

		aux = aux->seguinte;

	}
	return true;

}
identidade * adiciona_cantina(Mesa*mesas, identidade* pessoas) {
	identidade * ocupantes = pessoas;
	identidade * aux = pessoas;
	while (aux->seguinte != NULL && mesas->vagas > 1) {
		aux = aux->seguinte;
		mesas->vagas--;
	}
	mesas->vagas--;
	identidade * temp = aux->seguinte;
	aux->seguinte = mesas->pessoas;
	mesas->pessoas = ocupantes;
	return temp;
}


identidade * insereMesas(identidade * filadeespera, Mesa * mesas) {
	identidade * aux = filadeespera;
	int num_grupo = aux->numerogrupo;
	identidade * filanova = NULL;
	while (aux->seguinte->numerogrupo == num_grupo) {
		aux = aux->seguinte;
	}
	filanova = filadeespera;
	filadeespera = aux->seguinte;
	aux->seguinte = NULL;
	Mesa * aux2 = mesas;
	while (aux2->seguinte != NULL && filanova != NULL) {

		if (aux2->vagas == aux2->tamanho || aux2->pessoas == NULL) {//se a mesa não tem ngm
			filanova = adiciona_cantina(aux2, filanova);

		}
		else {//se a mesa tem pessoas
			if ((aux2->pessoas->curso == filanova->curso || filanova->tipo == 0 || aux2->pessoas->tipo == 0) && aux2->vagas != 0) {//condições do enunciado
				filanova = adiciona_cantina(aux2, filanova);
			}
		}
		aux2 = aux2->seguinte;




	}

	return filadeespera;
}

Mesa * reduzduracao2(Mesa *mesas, int custo) {
	Mesa * aux = mesas;
	while (aux != NULL) {
		identidade * iterator = aux->pessoas;
		while (iterator != NULL) {
			if (iterator->duracao == 0) {
				removeElemento(mesas, iterator->numeroid, custo);
				//iterator = iterator->seguinte;
			}
			else {
				iterator->duracao--;
				iterator = iterator->seguinte;
			}
		}
		aux = aux->seguinte;
	}
	return mesas;
}

Mesa * reduzduracao(Mesa *mesas, int custo) {
	Mesa * aux = mesas;
	while (aux != NULL) {
		identidade * iterator = aux->pessoas;
		while (iterator != NULL) {
			/*if (iterator->duracao == 0) {
				removeElemento(mesas, iterator->numeroid, custo);
				
			}*/
			iterator->duracao--;
			iterator = iterator->seguinte;
			
		}
		aux = aux->seguinte;
	}
	return mesas;
}

Mesa * removeElementos(Mesa * mesas) {
	bool pessoas_a_sair = true;
	while (pessoas_a_sair) {
		Mesa * aux = mesas;
		bool sair=false;
		pessoas_a_sair = false;
		while (aux != NULL && !sair) {
			identidade * iterator = aux->pessoas;
			while (iterator != NULL && !sair) {
				if (iterator->duracao == 0) {
					aux = removeElemento(mesas, iterator->numeroid, 0);
					pessoas_a_sair = true;
					sair = true;
				}
				iterator = iterator->seguinte;
			}
			aux = aux->seguinte;
		}
	}
	return mesas;
}





