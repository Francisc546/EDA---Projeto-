#pragma once

struct alunos {
	char p_nome;
	char u_nome;
	int id_number;
	int gr_number;
	char curso;
	float plafond;
};

void insereAlunos(alunos * const vAlunos);