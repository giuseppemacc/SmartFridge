#include <stdio.h>
#include "types.h"
#include "file_names.h"
#include "utils.h"
#include "menu.h"
#include "valutazioni.h"
#include "scegli_ricetta.h"
#include "piano_settimanale.h"
#include "gestione_alimenti.h"
#include "gestione_ricette.h"


int main(void) {
	setvbuf(stdout, NULL, _IONBF, 0);

	//t_alimento alimento = input_alimento();
	//print_alimento(alimento);

	aggiungi_alimenti();


	print_alimenti();

	modifica_alimenti();


	print_alimenti();

	//t_ricetta ricetta = input_ricetta();
	//print_ricetta(ricetta);

	return 0;
}





