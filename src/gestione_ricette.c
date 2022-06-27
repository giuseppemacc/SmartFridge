
#include "file_names.h"
#include "types.h"
#include "utils.h"
#include "gestione_alimenti.h"
#include <stdio.h>



void print_ricetta(t_ricetta ricetta){
  puts("====================");
  printf("nome: %s\n", ricetta.nome);
  printf("procedimento: %s\n", ricetta.procedimento);

  for(int i=0; i<ricetta.n_ingredienti; i++){
	  printf("\tingrediente %d\n",i+1);
	  print_alimento(ricetta.ingredienti[i]);
  }
  puts("====================");
}

void print_ricette(){

}



t_ricetta input_ricetta(){
	t_ricetta ricetta;
	int input;
	t_alimento alimento;

	ricetta.n_ingredienti = 0;
	ricetta.valutazione = -1;
	ricetta.proposta = 0;

	  printf("Inserisci nome ricetta >> ");
	  scanf("%s", ricetta.nome);
	  printf("Inserisci categoria ricetta >> ");
	  scanf("%d", &ricetta.categoria); // inserire come stringa la categoria
	  printf("Inserisci procedimento ricetta >> ");
	  scanf("%s", ricetta.procedimento);
	  printf("Inserisci ingredienti >> ");
	  do{
		  printf("n%d:\n",ricetta.n_ingredienti+1);
		  alimento = input_alimento();

		  printf("questo alimento si trova in dispensa? [0:no, 1:si] >> ");
		  scanf("%d", &input);

		  if(input == 1){
			  alimento.dispensa = 1;
		  }

		  ricetta.ingredienti[ ricetta.n_ingredienti ] = alimento;
		  ricetta.n_ingredienti++;

		  printf("Aggiungere un altro alimento? [si:1, no:0] >> ");
		  scanf("%d", &input);

	  }while(input==1);


	return ricetta;
}



void aggiungi_ricette(){

}


void rimuovi_ricette(){

}

void modifica_ricette(){

}
