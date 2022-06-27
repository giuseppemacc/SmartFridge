#include "file_names.h"
#include "types.h"
#include "utils.h"
#include "gestione_alimenti.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isAlimentoCompatibile(t_alimento alimento, t_alimento alimento_compatibile){
	//nome uguale e quantità maggiori
	//alimento <= alimento_compatibile
	int flag_compatibile=0;


	return flag_compatibile;

}


int isRicettaCompatibile(t_ricetta ricetta, t_alimento ingredienti[2]){
	// controlla se i due ingredienti sono presenti tra gli ingredienti della ricetta
	// scorro array ricetta.alimenti
	// vedo se è presente uno dei due alimenti nelle quantità giuste

	for(int i=0; i<ricetta.n_ingredienti; i++){
		if( isAlimentoCompatibile(ingredienti[0], ricetta.ingredienti[i]) ){

		}
	}

}


// ritorna 0 se array_ricette è vuoto e 1 altrimenti
int ricette_compatibili(const t_alimento ingredienti[2], t_ricetta ricette[], int* n_ricette){


}
