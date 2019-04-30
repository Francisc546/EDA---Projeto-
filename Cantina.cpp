#include <iostream>
#include <fstream>
#include <string>
#include "Cantina.h"
#include "Fila.h"
#include <vector>
#include <algorithm>
using namespace std;

void InsereRefeição(refeiçao * novaref) {
	cout << "**************REFEICAO NOVA*****************" << endl;
	cout << "Necessario uma nova refeicao, por favor atualize os seguintes dados" << endl;
	cout << "Introduza a entrada: " << endl;
	cin.sync();
	cin.seekg(0);
	getline(cin, novaref->entrada);
	cout << "Introduza o prato principal: " << endl;
	getline(cin, novaref->principal);
	cout << "Introduza o custo da refeicao: " << endl;
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
	//cout << tamanhodacantina << endl;
	while (i < tamanhodacantina) {
		if (tamanhodacantina > 5) {
			Mesa  novamesa;
			int lugares = rand() % 4 + 2;
			novamesa.tamanho = lugares;
			novamesa.vagas = novamesa.tamanho;
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
			novamesa.vagas = novamesa.tamanho;
			novamesa.pessoas = new identidade[novamesa.tamanho];
			temp[n_mesa - 1] = novamesa;
			i = i + novamesa.tamanho;
			n_mesa++;
			numeromesas++;
			
		}
	}
	//cout << "Numero de mesas: "<< numeromesas << endl;
	//cout << "Tamanho: " << tamanhodacantina<<endl;

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
	//int special = rand() % 100;
	identidade * novogrupo = new identidade[elementos];
	//if (special < 95) {
		int duracaoref = rand() % 4 + 2;
		int k = rand() % 18;
		for (int r = 0; r < elementos; r++) {
			int i = rand() % 43;
			int j = rand() % 96;
			novogrupo[r].special = 0;
			novogrupo[r].primeironome = pNome[i];
			novogrupo[r].ultimonome = uNome[j];
			novogrupo[r].tipo = d;
			novogrupo[r].n_elementos = elementos;
			//cout << "-- "<<novogrupo[r].primeironome << endl;
			if (d) {
				int id = rand() % 2087318 + 2000000;
				int dinheiro = rand() % 100 + 1;
				novogrupo[r].numerogrupo = numerogrupo;
				novogrupo[r].numeroid = id;
				novogrupo[r].plafond = dinheiro;
				novogrupo[r].duracao = duracaoref;
				novogrupo[r].curso = cursos[k];

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
	
	/*else {
		novogrupo = new identidade;
		int duracaoref = rand() % 4 + 2;
		int k = rand() % 18;
		int i = rand() % 43;
		int j = rand() % 96;
		int id = rand() % 2087318 + 2000000;
		int dinheiro = rand() % 100 + 1;
		novogrupo->special = 1;
		novogrupo->primeironome = pNome[i];
		novogrupo->ultimonome = uNome[j];
		novogrupo->n_elementos = 1;
		novogrupo->numerogrupo = numerogrupo;
		novogrupo->numeroid = id;
		novogrupo->plafond = dinheiro;
		novogrupo->duracao = duracaoref;
		novogrupo->curso = cursos[k];
		
	}*/
	
	return novogrupo;
}



void imprimeMesa(Mesa*cantina, int numeromesas) {
	int i = 0;
	while (i < numeromesas) {
		cout << "MESA N " << cantina[i].numMesa << "   TAMANHO  " << cantina[i].tamanho << endl;
		i++;
	}

}

void adicionaGrupos(Mesa * cantina, identidade * filadeespera, int numeromesas, int tamanho) {
	int enter;
	
	for (int i = 0; i < numeromesas; i++) {
			int count_elementos = adicionagrupo(cantina, filadeespera, numeromesas, 50, 10);
			apagaFilaEspera(filadeespera, count_elementos);
			imprimeFila(filadeespera, 50);
			imprimeCantina(cantina, numeromesas);

			cout << "Presione Enter";
			cin >> enter;
		}

		
	}
		
bool verificagrupo(identidade * filadeespera, int custo) {
	
	
	int num_elmentos = filadeespera[0].n_elementos;
	
	for (int j = 0; j < num_elmentos; j++) {
		//cout << "Verificando grupo " << filadeespera[0].numerogrupo<<endl;
		if (filadeespera[j].plafond < custo) {
			return false;
		}

	}
	return true;
}


int adicionagrupo(Mesa * cantina, identidade * filadeespera, int numerodemesas, int tamanho, int valorref) {
	int i = 0;
	int j = 0;
	int num_elmentos = filadeespera[0].n_elementos;
	int count_elementos = 0;
	while (i < numerodemesas) {

		//while( j < tamanho) {
		//cout << "MESA N " << cantina[i].numMesa << "   TAMANHO  " << cantina[i].tamanho << endl;
		//int removidos = 0;
		for (int z = 0; z < cantina[i].tamanho && j < tamanho && count_elementos < num_elmentos && cantina[i].vagas>0; z++) {
			if (cantina[i].pessoas[0].curso == filadeespera[j].curso || cantina[i].tamanho == cantina[i].vagas || !filadeespera[i].tipo) {
				cantina[i].pessoas[cantina[i].tamanho - cantina[i].vagas] = filadeespera[j];
				//cout << cantina[i].pessoas[z].primeironome << " | " << cantina[i].pessoas[z].numerogrupo << " | " << cantina[i].pessoas[z].curso << " | Duração : " << cantina[i].pessoas[z].duracao << endl;
				count_elementos++;
				cantina[i].vagas--;

				j++;
			}
			else
				cout << "CURSO DIFERENTE " << endl;
		}

		i++;
	}
	return count_elementos;
}

int adicionagrupoANTIGO(Mesa * cantina, identidade * filadeespera, int numerodemesas, int tamanho, int valorref) {
	int i = 0;
	int j = 0;
	int num_elmentos = filadeespera[0].n_elementos;
	int count_elementos = 0;
	while (i < numerodemesas) {

		//while( j < tamanho) {
		//cout << "MESA N " << cantina[i].numMesa << "   TAMANHO  " << cantina[i].tamanho << endl;
		//int removidos = 0;
		for (int z = 0; z < cantina[i].tamanho && j < tamanho && count_elementos < num_elmentos && cantina[i].vagas>0; z++) {

			cantina[i].pessoas[cantina[i].tamanho - cantina[i].vagas] = filadeespera[j];
			//cout << cantina[i].pessoas[z].primeironome << " | " << cantina[i].pessoas[z].numerogrupo << " | " << cantina[i].pessoas[z].curso << " | Duração : " << cantina[i].pessoas[z].duracao << endl;
			count_elementos++;
			cantina[i].vagas--;

			j++;
		}

		i++;
	}
	return count_elementos;
}

void imprimeCantina(Mesa * cantina, int numerodemesas) {
	int i = 0;
	while (i < numerodemesas) {
		//while( j < tamanho) {
		cout << "MESA N " << cantina[i].numMesa << "   TAMANHO  " << cantina[i].tamanho << endl;
		for (int z = 0; z < cantina[i].tamanho; z++) {

			//cantina[i].pessoas[cantina[i].tamanho - cantina[i].vagas] = filadeespera[j];
			cout << cantina[i].pessoas[z].primeironome << " | " << cantina[i].pessoas[z].numerogrupo << " | " << cantina[i].pessoas[z].numeroid << " | " << cantina[i].pessoas[z].curso << " | Duração : " << cantina[i].pessoas[z].duracao << " Plafond : " << cantina[i].pessoas[z].plafond << endl;
			
		}

		i++;
	}

}


void atualizagrupo(identidade * filadeespera, int numerogrup, int n_elementos) {
	for (int j = 0; j < 50; j++) {
		if (filadeespera[j].numerogrupo == numerogrup) {
			filadeespera[j].n_elementos = n_elementos;
			cout << "Elemento Atualizado" << endl;
		}
	}

}


void grava(Mesa * cantina, int numeromesas, identidade * filadeespera , refeiçao * novaref) {
	fstream file;
	file.open("dadosGravados.txt", ios::out);
	file << "************ Refeição" << endl << "Entrada: " << novaref->entrada << endl;
	file << "Prato Principal: " << novaref->principal << endl;
	file << "Custo: " << novaref->custo << endl;
	file << "************ Mesas com o pessoal" << endl;
	int i = 0;
	int tamanho = 50;
	while (i < numeromesas) {
		file << "----------------------------------------" << endl;
		file << "Mesa Nº " << cantina[i].numMesa << " (Capacidade " << cantina[i].tamanho << ")" << endl;
		for (int z = 0; z < cantina[i].tamanho; z++) {
			if (cantina[i].pessoas[z].tipo == 1) {
				file << "Tipo: Aluno"
					<< "   ||   Primeiro nome: " << cantina[i].pessoas[z].primeironome
					<< "   ||   Último nome: " << cantina[i].pessoas[z].ultimonome
					<< "   ||   Número de grupo: " << cantina[i].pessoas[z].numerogrupo
					<< "   ||   Curso: " << cantina[i].pessoas[z].curso
					<< "   ||   Duração: " << cantina[i].pessoas[z].duracao
					<< "   ||   Plafond: " << cantina[i].pessoas[z].plafond
					<< "   ||   Número de id: " << cantina[i].pessoas[z].numeroid
					<< endl;
				file << endl;
			}
			else {
				file << "Tipo: Staff"
					<< "   ||   Primeiro nome: " << cantina[i].pessoas[z].primeironome
					<< "   ||   Último nome: " << cantina[i].pessoas[z].ultimonome
					<< "   ||   Número de grupo: " << cantina[i].pessoas[z].numerogrupo
					<< "   ||   Curso: " << cantina[i].pessoas[z].curso
					<< "   ||   Duração: " << cantina[i].pessoas[z].duracao
					<< "   ||   Plafond: " << cantina[i].pessoas[z].plafond
					<< "   ||   Número de id: " << cantina[i].pessoas[z].numeroid
					<< endl;
				file << endl;
			}



		}

		i++;
	}
	file << "************ Fila de espera" << endl;
	for (int i = 0; i < tamanho; i++) {

		if (filadeespera[i].tipo == 1) {

			file << " -> " << "ALUNO" << ", " << filadeespera[i].primeironome << " " << filadeespera[i].ultimonome << ", " << filadeespera[i].curso << ", " << filadeespera[i].numeroid << ", Grupo: " << filadeespera[i].numerogrupo << ", " << filadeespera[i].plafond << " euros, (Duracao: " << filadeespera[i].duracao << ")" << endl;
		}
		else {
			file << " -> " << "STAFF" << ", " << filadeespera[i].primeironome << " " << filadeespera[i].ultimonome << ", " << filadeespera[i].curso << ", " << filadeespera[i].numeroid << ", Departamento: " << filadeespera[i].numerogrupo << ", " << filadeespera[i].plafond << " euros, (Duracao: " << filadeespera[i].duracao << ")" << endl;
		}
	}
	file << endl;
	file << "*********** Está tudo guardado" << endl;
	file.close();
	cout << "Guardado com sucesso " << endl;
}


void opcoes(identidade * filadeespera, int tamanho) {
	string nome[50];
	for (int i = 0; i < tamanho; i++) {
		filadeespera[i].ultimonome = nome[i];
	}
	vector <string> WordArray(nome, nome + 50);
	sort(begin(WordArray), end(WordArray));
	for (auto& Word : WordArray) {
		cout << Word << endl;
	}
	
}





/*int adicionagrupo_modificada(Mesa * cantina, identidade * filadeespera, int numerodemesas, int tamanho,int valorref) {
	int i = 0;
	int j = 0;
	int opcao;
	int num_elmentos = filadeespera[0].n_elementos;
	int count_elementos = 0;
	while (i < numerodemesas) {
		if (filadeespera[j].plafond < valorref) {
			cout << "Pessoa sem plafond, vou remover pessoa " << endl;
			j++;
		}
			
		//while( j < tamanho) {
		//cout << "MESA N " << cantina[i].numMesa << "   TAMANHO  " << cantina[i].tamanho << endl;
		for (int z = 0; z < cantina[i].tamanho && j < tamanho && count_elementos < num_elmentos && cantina[i].vagas>0; z++) {
			
			cantina[i].pessoas[cantina[i].tamanho - cantina[i].vagas] = filadeespera[j];
			//cout << cantina[i].pessoas[z].primeironome << " | " << cantina[i].pessoas[z].numerogrupo << " | " << cantina[i].pessoas[z].curso << " | Duração : " << cantina[i].pessoas[z].duracao << endl;
			j++;
			count_elementos++;
			cantina[i].vagas--;
		}

		i++;
	}
	return count_elementos;
}

/*void AlterarPlafond(identidade*filadeespera, int tamanho,int posicao) {
	int plafond = 0;
	for (int i = 0; i < 50; i++) {
		if (i == posicao) {
			cout << "Introduza o valor do novo plafond" << endl;
			cin >> ""
		}
	}
}

bool verificaPlafond(identidade pessoa, float valorref) {
	if (pessoa.plafond < valorref) {
		return false;
	}
	return true;
}

/*void adicionamesa(Mesa * cantina, identidade * filadeespera, int numeromesas, int tamanho) {
	int i = 0;
	int j = 0;
	int g = 0;
	int pessoas = 0;

	while (i < numeromesas) {
		int num_elementos = filadeespera[g].n_elementos;
		int count_elementos = 0;
		cout << "MESA N " << cantina[i].numMesa << "   TAMANHO  " << cantina[i].tamanho << endl;
		for (int z = 0; z < cantina[i].tamanho && j < tamanho && count_elementos < num_elementos; z++) {
			cantina[i].pessoas[z] = filadeespera[j];
			cout << cantina[i].pessoas[z].primeironome << " | " << cantina[i].pessoas[z].numerogrupo << " | " << cantina[i].pessoas[z].curso << " | Duração : " << cantina[i].pessoas[z].duracao << endl;
			j++;
			count_elementos++;
		}

		*/

	