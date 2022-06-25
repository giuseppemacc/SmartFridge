/* Contiene tutte le funzioni per:
 * - visualizzare
 * - caricare
 * - rimuovere
 * - modificare
 * le ricette e gli alimenti dei corrispettivi file
 * */


#ifndef V_M_C_FILES_H_
#define V_M_C_FILES_H_

#include "types.h"


void print_alimento(t_alimento alimento);
void print_alimenti();

t_alimento input_alimento();
void aggiungi_alimenti();

t_ricetta input_ricetta();
void print_ricetta(t_ricetta ricetta);

void aggiungi_ricette();
void print_ricette();

void rimuovi_ricette();

void modifica_ricette();



#endif /* V_M_C_FILES_H_ */
