

#ifndef SCEGLI_RICETTA_H_
#define SCEGLI_RICETTA_H_

#include "types.h"

// ritorna 0 se array_ricette è vuoto e 1 altrimenti
int ricette_compatibili(const t_alimento ingredienti[2], t_ricetta ricette[], int* n_ricette);

// ordina l array delle ricette compatibili in base al piano settimanale e alla cronologia ricette
void ordina_ricette(t_ricetta ricette[], const int n_ricette);

/* fa inserire 2 alimenti
 * mette in un array le ricette compatibili
 * le fa ordinare in base a piano sett e cronologia
 *
 * ... come nel diagramma di flusso
 * e aggiorna la cronologia
 * */
void consiglia_ricetta();


#endif /* SCEGLI_RICETTA_H_ */
