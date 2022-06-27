#ifndef GESTIONE_ALIMENTI_H_
#define GESTIONE_ALIMENTI_H_

#include "types.h"


void print_alimento(t_alimento alimento);
void print_alimenti();

t_alimento input_alimento();
void aggiungi_alimenti();


void rimuovi_alimenti();

void modifica_alimenti();

int ricerca_alimento(char* nome, t_alimento* alimento, FILE* file_alimenti);

#endif /* GESTIONE_ALIMENTI_H_ */
