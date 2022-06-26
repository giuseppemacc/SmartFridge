/*
 * gestione_ricette.h
 *
 *  Created on: 26 giu 2022
 *      Author: gioel
 */

#ifndef GESTIONE_RICETTE_H_
#define GESTIONE_RICETTE_H_

#include "types.h"

t_ricetta input_ricetta();
void print_ricetta(t_ricetta ricetta);

void aggiungi_ricette();
void print_ricette();

void rimuovi_ricette();

void modifica_ricette();

#endif /* GESTIONE_RICETTE_H_ */
